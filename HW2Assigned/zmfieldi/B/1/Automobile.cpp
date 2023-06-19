#include <iostream>
#include <string> 

#include "Automobile.h"

Automobile:: Automobile(int _vehicleID, float _miles, int _mm, int _dd, int _yyyy) {
    vehicleID = _vehicleID;
    miles =_miles;
    date = std::to_string(_mm)+"/"+std::to_string(_dd)+"/"+std::to_string(_yyyy);
}

std::string Automobile::mainteneceData() {
    return date;
}

int Automobile::vehicleData() {
    return vehicleID;
}

int Automobile::milesData() {
    return miles;
}


