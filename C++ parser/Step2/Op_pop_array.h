#include "Stmt.h"

class Op_pop_array : public Stmt{
public:
  Op_pop_array(int opnd);
  void operation(RunTime* rt, DataMemory* dm);
private:
  int oper;
};