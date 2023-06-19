#include "Stmt.h"
#include "RunTime.h"

class Op_pop : public Stmt{
public:
  Op_pop( );
  void operation(RunTime *rt);
};