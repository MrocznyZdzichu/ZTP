#ifndef BUILDING_H
#define BUILDING_H

#include "ac.h"
#include "vent.h"
#include "Human.h"
#include "inputdata.h"
#include "odeSystem.h"
#include <QVector>
#include <QTimer>
#include "boost/numeric/odeint.hpp"

typedef std::vector<double> stateVector;
/*!
 * \brief The Conditions struct storing temperature, humidity and CO2 concentration.
 * It is composed with Building class - it uses Condition for comapct information
 * about initial and outer conditions.
 */
struct Conditions
{
    double  temperature;
    double  humidity;
    double  CO2;

    /*!
     * \brief Initialising constructor. Nothing special.
     * \param CO2 CO2 concentration as a decimal.
     * \param humidity Relative humidity as a decimal.
     * \param temperature Temperature in degC.
     */
    Conditions(double CO2, double humidity, double temperature):
        CO2(CO2), humidity(humidity), temperature(temperature){}
    Conditions(){}
};
struct InputData;
/*!
 * \brief The Building class is a singleton class holding simulation parameters. It also stores state-changing objects
 * id est Human, AC and Vent class objects as an aggregation. Building class has methods performing the simulation
 * and QTimer object which triggers it.
 */
class Building
        :public QObject
{
    Q_OBJECT
//-----------attributes---------------
private:
    QVector<Component*>     HVAC_people;
    QVector<double>         historyCO2;
    QVector<double>         historyHumidity;
    QVector<double>         historyTemperature;
    QVector<double>         simTimes;
    Conditions              Initial;
    Conditions              Outer;
    double                  cubature;
    QTimer*                 trigger;
    int                     counter;
//-----------methods------------------
public:
    /*!
     * \brief Typical singleton get-instance method. It is called after "uruchom symulacje" button is clicked.
     * \param Parameters simulation parameters read from GUI. They are used to initialise Building static instance
     * during 1-st time call.
     * \return Pointer to Building singleton instance.
     */
    static Building& get(const InputData& Parameters)
    {
        static Building instance(Parameters);
        return instance;
    }
    /*!
     * \brief This method starts QTimer resposible for repetetive quasi real-time simulations.
     * QTimer timeouts each 1sec performing next simulation step.
     */
    void    startSim();
    /*!
     * \brief This method pauses QTimer making simulation stopped.
     */
    void    stopSim();

private:
    Building(const InputData& Parameters);
    void    changeComponents(const InputData& Parameters);
    void    changeOuter(const InputData& Parameters);
    void    simulate();
    void    drawResults();

private slots:
    void    onTimeout();
};

#endif // BUILDING_H
