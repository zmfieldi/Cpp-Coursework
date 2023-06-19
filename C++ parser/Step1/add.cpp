#include <iostream>
#include "add.h"

Add::Add(){
  op_code = "Add";
}

void Add::printOps(std::ofstream& file){
  file << op_code << "\n";
}