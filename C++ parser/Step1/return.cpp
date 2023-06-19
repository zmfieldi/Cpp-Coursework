#include <iostream>
#include "return.h"


Return::Return(){
  op_code = "Return";
}

void Return::printOps(std::ofstream& file){
  file << op_code << "\n";
}