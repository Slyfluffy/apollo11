//
//  thrust.h
//  apollo11
//
//  Created by Journey Curtis on 1/27/22.
//

#ifndef thrust_h
#define thrust_h

#include "uiInteract.h"

/*****************************************
 * APOLLO11 :: THRUST
 * Thrust component of apollo11. Basically
 * telling us if it's turning and igniting
 * thrusters.
 ****************************************/
class Thrust {
private:
   bool mainEngine;
   bool clockwise;
   bool counterClockwise;
   
public:
   Thrust() { mainEngine = false; clockwise = false; counterClockwise = false; }
   
   bool isMain()    const { return mainEngine;       }
   bool isClock()   const { return clockwise;        }
   bool isCounter() const { return counterClockwise; }
   
   void set(Interface ui) {
      mainEngine = ui.isUp();
      clockwise = ui.isRight();
      counterClockwise = ui.isLeft();
   }
};

#endif /* thrust_h */
