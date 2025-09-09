#ifndef PORT_HPP
#define PORT_HPP

#include "System.hpp"
#include "Charger.hpp"
#include "eVtol.hpp"
#include "Alpha.hpp"
#include "Bravo.hpp"
#include "Charlie.hpp"
#include "Delta.hpp"
#include "Echo.hpp"

#include <array>

class Port
{
	public:
		static Port& getInstance()
		{
			static Port inst;
			return inst;
		};
        Port(const Port&) = delete;
        Port& operator=(const Port&) = delete;

		void step();

        void addToCharger(eVtol* vehicle);

        void removeFromCharger(eVtol* vehicle);

		void generateReport();

	private:
		Port();

		std::array<eVtol, numVehicles> vehicles_a;
		std::array<Charger, numChargers> chargers_a;

        Charger* nextAvailableCharger = nullptr;

        void updateNextAvailable();
    #ifdef TEST_SUITE
        friend class TestCase_Port;
    #endif
};

#endif // PORT_HPP
