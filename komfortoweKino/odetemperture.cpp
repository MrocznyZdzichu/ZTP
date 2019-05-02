#include "odetemperture.h"

odeTemperature::odeTemperature(double cubature, double density, double specificHeat,
                               QVector<Component*> building_HVAC_people)
    : thermalCapacity(cubature*density*specificHeat),
      HVAC_people(building_HVAC_people)
{

}
