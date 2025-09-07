
#include "Port.hpp"
#include "System.hpp"
#include <cstdio>


/**
 * TODO
 */
Port::Port()
{
    // TODO: Randomize the population of vehicles_a
    vehicles_a[0] = Alpha();
    vehicles_a[1] = Bravo();
    vehicles_a[2] = Charlie();
    vehicles_a[3] = Delta();
    vehicles_a[4] = Echo();
}


/**
 * TODO
 */
void Port::step()
{
    // Check if vehicles have completed their current tasks
	for(eVtol vehicle : vehicles_a)
    {
        // If the vehicles are waiting for a charger, increment queue time, otherwise decrement the task time
        vehicle.state == VehicleState::eQueued ? vehicle.queueTime++ : vehicle.taskTime--;

        // Check if the vehicle has completed its current task (airborne or charging, queued vehicles dont update taskTime)
        if(vehicle.taskTime == 0)
        {
            switch(vehicle.state)
            {
                case VehicleState::eAirborne:
                    // Finished flight, add to charging queue
                    addToCharger(&vehicle);
                    break;

                case VehicleState::eCharging:
                    // Finished charging, remove from charger and start flying again
                    removeFromCharger(&vehicle);
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
    // TODO
    printf("Adding to charger...\n");

    // TODO: Add vehicle to the next available charger or queue for next available charger

    // TODO: Store charger index for vehicle reference

    // Update which charger should receive the next vehicle
    updateNextAvailable();
};


/**
 * TODO
 */
void Port::removeFromCharger(eVtol* vehicle)
{
    // TODO
    printf("Removing from charger...\n");

    // Check if vehicle is charging, if not (i.e. its queued or actually flying) we shouldn't remove it from the queue
    if(vehicle->state != VehicleState::eCharging) return;

    // TODO: Remove vehicle form the charger at the stored charger index

    if(vehicle->state == VehicleState::eAirborne)
    {
        // TODO: Calculate the new flight time

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
    printf("Updating next available...\n");
};


/**
 * TODO
 */
void Port::generateReport()
{
	printf("Generate Report Called\n");

    int i = 1;
	for(eVtol vehicle : vehicles_a)
	{
		printf("Vehicle %02i Company: %s\n", i++, vehicle.company.c_str());
	}
};
