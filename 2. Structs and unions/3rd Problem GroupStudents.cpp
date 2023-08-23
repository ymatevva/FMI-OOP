#ifndef GROUP
#define GROUP

#include "Student.h"


struct Group
{
    int numberOfStudentsInGroup;
    Student * students;
    float averageScore;

};

Group initGroupFromStdIn()
{
     Group g;
     std :: cin >> g.numberOfStudentsInGroup;
     g.students = new student[g.numberOfStudentsInGroup];
     char fnBuffer[FN_DIGITS + 1];

    for (int i = 0; i < g.numberOfStudentsInGroup; ++i)
    {
        std::cout << "Enter Fn: \n";
        std :: cin.ignore();
        std :: cin.getline(fnBuffer,FN_DIGITS+1);
        std::cout << "Enter course: \n";
        int c;
        std :: cin >> c;
        std ::cout << "Enter average grade: \n";
        float grade;
        std :: cin >> grade;
        g.averageScore += grade;
        g.students[i] = initStudents(fnBuffer,c,grade);
    }
    g.averageScore /= g.numberOfStudentsInGroup;

    return g;

}

void deleteGroup(const Group &g)
{

    for (int i = 0; i < g.numberOfStudentsInGroup; ++i) {
        deleteStudent(g.students[i]);
    }

    delete[] g.students;
}

void scholarship(const Group &g, float grade)
{
    for (int i = 0; i < g.numberOfStudentsInGroup; ++i)
    {
        if (g.students[i].averageScore >= grade)
        {
            printStudents(g.students[i]);
        }
    }
}

#endif