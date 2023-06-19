#include <iostream>
#include "end.h"

End::End(){
  op_code = "";
}

void End::printOps(std::ofstream& file){
  file << op_code << "\n";
}