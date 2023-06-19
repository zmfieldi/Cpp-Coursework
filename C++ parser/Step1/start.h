#ifndef START_H_
#include <iostream>
#include "stmt.h"
#include <fstream>

class Start : public Stmt{
public:
  Start();
  void printOps(std::ofstream& file);
  virtual void setNumDecl(int _num);
private:
int num_decl = 0;
};
#endif 