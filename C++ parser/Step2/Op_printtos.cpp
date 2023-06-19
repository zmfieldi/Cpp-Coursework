#include "Op_printtos.h"
 
Op_printtos::Op_printtos( ) {
    name_buffer = "printtos";
}

void Op_printtos::operation(RunTime* rt) { 
  // std::cout << "start" << std::endl;
  // rt->printEl();
  // std::cout << "end" << std::endl;
  int val =  rt->getLast();
  std::cout << val << std::endl;
  rt->eraseBack( );
}


