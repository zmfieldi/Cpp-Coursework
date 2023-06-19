#include "Op_jump.h"

Op_jump::Op_jump(int opnd) {
    name_buffer = "jump";
    oper = opnd;
}

int Op_jump::getOper( ) {
    return oper;
}