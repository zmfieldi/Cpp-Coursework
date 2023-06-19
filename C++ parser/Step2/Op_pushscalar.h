#include "Stmt.h"
#include "RunTime.h"
#include "DataMemory.h" 

class Op_pushscalar : public Stmt{
public:
  Op_pushscalar(int opnd);
  void operation(RunTime* rt, DataMemory* dm);
private:
  int oper;
};