#include "Op_negate.h"

Op_negate::Op_negate( ) {
    name_buffer = "negate";
}

void Op_negate::operation(RunTime *rt) {
    rt->addStack(rt->getLast());
    rt->pushOn(-(rt->getLast()));
}