#ifndef INTERFACE_H
#define INTERFACE_H

#include "mainwindow.h"
#include <QVector>

struct InputData;
class Interface
{
//-----------------attributes--------------------
public:
private:
    static MainWindow* appWindow;
//------------------methods---------------------
public:
    static Interface    getInstance();
    static void         setWindow(MainWindow* appWindow);
    static void         showWindow();
    static InputData    getInputData();
    static void         printComm(std::string text);
    static void         plotResults(QVector<double> xData,
                                    QVector<double> yData,
                                    int plotType);
private:
    Interface();
    Interface(const Interface&);

};

struct InputData
{
    int                         peopleCount;
    int                         ventCount;
    std::vector<std::string>    unitModes;
    std::vector<double>         unitPowers;
    double                      cubature;
    double                      outerTemperature;
    double                      outerHumidity;
    double                      startTemperature;
    double                      startHumidity;
    double                      startCO2;
};

#endif // INTERFACE_H
