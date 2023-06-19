#include <iostream>
#include "pop.h"

Pop::Pop(){
  op_code = "Pop";
}

void Pop::printOps(std::ofstream& file){
  file << op_code << std::endl;
}