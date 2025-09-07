#include "ListOfTasks.h"
#include<cstring>
#include<iostream>

#pragma warning(disable:4996)
void ListOfTasks::copyFrom(const ListOfTasks& other)
{
	_tasks = new Task[other._countTasks];
	for (size_t i = 0; i < other._countTasks; i++)
	{
		_tasks[i] = other._tasks[i];
	}
	_countTasks = other._countTasks;
	_capacity = other._capacity;
}


void ListOfTasks::free()
{
	delete[] _tasks;
}

void ListOfTasks::resize(size_t newCapacity)
{
	Task* temp = new Task[newCapacity];
	for (size_t i = 0; i < _countTasks; i++)
	{
		temp[i] = _tasks[i];
	}

	delete[]_tasks;
	_tasks = temp;
	_capacity = newCapacity;
}

int ListOfTasks::findTask(const char* name)
{
	if (!name)
		return -1;
	for (size_t i = 0; i < _countTasks; i++)
	{
		if(strcmp(name,_tasks[i].getName())==0)
			return i;
	}
	return -1;
}

ListOfTasks::ListOfTasks(const Task* tasks, size_t countTasks)
{
	if (!tasks)
		return;
	_tasks = new Task[countTasks];
	for (size_t i = 0; i < countTasks; i++)
	{
		_tasks[i] = tasks[i];
	}
	_countTasks = countTasks;
	_capacity = _countTasks * 2;
}

ListOfTasks::ListOfTasks(const ListOfTasks& other)
{
	copyFrom(other);
}

ListOfTasks& ListOfTasks::operator=(const ListOfTasks& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ListOfTasks::~ListOfTasks()
{
	delete[] _tasks;
}

size_t ListOfTasks::getCountTasks() const
{
	return _countTasks;
}

const Task* ListOfTasks::getTasks() const
{
	return _tasks;
}

void ListOfTasks::addTask(const Task& task)
{
	if (_countTasks + 1 > _capacity)
		resize(_capacity * 2);

	_tasks[_countTasks++] = task;
}

void ListOfTasks::removeTask(const Task& task)
{
	int indOfTask = findTask(task.getName());
	if (indOfTask == -1)
		return;

	for (size_t i = indOfTask; i < _countTasks - 1; i++)
	{
		_tasks[i] = _tasks[i + 1];
	}
	_countTasks--;
}

void ListOfTasks::changeDescription(const char* name, const char* description){
	int indOfTask = findTask(name);
	if (indOfTask == -1)
		return;
	
	_tasks[indOfTask].setDescription(description);
}

void ListOfTasks::printTasks() const
{
	std::cout << "List of tasks: " << std::endl;
	for (size_t i = 0; i < _countTasks; i++)
	{
		_tasks[i].printTask();
	}
}

int main() {
 
	 Task* tasks = new Task[3];
	 tasks[0] = Task("IsPalindrome", "Finding if a number is a palindrome",Status::Incompleted);
	 tasks[1] = Task("Reverse", "Reversing a number",Status::Completed);
	 tasks[2] = Task("IsPrime", "Finding if a number is prime",Status::InProgress);

	
	ListOfTasks taskList = ListOfTasks(tasks,3);

	taskList.printTasks();

	taskList.removeTask(tasks[2]);
	
	std::cout << "\nAfter removing task 2:\n";
	taskList.printTasks();

	taskList.changeDescription("Task 1", "Updated Description for Task 1");

	
	std::cout << "\nAfter changing description of task 1:\n";
	taskList.printTasks();

	Task newTask = Task("OOP task", "Hard one", Status::Incompleted);
	taskList.addTask(newTask);

	
	ListOfTasks copiedList = taskList;

	
	std::cout << "\nCopied List:\n";
	copiedList.printTasks();

}