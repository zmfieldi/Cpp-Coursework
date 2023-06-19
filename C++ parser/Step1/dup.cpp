#include <iostream>
#include "dup.h"

Dup::Dup(){
  op_code = "Dup";
}

void Dup::printOps(std::ofstream& file){
  file << op_code << "\n";
}