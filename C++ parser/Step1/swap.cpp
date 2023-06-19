#include <iostream>
#include "swap.h"

Swap::Swap(){
  op_code = "Swap";
}

void Swap::printOps(std::ofstream& file){
  file << op_code << "\n";
}