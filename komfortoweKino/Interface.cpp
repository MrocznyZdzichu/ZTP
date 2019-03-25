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

void Interface::plotTemperature(std::vector<double> xData, std::vector<double> yData)
{

}

void Interface::plotHumidity(std::vector<double> xData, std::vector<double> yData)
{

}

void Interface::plotCO2(std::vector<double> xData, std::vector<double> yData)
{

}

void Interface::plotResults(std::vector<double> xData,
                            std::vector<double> yData,
                            int plotType)
{
    switch (plotType)
    {
    case 1:
        Interface::plotTemperature(xData, yData);
        break;

    case 2:
        Interface::plotHumidity(xData, yData);
        break;

    case 3:
        Interface::plotCO2(xData, yData);
        break;
    }
}
