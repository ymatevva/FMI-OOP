#include "Shape.h"
#include<exception>
#include<iostream>

const Shape:: Point& Shape::getPointAtInd(size_t ind) const
{
	if (ind >= pointsCount) {
		throw std::out_of_range("The index is out of range.");
	}

	return pointsArr[ind];
}

void Shape::moveFrom(Shape&& other)
{
	pointsArr = other.pointsArr;
	other.pointsArr = nullptr;

	pointsCount = other.pointsCount;
	other.pointsCount = 0;
}

void Shape::copyFrom(const Shape& other)
{
	pointsArr = new Point[other.pointsCount];
	for (size_t i = 0; i < other.pointsCount; i++)
	{
		pointsArr[i] = other.pointsArr[i];
	}

	pointsCount = other.pointsCount;
}

void Shape::free()
{
	delete[] pointsArr;
}

Shape::Shape(size_t pointsCount)
{
	this->pointsCount = pointsCount;
	pointsArr = new Point[pointsCount];
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape::Shape(Shape&& other) noexcept
{
	moveFrom(std::move(other));
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Shape& Shape::operator=(Shape&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Shape::~Shape()
{
	free();
}

void Shape::setPointAtInd(size_t ind, double x, double y)
{
	if (ind >= pointsCount) {
		throw std::out_of_range("The index is out of range.");
	}

	pointsArr[ind] = Point(x, y);
}


