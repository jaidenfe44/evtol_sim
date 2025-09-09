#ifndef TEST_CASE_PORT_HPP
#define TEST_CASE_PORT_HPP

#include "TestCase.hpp"
#include "Port.hpp"
#include "eVtol.hpp"

class TestCase_Port: public TestCase, Port
{
    public:
        // Test Case execution function
        void run(uint32_t &pass, uint32_t& fail) override
        {
            // Functional test cases to run
            TC_step()                ? pass++ : fail++;
            TC_addToCharger()        ? pass++ : fail++;
            TC_removeFromCharger()   ? pass++ : fail++;
            TC_updateNextAvailable() ? pass++ : fail++;
        }

        // Test Cases
        bool TC_step();
        bool TC_addToCharger();
        bool TC_removeFromCharger();
        bool TC_updateNextAvailable();

    private:

        void cleanup() override;

        eVtol vehicle1;
        eVtol vehicle2;
        eVtol vehicle3;
};

#endif // TEST_CASE_PORT_HPP
