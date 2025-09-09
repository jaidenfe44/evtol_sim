
#include "eVtol.hpp"

class Bravo: public eVtol
{
    public:
        Bravo()
        {
            company           = eVtolCompany::eBravo;
            speed             = 100;
            battCapacity      = 100;
            chargeTime        = 720; // 3600 * 0.2
            energyConsumption = 1.5;
            passengers        = 5;
            faultProbability  = 0.1;

            init();
        }
};
