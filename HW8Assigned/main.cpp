#include <iostream>
#include "Int.h"
#include "Node.h"

int main(int argc, char** args) {
   const int values[ ] {5, 1, 7, 15};
   Node* rootInt = new Node(Int(10));
   for (int i = 0; i < 4; i++) {
      rootInt->insertNode(Int(values[i])); 
   }

   rootInt->print( );
   std::cout << std::endl;

/*
   Node<double>* rootDouble = new Node<double>(10.0);
   for (int i = 0; i < 4; i++) {
      rootDouble->insertNode((double) values[i]); 
   }
   rootInt->print( );
   std::cout << std::endl;
*/
}
