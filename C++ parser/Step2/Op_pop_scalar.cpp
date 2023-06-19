#include "Op_pop_scalar.h"

Op_pop_scalar::Op_pop_scalar(int opnd) {
    name_buffer = "popScalar";
    oper = opnd;
}

void Op_pop_scalar::operation(RunTime* rt, DataMemory* dm){
    int val = rt->getLast();
    rt->eraseBack();
    //dm->pushBack(0);
    dm->addToLoc(oper, val);
}

