#pragma once


enum class Status {
	Incompleted,
	Completed,
	InProgress
};

class Task {

	char* _name = nullptr;
	char* _description = nullptr;
	Status _status;
	
	void copyFrom(const Task& other);
	void free();

public:

	Task() = default;
	Task(const char* name, const char* description, Status status);
	Task(const Task& other);
	Task&operator=(const Task& other);
	~Task();

	void setName(const char* name);
	void setDescription(const char* description);
	void setStatus(Status status);

	const char* getName()const;
	const char* getDescription()const;
	Status getStatus() const;

	void printStatus(Status status)const;
	void printTask() const;
	void changeStatus(Status status);

};