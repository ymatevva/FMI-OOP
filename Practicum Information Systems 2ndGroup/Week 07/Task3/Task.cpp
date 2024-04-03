#include "Task.h"
#include<cstring>
#include<iostream>
#pragma warning(disable:4996)


void Task::copyFrom(const Task& other)
{
	_name = new char[strlen(other._name) + 1];
	strcpy(_name, other._name);

	_description = new char[strlen(other._description) + 1];
	strcpy(_description, other._description);

	_status = other._status;
}


void Task::free()
{
	delete[] _name;
	delete[] _description;
}

Task::Task(const char* name, const char* description, Status status)
{
	setName(name);
	setDescription(description);
	setStatus(status);
}

Task::Task(const Task& other)
{
	copyFrom(other);
}

Task& Task::operator=(const Task& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Task::~Task()
{
	free();
}

void Task::setName(const char* name)
{
	if (!name || _name == name)
		return;
	
	delete[]_name;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
}

void Task::setDescription(const char* description)
{
	if (!description || _description == description)
		return;
	delete[] _description;
	_description = new char[strlen(description) + 1];
	strcpy(_description, description);
}

void Task::setStatus(Status status)
{
	_status = status;
}

const char* Task::getName() const
{
	return _name;
}

const char* Task::getDescription() const
{
	return _description;
}

Status Task::getStatus() const
{
	return _status;
}

void Task::printStatus(Status status) const {
	if (status == Status::Incompleted)
		std::cout << "Incompleted" << " ";
	else if (status == Status::Completed)
		std::cout << "Completed" << " ";
	else if (status == Status::InProgress)
		std::cout << "In progress" << " ";
	else
		std::cout << "Undefined status" << " ";
}
void Task::printTask() const
{
	std::cout << "Name of task: " << _name << " Status: ";
	printStatus(_status);
	std::cout << " Description of task: " << _description << std::endl;
}

