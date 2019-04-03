#ifndef HUMAN_H
#define HUMAN_H
#include "Component.h"

class Human : public Component
{
public:
    Human();
    static constexpr double thermalResistance = 0.3;
    static constexpr double temperature = 273.15 + 36.6;
    virtual double  changeCO2();
    virtual double  changeHumidity();
    virtual double  changeTemperature();
};

#endif // HUMAN_H
