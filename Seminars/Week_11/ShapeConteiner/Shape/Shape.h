#pragma once
#include<cmath>

class Shape {

protected:
	struct Point {
		double x;
		double y;
		Point():x(0),y(0){}
		Point(int x, int y) : x(x), y(y){}
		double getDist(const Point& other) {
			int dx = other.x - x;
			int dy = other.y - y;

			return sqrt(dx * dx + dy * dy);
		}
	};
	const Shape::Point& getPointAtInd(size_t ind) const;

private:

	Point* pointsArr;
	size_t pointsCount;

	void moveFrom(Shape&& other);
	void copyFrom(const Shape& other);
	void free();

public:
	Shape(size_t pointsCount);
	Shape(const Shape& other);
	Shape(Shape&& other)noexcept;
	Shape& operator=(const Shape& other);
	Shape& operator=(Shape&& other)noexcept;
	virtual ~Shape();

	void setPointAtInd(size_t ind, double x, double y);

	virtual double getArea() const = 0;
	virtual double getPer() const = 0;
	virtual bool isPointIn(int x, int y) const = 0;


};