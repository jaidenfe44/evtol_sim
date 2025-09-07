
#include "eVtol.hpp"

class Delta: public eVtol
{
    public:
        Delta()
        {
            company           = "Delta";
            speed             = 90;
            battCapacity      = 120;
            chargeTime        = 37.2;
            energyConsumption = 0.8;
            passengers        = 2;
            faultProbability  = 0.22;
        }
};
