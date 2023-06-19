#include "Op_add.h"

Op_add::Op_add(){
  name_buffer = "add";
  
}

void Op_add::operation(RunTime* rt){ 
  rt->pushOn(rt->getSecond() + rt->getLast());
}