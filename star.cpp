#include "star.h"

/*********************************************
 * STAR :: CONSTRUCTOR
 * Constructs star class with default values
 ********************************************/
Star::Star() {
	p = new Point();
	phase = 0;
}

/***************************************
 * STAR   :: CONSTRUCTOR
 * INPUTS :: p, phase
 * Constructs star class with nondefault 
 * values
 **************************************/
Star::Star(Point* p, char phase) {
	this->p = p;
	this->phase = phase;
}

void Star::reset() {
	p = new Point(random(0, 400), random(0, 400));
}

/*****************
 * STAR    :: DRAW
 * INPUTS  :: NONE
 * OUTPUTS :: NONE
 * Draws the star!
 ****************/
void Star::draw() {
	// increase the phase before we draw the star
	phase++;
	// draw it
	ogstream gout;
	gout.drawStar(*p, phase);
}