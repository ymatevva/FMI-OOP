#pragma once
#include"Shape.h"

class Circle : public Shape {
	double radius;
public:
	Circle(double radius, int x, int y);
	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;
};