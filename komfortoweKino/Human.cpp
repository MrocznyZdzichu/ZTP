#include "Human.h"

Human::Human()
{

}

double Human::changeCO2(const double& co2, const double& cubature, const double& temperature)
{
    return (efficiency(co2) * airMorphSpeed * breathVolume )/ cubature;
}

double Human::changeHumidity(const double& humidity, const double& co2,
                             const double& temperature, const double& cubature)
{
    double vaporMassFlow    = efficiency(co2) * vaporizeSpeed * breathVolume * airDensity;
    double vaporMolFlow     = vaporMassFlow / waterMolMass;
    double dpdt             = (Rgas * (temperature + 273.15) * vaporMolFlow) / cubature;

    return dpdt / maxVaporPressure(temperature);
}

double Human::changeTemperature(const double& temperature)
{
    double residuum = this->temperature - temperature;
    return residuum/this->thermalResistance;
}

double Human::efficiency(const double& co2)
{
    double eff = (-1/0.21) * co2 + 1;
    if (eff < 0.0)
        eff = 0.0;
    return eff;
}


