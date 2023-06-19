#include "Stmt.h"


class Op_prints : public Stmt{
public:
  Op_prints(int opnd);
  void operations(std::vector<std::shared_ptr<Stmt>> s_buff); 
  int getOper();
private: 
  int oper;
};