#ifndef STMT_H
#define STMT_H

#include <iostream>
#include <string>
#include "DataMemory.h"
#include "RunTime.h"
#include <memory>

class Stmt{
public:
  std::string name_buffer;
  virtual void operation();
  virtual void operation(DataMemory* dm);
  virtual void operation(RunTime* rt);
  virtual void operation(RunTime* rt, DataMemory* dm);
  virtual void operation(DataMemory* dm, int n);
  virtual void operation(RunTime* rt, DataMemory* dm, int n);
  virtual void operation(std::vector<std::shared_ptr<Stmt>> sbuff);
  virtual int getOper();
  int oper;
};

#endif