#ifndef PARSE_H_
#include <iostream>
#include <fstream>
#include "stmt.h"
#include "Instruction.h"



class Parse {
public:
  Parse(std::string infilename);
private:
  Instruction i_buf;
  static std::ofstream output_file;
};
#endif 