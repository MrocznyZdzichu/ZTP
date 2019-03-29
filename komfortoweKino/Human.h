#ifndef HUMAN_H
#define HUMAN_H
#include "Component.h"

class Human : public Component
{
public:
    Human();
    virtual double  changeCO2();
    virtual double  changeHumidity();
    virtual double  changeTemperature();
};

#endif // HUMAN_H
