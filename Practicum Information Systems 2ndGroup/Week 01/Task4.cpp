#include<iostream>
constexpr int MAX_SIZE = 20;

enum Colors : unsigned char {

	Red = 0b100,
	Green = 0b010,
	Blue = 0b001
};
struct Color{

	unsigned char color : 3;
};

void printColor(const Color& myColor) {

	switch (myColor.color) {
	
	  case Red:
		  std::cout << "RED" << std::endl; break;
	  case Blue:
		  std::cout << "BLUE" << std::endl; break;
	  case Green:
		  std::cout << "GREEN" << std::endl; break;
	  default:
		  std::cout << "NOT BASIC COLOR" << std::endl;
	}
}

Color turnOpposite(const Color& myColor) {
	
	Color newColor;
	newColor.color = ~myColor.color;

	return newColor;
}

Color combineColors(const Color& color1, const Color& color2) {

	Color newColor;
	newColor.color = color1.color | color2.color;

	return newColor;
}

Color removeColor(const Color& color1, const Color& color2) {

	Color newColor;
	newColor.color = color1.color &(~ color2.color);

	return newColor;
}


int main() {

	Color col1;
	col1.color = Blue;
	
	Color col2;
	col2.color = Red;

	
    std::cout << (int)combineColors(col1, col2).color << std::endl;
	std::cout << (int)turnOpposite(col2).color<< std::endl;

	return 0;
}
