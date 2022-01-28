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
   float angle;
   bool alive;
   int fuel;
   
   //Has-a
   Point p;
   Velocity v;
   
public:
   //Constructors
   Lander();
   Lander(Velocity v, Point p, float angle);
   
   // Getters
   float getWeight() const { return weight; }
   float getAngle()  const { return angle;  }
   bool isAlive()    const { return alive;  }
   int getFuel()     const { return fuel;   }
   Point getP()      const { return p;      }
   Velocity getV()   const { return v;      }
   
   // Setters
   void setWeight(float weight) { this->weight = weight; }
   void setAngle(float angle)   { this->angle = angle;   }
   void setAlive(bool alive)    { this->alive = alive;   }
   void setFuel(int fuel)       { this->fuel = fuel;     }
   void setV(Velocity v)        { this->v = v;           }
   void setP(Point p)           { this->p = p;           }
   
   //special functions
   void draw();
   void turnLeft();
   void turnRight();
   void subtractFuel();
};

#endif /* lander_h */
