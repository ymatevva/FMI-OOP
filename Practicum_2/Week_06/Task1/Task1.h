#pragma once

namespace Constants {
	constexpr int ABBREVIATION_SIZE = 4;
	constexpr int NAME_SIZE = 19;
	constexpr int MONTHS = 12;
}


class Stock {

	char _abbreviation[Constants::ABBREVIATION_SIZE + 1] = " ";
	char _name[Constants::NAME_SIZE + 1] = " ";
	double _stockPrice[Constants::MONTHS]{ 0 };

	void copyFrom(const Stock& other);

public:

	Stock() = default;
	Stock(const char* abbreviation, const char* name, const double* stockPrice);
	Stock(const Stock& other);
	Stock& operator=(const Stock& other);

	void setAbbreviation(const char* abbreviation);
	void setName(const char* name);
	void setStockPrice(const double* stockPrice);

	const char* getAbbreviation() const;
	const char* getName() const;
	const double* getStockPrice() const;

	bool isProfitable() const;




};

