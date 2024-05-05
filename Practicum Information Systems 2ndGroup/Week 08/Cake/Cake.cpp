#include "Cake.h"
#include<exception>
#include<iostream>

Cake::Cake()
{
	_flourGrams = 0;
	_waterMl = 0;
	_sugarGrams = 0;
	_currPiecesCount = 0;
	_maxPiecesCount = 0;
}

Cake::Cake(float flourGrams, float waterMl, float sugarGrams, unsigned currPiecesCount, unsigned maxPiecesCount)
{
	setCurrPiecesCount(currPiecesCount);
	setMaxPiecesCount(maxPiecesCount);
	setFlourGrams(flourGrams);
	setSugarGrams(sugarGrams);
	setWaterMl(waterMl);
}

float Cake::getFlourGrams() const
{
	return _flourGrams;
}

float Cake::getWaterMl() const
{
	return _waterMl;
}

float Cake::getSugarGrams() const
{
	return _sugarGrams;
}

unsigned Cake::getCurrPiecesCount() const
{
	return _currPiecesCount;
}

unsigned Cake::getMaxPiecesCount() const
{
	return _maxPiecesCount;
}

void Cake::setFlourGrams(float flourGrams)
{
	if (flourGrams < 0) {
		throw std::invalid_argument("Quantity can't be a negative number.");
	}
	_flourGrams = flourGrams;
}

void Cake::setWaterMl(float waterMl)
{
	if(waterMl < 0){
		throw std::invalid_argument("Quantity can't be a negative number.");
	}
	_waterMl = waterMl;
}

void Cake::setSugarGrams(float sugarGrams)
{
	if (sugarGrams < 0) {
		throw std::invalid_argument("Quantity can't be a negative number.");
	}
	_sugarGrams = sugarGrams;
}

void Cake::setCurrPiecesCount(unsigned currPiecesCount)
{
	if (currPiecesCount < 0 || currPiecesCount > _maxPiecesCount) {
		throw std::invalid_argument("Invalid count of current pieces.");
	}
	_currPiecesCount = currPiecesCount;
}

void Cake::setMaxPiecesCount(unsigned maxPiecesCount)
{
	if (maxPiecesCount < 0 ) {
		throw std::invalid_argument("Invalid count of current pieces.");
	}
	_maxPiecesCount = maxPiecesCount;
}

Cake& Cake::operator-=(int numberOfSlices)
{
	if (_currPiecesCount - numberOfSlices < 0) {
		throw std::out_of_range("No more slices left");
	}

	_currPiecesCount -= numberOfSlices;
	return *this;
}


Cake& Cake::operator/=(int numberOfSlices)
{
	if (!_maxPiecesCount)
	{
		_maxPiecesCount == 2;
	}
	else if (numberOfSlices % _maxPiecesCount != 0)
	{
		throw std::out_of_range("No pieces left.");
	}
	else
	{
		_currPiecesCount = _currPiecesCount * (numberOfSlices / _maxPiecesCount);
		_maxPiecesCount = numberOfSlices;
	}
	return *this;
}

Cake& Cake::operator+=(int numberOfSlices)
{
	if (_maxPiecesCount == 0 || _currPiecesCount + numberOfSlices > _maxPiecesCount) {
		throw std::out_of_range("Limit reached.");
	}
	_currPiecesCount += numberOfSlices;
	return *this;
}

Cake operator+(const Cake& lhs, int numOfPieces)
{
	Cake res(lhs);
	res += numOfPieces;
	return res;
}

Cake operator-(const Cake& lhs, int numOfPieces)
{
	Cake res(lhs);
	res -= numOfPieces;
	return res;
}

Cake operator/(const Cake& lhs, int numOfPieces)
{
	Cake res(lhs);
	res /= numOfPieces;
	return res;
}

bool operator==(const Cake& lhs, const Cake& rhs)
{
	return lhs.getWaterMl() == rhs.getWaterMl() &&
		lhs.getCurrPiecesCount() == rhs.getCurrPiecesCount() &&
		lhs.getFlourGrams() == rhs.getFlourGrams() &&
		lhs.getMaxPiecesCount() == rhs.getMaxPiecesCount() &&
		lhs.getSugarGrams() == rhs.getSugarGrams();
}

bool operator!=(const Cake& lhs, const Cake& rhs)
{
	return !(rhs==lhs);
}
int main() {
	try {
		// Create Cake objects
		Cake cake1(500, 300, 200, 4, 8);
		Cake cake2(600, 400, 250, 6, 10);
		Cake cake3(600, 400, 250, 6, 10);

		// Test member functions
		cake1 -= 2; // Slice 2 pieces from cake1
		//cake2 += 3; // Add 3 pieces to cake2
		//cake1 /= 2; // Divide cake1 into 2 equal parts

		// Test comparison operators
		if (cake3 == cake2) {
			std::cout << "cake1 and cake2 are equal." << std::endl;
		}
		else {
			std::cout << "cake1 and cake2 are not equal." << std::endl;
		}

		if (cake1 != cake2) {
			std::cout << "cake1 and cake2 are not equal." << std::endl;
		}
		else {
			std::cout << "cake1 and cake2 are equal." << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
