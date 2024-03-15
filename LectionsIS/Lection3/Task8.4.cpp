#include<iostream>

using DoubleFunc = double(*)(double);

double addTwo(double x){
	return x + 2;
}

double addOne(double x) {
	return x + 1;
}

double multByThree(double x) {
	return x * 3;
}

double divByThree(double x) {
	return x/3;
}

double minusFour(double x) {
	return x - 4;
}

int getMaxValueIndex(DoubleFunc* arr, size_t size, double num){
	
	if (!arr){
		return -1;
	}

	double maxEl = INT_MIN;
	int maxIndex = -1;

	for (size_t i = 0; i < size; i++){
		double curr = arr[i](num);
		if (curr > maxEl){
			maxEl = curr;
			maxIndex = i;
		}
	}
	return maxIndex;
}


int main() {

	constexpr size_t SIZE = 5;
	DoubleFunc functions[SIZE] = { addTwo,addOne,multByThree, divByThree, minusFour};

	double x;
	std::cin >> x;

	std::cout << getMaxValueIndex(functions, SIZE, x);

	return 0;
}