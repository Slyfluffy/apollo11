#pragma once
#include "point.h"
#include "uiDraw.h"
#include "ground.h"

/**************************************************
 * APOLLO 11 :: STAR
 * Star class. contains everything required for the
 * star to function
 *************************************************/
class Star
{
private:
	Point * p;
	char phase;
public:
	// Constructors
	Star();
	Star(Point* p, char phase);

	// Getter
	Point* getPoint() { return p; }

	void reset();
	void draw();
};

