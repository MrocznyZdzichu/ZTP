#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
typedef std::vector<double> stateVector;
/*!
 * \brief Structure used to read and store values and timestamp in each integration step during ODE solving.
 */
struct observer
{
    std::vector<stateVector>& states;
    std::vector<double>& times;

    observer(std::vector<stateVector>& x, std::vector<double>& t)
        :   states(x), times(t) {}

    void operator() (const stateVector& x, double t)
    {
        states.push_back(x);
        times.push_back(t);
    }
};

#endif // OBSERVER_H
