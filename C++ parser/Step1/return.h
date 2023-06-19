#ifndef RETURN_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class Return : public Stmt{
public:
  Return();
  void printOps(std::ofstream& file);
};
#endif 