#include<iostream>

using DoubleFunc = double(*)(double);

double minusOne(double x){
	return x - 1;
}

double addOne(double x) {
	return x + 1;
}

double maxNum(double(*f)(double), double(*g)(double), double x) {
	
	double num1 = f(x);
	double num2 = g(x);
	
	return num1 >= num2 ? num1 : num2;
}

int main() {


	 std::cout << maxNum(addOne,minusOne ,2);

	return 0;
}