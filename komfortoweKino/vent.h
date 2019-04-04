#ifndef VENT_H
#define VENT_H

#include "Component.h"
#include <cmath>

class Vent : public Component
{
private:
    static constexpr double k0 = 0.025;
    static double outerTemperature;
    const double length;
    const double area;
    const double speed;
    double k;
    double thermalResistance;
public:
    Vent(double length, double area, double speed);
    virtual double  changeCO2();
    virtual double  changeHumidity();
    virtual double  changeTemperature(const double& temperature);
    static void     setOuterTemperature(const double& temperature);
};

#endif // VENT_H
