#include "InstructionMemory.h"
#include <iostream>
#include <fstream>
#include "Op_jumpnzero.h"
#include "Op_jumpzero.h"
#include "Op_jump.h"
#include "Op_gosub.h"
#include "Op_return.h"
#include "Op_pushscalar.h"
#include "Op_pusharray.h"
#include "Op_pushi.h"
#include "Op_pop.h"
#include "Op_mul.h"
#include "Op_div.h"
#include "Op_prints.h"
#include "Op_printtos.h"
#include "Op_pop_scalar.h"
#include "Op_pop_array.h"
#include "Op_dup.h"
#include "Op_swap.h"
#include "Op_enter_sub.h"
#include "Op_start_prog.h"
#include "Op_exit.h"
#include "Op_negate.h"
#include "Op_add.h"
#include "Words.h"

InstructionMemory::InstructionMemory(std::string fName){
  std::ifstream file;

  file.open(fName);
  std::string line;
  std::vector<std::string> vec_of_strings;
  int num_lines = 0;

  while(getline(file,line)){
    vec_of_strings.push_back(line);
    num_lines++;
  }

  for(int i = 0; i < num_lines; i++){
    std::string inst = vec_of_strings[i];
   



    if(inst.substr(0,9) == "JumpNZero"){
      int opnd = stoi(inst.substr(10));
      std::shared_ptr<Stmt> my_ptr(new Op_jumpnzero(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,8) == "JumpZero"){
      int opnd = stoi(inst.substr(9));
      std::shared_ptr<Stmt> my_ptr(new Op_jumpzero(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,4) == "Jump") {
      int opnd = stoi(inst.substr(5));
      std::shared_ptr<Stmt> my_ptr(new Op_jump(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,10) == "GoSubLabel") {
      int opnd = stoi(inst.substr(11));
      std::shared_ptr<Stmt> my_ptr(new Op_enter_sub(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,5) == "GoSub"){
  
      int opnd = stoi(inst.substr(6));
      std::shared_ptr<Stmt> my_ptr(new Op_gosub(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,6) == "Return"){
      std::shared_ptr<Stmt> my_ptr(new Op_return());
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,10) == "PushScalar"){
      int opnd = stoi(inst.substr(11));
      std::shared_ptr<Stmt> my_ptr(new Op_pushscalar(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,9) == "PushArray"){
      int opnd = stoi(inst.substr(10));
      std::shared_ptr<Stmt> my_ptr(new Op_pusharray(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,5) == "PushI"){
      int opnd = stoi(inst.substr(6));
      std::shared_ptr<Stmt> my_ptr(new Op_pushi(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,9) == "PopScalar"){
      int opnd = stoi(inst.substr(10));
      std::shared_ptr<Stmt> my_ptr(new Op_pop_scalar(opnd));
      i_buffer.push_back(my_ptr);
    }

     else if(inst.substr(0,8) == "PopArray"){
      int opnd = stoi(inst.substr(9));
      std::shared_ptr<Stmt> my_ptr(new Op_pop_array(opnd));
      i_buffer.push_back(my_ptr);
     }

    else if(inst.substr(0,3) == "Pop"){
    
      std::shared_ptr<Stmt> my_ptr(new Op_pop());
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,3) == "Dup"){
      std::shared_ptr<Stmt> my_ptr(new Op_dup());
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,4) == "Swap"){
      std::shared_ptr<Stmt> my_ptr(new Op_swap());
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,3) == "Add"){
      std::shared_ptr<Stmt> my_ptr(new Op_add());
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,6) == "Negate"){
      std::shared_ptr<Stmt> my_ptr(new Op_negate());
      i_buffer.push_back(my_ptr);
    }
    
    else if(inst.substr(0,3) == "Mul"){
      std::shared_ptr<Stmt> my_ptr(new Op_mul());
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,3) == "Div") {
      std::shared_ptr<Stmt> my_ptr(new Op_div());
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,6) == "Prints"){
      int opnd = stoi(inst.substr(7));
      std::shared_ptr<Stmt> my_ptr(new Op_prints(opnd));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,8) == "PrintTOS"){
      std::shared_ptr<Stmt> my_ptr(new Op_printtos( ));
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,5) == "Start") {
      int opnd = stoi(inst.substr(6));
      std::shared_ptr<Stmt> my_ptr(new Op_start_prog(opnd));
      //std::cout << "PUSHES BACK START" << std::endl;
      i_buffer.push_back(my_ptr);
    }

    else if(inst.substr(0,4) == "Exit") {
      std::shared_ptr<Stmt> my_ptr(new Op_exit());
      i_buffer.push_back(my_ptr);
    }

    

    else{
      std::shared_ptr<Stmt> my_ptr(new Words(inst));
      s_buff.push_back(my_ptr);
    }
  }
}

std::vector<std::shared_ptr<Stmt>> InstructionMemory::getInstructionMemory(){
  return i_buffer;
}

std::vector<std::shared_ptr<Stmt>> InstructionMemory::getStringBuffer(){
  return s_buff;
}



void InstructionMemory::printIMem(){
  for(int i = 0; i < i_buffer.size(); i++){
    std::shared_ptr<Stmt> cur_op = i_buffer[i];
    std::cout << cur_op->name_buffer << std::endl;
  }
}
