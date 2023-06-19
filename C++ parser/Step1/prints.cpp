#include <iostream>
#include "prints.h"

Prints::Prints(std::string print_this, int print_count){
  op_code = "Prints";
  to_be_printed = print_this;
  print_num = print_count;
}



void Prints::printOps(std::ofstream& file){
  //std::cout << op_code << " " << to_be_printed << std::endl;
  file << op_code << " " << print_num << "\n";
}