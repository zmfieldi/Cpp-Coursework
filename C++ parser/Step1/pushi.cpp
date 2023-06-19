#include <iostream>
#include "pushi.h"


PushI::PushI(int op){
  op_code = "PushI";
  operand = op;
}

void PushI::printOps(std::ofstream& file){
  file << op_code << " " << operand << "\n";
}