#include "Stmt.h"

class Op_pop_scalar : public Stmt{
public:
  Op_pop_scalar(int opnd);
  void operation(RunTime* rt, DataMemory* dm);
private:
  int oper;
};