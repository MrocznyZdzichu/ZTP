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

void Interface::getInputData()
{

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
