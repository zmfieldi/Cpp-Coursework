#include <iostream>
#include "start.h"

Start::Start(){
  op_code = "Start";
}

void Start::printOps(std::ofstream& file){
  file << op_code << " " << num_decl << std::endl;
}

void Start::setNumDecl(int _num_decl){
  num_decl = _num_decl;
}
