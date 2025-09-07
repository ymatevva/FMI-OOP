#include "Student.h"
#include<iostream>
#pragma warning(disable:4996)

void Student::copyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	FN = other.FN;
	major = other.major;
}

void Student::moveFrom(Student&& other)
{
	name = other.name;
	other.name = nullptr;

	FN = other.FN;
	other.FN = 0;

	major = other.major;
	other.major = Major::None;
}

void Student::free()
{
	delete[] name;
}

Student::Student() : name(nullptr),FN(0),major(Major::None)
{
}

Student::Student(const char* name, unsigned FN, Major major)
{
	setName(name);
	setFN(FN);
	setMajor(major);
}

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student::Student(Student&& other) noexcept
{
	moveFrom(std::move(other));
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Student& Student::operator=(Student&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Student::~Student()
{
	free();
}

const char* Student::getName() const
{
	return name;
}

unsigned Student::getFN() const
{
	return FN;
}

Major Student::getMajor() const
{
	return major;
}

void Student::setName(const char* _name)
{
	if (!_name || this->name == _name) {
		throw std::invalid_argument("The name is not valid");
	}

	delete[] name;
	this->name = new char[strlen(_name) + 1];
	strcpy(this->name,_name);
}

void Student::setFN(unsigned FN)
{
	this->FN = FN;
}

void Student::setMajor(Major major)
{
	this->major = major;
}

std::ostream& operator<<(std::ostream& os, const Student& st)
{

	return os << "Name: "
		<< (st.getName() != nullptr ? st.getName() : "The name is default.")
		<< " FN: " << st.getFN() << " Major: " << (int)st.getMajor();
}
