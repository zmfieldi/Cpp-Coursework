#include <iostream>
#include "jumpnzero.h"

JumpNZero::JumpNZero(std::string _label){
  op_code = "JumpNZero, ";
  label_name = _label;
}

void JumpNZero::printOps(std::ofstream& file){
  file << "JumpNZero " << label_numloc << "\n";
}

void JumpNZero::setLabelName(std::string _label){
  label_name = _label;
}

void JumpNZero::setLabelNum(int num){
  label_numloc = num;
}

std::string JumpNZero::getLabelName(){
  return label_name;
}