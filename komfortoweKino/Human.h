#ifndef HUMAN_H
#define HUMAN_H

#define airMorphSpeed   0.04
#define vaporizeSpeed   0.00005
#define breathVolume    5e-4

#include "Component.h"

class Human : public Component
{
public:
    Human();
    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature);
    virtual double  changeHumidity(const double& humidity, const double& co2,
                                   const double& temperature, const double& cubature);
    virtual double  changeTemperature(const double& temperature);
private:
    static constexpr double thermalResistance = 0.3;
    static constexpr double temperature = 36.6;
    double efficiency(const double& co2);
};

#endif // HUMAN_H
