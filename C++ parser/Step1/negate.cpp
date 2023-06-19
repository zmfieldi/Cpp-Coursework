#include <iostream>
#include "negate.h"

Negate::Negate(){
  op_code = "Negate";
}

void Negate::printOps(std::ofstream& file){
  file << op_code << "\n";
}