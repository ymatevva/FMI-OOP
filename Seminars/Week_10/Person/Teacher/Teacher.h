#pragma once
#include<iostream>
#include<utility>
#include "Person.h"


class Teacher : public Person {

	char** _studentsSubjects;
	size_t _studentsCount;

	void copyFrom(const Teacher& other);
	void moveFrom(Teacher&& other);
	void free();

public:
	Teacher(const char* name, int age, const char* const *studentsSubjects, size_t studentsCount);
	Teacher(const Teacher& other);
	Teacher(Teacher&& other)noexcept;
	Teacher& operator=(const Teacher& other);
	Teacher& operator=(Teacher&& other)noexcept;
	~Teacher();

	void print()const;
};