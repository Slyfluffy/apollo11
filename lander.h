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
#include "uiDraw.h"
#include "thrust.h"

/****************************************************
 * APOLLO 11 :: LANDER
 * Lander class. contains everything required for the
 * lander to function
 ***************************************************/
class Lander
{
private:
   bool alive;
   bool landed;
   Point p;
   Velocity v;
   Point ptUpperRight;
   float angle;
   const float weight = 15103;
   const float vThrust = 45000;
   const float hThrust = 450;
   const float g = -.1625;
   int fuel;
   
   float convertToRadians(float degree) { return (2 * M_PI * (degree / 360)); }
   
public:
   //Constructors
   Lander(const Point & ptUpperRight);
   
   void reset();
   
   // Getters
   float getWeight() const { return weight; }
   float getAngle()  const { return angle;  }
   bool isAlive()    const { return alive;  }
   bool isLanded()   const { return landed; }
   int getFuel()     const { return fuel;   }
   Point getP()      const { return p;      }
   Velocity getV()   const { return v;      }
   
   // Setters
   void setAngle(float angle)   { this->angle = angle;   }
   void setFuel(int fuel)       { this->fuel = fuel;     }
   void setV(Velocity v)        { this->v = v;           }
   void setP(Point p)           { this->p = p;           }
   
   //special functions
   void draw(Thrust t);
   void input(Thrust thrust);
   void coast() { if (alive) { v.addDy(g); p.addY(v.getDy()); p.addX(v.getDx()); } }
   void land()  { landed = true; angle = 0; }
   void crash() { alive = false; }
};

#endif /* lander_h */
