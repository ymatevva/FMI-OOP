#include<iostream>

#pragma warning(disable : 4996)

constexpr int MAX_NAME_LEN = 20;
constexpr int MIN_NAME_LEN = 2;
constexpr int MAX_AGE_SIZE = 90;
constexpr int MIN_AGE_SIZE = 5;

namespace HelperFunctions {

	bool isLowerLetter(char ch) {
		return ch >= 'a' && ch <= 'z';
	}

	bool isCapLetter(char ch) {
		return ch >= 'A' && ch <= 'Z';
	}

	bool areAllLowerLetters(const char* str) {

		if (!str)
			return false;

		while (*str) {
			if (!isLowerLetter(*str))
				return false;
			str++;
		}
		return true;
	}
}


class Student {

	char name[MAX_NAME_LEN + 1] = "Unknown name";
	int age = MIN_AGE_SIZE;

	bool isValidAge(int age) {
		return age >= MIN_AGE_SIZE && age <= MAX_AGE_SIZE;
	}

	bool isValidName(const char* name) {

		if (!name)
			return false;

		size_t nameLen = strlen(name);

		if (nameLen < MIN_NAME_LEN || nameLen > MAX_NAME_LEN)
			return false;

		if (!HelperFunctions::isCapLetter(*name))
			return false;

		return HelperFunctions::areAllLowerLetters(name + 1);
	}



public:

	Student() = default;

	Student(const char* name, int age) {
		setName(name);
		setAge(age);
	}

	void setAge(int age) {
		
		if (isValidAge(age))
			this->age = age;
		else
			this->age = 0;
	}

	void setName(const char* name) {

		if (isValidName(name))
			strcpy(this->name, name);
		else
			strcpy(this->name, "Unknown name");
	}

	int getAge() const {
		return age;
	}	

	const char* getName() const {
		return name;
	}

	void printStudent() {
		std::cout << "Name of student: " << this->name << "  Age of student: " << this->age << std::endl;
	}

};
int main() {

	Student myStudent("Yoana", 20);
	myStudent.printStudent();

	myStudent.setAge(28);
	myStudent.printStudent();

	myStudent.setName("Monika");
	myStudent.printStudent();

	return 0;
}