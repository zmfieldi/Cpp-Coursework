#include "RunTime.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int RunTime::getSecond( ) {
    return rt_stack[rt_stack.size() - 2]; 
}
int RunTime::getLast( ) {
    return rt_stack[rt_stack.size() - 1]; 
}

void RunTime::pushOn(int num) {
    rt_stack[rt_stack.size() -2] = num;
    rt_stack.pop_back();
}

void RunTime::addStack(int num) {
    rt_stack.push_back(num);
}

void RunTime::printStack(int num) { 
    rt_stack.pop_back();
    std::cout << num << std::endl;

}

void RunTime::eraseBack(){
  rt_stack.pop_back();
}

void RunTime::printEl(){
    for(int i = 0; i < rt_stack.size(); i++){
        std::cout << rt_stack[i];
    }
}

int RunTime::getSize(){
    return rt_stack.size();
}

int RunTime::getLocVal(int num) {
  return rt_stack[num];
}