#include "Studenth.h"

Student::Student(const char* name, int age, size_t fn):Person(name,age)
{

    setFn(fn);
}

size_t Student::getFn() const
{
    return _fn;
}

void Student::setFn(size_t fn)
{
    if (fn < 100) {
        fn = 100;
    }
    _fn = fn;
}

void Student::print() const
{
    Person::print();
    std::cout << " Fn: " << _fn << std::endl;
}
