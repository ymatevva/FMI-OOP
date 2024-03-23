#include<iostream>
#include<fstream>

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


struct Calendar {

	Month month = Month::Undefined;
	unsigned year = 0;
};


Calendar init(const Month& month, unsigned year) {

	Calendar calendar{};

	calendar.month = month;
	calendar.year = year;

	return calendar;
}


size_t getFileSize(std::ifstream& ifs) {

	unsigned currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	size_t fileSize = ifs.tellg();
	ifs.seekg(currPos);

	return fileSize;
}

void readArrFromFile(std::ifstream& ifs, Calendar*& calendar, size_t& arrSize) {

	arrSize = getFileSize(ifs)/sizeof(Calendar);	
	calendar = new Calendar[arrSize];
	ifs.read((char*)calendar, sizeof(Calendar)*arrSize);
}
void readFromFile(const char* fromFile,  Calendar*& calendar, size_t& arrSize) {
	if (!fromFile)
		return;

	std::ifstream ifs(fromFile, std::ios::binary);
	if (!ifs.is_open())
		return;

	readArrFromFile(ifs, calendar, arrSize);
}

void writeCalendarToFile(std::ofstream& ofs, const Calendar& calendar) {
	ofs.write((const char*)&calendar, sizeof(calendar));
}
void writeArrToFile(std::ofstream& ofs, const Calendar* calendar, size_t arrSize) {
	if (!calendar)
		return;

	ofs.write((const char*)&arrSize, sizeof(arrSize));
	for (size_t i = 0; i < arrSize; i++){
		writeCalendarToFile(ofs, calendar[i]);
	}
}
void writeToFile(const char* toFile, const Calendar* calendar, size_t arrSize) {

	if (!toFile || !calendar)
		return;

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;

	writeArrToFile(ofs, calendar, arrSize);
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
		std::cout << "March" << " " ; break;
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

void printCalendar(const Calendar& calendar) {
	printMonth(calendar.month);
	std::cout << calendar.year << std::endl;

}
void printArr(const Calendar* calendar, size_t arrSize) {

	if (!calendar)
		return;
	for (size_t i = 0; i < arrSize; i++){
		printCalendar(calendar[i]);
	}
}
void getPrevMonth(Calendar& calendar) {

	if (calendar.month == Month::January)
		calendar.month = Month::December;
	else
		calendar.month = (Month)((int)calendar.month - 1);

	if (calendar.year == 0)
		std::cout << "There is no previous year." << std::endl;
	else
		calendar.year = calendar.year - 1;
}

void getNextMonth(Calendar& calendar) {

	if (calendar.month == Month::December)
		calendar.month = Month::January;
	else
		calendar.month = (Month)((int)calendar.month + 1);


	calendar.year = calendar.year + 1;

int main() {

	Calendar calendar[3];

	calendar[0] = init(Month::May, 1974);
	calendar[1] = init(Month::January, 2004);
	calendar[2] = init(Month::August, 2003);

	writeToFile("CALENDAR.dat", calendar, 3);

	size_t sizeArr = 0;
	Calendar* newCalendar = new Calendar[sizeArr];
	readFromFile("CALENDAR.dat", newCalendar, sizeArr);
	printArr(newCalendar, sizeArr);

	
	getPrevMonth(newCalendar[1]);
	printArr(newCalendar, sizeArr);

	
	delete[] newCalendar;
	return 0;
}
