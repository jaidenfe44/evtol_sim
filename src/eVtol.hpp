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
         * Calculate the flight time and set the taskTime to that value
         *
         * We also update the passenger miles here
         */
        void computeFlightTime()
        {
            taskTime = flightTime;
            passengerMiles += passMilesPerFlight;
        }

        /**
         * Calculate the time it takes to Charge and set it to taskTime
         */
        void computeChargeTime()
        {
            taskTime = chargeTime;
        }

        /**
         * Compute if a fault occurred and increment the fault variable
         *
         * This function should be called once a sim hour
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

        // Which company the vehicle belongs to
		eVtolCompany company;
        // The state the vehicle is in
        VehicleState state = VehicleState::eAirborne;
        // The time the current task will take (in seconds)
        uint32_t taskTime = 0;

        // The time the vehicle has spent queued (in seconds)
        uint32_t queueTime = 0;

        // The index of the charger the vehicle is using
        uint32_t vehicleCharger = 0;

	protected:
        // The cruise speed of the vehicle (mph)
		uint32_t speed = 0;
        // The battery capacity (kWh)
		uint32_t battCapacity = 0;
        // The amount of time to fully charge the batter (in seconds)
		uint32_t chargeTime = 0;
        // Energy used at cruise (kWh/mile)
		float energyConsumption = 0;
        // Passenger count per flight
		unsigned int passengers = 0;
        // Probability of a fault occurring per hour (percentage i.e. 0.25)
		float faultProbability = 0;
        // Number of miles traveled per flight, on one battery charge, in miles (battery capacity / energy consumption)
        uint32_t range = 0;
        // The amount of time, in seconds, a flight takes on a full battery ((3600/speed) * range)
        uint32_t flightTime = 0;

        // Total number of miles passengers have flown
        uint32_t passengerMiles = 0;
        // Number of total faults
        uint32_t faults = 0;
        // Number of passenger miles per flight (passengers * range)
        uint32_t passMilesPerFlight = 0;

        /**
         * Initialize values based on company specific stats
         *
         * Set range, flight time, and passenger miles per flight
         *
         * @return void
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
