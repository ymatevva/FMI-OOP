#pragma once
#include<iostream>
#include<fstream>

class MyString {

	char* data = nullptr;
	size_t size;
	size_t cap;

	void resize(size_t newCap);
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();
	explicit MyString(size_t stringLen);

public:
	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other)noexcept;
	MyString& operator=(MyString&& other)noexcept;
	~MyString();


	size_t getSize() const;
	size_t getCap() const;
	const char* getData() const;

	MyString& operator+=(const MyString& other);

	const char& operator[](size_t ind) const;
    char& operator[](size_t ind) ;

	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is,  MyString& obj);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);

};