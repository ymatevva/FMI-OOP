#include<iostream>
#include <string>

struct Student
{
    std::string facNum;
    int course;
    double averageGrade;
};

void initStudent(Student * A)
{
    std :: cin >> A -> facNum;
    std :: cin >> A -> course;
    std :: cin >> A -> averageGrade;
}

void printStudent(const Student & A)
{
    std :: cout << A.facNum << " " << A.course  << " " << A.averageGrade << std :: endl;
}


int main()
{
    Student * A = new Student;

    initStudent(A);
    printStudent(*A);

    delete A;

    return 0;
}

