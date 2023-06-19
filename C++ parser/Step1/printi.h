#ifndef PRINTI_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class Printi : public Stmt{
public:
  Printi(std::string print_this);
  void printOps(std::ofstream& file);
private:
  std::string to_be_printed;
};
#endif 