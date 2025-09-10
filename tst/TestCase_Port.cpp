#include "TestCase_Port.hpp"

void TestCase_Port::cleanup()
{
    for(int i = 0; i < chargers_a.size(); i++)
    {
        while(!chargers_a[i].chargingQueue.empty())
        {
            chargers_a[i].chargingQueue.pop();
        }
    }

}


bool TestCase_Port::TC_step()
{
    // TODO: Initialize test case
    tcPass = true;

    // TODO: Execute Function

    // Verify expected behavior
    tcAssert(false, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Port::step", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_Port::TC_addToCharger()
{
    // Initialize test case
    tcPass = true;
    for(int i = 0; i < chargers_a.size(); i++)
    {
        while(!chargers_a[i].chargingQueue.empty())
        {
            chargers_a[i].chargingQueue.pop();
        }
    }
    nextAvailableCharger = nullptr;

    // Execute Function
    addToCharger(&vehicles_a[0]);

    // Verify expected behavior
    for(Charger c : chargers_a)
    {
        tcAssert(c.chargingQueue.empty(), __func__, "Vehicle index 0 was added to a Charger when it wasnt supposed to be");
    }

    // Initialize nominal test case
    uint32_t chargerIdx = 2;
    uint32_t charger2Idx = 1;
    uint32_t vehicleIdx = 1;
    uint32_t vehicle2Idx = 6;
    uint32_t vehicle3Idx = 0;
    
    nextAvailableCharger = &chargers_a[chargerIdx];
    vehicles_a[vehicleIdx].state = VehicleState::eAirborne;
    vehicles_a[vehicleIdx].taskTime = 0;
    vehicles_a[vehicleIdx].vehicleCharger = 0;

    // Execute function
    addToCharger(&vehicles_a[vehicleIdx]);

    // Verify expected behavior
    tcAssert(chargers_a[chargerIdx].chargingQueue.size() == 1, __func__, "Charger queue does not contain a vehicle, queue is empty");
    tcAssert(chargers_a[chargerIdx].chargingQueue.front() == &vehicles_a[vehicleIdx], __func__, "TODO");
    tcAssert(chargers_a[chargerIdx].chargingQueue.front()->state == VehicleState::eCharging, __func__, "TODO");
    tcAssert(vehicles_a[vehicleIdx].vehicleCharger == chargerIdx, __func__, "The added vehicle did not update the charger index properly");
    tcAssert(nextAvailableCharger != &chargers_a[chargerIdx], __func__, "Next available charger was not update, still pointing to the same Charger");

    // Add second vehicle to the same charger
    nextAvailableCharger = &chargers_a[chargerIdx];
    vehicles_a[vehicle2Idx].state = VehicleState::eAirborne;
    vehicles_a[vehicle2Idx].taskTime = 0;
    vehicles_a[vehicle2Idx].vehicleCharger = 0;
    
    // Execute function
    addToCharger(&vehicles_a[vehicle2Idx]);

    // Verifuy expected behavior
    tcAssert(chargers_a[chargerIdx].chargingQueue.size() == 2, __func__, "Charger queue does not contain two vehicles as expected");
    tcAssert(chargers_a[chargerIdx].chargingQueue.front() == &vehicles_a[vehicleIdx], __func__, "The front of the charger is not the first vehicle added");
    tcAssert(vehicles_a[vehicle2Idx].state == VehicleState::eQueued, __func__, "The second vehicle did not update its state to eQueued");
    tcAssert(vehicles_a[vehicle2Idx].vehicleCharger == chargerIdx, __func__, "The added vehicle did not update the charger index properly");
    tcAssert(nextAvailableCharger != &chargers_a[chargerIdx], __func__, "Next available charger was not update, still pointing to the same Charger");

    // Add third vehicle to a new charger
    nextAvailableCharger = &chargers_a[charger2Idx];
    vehicles_a[vehicle3Idx].state = VehicleState::eAirborne;
    vehicles_a[vehicle3Idx].taskTime = 0;
    vehicles_a[vehicle3Idx].vehicleCharger = 0;

    // Execute function
    addToCharger(&vehicles_a[vehicle3Idx]);

    // Verify expected behavior
    tcAssert(chargers_a[chargerIdx].chargingQueue.size() == 2, __func__, "Initial charger queue was modified unexpectedly");
    tcAssert(chargers_a[chargerIdx].chargingQueue.front() == &vehicles_a[vehicleIdx], __func__, "The front of the initial charger is not the first vehicle added");
    tcAssert(vehicles_a[vehicle2Idx].state == VehicleState::eQueued, __func__, "The second vehicle state was modified");
    tcAssert(vehicles_a[vehicle2Idx].vehicleCharger == chargerIdx, __func__, "The second added vehicle charger index was modified");
    tcAssert(nextAvailableCharger != &chargers_a[chargerIdx], __func__, "Next available charger was not update properly, pointing to first charger");
    tcAssert(nextAvailableCharger != &chargers_a[charger2Idx], __func__, "Next available charger was not update properly, pointing to second charger");

    tcAssert(chargers_a[charger2Idx].chargingQueue.front() == &vehicles_a[vehicle3Idx], __func__, "The third vehicle added is not at the second charger ");
    tcAssert(vehicles_a[vehicle3Idx].state == VehicleState::eCharging, __func__, "The third vehicle's state was not updated to eCharging");
    tcAssert(vehicles_a[vehicle3Idx].vehicleCharger == charger2Idx, __func__, "The third vehicle's charger index did not match the charger it was added to");
    

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Port::addToCharger", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_Port::TC_removeFromCharger()
{
    // TODO: Initialize test case
    tcPass = true;

    // TODO: Execute Function

    // TODO: Verify expected behavior
    tcAssert(false, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Port::removeFromCharger", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_Port::TC_updateNextAvailable()
{
    // Initialize test case
    tcPass = true;
    for(int i = 0; i < chargers_a.size(); i++)
    {
        while(!chargers_a[i].chargingQueue.empty())
        {
            chargers_a[i].chargingQueue.pop();
        }
    }

    nextAvailableCharger = &chargers_a[0];

    // Execute Function
    updateNextAvailable();

    // Verify expected behavior
    tcAssert(nextAvailableCharger == &chargers_a[0], __func__, "When all charger queues are empty the next available should not update, but the charger did update");

    // Set up another test case
    nextAvailableCharger = &chargers_a[1];
    chargers_a[1].chargingQueue.push(&vehicles_a[0]);

    // Execute Function
    updateNextAvailable();

    // Verify expected behavior
    tcAssert(nextAvailableCharger == &chargers_a[0], __func__, "Next available charger was not updated to Charger at index 0");

    // Test case where charger 1 has 2 vehicles, charger 0 has one vehicle and charger 2 has no vehicles
    chargers_a[1].chargingQueue.push(&vehicles_a[1]);
    chargers_a[0].chargingQueue.push(&vehicles_a[2]);
    nextAvailableCharger = &chargers_a[1];

    // Execute function
    updateNextAvailable();

    // verify expected behavior
    tcAssert(nextAvailableCharger == &chargers_a[2], __func__, "Next available charger was not updated to Charger at index 2");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Port::updateNextAvailable", tcPass ? "Passed" : "Failed");

    return tcPass;
}
