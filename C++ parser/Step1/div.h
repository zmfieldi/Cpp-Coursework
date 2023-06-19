#ifndef DIV_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class Div : public Stmt{
public:
  Div();
  void printOps(std::ofstream& file);
};
#endif 