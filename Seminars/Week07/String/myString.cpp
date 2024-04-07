#include "myString.h"
#include <cstring>
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


void String::copyFrom(const String& other) {
    size = other.size;
    capacity = other.capacity;
    char* data = new char[other.capacity + 1];
    strcpy(data, other.data);
}

void String::free() {
    delete[] data;
}

String::String():String("") { }

String::String(const char* str) {
    if (!str) {
        data = new char[strlen(str) + 1];
        data[0] = '\0';
    }
    else {
        size = strlen(str);
        capacity = std::max((int)getNextPowerOfTwo(size), 16) - 1;
        data = new char[capacity + 1];
        strcpy(data, str);
    }
}

String& String::operator=(const String& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

String::String(const String& other) {
    copyFrom(other);
}

String::~String() {
    free();
}

String operator+(const String& lhs, const String& rhs)
{
    size_t resLen = lhs.size + rhs.size;
    size_t capacity = getNextPowerOfTwo(resLen) + 1;

    String res(capacity);
    strcpy(res.data, lhs.data);
    strcpy(res.data, rhs.data);
    res.size = resLen;

    return res;
}


size_t String::getSize() const {
    return this->size;
}
size_t String::getCapacity() const {
    return this->capacity;
}

const char* String::getData() const {
    return this->data;
}

void String::resize(size_t newCapacity) {
    capacity = size < 16 ? 16 : getNextPowerOfTwo(newCapacity + 1) - 1;
    char* newData = new char[capacity + 1];
    strcpy(newData, data);

    delete[] data;
    data = newData;
}

std::istream& operator>>(String& str, std::istream& is)
{
    // TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    // TODO: insert return statement here
}

bool operator==(const String& lhs, const String& rhs)
{
    return false;
}

bool operator!=(const String& lhs, const String& rhs)
{
    return false;
}

bool operator>=(const String& lhs, const String& rhs)
{
    return false;
}

bool operator<=(const String& lhs, const String& rhs)
{
    return false;
}

bool operator<(const String& lhs, const String& rhs)
{
    return false;
}

bool operator>(const String& lhs, const String& rhs)
{
    return false;
}

String& String::operator+=(const String& other) {
    size += other.size;
    if (size <= capacity) {
        strcat(data, other.data);
        return*this;
    }
    resize(size);
    strcat(data, other.data);
    return *this;
}

String& String::operator+=(char ch) {
    if (size == capacity) {
        resize(size + 1);
    }
    data[size++] = ch;
    return *this;
}

char& String::operator[](size_t index) {
    return data[index];
}
char String::operator[](size_t index) const{
    return data[index];
}


