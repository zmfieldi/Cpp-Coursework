#include "Op_swap.h"

Op_swap::Op_swap(){
  name_buffer = "swap";
}

void Op_swap::operation(RunTime* rt){
  int temp = rt->getSecond();

  rt->pushOn(rt->getLast());
  rt->addStack(temp);
}