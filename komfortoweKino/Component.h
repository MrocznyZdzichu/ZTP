#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
    Component();
    virtual double  changeCO2() = 0;
    virtual double  changeHumidity() = 0;
    virtual double  changeTemperature() = 0;
};

#endif // COMPONENT_H
