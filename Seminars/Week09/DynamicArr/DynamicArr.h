#pragma once

struct A {
	int x = 1;
	int y = 2;
};

class DynamicArr {

	A* data;
	size_t size;
	size_t cap;

	void copyFrom(const DynamicArr& other);
	void moveFrom( DynamicArr&& other);
	void free();
	void resize(size_t newCap);

public:
	DynamicArr();
	DynamicArr(size_t capacity);
	DynamicArr(const DynamicArr& other);
	DynamicArr(DynamicArr&& other);
	DynamicArr& operator=(const DynamicArr& other);
	DynamicArr& operator=(DynamicArr&& other);
	~DynamicArr();

	void putAtIndex(const A& element, size_t index);
	void putAtIndex(A&& element, size_t index);

	void pushBack(const A&element);
	void pushBack(A&& element);

	void popBack();

	A& operator[](size_t index);
	const A& operator[](size_t index) const;

	size_t getSize() const;
	bool isEmpty() const;
};