#include<iostream>
#include<fstream>
#include<cstring>

#pragma warning( disable : 4996)

struct DynamicStudent{
	char* name;
	int age;
	int fn;
};


void freeStudent(DynamicStudent& dynSt) {

	delete[] dynSt.name;
	dynSt.age = 0;
	dynSt.fn = 0;
}

void printStudent(const DynamicStudent& dynSt) {
	std::cout << dynSt.name << " " << dynSt.age << " " << dynSt.fn << std::endl;
}
void printStudentsArr(const DynamicStudent* dynArr, size_t sizeArr) {

	if (!dynArr)
		return;

	for (size_t i = 0; i < sizeArr; i++) {
		printStudent(dynArr[i]);
	}
}

DynamicStudent readStudentFromFile(std::ifstream& ifs) {

	DynamicStudent dynSt;

	int nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));

	dynSt.name = new char[nameLen + 1];

	ifs.read(dynSt.name, nameLen + 1);

	ifs.read((char*)&dynSt.age, sizeof(dynSt.age));
	ifs.read((char*)&dynSt.fn, sizeof(dynSt.fn));

	return dynSt;
}

void readStudentsArrFromFile(std::ifstream& ifs, DynamicStudent*& dynStArr, size_t& sizeArr) {

	ifs.read((char*)&sizeArr, sizeof(sizeArr));

	dynStArr = new DynamicStudent[sizeArr];
	for (size_t i = 0; i < sizeArr; i++) {
		dynStArr[i] = readStudentFromFile(ifs);
	}
}

DynamicStudent initializeStudent(const char* name, int age, int fn) {


	DynamicStudent dynStudent;

	dynStudent.name = new char[strlen(name) + 1];
	strcpy(dynStudent.name, name);

	dynStudent.age = age;
	dynStudent.fn = fn;

	return dynStudent;
}

void writeStudentToFile(std::ofstream& ofs, const DynamicStudent& dynSt) {

	int nameLen = strlen(dynSt.name);
	ofs.write((const char*)&nameLen, sizeof(int));

	ofs.write(dynSt.name, nameLen + 1);
	ofs.write((const char*)&dynSt.age, sizeof(dynSt.age));
	ofs.write((const char*)&dynSt.fn, sizeof(dynSt.fn));
}

void writeArrStudentsToFile(std::ofstream& ofs, const DynamicStudent* stArr, size_t sizeArr) {

	ofs.write((const char*)&sizeArr, sizeof(sizeArr));
	for (size_t i = 0; i < sizeArr; i++) {
		writeStudentToFile(ofs, stArr[i]);
	}
}

int main() {

	{
		std::ofstream ofs("StudentsFile.dat", std::ios::binary | std::ios::out);
		if (!ofs.is_open())
			return -1;

		DynamicStudent dynStudentsArr[3];
		dynStudentsArr[0] = initializeStudent("Yoana", 20, 295);
		dynStudentsArr[1] = initializeStudent("Monika", 20, 101);
		dynStudentsArr[2] = initializeStudent("Ralitsa", 20, 266);

		writeArrStudentsToFile(ofs, dynStudentsArr, 3);

		freeStudent(dynStudentsArr[0]);
		freeStudent(dynStudentsArr[1]);
		freeStudent(dynStudentsArr[2]);
	}

	{
		std::ifstream ifs("StudentsFile.dat", std::ios::binary | std::ios::in);
		if (!ifs.is_open())
			return -1;

		size_t sizeArr;
		DynamicStudent* dynStArr;
		readStudentsArrFromFile(ifs, dynStArr, sizeArr);

		printStudentsArr(dynStArr, sizeArr);
		for (size_t i = 0; i < sizeArr; i++) {
			freeStudent(dynStArr[i]);
		}
	}
	return 0;
}

