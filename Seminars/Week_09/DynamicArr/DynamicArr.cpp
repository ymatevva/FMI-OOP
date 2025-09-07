#include "DynamicArr.h"
#include<utility>
#include<exception>

static size_t closestPowerOfTwo(size_t n)
{
	n--;

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;

	return n + 1;
};

DynamicArr::DynamicArr(size_t capacity) 
{
	cap = closestPowerOfTwo(capacity);
	data = new A[cap];
}
void DynamicArr::copyFrom(const DynamicArr& other)
{
	size = other.size;
	cap = other.cap;
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
	
}

void DynamicArr::moveFrom(DynamicArr&& other)
{
	size = other.size;
	other.size = 0;

	cap = other.cap;
	other.cap = 0;

	data = other.data;
	other.data = nullptr;
}


void DynamicArr::free()
{
	delete[] data;
}

void DynamicArr::resize(size_t newCap)
{
	cap = newCap;
	A* temp = new A[cap];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

DynamicArr::DynamicArr():DynamicArr(8)
{

}

DynamicArr::DynamicArr(const DynamicArr& other)
{
	copyFrom(other);
}

DynamicArr::DynamicArr(DynamicArr&& other)
{
	moveFrom(std::move(other));
}

DynamicArr& DynamicArr::operator=(const DynamicArr& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicArr& DynamicArr::operator=(DynamicArr&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

DynamicArr::~DynamicArr()
{
	free();
}

void DynamicArr::putAtIndex(const A& element, size_t index)
{
	if (index >= size) {
		throw std::exception("Index is out of range");
	}
	data[index] = element;
}

void DynamicArr::putAtIndex(A&& element, size_t index)
{
	if (index >= size) {
		throw std::exception("Index is out of range");
	}
	data[index] = std::move (element);
}

void DynamicArr::pushBack(const A& element)
{
	if (size == cap)
		resize(cap * 2);

	data[size++] = element;
}

void DynamicArr::pushBack(A&& element)
{
	if (size == cap)
		resize(cap * 2);

	data[size++] = std::move(element);
}

void DynamicArr::popBack()
{
	if (size)
		size--;
	else
		throw std::exception("no elements left");

	if (size * 4 <= cap && cap > 1)
		resize(cap / 2);
}

A& DynamicArr::operator[](size_t index)
{
	return data[index];
}

const A& DynamicArr::operator[](size_t index) const
{
	return data[index];
}

size_t DynamicArr::getSize() const
{
	return size;
}

bool DynamicArr::isEmpty() const
{
	return size == 0;
}


