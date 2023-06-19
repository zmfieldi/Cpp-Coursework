#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

#include <string>

class Automobile {
private:
    int vehicleID;
    float miles;
    std::string date;

public:
    Automobile(int _vehicleID, float _miles, int _mm, int _dd, int _yyyy);
    std::string mainteneceData();
    int vehicleData();
    int milesData();

};

#endif