
#include <chrono>
#include "TestCase_eVtol.hpp"
#include "TestCase_Charger.hpp"
#include "TestCase_Port.hpp"


class TestSuite
{
	public:
		static TestSuite& getInstance()
		{
			static TestSuite inst;
			return inst;
		}

		void run();

		void report();


	private:
		unsigned int passed = 0;
		unsigned int failed = 0;
		std::chrono::microseconds execTime;

		// Test Cases
        TestCase_eVtol   tceVtol;
        TestCase_Charger tcCharger;
        TestCase_Port    tcPort;
};
