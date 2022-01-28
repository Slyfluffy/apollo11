//
//  simulator.h
//  Lab03
//
//  Created by Journey Curtis on 1/27/22.
//

#ifndef simulator_h
#define simulator_h

#include "lander.h"
#include "thrust.h"
#include "point.h"
#include "ground.h"
#include "uiInteract.h"

class Simulator {
   Lander * lander;
   Point ptUpperRight;
   Ground * ground;
   
public:
   Simulator(Point & ptUpperRight) {
      this->ptUpperRight = ptUpperRight;
      lander = new Lander(ptUpperRight);
      ground = new Ground(ptUpperRight);
      reset();
   }
   
   void reset() {
      ground->reset();
      lander->reset();
   }
   void input(Interface ui);
   void runSimulation(Thrust t);
   void display(Thrust &thrust);
};

#endif /* simulator_h */
