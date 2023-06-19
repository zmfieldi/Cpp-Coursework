#ifndef POPARR_H_
#include <iostream>
#include "stmt.h"

class PopArr : public Stmt{
public:
  PopArr(std::string _var,int _loc);
  void printOps(std::ofstream& file);
private:
  std::string var;
  int loc;
};
#endif 