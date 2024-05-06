#include "StudentArray.h"
#include<exception>
#include<iostream>

void StudentArray::resize(size_t newCap)
{
	capacity = newCap;
	Student** tmp = data;
	data = new Student* [capacity] {nullptr};

	for (size_t i = 0; i < capacity; i++)
	{
		if (tmp[i])
		{
			this->data[i] = new Student(*tmp[i]);
		}
	}
	delete[] tmp;
}
void StudentArray::copyFrom(const StudentArray& other)
{
	capacity = other.capacity;
	count = other.count;
	data = new Student * [capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		if(other.data[i] == nullptr){
			data[i] = nullptr;
		}
		else {
			data[i] = new Student(*other.data[i]);
		}
	}

}
void StudentArray::moveFrom(StudentArray&& other)
{
	count = other.count;
	other.count = 0;

	capacity = other.capacity;
	other.capacity = 0;

	data = other.data;
	other.data = nullptr;
}
void StudentArray::free()
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}
int StudentArray::getFirstFreeIndex() const
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (data[i] == nullptr){ 
			return i;
		}
	}
	return -1;
}
int StudentArray::getLastFreeIndex() const
{
	for (int i = capacity-1; i >= 0; i--)
	{
		if (data[i] == nullptr) {
			return i;
		}
	}
	return -1;
}

StudentArray::StudentArray()
{
	count = 0;
	capacity = 8;
	data = new Student * [capacity]; // Allocate memory for pointers

	// Initialize pointers to nullptr
	for (size_t i = 0; i < capacity; ++i)
	{
		data[i] = nullptr;
	}
}

StudentArray::StudentArray(const StudentArray& other)
{
	copyFrom(other);
}

StudentArray& StudentArray::operator=(const StudentArray& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
StudentArray::StudentArray(StudentArray&& other) noexcept
{
	moveFrom(std::move(other));
}
StudentArray& StudentArray::operator=(StudentArray&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
StudentArray::~StudentArray()
{
	free();
}
void StudentArray::pushBack(const Student& st)
{
	if (count == capacity) {
		resize(capacity * 2);
	}

	int firstFree = getFirstFreeIndex();
	data[firstFree] = new Student(st);
	count++;
}
void StudentArray::pushBack(Student&& st)
{
	if (count == capacity) {
		resize(capacity * 2);
	}

	int firstFree = getFirstFreeIndex();
	data[firstFree] = new Student(std::move(st));
	count++;
}

void StudentArray::pushFront(const Student& st)
{
	if (count == capacity) {
		resize(capacity * 2);
	}

	for (int i = capacity; i >= 0; i--)
	{
		data[i + 1] = data[i];
	}

	delete[] data[0];
	data[0] = nullptr;
	data[0] = new Student(st);
	count++;
}

void StudentArray::pushFront(Student&& st)
{
	if (count == capacity) {
		resize(capacity * 2);
	}

	for (int i = capacity; i >= 0; i--)
	{
		data[i + 1] = data[i];
	}

	delete[] data[0];
	data[0] = nullptr;
	data[0] = new Student(std::move(st));
	count++;
}

const Student& StudentArray::getBack() const
{
	int lastFree = getLastFreeIndex();
	if (lastFree == -1) {
		throw std::logic_error("The array is full.");
	}

	return *data[lastFree];
}

Student& StudentArray::getBack()
{
	int lastFree = getLastFreeIndex();
	if (lastFree == -1) {
		throw std::logic_error("The array is full.");
	}

	return *data[lastFree];
}

const Student& StudentArray::getFront() const
{
	int firstFree = getFirstFreeIndex();
	if (firstFree == -1) {
		throw std::logic_error("The array is full.");
	}

	return *data[firstFree];
}

Student& StudentArray::getFront()
{
	int firstFree = getFirstFreeIndex();
	if (firstFree == -1) {
		throw std::logic_error("The array is full.");
	}

	return *data[firstFree];
}

size_t StudentArray::getCount() const
{
	return count;
}

const Student& StudentArray::at(size_t index) const
{
	if (index < 0 || index >= capacity || data[index] == nullptr) {
		throw std::invalid_argument("The index is not valid");
	}
	return *data[index];
}

Student& StudentArray::at(size_t index)
{
	if (index < 0 || index >= capacity || data[index] == nullptr) {
		throw std::invalid_argument("The index is not valid");
	}
	return *data[index];
}

std::ostream& operator<<(std::ostream& os, const StudentArray& arr)
{
	for (size_t i = 0; i < arr.capacity; i++)
	{
		if (arr.data[i] != nullptr)
		{
			os << *arr.data[i] << std::endl;
		}
	}
	return os;
}
int main() {
	
	Student st1;
	std::cout << "Default constructed student:" << std::endl;
	std::cout << st1 << std::endl;

	 
	Student st2("Alice", 123456, Major::CS);
	std::cout << "Parameterized constructed student:" << std::endl;
	std::cout << st2 << std::endl;

	
	Student st3 = st2;
	std::cout << "Copy constructed student:" << std::endl;
	std::cout << st3 << std::endl;

	
	Student st4 = std::move(st3);
	std::cout << "Move constructed student:" << std::endl;
	std::cout << st4 << std::endl;

	 
	Student st5;
	st5 = st2;
	std::cout << "Student after assignment:" << std::endl;
	std::cout << st5 << std::endl;

	
	Student st6;
	st6 = std::move(st5);
	std::cout << "Student after move assignment:" << std::endl;
	std::cout << st6 << std::endl;

	 
	st6.setName("Bob");
	st6.setFN(654321);
	st6.setMajor(Major::IS);
	std::cout << "Student after setters:" << std::endl;
	std::cout << st6 << std::endl;

	std::cout << "Name: " << st6.getName() << std::endl;
	std::cout << "FN: " << st6.getFN() << std::endl;
	std::cout << "Major: " << (int)st6.getMajor() << std::endl;

	return 0;
}
