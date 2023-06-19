#include <string>
#include <iostream>
#include "Automobile.h"

int main(int argc, char* argv[]) {
    Automobile* automobile1 = new Automobile(5, 6, 12, 10,2022);
    std::cout << automobile1->vehicleData() << std::endl;
    std::cout << automobile1->milesData() << std::endl;
    std::cout << automobile1->mainteneceData() << std::endl;

    Automobile* automobile2 = new Automobile(5, 5, 5, 5, 2020);
    std::cout << automobile2->vehicleData() << std::endl;
    std::cout << automobile2->milesData() << std::endl;
    std::cout << automobile2->mainteneceData() << std::endl;
};