#pragma once
#include<fstream>

enum class Major{
	IS,
	CS,
	Inf,
	SE,
	None
};
class Student {

	char* name;
	unsigned FN;
	Major major;

	void copyFrom(const Student& other);
	void moveFrom(Student&& other);
	void free();


public:

	Student();
	Student(const char* name, unsigned FN, Major major);
	Student(const Student& other);
	Student(Student&& other)noexcept;
	Student& operator=(const Student& other);
	Student& operator=(Student&& other)noexcept;
	~Student();

	const char* getName() const;
	unsigned getFN() const;
	Major getMajor() const;

	void setName(const char* name);
	void setFN(unsigned FN);
	void setMajor(Major major);

	friend std::ostream& operator<<(std::ostream& os, const Student& st);
	
};
