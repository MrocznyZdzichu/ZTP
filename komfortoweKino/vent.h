#ifndef VENT_H
#define VENT_H

#include "Component.h"
#include <cmath>

class Vent : public Component
{
private:
    static constexpr double k0 = 0.5;
    static double outerTemperature;
    static double outerCO2;

    const double length;
    const double area;
    const double speed;
    double k;
    double thermalResistance;
public:
    Vent(double length, double area, double speed);
    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature);
    virtual double  changeHumidity();
    virtual double  changeTemperature(const double& temperature);
    static void     setOuterTemperature(const double& temperature);
    static void     setOuterCO2(const double& co2);
};

#endif // VENT_H
