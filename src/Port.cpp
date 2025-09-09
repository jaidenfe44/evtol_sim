
#include "Port.hpp"
#include "System.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>

/**
 * Port constructor
 *
 * Randomize the population of the vehicle array and compute the initial flight times of each
 *
 * @return a Port class
 */
Port::Port()
{
    srand(time(0));
    // Randomize the population of vehicles_a
    for(int idx = 0; idx < vehicles_a.size(); idx++)
    {
        // Set company and statistics
        switch(rand() % 5)
        {
            case 0:
                vehicles_a[idx] = Alpha();
                break;
    
            case 1:
                vehicles_a[idx] = Bravo();
                break;
    
            case 2:
                vehicles_a[idx] = Charlie();
                break;
    
            case 3:
                vehicles_a[idx] = Delta();
                break;
    
            case 4:
                vehicles_a[idx] = Echo();
                break;
    
            default:
                printf("Error in Port initialization\n");
                break;
        }

        // Set initial flight time
        vehicles_a[idx].computeFlightTime();
    }

    for(int i = 0; i < chargers_a.size(); i++)
    {
        chargers_a[i].Id = i;
    }

    // Set next available
    nextAvailableCharger = &chargers_a[0];
}


/**
 * Step through the simulation one second at a time
 *
 * @return void
 */
void Port::step()
{
    static uint32_t faultCount = 0;

    // Check if vehicles have completed their current tasks
	for(int idx = 0; idx < vehicles_a.size(); idx++)
    {
        // Calculate if a fault occurs
        if((faultCount % 3600) == 0) vehicles_a[idx].computeFault();

        // If the vehicles are waiting for a charger, increment queue time, otherwise decrement the task time
        vehicles_a[idx].state == VehicleState::eQueued ? vehicles_a[idx].queueTime++ : vehicles_a[idx].taskTime--;

        // Check if the vehicle has completed its current task (airborne or charging, queued vehicles dont update taskTime)
        if(vehicles_a[idx].taskTime == 0)
        {
            switch(vehicles_a[idx].state)
            {
                case VehicleState::eAirborne:
                    // Finished flight, add to charging queue
                    addToCharger(&vehicles_a[idx]);
                    break;

                case VehicleState::eCharging:
                    // Finished charging, remove from charger and start flying again
                    removeFromCharger(&vehicles_a[idx]);
                    break;

                default:
                    // Should never get here
                    printf("Error: Unexpected vehicle state when task time is 0");
                    break;
            }
        }
    }
    faultCount++;
};


/**
 * Add a vehicle to the next available charger
 *
 * @return void
 */
void Port::addToCharger(eVtol* vehicle)
{
    // If we dont have a next available charger, return
    if(nextAvailableCharger == nullptr) return;

    // Add vehicle to the next available charger or queue for next available charger
    nextAvailableCharger->add(vehicle);

    // Store charger for vehicle reference
    vehicle->atCharger(nextAvailableCharger->Id);
    
    // Update which charger should receive the next vehicle
    updateNextAvailable();
};


/**
 * Remove a vehicle from the charger it is charging at
 *
 * Once the vehicle is finished charging, this function rmeoves it from the Charger
 *
 * @return void
 */
void Port::removeFromCharger(eVtol* vehicle)
{
    // Check if vehicle is charging, if not (i.e. its queued or actually flying) we shouldn't remove it from the queue
    if(vehicle->state != VehicleState::eCharging) return;

    // Remove vehicle form the charger at the stored charger index
    chargers_a[vehicle->vehicleCharger].remove();

    if(vehicle->state == VehicleState::eAirborne)
    {
        // Calculate the new flight time
        vehicle->computeFlightTime();

        // Update the next available charger
        updateNextAvailable();
    }
};


/**
 * Update the next available Charger
 *
 * @return void
 */
void Port::updateNextAvailable()
{
    // Sequence through chargers to update availability
    for(int idx = 0; idx < chargers_a.size(); idx++)
    {
        // Check if the availability weight is less than that of the current next available charger
        if(chargers_a[idx].checkAvailability() < nextAvailableCharger->checkAvailability())
        {
            // Set next available charger
            nextAvailableCharger = &chargers_a[idx];
        }
    }
};


/**
 * Print out vehicle statistics
 *
 * @return void 
 */
void Port::generateReport()
{
	printf("\nGenerating Simulation Report...\n");

    // Note: index 0 = Alpha, 1 = Bravo, 2 = Charlie, 3 = Delta, 4 = Echo
    const char* companies[5] = {"Alpha", "Bravo", "Charlie", "Delta", "Echo"};
    uint32_t numVehicles[5]  = {0};
    uint32_t flightTime[5]   = {0};
    uint32_t distance[5]     = {0};
    uint32_t chargeTime[5]   = {0};
    uint32_t faults[5]       = {0};
    uint32_t passMiles[5]    = {0};
    uint32_t queueTime[5]    = {0};

	for(eVtol vehicle : vehicles_a)
	{
        numVehicles[vehicle.company]++;
        flightTime[vehicle.company] = vehicle.getFlightTime();
        chargeTime[vehicle.company] = vehicle.getChargeTime();
        distance[vehicle.company]   = vehicle.getRange();
        faults[vehicle.company]    += vehicle.getFaults();
        passMiles[vehicle.company] += vehicle.getPassengerMiles();
        queueTime[vehicle.company] += vehicle.queueTime;
	}

    for(int i = 0; i < 5; i++)
    {

        printf("\n%s eVtol Statistics:\n", companies[i]);
        printf("    Number of Vehicles:                         %4i\n", numVehicles[i]);
        printf("    Average Flight Time (Per Flight):           %4i minutes\n", flightTime[i]);
        printf("    Average Time Charging (Per Charge Session): %4i minutes\n", chargeTime[i]);
        printf("    Average Distance Traveled (Per Flight):     %4i miles\n",   distance[i]);
        printf("    Average Time Waiting for Charger:           %4i minutes\n", (queueTime[i]/numVehicles[i])/60);
        printf("    Total Number of Faults:                     %4i\n",         faults[i]);
        printf("    Total Number of Passenger Miles:            %4i miles\n",   passMiles[i]);
    }
};
