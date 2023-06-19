#ifndef PRINTS_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class Prints : public Stmt{
public:
  Prints(std::string print_this, int print_count);
  void printOps(std::ofstream& file);
private:
  std::string to_be_printed;
  int print_num;
};
#endif 