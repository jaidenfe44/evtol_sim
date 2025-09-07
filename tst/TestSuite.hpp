
#include <chrono>


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
		std::chrono::milliseconds execTime;

		// TODO: Test Cases
};
