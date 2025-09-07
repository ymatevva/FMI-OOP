#include<cstring>
#include<utility>
#include<exception>
#include<iostream>
#include "Person.h"

#pragma warning (disable:4996)

void Person::copyFrom(const Person& other)
{
	_name = new char[strlen(other._name) + 1];
	strcpy(_name,other._name);
	_age = other._age;
}

void Person::moveFrom(Person&& other)
{
	_age = other._age;
	other._age = 0;

	_name = other._name;
	other._name = nullptr;
}

void Person::free()
{
	delete[] _name;
}

Person::Person(const char* name, int age)
{
	setName(name);
	setAge(age);
}

Person::Person(const Person& other)
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Person::Person(Person&& other) noexcept
{
	moveFrom(std::move(other));
}

Person& Person::operator=(Person&& other)noexcept 
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Person::~Person()
{
	free();
}

const char* Person::getName() const
{
	return _name;
}

int Person::getAge() const
{
	return _age;
}

void Person::setName(const char* name)
{
	if (!name || _name == name) {
		throw std::invalid_argument("The name is not valid.");
	}

	delete[] _name;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
}

void Person::setAge(int age)
{
	if (age < 0|| age > 100) {
		throw std::invalid_argument("The age is not valid.");
	}
	_age = age;
}

void Person::print() const
{
	std::cout << "Name: " << _name << " Age: " << _age << std::endl;
}

