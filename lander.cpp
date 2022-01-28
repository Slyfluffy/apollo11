//
//  lander.cpp
//  apollo_11
//
//  Created by Journey Curtis on 1/4/22.
//

#include "lander.h"

#include <iostream>

/*********************************************
 * APOLLO 11 :: LANDER :: DEFAULT CONSTRUCTOR
 * Constructs Lander class with default values
 ********************************************/
Lander :: Lander(const Point & ptUpperRight) {
   this->ptUpperRight = ptUpperRight;
   reset();
}

void Lander :: reset() {
   p.setX(200);
   p.setY(350);
   
   v.setDx(0);
   v.setDy(0);
   
   angle = 0;
   fuel = 3000;
   alive = true;
   landed = false;
   flying = true;
}

void Lander :: draw(Thrust t, ogstream gout) {
   gout.drawLander(p, angle);
   gout.drawLanderFlames(p, angle, t.isMain(), t.isCounter(), t.isClock());
}

void Lander :: input(Thrust thrust) {
   if (fuel == 0)
      return;
   
   if (thrust.isMain()) {
      float power = vThrust / weight * .1;
      v.addDy(cos(angle) * power);
      v.addDx(-sin(angle) * power);
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
   
   if (fuel < 0)
      fuel = 0;
}
