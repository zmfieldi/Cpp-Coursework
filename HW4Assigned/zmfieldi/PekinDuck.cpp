#include <iostream>
#include "PekinDuck.h"
#include "Quack.h"
#include "FlysPoorly.h"
#include "LaysEggsNotBroodly.h"

PekinDuck::PekinDuck( ) {
   quackBehavior = new Quack( );
   flyBehavior = new FlysPoorly( );
   layEggs = new LaysEggsNotBroodly();
}

void PekinDuck::display( ) {
   std::cout << "I’m a real pekin duck." << std::endl;
}

