#include <iostream>
#include <string>
#include "Person.h"

Person::Person(std::string* _name, int _birthMonth, int _birthDay, int _birthYear, Address* _address) { 
   name = _name;
   dateOfBirth = new std::string(std::to_string(_birthMonth)+"/"+std::to_string(_birthDay)+"/"+std::to_string(_birthYear)); // this should be the only line in the constructor body
   address = _address;
}

std::string getRole( ) { 
   return "unknown";
}
