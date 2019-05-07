#include "vent.h"

double Vent::outerTemperature;
double Vent::outerCO2;
double Vent::outerHumidity;

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

double Vent::changeHumidity(const double& humidity, const double& co2,
                            const double& temperature, const double& cubature)
{
    double insideH20conc = (waterMolMass * humidity * maxVaporPressure(temperature))/
                            (airDensity * Rgas * temperature);

    double outsideH20conc = (waterMolMass * Vent::outerHumidity * maxVaporPressure(temperature))/
                             (airDensity * Rgas * temperature);

    double volume = this->speed * this->area;
    double massFlowOut = insideH20conc * airDensity * volume;
    double massFlowIn  = outsideH20conc * airDensity * volume;

    double deltaH20    = massFlowIn - massFlowOut;

    double molFlow     = deltaH20 / waterMolMass;
    double vaporPressure = Rgas * temperature * molFlow / cubature;

    return vaporPressure / maxVaporPressure(temperature);
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

void Vent::setOuterHumidity(const double &humidity)
{
    Vent::outerHumidity = humidity;
    return;
}
