#include "ac.h"
#include <cmath>

#define co2conc 0.0004
double AC::airMaxSpeed = 5;
double AC::outerCO2 = co2conc;

AC::AC(double SP, double power):
    SP(SP), powerMax(power)
{

}

double AC::changeCO2(const double& co2, const double& cubature, const double& temperature)
{
    double residuum = this->SP - temperature;
    double airFlowIn = airMaxSpeed * (powerMax / 1e6) * tanh(0.5*fabs(residuum));
    return airFlowIn / cubature;
}

double AC::changeHumidity()
{

}

double AC::changeTemperature(const double& temperature)
{
    double residuum = this->SP - temperature;
    return this->powerMax*tanh(0.5*residuum);
}
