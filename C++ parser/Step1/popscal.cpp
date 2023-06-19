#include <iostream>
#include "popscal.h"

PopScal::PopScal(std::string _var,int _loc){
  op_code = "PopScalar ";
  var = _var;
  loc = _loc;
}

void PopScal::printOps(std::ofstream& file){
  file << op_code << loc << "\n";
}