#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <vector>
#include <string>
struct InputData
{
    int                         peopleCount;
    std::vector<double>         unitModes;
    std::vector<double>         unitPowers;
    std::vector<double>         ventLengths;
    std::vector<double>         ventAreas;
    std::vector<double>         ventSpeed;
    double                      cubature;
    double                      outerTemperature;
    double                      outerHumidity;
    double                      startTemperature;
    double                      startHumidity;
    double                      startCO2;
};

#endif // INPUTDATA_H
