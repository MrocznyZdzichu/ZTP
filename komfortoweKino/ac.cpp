#include "ac.h"
#include <cmath>

AC::AC(double SP, double power):
    SP(SP), powerMax(power)
{

}

double AC::changeCO2()
{

}

double AC::changeHumidity()
{

}

double AC::changeTemperature(const double& temperature)
{
    double residuum = this->SP - temperature;
    return this->powerMax*tanh(0.5*residuum);
}
