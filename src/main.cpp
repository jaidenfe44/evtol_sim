#include "System.hpp"
#include "Port.hpp"



/**
 * Main loop of the simulation
 *
 * In charge of handling stepping through the sim and managing the system counts and simulation report generation
 */
int main() {
	// Initialize System Ticks (minutes)
	unsigned int sysCount = 0;

	// Initialize the Station Hub object
	Port &port = Port::getInstance();

	// Main Loop
	while(sysCount < simRuntime)
	{
		// Step through one sim minute
		port.step();

		sysCount++;
	}

	// Generate the simulation report
	port.generateReport();

	return 0;
}
