#include<iostream>
#include<cmath>

namespace Points{
	
	struct Point {

		int x = 0;
		int y = 0;
	};

	void readPoint(Point& point) {	

		std :: cin >> point.x;
		std :: cin >> point.y;
	}

	double getDistBetweenPoints(const Point& point1, const Point& point2) {
		
		int dx = point1.x - point2.x;
		int dy = point1.y - point2.y;

		return sqrt(dx * dx + dy * dy);
	}

	void printPoint(const Point& point) {
		
		std::cout << point.x << " " << point.y;
	}
}

namespace Figures {

	using namespace Points;

	struct Triangle {

		Point p1;
		Point p2;
		Point p3;
	};

	void readTriangle(Triangle& triangle) {

		readPoint(triangle.p1);
		readPoint(triangle.p2);
		readPoint(triangle.p3);
	}

	double getAreaOfTriangle(const Triangle& triangle) {

		double sideA = getDistBetweenPoints(triangle.p1, triangle.p2);
		double sideB = getDistBetweenPoints(triangle.p2, triangle.p3);
		double sideC = getDistBetweenPoints(triangle.p1, triangle.p3);

		double halfPer = (sideA + sideB + sideC) / 2;

		return sqrt(halfPer * (halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC));
	}

	void sortTrianglesByArea(Triangle* triangles, size_t N) {
		
		double* areas = new double[N];
		for (size_t i = 0; i < N; i++){
			areas[i] = getAreaOfTriangle(triangles[i]);
		}

		for (size_t i = 0; i < N - 1; i++)
		{
			int minAreaIndex = i;
			for (size_t j = i + 1; j < N; j++)
			{
				if (areas[i] < areas[minAreaIndex])
					minAreaIndex = j;
			}

			if (minAreaIndex != i)
			{
				std::swap(triangles[i], triangles[minAreaIndex]);
				std::swap(areas[i], areas[minAreaIndex]);
			}
		}
		delete[] areas;
	}

	void printTriangle(const Triangle& triangle){
	
		printPoint(triangle.p1);
		std::cout << std::endl;

		printPoint(triangle.p2);
		std::cout << std::endl;
		
		printPoint(triangle.p3);
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

int main()
{
    size_t N;
	std::cin >> N;

	Figures::Triangle* trianglesArr= new Figures :: Triangle[N];

	for (size_t i = 0; i < N; i++) {
		Figures::readTriangle(trianglesArr[i]);
	}

	Figures::sortTrianglesByArea(trianglesArr, N);

	for (size_t i = 0; i < N; i++) {
		Figures::printTriangle(trianglesArr[i]);
	}

	delete[] trianglesArr;
}
