#include "Stmt.h"

class Op_jumpzero: public Stmt{
public:
  Op_jumpzero(int opnd);
  int getOper();
private:
  int oper;
};