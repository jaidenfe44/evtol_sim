
#include "Charger.hpp"
#include "eVtol.hpp"


/**
 * TODO
 *
 * @return void
 */
void Charger::add(eVtol* vehicle)
{
    // Set vehicle state according to if its charging or waiting to charge
    vehicle->state = chargingQueue.empty() ? VehicleState::eCharging : VehicleState::eQueued;

    // Add to queue
    chargingQueue.push(vehicle);

    // Set task time according to charge 
    vehicle->computeChargeTime();

};


/**
 * TODO
 *
 * @return void
 */
void Charger::remove()
{
    // CHeck if charging queue is empty
    if(chargingQueue.empty()) return;

    // Update the state of the vehicle currently charging to eAirborne
    chargingQueue.front()->state = VehicleState::eAirborne;

    // Remove vehicle once its done charging
    chargingQueue.pop();

    // Check if the queue is empty
    if(!chargingQueue.empty())
    {
        // Update the state of the vehicle at the front of the queue to eCharging
        chargingQueue.front()->state = VehicleState::eCharging;
    }
};


/**
 * Check the charger availability
 *
 * This is computed by returning the size of the queue. The lower the number the higher the availability.
 *
 * @return uint32_t - The availability (lower is more available)
 */
uint32_t Charger::checkAvailability()
{
    return chargingQueue.size();
};
