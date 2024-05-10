#include "Triangle.h"
#include<climits>
#include<iostream>

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):Shape(3)
{
	setPointAtInd(0, x1, y1);
	setPointAtInd(1, x2, y2);
	setPointAtInd(2, x3, y3);
}

double Triangle::getArea() const
{
	Shape::Point p0 = getPointAtInd(0);
	Shape::Point p1 = getPointAtInd(1);
	Shape::Point p2 = getPointAtInd(2);

	//a formula which is not ness to be learned
	return abs(p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p0.y * p1.x - p1.y * p2.x - p2.y * p0.x) / 2.00;
}

double Triangle::getPer() const
{
	Shape::Point p0 = getPointAtInd(0);
	Shape::Point p1 = getPointAtInd(1);
	Shape::Point p2 = getPointAtInd(2);

	return p0.getDist(p1) + p1.getDist(p2) + p2.getDist(p0);
}

bool Triangle::isPointIn(int x, int y) const
{
	//dont know this alg
	Shape::Point p(x, y);
	Triangle t1(getPointAtInd(0).x, getPointAtInd(0).y, getPointAtInd(1).x, getPointAtInd(1).y, p.x, p.y);
	Triangle t2(getPointAtInd(2).x, getPointAtInd(2).y, getPointAtInd(1).x, getPointAtInd(1).y, p.x, p.y);
	Triangle t3(getPointAtInd(2).x, getPointAtInd(2).y, getPointAtInd(0).x, getPointAtInd(0).y, p.x, p.y);

	return abs(t1.getArea() + t2.getArea() + t3.getArea() - getArea()) <= std::numeric_limits<double>::epsilon();
}
