#include <iostream>
#include "gosublabel.h"

GoSubLabel::GoSubLabel(std::string _label){
  op_code = "GoSubLabel ";
  label_name = _label;
}

void GoSubLabel::printOps(std::ofstream& file){
  file << op_code << label_numloc << "\n";
}

void GoSubLabel::setLabelNum(int num){
  label_numloc = num;
}

std::string GoSubLabel::getLabelName(){
  return label_name;
}