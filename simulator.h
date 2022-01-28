//
//  simulator.h
//  Lab03
//
//  Created by Journey Curtis on 1/27/22.
//

#ifndef simulator_h
#define simulator_h

#include "lander.h"
#include "ground.h"

class Simulator {
private:
   Lander * lander;
   Point ptUpperRight;
   Ground * ground;
   
public:
   Simulator(Point ptUpperRight);
   
   void reset() { lander->reset(); ground->reset(); }
   void input(Interface ui);
   void runSimulation(Thrust t);
   void display(Thrust t);
};

#endif /* simulator_h */
