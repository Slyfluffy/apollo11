//
//  simulator.cpp
//  apollo11
//
//  Created by Journey Curtis on 1/27/22.
//

#include "simulator.h"
#include "uiDraw.h"

/*********************************
 * SIMULATOR :: CONSTRUCTOR
 * INPUTS    :: Point ptUpperRight
 * OUTPUTS   :: NONE
 * Constructs the Simulator class
 ********************************/
Simulator::Simulator(Point ptUpperRight) {
   this->ptUpperRight = ptUpperRight;
   lander = new Lander(ptUpperRight);
   ground = new Ground(ptUpperRight);
   Ground g = *ground;
   for (int i = 0; i < 80; i++)
      stars[i] = new Star(new Point(random(0, 400), random(0, 400)), random(0,255));
}

/***********************
 * SIMULATOR :: RESET
 * INPUTS    :: NONE
 * OUTPUTS   :: NONE
 * Resets the simulation
 **********************/
void Simulator::reset() {
    for (int i = 0; i < 80; i++)
        stars[i]->reset();

    ground->reset();
    lander->reset();
}

/**********************************
 * SIMULATOR :: INPUT
 * INPUTS    :: Interface ui
 * OUTPUTS   :: NONE
 * Handles input for the simulation
 *********************************/
void Simulator::input(Interface ui) {
   if (ui.isSpace())
      reset();

   Thrust t;
   display(t);

   // Check to see if crashed then check if lander can land.
   //  Check if we hit the ground
   if (ground->hitGround(lander->getP(), 20)) {
       displayEndMessage(true);
   }
   else if (ground->onPlatform(lander->getP(), 20)) {
       // If we are going too fast when we hit the platform,
       // we still crash
       if (lander->getV().getSpeed() >= 4) {
           displayEndMessage(true);
       }
       else {
           displayEndMessage(false);
           lander->setAngle(0);
       }
   }
   else {
       t.set(ui);
       runSimulation(t);
       display(t);
   }

   
   
}

/****************************
 * SIMULATOR :: RUNSIMULATION
 * INPUTS    :: Thrust t
 * OUTPUTS   :: NONE
 * Runs the simulation
 ***************************/
void Simulator::runSimulation(Thrust t) {
       // Take input
       lander->input(t);
       // Update velocity and position
       lander->coast();
   
}

/**********************************************
 * SIMULATOR :: DISPLAY
 * INPUTS    :: Thrust t
 * OUTPUTS   :: NONE
 * Displays the various parts of the simulation
 *********************************************/
void Simulator::display(Thrust t) {
   ogstream gout;
   
   // draw our little stars
   for (int i = 0; i < 80; i++)
       stars[i]->draw();

   ground->draw(gout);

   // draw the lander and its flames
   lander->draw(t);

   // put some text on the screen
   // Fuel
   gout.setPosition(Point(20.0, 380.0));
   gout << "Fuel:";
   gout.setPosition(Point(70.0, 380.0));
   gout << lander->getFuel() << " lbs" << "\n";

   // Altitude
   gout.setPosition(Point(20.0, 362.0));
   gout << "Altitude:";
   gout.setPosition(Point(70.0, 362.0));
   gout << round(ground->getElevation(lander->getP())) << " meters\n";

   // Speed
   gout.setPosition(Point(20.0, 344.0));
   gout << "Speed:";
   gout.setPosition(Point(70.0, 344.0));
   gout << lander->getV().getSpeed() << " m/s\n";

}

/**********************************************
 * SIMULATOR :: DISPLAYENDMESSAGE
 * INPUTS    :: bool crashed
 * OUTPUTS   :: NONE
 * Displays the end simulation message
 *********************************************/
void Simulator::displayEndMessage(bool crashed) {
    //End simulation message
    ogstream gout;
    gout.setPosition(Point(150, 200));
    if (crashed == false)
        gout << "Successful Landing.\n";
    else
        gout << "You have crashed!\n";
}
