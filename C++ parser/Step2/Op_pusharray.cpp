#include "Op_pusharray.h"

Op_pusharray::Op_pusharray(int opnd){
  name_buffer = "pusharray";
  oper = opnd;
}

void Op_pusharray::operation(RunTime* rt, DataMemory* dm){
  rt->addStack(oper);
  rt->pushOn(rt->getSecond() + rt->getLast());
  // for (int x = 0; x < dm->getSize(); x++){
  //   std::cout << dm->getLocVal(x) << std::endl;
  // }
  int val = dm->getLocVal(rt->getLast());
  rt->eraseBack();
  rt->addStack(val);
}