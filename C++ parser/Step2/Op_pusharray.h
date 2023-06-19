#include "Stmt.h"
#include "RunTime.h"
#include "DataMemory.h"

class Op_pusharray : public Stmt{
public:
  Op_pusharray(int opnd);
  void operation(RunTime* rt, DataMemory* dm);
private:
  int oper;
};

