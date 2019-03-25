#ifndef INTERFACE_H
#define INTERFACE_H

#include "mainwindow.h"
#include <vector>
class Interface
{
//-----------------attributes--------------------
public:
private:
    static MainWindow* appWindow;
//------------------methods---------------------
public:
    static Interface getInstance();
    static void setWindow(MainWindow* appWindow);
    static void showWindow();
    static void plotResults(std::vector<double> xData,
                     std::vector<double> yData,
                     int plotType);
private:
    Interface();
    Interface(const Interface&);
    static void plotTemperature(std::vector<double> xData,
                                std::vector<double> yData);

    static void plotHumidity(std::vector<double> xData,
                             std::vector<double> yData);

    static void plotCO2(std::vector<double> xData,
                        std::vector<double> yData);
};

#endif // INTERFACE_H
