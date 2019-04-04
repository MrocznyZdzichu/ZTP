#include "Human.h"

Human::Human()
{

}

double Human::changeCO2()
{

}

double Human::changeHumidity()
{

}

double Human::changeTemperature(const double& temperature)
{
    double residuum = this->temperature - temperature;
    return residuum/this->thermalResistance;
}
