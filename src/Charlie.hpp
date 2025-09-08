
#include "eVtol.hpp"

class Charlie: public eVtol
{
    public:
        Charlie()
        {
            company           = "Charlie";
            speed             = 160;
            battCapacity      = 220;
            chargeTime        = 2880; // 3600 * 0.8
            energyConsumption = 2.2;
            passengers        = 3;
            faultProbability  = 0.05;

            init();
        }
};
