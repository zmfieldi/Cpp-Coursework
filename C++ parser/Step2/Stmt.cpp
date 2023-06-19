#include <string>
#include "Stmt.h"


void Stmt::operation(){

}

void Stmt::operation(DataMemory* dm){
  
}

void Stmt::operation(RunTime* rm){

}

void Stmt::operation(DataMemory* dm, int n){
  std::cout << "hi" << std::endl;
}

void Stmt::operation(RunTime* rt, DataMemory* dm){
  
}

void Stmt::operation(RunTime* rt, DataMemory* dm, int n){
  
}

void Stmt::operation(std::vector<std::shared_ptr<Stmt>> sbuff){

}

int Stmt::getOper(){
  return 100;
}