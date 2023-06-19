#ifndef DUP_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class Dup : public Stmt{
public:
  Dup();
  void printOps(std::ofstream& file);
};
#endif 