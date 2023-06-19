#ifndef GOSUB_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class GoSub : public Stmt{
public:
  GoSub(std::string _name);
  void printOps(std::ofstream& file);
  void setLabelName(std::string name);
  virtual void setLabelNum(int num); 
  std::string getLabelName(); 
private:
  std::string label_name;
  int label_numloc;
};
#endif 