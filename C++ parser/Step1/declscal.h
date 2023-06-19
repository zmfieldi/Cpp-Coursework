#ifndef DECLSCAL_H_
#define DECLSCAL_H_
#include <iostream>
#include "stmt.h"


class DeclScal : public Stmt{
public:
  DeclScal();
  int getAddLoc();
private:
  int add_loc;
};
#endif 