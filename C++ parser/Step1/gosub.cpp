#include <iostream>
#include "gosub.h"

GoSub::GoSub(std::string _label){
  op_code = "GoSub ";
  label_name = _label;
}

void GoSub::printOps(std::ofstream& file){
  file << op_code << label_numloc << "\n";
}

void GoSub::setLabelNum(int num){
  label_numloc = num;
}

std::string GoSub::getLabelName(){
  return label_name;
}