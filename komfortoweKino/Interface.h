#ifndef INTERFACE_H
#define INTERFACE_H

#include "mainwindow.h"
#include <QVector>
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
    static void plotResults(QVector<double> xData,
                            QVector<double> yData,
                            int plotType);
private:
    Interface();
    Interface(const Interface&);

};

#endif // INTERFACE_H
