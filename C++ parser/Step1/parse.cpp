#include "parse.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "declarr.h"
#include "declscal.h"
#include "label.h"
#include "gosublabel.h"
#include "exit.h"
#include "jump.h"
#include "jumpzero.h"
#include "jumpnzero.h"
#include "gosub.h"
#include "return.h"
#include "pushscal.h"
#include "pusharr.h"
#include "pushi.h"
#include "pop.h"
#include "popscal.h"
#include "poparr.h"
#include "dup.h"
#include "swap.h"
#include "add.h"
#include "negate.h"
#include "mul.h"
#include "div.h"
#include "printtos.h"
#include "printi.h"
#include "prints.h"
#include "start.h"
#include "end.h"
#include <memory> 

Parse::Parse(std::string infilename){

  Instruction i_buf;
  SymbolTable s_table;
  std::ifstream file;
  static std::ofstream output_file;
  std::string outFilename = infilename + "test2.pout";
  output_file.open (outFilename);
  //if(output_file == nullptr){std::cout << "null";}
  int num_decl = 0;
  int buf_idx = 0;
  int control_var = 0;
  std::vector<std::string> subroute_vec;
  int label_loc;
  std::vector<std::string> new_level;
  file.open(infilename);
  std::string line;
  std::vector<std::string> vec_of_strings;
  int num_lines = 0; 
  int mem_loc = 0;
  int end_check = 0;
  int sub_check = 0;
  int print_count = 0;
  int sub_len = 0;
  int scalDecl = 0;
  int arrDecl = 0;
  int lblDecl = 0;
  while(getline(file,line)){
    vec_of_strings.push_back(line);
    if (line == "end"){
      end_check++;
    }
    if (line.substr(0,10) == "gosublabel" || line.substr(0,4) == "jump"){
      sub_check++;
    }
    if (line.substr(0,6) == "prints"){
      std::string print_this = line.substr(7);
      std::shared_ptr<Stmt> my_ptr(new Printi(print_this));
      my_ptr->printOps(output_file);
    }
    num_lines++;   
  }
  file.close();
  if (end_check != 1){
    output_file << "error: no end statement in program \n";
    output_file.close();
    exit(EXIT_FAILURE);
  }

  std::string should_bestart = vec_of_strings[0];
  std::string should_beend = vec_of_strings.back();
  if(should_bestart.substr(0,5) != "start"){
    output_file <<"failure \n";
    output_file.close();
    exit(EXIT_FAILURE);
  }
  else{
    std::shared_ptr<Stmt> my_pt(new Start);
    //my_pt->printOps();
    i_buf.addToBuffer(my_pt);
  }


  for(int i = 0; i < num_lines; i++){
    std::string inst = vec_of_strings[i];
    int inst_len = inst.length();

    if(inst.substr(0,8) == "declscal"){
      scalDecl++;
      char var = inst[9];
      std::string var2(1,var);
      num_decl++;
      if(s_table.getSymbolTable().empty()){
        mem_loc = 0;
        
      }
      if(control_var == 1){
        subroute_vec.push_back(var2);
        num_decl--;
        sub_len++;
      }

      if(s_table.getSymbolTable().find(var2) != s_table.getSymbolTable().end()){
        if (sub_check < 1  && scalDecl > 1 && var2 != "B") {
          output_file << "error: attempting to add variable with name "<< var2 << " twice \n";
          output_file.close();
          exit(EXIT_FAILURE);
          }
      }
      int len = 1;
      
      s_table.addTableEntry(var2,mem_loc,len);
      
      mem_loc++;
    }

    else if(inst.substr(0,7) == "declarr"){
      //DeclArr darr;
      arrDecl++;
      char var = inst[8];
      std::string var2(1,var);
      int len = int(inst[10]) - 48;
      if(s_table.getSymbolTable().empty()){
        mem_loc = 0;
      }
      if(control_var == 1){
        subroute_vec.push_back(var2);
        num_decl-= len;
        sub_len += len;
      }
      if(s_table.getSymbolTable().find(var2) != s_table.getSymbolTable().end()){
        if (sub_check < 1 && arrDecl > 1) {
          output_file << "error: attempting to add variable with name "<< var2 << " twice\n";
          output_file.close();
          exit(EXIT_FAILURE);
          }
      }
      s_table.addTableEntry(var2,mem_loc,len);
      mem_loc += len;
      num_decl += len;
    }

    else if(inst.substr(0,5) == "label"){
      lblDecl++;
      std::string var = inst.substr(6);
      label_loc = buf_idx + 1;
      if(s_table.getSymbolTable().find(var) != s_table.getSymbolTable().end()){
        if (sub_check < 1 && lblDecl > 1) {
          output_file << "error: attempting to add label with name "<< var << " twice\n";
          output_file.close();
          exit(EXIT_FAILURE);
          }
      }
      s_table.addTableEntry(var,label_loc,0);
    }

    else if(inst.substr(0,10) == "gosublabel"){
      control_var += 1;
      buf_idx++;
      std::string var = inst.substr(11);
      label_loc = buf_idx;
      s_table.addTableEntry(var,label_loc,0);
      std::shared_ptr<Stmt> my_ptr(new GoSubLabel(var));
      i_buf.addToBuffer(my_ptr);
    }

    else if(inst.substr(0,4) == "exit"){
      std::shared_ptr<Stmt> my_ptr(new Exit());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

    else if(inst.substr(0,8) == "jumpzero"){
       std::string label_sub = inst.substr(9);
      std::shared_ptr<Stmt> my_ptr(new JumpZero(label_sub));
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
      
    }

    else if(inst.substr(0,9) == "jumpnzero"){
      std::string label_sub = inst.substr(10);
      std::shared_ptr<Stmt> my_ptr(new JumpNZero(label_sub));
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

    else if(inst.substr(0,4) == "jump"){
      std::string label_sub = inst.substr(5);
      std::shared_ptr<Stmt> my_ptr(new Jump(label_sub));
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

    else if(inst.substr(0,5) == "gosub"){
      std::string label_sub = inst.substr(6);
      std::shared_ptr<Stmt> my_ptr(new GoSub(label_sub));
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

    else if(inst.substr(0,6) == "return"){
      control_var -= 1;
      std::vector<std::shared_ptr<Stmt>> ibuf = i_buf.getBuffer();
      for (int k = 0; k < ibuf.size(); k++){
        if(ibuf[k]->op_code == "GoSubLabel "){
          ibuf[k]->setLabelNum(sub_len); 
        }
      }
      for(int i = 0; i < subroute_vec.size(); i++){
        s_table.exitScope(subroute_vec[i]);
      }
      std::shared_ptr<Stmt> my_ptr(new Return());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

    else if(inst.substr(0,8) == "pushscal"){
      std::map<std::string, std::vector<std::pair<int,int>>> s = s_table.getSymbolTable();
      std::string var = inst.substr(9);
      std::map<std::string, std::vector<std::pair<int,int>>>::iterator it;
      it = s.find(var);
      std::vector<std::pair<int,int>> vec = it->second;
      std::pair<int,int> inner_scope = vec.back();
      int loc = inner_scope.first;
      std::shared_ptr<Stmt> my_ptr(new PushScal(var,loc));
      

      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

    else if(inst.substr(0,7) == "pusharr"){
      std::map<std::string, std::vector<std::pair<int,int>>> s = s_table.getSymbolTable();
      char var = inst[8];
      std::string var2(1,var);
      std::map<std::string, std::vector<std::pair<int,int>>>::iterator it;
      it = s.find(var2);
      std::vector<std::pair<int,int>> vec = it->second;
      std::pair<int,int> inner_scope = vec.back();
      int loc = inner_scope.first;
      std::shared_ptr<Stmt> my_ptr(new PushArr(var2,loc));
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

    else if(inst.substr(0,5) == "pushi"){
      std::string num_before = inst.substr(6);
      int op = std::stoi(num_before);
      std::shared_ptr<Stmt> my_ptr(new PushI(op));
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

     else if(inst.substr(0,7) == "popscal"){
      std::map<std::string, std::vector<std::pair<int,int>>> s = s_table.getSymbolTable();
      std::string var = inst.substr(8);
      std::map<std::string, std::vector<std::pair<int,int>>>::iterator it;
      it = s.find(var);
      std::vector<std::pair<int,int>> vec = it->second;
      std::pair<int,int> inner_scope = vec.back();
      int loc = inner_scope.first;
      std::shared_ptr<Stmt> my_ptr(new PopScal(var,loc));
      
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

     else if(inst.substr(0,6) == "poparr"){
      std::map<std::string, std::vector<std::pair<int,int>>> s = s_table.getSymbolTable();
      char var = inst[7];
      std::string var2(1,var);
      std::map<std::string, std::vector<std::pair<int,int>>>::iterator it;
      it = s.find(var2);
      std::vector<std::pair<int,int>> vec = it->second;
      std::pair<int,int> inner_scope = vec.back();
      int loc = inner_scope.first;
      std::shared_ptr<Stmt> my_ptr(new PopArr(var2,loc));
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
      
    }
     else if(inst.substr(0,3) == "pop"){
      std::shared_ptr<Stmt> my_ptr(new Pop());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
      
    }
     else if(inst.substr(0,3) == "dup"){
      std::shared_ptr<Stmt> my_ptr(new Dup());
      i_buf.addToBuffer(my_ptr); 
      buf_idx++;
    }

     else if(inst.substr(0,4) == "swap"){
      std::shared_ptr<Stmt> my_ptr(new Swap());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
      
    }

     else if(inst.substr(0,3) == "add"){
      std::shared_ptr<Stmt> my_ptr(new Add());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
      
    }

     else if(inst.substr(0,6) == "negate"){
      std::shared_ptr<Stmt> my_ptr(new Negate());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
      
    }

     else if(inst.substr(0,3) == "mul"){
      std::shared_ptr<Stmt> my_ptr(new Mul());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
      
    }

     else if(inst.substr(0,3) == "div"){
      std::shared_ptr<Stmt> my_ptr(new Div());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;

    }

     else if(inst.substr(0,8) == "printtos"){
      std::shared_ptr<Stmt> my_ptr(new PrintTos());
      i_buf.addToBuffer(my_ptr);
      buf_idx++;
    }

     else if(inst.substr(0,6) == "prints"){
      std::string print_this = inst.substr(7);
      std::shared_ptr<Stmt> my_ptr(new Prints(print_this, print_count));
      i_buf.addToBuffer(my_ptr);
      print_count++;
      buf_idx++;
    }
  }

  if(should_beend.substr(0,3) != "end"){
    output_file <<"error: code encountered after an end statement\n";
    output_file.close();
    exit(EXIT_FAILURE);
  }
  else{
    std::shared_ptr<Stmt> my_ptr(new End());
    i_buf.addToBuffer(my_ptr);
  }

 i_buf.getBufElement(0)->setNumDecl(num_decl);
 i_buf.printCurrentBuf(s_table, output_file);
 output_file.close();
}
