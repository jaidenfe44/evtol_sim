#ifndef EVTOL_HPP
#define EVTOL_HPP

#include <string>

/**
 * TODO
 */
enum class VehicleState
{
    eAirborne,
    eCharging,
    eQueued
};


/**
 * TODO
 */
class eVtol
{
	public:
        void atCharger(uint32_t charger)
        {
            vehicleCharger = charger;
        }

        void computeFlightTime()
        {
            taskTime = flightTime;
        }

        void computeChargeTime()
        {
            taskTime = chargeTime;
        }

		std::string company;
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
        uint32_t range = 0;
        uint32_t flightTime = 0;

        void init()
        {
            range             = battCapacity / energyConsumption;
            flightTime        = (3600 / speed) * range;
        };

	private:
};

#endif // EVTOL_HPP
