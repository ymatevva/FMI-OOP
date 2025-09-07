#include<iostream>

struct Point {

	int x = 0;
	int y = 0;
};

void readPoint(Point& point){

	std::cin >> point.x;
	std::cin >> point.y;
}

double getDist(const Point& point1, const Point& point2) {

	int dx = point1.x - point2.x;
	int dy = point1.y - point2.y;

	return sqrt(dx * dx + dy * dy);
}

struct Line {

	Point p1;
	Point p2;
};

void readLine(Line& line) {
	
	readPoint(line.p1);
	readPoint(line.p2);
}

double getSlope(const Line& myLine) {

	double dx = myLine.p1.x - myLine.p2.x;
	double dy = myLine.p1.y - myLine.p2.y;

	return dy / dx;
}

bool areParallel(const Line& line1, const Line& line2) {

	return abs(getSlope(line1) - getSlope(line2)) <= 0.0001;
}

int main()
{
	Line line1;
	Line line2;

	readLine(line1);
	readLine(line2);

	std::cout << areParallel(line1, line2) << std::endl;

	return 0;
}
