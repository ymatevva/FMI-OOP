#include"myString.h"
#include<iostream>
#include<cstring>

#pragma warning(disable:4996)

namespace StringHelperFunctions {
    unsigned int getNextPowerOfTwo(unsigned int n) {
        unsigned int step = 1;

        while ((n >> step) > 0) {
            n |= n >> step;
            step *= 2;
        }

        return n + 1;
    }
}

using namespace StringHelperFunctions;

void String::resize(size_t lenToFit) {

    capacity = size < 16 ? 15 : getNextPowerOfTwo(lenToFit + 1) - 1;
    char* temp = new char[capacity + 1];
    strcpy(temp, data);
    delete[] data;
    data = temp;
}

void String::copyFrom(const String& other) {
    size = other.size;
    capacity = other.capacity;
    data = new char[capacity + 1];
    strcpy(data, other.data);
}

void String::free() {
    delete[] data;
}

String::String(size_t capacity) {
    data = new char[capacity + 1];
}

String& String::operator+=(const String& other) {
    size += other.size;
    if (size >= capacity) {
        resize(size);
        strcat(data, other.data);
        return*this;
    }

    strcat(data, other.data);
    return*this;
}

String& String::operator+=(char ch) {

    if (size == capacity) {
        resize(size + 1);
    }

    data[size++] = ch;
    return*this;
}

char& String::operator[](unsigned ind) {
    return data[ind];
}

char String::operator[](unsigned ind) const {
    return data[ind];
}

String::String() :String("") {}

String::String(const char* data) {
    if (!data) {
        this->data = new char[capacity + 1];
        this->data[0] = '\0';
    }
    else {
        size = strlen(data);
        capacity = std::max((int)getNextPowerOfTwo(size), 16) - 1;
        this->data = new char[capacity + 1];
        strcpy(this->data, data);
    }
}
String::String(const String& other) {
    copyFrom(other);
}

String& String::operator=(const String& other) {
  
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

String::~String() {
    free();
}

size_t String::getSize() const {
    return size;
}

size_t String::getCapacity() const {
    return capacity;
}

const char* String::getData() const {
    return data;
}

String operator+(const String& lhs, const String& rhs) {
    
    size_t newSize = lhs.size + rhs.size;
    size_t newCapacity = getNextPowerOfTwo(newSize) - 1;

    String res(newCapacity);
    strcpy(res.data, lhs.data);
    strcat(res.data, rhs.data);

    res.size = newSize;
    return res;
}

std::istream& operator>>(std::istream& is, String& str) {
    char buff[1024];
    is >> buff;

    delete[] str.data;
    str.size = strlen(buff);
    str.capacity = std::max((int)getNextPowerOfTwo(str.size), 16) - 1;
    str.data = new char[str.capacity + 1];
    strcpy(str.data, buff);

    return is;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << str.getData();
}

bool operator>(const String& lhs, const String& rhs) {
    return strcmp(lhs.getData(), rhs.getData()) > 0;
}

bool operator<(const String& lhs, const String& rhs) {
    return strcmp(lhs.getData(), rhs.getData()) < 0;
}

bool operator>=(const String& lhs, const String& rhs) {
    return strcmp(lhs.getData(), rhs.getData()) >= 0;
}

bool operator<=(const String& lhs, const String& rhs) {
    return strcmp(lhs.getData(), rhs.getData()) <= 0;
}

bool operator==(const String& lhs, const String& rhs) {
    return strcmp(lhs.getData(), rhs.getData()) == 0;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}