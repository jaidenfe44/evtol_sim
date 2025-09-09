
#include "TestCase_Charger.hpp"

void TestCase_Charger::cleanup()
{
    while(!chargingQueue.empty()) chargingQueue.pop();

    vehicle1.taskTime = 0;
    vehicle1.queueTime = 0;
    vehicle1.state = VehicleState::eAirborne;
    vehicle1.chargeTime = 0;

    vehicle2.taskTime = 0;
    vehicle2.queueTime = 0;
    vehicle2.state = VehicleState::eAirborne;
    vehicle2.chargeTime = 0;
}


bool TestCase_Charger::TC_add()
{
    // Initialize test case
    tcPass = true;
    while(!chargingQueue.empty()) chargingQueue.pop();
    vehicle1.taskTime = 0;
    vehicle1.queueTime = 0;
    vehicle1.state = VehicleState::eAirborne;
    vehicle1.chargeTime = 17;
    vehicle2.taskTime = 0;
    vehicle2.queueTime = 0;
    vehicle2.state = VehicleState::eAirborne;
    vehicle2.chargeTime = 23;

    // Verify initial state
    tcAssert(chargingQueue.empty(), __func__, "Charger::chargingQueue was not empty");

    // Execute Function
    add(&vehicle1);

    // Verify expected behavior
    tcAssert(chargingQueue.size() == 1, __func__, "vehicle was not added to the charging queue");
    tcAssert(chargingQueue.front() == &vehicle1, __func__, "The vehicle is not at the front of the queue as expected");
    tcAssert(vehicle1.state == VehicleState::eCharging, __func__, "The vehicle state was not updated to eCharging");
    tcAssert(vehicle1.taskTime == vehicle1.chargeTime, __func__, "The vehicle task time was not updated to its charge time");

    // Execute Function again
    add(&vehicle2);

    // Verify expected behavior
    tcAssert(chargingQueue.size() == 2, __func__, "Second vehicle was not added to the charging queue");
    tcAssert(chargingQueue.front() == &vehicle1, __func__, "The first vehicle is not at the front of the queue as expected");
    tcAssert(vehicle1.state == VehicleState::eCharging, __func__, "The first vehicle state was modified");
    tcAssert(vehicle2.state == VehicleState::eQueued, __func__, "The second vehicle state was not set to eQueued");
    tcAssert(vehicle2.taskTime == vehicle2.chargeTime, __func__, "The second vehicle task time was not updated to its charge time");
    
    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Charger::add", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_Charger::TC_remove()
{
    // TODO: Initialize test case
    tcPass = true;

    // TODO: Execute Function

    // TODO: Verify expected behavior
    tcAssert(false, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Charger::remove", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_Charger::TC_checkAvailability()
{
    // TODO: Initialize test case
    tcPass = true;

    // TODO: Execute Function

    // TODO: Verify expected behavior
    tcAssert(false, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Charger::checkAvailability", tcPass ? "Passed" : "Failed");

    return tcPass;
}
