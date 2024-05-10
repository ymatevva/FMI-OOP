#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3):Shape(4)
{
	setPointAtInd(0, x1, y1);
	setPointAtInd(1, x3, y1);
	setPointAtInd(2, x3, y3);
	setPointAtInd(3, x1, y3);
}

double Rectangle::getArea() const
{
	Shape::Point p0 = getPointAtInd(0);
	Shape::Point p1 = getPointAtInd(1);
	Shape::Point p2 = getPointAtInd(2);

	return p0.getDist(p1) * p1.getDist(p2);
}

double Rectangle::getPer() const
{
	Shape::Point p0 = getPointAtInd(0);
	Shape::Point p1 = getPointAtInd(1);
	Shape::Point p2 = getPointAtInd(2);

	return 2 * ( p0.getDist(p1) + p1.getDist(p2));
}

bool Rectangle::isPointIn(int x, int y) const
{
	Shape::Point p(x, y);
	
	return p.x >= getPointAtInd(0).x && p.y >= getPointAtInd(1).x &&
		p.y <= getPointAtInd(0).y && p.y >= getPointAtInd(2).y;
}
