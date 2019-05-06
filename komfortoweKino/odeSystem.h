#ifndef ODETEMPERTURE_H
#define ODETEMPERTURE_H

#include "Component.h"
#include <numeric>
#include <QVector>


typedef std::vector<double> stateVector;
class odeSystem
{
public:
    odeSystem(double cubature, double density, double specificHeat,
                   QVector<Component*> building_HVAC_people);

    void operator() (const stateVector &x , stateVector &dxdt , const double t )
    {
        double sum = 0.0;
        for (int i = 0; i < this->HVAC_people.size(); i++)
            sum += HVAC_people[i]->changeTemperature(x[0]);
        dxdt[0] = sum/this->thermalCapacity;
    }
private:
    double thermalCapacity;
    QVector<Component*> HVAC_people;
};


#endif // ODETEMPERTURE_H
