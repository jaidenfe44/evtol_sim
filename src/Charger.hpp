#ifndef CHARGER_HPP
#define CHARGER_HPP

#include "eVtol.hpp"

#include <queue>


/**
 * TODO
 */
class Charger
{
    public:
        /**
         * Charger class constructor
         *
         * As objects are created they are given an ID.
         * Because the Charger objects are created when we create the
         * charger array, the IDs are also used as indexes into the
         * charger array. While this is a simplification for the sim,
         * it has its drawbacks. If other chargers were created elsewhere
         * this ID being used as an index into an array might cause errors.
         * This would be fixed in further development.
         */
        Charger()
        {
            static uint32_t id = 0;
            Id = id++;
        };

        /**
         * Add a vehicle to the Charger queue
         *
         * Objects at the front of the queue are considered to be
         * "charging" while objects further in the queue are considered
         * "queued" or "waiting for the charger".
         *
         * @return void
         */
        void add(eVtol* vehicle);

        /**
         * TODO
         */
        void remove();

        /**
         * TODO
         */
        uint32_t checkAvailability();

        /**
         * The Charger ID
         *
         * This ID is also used to index into the Port::chargers_a
         * Cherger array
         */
        uint32_t Id = 0;

    private:

        /**
         * The charging queue
         *
         * TODO
         */
        std::queue<eVtol*> chargingQueue;

    #ifdef TEST_SUITE
        friend class TestCase_Charger;
        friend class TestCase_Port;
    #endif
};

#endif // CHARGER_HPP
