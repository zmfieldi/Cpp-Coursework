#include "Stmt.h"
#include "RunTime.h"

class Op_negate : public Stmt{
public:
  Op_negate();
  void operation(RunTime *rt);
};