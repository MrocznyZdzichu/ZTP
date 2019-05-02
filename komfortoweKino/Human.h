#ifndef HUMAN_H
#define HUMAN_H
#include "Component.h"

class Human : public Component
{
public:
    Human();
    virtual double  changeCO2();
    virtual double  changeHumidity();
    virtual double  changeTemperature(const double& temperature);
private:
    static constexpr double thermalResistance = 0.3;
    static constexpr double temperature = 36.6;
};

#endif // HUMAN_H
