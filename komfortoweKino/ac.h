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
    static double   outerHumidity;


public:
    AC(double mode, double power);
    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature);
    virtual double  changeHumidity(const double& humidity, const double& co2,
                                   const double& temperature, const double& cubature);
    virtual double  changeTemperature(const double& temperature);

    static void setOuterHumidity(const double& humidity);
    static void setOuterCO2(const double& humidity);
};

#endif // AC_H
