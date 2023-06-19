#include <iostream>
#include "exit.h"

Exit::Exit(){
  op_code = "Exit";
}

void Exit::printOps(std::ofstream& file){
  file << op_code << "\n";
}

