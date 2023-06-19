#include "DataMemory.h"

void DataMemory::resizeStackUp(int n){
  std::vector<int> new_frame;
  new_frame.resize(n);
  dm_stack.push_back(new_frame);
}

void DataMemory::resizeStackDown( ){
  dm_stack.pop_back();
}


int DataMemory::getSize(){
  return dm_stack.back().size();
}

void DataMemory::pushBack(int n){
  dm_stack.back().push_back(n);
  
}

void DataMemory::addToLoc(int e, int val){
  dm_stack.back()[e] = val;
}

int DataMemory::getLocVal(int num) {
  return dm_stack.back()[num];
}

