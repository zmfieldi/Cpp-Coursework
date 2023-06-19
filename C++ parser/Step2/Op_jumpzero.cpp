#include "Op_jumpzero.h"

Op_jumpzero::Op_jumpzero(int opnd){
  name_buffer = "jumpzero";
  oper = opnd;
}

int Op_jumpzero::getOper(){
  return oper;
}