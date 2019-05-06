#include "Human.h"

Human::Human()
{

}

double Human::changeCO2(const double& co2, const double& cubature, const double& temperature)
{
    return (efficiency(co2) * airMorphSpeed * breathVolume )/ cubature;
}

double Human::changeHumidity()
{

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
