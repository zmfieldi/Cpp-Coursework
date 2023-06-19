#include <iostream>
#include <string>
#include <map>
#include <list>
#include "SymbolTable.h"

SymbolTable::SymbolTable(){

}

void SymbolTable::addTableEntry(std::string st, int address, int length){

 std::pair<int,int> pair{address,length};

 std::map<std::string, std::vector<std::pair<int,int>>>::iterator it;
 it = symbol_table.find(st);
 
 if(it == symbol_table.end()){
  std::vector<std::pair<int,int>> vec;
  vec.push_back(pair);
  symbol_table.insert(std::pair<std::string, std::vector<std::pair<int,int>>>(st,vec));
 }
 else{
  (it->second).push_back(pair);
 }
} 

void SymbolTable::exitScope(std::string st){
 std::map<std::string, std::vector<std::pair<int,int>>>::iterator it;
 it = symbol_table.find(st);
 if(it == symbol_table.find(st)){
   (it->second).pop_back();
 }
}

std::map<std::string, std::vector<std::pair<int,int>>> SymbolTable::getSymbolTable(){
  return symbol_table;
}

void SymbolTable::printKeyVals(){
  if(symbol_table.empty()){
    std::cout << "empty map" << std::endl;
  }
  for(auto it = symbol_table.cbegin(); it != symbol_table.cend(); ++it){
     std::vector<std::pair<int,int>> vec = it->second;
     std::cout << it->first << std::endl;
     for(int j = 0; j < vec.size(); j++){
      std::cout << "<" << vec[j].first << "," << vec[j].second << ">" << std::endl;
     }
  }
}



