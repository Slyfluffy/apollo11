//
//  velocity.h
//  apollo_11
//
//  Created by Journey Curtis on 1/13/22.
//

#ifndef velocity_h
#define velocity_h
#include <cmath>

class Velocity {
private:
   float dx;
   float dy;
   bool thrustOn;
public:
   //Constructors
   Velocity() { dx = 0; dy = 0; }
   Velocity(float dx, float dy) { this->dx = dx; this->dy = dy; }
   Velocity(Velocity &rhs) { dx = rhs.getDx(); dy = rhs.getDy(); }
   
   //Getters
   float getDx() const { return dx; }
   float getDy() const { return dy; }
   bool getTOn() const { return thrustOn; }
   
   //Setters
   void setDx(float dx)         { this->dx = dx; }
   void setDy(float dy)         { this->dy = dy; }
   void setTOn(bool thrustOn) { this->thrustOn = thrustOn; }
   
   float getSpeed() const { return sqrt((dx * dx) + (dy * dy)); }
   void addAcceleration(float weight, float angle);
};

#endif /* velocity_h */
