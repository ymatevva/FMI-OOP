#include <iostream>
using namespace std;

enum Colors : unsigned char
{
	Red = 0b100,
	Green = 0b010,
	Blue = 0b001
};
struct Color
{
	unsigned char color : 3;
};

void printColor(const Color& color)
{
	switch (color.color)
	{
	case Red:
		cout << "Red";
		break;
	case Green:
		cout << "Green";
		break;
	case Blue:
		cout << "Blue";
		break;
	}
}
Color getReverseColor(const Color& color)
{
	Color newColor{ ~color.color };
	return newColor;
}
Color combineColors(const Color& first, const Color& second)
{
	Color newColor{ first.color | second.color };
	return newColor;
}
Color removeColor(const Color& first, const Color& second)
{
	Color newColor{ first.color & getReverseColor(second).color };
	return newColor;
}
int main()
{
	Color color1{ Blue };
	Color color2{ Red };

	cout << (int)combineColors(color1, color2).color << endl;

	cout << (int)getReverseColor(color2).color << endl;

}
