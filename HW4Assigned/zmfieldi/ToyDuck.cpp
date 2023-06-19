#include <iostream>
#include "ToyDuck.h"
#include "Quack.h"
#include "FlyNoWay.h"
#include "LaysToyEggs.h"


ToyDuck::ToyDuck( ) {
    quackBehavior = new Quack( );
    flyBehavior = new FlyNoWay( );
    layEggs = new LaysToyEggs( );
}

void ToyDuck::display ( ) {
    std::cout << "I'm a toy duck." << std::endl;
}