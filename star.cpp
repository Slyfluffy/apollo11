#include "star.h"


Star::Star() {
	p = * new Point();
	phase = 0;
}

Star::Star(Point p, char phase) {
	this->p = p;
	this->phase = phase;
}

void Star::reset(int width, int height) {
	
}

void Star::draw(ogstream gout) {
	// increase the phase before we draw the star
	phase++;
	// draw it
	gout.drawStar(p, phase);
}