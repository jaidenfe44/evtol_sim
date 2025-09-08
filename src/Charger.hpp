#ifndef CHARGER_HPP
#define CHARGER_HPP

#include "eVtol.hpp"

#include <queue>

class Charger
{
    public:
        Charger()
        {
            static uint32_t id = 0;
            Id = id++;
        };

        // TODO
        void add(eVtol* vehicle);

        // TODO
        void remove();

        // TODO
        uint32_t checkAvailability();

        uint32_t Id = 0;

    private:
        std::queue<eVtol*> chargingQueue;
};

#endif // CHARGER_HPP
