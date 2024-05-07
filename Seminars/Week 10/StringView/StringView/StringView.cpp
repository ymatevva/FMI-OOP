#include "StringView.h"
#include<iostream>
StringView::StringView(const char* begin, const char* end):_begin(begin),_end(end)
{
}

StringView::StringView(const char* str):StringView(str,str+strlen(str))
{
}

StringView::StringView(const MyString& str):StringView(str.c_str())
{
}

char StringView::operator[](size_t index) const
{
	return _begin[index];
}

size_t StringView::getLen() const
{
	return _end - _begin;
}

StringView StringView::substr(size_t from, size_t len) const
{

	if (from + _begin + len > _end) {
		throw std::length_error("Out of bounds");
	}

	return StringView(from + _begin, from + _begin + len);;
}

std::ostream& operator<<(std::ostream& os, const StringView& obj)
{
	const char* iter = obj._begin;
	while (iter != obj._end) {
		os << *iter;
		iter++;
	}
	return os;
}

int main() {
	const char* str = "Hello, world!";
	StringView sv1(str);
	StringView sv2("Hello");
	MyString myString("Hello, world!");

	std::cout << "StringView 1: " << sv1 << std::endl;
	std::cout << "StringView 2: " << sv2 << std::endl;

	std::cout << "Length of StringView 1: " << sv1.getLen() << std::endl;
	std::cout << "Length of StringView 2: " << sv2.getLen() << std::endl;

	std::cout << "Character at index 7 in StringView 1: " << sv1[7] << std::endl;

	try {
		StringView substr = sv1.substr(7, 5);
		std::cout << "Substring of StringView 1 (from index 7, length 5): " << substr << std::endl;
	}
	catch (const std::length_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}