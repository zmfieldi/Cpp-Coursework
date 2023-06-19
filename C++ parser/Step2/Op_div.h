#include "Stmt.h"
#include "RunTime.h"

class Op_div : public Stmt{
public:
  Op_div();
  void operation(RunTime *rt);
};