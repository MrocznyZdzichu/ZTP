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
    static Interface getInstance();
    static void setWindow(MainWindow* appWindow);
    static void showWindow();
    static void getInputData();
    static void plotResults(QVector<double> xData,
                            QVector<double> yData,
                            int plotType);
    static void printComm(std::string text);
private:
    Interface();
    Interface(const Interface&);

};

struct InputData
{

};

#endif // INTERFACE_H
