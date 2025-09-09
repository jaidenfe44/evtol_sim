#ifndef TEST_CASE_CHARGER_HPP
#define TEST_CASE_CHARGER_HPP

#include "TestCase.hpp"
#include "Charger.hpp"
#include "eVtol.hpp"

class TestCase_Charger: public TestCase, Charger
{
    public:
        TestCase_Charger(){};

        void cleanup() override;

        // Test Case execution function
        void run(uint32_t &pass, uint32_t& fail) override
        {
            // Functional test cases to run
            TC_add()                ? pass++ : fail++;
            TC_remove()             ? pass++ : fail++;
            TC_checkAvailability()  ? pass++ : fail++;
        }

        // Test Cases
        bool TC_add();
        bool TC_remove();
        bool TC_checkAvailability();
    private:
        eVtol vehicle1;
        eVtol vehicle2;
};

#endif // TEST_CASE_CHARGER_HPP
