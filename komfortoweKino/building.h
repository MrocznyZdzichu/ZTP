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
struct Conditions
{
    double  temperature;
    double  humidity;
    double  CO2;

    Conditions(double CO2, double humidity, double temperature):
        CO2(CO2), humidity(humidity), temperature(temperature){}
    Conditions(){}
};
struct InputData;
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
    const double            cubature;
    QTimer*                 trigger;
    int                     counter;
//-----------methods------------------
public:
    static Building& get(const InputData& Parameters)
    {
        static Building instance(Parameters);
        return instance;
    }
    void    startSim();
    void    stopSim();

private:
    Building(const InputData& Parameters);
    void    changeComponents(const InputData& Parameters);
    void    simulate();
    void    drawResults();

private slots:
    void    onTimeout();
};

#endif // BUILDING_H
