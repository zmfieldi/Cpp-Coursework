#ifndef PUSHSCAL_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class PushScal : public Stmt{
public:
  PushScal(std::string _var,int _loc);
  void printOps(std::ofstream& file);
private:
  std::string var;
  int loc;
};
#endif 