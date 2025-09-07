
#include "eVtol.hpp"

class Alpha: public eVtol
{
    public:
        Alpha()
        {
            company           = "Alpha";
            speed             = 120;
            battCapacity      = 320;
            chargeTime        = 36;
            energyConsumption = 1.6;
            passengers        = 4;
            faultProbability  = 0.25;
        }
};
