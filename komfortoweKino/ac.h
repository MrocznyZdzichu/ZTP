#ifndef AC_H
#define AC_H

#include <string>
#include "Component.h"
class AC : public Component
{
private:
    const std::string     mode;
    const double          power;
public:
    AC(std::string mode, double power);
    virtual double  changeCO2();
    virtual double  changeHumidity();
    virtual double  changeTemperature();
};

#endif // AC_H
