#include "Circle.h"

constexpr double PI = 3.14;

Circle::Circle(double radius, int x, int y):Shape(1)
{
	this->radius = radius;
	setPointAtInd(0, x, y);
}

double Circle::getArea() const
{
	return PI * radius * radius;
}

double Circle::getPer() const
{
	return PI * radius * 2;
}

bool Circle::isPointIn(int x, int y) const
{
	Shape::Point p = getPointAtInd(0);
	Shape::Point other = Point(x, y);
	return p.getDist(other) <= radius;
}
