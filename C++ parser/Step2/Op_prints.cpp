#include "Op_prints.h"

#include <stdio.h>


Op_prints::Op_prints(int opnd){
  name_buffer = "prints";
  oper = opnd;
}

void Op_prints::operations(std::vector<std::shared_ptr<Stmt>> s_buff){
  std::cout << s_buff[oper]->name_buffer << std::endl;
}

int Op_prints::getOper( ) {
  return oper;
}