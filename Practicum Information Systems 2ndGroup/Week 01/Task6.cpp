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

	void readLine(Line& line) {
		p1.readPoint();
		p2.readPoint();
	}

	double lineLenght() const{

		int dx = p2.x - p1.x;
		int dy = p2.y - p1.y;

		return sqrt(dx * dx + dy * dy);
	}



	void printData() const{
		
		std::cout << "P1";
		p1.printPoint();
		std :: cout << ", P2";
		p2.printPoint();
		std::cout << std::endl;
	}
};

bool areEqualLenght(const Line& line1, const Line& line2) {
	return abs(line1.lineLenght() - line2.lineLenght()) <= 0.0001;
}

int main() {

	Line line1;
	Line line2;

	line1.readLine(line1);
	line2.readLine(line2);

	std::cout << std :: boolalpha << areEqualLenght(line1, line2) << std::endl;

	line1.printData();
	line2.printData();

	return 0;
}
