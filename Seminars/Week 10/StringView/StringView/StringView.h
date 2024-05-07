#pragma once
#include<fstream>
#include"MyString.h"

class StringView {

	const char* _begin;
	const char* _end;

public:
	StringView(const char* begin, const char* end);
	StringView(const char* str);
	StringView(const MyString& str);

	char operator[](size_t index)const;
	size_t getLen() const;

	StringView substr(size_t from, size_t len)const;
	friend std::ostream& operator<<(std::ostream& os, const StringView& obj);

};