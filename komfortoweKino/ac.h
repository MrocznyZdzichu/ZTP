#ifndef AC_H
#define AC_H

#include <string>
#include "Component.h"
/*!
 * \brief Class implementing air conditioning within building.
 * AC class herits from Component class and implement its virtual change... methods.
 * Instances of this class are created in GUI.
 */
class AC : public Component
{
private:
    const double    SP;
    const double    powerMax;
    static double   airMaxSpeed;
    static double   outerCO2;
    static double   outerHumidity;
public:
    /*!
     * \brief Initialising constructor. Nothing special
     * \param sp Set Point of temperature in degC. AC will try to maintain room's temperature at set point. AC works like P regulator.
     * \param power Power of air conditioner in W.
     */
    AC(double sp, double power);
    /*!
     * \brief This method overrides Component::changeCO2 pure virtual function. It is called by Building::Simulation().
     * \param co2 Current CO2 concentration in room as a decimal.
     * \param cubature Room's volume in m3.
     * \param temperature Current temperature in room in degC.
     * \return Derivative of CO2 concentration introduced into room by air conditioner.
     */
    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature);
    /*!
     * \brief This method overrides Component::changeHumidity pure virtual function. It is called by Building::Simulation().
     * \param humidity Current relative humidity in room as a decimal.
     * \param co2 Current CO2 concentration in room as a decimal.
     * \param temperature Current room's temperature in degC.
     * \param cubature Room's volume in m3.
     * \return Derivative of relative humidity introduced into room by air conditioner.
     */
    virtual double  changeHumidity(const double& humidity, const double& co2,
                                   const double& temperature, const double& cubature);
    /*!
     * \brief This method overrides Component::changeTemperature pure virtual function. It is called by Building::Simulation().
     * \param temperature Current romm's temperature in degC.
     * \return  Derivative of temeprature introduced into room by air conditioner.
     */
    virtual double  changeTemperature(const double& temperature);
    /*!
     * \brief This method sets static field determining outer humidity for all AC instances.
     * It is called during Building creation and when simulation parameters are being updated.
     * \param humidity Outer relative humidity as a decimal.
     */
    static void setOuterHumidity(const double& humidity);
    /*!
     * \brief This method sets static field determining outer CO2 concentration for all AC instances.
     * It is called during Building creation and when simulation parameters are being updated.
     * \param humidity Outer CO2 concentration as a decimal
     */
    static void setOuterCO2(const double& humidity);
};

#endif // AC_H
