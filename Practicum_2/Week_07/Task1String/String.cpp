#include<iostream>
#include"String.h"
#include <exception>


#pragma warning(disable:4996)
void String::copyFrom(const String& other) {
	str = new char[other.capacity];
	for (size_t i = 0; i < other.capacity; i++){
		str[i] = other.str[i];
	}
	str[other.capacity-1] = '\0';
	size = other.size;
	capacity = other.capacity;
}

void String::free() {
	delete[] str;
}

void String::setStr(const char* str)
{
	if (!str)
		return;
	this->str = new char[strlen(str) +1];
	strcpy(this->str, str);
	this->size = strlen(str);
	this->capacity = strlen(str) + 1;
}

String::String(const char* str) {
	setStr(str);	
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

const char* String::getStr() const{
	return this->str;
}

char String::at(unsigned index) const{
	if (index > size)
		return '\0';

	return this->str[index];
}

char String::front() const{
	if (!this->str)
		return '\0';

	return this->str[0];
}

char String::back() const{
	if (!this->str)
		return '\0';

	return this->str[size - 2];
}

unsigned String::lengthStr() const{
	return this->size;
}

unsigned String::capacityStr() const{
	return this->capacity;
}

bool String::isEmpty() const{
	return size == 0;
}

void String::resize(unsigned newCapacity) {

	char* temp = new char[newCapacity];
	strcpy(temp, str);
	delete[] str;
	str = temp;
	capacity = newCapacity;
}

void String::appChar(char ch) {
	if (size + 1 >= capacity)
		resize(capacity * 2);
	
	str[size++] = ch;
}
void String::appendStr(const char* strToApp) {
	if (!strToApp)
		return;

	if (strlen(strToApp) + 1 + size >= capacity)
		resize(capacity * 2);

	strcat(str, strToApp);
	size += strlen(strToApp);

	
}
void String::appStrings(const String& other){
	appendStr(other.str);
}

void String::clear(){
	for (size_t i = 0; i < this->size; i++){
		this->str[i] = 0;
	}
	this->size = 0;
}

bool String::areEqual(const String& other) const
{
	if (this->size != other.size)
		return false;
	
	return strcmp(this->str, other.str) == 0;
}

int String::findSymbol(char ch) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] == ch)
			return i;
	}
	return -1;
}

size_t String::getCapacity() const {
	return this->capacity;
}
int main() {

	String myStr ("Yoana");
	std::cout <<"Index of symbol: " << myStr.findSymbol('a')<< std::endl;
	std::cout << "Len of str: " << myStr.lengthStr() << std::endl;
	std::cout << "Size: " << myStr.getCapacity() << std::endl;
	std::cout << "First element: " << myStr.front() << std::endl;
	std::cout << "Last element: " << myStr.back() << std::endl;
	std::cout << "Str:" << myStr.getStr() << std::endl;
	std::cout << "Is empty " << std::boolalpha << myStr.isEmpty() << std::endl;
	//myStr.clear();
	std::cout << "Is empty " << std::boolalpha << myStr.isEmpty()  <<  std::endl;
	std::cout << "Are equal " << std::boolalpha << myStr.areEqual("Yoana") << std::endl;
	
	String myStr2("Hello");
	myStr.appStrings(myStr2);

	std::cout << "Str:" << myStr.getStr() << std::endl;
} 