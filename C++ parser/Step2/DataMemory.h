#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <vector>

class DataMemory{
public:
  void resizeStackUp(int n);
  void resizeStackDown( );
  int getSize();
  void pushBack(int n);
  void addToLoc(int e, int loc);
  int getLocVal(int num);

private:
  //std::vector<int> dm_stack;  
  std::vector<std::vector<int>> dm_stack;
};

#endif