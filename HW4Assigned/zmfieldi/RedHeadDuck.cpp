#include <iostream>
#include "RedHeadDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include "LaysEggsBroodly.h"

RedHeadDuck::RedHeadDuck( ) {
   quackBehavior = new Quack( );
   flyBehavior = new FlyWithWings( );
   layEggs = new LaysEggsBroodly( );
}

void RedHeadDuck::display( ) {
   std::cout << "I’m a real redheaded duck" << std::endl;
}
