#include "vent.h"

double Vent::outerTemperature;
double Vent::outerCO2;

Vent::Vent(double length, double area, double speed) :
    length(length), area(area), speed(speed)
{
    this->k = Vent::k0*exp(-1*speed/3);
    this->thermalResistance = k * length / area;
}

double Vent::changeCO2(const double& co2, const double& cubature, const double& temperature)
{
    return ((Vent::outerCO2 - co2) * this->speed * this->area) / (cubature);
}

double Vent::changeHumidity()
{

}

double Vent::changeTemperature(const double& temperature)
{
    double residuum = Vent::outerTemperature - temperature;
    return residuum/this->thermalResistance;
}

void Vent::setOuterTemperature(const double &temperature)
{
    Vent::outerTemperature = temperature;
    return;
}

void Vent::setOuterCO2(const double &co2)
{
    Vent::outerCO2 = co2;
    return;
}
