#include<iostream>

namespace Constants {

	constexpr int COURSE_SIZE = 7;
	constexpr int GROUP_SIZE = 30;
}

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

	char myCourse[Constants :: COURSE_SIZE];
	std::cin.getline(myCourse,Constants :: COURSE_SIZE);

	if (strcmp(myCourse, "First") == 0)
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
	std::cin.ignore();
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


struct Group {

	size_t groupSize = 0;
	size_t avgGroupGrade = 0;
	Student students[Constants::GROUP_SIZE];
};


void readGroup(Group& group) {

	std::cin >> group.groupSize;
	std::cin.ignore();

	double avgGrade = 0;
	for (size_t i = 0; i < group.groupSize; i++) {

		readStudent(group.students[i]);
		avgGrade += group.students[i].averageGrade;
	}

	group.avgGroupGrade = avgGrade / group.groupSize;
}

unsigned int studentsToGetScholarship(const Group& group, double minForScholarship) {

	unsigned int count = 0;

	for (size_t i = 0; i < group.groupSize; i++) {
		if (group.students[i].averageGrade >= minForScholarship)
			count++;
	}

	return count;
}

int main() {

	Group groupOfStudents;
	readGroup(groupOfStudents);

	double minForScholarship = 0;
	std::cin >> minForScholarship;

	std::cout << studentsToGetScholarship(groupOfStudents, minForScholarship) << std::endl;


	return 0;
}