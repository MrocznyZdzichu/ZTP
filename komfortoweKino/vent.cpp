
#include "vent.h"

Vent::Vent(double length, double area, double speed) :
    length(length), area(area), speed(speed)
{
    this->k = Vent::k0 * sqrt(this->speed + 1);
    this->thermalResistance = this->length /
                                (this->k * this->area);
}

double Vent::changeCO2()
{

}

double Vent::changeHumidity()
{

}

double Vent::changeTemperature()
{

}
