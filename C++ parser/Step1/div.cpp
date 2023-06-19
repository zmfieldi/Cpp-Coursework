#include <iostream>
#include "div.h"

Div::Div(){
  op_code = "Div";
}

void Div::printOps(std::ofstream& file){
  file << op_code << "\n";
}
