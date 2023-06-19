#include "Stmt.h"
#include "RunTime.h"

class Op_printtos : public Stmt{
public:
    Op_printtos( );
    void operation(RunTime *rt);
};