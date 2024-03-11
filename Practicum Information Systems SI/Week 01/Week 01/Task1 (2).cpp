#include<iostream>

struct Complex {
	
	int real = 0;
	int imag = 0;
};

void readCompleX(Complex& complexNum) {
	std::cin >> complexNum.real >> complexNum.imag;
}

Complex sumOfComplex(const Complex& complex1, const Complex& complex2) {
	
	Complex complexSumRes = {};

	complexSumRes.real = complex1.real + complex2.real;
	complexSumRes.imag = complex1.imag + complex2.imag;

	return complexSumRes;
}


Complex productOfComplex(const Complex& complex1, const Complex& complex2) {

	Complex complexProdRes = {};

	complexProdRes.real = complex1.real * complex2.real;
	complexProdRes.imag = complex1.imag * complex2.imag;

	return complexProdRes;
}

void printComplex(const Complex& complexNum) {
	std::cout << complexNum.real << " + " << complexNum.imag << "i" << std::endl;
}


int main() {

	Complex complex1 = {};
	Complex complex2 = {};

	readCompleX(complex1);
	readCompleX(complex2);

	Complex sumRes = sumOfComplex(complex1, complex2);
	Complex prodRes = productOfComplex(complex1, complex2);

	printComplex(sumRes);
	printComplex(prodRes);

	return 0;
}