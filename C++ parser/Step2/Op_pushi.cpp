#include "Op_pushi.h"

Op_pushi::Op_pushi(int opnd){
  name_buffer = "pushi";
  oper = opnd;
}

void Op_pushi::operation(RunTime* rt) { 
  rt->addStack(oper);
}