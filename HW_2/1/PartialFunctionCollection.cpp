#include "PartialFunctionCollection.h"
#include "SharedPtr.hpp"
#include <utility>
#include <exception>

PartialFunctionCollection::PartialFunctionCollection() : size(0), capacity(4) {
	partialFunctions = new PartialFunction * [capacity];
}

PartialFunctionCollection::PartialFunctionCollection(const PartialFunctionCollection& other) {
	copyFrom(other);
}

PartialFunctionCollection::PartialFunctionCollection(PartialFunctionCollection&& other) noexcept {
	move(std::move(other));
}

PartialFunctionCollection& PartialFunctionCollection::operator=(const PartialFunctionCollection& other) {

	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

PartialFunctionCollection& PartialFunctionCollection::operator=(PartialFunctionCollection&& other) noexcept {

	if (this != &other) {
		free();
		move(std::move(other));
	}
	return *this;
}

PartialFunctionCollection::~PartialFunctionCollection() {
	free();
}

void PartialFunctionCollection::resize() {

	PartialFunction** temp = new PartialFunction * [capacity *= 2];

	for (size_t i = 0; i < size; i++) {
		temp[i] = partialFunctions[i];
	}

	delete[] partialFunctions;
	partialFunctions = temp;
}

size_t PartialFunctionCollection::getSize()const {
	return size;
}

const PartialFunction* PartialFunctionCollection::operator[](size_t index)const {
	if (index >= size) {
		throw std::out_of_range("The index is out of range");
	}
	return partialFunctions[index];
}

PartialFunction* PartialFunctionCollection::operator[](size_t index) {
	if (index >= size) {
		throw std::out_of_range("The index is out of range");
	}
	return partialFunctions[index];
}

void PartialFunctionCollection::addPartialFunction(UniquePointer<PartialFunction>& newFunc) {

	if (size == capacity) {
		resize();
	}
	partialFunctions[size++] = newFunc.release();
}

void PartialFunctionCollection::addPartialFunction(const SharedPtr<PartialFunction>& newFunc) {

	if (size == capacity) {
		resize();
	}
	partialFunctions[size++] = newFunc.operator->();
}

void PartialFunctionCollection::addPartialFunction(PartialFunction* newFunc) {

	if (size == capacity) {
		resize();
	}
	partialFunctions[size++] = newFunc->clone();
}

void PartialFunctionCollection::move(PartialFunctionCollection&& other) {

	partialFunctions = other.partialFunctions;
	other.partialFunctions = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

void PartialFunctionCollection::copyFrom(const PartialFunctionCollection& other) {

	size = other.size;
	capacity = other.capacity;

	partialFunctions = new PartialFunction * [capacity];
	for (size_t i = 0; i < size; i++) {
		partialFunctions[i] = other.partialFunctions[i]->clone();
	}
}

void PartialFunctionCollection::free() {

	for (size_t i = 0; i < size; i++) {
		delete partialFunctions[i];
	}

	delete[] partialFunctions;
	partialFunctions = nullptr;
}