#include<iostream>


enum class Month : char{

	Undefined = 0,
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,

};

struct Calendar {

	int year = 0;
	Month currMonth;

	int compare(const Calendar& compareCal) {

		if (year != compareCal.year)
			return year - compareCal.year;

		return(int)currMonth - (int)compareCal.currMonth;
	}
};

struct Product {

	bool isSold = false;
	float price;
	Calendar supplyDate;
	Calendar sellDate{ 0,Month::January};
	unsigned long ID;
};

void sell(Product& product, Calendar sellDate) {

	if (sellDate.compare(product.supplyDate) < 0){
		std::cout << "Error" << std::endl;
		return;
	}

	product.sellDate = sellDate;
	product.isSold = true;
}
int main() {

	Product p1{ 1,20.56,{ 2003, Month::August} };
	Product p2{ 1,20.34,{ 2004, Month::September} };

	sell(p1, { 2003, Month :: August });
	std :: cout << p1.isSold << std ::endl;
	
	sell(p2, { 2003, Month::August });
	std::cout << p2.isSold << std::endl;

	return 0;

}