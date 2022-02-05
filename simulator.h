//
//  simulator.h
//  apollo11
//
//  Created by Journey Curtis on 1/27/22.
//

//#ifndef simulator_h
#define simulator_h

#include "lander.h"
#include "ground.h"
#include "star.h"

/******************************************
 * APOLLO11 :: SIMULATOR
 * Simulator basically runs the program.
 * It handles input, movement, and display.
 *****************************************/
class Simulator {
private:
   Lander * lander;
   Point ptUpperRight;
   Ground * ground;
   Star * stars[80];
   
   void displayMessage(int selector);
   
public:
   Simulator(Point ptUpperRight);
   
   void reset();
   void input(Interface ui);
   void runSimulation(Thrust t);
   void display(Thrust t);
};

//#endif /* simulator_h */
