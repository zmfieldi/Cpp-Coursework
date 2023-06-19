#include "Op_pushscalar.h"

Op_pushscalar::Op_pushscalar(int opnd) {
    name_buffer = "pushscalar";
    oper = opnd;
}

void Op_pushscalar::operation(RunTime* rt, DataMemory* dm){
  int val = dm->getLocVal(oper);
  rt->addStack(val);
}