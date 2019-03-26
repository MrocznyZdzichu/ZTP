#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Interface;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    void plotTemperature(QVector<double> xData,
                         QVector<double> yData);

    void plotHumidity(QVector<double> xData,
                      QVector<double> yData);

    void plotCO2(QVector<double> xData,
                 QVector<double> yData);

    double* axisLimits(QVector<double> xData,
                        QVector<double> yData);

    void printComm(QString text);
};

#endif // MAINWINDOW_H
