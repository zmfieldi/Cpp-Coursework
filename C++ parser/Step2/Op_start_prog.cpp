#include "Op_start_prog.h"

Op_start_prog::Op_start_prog(int opnd){
  name_buffer = "start program";
  oper = opnd;
}

void Op_start_prog::operation(DataMemory* dm){
  //std::cout << oper << std::endl;
  dm->resizeStackUp(oper);

}