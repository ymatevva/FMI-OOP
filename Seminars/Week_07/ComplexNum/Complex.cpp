#include"Complex.h"

Complex::Complex() {
	_im = 0;
	_real = 0;
}

Complex::Complex(double im, double real){
	setIm(im);
	setReal(real);
}

void Complex::setIm(double im){
	_im = im;
}

void Complex::setReal(double real){
	_real = real;
}

double Complex::getIm() const{
	return _im;
}

double Complex::getReal() const{
	return _real;
}

Complex Complex::getConjugated() const
{
	Complex res(*this);
	res._im *= -1;
	return res;
}

Complex& Complex::operator+=(const Complex& other)
{
	_im += other. _im;
	_real += other._real;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	_im -= other._im;
	_real -= other._real;
	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	double oldReal = _real;
	_real = _real * other._real - _im * other._im;
	_im = oldReal * other._im + _im * other._real;
}

Complex& Complex::operator/=(const Complex& other)
{
	Complex Conjugated = other.getConjugated(); 
	Complex otherCopy(other);

	*this *= Conjugated;
	otherCopy *= Conjugated; 

	if (otherCopy._real != 0)
	{
		_real /= otherCopy._real;
		_im /= otherCopy._real;
	}

	return *this;
}

std::ostream& operator<<(const Complex& complex, std::ostream& os)
{
	return os << complex._real<< " " << complex._im << "i";
}

std::istream& operator>>(Complex& complex, std::istream& is)
{
	return is >> complex._real >> complex._im;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex res (lhs);
	res += rhs;
	return res;
}


Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex res (lhs);
	res -= rhs;
	return res;
}


Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex res (lhs);
	res *= rhs;
	return res;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex res(lhs);
	res /= rhs;
	return res;
}


Complex operator*(const Complex& lhs, const Complex& rhs)
{
	
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
	return (lhs.getIm() == rhs.getIm() && lhs.getReal() == rhs.getReal());
}


bool operator!=(const Complex& lhs, const Complex& rhs)
{
	return !operator==(lhs, rhs);
}
