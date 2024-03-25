#include"Interval.h"
#include<algorithm>
#include<iostream>
#include<cmath>


namespace HelperFunctions {

	bool isPrime(int n) {
		if (n <= 1)
			return false;

		double temp = sqrt(n);
		for (size_t i = 2; i <= temp; i++)
		{
			if (n % i == 0)
				return false;
		}
		return true;
    }

	int getReversed(int n) {

		int res = 0;

		while (n != 0) {
			(res *= 10) += n % 10;
			n /= 10;
		}
		return res;
	}

	bool isPal(int n) {
		return n == getReversed(n);
	}

	bool isWithDiffDigits(int n) {

		while (n > 10) {

			int currDigit = n % !0;
			int prevDigit = (n / 10) % 10;

			if (currDigit == prevDigit)
				return false;
		}
		return true;
	}

	bool isPowOfTwo(int n) {

		while (n % 2 == 0) {
			n /= 2;
		}
		return n == 1;
	}



}


Interval::Interval() : Interval(0, 0){}

Interval::Interval(int a, int b) {
	setA(a);
	setB(b);
}


void Interval :: setA(int a) {

	if (a > _b)
		a = _b;
	else
		_a = a;
}

void Interval::setB(int b) {
	if (b < _a)
		b = _a;
	else
		_b = b;
}

int Interval::getA() const {
	return _a;
}

int Interval::getB() const {
	return _b;
}

unsigned int Interval::IntervalLen() const{
	return _b - _a;
}

unsigned int Interval::getCountCondition(bool (*pred)(int))const {

	unsigned count = 0;
	for (size_t i = _a; i <= _b; i++){
		if (pred(i))
			count++;
	}
	return count;
}

unsigned int Interval::countPrimes()const {
	return getCountCondition(HelperFunctions::isPrime);
}

unsigned int Interval::countPalindromes() const {
	return getCountCondition(HelperFunctions::isPal);
}

unsigned int Interval::countNumbersWithDiffDigits() const {
	return getCountCondition(HelperFunctions::isWithDiffDigits);
}

bool Interval::arePowOfTwo()const {
	return HelperFunctions::isPowOfTwo(_a) && HelperFunctions::isPowOfTwo(_b);
}

bool Interval::isSubInterval(const Interval& otherInt) {
	return _a >= otherInt._a && _b <= otherInt._b;
}

bool Interval::isInInterval(int x) const {
	return x >= _a && x <= _b;
}

int main() {

	Interval interval{ 1,100 };
	Interval otherInterval{ 0,120 };

	std::cout << "Is the number in the interval? " << std::boolalpha << interval.Interval::isInInterval(89) << std::endl;
	std::cout << "Are the start and the end pows of two?" << std::boolalpha << interval.Interval::arePowOfTwo() << std::endl;
	std::cout << "Lenght of interval: " << interval.Interval::IntervalLen() << std::endl;
	std::cout << "Count of prime numbers in the interval: " << interval.Interval::countPrimes() << std::endl;
	std::cout << "Count of palindromes in the interval: " << interval.Interval::countPalindromes() << std::endl;
	std::cout << "Count of numbers with different digits in the interval: " << interval.Interval::countNumbersWithDiffDigits() << std::endl;
	std::cout << "Is sub interval? " << interval.Interval::isSubInterval(otherInterval) << std::endl;

	return 0;
}