#ifndef ODETEMPERTURE_H
#define ODETEMPERTURE_H

#include "Component.h"
#include <numeric>
#include <QVector>


typedef std::vector<double> stateVector;
/*!
 * \brief Class packaging Ordinary Differential Equation solved by Boost's odeint.
 * Solving itself is performed by calling operator ()/
 */
class odeSystem
{
public:
    /*!
     * \brief Constructor setting up ode parameters/
     * \param cubature Room's volume in m3.
     * \param density Air density: constant = 1.2 kg/m3
     * \param specificHeat Air specific heat: constant = 1005 J/kgK
     * \param building_HVAC_people Vector of state-changing objects in room.
     */
    odeSystem(double cubature, double density, double specificHeat,
                   QVector<Component*> building_HVAC_people);

    void operator() (const stateVector &x , stateVector &dxdt , const double t )
    {
        double sum = 0.0;
        for (int i = 0; i < this->HVAC_people.size(); i++)
            sum += HVAC_people[i]->changeTemperature(x[0]);
        dxdt[0] = sum/this->thermalCapacity;

        if (x[1] < 0.21)
        {
            sum = 0.0;
            for (int i = 0; i < this->HVAC_people.size(); i++)
                sum += HVAC_people[i]->changeCO2(x[1], this->cubature, x[0]);
            dxdt[1] = sum;
        }
        else
            dxdt[1] = 0;

        if (x[2] < 1)
        {
            sum = 0.0;
            for (int i = 0; i < this->HVAC_people.size(); i++)
                sum += HVAC_people[i]->changeHumidity(x[2], x[1], x[0], this->cubature);
            dxdt[2] = sum;
        }
        else
            dxdt[2] = 0;
    }
private:
    double thermalCapacity;
    double cubature;
    QVector<Component*> HVAC_people;
};


#endif // ODETEMPERTURE_H
