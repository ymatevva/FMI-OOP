#include<iostream>
#include"Task1.h"

#pragma warning(disable:4996)
using namespace Constants;


void Stock::copyFrom(const Stock& other) {

	strcpy(_abbreviation, other._abbreviation);
	strcpy(_name, other._name);
	for (size_t i = 0; i < 12; i++){
		_stockPrice[i] = other._stockPrice[i];
	}
}

Stock::Stock(const char* abbreviation, const char* name, const double* stockPrice) {
	setAbbreviation(abbreviation);
	setName(name);
	setStockPrice(stockPrice);
}

 Stock::Stock(const Stock& other) {
	 copyFrom(other);
 }
 
Stock& Stock::operator=(const Stock& other){
	if (this != &other) {
		copyFrom(other);
    }
    return *this;
}

void Stock::setAbbreviation(const char* abbreviation) {
	if (!abbreviation || _abbreviation == abbreviation || strlen(abbreviation) > ABBREVIATION_SIZE){
		strcpy(_abbreviation, "Unknown");
		
	}
	strcpy(_abbreviation, abbreviation);
}
void Stock::setName(const char* name) {
	if (!name || _name == name || strlen(name) > NAME_SIZE) {
		strcpy(_name, "Unknown");

	}
	strcpy(_name, name);
}

void Stock::setStockPrice(const double* stockPrice) {
	if (!stockPrice)
		return;
	for (size_t i = 0; i < 12; i++){
		_stockPrice[i] = stockPrice[i];
	}
}

const char* Stock::getAbbreviation() const {
	return _abbreviation;
}

const char* Stock::getName() const {
	return _name;
}

const double* Stock::getStockPrice() const {
	return _stockPrice;
}

bool hasIncreasedMore(const double* stockPrice) {
	unsigned countIncreased = 0;
	unsigned countDecreased= 0;
	for (size_t i = 0; i < 11; i++){
		if (stockPrice[i] > stockPrice[i + 1])
			countIncreased++;
		else if (stockPrice[i] < stockPrice[i + 1])
			countDecreased++;
	}
	return countDecreased < countIncreased;
}
bool Stock::isProfitable() const {
	bool isFinalPriceHigher = ((_stockPrice[11] - _stockPrice[0])/_stockPrice[0])*100 >= 10;
	return isFinalPriceHigher && hasIncreasedMore(_stockPrice);
}

int main() {



	return 0;
}
