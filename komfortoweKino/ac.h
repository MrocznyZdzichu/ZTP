#ifndef AC_H
#define AC_H

#include <string>
#include "Component.h"
class AC : public Component
{
private:
    const double    SP;
    const double    powerMax;
    static double   airMaxSpeed;
    static double   outerCO2;
public:
    AC(double mode, double power);
    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature);
    virtual double  changeHumidity();
    virtual double  changeTemperature(const double& temperature);
    void operator() ()
    {

    }
};

#endif // AC_H
