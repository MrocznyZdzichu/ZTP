#ifndef VENT_H
#define VENT_H

#include "Component.h"
class Vent : public Component
{
public:
    Vent();
    virtual double  changeCO2();
    virtual double  changeHumidity();
    virtual double  changeTemperature();
};

#endif // VENT_H
