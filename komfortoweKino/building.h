#ifndef BUILDING_H
#define BUILDING_H

#include "Component.h"
#include "inputdata.h"
#include <QVector>

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
{
//-----------attributes---------------
private:
    QVector<Component*>     HVAC_people;
    QVector<double>         historyCO2;
    QVector<double>         historyHumidity;
    QVector<double>         historyTemperature;
    Conditions              Initial;
    Conditions              Outer;
    const double            cubature;
//-----------methods------------------
public:
    Building(const InputData& Parameters);
    void    update();
    void    drawResults();
};



#endif // BUILDING_H
