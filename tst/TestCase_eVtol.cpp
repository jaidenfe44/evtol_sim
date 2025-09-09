
#include "TestCase_eVtol.hpp"


void TestCase_eVtol::cleanup()
{
    vehicleCharger = 0;
    taskTime = 0;
    queueTime = 0;
    flightTime = 0;
    passengerMiles = 0;
    passMilesPerFlight = 0;
    range = 0;
}

bool TestCase_eVtol::TC_atCharger()
{
    // Initialize test case
    tcPass = true;
    vehicleCharger = 0;
    uint32_t expectedChargerIdx = 2;

    // Execute Function
    atCharger(expectedChargerIdx);

    // Verify expected behavior
    tcAssert(vehicleCharger == expectedChargerIdx, __func__, "Vehicle Charger is not being set properly");

    // Set up second execution
    expectedChargerIdx = 276;

    // Execute funciton again
    atCharger(expectedChargerIdx);

    // Verify expected behavior
    tcAssert(vehicleCharger == expectedChargerIdx, __func__, "Vehicle Charger is not being set properly in second call");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::atCharger", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_eVtol::TC_computeFlightTime()
{
    // Initialize test case
    tcPass = true;
    taskTime = 0;
    flightTime = 8730;
    passengerMiles = 0;
    passMilesPerFlight = 456;

    // Execute Function
    computeFlightTime();

    // Verify expected behavior
    tcAssert(taskTime == flightTime, __func__, "TODO");
    tcAssert(passengerMiles == passMilesPerFlight, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::computeFlightTime", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_eVtol::TC_computeChargeTime()
{
    // Initialize test case
    tcPass = true;
    taskTime = 0;
    chargeTime = 983;

    // Execute Function
    computeChargeTime();

    // Verify expected behavior
    tcAssert(taskTime == chargeTime, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::computeChargeTime", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_eVtol::TC_computeFault()
{
    // TODO: Initialize test case
    tcPass = true;

    // TODO: Execute Function

    // TODO: Verify expected behavior
    tcAssert(false, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::computeFault", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_eVtol::TC_getFlightTime()
{
    // Initialize test case
    tcPass = true;
    uint32_t expectedFlightTime = 874;
    flightTime = expectedFlightTime * 60;
    uint32_t checkFlightTime = 0;

    // Execute Function
    checkFlightTime = getFlightTime();

    // Verify expected behavior
    tcAssert(checkFlightTime == expectedFlightTime, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::getFlightTime", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_eVtol::TC_getChargeTime()
{
    // Initialize test case
    tcPass = true;
    uint32_t expectedChargeTime = 27;
    chargeTime = expectedChargeTime * 60;
    uint32_t checkChargeTime = 0;

    // Execute Function
    checkChargeTime = getChargeTime();

    // Verify expected behavior
    tcAssert(checkChargeTime == expectedChargeTime, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::getChargeTime", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_eVtol::TC_getRange()
{
    // Initialize test case
    tcPass = true;
    range = 638;
    uint32_t checkRange = 0;

    // Execute Function
    checkRange = getRange();

    // Verify expected behavior
    tcAssert(checkRange == range, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::getRange", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_eVtol::TC_getPassengerMiles()
{
    // Initialize test case
    tcPass = true;
    passengerMiles = 27963;
    uint32_t checkPassengerMiles = 0;

    // Execute Function
    checkPassengerMiles = getPassengerMiles();

    // Verify expected behavior
    tcAssert(checkPassengerMiles == passengerMiles, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::getPassengerMiles", tcPass ? "Passed" : "Failed");

    return tcPass;
}


bool TestCase_eVtol::TC_getFaults()
{
    // Initialize test case
    tcPass = true;
    faults = 6;
    uint32_t checkFaults = 0;

    // Execute Function
    checkFaults = getFaults();

    // Verify expected behavior
    tcAssert(checkFaults == faults, __func__, "TODO");

    // Cleanup
    cleanup();


    printf("    %-44s%s\n", "Test Case: eVtol::getFaults", tcPass ? "Passed" : "Failed");

    return tcPass;
}


