#ifndef COMPONENT_H
#define COMPONENT_H

#define airDensity      1.2
#define waterMolMass    0.018
#define Rgas            8.31446

#include <cmath>
/*!
 * \brief Abstract class used for comfortable computing how dervied objects: Human, AC and Vent
 * changes temperature, relative humidity and CO2 concentration in given room.
 */
class Component
{
public:
    Component();
    virtual ~Component();
    /*!
     * \brief Virtual method overriden in Human, AC and Vent.
     * \param co2 current CO2 concentration as a decimal.
     * \param cubature room's volume in m3.
     * \param temperature current temperature in room in degC.
     * \return derivative of CO2 concentration introduced by Component derived class' object.
     */
    virtual double  changeCO2(const double& co2, const double& cubature, const double& temperature) = 0;
    /*!
     * \brief Virtual method overriden in Human, AC and Vent.
     * \param humidity current relative humidity as a decimal
     * \param co2 current CO2 concentration as a decimal.
     * \param temperature current temperature in room in degC.
     * \param cubature room's volume in m3.
     * \return derivative of relative humidity introduced by Component derived class' object.
     */
    virtual double  changeHumidity(const double& humidity, const double& co2,
                                   const double& temperature, const double& cubature) = 0;
    /*!
     * \brief Virtual method overriden in Human, AC and Vent.
     * \param temperature current temperature in room in degC.
     * \return derivative of temperature introduced by Component derived class' object.
     */
    virtual double  changeTemperature(const double& temperature) = 0;
protected:
    double maxVaporPressure(const double& temperature);
};

#endif // COMPONENT_H
