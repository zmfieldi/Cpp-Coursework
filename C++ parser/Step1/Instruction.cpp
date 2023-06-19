#include <iostream>
#include "Instruction.h"
#include <vector>
#include <memory>
#include "declscal.h"

Instruction::Instruction(){

}

void Instruction::addToBuffer(std::shared_ptr<Stmt> stmt_ptr){
  i_buffer.push_back(stmt_ptr);
  
}

void Instruction::printCurrentBuf(SymbolTable s_table, std::ofstream& file){
  std::map<std::string, std::vector<std::pair<int,int>>> actual_table = s_table.getSymbolTable();
  for(int k = 0; k < i_buffer.size(); k++){
    if(i_buffer[k]->op_code == "JumpNZero, "){
      for(auto it = actual_table.cbegin(); it != actual_table.cend(); ++it){
        //std::cout << "label from symbol" <<it->first << std::endl;
        //std::cout << "label from buf" <<i_buffer[k]->getLabelName() << std::endl;
        if(i_buffer[k]->getLabelName().compare(it->first) == 0){
          //std::cout << "MATCHES" << std::endl;
          std::vector<std::pair<int, int>> vec = it->second;
          std::pair<int,int> pair1 = vec[0];
          int num = pair1.first;
          i_buffer[k]->setLabelNum(num);
        }
      }
    }
    if(i_buffer[k]->op_code == "JumpZero, "){
      for(auto it = actual_table.cbegin(); it != actual_table.cend(); ++it){
        //std::cout << "label from symbol" <<it->first << std::endl;
        //std::cout << "label from buf" <<i_buffer[k]->getLabelName() << std::endl;
        if(i_buffer[k]->getLabelName().compare(it->first) == 0){
          //std::cout << "MATCHES" << std::endl;
          std::vector<std::pair<int, int>> vec = it->second;
          std::pair<int,int> pair1 = vec[0];
          int num = pair1.first;
          i_buffer[k]->setLabelNum(num);
        }
      }
    }
    if(i_buffer[k]->op_code == "Jump, " ){
      for(auto it = actual_table.cbegin(); it != actual_table.cend(); ++it){
        if(i_buffer[k]->getLabelName().compare(it->first) == 0){
          std::vector<std::pair<int, int>> vec = it->second;
          std::pair<int,int> pair1 = vec[0];
          int num = pair1.first;
          i_buffer[k]->setLabelNum(num);
        }
      }
    }
    if(i_buffer[k]->op_code == "GoSub "){
      
      for(auto it = actual_table.cbegin(); it != actual_table.cend(); ++it){
        // std::cout << "label from symbol" <<it->first << std::endl;
        // std::cout << "label from buf" <<i_buffer[k]->getLabelName() << std::endl;
        if(i_buffer[k]->getLabelName().compare(it->first) == 0){
          std::vector<std::pair<int, int>> vec = it->second;
          std::pair<int,int> pair1 = vec[0];
          int num = pair1.first;
          i_buffer[k]->setLabelNum(num);
        }
      }
    }
  }
  for(int i = 0; i < i_buffer.size(); i++){
      i_buffer[i]->printOps(file);
    }
}

std::vector<std::shared_ptr<Stmt>> Instruction::getBuffer(){
  //std::cout<< "enters"<< std::endl;
  //i_buffer[0]->printOps();
  return i_buffer;
}

std::shared_ptr<Stmt> Instruction::getBufElement(int element){
  return i_buffer[element];
}

