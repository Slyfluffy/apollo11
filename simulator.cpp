//
//  simulator.cpp
//  Lab03
//
//  Created by Journey Curtis on 1/27/22.
//

#include "simulator.h"
#include "uidraw.h"

Simulator :: Simulator(Point ptUpperRight); {
   this->ptUpperRight = ptUpperRight;
   reset();
}

void Simulator :: reset() {
   lander = lander(ptUpperRight);
   ground = ground(ptUpperRight);
}

void Simulator :: input(Interface ui) {
   
}

void Simulator :: runSimulation(Thrust t) {
   if !(lander.isFlying())
      return;
   
   lander.input(t);
   
   lander.coast();
   
   if (ground.hitGround(lander.getPosition(), 20))
      lander.crash();
   else if (ground.onPlatform(lander.getPosition(), 20)) {
      if (lander.getVelocity().getSpeec() > 4)
         lander.crash();
      else
         lander.land();
   }
}

void Simulator :: display(Thrust &thrust) {
   
   ogstream gout;
   
   // draw the lander and its flames
   lander.draw(thrust, gout);
   ground.draw(gout);

   // put some text on the screen
//   gout.setPosition(Point(20.0, 380.0));
//
//   // TODO: Line these up somehow ???
//   gout << "Fuel:      " << 0 << " lbs" << "\n"
//        << "Altitude:  " << round(ground.getElevation(lander.P())) << " meters\n"
//        << "Speed:   " << 0 << " m/s\n";
}
