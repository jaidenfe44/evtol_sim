
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
    vehicle3.taskTime = 0;
    vehicle3.queueTime = 0;
    vehicle3.state = VehicleState::eAirborne;
    vehicle3.chargeTime = 9;

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
    // Initialize test case
    tcPass = true;
    while(!chargingQueue.empty()) chargingQueue.pop();
    vehicle1.chargeTime = 36;
    vehicle1.taskTime = vehicle1.chargeTime;
    vehicle1.queueTime = 0;
    vehicle1.state = VehicleState::eCharging;
    vehicle2.chargeTime = 23;
    vehicle2.taskTime = vehicle2.chargeTime;
    vehicle2.queueTime = 0;
    vehicle2.state = VehicleState::eQueued;
    vehicle3.chargeTime = 41;
    vehicle3.taskTime = vehicle2.chargeTime;
    vehicle3.queueTime = 0;
    vehicle3.state = VehicleState::eQueued;

    // Verify initial state
    tcAssert(chargingQueue.empty(), __func__, "Charger::chargingQueue was not empty");

    // Execute Function
    remove();

    // Verify expected behavior
    tcAssert(chargingQueue.empty(), __func__, "Charger::chargingQueue was not empty");

    // Set up charging queue to have vehicles
    chargingQueue.push(&vehicle1);
    chargingQueue.push(&vehicle2);
    chargingQueue.push(&vehicle3);

    // Verify initial setup
    tcAssert(chargingQueue.size() == 3, __func__, "The charging queue does not reflect the number of vehicles added (3)");
    tcAssert(chargingQueue.front() == &vehicle1, __func__, "The first vehicle in the queue is not the first vehicle added");

    // Execute function
    remove();

    // Verify expected behavior
    tcAssert(chargingQueue.size() == 2, __func__, "A vehicle was not removed from the queue (queue size is not 2)");
    tcAssert(chargingQueue.front() == &vehicle2, __func__, "The second vehicle is not at the front of the queue");
    tcAssert(chargingQueue.front()->state == VehicleState::eCharging, __func__, "The state of the vehicle at the front of the queue was not updated to eCharging");
    tcAssert(vehicle1.state == VehicleState::eAirborne, __func__, "The state of the removed vehicle was not updated to eAirborne");
    tcAssert(vehicle3.state == VehicleState::eQueued, __func__, "The state of the queued vehicle was modified unexpectedly");

    // Execute function again
    remove();

    // Verify expected behavior
    tcAssert(chargingQueue.size() == 1, __func__, "A vehicle was not removed from the queue (queue size is not 1)");
    tcAssert(chargingQueue.front() == &vehicle3, __func__, "The third vehicle is not at the front of the queue");
    tcAssert(chargingQueue.front()->state == VehicleState::eCharging, __func__, "The state of the vehicle at the front of the queue was not updated to eCharging");
    tcAssert(vehicle1.state == VehicleState::eAirborne, __func__, "The state of the first vehicle was modified after it was removed");
    tcAssert(vehicle2.state == VehicleState::eAirborne, __func__, "The state of the second vehicle was not updated to eAirborne");

    // Execute function one last time
    remove();

    // Verify expected behavior
    tcAssert(chargingQueue.size() == 0, __func__, "The queue is not empty");
    tcAssert(vehicle1.state == VehicleState::eAirborne, __func__, "The state of the first vehicle was modified after it was removed (remove called twice)");
    tcAssert(vehicle2.state == VehicleState::eAirborne, __func__, "The state of the second vehicle was modified after it was removed");
    tcAssert(vehicle3.state == VehicleState::eAirborne, __func__, "The state of the third vehicle was not updated to eAirborne");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Charger::remove", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_Charger::TC_checkAvailability()
{
    // Initialize test case
    tcPass = true;
    uint32_t verifyCheckAvailability = 0;
    while(!chargingQueue.empty()) chargingQueue.pop();

    // Verify initial state
    tcAssert(chargingQueue.empty(), __func__, "Charger::chargingQueue was not empty");

    // Execute Function
    verifyCheckAvailability = checkAvailability();

    // Verify expected behavior
    tcAssert(verifyCheckAvailability == 0, __func__, "The availability was not 0 as expected");

    // Set next test state
    chargingQueue.push(&vehicle1);
    chargingQueue.push(&vehicle2);
    chargingQueue.push(&vehicle3);
    verifyCheckAvailability = 0;

    // Verify initial state
    tcAssert(chargingQueue.size() == 3, __func__, "Charger::chargingQueue did not contain all 3 vehicles");

    // Execute Function
    verifyCheckAvailability = checkAvailability();

    // Verify expected behavior
    tcAssert(verifyCheckAvailability == 3, __func__, "The availability was not 3 as expected");

    // Set next test runs state
    chargingQueue.pop();
    chargingQueue.pop();
    verifyCheckAvailability = 0;

    // Verify initial state
    tcAssert(chargingQueue.size() == 1, __func__, "Charger::chargingQueue did not contain 1 vehicle");

    // Execute Function
    verifyCheckAvailability = checkAvailability();

    // Verify expected behavior
    tcAssert(verifyCheckAvailability == 1, __func__, "The availability was not 1 as expected");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: Charger::checkAvailability", tcPass ? "Passed" : "Failed");

    return tcPass;
}
