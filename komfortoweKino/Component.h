#ifndef COMPONENT_H
#define COMPONENT_H

#define airDensity      1.2
#define waterMolMass    0.018
#define Rgas            8.31446

#include <cmath>
class Component
{
public:
    Component();
    virtual ~Component();

    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature) = 0;
    virtual double  changeHumidity(const double& humidity, const double& co2,
                                   const double& temperature, const double& cubature) = 0;
    virtual double  changeTemperature(const double& temperature) = 0;
protected:
    double maxVaporPressure(const double& temperature);
};

#endif // COMPONENT_H
