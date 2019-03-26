#include "Interface.h"

MainWindow *Interface::appWindow;
Interface Interface::getInstance()
{
    static Interface instance;
    return instance;
}

Interface::Interface()
{

}

Interface::Interface(const Interface &)
{

}

void Interface::showWindow()
{
    Interface::appWindow->show();
}

void Interface::setWindow(MainWindow *appWindow)
{
    Interface::appWindow = appWindow;
}

InputData Interface::getInputData()
{
    InputData Parameters;
    Parameters.peopleCount = appWindow->getPeopleCount();
    Parameters.ventCount = appWindow->getVentsCount();
    Parameters.cubature = appWindow->getCubature();
    Parameters.outerTemperature = appWindow->getOuterTemperature();
    Parameters.outerHumidity = appWindow->getOuterHumidity();
    Parameters.startTemperature = appWindow->getStartTemperature();
    Parameters.startHumidity = appWindow->getStartHumidity();
    Parameters.startCO2 = appWindow->getStartCO2();

    int acCount = appWindow->getACCount();

    double* acPowers = appWindow->getACPowers();
    for (int i = 0; i < acCount; i++)
        Parameters.unitPowers.push_back(acPowers[i]);

    std::string* acModes = appWindow->getACModes();
    for (int i = 0; i < acCount; i++)
        Parameters.unitModes.push_back(acModes[i]);

    return Parameters;
}

void Interface::plotResults(QVector<double> xData,
                            QVector<double> yData,
                            int plotType)
{
    switch (plotType)
    {
    case 1:
        Interface::appWindow->plotTemperature(xData, yData);
        break;

    case 2:
        Interface::appWindow->plotHumidity(xData, yData);
        break;

    case 3:
        Interface::appWindow->plotCO2(xData, yData);
        break;
    }
}

void Interface::printComm(std::string text)
{
    QString QText = QString::fromStdString(text);
    Interface::appWindow->printComm(QText);
}
