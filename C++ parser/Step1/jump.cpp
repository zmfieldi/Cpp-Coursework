#include <iostream>
#include "jump.h"
#include <fstream>
Jump::Jump(std::string _label){
  op_code = "Jump, ";
  label_name = _label;
}

void Jump::printOps(std::ofstream& file){
  file << "Jump " << label_numloc << "\n";
}

void Jump::setLabelName(std::string _label){
  label_name = _label;
}

void Jump::setLabelNum(int num){
  label_numloc = num;
}

std::string Jump::getLabelName(){
  return label_name;
}