#include "Stmt.h"

class Op_gosub : public Stmt{
public: 
  Op_gosub(int opnd);
  int getOper();
};