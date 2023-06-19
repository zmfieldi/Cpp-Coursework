#ifndef PUSHARR_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class PushArr : public Stmt{
public:
  PushArr(std::string _var,int _loc);
  void printOps(std::ofstream& file);
private:
  std::string var;
  int loc;
};
#endif 