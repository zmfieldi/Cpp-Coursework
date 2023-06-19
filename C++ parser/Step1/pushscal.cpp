#include <iostream>
#include "pushscal.h"


PushScal::PushScal(std::string _var,int _loc){
  op_code = "PushScalar ";
  var = _var;
  loc = _loc;
}

void PushScal::printOps(std::ofstream& file){
  file << op_code << loc << "\n";
}