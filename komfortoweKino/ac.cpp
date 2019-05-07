#include "ac.h"
#include <cmath>

#define co2conc 0.0004

double AC::airMaxSpeed = 5;
double AC::outerCO2 = co2conc;
double AC::outerHumidity;

AC::AC(double SP, double power):
    SP(SP), powerMax(power)
{

}

//    double volume = this->speed * this->area;
//    double massFlowOut = insideH20conc * airDensity * volume;
//    double massFlowIn  = outsideH20conc * airDensity * volume;

//    double deltaH20    = massFlowIn - massFlowOut;

//    double molFlow     = deltaH20 / waterMolMass;
//    double vaporPressure = Rgas * temperature * molFlow / cubature;

//    return vaporPressure / maxVaporPressure(temperature);

double AC::changeCO2(const double& co2, const double& cubature, const double& temperature)
{
    double residuum = this->SP - temperature;
    double area = powerMax * 1e-6; //zalożenie, że "wylot jest im większy im większa moc jednostki"
    double airFlowIn = airMaxSpeed * area * tanh(0.5*fabs(residuum));
    return (AC::outerCO2 - co2) * airFlowIn / cubature;
}

double AC::changeHumidity(const double& humidity, const double& co2,
                          const double& temperature, const double& cubature)
{
    double residuum = this->SP - temperature;

    double area     = powerMax * 1e-6;
    double speed    = airMaxSpeed * tanh(0.5*fabs(residuum));
    double volume   = area * speed;

    double insideH20conc = (waterMolMass * humidity * maxVaporPressure(temperature))/
            (airDensity * Rgas * temperature);

    double outsideH20conc = (waterMolMass * AC::outerHumidity * maxVaporPressure(temperature))/
            (airDensity * Rgas * temperature);

    double massFlowOut = insideH20conc * airDensity * volume;
    double massFlowIn  = outsideH20conc * airDensity * volume;

    double deltaH20    = massFlowIn - massFlowOut;

    double molFlow     = deltaH20 / waterMolMass;
    double vaporPressure = Rgas * temperature * molFlow / cubature;

    return vaporPressure / maxVaporPressure(temperature);
}

double AC::changeTemperature(const double& temperature)
{
    double residuum = this->SP - temperature;
    return this->powerMax*tanh(0.5*residuum);
}

void AC::setOuterHumidity(const double &humidity)
{
    AC::outerHumidity = humidity;
    return;
}

void AC::setOuterCO2(const double &co2)
{
    AC::outerCO2 = co2;
    return;
}
