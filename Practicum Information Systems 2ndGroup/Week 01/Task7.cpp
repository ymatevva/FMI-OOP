#include<iostream>


struct Point {

	int x = 0;
	int y = 0;


	void readPoint() {
		std::cin >> x >> y;
	}

	void printPoint() const {
		std::cout << "( " << x << "," << y << " )";
	}
};

struct Line {

	Point p1;
	Point p2;

	void readLine() {
		p1.readPoint();
		p2.readPoint();
	}

	double lineLenght() const {

		int dx = p2.x - p1.x;
		int dy = p2.y - p1.y;

		return sqrt(dx * dx + dy * dy);
	}


	void printLine() const {

		std::cout << "P1";
		p1.printPoint();
		std::cout << ", P2";
		p2.printPoint();
		std::cout << std::endl;
	}
};

bool areEqualLenght(const Line& line1, const Line& line2) {
	return abs(line1.lineLenght() - line2.lineLenght()) <= 0.0001;
}


struct Triangle {

	Line l1;
	Line l2;
	Line l3;

	void readTriangle() {

		l1.readLine();
		l2.readLine();
		l3.readLine();
	}

	bool isValidTriangle()const {

		if (!( l1.lineLenght() + l2.lineLenght() > l3.lineLenght() )
			&& ( l2.lineLenght() + l3.lineLenght() > l1.lineLenght() )
			&& ( l1.lineLenght() + l3.lineLenght() > l2.lineLenght() ) )
			return false;

		if (((l1.p1.x != l2.p1.x || l1.p1.y != l2.p2.y) ||
			(l2.p2.x != l3.p2.x || l2.p2.y != l3.p2.y) ||
			(l3.p1.x != l1.p2.x || l3.p1.y != l1.p2.y)))
			return false;

		return true;
	}

	double getPerimeter()const {
		return l1.lineLenght() + l2.lineLenght() + l3.lineLenght();
	}

	double getArea()const {

		double halfPer = getPerimeter() / 2;

		return sqrt(halfPer * (halfPer - l1.lineLenght()) * (halfPer - l2.lineLenght()) * (halfPer - l3.lineLenght()));
	}

	void printData() const {

		std::cout << "Triangle: " << std::endl;

		std::cout << "Line1: " << "Start: ";
		l1.printLine();

		std::cout << "Line2: " << "Start: ";
		l2.printLine();

		std::cout << "Line3: " << "Start: ";
		l3.printLine();


		if (isValidTriangle()) {
			std::cout << "Perimeter: " << getPerimeter() << std::endl;
			std::cout << "Area: " << getArea() << std::endl;
		}
		else
			std::cout << "Inavlid triangle" << std::endl;
	}
};
int main() {

    Triangle triangle;

	triangle.readTriangle();
	
	triangle.printData();

	return 0;
}
