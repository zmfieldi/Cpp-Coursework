#include "Op_pop_array.h"

Op_pop_array::Op_pop_array(int opnd){
  name_buffer = "pop array";
  oper = opnd;
}

void Op_pop_array::operation(RunTime* rt, DataMemory* dm){
  int e = rt->getLast() + oper;
  rt->eraseBack();
  int val = rt->getLast();
  rt->eraseBack();
  //dm->resizeStackUp(1000);
  dm->addToLoc(e,val);
}