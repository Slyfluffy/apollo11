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
Lander :: Lander() {
   this->weight = 15103;
   this->vPower = 45000;
   this->hPower = 450;
   
   p.setX(0);
   p.setY(100);
   
   v.setDx(0);
   v.setDy(0);
}

Lander :: Lander(float vVelocity, float hVelocity, float yPosition) {
	this->weight = 15103;
	this->vPower = 45000;
	this->hPower = 450;
   
   v.setDx(hVelocity);
   v.setDy(vVelocity);
   
   p.setX(0);
   p.setY(yPosition);
}
