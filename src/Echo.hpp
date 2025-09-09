
#include "eVtol.hpp"

class Echo: public eVtol
{
    public:
        Echo()
        {
            company           = eVtolCompany::eEcho;
            speed             = 30;
            battCapacity      = 150;
            chargeTime        = 1080; // 3600 * 0.3
            energyConsumption = 5.8;
            passengers        = 2;
            faultProbability  = 0.61;

            init();
        }
};
