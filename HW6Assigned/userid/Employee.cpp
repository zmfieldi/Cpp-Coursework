#include "Address.h"
#include "Person.h"
#include "Employee.h"

Employee::Employee(std::string* _name, int _birthMonth, int _birthDay, int _birthYear, Address* _address, double _salary) { 
   salary = _salary; 
}

std::string Employee::getRole( ) { 
   return "Employee";
}

double getSalary( ) { 
   return salary;
}
