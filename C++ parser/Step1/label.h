#ifndef LABEL_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class Label : public Stmt{
public:
  Label();
  void printOps(std::ofstream& file);
};
#endif 