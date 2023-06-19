#include "Stmt.h"

class Op_enter_sub : public Stmt{
public:
  Op_enter_sub(int opnd);
  void operation(DataMemory* dm);
  int getOper();
private:
  int oper;
};