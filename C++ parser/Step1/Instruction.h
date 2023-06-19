#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_
#include <iostream>
#include <vector>
#include "stmt.h"
#include <memory>
#include "SymbolTable.h"

class Instruction{
public:
  Instruction();
  std::vector<std::shared_ptr<Stmt>> getBuffer();
  void printCurrentBuf(SymbolTable s_table, std::ofstream& file);
  void addToBuffer(std::shared_ptr<Stmt> stmt);
  std::shared_ptr<Stmt> getBufElement(int element);
private:
  std::vector<std::shared_ptr<Stmt>> i_buffer;
};
#endif 