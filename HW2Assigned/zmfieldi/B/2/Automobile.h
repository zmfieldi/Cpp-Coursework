#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

#include <string>

class Automobile {
private:
    int vehicleID;
    float miles;
    int dd;
    int mm;
    int yyyy;
    std::string combine;

public:
    Automobile(int _vehicleID, float _miles, int _mm, int _dd, int _yyyy);
    std::string mainteneceData();
    int vehicleData();
    int milesData();

};

#endif