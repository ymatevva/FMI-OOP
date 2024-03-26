#include<iostream>
#include<fstream>
//not completed
#pragma warning (disable:4996)

constexpr int MAX_STUDENTS = 100;
constexpr int MAX_GRADES = 32;

enum class Department {
	Undefined,
	Algebra,
	Geometry,
	ComputerScience
};


void setString(char* dest,const char* source) {
	if (!source)
		return;

	delete[] dest;
	dest = new char[strlen(source) + 1];
	strcpy(dest, source);
}

struct Student {


private:

	char* firstName = nullptr;
	char* lastName = nullptr;
	char* FN = nullptr;
	size_t gradesCount = 0;
	float grades[MAX_GRADES];

	void copyGrades(const float* grades, size_t sizeArr) {
		
		if (!grades)
			return;

		for (size_t i = 0; i < sizeArr; i++){
			this->grades[i] = grades[i];
		}
	}

public:

	Student() : Student("Undefined", "Undefined", "Undefined", 0, {0 }) {}

	Student(const char* firstName, const char* lastName, const char* FN, size_t gradesCount, const float* grades ) {

		setString(this->firstName, firstName);
		setString(this->lastName, lastName);
		setString(this->FN, FN);
		this->gradesCount = gradesCount;
		this->copyGrades(grades, gradesCount);
	}

	~Student() {
		delete[] firstName;
		delete[] lastName;
		delete[] FN;
	}

	const char* getFirstName() const {
		return this->firstName;
	}

	const char* getLastName() const {
		return this->lastName;
	}

	const char* getFN() const {
		return this->FN;
	}

	const float* getGrades() const {
		return this->grades;
	}

	void addGrade(float grade) {
		if (this->gradesCount + 1 > MAX_GRADES)
			return;
		if (grade < 2 || grade > 6)
			return;

		this->grades[gradesCount++] = grade;
	}

	void removeGrade() {

		if (gradesCount - 1 < 0)
			return;
		this->grades[gradesCount--] = 0;
	}

	float getAvgGrade() const {

		float sum = 0;
		for (size_t i = 0; i < this->gradesCount; i++){
			sum += this->grades[i];
		}
		return sum / this->gradesCount;
	}

	void serialize(std::ofstream& ofs) const{

		size_t firstNameLen = strlen(this->firstName);
		ofs.write((const char*)&firstNameLen, sizeof(firstNameLen));
		ofs.write(this->firstName, firstNameLen + 1);

		size_t lastNameLen = strlen(this->lastName);
		ofs.write((const char*)&lastNameLen, sizeof(lastNameLen));
		ofs.write(this->lastName, lastNameLen + 1);

		
		size_t FNLen = strlen(this->FN);
		ofs.write((const char*)&FNLen, sizeof(FNLen));
		ofs.write(this->FN, FNLen + 1);

		ofs.write((const char*)&this->gradesCount, sizeof(this->gradesCount));
		ofs.write((const char*)this->grades, sizeof(float) * this->gradesCount);
	}

	void deserialize(std::ifstream& ifs) {

		size_t firstNameLen = 0;
		ifs.read((char*)&firstNameLen, sizeof(firstNameLen));
		this->firstName = new char[firstNameLen + 1];
		ifs.read(this->firstName, firstNameLen + 1);
	

		size_t lastNameLen = 0;
		ifs.read((char*)&lastNameLen, sizeof(lastNameLen));
		this->lastName = new char[lastNameLen + 1];
		ifs.read(this->lastName, lastNameLen + 1);

		size_t FNLen = 0;
		ifs.read((char*)&FNLen, sizeof(FNLen));
		this->FN = new char[FNLen + 1];
		ifs.read(this->FN, FNLen + 1);

		ifs.read((char*)&gradesCount, sizeof(gradesCount));
		ifs.read((char*)grades, sizeof(float) * gradesCount);
	}

	void copyTo(Student& otherSt) const {
		setString(otherSt.firstName, this->firstName);
		setString(otherSt.lastName, this->lastName);
		setString(otherSt.FN, this->FN);
		otherSt.gradesCount = this->gradesCount;
		otherSt.copyGrades(this->grades,this->gradesCount);
	}

};

struct Teacher {


private:

	char* firstName = nullptr;
	char* lastName = nullptr;
	Department department = Department::Undefined;



public:

	Teacher() : Teacher("Undefined", "Undefined", Department::Undefined)
	{

	}
	Teacher(const char* firstName, const char* lastName, const Department& department) {

		setString(this->firstName, firstName);
		setString(this->lastName, lastName);
		this->department = department;
	}

	const char* getFirstName() const {
		return this->firstName;
	}

	const char* getLastName() const {
		return this->lastName;
	}

	Department getDepartment() const {
		return this->department;
	}

	~Teacher() {
		delete[] firstName;
		delete[] lastName;
	}

	void serialize(std::ofstream& ofs) const {

		size_t firstNameLen = strlen(firstName);
		ofs.write((const char*)&firstNameLen, sizeof(firstNameLen));
		ofs.write(this->firstName, firstNameLen + 1);

		size_t lastNameLen = strlen(lastName);
		ofs.write((const char*)&lastNameLen, sizeof(lastNameLen));
		ofs.write(this->lastName, lastNameLen + 1);

		ofs.write((const char*)&department, sizeof(department));
	}

	void deserialize(std::ifstream& ifs) {

		size_t firstNameLen = 0;
		ifs.read((char*)&firstNameLen, sizeof(firstNameLen));
		this->firstName = new char[firstNameLen + 1];
		ifs.read(this->firstName, firstNameLen + 1);

		size_t lastNameLen = 0;
		ifs.read((char*)&lastNameLen, sizeof(lastNameLen));
		this->lastName = new char[lastNameLen + 1];
		ifs.read(this->lastName, lastNameLen + 1);

		ifs.read((char*)&department, sizeof(department));
	}

	void copyTo(Teacher& otherTeacher) const {

		setString(otherTeacher.firstName, this->firstName);
		setString(otherTeacher.lastName, this->lastName);
		otherTeacher.department = this->department;
	}
};


struct Subject {

private:

	size_t studentsCount = 0;
	Student students[MAX_STUDENTS];
	Teacher teacher{};

	
	bool containsStudent(const Student& student)
	{
		for (size_t i = 0; i < this->studentsCount; i++)
		{
			if (strcmp(student.getFN(), this->students[i].getFN()) == 0)
			{
				return true;
			}
		}
		return false;
	}

	void serialize(std::ofstream& ofs)const {

		ofs.write((const char*)&studentsCount, sizeof(studentsCount));

		for (size_t i = 0; i < this->studentsCount; i++)
		{
			this->students[i].serialize(ofs);
		}
		this->teacher.serialize(ofs);
	}

	void deserialize(std::ifstream& ifs) {

		ifs.read((char*)&studentsCount, sizeof(studentsCount));

		for (size_t i = 0; i < this->studentsCount; i++)
		{
			this->students[i].deserialize(ifs);
		}
		this->teacher.deserialize(ifs);
	}

public:

	Subject() : studentsCount(0) {

	}

	Subject(size_t studentsCount, const Student* students, const Teacher& teacher) {

		if (!students)
			return;

		for (size_t i = 0; i < studentsCount; i++)
		{
			addStudent(students[i]);
		}
		addTeacher(teacher);
	}

	void addStudent(const Student& student) {

		if (studentsCount + 1 > MAX_STUDENTS)
			return;

		if (this->containsStudent(student))
		return;
		student.copyTo(this->students[studentsCount++]);
	}

	void addTeacher(const Teacher& teacher){
		teacher.copyTo(this->teacher);
	}

	void serialize(const char* toFile) const
	{
		if (!toFile) {
			return;
		}

		std::ofstream ofs(toFile, std::ios::binary);
		if (!ofs.is_open()) {
			return;
		}

		serialize(ofs);
	}

	void deserialize(const char* fromFile)
	{
		if (!fromFile) {
			return;
		}

		std::ifstream ifs(fromFile, std::ios::binary);
		if (!ifs.is_open()) {
			return;
		}

		deserialize(ifs);
	}
};

int main() {

	float firstGrades[4] = { 5, 4.7, 6, 3 };
	float secondGrades[6] = { 2, 4.3, 6, 5.5, 5.2, 5.3 };
	Student students[2] = { {"Student1", "Family1",  "1111111111",4,firstGrades, },  {"Student2", "Family2","2222222222" , 6,secondGrades} };
	Subject subject( 2,students, { "Ivan", "Petrov", Department::ComputerScience });

	subject.serialize("subject.dat");

	Subject deserialized;
	deserialized.deserialize("subject.dat");

	return 0;
}