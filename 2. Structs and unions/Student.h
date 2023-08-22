#ifndef STUDENT
#define STUDENT

#include<iostream>
#include<exception>
#include <cstring>
#include<iomanip>

enum Course
{
    FIRST = 1,
    SECOND,
    THIRD,
    FOURTH
};


struct Student
{
    char *FN;
    Course course_;
    float averageGrade;
};

const int FN_DIGITS = 5;

bool isFNBValid(const char *c)

{
    if (strlen(c)!=FN_DIGITS)
    {
        return false;
    }
    for (int i = 0; i < FN_DIGITS; ++i)
    {
        if (!isdigit(c[i]))
        {
            return false;
        }
    }
    return true;
}

Student isitStudent(const char *FN, int course, float averageGrade)
{

    Course c;
    switch(course) {
        case 1:
            c = FIRST;
            break;

        case 2:
            c = SECOND;
            break;

        case 3:
            c = THIRD;
            break;

        case 4:
            c = FOURTH;
            break;


        default:
        {
            throw std::invalid_argument("A student can only be course 1-4.\n");
        }

    }
    if (!isFNBValid(FN))
    {
        throw std :: invalid_argument("A faculty number must contain 5 digits.\n");
    }

    char *studentFN = new char[strlen(FN) + 1];
    strcpy(studentFN,FN);
    return {studentFN, c, averageGrade};

}

void deleteStudent(const Student &s)
{
    delete s.FN;
}

void printStudent(const Student &s)
{
    std :: cout << s.FN << " " << s.course_ << " " << std :: setprecision(2) << std :: fixed << s.averageGrade << '\n';
}

#endif