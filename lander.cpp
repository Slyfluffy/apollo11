//
//  lander.cpp
//  apollo_11
//
//  Created by Journey Curtis on 1/4/22.
//

#include "lander.h"
#include <iostream>

/*********************************************
 * LANDER :: CONSTRUCTOR
 * INPUTS :: ptUpperRight
 * Constructs Lander class with default values
 ********************************************/
Lander :: Lander(const Point & ptUpperRight) {
   this->ptUpperRight = ptUpperRight;
   reset();
}

/************************************
 * LANDER :: RESET
 * INPUTS  :: NONE
 * OUTPUTS :: NONE
 * reset the lander to default values
 ***********************************/
void Lander :: reset() {
   p.setX(200);
   p.setY(350);
   
   v.setDx(0);
   v.setDy(0);
   
   angle = 0;
   fuel = 3000;
   alive = true;
   landed = false;
}


/************************************
 * LANDER  :: DRAW
 * INPUTS  :: Thrust t, ogstream gout
 * OUTPUTS :: NONE
 * draw the lander and it's flames
 * when needed.
 ***********************************/
void Lander :: draw(Thrust t) {
   ogstream gout;
   gout.drawLander(p, angle);
   
   if (isLanded())
      return;
   else if (fuel > 0 && isAlive())
      gout.drawLanderFlames(p, angle, t.isMain(), t.isCounter(), t.isClock());
}

/************************************
 * LANDER  :: INPUT
 * INPUTS  :: Thrust thrust
 * OUTPUTS :: NONE
 * Handle input for lander. It will
 * adjust angles and fuel accordingly
 ***********************************/
void Lander :: input(Thrust thrust) {
   if (!isAlive())
      return;
   
   if (fuel > 0) {
       if (thrust.isMain()) {
           float power = vThrust / weight * .1;
           v.addDy(cos(angle) * power);
           v.addDx(-sin(angle) * power);
           /*p.addX(v.getDx());
           p.addY(v.getDy());*/
           fuel -= 10;
       }

       if (thrust.isClock()) {
           angle = angle -= .1;
           fuel -= 1;
       }
       if (thrust.isCounter()) {
           angle += .1;
           fuel -= 1;
       }
   }
   
   if (fuel < 0)
      fuel = 0;
}
