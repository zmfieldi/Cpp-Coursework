#ifndef SWAP_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class Swap : public Stmt{
public:
  Swap();
  void printOps(std::ofstream& file);
};
#endif 