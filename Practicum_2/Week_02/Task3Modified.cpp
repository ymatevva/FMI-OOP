#include<iostream>
#include<fstream>
/* 
11900
1234
1000
Male
Kia
1987
January
10000
1567
1200
Female
Toyota
1900
May*/

constexpr int MONTH_SIZE = 10;
constexpr int GENDER_SIZE = 10;
constexpr int CAR_BRAND_SIZE = 15;
constexpr double COEF = 0.1;
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
Month readMonth() {

	char month[MONTH_SIZE + 1];
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

struct Date{

	Month month = Month::Undefined;
	unsigned year = 0;
};

Date readDate() {

	Date date{};
	std::cin >> date.year;
	std::cin.ignore();
	date.month = readMonth();
	return date;
}

enum class Gender {
	Undefined,
	Male,
	Female
};

enum class CarBrand {
	Undefined,
	KIA,
	Toyota,
	Tesla
};

struct Person {
	long int ID = 0;
	int postCode = 0;
	Gender gender = Gender::Undefined;
};

struct Car {
	
	double price = 0;
	Person carOwner{};
	CarBrand carBrand = CarBrand::Undefined; 
	Date firstRegistration{ Month::Undefined ,0};
};


Gender readGender() {

	char gender[GENDER_SIZE + 1];
	std::cin.getline(gender, GENDER_SIZE + 1);

	if((strcmp(gender,"Undefined") == 0))
		return Gender::Undefined;

	else if((strcmp(gender, "Male") == 0))
		return Gender::Male;

	else if ((strcmp(gender, "Female") == 0))
		return Gender::Female;
}

CarBrand readCarBrand() {

	char carBrand[CAR_BRAND_SIZE + 1];
	std::cin.getline(carBrand, CAR_BRAND_SIZE + 1);

	if ((strcmp(carBrand, "Undefined") == 0))
		return CarBrand::Undefined;
	else if (strcmp(carBrand, "Kia") == 0)
		return CarBrand::KIA;
	else if (strcmp(carBrand, "Toyota") == 0)
		return CarBrand::Toyota;
	else if (strcmp(carBrand, "Tesla") == 0)
		return CarBrand::Tesla;
}
Person initPerson() {

	Person person{};

	std::cin >> person.ID;
	std::cin >> person.postCode;

	std::cin.ignore();

	person.gender = readGender();

	return person;
}

Car initCar() {

	Car car{};

	std::cin >> car.price;
	car.carOwner = initPerson();
	car.carBrand = readCarBrand();
	car.firstRegistration = readDate();

	return car;
}
bool isCarMoreValuable(const Car& car1, const Car& car2) {

	double firstPrice = COEF * car1.firstRegistration.year * car1.price;
	double secondPrice = COEF * car2.firstRegistration.year * car2.price;

	return firstPrice > secondPrice;
}

int main()
{

	Car car1 = initCar();
	Car car2 = initCar();
	std::cout << "Is first more valuable? " << std::boolalpha << isCarMoreValuable(car1, car2) << std::endl;


	return 0;
}