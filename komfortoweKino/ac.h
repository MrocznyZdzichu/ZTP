#ifndef AC_H
#define AC_H

#include <string>
#include "Component.h"
class AC : public Component
{
private:
    const double SP;
    const double powerMax;
public:
    AC(double mode, double power);
    virtual double  changeCO2();
    virtual double  changeHumidity();
    virtual double  changeTemperature(const double& temperature);
};

#endif // AC_H
