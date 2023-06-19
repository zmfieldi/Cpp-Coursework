#ifndef PRINTTOS_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class PrintTos : public Stmt{
public:
  PrintTos();
  void printOps(std::ofstream& file);
};
#endif 