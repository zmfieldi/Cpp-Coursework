#include "Op_dup.h"

Op_dup::Op_dup(){
  name_buffer = "dup";
}

void Op_dup::operation(RunTime* rt){ 
  rt->addStack(rt->getLast());
}