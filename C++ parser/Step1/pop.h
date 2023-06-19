#ifndef POP_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class Pop : public Stmt{
public:
  Pop();
  void printOps(std::ofstream& file);
};
#endif 