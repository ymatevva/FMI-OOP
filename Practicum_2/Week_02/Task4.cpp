#include<iostream>

struct ComplexNumber {
	int imag = 0;
	int real = 0;
};

void readComplexNum(ComplexNumber& complexNum) {
	std::cin >> complexNum.real >> complexNum.imag;
}

void printComplex(const ComplexNumber& complexNum) {
	std::cout << complexNum.real << " + " << complexNum.imag << "i" << std::endl;
}

double absForComplexNumbers(const ComplexNumber& complexNum) {
	return sqrt(complexNum.real * complexNum.real + complexNum.imag * complexNum.imag);
}

ComplexNumber addComplex(const ComplexNumber& first, const ComplexNumber& second) {
	
	ComplexNumber complexResult;

	complexResult.real = first.real +second.real;
	complexResult.imag = first.imag + second.imag;

	return complexResult;
}

ComplexNumber multiplyComplex(const ComplexNumber& first, const ComplexNumber& second) {

	ComplexNumber complexResult;

	complexResult.real = first.real * second.real;
	complexResult.imag = first.imag * second.imag;

	return complexResult;
}

int main() {

	ComplexNumber complexNum1;
	ComplexNumber complexNum2;

	readComplexNum(complexNum1);
	readComplexNum(complexNum2);

	printComplex(complexNum1);
	printComplex(complexNum2);

	ComplexNumber sumOfTwo = addComplex(complexNum1, complexNum2);
	ComplexNumber multOfTwo = multiplyComplex(complexNum1, complexNum2);

	printComplex(sumOfTwo);
	printComplex(multOfTwo);

	return 0;
}
