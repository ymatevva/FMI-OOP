#pragma once
#include "PartialFunction.h"
#include "SharedPtr.hpp"
#include "UniquePtr.hpp"


class PartialFunctionCollection {

	PartialFunction** partialFunctions = nullptr;
	size_t size;
	size_t capacity;

	void move(PartialFunctionCollection&& other);
	void copyFrom(const PartialFunctionCollection& other);
	void free();
	void resize();

public:
	PartialFunctionCollection();
	PartialFunctionCollection(const PartialFunctionCollection& other);
	PartialFunctionCollection(PartialFunctionCollection&& other) noexcept;
	PartialFunctionCollection& operator=(const PartialFunctionCollection& other);
	PartialFunctionCollection& operator=(PartialFunctionCollection&& other) noexcept;
	~PartialFunctionCollection();

	const PartialFunction* operator[](size_t index)const;
	PartialFunction* operator[](size_t index);

	size_t getSize()const;

	void addPartialFunction(UniquePointer<PartialFunction>& newFunc);
	void addPartialFunction(const SharedPtr<PartialFunction>& newFunc);
	void addPartialFunction(PartialFunction* newFunc);
};