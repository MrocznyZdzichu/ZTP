#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
    Component();
    virtual ~Component();

    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature) = 0;
    virtual double  changeHumidity() = 0;
    virtual double  changeTemperature(const double& temperature) = 0;
};

#endif // COMPONENT_H
