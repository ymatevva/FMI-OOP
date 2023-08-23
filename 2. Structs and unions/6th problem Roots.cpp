#include<iostream>
#include<cmath>

struct Quadratic
{
    double a,b,c, discriminant, x1, x2;
};

void findRoots(Quadratic &q)
{

   q.discriminant = q.b*q.b - 4 * q.a * q.c;

    if (q.a == 0)
    {
        return;
    }

    if (q.discriminant > 0)
    {
        q.x1 = (-q.b + sqrt(q.discriminant))/(2*q.a);
        q.x2 = (-q.b - sqrt( q.discriminant))/(2*q.a);
        return ;
    }

    if (q.discriminant == 0)

    {
        q.x1 = -q.b / (2*q.a);
        q.x2 = -q.b / (2*q.a);
    }
};

int main()
{

    Quadratic equation;

    equation.a;
    equation.b;
    equation.c;
    std :: cin >> equation.a >> equation.b >> equation.c;

    findRoots(equation);

    if (equation.discriminant > 0)
    {
        std :: cout << "Two real roots: " << std :: endl;
        std :: cout << "X1: " << equation.x1 << std :: endl;
        std :: cout << "X2: " << equation.x2 << std :: endl;
    }

    else if (equation.discriminant == 0)
    {
        std :: cout << "There is only one root: " << std :: endl;
        std :: cout << "X1 = X2 = " << equation.x1 << std :: endl;
    }

    else
    {
        std :: cout << "There is no real roots" << std :: endl;
    }


    return 0;
}