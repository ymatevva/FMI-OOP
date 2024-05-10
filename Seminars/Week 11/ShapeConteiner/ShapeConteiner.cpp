#include "ShapeConteiner.h"
#include<utility>
#include<exception>
#include<iostream>

void ShapeConteiner::free()
{
	for (size_t i = 0; i < shapesCount; i++)
	{
		delete[] shapeArr[i];
	}
	delete[] shapeArr;
}

void ShapeConteiner::resize()
{
	cap = cap * 2;
	Shape** tmp = new Shape * [cap];
	for (size_t i = 0; i < shapesCount; i++)
	{
		tmp[i] = shapeArr[i];
	}
	delete[] shapeArr;
	shapeArr = tmp;
}

void ShapeConteiner::copyFrom(const ShapeConteiner& other)
{
	shapesCount = other.shapesCount;
	cap = other.cap;
	shapeArr = new Shape * [cap] {nullptr};
	for (size_t i = 0; i < shapesCount; i++)
	{
		shapeArr[i] = other.shapeArr[i];
	}

}

void ShapeConteiner::moveFrom(ShapeConteiner&& other)
{
	shapesCount = other.shapesCount;
	other.shapesCount = 0;

	cap = other.cap;
	other.cap = 0;

	shapeArr = other.shapeArr;
	other.shapeArr = nullptr;
}

ShapeConteiner::ShapeConteiner()
{
	shapesCount = 0;
	cap = 8;
	shapeArr = new Shape * [cap] {nullptr};
}

ShapeConteiner::ShapeConteiner(const ShapeConteiner& other)
{
	copyFrom(other);
}

ShapeConteiner::ShapeConteiner(ShapeConteiner&& other) noexcept
{
	moveFrom(std::move(other));
}

ShapeConteiner& ShapeConteiner::operator=(const ShapeConteiner& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ShapeConteiner& ShapeConteiner::operator=(ShapeConteiner&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ShapeConteiner::~ShapeConteiner()
{
	free();
}

void ShapeConteiner::addTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	if (shapesCount >= cap) {
		resize();
	}

	 Triangle* newTr = new Triangle(x1, y1, x2, y2, x3, y3);
	 addShape(newTr);
}

void ShapeConteiner::arrRecatngle(double x1, double y1, double x3, double y3)
{
	if (shapesCount >= cap) {
		resize();
	}

	Rectangle* rect= new Rectangle(x1, y1, x3, y3);
	addShape(rect);
}

void ShapeConteiner::addCircle(double radius, double x, double y)
{
	if (shapesCount >= cap) {
		resize();
	}

	Circle* newCircle  = new Circle(radius,x, y);
	addShape(newCircle);
}

size_t ShapeConteiner::getShapesCount() const
{
	return shapesCount;
}

double ShapeConteiner::getAreaByInd(size_t ind) const
{
	if (ind >= shapesCount) {
		throw std::out_of_range("Index is out of range.");
	}

	return shapeArr[ind]->getArea();
}

double ShapeConteiner::getPerByInd(size_t ind) const
{
	if (ind >= shapesCount) {
		throw std::out_of_range("Index is out of range.");
	}

	return shapeArr[ind]->getPer();
}

bool ShapeConteiner::isPointIn(size_t ind, double x, double y) const
{
	if (ind >= shapesCount) {
		throw std::out_of_range("Index is out of range.");
	}

	return shapeArr[ind]->isPointIn(x,y);
}
void ShapeConteiner::addShape(Shape* shape)
{
	if (shapesCount == cap)
		resize();
	shapeArr[shapesCount++] = shape; //we dont make a copy here (it's a private function, called from creation funcions)
}
int main() {
	// Create a ShapeContainer object
	ShapeConteiner container;

	// Add shapes to the container
	container.addTriangle(0, 0, 3, 0, 0, 4); // Triangle with vertices (0, 0), (3, 0), (0, 4)
	container.arrRecatngle(0, 0, 3, 4);      // Rectangle with bottom-left corner at (0, 0) and top-right corner at (3, 4)
	container.addCircle(5, 0, 0);            // Circle with radius 5 and center at (0, 0)

	// Test the methods of the container
	for (size_t i = 0; i < container.getShapesCount(); i++) {
		std::cout << "Shape " << i + 1 << ":\n";
		std::cout << "Area: " << container.getAreaByInd(i) << std::endl;
		std::cout << "Perimeter: " << container.getPerByInd(i) << std::endl;
		std::cout << "Is point (2, 2) inside? " << (container.isPointIn(i, 2, 2) ? "Yes" : "No") << std::endl;
		std::cout << std::endl;
	}

	return 0;
}