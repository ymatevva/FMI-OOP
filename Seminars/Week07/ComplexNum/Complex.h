#pragma once
#include<iostream>

class Complex {

	double _im = 0;
	double _real = 0;

public:

	Complex();
	Complex(double im, double real);


	void setIm(double im) ;
	void setReal(double real) ;

	double getIm() const;
	double getReal() const;

	Complex getConjugated() const;

	Complex& operator+=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator/=(const Complex& other);

	friend std::ostream& operator<<(const Complex& complex, std::ostream& os);
	friend std::istream& operator>>( Complex& complex, std::istream& is);
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);