#include "Stmt.h"

class Op_jumpnzero : public Stmt{
public:
  Op_jumpnzero(int opnd);
  int getOper();
private:
  int opnd;

};