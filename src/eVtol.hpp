#ifndef EVTOL_HPP
#define EVTOL_HPP

#include <string>

/**
 * enumeration of the eVTOL companies
 */
enum eVtolCompany
{
    eAlpha = 0,
    eBravo,
    eCharlie,
    eDelta,
    eEcho
};


/**
 * Vehicle states representing what the vehicles current task is
 */
enum class VehicleState
{
    eAirborne,  // Currently flying
    eCharging,  // Currently charging
    eQueued     // Waiting to charge
};


/**
 * eVTOL vehicle base class
 *
 * Each company vehicle is derrived from this class, with their specifications
 */
class eVtol
{
	public:
        /**
         * update the vehicleCharger index
         *
         * @param uint32_t charger - the charger index where the vehicle is charging
         *
         * @return void
         */
        void atCharger(uint32_t charger)
        {
            vehicleCharger = charger;
        }

        /**
         * TODO
         */
        void computeFlightTime()
        {
            taskTime = flightTime;
            passengerMiles += passMilesPerFlight;
        }

        /**
         * TODO
         */
        void computeChargeTime()
        {
            taskTime = chargeTime;
        }

        /**
         * TODO
         */
        void computeFault()
        {
            (rand() % 100) < (faultProbability * 100) ? faults++ : faults;
        };

        /**
         * Get the Flight Time in minutes
         *
         * Note: The flight time onboard is in seconds so we convert from
         * seconds to minutes
         *
         * @return uint32_t - Flight time in minutes
         */
        uint32_t getFlightTime(){return flightTime/60;};

        /**
         * Get the Charge Time in minutes
         *
         * Note: The charge time onboard is in seconds, so we convert
         * from seconds to minutes
         *
         * @return uint32_t - Charge time in minutes
         */
        uint32_t getChargeTime(){return chargeTime/60;};

        /**
         * Get the Range, in miles, of a single flight on one fully
         * charged battery
         *
         * @return uint32_t - The milage range of a single flight
         */
        uint32_t getRange(){return range;};

        /**
         * Get the accumulated number of passenger miles
         *
         * @return uint32_t - The number of passenger miles
         */
        uint32_t getPassengerMiles(){return passengerMiles;};

        /**
         * Get the number of faults experienced by the vehicle
         *
         * @return uint32_t - Number of faults
         */
        uint32_t getFaults(){return faults;};

		eVtolCompany company;
        VehicleState state = VehicleState::eAirborne;
        // TODO: (in seconds)
        uint32_t taskTime = 0;

        // TODO: (in seconds)
        uint32_t queueTime = 0;
        uint32_t vehicleCharger = 0;

	protected:
		uint32_t speed = 0;
		uint32_t battCapacity = 0;
		uint32_t chargeTime = 0; // In Seconds
		float energyConsumption = 0;
		unsigned int passengers = 0;
		float faultProbability = 0;
        uint32_t range = 0; // Number of miles traveled per flight (on one charge)
        uint32_t flightTime = 0;

        uint32_t passengerMiles = 0;
        uint32_t faults = 0;
        uint32_t passMilesPerFlight = 0;

        /**
         * TODO
         */
        void init()
        {
            range              = battCapacity / energyConsumption;
            flightTime         = (3600 / speed) * range;
            passMilesPerFlight = passengers * range;
        };

    #ifdef TEST_SUITE
        friend class TestCase_Charger;
    #endif
};

#endif // EVTOL_HPP
