#include<iostream>

struct Complex {

	double real;
	double imag;
};


void readComplex(Complex& complex) {

	std::cin >> complex.real;
	std::cin >> complex.imag;
}

Complex addTwoComplex(const Complex& complex1, const Complex& complex2) {

	Complex complex3;

	complex3.real = complex1.real + complex2.real;
	complex3.imag = complex1.imag + complex2.imag;

	return complex3;
}

void printComplex(const Complex& complex) {

	std::cout << complex.real << " + ";
	std::cout << complex.imag << "i" <<  std::endl;
}


int main(){

	Complex complex1;
	Complex complex2;

	readComplex(complex1);
	readComplex(complex2);

	Complex complex3 = addTwoComplex(complex1, complex2);
	printComplex(complex3);


	return 0;
}