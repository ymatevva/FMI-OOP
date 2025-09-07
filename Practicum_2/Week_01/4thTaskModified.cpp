#include<iostream>


enum class Colors : unsigned char {

	Red = 0b100,
	Green = 0b010,
	Blue = 0b001
};

struct Color{
	unsigned char color : 3;
};

void printColorName(const Color& color) {

	switch (color.color) {

	case (unsigned char)Colors::Red:
		std::cout << "Red" << std::endl; break;

	case (unsigned char)Colors::Blue :
		std::cout << "Blue" << std::endl; break;

	case (unsigned char)Colors::Green:
		std::cout << "Green" << std::endl; break;

	default:
		std::cout << "Undefined" << std::endl;
	}
}
Color returnOppositeColor(const Color& myColor) {

	Color oppColor{};
	oppColor.color = ~(unsigned char)myColor.color;

	return oppColor;
}

Color combineColors(const Color& color1, const Color& color2) {

	Color combColor{};
	combColor.color =  ((unsigned char)color1.color | (unsigned char)color2.color);

	return combColor;
}


Color removeColor(const Color& myColor, const Color& colorToRemove) {

	Color removeColor{};
	removeColor.color = ((unsigned char)myColor.color & ~(unsigned char)colorToRemove.color);

	return removeColor;
}


int main() {


	Color myColor1{ (unsigned char)Colors :: Red };
	Color myColor2{ (unsigned char)Colors::Blue};

	Color oppColor = returnOppositeColor(myColor1);
	std::cout << (int)oppColor.color << std::endl;

	Color mix = combineColors(myColor1, myColor2);
	std::cout << (int)mix.color << std::endl;

	Color removedColor = removeColor(myColor1, myColor2);
	std::cout << (int)removedColor.color << std::endl;

	return 0;
}