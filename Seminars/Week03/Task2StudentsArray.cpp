#include<iostream>
#include<fstream>

#pragma warning( disable : 4996)

constexpr int NAME_SIZE = 31;

struct Student {
	char name[NAME_SIZE];
	int age;
	int fn;
};

Student init(const char* name, int age, int fn) {
	
	Student student{};
	
	strcpy(student.name, name);
	student.age = age;
	student.fn = fn;

	return student;
}

//write only 1 student
void writeStudentToFile(const Student& student,std::ofstream& ofs) {

	ofs.write((const char*)&student, sizeof(Student));
}

//write array of students
void writeStudentArrToFile(const Student* students, size_t sizeArr, std::ofstream& ofs) {
	ofs.write((const char*)students, sizeof(Student)*sizeArr);
}

void readStudent(std::ifstream& ifs, Student& student) {

	ifs.read((char*)&student, sizeof(student));
}

size_t getFileSize(std::ifstream& ifs) {

	unsigned currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	size_t fileSize = ifs.tellg();
	ifs.seekg(currPos);

	return fileSize;
}

void readStudentsArr(std::ifstream& ifs, Student*& students, size_t& sizeArr) {

    sizeArr = getFileSize(ifs) / sizeof(Student);
	students = new Student[sizeArr];

	ifs.read((char*)students, sizeArr * sizeof(Student));
}

void printStudent(const Student& student) {
	std::cout << student.name << " " << student.age << " " << student.fn << std::endl;
}

void printArr(const Student* students, size_t sizeArr) {


	for (size_t i = 0; i < sizeArr; i++){
		printStudent(students[i]);
	}
}
int main() {

	{
		std::ofstream ofs("StudentsArr.dat", std::ios::out | std::ios::binary);
		if (!ofs.is_open())
			return -3;

		Student students[2] = {};
		students[0] = init("Yoana", 20, 295);
		students[1] = init("Monika", 20, 101);

		writeStudentArrToFile(students, 2, ofs);
	}

	{
		std::ifstream ifs("StudentsArr.dat", std::ios::binary | std::ios::in);
		if (!ifs.is_open())
			return -6;

		Student* students = nullptr;
		size_t sizeArr = 0;
		readStudentsArr(ifs, students, sizeArr);
		printArr(students, sizeArr);

	}



	return 0;
}