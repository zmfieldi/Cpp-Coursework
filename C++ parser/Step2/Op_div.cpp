#include "Op_div.h"

Op_div::Op_div(){
  name_buffer = "div";
}

void Op_div::operation(RunTime* rt){ 
  rt->pushOn(rt->getLast() / rt->getSecond());
}