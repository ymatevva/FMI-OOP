#include<iostream>

using DoubleFunc = double(*)(double);
double minusOne(double x) {
	return x - 1;
}

double addOne(double x) {
	return x + 1;
}

double multByThree(double x) {
	return x * 3;
}

double divByThree(double x) {
	return x / 3;
}

double minusFour(double x) {
	return x - 4;
}


double maxArray(DoubleFunc* arr, int n, double x) {
	if (!arr)
		return -1;


	double maxNum = INT_MIN;
	for (size_t i = 0; i < n; i++)
	{
		double curr = arr[i](x);
		if (curr > maxNum) {
			maxNum = curr;
		}
	}
	return maxNum;

}

int main() {

	constexpr size_t SIZE = 5;
	DoubleFunc functions[SIZE] = { addOne, minusOne, multByThree, minusFour, divByThree };

	std::cout << maxArray(functions, SIZE, 5);

	return 0;
}