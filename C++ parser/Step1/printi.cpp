#include <iostream>
#include "printi.h"

Printi::Printi(std::string print_this){
  op_code = "Prints";
  to_be_printed = print_this;
}



void Printi::printOps(std::ofstream& file){
  file << to_be_printed << "\n";
}