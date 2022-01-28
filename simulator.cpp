//
//  simulator.cpp
//  apollo11
//
//  Created by Journey Curtis on 1/27/22.
//

#include "simulator.h"
#include "uiDraw.h"

/********************************
 * SIMULATOR :: CONSTRUCTOR
 * INPUTS  :: Point ptUpperRight
 * OUTPUTS :: NONE
 * Constructs the Simulator class
 *******************************/
Simulator::Simulator(Point ptUpperRight) {
   this->ptUpperRight = ptUpperRight;
   lander = new Lander(ptUpperRight);
   ground = new Ground(ptUpperRight);
}

/**********************************
 * SIMULATOR :: INPUT
 * INPUTS  :: Interface ui
 * OUTPUTS :: NONE
 * Handles input for the simulation
 *********************************/
void Simulator::input(Interface ui) {
   if (ui.isSpace())
      reset();
   
   Thrust t;
   t.set(ui);
   runSimulation(t);
   display(t);
}

/****************************
 * SIMULATOR :: RUNSIMULATION
 * INPUTS  :: Thrust t
 * OUTPUTS :: NONE
 * Runs the simulation
 ***************************/
void Simulator::runSimulation(Thrust t) {
   if (!lander->isFlying())
      return;
   
   lander->input(t);
   lander->coast();
   
   if (ground->hitGround(lander->getP(), 20))
      lander->crash();
   else if (ground->onPlatform(lander->getP(), 20)) {
      if (lander->getV().getSpeed() > 4)
         lander->crash();
      else
         lander->land();
   }
}

/**********************************************
 * SIMULATOR :: DISPLAY
 * INPUTS  :: Thrust t
 * OUTPUTS :: NONE
 * Displays the various parts of the simulation
 *********************************************/
void Simulator::display(Thrust t) {
   ogstream gout;
   
   ground->draw(gout);

   // draw the lander and its flames
   gout.drawLander(lander->getP()/*position*/, lander->getAngle() /*angle*/);
   gout.drawLanderFlames(lander->getP(), lander->getAngle(), /*angle*/
       t.isMain(), t.isCounter(), t.isClock());

   // put some text on the screen
   gout.setPosition(Point(20.0, 380.0));
   
   // TODO: Line these up somehow ???
   gout << "Fuel:      " << lander->getFuel() << " lbs" << "\n"
        << "Altitude:  " << round(ground->getElevation(lander->getP())) << " meters\n"
        << "Speed:   " << 0 << " m/s\n";

   // draw our little stars
//   for (int i = 0; i < 50; i++) {
//       pDemo->phase[i]++;
//       gout.drawStar(pDemo->ptStar[i], pDemo->phase[i]);
//   }
}
