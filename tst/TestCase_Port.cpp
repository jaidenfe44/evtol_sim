#include "TestCase_Port.hpp"

void TestCase_Port::cleanup()
{
    for(Charger c : chargers_a)
    {
        while(!c.chargingQueue.empty()) c.chargingQueue.pop();
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
    for(Charger c : chargers_a)
    {
        while(!c.chargingQueue.empty()) c.chargingQueue.pop();
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
    uint32_t vehicleIdx = 1;
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

    // TODO: Add second vehicle to the same charger
    tcAssert(false, __func__, "TODO: Add second vehicle to same charger test case");

    // TODO: Add third vehicle to a new charger
    tcAssert(false, __func__, "TODO: Add third vehicle to a new charger test case");
    

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
    // TODO: Initialize test case
    tcPass = true;

    // TODO: Execute Function

    // TODO: Verify expected behavior
    tcAssert(false, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Port::updateNextAvailable", tcPass ? "Passed" : "Failed");

    return tcPass;
}
