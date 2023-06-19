#include "Stmt.h"
#include "DataMemory.h"

class Op_start_prog : public Stmt{
public:
    Op_start_prog(int opnd);
    void operation(DataMemory* dm);
private:
    int oper;
};