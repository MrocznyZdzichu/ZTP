#ifndef VENT_H
#define VENT_H

#include "Component.h"
#include <cmath>

class Vent : public Component
{
private:
    static constexpr double k0 = 0.5;
    static double outerTemperature;
    static double outerCO2;
    static double outerHumidity;

    const double length;
    const double area;
    const double speed;
    double k;
    double thermalResistance;
public:
    /*!
     * \brief Initialising constructor, nothing special.
     * \param length Length of air route in ventilation in m.
     * \param area Surface of ventilation cross-section in m2.
     * \param speed Speed of air in ventilation in m/s.
     */
    Vent(double length, double area, double speed);
    /*!
     * \brief This method overrides Component::changeCO2 pure virtual function. It is called by Building::Simulation().
     * \param co2 Current CO2 concentration in room as a decimal.
     * \param cubature Room's volume in m3.
     * \param temperature Current temperature in room in degC.
     * \return Derivative of CO2 concentration introduced into room by single Vent object.
     */
    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature);
    /*!
     * \brief This method overrides Component::changeHumidity pure virtual function. It is called by Building::Simulation().
     * \param humidity Current relative humidity in room as a decimal.
     * \param co2 Current CO2 concentration in room as a decimal.
     * \param temperature Current room's temperature in degC.
     * \param cubature Room's volume in m3.
     * \return Derivative of relative humidity introduced into room by single Vent object.
     */
    virtual double  changeHumidity(const double& humidity, const double& co2,
                                   const double& temperature, const double& cubature);
    /*!
     * \brief This method overrides Component::changeTemperature pure virtual function. It is called by Building::Simulation().
     * \param temperature Current romm's temperature in degC.
     * \return  Derivative of temeprature introduced into room by single Vent object.
     */
    virtual double  changeTemperature(const double& temperature);
    /*!
     * \brief This method sets static field determining outer temperature for all Vent instances.
     * It is called during Building creation and when simulation parameters are being updated.
     * \param humidity Outer temperature in degC.
     */
    static void     setOuterTemperature(const double& temperature);
    /*!
     * \brief This method sets static field determining outer CO2 concentration for all Vent instances.
     * It is called during Building creation and when simulation parameters are being updated.
     * \param humidity Outer CO2 concentration as a decimal
     */
    static void     setOuterCO2(const double& co2);
    /*!
     * \brief This method sets static field determining outer humidity for all Vent instances.
     * It is called during Building creation and when simulation parameters are being updated.
     * \param humidity Outer relative humidity as a decimal.
     */
    static void     setOuterHumidity(const double& humidity);
};

#endif // VENT_H
