#pragma once
#include<fstream>

class MyString {

	char* data;
	size_t size;
	size_t capacity;

	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();
	void resize(size_t newCap);
	explicit MyString(size_t strLen);

public:
	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString(MyString&& other)noexcept;
	MyString& operator=(MyString&& other)noexcept;
	MyString& operator=(const MyString& other);
	~MyString();

	size_t getCapacity()const;
	const char* c_str() const;
	size_t getSize() const;

	const char& operator[](size_t index) const;
	char& operator[](size_t index);

	MyString& operator+=(const MyString& other);
	MyString substr(size_t from, size_t len) const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& obj);
};
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);