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
		std::string company;
        VehicleState state = VehicleState::eAirborne;
        uint32_t taskTime = 0;
        uint32_t queueTime = 0;

	protected:
		unsigned int speed;
		unsigned int battCapacity;
		float chargeTime; // In Minutes
		float energyConsumption;
		unsigned int passengers;
		float faultProbability;

	private:
};

#endif // EVTOL_HPP
