#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "StringTable.h"
#include "InstructionMemory.h"
#include "DataMemory.h"
#include "RunTime.h"





int main(int argc, char** argv){
  int pc = 0;
  std::string fName = argv[1];

  InstructionMemory imem(fName);

  DataMemory* dm_stack = new DataMemory;
  std::vector<std::shared_ptr<Stmt>> i_mem = imem.getInstructionMemory();
  std::vector<std::shared_ptr<Stmt>> s_buff = imem.getStringBuffer();

  RunTime* rt_stack = new RunTime; 
  std::vector<int> return_add; 
  
  // for(int i = 0; i < i_mem.size(); i++){
  //   if(i_mem[i]->name_buffer == "start program"){
  //     i_mem[i]->operation(dm_stack);
  //   }
  // }

  int end_index = 0;
  //std::cout << i_mem.size();
  for(int i = 0; i < i_mem.size(); i++){
    if(i_mem[i]->name_buffer == "exit"){
      end_index = i;
    }
  }
  
  int sub_route_vars = 0;
  // for(int i = 0; i < i_mem.size(); i++){
  //   std::cout << i_mem[0]->name_buffer;
  // }
  //int sub_offset = 0;
  //int temp_sub = 0;
  while(pc != end_index){
    //std::cout << "CURRENT PC: "<< pc << std::endl;
    //std::cout << i_mem[pc]->name_buffer << std::endl;
    // for(int i = 0; i < rt_stack->getSize(); i++){
    //   std::cout << rt_stack->getLocVal(i) << " ";
    // }
    // std::cout << std::endl;
    if(i_mem[pc]->name_buffer == "start program"){
      //std::cout << "done" << std::endl;
      i_mem[pc]->operation(dm_stack);
      pc++;
    }
    
    else if(i_mem[pc]->name_buffer == "enter sub"){
      i_mem[pc]->operation(dm_stack);
      sub_route_vars = i_mem[pc]->getOper();
      //temp_sub = i_mem[pc]->getOper();
      //sub_offset += i_mem[pc]->getOper();
      //std::cout << sub_offset << std::endl;
      pc++;
    }
    
    else if(i_mem[pc]->name_buffer == "gosub"){
      return_add.push_back(pc + 1);
      pc = i_mem[pc]->getOper();
    }

    else if(i_mem[pc]->name_buffer == "return"){

      int temp = pc;
      
      //std::cout << pc << std::endl;
      //std::cout << sub_route_vars << std::endl;
      //std::cout << "BEFORE: "<<dm_stack->getSize() << std::endl;
      //std::cout << i_mem[temp]->name_buffer << std::endl;
      i_mem[temp]->operation(dm_stack, sub_route_vars);
      pc = return_add.back();
      return_add.pop_back();
      //dm_stack->resizeStackDown();
      //std::cout << "AFTER: " << dm_stack->getSize() << std::endl;
      //std::cout << sub_offset << std::endl;
      //sub_offset -= temp_sub;
      //sub_route_vars = 0;
      //exit(EXIT_FAILURE);
      
    }

    else if(i_mem[pc]->name_buffer == "jumpnzero"){
      int top = rt_stack->getLast();
      rt_stack->eraseBack();
      if(top != 0){
        pc = i_mem[pc]->getOper();
      }
      else{
        pc++;
      }
    }

    

    else if(i_mem[pc]->name_buffer == "jumpzero"){
      int top = rt_stack->getLast();
      rt_stack->eraseBack();
      if(top == 0){
        pc = i_mem[pc]->getOper();
      }
      else{
        pc++;
      }
    }

    else if(i_mem[pc]->name_buffer == "jump"){
      pc = i_mem[pc]->getOper();
    }

    else if(i_mem[pc]->name_buffer == "pushi" || i_mem[pc]->name_buffer == "add" || i_mem[pc]->name_buffer == "mul" || i_mem[pc]->name_buffer == "dup" || i_mem[pc]->name_buffer == "negate" || i_mem[pc]->name_buffer == "swap" || i_mem[pc]->name_buffer == "pop" || i_mem[pc]->name_buffer == "printtos" || i_mem[pc]->name_buffer == "div") {
      //rt_stack->printEl();
      //std::cout << "done" << std::endl;
      i_mem[pc]->operation(rt_stack);
      //std::cout << "THIS "<< pc << rt_stack->getLast( ) << std::endl;
      pc++;
    }

    else if(i_mem[pc]->name_buffer == "popScalar" || i_mem[pc]->name_buffer == "pushscalar"){
      i_mem[pc]->operation(rt_stack, dm_stack);
      pc++;
    }
    else if(i_mem[pc]->name_buffer == "pop array" || i_mem[pc]->name_buffer == "pusharray") {
      //std::cout << dm_stack->getSize() << std::endl;
      
      i_mem[pc]->operation(rt_stack, dm_stack);
      pc++;
    }

    

    else if(i_mem[pc]->name_buffer == "prints") {
      std::cout << s_buff[i_mem[pc]->getOper()]->name_buffer << std::endl;
      pc++;
    }

    
  }

  //std::cout << dm_stack->getSize() << std::endl;

  //imem.printIMem();

}
