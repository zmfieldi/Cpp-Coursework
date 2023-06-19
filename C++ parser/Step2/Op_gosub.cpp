#include "Op_gosub.h"

Op_gosub::Op_gosub(int opnd){
  name_buffer = "gosub";
  oper = opnd;
}

int Op_gosub::getOper( ) {
    return oper;
}