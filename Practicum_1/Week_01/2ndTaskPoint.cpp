#include<iostream>


struct Point {
	
	double x = 0;
	double y = 0;
};

void readPoint(Point& point) {

	std::cin >> point.x;
	std::cin >> point.y;
}

void printPoint(const Point& point) {

	std::cout << "( " << point.x << "," << point.y << ")" << std::endl;
}

double distFromTheCenter(const Point& point) {

	return sqrt((point.x * point.x) + (point.y * point.y));
}

double distBetweenTwoPoints(const Point& point1, const Point& point2) {

	int dx = point2.x - point1.x;
	int dy = point2.y - point1.y;

	return sqrt((dx*dx) + (dy*dy));
}

unsigned quad(const Point& point) {

	if (point.x > 0 && point.y > 0)
		return 1;
	else if (point.x < 0 && point.y > 0)
		return 2;
	else if (point.x < 0 && point.y < 0)
		return 3;
	else 
		return 4;
}

bool isOnContourOrInside(const Point& point, unsigned radius) {
	
	double distPoint = distFromTheCenter(point);
	return distPoint <= radius;
}

int main() {

	Point point;
	readPoint(point);

	unsigned radius;
	std::cin >> radius;
	
	printPoint;
	std::cout << quad(point) << std::endl;
	std::cout << isOnContourOrInside(point, radius) << std::endl;

	

	return 0;
}