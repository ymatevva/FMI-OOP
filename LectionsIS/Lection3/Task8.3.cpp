#include<iostream>

template<typename T>
bool isInIt(const T* arr, size_t sizeArr, T elem) {

	if (!arr)
		return false;

	for (size_t i = 0; i < sizeArr; i++){
		if (arr[i] == elem)
			return true;
	}
	return false;
}

template<typename T>
void input(T* arr, size_t arrSize) {
	
	if (!arr)
		return;
	
	for (size_t i = 0; i < arrSize; i++){
		std::cin >> arr[i];
	}
}

int main() {

	constexpr int SIZE = 3;

	{
		double arr[SIZE]{};
		input(arr, SIZE);
		std::cout << isInIt(arr, SIZE,3.4);
	}


	{
		int arr[SIZE]{};
		input(arr, SIZE);
		std::cout << isInIt(arr, SIZE,9);
	}
}