#ifndef PUSHI_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class PushI : public Stmt{
public:
  PushI(int op);
  void printOps(std::ofstream& file);
private:
  int operand;
};
#endif 