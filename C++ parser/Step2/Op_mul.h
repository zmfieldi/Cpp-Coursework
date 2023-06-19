#include "Stmt.h"
#include "RunTime.h"

class Op_mul : public Stmt{
public:
  Op_mul();
  void operation(RunTime *rt);
};