
#include "Port.hpp"
#include "System.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>

/**
 * TODO
 */
Port::Port()
{
    srand(time(0));
    // TODO: Randomize the population of vehicles_a
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

    // Set next available
    nextAvailableCharger = &chargers_a[0];
}


/**
 * TODO
 */
void Port::step()
{
    // Check if vehicles have completed their current tasks
	for(int idx = 0; idx < vehicles_a.size(); idx++)
    {
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
};


/**
 * TODO
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
 * TODO
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
 * TODO
 */
void Port::updateNextAvailable()
{
    // TODO
    for(int idx = 0; idx < chargers_a.size(); idx++)
    {
        // TODO
        if(chargers_a[idx].checkAvailability() < nextAvailableCharger->checkAvailability())
        {
            nextAvailableCharger = &chargers_a[idx];
        }
    }
};


/**
 * TODO
 */
void Port::generateReport()
{
	printf("\nGenerate Report Called\n");

    int i = 1;
	for(eVtol vehicle : vehicles_a)
	{
		printf("Vehicle %02i Company: %s\n", i++, vehicle.company.c_str());
	}

    for(Charger c : chargers_a)
    {
        printf("Charger %i\n", c.Id);
        printf("    Queue Size: %i\n", c.checkAvailability());
    }
};
