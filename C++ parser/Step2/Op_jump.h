#include "Stmt.h"

class Op_jump : public Stmt{
public:
  Op_jump(int opnd);
  int getOper( );
private:
  int oper;

};