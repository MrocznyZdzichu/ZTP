#include "Component.h"

Component::Component()
{

}
Component::~Component()
{

}

double Component::maxVaporPressure(const double &temperature)
{
    return 6.1121 * exp((17.502 * temperature)/(240.97 + temperature));
}
