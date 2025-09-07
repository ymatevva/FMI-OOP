#include<iostream>
#include<fstream>

constexpr int MAX_STUDENTS = 20;
constexpr int MAJOR_SIZE = 10;
constexpr int FN_SIZE = 11;

enum class Major {
	Undefined,
	SE,
	CS,
	IS,
	Inf,
};

enum class Degree {
	Undefined,
	Bachelor,
	Master,
	PhD
};

Degree getDegree() {

	char input[MAJOR_SIZE];
	std::cin.getline(input, MAJOR_SIZE);

	if (strcmp(input, "Bachelor") == 0)
		return Degree::Bachelor;

	else if (strcmp(input, "Master") == 0)
		return Degree::Master;

	else if (strcmp(input, "PhD") == 0)
		return Degree::PhD;
	else
		return Degree::Undefined;
}

void printDegree(const Degree& degree) {

	switch (degree)
	{
	case Degree::Bachelor:
		std::cout << "Bachelor"; break;

	case Degree::Master:
		std::cout << "Master"; break;

	case Degree::PhD:
		std::cout << "PhD"; break;

	case Degree::Undefined:
		std::cout << "Undefined"; break;
	}
}

Major getMajor() {

	char input[MAJOR_SIZE];
	std::cin.getline(input, MAJOR_SIZE);

	if (strcmp(input, "SE") == 0)
		return Major::SE;

	else if (strcmp(input, "CS") == 0)
		return Major::CS;

	else if (strcmp(input, "IS") == 0)
		return Major::IS;

	else if (strcmp(input, "Inf") == 0)
		return Major::Inf;

	else
		return Major::Undefined;
}

void printMajor(const Major& major) {

	switch (major)
	{
	   case Major::SE:
		   std::cout << "SE"; break;

	   case Major::CS:
		   std::cout << "CS"; break;

	   case Major::IS:
		   std::cout << "IS"; break;

	   case Major::Inf:
		   std::cout << "Inf"; break;

	   case Major::Undefined:
		   std::cout << "Undefined"; break;

	}
}

struct Student {
	char FN[11];
	bool isFullTime = true;
	char* name = nullptr;
	Major major;
	Degree degree;
};

struct University {	
	size_t numStudents = 0;
	char* name = nullptr;
	Student students[MAX_STUDENTS];
};

void addStudentToUni(const Student& student, University& university) {

	if (university.numStudents + 1 > MAX_STUDENTS)
		return;

	university.students[university.numStudents++] = student;
}

void printStudent(const Student& student) {

	std::cout << student.FN << " " << (student.isFullTime ? "Full-time" : "Part-time") << " " << student.name << " ";
	printMajor(student.major);
	std::cout << " ";
	printDegree(student.degree);
}

void printAllStudents(const University& university) {

	for (size_t i = 0; i < university.numStudents; i++){
		printStudent(university.students[i]);
		std::cout << std::endl;

	}
}

void saveStudent(std::ofstream& ofs, const Student& student) {

	ofs.write(student.FN, FN_SIZE);

	ofs.write((const char*)&student.isFullTime, sizeof(student.isFullTime));

	size_t nameLen = strlen(student.name);
	ofs.write((const char*)&nameLen, sizeof(nameLen));
	ofs.write(student.name, nameLen + 1);

	ofs.write((const char*)&student.major, sizeof(student.major));
	ofs.write((const char*)&student.degree, sizeof(student.degree));

}	

void saveUniversity(std::ofstream& ofs, const University& university) {

	ofs.write((const char*)&university.numStudents, sizeof(university.numStudents));

	size_t nameLen = strlen(university.name);
	ofs.write((const char*)&nameLen, sizeof(nameLen));
	ofs.write(university.name, nameLen + 1);

	for (size_t i = 0; i < university.numStudents; i++){
		saveStudent(ofs, university.students[i]);
	}
}

void saveToFile(const char* toFile, const University& university) {

	if (!toFile)
		return;

	std :: ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;

	saveUniversity(ofs, university);

}


void readStudent(std::ifstream& ifs, Student& student){

	ifs.read(student.FN, FN_SIZE);
	ifs.read((char*)&student.isFullTime, sizeof(student.isFullTime));

	size_t nameLen = 0;
	ifs.read((char*)&nameLen, sizeof(nameLen));
	student.name = new char[nameLen + 1];
	ifs.read(student.name, nameLen + 1);

	ifs.read((char*)&student.major, sizeof(student.major));
	ifs.read((char*)&student.degree, sizeof(student.degree));

}

void readUni(std::ifstream& ifs, University& university) {

	ifs.read((char*)&university.numStudents, sizeof(university.numStudents));

	size_t nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));

	university.name = new char[nameLen + 1];
	ifs.read(university.name, nameLen + 1);

	for (size_t i = 0; i < university.numStudents; i++){
		readStudent(ifs, university.students[i]);
	}
}

void readFromFile(const char* fromFile, University& university) {

	if (!fromFile)
		return;

	std::ifstream ifs(fromFile,std::ios::binary);
	if (!ifs.is_open())
		return;

	readUni(ifs, university);
}

void freeMemory(University& university)
{
	delete[] university.name;
	for (size_t i = 0; i < university.numStudents; i++)
	{
		delete[] university.students[i].name;
	}
}

int main() {

	// University uni{ 2, new char[10] {"SU"}, {{"1111111111", true, new char[10] {"Ivan"}, Major::IS, Degree::Bachelor}, {"2222222222", false, new char[10] {"Georgi"}, Major::CS, Degree::Master}} };
	// saveToFile("uni.dat", uni);

	University university;
	readFromFile("uni.dat", university);
	printAllStudents(university);

	freeMemory(university);
	return 0;
}