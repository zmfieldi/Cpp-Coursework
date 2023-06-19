#include "Op_mul.h"

Op_mul::Op_mul(){
  name_buffer = "mul";
}

void Op_mul::operation(RunTime* rt){ 
  rt->pushOn(rt->getLast() * rt->getSecond());
}