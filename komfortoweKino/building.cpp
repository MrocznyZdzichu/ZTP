#define co2conc             0.0004
#define airDensity          1.2
#define airSpecificHeat     1005.0

#include "building.h"
#include "Component.h"
#include "observer.h"
#include "Interface.h"
#include <numeric>

using namespace boost::numeric;

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

    for (int i = 0; i < Parameters.ventLengths.size(); i++)
        this->HVAC_people.push_back(new Vent(Parameters.ventLengths[i],
                                             Parameters.ventAreas[i],
                                             Parameters.ventSpeed[i]));

    Vent::setOuterTemperature(this->Outer.temperature);
    Vent::setOuterCO2(co2conc);

    for (int i = 0; i < Parameters.unitModes.size(); i++)
    {
        this->HVAC_people.push_back(new AC(Parameters.unitModes[i],
                                           Parameters.unitPowers[i]));
    }
}

void Building::simulate()
{
    //state vector: x[0] - temperature
    //              x[1] - CO2 concentration
    //              x[2] - air dampness
    stateVector x;
    x.push_back(this->Initial.temperature);
    x.push_back(this->Initial.CO2);

    std::vector<stateVector>    states;
    std::vector<double>         times;
    odeSystem system(this->cubature, airDensity, airSpecificHeat, this->HVAC_people);

    size_t steps = odeint::integrate(system, x, 0, 1800, 1, observer(states, times));

    std::vector<double> temperatures;
    std::vector<double> co2History;
    for (const auto& state : states)
    {
        temperatures.push_back(state[0]);
        co2History.push_back(state[1]);
    }

    this->simTimes = QVector<double>::fromStdVector(times);
    this->historyTemperature = QVector<double>::fromStdVector(temperatures);
    this->historyCO2 = QVector<double>::fromStdVector(co2History);
}

void Building::drawResults()
{
    Interface::plotResults(this->simTimes, this->historyTemperature, 1);
    Interface::plotResults(this->simTimes, this->historyCO2, 3);
}
