

#include "TestSuite.hpp"


int main()
{
	TestSuite &suite = TestSuite::getInstance();

	suite.run();

	suite.report();

	return 0;
}
