#include <iostream>
#include "Address.h"
#include "Employee.h"

int main(int argc, char** args) {
   Address* add1 = new Address(new std::string("1281 Gruene Rd"), new std::string("Greune"), 
                               new std::string("TX"), 78130);
   Address* add2 = new Address(new std::string("801 Bldg"), new std::string("Yorktown Heights"), 
                               new std::string("NY"), 10598);
   std::cout << "add1:\n"+add1->getAddress( ) << std::endl;
   std::cout << "add2:\n"+add2->getAddress( ) << std::endl;
   
   Employee* emp1 = new Employee(new std::string("Jerry Jeff Walker"), 3, 16, 1942, add1, 55000);
   Employee* emp2 = new Employee(new std::string("Fran Allen"), 8, 4, 1932, add2, 256000);

   std::cout << "Employee1: " << emp1->getRole( ) << ", " << emp1->getName( ) << ", ";
   std::cout << emp1->getZipCode( ) << std::endl;

   std::cout << "Employee2: " << emp2->getRole( ) << ", " << emp2->getName( ) << ", ";
   std::cout << emp2->getZipCode( ) << std::endl;
}
