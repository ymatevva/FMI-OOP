#include<iostream>
#include<fstream>

constexpr int MONTH_SIZE = 9;
enum class Month {

	Undefined,
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
	December
};



struct Date{

	Month month = Month::Undefined;
	unsigned year = 0;
};

struct Product {
	long int ID = 0;
	double price = 0;
	Date supplyDate;
	Date sellDate{ Month::Undefined,0 };
	bool isSold = false;

	bool comparison(const Product& other) const {
		return ID == other.ID &&
			price == other.price &&
			supplyDate.month == other.supplyDate.month &&
			supplyDate.year == other.supplyDate.year &&
			sellDate.month == other.sellDate.month &&
			sellDate.year == other.sellDate.year &&
			isSold == other.isSold;
	}
};

Month readMonth() {

	char month [MONTH_SIZE + 1];
	std::cin.getline(month, MONTH_SIZE + 1);
	
	if (strcmp(month, "January") == 0) {
		return Month::January;
	}
	else if (strcmp(month, "February") == 0) {
		return Month::February;
	}
	else if (strcmp(month, "March") == 0) {
		return Month::March;
	}
	else if (strcmp(month, "April") == 0) {
		return Month::April;
	}
	else if (strcmp(month, "May") == 0) {
		return Month::May;
	}
	else if (strcmp(month, "June") == 0) {
		return Month::June;
	}
	else if (strcmp(month, "July") == 0) {
		return Month::July;
	}
	else if (strcmp(month, "August") == 0) {
		return Month::August;
	}
	else if (strcmp(month, "September") == 0) {
		return Month::September;
	}
	else if (strcmp(month, "October") == 0) {
		return Month::October;
	}
	else if (strcmp(month, "November") == 0) {
		return Month::November;
	}
	else if (strcmp(month, "December") == 0)
		return Month::December;
	else
		return Month::Undefined;

	
}

void printMonth(const Month& month) {

	switch (month) {

	case Month::Undefined:
		std::cout << "Undefined" << " "; break;
	case Month::January:
		std::cout << "January" << " "; break;
	case Month::February:
		std::cout << "February" << " "; break;
	case Month::March:
		std::cout << "March" << " "; break;
	case Month::April:
		std::cout << "April" << " "; break;
	case Month::May:
		std::cout << "May" << " "; break;
	case Month::June:
		std::cout << "June" << " "; break;
	case Month::July:
		std::cout << "July" << " "; break;
	case Month::August:
		std::cout << "August" << " "; break;
	case Month::September:
		std::cout << "september" << " "; break;
	case Month::October:
		std::cout << "October" << " "; break;
	case Month::November:
		std::cout << "November" << " "; break;
	case Month::December:
		std::cout << "December" << " "; break;
	}

}

void printDate(const Date& date) {

	std::cout << date.year << " ";
	printMonth(date.month);
}

Date initDate() {

	Date date{};
	std::cin >> date.year;
	std::cin.ignore();
	date.month = readMonth();
	return date;
}
void initSell(Product& product) {

	product.sellDate = initDate();
	product.isSold = true;
}

bool isValid(const Date& supplyDate, const Date& sellDate) {

	return  (sellDate.year < supplyDate.year ) ||
		( ( sellDate.year == supplyDate.year) && ( (int)supplyDate.month > (int)sellDate.month ) );
}

Product initProduct() {

	Product product{};

	std::cin >> product.ID;
	std::cin >> product.price;
	product.supplyDate = initDate();
	initSell(product);

	bool validDate = !isValid(product.supplyDate, product.sellDate);

	if (validDate)
		return product;
	else
		return { 0,0,{Month::Undefined,0},{Month::Undefined,0},0 };
}

size_t getFileSize(std::ifstream& ifs) {

	unsigned currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	size_t fileSize = ifs.tellg();
	ifs.seekg(currPos);

	return fileSize;
}

void readArrFromFile(std::ifstream& ifs, Product*& productsArr, size_t& sizeArr) {

	sizeArr = getFileSize(ifs) / sizeof(Product);
	productsArr = new Product[sizeArr];
	ifs.read((char*)productsArr, sizeArr * sizeof(Product));
}
void readFromFile(const char* fromFile, Product*& productsArr, size_t& sizeArr) {

	if (!fromFile)
		return;

	std::ifstream ifs(fromFile,std::ios::binary);
	if (!ifs.is_open())
		return;

	readArrFromFile(ifs, productsArr, sizeArr);
}

void writeProductArrToFile(std::ofstream& ofs, const Product* productArr, size_t sizeArr) {

	if (!productArr)
		return;
	ofs.write((const char*)productArr, sizeof(Product)*sizeArr);
}
void writeToFile(const char* toFile, const Product* productArr, size_t sizeArr) {

	if (!toFile || !productArr)
		return;

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;

	writeProductArrToFile(ofs, productArr, sizeArr);
}

void printProduct(const Product& product) {

	Product excessProd = { 0, 0, {Month::Undefined,0}, {Month::Undefined,0}, 0 };
	if (product.comparison(excessProd))
		std::cout << "The sell date is invalid. The product does not exist." << std::endl;

	std::cout << "Product ID: " << product.ID << " Product price: " << product.price << " Selldate: ";
	printDate(product.sellDate);
	std::cout << "Supply date: ";
	printDate(product.supplyDate);
	std::cout << "Is product sold: " <<  std::boolalpha << product.isSold << std::endl;

}
void printProductArr(const Product* productArr, size_t sizeArr) {
	if (!productArr)
		return;
	for (size_t i = 0; i < sizeArr; i++){
		printProduct(productArr[i]);
	}
}
int main() {

	Product productsArr[3];
	productsArr[0] = initProduct();
	productsArr[1] = initProduct();
	productsArr[2] = initProduct();

	writeToFile("ProucuctsMod.dat", productsArr, 3);

	size_t sizeArr = 0;
	Product* newArr = nullptr;
	readFromFile("ProucuctsMod.dat", newArr, sizeArr);
	printProductArr(newArr, sizeArr);


	delete[] newArr;
	return 0;
}