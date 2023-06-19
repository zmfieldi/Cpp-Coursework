#include "Stmt.h"
#include "RunTime.h"

class Op_add : public Stmt{
public:
  Op_add();
  void operation(RunTime *rt);
};