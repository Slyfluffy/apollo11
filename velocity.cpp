//
//  velocity.cpp
//  Lab03
//
//  Created by Journey Curtis on 1/27/22.
//

#include "velocity.h"

void Velocity::addAcceleration(float weight, float angle) {
   float thrust = 0;
   if (thrustOn)
      thrust = 45000;
   
   float a = thrust / weight;
   float vA = (a * cos(angle)) - 1.625;
   float hA = a * sin(angle);
   
   dx = dx + vA;
   dy = dy + hA;
}
