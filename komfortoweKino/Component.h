#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
    Component();
    virtual double  changeCO2() = 0;
    virtual double  changeHumidity() = 0;
    virtual double  changeTemperature(const double& temperature) = 0;
};

#endif // COMPONENT_H
