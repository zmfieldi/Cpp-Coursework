#ifndef POPSCAL_H_
#include <iostream>
#include "stmt.h"

class PopScal : public Stmt{
public:
  PopScal(std::string _var,int _loc);
  void printOps(std::ofstream& file);
private:
  std::string var;
  int loc;
};
#endif 