#pragma once
#include<climits>


class Interval {
	int _a = INT_MIN;
	int _b = INT_MAX;

public:

	Interval();
	Interval (int a, int b);


	void setA(int a);
	void setB(int b);

	int getA() const;
	int getB() const;

	unsigned int IntervalLen() const;
	bool isInInterval(int x) const;

	unsigned int getCountCondition(bool (*pred)(int)) const;
	unsigned int countPrimes() const;
	unsigned int countPalindromes() const;
	unsigned int countNumbersWithDiffDigits()const;

	bool arePowOfTwo() const;
	bool isSubInterval(const Interval& otherInt);

};