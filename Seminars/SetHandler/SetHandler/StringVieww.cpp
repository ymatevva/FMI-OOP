#include "StringVieww.h"
#include<iostream>
StringView::StringView(const char* begin, const char* end) :_begin(begin), _end(end)
{
}

StringView::StringView(const char* str) :StringView(str, str + strlen(str))
{
}

StringView::StringView(const MyString& str) :StringView(str.c_str())
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
