
#include "eVtol.hpp"

class Bravo: public eVtol
{
    public:
        Bravo()
        {
            company           = "Bravo";
            speed             = 100;
            battCapacity      = 100;
            chargeTime        = 12;
            energyConsumption = 1.5;
            passengers        = 5;
            faultProbability  = 0.1;
        }
};
