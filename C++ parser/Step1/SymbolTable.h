#include <iostream>
#include <string>
#include <map>
#include <vector>

class SymbolTable{
public:
  SymbolTable();
  void addTableEntry(std::string statement_string, int add, int len);
  std::map<std::string, std::vector<std::pair<int,int>>> getSymbolTable();
  void exitScope(std::string statement_string);
  void printKeyVals();

private:
  std::map<std::string, std::vector<std::pair<int,int>>> symbol_table;
};
