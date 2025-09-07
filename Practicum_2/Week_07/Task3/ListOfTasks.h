#pragma once
#include"Task.h"

class ListOfTasks {

	Task* _tasks = nullptr;
	size_t _countTasks = 0;
	size_t _capacity = 1;

	void copyFrom(const ListOfTasks& other);
	void free();
	void resize(size_t capacity);
	int findTask(const char* name);

public:

	ListOfTasks() = default;
	ListOfTasks(const Task* tasks, size_t countTasks);
	ListOfTasks(const ListOfTasks& other);
	ListOfTasks&operator=(const ListOfTasks& other);
	~ListOfTasks();

	size_t getCountTasks() const;
	const Task* getTasks() const;

	void addTask(const Task& task);
	void removeTask(const Task& task);
	void changeDescription(const char* name, const char* description);
	void printTasks() const;
		 

};