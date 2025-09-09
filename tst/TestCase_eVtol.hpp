#ifndef TEST_CASE_EVTOL_HPP
#define TEST_CASE_EVTOL_HPP

#include "TestCase.hpp"
#include "eVtol.hpp"

class TestCase_eVtol: public TestCase, eVtol
{
    public:
        // Test Case execution function
        void run(uint32_t &pass, uint32_t& fail) override
        {
            // Functional test cases to run
            TC_atCharger()          ? pass++ : fail++;
            TC_computeFlightTime()  ? pass++ : fail++;
            TC_computeChargeTime()  ? pass++ : fail++;
            TC_computeFault()       ? pass++ : fail++;
            TC_getFlightTime()      ? pass++ : fail++;
            TC_getChargeTime()      ? pass++ : fail++;
            TC_getRange()           ? pass++ : fail++;
            TC_getPassengerMiles()  ? pass++ : fail++;
            TC_getFaults()          ? pass++ : fail++;
        }

        // Test Cases
        bool TC_atCharger();
        bool TC_computeFlightTime();
        bool TC_computeChargeTime();
        bool TC_computeFault();
        bool TC_getFlightTime();
        bool TC_getChargeTime();
        bool TC_getRange();
        bool TC_getPassengerMiles();
        bool TC_getFaults();

    private:

        void cleanup() override;

};

#endif // TEST_CASE_EVTOL_HPP
