#include<iostream>
#include<cmath>

struct Point
{
    int x;
    int y;
};

struct Triangle
{
    Point A;
    Point B;
    Point C;
};

int area(const Triangle &T)
{
    return  abs((T.A.x - T.C.x)*(T.B.y - T.C.y) - (T.B.y - T.C.y)*(T.A.x - T.C.x))/2;
}

int main() {

    int n;
    std::cin >> n;

    Triangle *triangles = new Triangle[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> triangles[i].A.x >> triangles[i].A.y >> triangles[i].B.x >> triangles[i].B.y >> triangles[i].C.x>> triangles[i].C.y;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (area(triangles[j]) < area(triangles[i]))
            {
                std::swap(triangles[i], triangles[j]);
            }
        }
    }


    std::cout << '\n';
    for (int i = 0; i < n; ++i)
    {
        std::cout << triangles[i].A.x << ' ' << triangles[i].A.y << ' ' << triangles[i].B.x << ' ' << triangles[i].B.y
                  << ' ' << triangles[i].C.x << ' ' << triangles[i].C.y << '\n';
    }

    delete[] triangles;

    return 0;
}