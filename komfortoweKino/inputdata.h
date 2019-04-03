#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <vector>
#include <string>
struct InputData
{
    int                         peopleCount;
    int                         ventCount;
    std::vector<double>         unitModes;
    std::vector<double>         unitPowers;
    double                      cubature;
    double                      outerTemperature;
    double                      outerHumidity;
    double                      startTemperature;
    double                      startHumidity;
    double                      startCO2;
};

#endif // INPUTDATA_H
