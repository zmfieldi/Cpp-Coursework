#include "Op_return.h"

Op_return::Op_return(){
  name_buffer = "return";
}

void Op_return::operation(DataMemory* dm, int n){
  //std::cout << "BEFORE: "<<dm->getSize() << std::endl;
  dm->resizeStackDown( );
  //std::cout << "AFTER: "<<dm->getSize() << std::endl;  
}