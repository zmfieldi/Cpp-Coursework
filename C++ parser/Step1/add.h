#ifndef ADD_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class Add : public Stmt{
public:
  Add();
  void printOps(std::ofstream& file);
};
#endif 