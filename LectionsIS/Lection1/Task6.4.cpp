#include<iostream>

struct Polar {
	double len = 0;
	double angle = 0;
};

void readPolar(Polar& polar) {
	std::cin >> polar.len >> polar.angle;
}

void printPolar(const Polar& polar) {
	std::cout << polar.len << "V @ " << polar.angle << " rad " << std::endl;
}

struct Rect {
	double x = 0;
	double y = 0;
};

void readRect(Rect& rect) {
	std::cin >> rect.x >> rect.y;
}

void printRect(const Rect& rect) {
	std::cout << "( " << rect.x << ", " << rect.y << ")" << std::endl;
}

Rect convertToRect(Polar& vector){
	return { vector.len* cos(vector.angle), vector.len * sin(vector.angle)};
}

Polar convertToPolar(Rect vector){
	double radius = sqrt(vector.x * vector.x + vector.y * vector.y);

	return { radius,  asin(vector.y / radius) };
}

int main() {

	Polar p1;
	readPolar(p1);
	printPolar(p1);

	Rect converted = convertToRect(p1);
	printRect(converted);

	Polar convConverted = convertToPolar(converted);
	printPolar(convConverted);

	return 0;
}