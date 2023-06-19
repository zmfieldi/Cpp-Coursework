#include "Stmt.h"
#include "RunTime.h"

class Op_dup : public Stmt{
public:
  Op_dup();
  void operation(RunTime *rt);
};