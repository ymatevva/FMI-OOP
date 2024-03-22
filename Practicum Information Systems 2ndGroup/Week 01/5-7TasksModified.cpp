#include<iostream>
#include<fstream>


struct Point {
	int x = 0;
	int y = 0;
};

struct Line {
	Point p1;
	Point p2;


	double getSideLen()const {

		double dx = p2.x - p1.x;
		double dy = p2.x - p2.y;

		return sqrt(dx * dx + dy * dy);
	}

	bool areSameLen(const Line& otherLine) {

		return fabs(getSideLen() - otherLine.getSideLen()) <= 0.0001;
	}

	void print() {
		std::cout << "P1: (" << p1.x << "," << p1.y << ")" << ", P2: (" << p2.x << "," << p2.y << ") - " << getSideLen() << std::endl;
	}
};

struct Triangle {

	Line l1;
	Line l2;
	Line l3;

	bool isValidTriangle()const {

		return (l1.getSideLen() + l2.getSideLen() >= l3.getSideLen()
			&& l3.getSideLen() + l2.getSideLen() >= l1.getSideLen()
			&& l1.getSideLen() + l3.getSideLen() >= l2.getSideLen());
	}

	double getPerimeter()const {

		return l1.getSideLen() + l2.getSideLen() + l3.getSideLen();
	}

	double getArea() const {

		double halfPer = getPerimeter() / 2;
		return sqrt(halfPer * (l1.getSideLen() - halfPer) * (l2.getSideLen() - halfPer) * (l3.getSideLen() - halfPer));
	}

	void printData() {
		std::cout << "Perimeter: " << getPerimeter() << " Area: " << getArea() << std::endl;
	}
};

int main() {

	Triangle trianglesArr[3];
	trianglesArr[0] = { {1,2},{3,2},{4,5} };
	trianglesArr[1] = { {1,1},{-1,0},{9,5} };
	trianglesArr[2] = { {1,-8},{-8,2},{2,3} };

	for (size_t i = 0; i < 3; i++) {
		std::cout << std::boolalpha << trianglesArr[i].isValidTriangle() << std::endl;
		trianglesArr[i].printData();
	}

	return 0;
}