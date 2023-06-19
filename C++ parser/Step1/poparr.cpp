#include <iostream>
#include "poparr.h"

PopArr::PopArr(std::string _var,int _loc){
  op_code = "PopArray ";
  var = _var;
  loc = _loc;
}

void PopArr::printOps(std::ofstream& file){
  file << op_code << loc << "\n";
}