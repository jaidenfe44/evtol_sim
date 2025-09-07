
#include "eVtol.hpp"

class Echo: public eVtol
{
    public:
        Echo()
        {
            company           = "Echo";
            speed             = 30;
            battCapacity      = 150;
            chargeTime        = 18;
            energyConsumption = 5.8;
            passengers        = 2;
            faultProbability  = 0.61;
        }
};
