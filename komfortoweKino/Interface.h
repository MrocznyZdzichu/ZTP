#ifndef INTERFACE_H
#define INTERFACE_H

#include "mainwindow.h"
#include "inputdata.h"
#include <QVector>
/*!
 * \brief Class composed of set of static methods
 * used to perform two-directional communication
 * between program's logic and GUI MainWindow object.
 */
class Interface
{
//-----------------attributes--------------------
public:
private:
    static MainWindow* appWindow;
//------------------methods---------------------
public:
    /*!
     * \brief This methods sets appWindow attribute as a reference to GUI window.
     * \param appWindow GUI window.
     */
    static void         setWindow(MainWindow* appWindow);
    /*!
     * \brief This method renders GUI window.
     */
    static void         showWindow();
    /*!
     * \brief This methods reads all simulation parameters from MainWindow
     * \return Simulation parameters read from GUI and packed into one InputData structure
     */
    static InputData    getInputData();
    /*!
     * \brief This methods prints simple log in MainWindow textBrowser.
     * \param text Log text to be written on GUI.
     */
    static void         printComm(std::string text);
    /*!
     * \brief This methods plots single time-serie. For correct working this method needs
     * xData and yData to be same size QVectors.
     * \param xData X-axis values.
     * \param yData Y-axis values.
     * \param plotType 1 - temperature chart, 2 - humidity chart, 3 - CO2 chart
     */
    static void         plotResults(QVector<double> xData,
                                    QVector<double> yData,
                                    int plotType);
private:
    Interface();
    Interface(const Interface&);

};



#endif // INTERFACE_H
