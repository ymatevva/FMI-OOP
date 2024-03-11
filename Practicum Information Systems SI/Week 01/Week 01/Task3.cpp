#include<iostream>

constexpr int COURSE_SIZE = 7;

enum class Course {

	First,
	Second,
	Third,
	Fourth,
	Undefined
};


struct Student {

	Course course;
	unsigned FN = 0;
	double averageGrade = 0;
};

Course readCourse(Student& student) {

	char myCourse[COURSE_SIZE];
	std :: cin.getline(myCourse,COURSE_SIZE);

	if (strcmp(myCourse, "First")  == 0)
		return Course::First;

	else if (strcmp(myCourse, "Second") == 0)
		return Course::Second;

	else if (strcmp(myCourse, "Shird") == 0)
		return Course::Third;

	else if (strcmp(myCourse, "Fourth") == 0)
		return Course::Fourth;

	else
		return Course::Undefined;

}

void readStudent(Student& student) {

	student.course = readCourse(student);
	std::cin >> student.FN;
	std::cin >> student.averageGrade;
}

void printCourse(const Student& student) {

	if (student.course == Course::First)
		std::cout << "First" << std::endl;

	else if (student.course == Course::Second)
		std::cout << "Second" << std::endl;

	else if (student.course == Course::Third)
		std::cout << "Third" << std::endl;

	else if (student.course == Course::Fourth)
		std::cout << "Fourth" << std::endl;

	else
		std::cout << "Undefined" << std::endl;
}

void printStudent(const Student& student) {

	printCourse(student);
	std::cout << student.FN << std::endl;
	std::cout << student.averageGrade << std::endl;
}

int main() {

	Student student;
	readStudent(student);
	printStudent(student);


	return 0;
}