#include <iostream>


struct ComplexNum
{
    float realPart;
    float imaginaryPart;
};

void print (const ComplexNum & c)
{
    std :: cout << c.realPart << " + " << (c.imaginaryPart < 0 ? "(" : "") << c.imaginaryPart<<(c.imaginaryPart < 0 ? ")" : "") <<"i"<< std :: endl;
}


ComplexNum sumTwoComplexNums(const  ComplexNum &first, const ComplexNum & second )
{
    return {first.realPart + second.realPart, first.imaginaryPart + second.imaginaryPart};
}


int main()
{

  ComplexNum a{5, -3.14};

  print (a);

  ComplexNum b {10, 4.15};

  print (b);
  print(sumTwoComplexNums(a,b));

    return 0;
}