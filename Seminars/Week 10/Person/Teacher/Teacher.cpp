#include "Teacher.h"
#pragma warning (disable:4996)


static char** copyArrayOfString(const char* const* strings, size_t size)
{
	char** res = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		size_t len = strlen(strings[i]);
		res[i] = new char[len + 1];  
		strcpy(res[i], strings[i]); 
	}

	return res;
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount) : Person(name, age)
{
	_studentsSubjects = copyArrayOfString(subjects, subjectsCount);
	_studentsCount = subjectsCount;
}

void Teacher::moveFrom(Teacher&& other) {
	_studentsCount = other._studentsCount;
	other._studentsCount = 0;

	_studentsSubjects = other._studentsSubjects;
	other._studentsSubjects = nullptr;
}
void Teacher::free()
{
	for (size_t i = 0; i < _studentsCount; i++)
		delete[] _studentsSubjects[i];
	delete[] _studentsSubjects;
}

void Teacher::copyFrom(const Teacher& other)
{
	_studentsSubjects = copyArrayOfString(other._studentsSubjects, other._studentsCount);
	_studentsCount = other._studentsCount;
}

Teacher::Teacher(const Teacher& other):Person(other)
{
	copyFrom(other);
}

Teacher::Teacher(Teacher&& other)noexcept : Person(std::move(other))
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other) {
		Person::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
	if (this != &other) {
		Person::operator=(std::move(other));
		free();
	    moveFrom(std::move(other));
	}
	return *this;
}

Teacher::~Teacher()
{
	free();
}

void Teacher::print() const
{
	Person::print();
	std::cout << "Students count: " << _studentsCount << std::endl;
	for (size_t i = 0; i < _studentsCount; i++){
	
		if (_studentsSubjects[i] != nullptr) {
			std::cout << _studentsSubjects[i] << " ";
		}
	}
	std::cout << std::endl;
}
int main() {
	// Create a Teacher object
	const char* subjects[] = { "Math", "Science", "History" };
	size_t subjectsCount = sizeof(subjects) / sizeof(subjects[0]);
	Teacher teacher("John Doe", 35, subjects, subjectsCount);

	// Print the teacher's information
	std::cout << "Teacher Information:" << std::endl;
	teacher.print();

	// Test copy constructor
	Teacher teacherCopy(teacher);
	std::cout << "Teacher Copy Information:" << std::endl;
	teacherCopy.print();

	// Test move constructor
	Teacher teacherMoved(std::move(teacher));
	std::cout << "Teacher Moved Information:" << std::endl;
	teacherMoved.print();

	

	return 0;
}
