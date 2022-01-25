//
//  lander.h
//  apollo_11
//
//  Created by Journey Curtis on 1/4/22.
//

#ifndef lander_h
#define lander_h

#include <cmath>
#include "point.h"
#include "velocity.h"

/****************************************************
 * APOLLO 11 :: LANDER
 * Lander class. contains everything required for the
 * lander to function
 ***************************************************/
class Lander
{
private:
   //Part of the lander
   float weight;
   float vPower;
   float hPower;
   
   //Has-a
   Point p;
   Velocity v;
   
public:
   //Constructors
   Lander();
   Lander(float vVelocity, float hVelocity, float yPosition);
   
   // Getters
   float getWeight() const { return weight; }
   float getVPower() const { return vPower; }
   float getHPower() const { return hPower; }
   float getTPower() const { return sqrt((vPower * vPower) + (hPower * hPower)); }
   
   Point getPoint()       const { return p; }
   Velocity getVelocity() const { return v; }
   
   // Setters
   void setVelocity(float dx, float dy) { v.setDx(dx); v.setDy(dy); }
   void setPoint(float x, float y)      { p.setX(x); p.setY(y);     }
};

#endif /* lander_hpp */
