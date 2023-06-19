#include <iostream>
#include <string> 

#include "Automobile.h"

Automobile:: Automobile(int _vehicleID, float _miles, int _mm, int _dd, int _yyyy) {
    vehicleID = _vehicleID;
    miles =_miles;
    mm = _mm;
    dd = _dd;
    yyyy = _yyyy;
}

std::string Automobile::mainteneceData() {
    combine = std::to_string(mm)+"/"+std::to_string(dd)+"/"+std::to_string(yyyy);
    return combine;
}

int Automobile::vehicleData() {
    return vehicleID;
}

int Automobile::milesData() {
    return miles;
}



