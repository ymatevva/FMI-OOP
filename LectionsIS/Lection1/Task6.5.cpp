#include<iostream>


struct Point {

	double x = 0;
	double y = 0;
};

void initPoint(Point& point) {
	std::cin >> point.x >> point.y;
}

Point* initPointArr(size_t& numPoints) {

	std::cin >> numPoints;

	Point* pointsArr = new Point[numPoints];
	for (size_t i = 0; i < numPoints; i++){
		initPoint(pointsArr[i]);
	}

	return pointsArr;
}


void sortPoints(Point* points,size_t numPoints) {

	if (!points)
		return;

	for (size_t i = 0; i < numPoints - 1; i++){

		int minElInd = i;
		for (size_t j = i + 1; j < numPoints; j++)
		{
			if (points[j].x < points[minElInd].x) {
				minElInd = j;
			}
			else if (points[j].x == points[minElInd].x  && points[j].y < points[minElInd].y) {
				minElInd = j;
			}
		}

		if (minElInd != i)
			std::swap(points[i], points[minElInd]);
	}
}

void printPoint(const Point& point) {

	std::cout << "(" << point.x << "," << point.y << ")" << std::endl;
}

void printPointArr(const Point* points, size_t numPoints) {
	for (size_t i = 0; i < numPoints; i++){
		printPoint(points[i]);
	}
}

int main() {

	size_t numPoints = 0;

	Point* points = initPointArr(numPoints);

	sortPoints(points, numPoints);

	printPointArr(points, numPoints);

	delete[] points;
	return 0;
}