#include<iostream>

struct Point {

	int x = 0;
	int y = 0;


	void readPoint(Point& p) {
		std::cin >> p.x >> p.y;
	}

	void printPoint(const Point& p) {

		std::cout << "( " << p.x << "," << p.y << ")" << std::endl;
	}
};
int main() {

	Point point;
	point.readPoint(point);
	point.printPoint(point);


	return 0;
}
