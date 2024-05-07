#pragma once
#include<iostream>
#include"Person.h"

class Student : public Person{

	size_t _fn;

public:
	
	Student(const char* name, int age, size_t fn);
	
	size_t getFn() const;
	void setFn(size_t fn);

	void print() const;

};