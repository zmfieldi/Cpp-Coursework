#include "Stmt.h"
#include "DataMemory.h"

class Op_return : public Stmt{
public:
  Op_return();
  void operation(DataMemory* dm, int n);
};