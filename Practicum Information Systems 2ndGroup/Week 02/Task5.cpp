#include<iostream>


union Number {

	int intNumber;
	double doubleNumber;
};


int main() {
	
	Number number;

	number.intNumber = 11;
	std::cout << "Int number: " << number.intNumber << std::endl;



	number.doubleNumber = 13;
	std::cout << "Double number: " << number.doubleNumber << std::endl;


	std::cout << "Int number: " << number.intNumber << std::endl;

    return 0;
}