#include <iostream>
#include "printtos.h"



PrintTos::PrintTos(){
  op_code = "PrintTOS";
}

void PrintTos::printOps(std::ofstream& file){
  file << op_code << "\n";
}