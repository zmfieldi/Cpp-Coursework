#include <vector>
#include <memory>
#include "Stmt.h"


class InstructionMemory{
public:
  InstructionMemory(std::string fName);
  std::vector<std::shared_ptr<Stmt>> getInstructionMemory();
  std::vector<std::shared_ptr<Stmt>> getStringBuffer();
  void printIMem();
  
private:
  std::vector<std::shared_ptr<Stmt>> i_buffer;
  std::vector<std::shared_ptr<Stmt>> s_buff;
};