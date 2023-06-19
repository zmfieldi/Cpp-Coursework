#include <iostream>
#include "mul.h"

Mul::Mul(){
  op_code = "Mul";
}

void Mul::printOps(std::ofstream& file){
  file << op_code << "\n";
}