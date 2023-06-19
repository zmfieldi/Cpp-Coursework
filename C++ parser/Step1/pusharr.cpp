#include <iostream>
#include "pusharr.h"

PushArr::PushArr(std::string _var,int _loc){
  op_code = "PushArr ";
  var = _var;
  loc = _loc;
}

void PushArr::printOps(std::ofstream& file){
  file << "PushArray " << loc << "\n";
}