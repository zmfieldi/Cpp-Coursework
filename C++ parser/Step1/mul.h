#ifndef MUL_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class Mul : public Stmt{
public:
  Mul();
  void printOps(std::ofstream& file);
};
#endif 