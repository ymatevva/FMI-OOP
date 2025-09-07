#pragma once
#include"Shape.h"
#include"Triangle.h"
#include"Rectangle.h"
#include"Circle.h"


class ShapeConteiner{

	Shape** shapeArr;
	size_t shapesCount;
	size_t cap;

	void free();
	void resize();
	void copyFrom(const ShapeConteiner& other);
	void moveFrom(ShapeConteiner&& other);

public:
	ShapeConteiner();
	ShapeConteiner(const ShapeConteiner& other);
	ShapeConteiner(ShapeConteiner&& other)noexcept;
	ShapeConteiner& operator=(const ShapeConteiner& other);
	ShapeConteiner& operator=(ShapeConteiner&& other)noexcept;
	~ShapeConteiner();

	void addTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
	void arrRecatngle(double x1, double y1, double x3, double y3);
	void addCircle(double radius, double x, double y);
	void addShape(Shape* shape);

	size_t getShapesCount()const;

	double getAreaByInd(size_t ind) const;
	double getPerByInd(size_t ind) const;
	bool isPointIn(size_t ind, double x, double y)const;
};