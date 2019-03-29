#define co2conc 0.0004

#include "building.h"
#include "Human.h"
#include "vent.h"
#include "ac.h"

Building::Building(const InputData& Parameters):
    cubature(Parameters.cubature),
    Initial(Conditions(Parameters.startCO2,
                       Parameters.startHumidity,
                       Parameters.startTemperature)),

    Outer(Conditions(co2conc,
                     Parameters.outerHumidity,
                     Parameters.outerTemperature))
{
    this->historyCO2.push_back(Parameters.startCO2);
    this->historyHumidity.push_back(Parameters.startHumidity);
    this->historyTemperature.push_back(Parameters.startTemperature);

    for (int i = 0; i < Parameters.peopleCount; i++)
        this->HVAC_people.push_back(new Human());

    for (int i = 0; i < Parameters.ventCount; i++)
        this->HVAC_people.push_back(new Vent());

    for (int i = 0; i < Parameters.unitModes.size(); i++)
    {
        this->HVAC_people.push_back(new AC(Parameters.unitModes[i],
                                           Parameters.unitPowers[i]));
    }
}

void Building::update()
{

}

void Building::drawResults()
{

}
