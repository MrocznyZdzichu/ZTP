#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

#include "building.h"

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
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_2_editingFinished();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_lineEdit_9_editingFinished();

    void on_lineEdit_8_editingFinished();

    void on_lineEdit_7_editingFinished();

    void on_lineEdit_6_editingFinished();

    void on_lineEdit_10_editingFinished();

    void on_lineEdit_11_editingFinished();

    void on_lineEdit_12_editingFinished();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    void            plotTemperature(QVector<double> xData,
                                    QVector<double> yData);

    void            plotHumidity(QVector<double> xData,
                                 QVector<double> yData);

    void            plotCO2(QVector<double> xData,
                            QVector<double> yData);

    double*         axisLimits(QVector<double> xData,
                               QVector<double> yData);

    void            printComm(QString text);
    bool            isTextNumeric(QString text);
    bool            allFieldsFilled();
    int             getPeopleCount();
    int             getVentsCount();
    double          getCubature();
    double          getOuterTemperature();
    double          getOuterHumidity();
    double          getStartTemperature();
    double          getStartHumidity();
    double          getStartCO2();
    double*         getACPowers();
    double*         getACSPs();
    int             getACCount();

};

#endif // MAINWINDOW_H
