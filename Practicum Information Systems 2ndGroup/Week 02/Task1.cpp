#include<iostream>

constexpr int MAX_SIZE = 20;

enum class Month {

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
	int year;
	Month currMonth;
};

int myStrCmp(const char* str1, const char* str2) {

	if (!str1 || !str2)
		return -9;

	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}


Month readMonth() {

	char month[MAX_SIZE];
	std::cin.getline(month, MAX_SIZE);

	if (myStrCmp(month, "January") == 0)
		return Month::January;

	else if (myStrCmp(month, "February") == 0)
		return Month::February;

	else if (myStrCmp(month, "March") == 0)
		return Month::March;

	else if (myStrCmp(month, "April") == 0)
		return Month::April;

	else if (myStrCmp(month, "May") == 0)
		return Month::May;

	else if (myStrCmp(month, "June") == 0)
		return Month::June;

	else if (myStrCmp(month, "July") == 0)
		return Month::July;

	else if (myStrCmp(month, "August") == 0)
		return Month::August;

	else if (myStrCmp(month, "September") == 0)
		return Month::September;

	else if (myStrCmp(month, "October") == 0)
		return Month::October;

	else if (myStrCmp(month, "November") == 0)
		return Month::November;

	else if (myStrCmp(month, "December") == 0)
		return Month::December;
	else
		return Month::Undefined;
}

void printMonth(const Calendar& calendar) {

	if (calendar.currMonth == Month::January)
		std::cout << "January" << std::endl;

	else if (calendar.currMonth == Month::February)
		std::cout << "February" << std::endl;

	else if (calendar.currMonth == Month::March)
		std::cout << "March" << std::endl;

	else if (calendar.currMonth == Month::April)
		std::cout << "April" << std::endl;

	else if (calendar.currMonth == Month::May)
		std::cout << "May" << std::endl;

	else if (calendar.currMonth == Month::June)
		std::cout << "June" << std::endl;

	else if (calendar.currMonth == Month::July)
		std::cout << "July" << std::endl;

	else if (calendar.currMonth == Month::August)
		std::cout << "August" << std::endl;

	else if (calendar.currMonth == Month::September)
		std::cout << "September" << std::endl;

	else if (calendar.currMonth == Month::October)
		std::cout << "October" << std::endl;

	else if (calendar.currMonth == Month::November)
		std::cout << "November" << std::endl;

	else if (calendar.currMonth == Month::December)
		std::cout << "December" << std::endl;

	else
		std::cout << "Undefined" << std::endl;

}

void readCalendar(Calendar& calendar) {

	calendar.currMonth = readMonth();
	std::cin >> calendar.year;
}

void printCalendar(const Calendar& calendar) {

	printMonth(calendar);
	std::cout << calendar.year << std::endl;
}

void printPrevMonth(Calendar& calendar) {

	Calendar newCalendar;

	if (calendar.currMonth == Month::January)
		newCalendar.currMonth = Month::December;
	else
		newCalendar.currMonth = (Month)((int)calendar.currMonth - 1);

	if (calendar.year == 0) {
		std::cout << "There isn't previous year\n";
	}

	else {
		newCalendar.year = calendar.year - 1;
	}

	printCalendar(newCalendar);
}

void printNextMonth(Calendar& calendar) {
	
	Calendar newCalendar;
	
	if (calendar.currMonth == Month::December)
		newCalendar.currMonth = Month::January;
	else
		newCalendar.currMonth = (Month)((int)calendar.currMonth + 1);

	
	newCalendar.year = calendar.year + 1;
	

	printCalendar(newCalendar);
}

int main() {

	Calendar myCalendar;
	readCalendar(myCalendar);

	printCalendar(myCalendar);

	printPrevMonth(myCalendar);

	printNextMonth(myCalendar);

	return 0;
}
