#pragma once
#include"Student.h"

class StudentArray {

	Student** data;
	size_t count;
	size_t capacity;

	void resize(size_t newCap);
	void copyFrom(const StudentArray& other);
	void moveFrom(StudentArray&& other);
	void free();
	int getFirstFreeIndex() const;
	int getLastFreeIndex() const;
public:
	StudentArray();
	StudentArray(const StudentArray& other);
	StudentArray&operator=(const StudentArray& other);
	StudentArray(StudentArray&& other)noexcept;
	StudentArray&operator=(StudentArray&& other)noexcept;
	~StudentArray();

	void pushBack(const Student& st);
	void pushBack(Student&& st);

	void pushFront(const Student& st);
	void pushFront(Student&& st);

	const Student& getBack() const;
	Student& getBack() ;

	const Student& getFront() const;
	Student& getFront();

	size_t getCount() const;

	const Student& at(size_t index) const;
	Student& at(size_t index);

	friend std::ostream& operator<<(std::ostream& os, const StudentArray& st);
};

