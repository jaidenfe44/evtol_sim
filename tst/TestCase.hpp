#ifndef TEST_CASE_HPP
#define TEST_CASE_HPP

#include <cstdlib>
#include <cstdio>

class TestCase
{
	public:
		virtual void run(uint32_t &pass, uint32_t &fail) = 0;

		virtual void cleanup() = 0;

		constexpr void tcAssert(bool expr, const char* func, const char* msg = "Assertion Failed!")
		{
		    if(!expr)
		    {   
		        printf("        [%s] %s\n", func, msg);
				tcPass = false;
		    }
		}

		bool tcPass = true;
};

#endif // TEST_CASE_HPP
