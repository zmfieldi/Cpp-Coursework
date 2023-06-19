#include "Stmt.h"
#include "RunTime.h"

class Op_pushi : public Stmt{
public:
  Op_pushi(int opnd);
  void operation(RunTime *rt);
private:
  int oper;
};

