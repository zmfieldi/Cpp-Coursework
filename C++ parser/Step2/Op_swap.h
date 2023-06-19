#include "Stmt.h"
#include "RunTime.h"

class Op_swap : public Stmt{
public:
  Op_swap();
  void operation(RunTime *rt);
};