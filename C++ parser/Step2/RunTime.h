#ifndef RUNTIME_H
#define RUNTIME_H

#include <vector>

class RunTime{
public:
  int getSecond( );
  int getLast( );
  void pushOn(int num);
  void addStack(int num);
  void printStack(int num);
  void eraseBack( );
  int getSize();
  int getLocVal(int num);

  void printEl();
private:
  std::vector<int> rt_stack;  
};

#endif