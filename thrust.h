//
//  thrust.h
//  Lab03
//
//  Created by Journey Curtis on 1/27/22.
//

#ifndef thrust_h
#define thrust_h

#include "uiInteract.h"

class Thrust {
private:
   bool mainEngine;
   bool clockwise;
   bool counterClockwise;
   
public:
   Thrust() { mainEngine = false; clockwise = false; counterClockwise = false; }
   void rotation();
   void mainEngineThrust();
   
   bool isMain()  const   { return mainEngine;       }
   bool isClock() const   { return clockwise;        }
   bool isCounter() const { return counterClockwise; }
   
   void set(Interface ui) {
      mainEngine = ui.isUp();
      clockwise = ui.isRight();
      counterClockwise = ui.isLeft();
   }
};

#endif /* thrust_h */
