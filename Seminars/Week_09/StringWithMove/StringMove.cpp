#include "StringMove.h"



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

void MyString::resize(size_t newCap)
{
    cap = newCap;
    char* temp = new char[newCap];
    strcpy(temp, data);
    delete[] data;
    data = temp;
}

void MyString::copyFrom(const MyString& other)
{
    size = other.size;
    cap = other.cap;
    data = new char[cap];
    strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other)
{
    size = other.size;
    other.size = 0;
    data = other.data;
    other.data = nullptr;
    cap = other.cap;
    other.cap = 0;
}

void MyString::free()
{
	delete[] data;
}

MyString::MyString(size_t stringLen)
{
    cap = dataToAllocByStringLen(stringLen);
    data = new char[cap];
    data[0] = '\0';
    size = 0;
}

MyString::MyString():MyString("")
{
}

MyString::MyString(const char* data)
{
    size = strlen(data);
    cap = dataToAllocByStringLen(size);
    this->data = new char[cap];
    strcpy(this->data, data);
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString::MyString(MyString&& other)
{
    moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

size_t MyString::getCap() const
{
    return cap-1;
}

const char* MyString::getData() const
{
    return data;
}

MyString& MyString::operator+=(const MyString& other)
{
    if (getSize() + other.getSize() + 1 > getCap())
        resize(dataToAllocByStringLen(getSize() + other.getSize()));

    strncpy(data, other.data, other.getSize());
    size = getSize() + other.getSize();
    return *this;
}

const char& MyString::operator[](size_t ind) const
{
    return data[ind];
}

char& MyString::operator[](size_t ind)
{
    return data[ind];
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
    return os << obj.data;
}

std::istream& operator>>(std::istream& is, MyString& obj)
{
    char buff[1024];
    is >> buff;

    obj.size = strlen(buff);
    obj.cap = dataToAllocByStringLen(obj.size);
    obj.data = new char[obj.cap];
    strcpy(obj.data, buff);
    return is;

}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    return MyString();
}
