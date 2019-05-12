#ifndef HUMAN_H
#define HUMAN_H

#define airMorphSpeed   0.04
#define vaporizeSpeed   0.00005
#define breathVolume    5e-4

#include "Component.h"

class Human : public Component
{
public:
    /*!
     * \brief Default constructor.
     */
    Human();
    /*!
     * \brief This method overrides Component::changeCO2 pure virtual function. It is called by Building::Simulation().
     * \param co2 Current CO2 concentration in room as a decimal.
     * \param cubature Room's volume in m3.
     * \param temperature Current temperature in room in degC.
     * \return Derivative of CO2 concentration introduced into room by single Human object.
     */
    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature);
    /*!
     * \brief This method overrides Component::changeHumidity pure virtual function. It is called by Building::Simulation().
     * \param humidity Current relative humidity in room as a decimal.
     * \param co2 Current CO2 concentration in room as a decimal.
     * \param temperature Current room's temperature in degC.
     * \param cubature Room's volume in m3.
     * \return Derivative of relative humidity introduced into room by single Human object.
     */
    virtual double  changeHumidity(const double& humidity, const double& co2,
                                   const double& temperature, const double& cubature);
    /*!
     * \brief This method overrides Component::changeTemperature pure virtual function. It is called by Building::Simulation().
     * \param temperature Current romm's temperature in degC.
     * \return  Derivative of temeprature introduced into room by single Human object.
     */
    virtual double  changeTemperature(const double& temperature);
private:
    static constexpr double thermalResistance = 0.3;
    static constexpr double temperature = 36.6;
    double efficiency(const double& co2);
};

#endif // HUMAN_H
