#pragma once
#include<iostream>

namespace HelperFunctions {
	unsigned getNextPowOfTwo(unsigned num) {
		//
	}
}

class String {

	char* data = nullptr;
	size_t size = 0;
	size_t capacity = 15;


	void resize(size_t lenToFit);
	void copyFrom(const String& other);
	void free();
	explicit String(size_t capacity);

public:

	String();
	//Big Four
	String(const char* name);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	//getters
	size_t getSize()const;
	size_t getCapacity() const;
	const char* getData() const;

	//+=
	String& operator+=(const String& other);
	String& operator+=(char ch);

	//[]
	char& operator[](unsigned ind);
	char operator[](unsigned ind) const;


	friend  std::istream& operator>>(std::istream& is, String& str);
	friend String operator+(const String& lhs, const String& rhs);
};

std::ostream& operator<<(std::ostream& os, const String& str);
bool operator>(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);