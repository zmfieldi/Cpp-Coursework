#ifndef NEGATE_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class Negate : public Stmt{
public:
  Negate();
  void printOps(std::ofstream& file);
};
#endif 