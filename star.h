#pragma once
#include "point.h"
#include "uiDraw.h"


class Star
{
private:
	Point p;
	char phase;
public:
	Star();
	Star(Point p, char phase);
	void reset(int width, int height);
	void draw(ogstream gout);
};

