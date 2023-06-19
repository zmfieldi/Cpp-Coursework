#include "Op_pop.h"

Op_pop::Op_pop( ) {
    name_buffer = "pop";
}

void Op_pop::operation(RunTime* rt){
  rt->eraseBack();
}