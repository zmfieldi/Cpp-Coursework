#include "Op_jumpnzero.h"

Op_jumpnzero::Op_jumpnzero(int opnd){
  name_buffer = "jumpnzero";
  oper = opnd;
}

int Op_jumpnzero::getOper(){
  return oper;
}