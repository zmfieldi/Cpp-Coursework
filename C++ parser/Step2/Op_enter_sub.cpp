#include "Op_enter_sub.h"

Op_enter_sub::Op_enter_sub(int opnd){
  name_buffer = "enter sub";
  oper = opnd;
}

void Op_enter_sub::operation(DataMemory* dm){
  dm->resizeStackUp(oper);
}

int Op_enter_sub::getOper(){
  return oper;
}