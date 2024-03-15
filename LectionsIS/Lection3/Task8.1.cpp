#include<iostream>


template<typename T>

void input(T* arr, size_t sizeArr) {

	if (!arr)
		return;

	for (size_t i = 0; i < sizeArr; i++){
		std::cin >> arr[i];
	}
}

int main() {

	constexpr size_t size = 5;
	{
		int arr[size]{};

		input(arr, size);
	}

	{
		double arr[size]{};

		input(arr, size);
	}

	return 0;
}
