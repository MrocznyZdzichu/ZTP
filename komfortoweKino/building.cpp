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
                     Parameters.outerTemperature)),
    counter(0)
{
    this->changeComponents(Parameters);

    trigger = new QTimer(this);
    trigger->setInterval(1000);
    connect(trigger, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void Building::simulate()
{
    //state vector: x[0] - temperature
    //              x[1] - CO2 concentration
    //              x[2] - air dampness
    stateVector x;
    if (counter == 60)
    {
        x.push_back(this->Initial.temperature);
        x.push_back(this->Initial.CO2);
        x.push_back(this->Initial.humidity);
    }

    else
    {
        x.push_back(*(this->historyTemperature.end()-1));
        x.push_back(*(this->historyCO2.end()-1));
        x.push_back(*(this->historyHumidity.end()-1));
    }
    std::vector<stateVector>    states;
    std::vector<double>         times;
    odeSystem system(this->cubature, airDensity, airSpecificHeat, this->HVAC_people);

    size_t steps = odeint::integrate(system, x, this->counter-60, this->counter,
                                     1, observer(states, times));

    for (const auto& state : states)
    {
        this->historyTemperature.push_back(state[0]);
        this->historyCO2.push_back(state[1]);
        this->historyHumidity.push_back(state[2]);
    }

    for (const auto& timestamp : times)
    {
        this->simTimes.push_back(timestamp);
    }
}

void Building::drawResults()
{
    Interface::plotResults(this->simTimes, this->historyTemperature, 1);
    Interface::plotResults(this->simTimes, this->historyCO2, 3);
    Interface::plotResults(this->simTimes, this->historyHumidity, 2);
}

void Building::changeComponents(const InputData &Parameters)
{
    this->HVAC_people.clear();

    for (int i = 0; i < Parameters.peopleCount; i++)
        this->HVAC_people.push_back(new Human());

    for (int i = 0; i < Parameters.ventLengths.size(); i++)
        this->HVAC_people.push_back(new Vent(Parameters.ventLengths[i],
                                             Parameters.ventAreas[i],
                                             Parameters.ventSpeed[i]));

    Vent::setOuterTemperature(Parameters.outerTemperature);
    Vent::setOuterCO2(co2conc);
    Vent::setOuterHumidity(Parameters.outerHumidity);

    AC::setOuterCO2(co2conc);
    AC::setOuterHumidity(Parameters.outerHumidity);

    for (int i = 0; i < Parameters.unitModes.size(); i++)
    {
        this->HVAC_people.push_back(new AC(Parameters.unitModes[i],
                                           Parameters.unitPowers[i]));
    }
}

void Building::changeOuter(const InputData& Parameters)
{
    this->cubature = Parameters.cubature;

    this->Outer = Conditions(co2conc,
                     Parameters.outerHumidity,
                     Parameters.outerTemperature);
}
void Building::onTimeout()
{
    this->counter += 60;

    InputData currentDataSet = Interface::getInputData();

    this->changeComponents(currentDataSet);
    this->changeOuter(currentDataSet);

    this->simulate();
    this->drawResults();

}

void Building::startSim()
{
    this->trigger->start();
}

void Building::stopSim()
{
    this->trigger->stop();
}
