#include<iostream>
#include<cassert>

struct Rational {
	int nom = 0;
	int denom = 0;
};

void readRational(Rational& r){
	std::cin >> r.nom >> r.denom;
}

void printRational(const Rational& r) {
	std::cout << r.nom << "/" << r.denom << std::endl;
}

unsigned getGCD(unsigned a, unsigned b) {
	
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

bool isValid(const Rational& r) {
	return r.denom != 0;
}

void rationalize(Rational& r) {

	assert(isValid(r));

	unsigned gcd = getGCD(r.nom,r.denom);
	r.denom /= gcd;
	r.nom /= gcd;

	if (r.nom < 0 && r.denom < 0 || r.nom > 0 && r.denom < 0){
		r.nom *= -1;
		r.denom *= -1;
	}
}

Rational& plusEq(Rational& left, const Rational& right){
	
	assert(isValid(left), isValid(right));

	left.nom *= right.denom;
	
	left.nom += right.nom * left.denom;
    left.denom *= right.denom;

	rationalize(left);
	return left;
}

Rational plusRationals(const Rational& left, const Rational& right) {

	assert(isValid(left), isValid(right));
	Rational leftCopy = left;
	plusEq(leftCopy, right);
	return leftCopy;
}

int main() {

	Rational r1;
	Rational r2;

	readRational(r1);
	readRational(r2);

	Rational r3 = plusRationals(r1, r2);

	printRational(r3);
	
	return 0;
}