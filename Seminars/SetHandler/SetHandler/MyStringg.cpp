#include "MyStringg.h"
#include<iostream>
#include<utility>
#include<exception>

#pragma warning (disable:4996)

static unsigned roundToPowerOfTwo(unsigned v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

static unsigned dataToAllocByStringLen(unsigned stringLength)
{
    return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}


void MyString::copyFrom(const MyString& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new char[strlen(other.data) + 1];
    strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other)
{
    size = other.size;
    other.size = 0;

    capacity = other.capacity;
    other.capacity = 0;

    data = other.data;
    other.data = nullptr;
}

void MyString::free()
{
    delete[] data;
}

void MyString::resize(size_t newCap)
{
    capacity = newCap;
    char* tmp = new char[capacity + 1];
    strcpy(tmp, data);
    delete[] data;
    data = tmp;
}

MyString::MyString(size_t strLen)
{
    size = 0;
    capacity = dataToAllocByStringLen(strLen);
    data = new char[capacity];
    data[0] = '\0';
}

MyString::MyString() :MyString("") {}

MyString::MyString(const char* data)
{
    size = strlen(data);
    capacity = dataToAllocByStringLen(size);
    this->data = new char[capacity];
    strcpy(this->data, data);
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept
{
    moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        free();
        copyFrom((other));
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

size_t MyString::getCapacity() const
{
    return capacity - 1;
}

const char* MyString::c_str() const
{
    return data;
}

size_t MyString::getSize() const
{
    return size;
}

const char& MyString::operator[](size_t index) const
{
    return data[index];
}

char& MyString::operator[](size_t index)
{
    return data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
    if (size + other.size + 1 > capacity) {
        resize(dataToAllocByStringLen(size + other.size));
    }

    size += other.size;
    strncat(data, other.data, other.size);
    return *this;
}

MyString MyString::substr(size_t from, size_t len) const
{
    if (from + len > getSize()) {
        throw std::length_error("The string is not that long.");
    }

    MyString res(len + 1);
    strncat(res.data, data + from, len);
    return res;

}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString res(lhs.getSize() + rhs.getSize());
    res += lhs;
    res += rhs;
    return res;
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
    return os << obj.data;
}

std::istream& operator>>(std::istream& is, MyString& obj)
{
    char buff[1024];
    is >> buff;

    if (strlen(buff) > obj.getCapacity()) {
        obj.resize(dataToAllocByStringLen(strlen(buff)));
    }

    obj.size = strlen(buff);
    strcpy(obj.data, buff);
    return is;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
