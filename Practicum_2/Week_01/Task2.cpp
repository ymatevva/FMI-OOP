#include<iostream>

void popFront(int*& arr, size_t& size) {

	for (size_t i = 0; i < size-1; i++){
		arr[i] = arr[i + 1];
	}
	
	size -= 1;
}

int main() {
	
	size_t length = 0;
	std::cin >> length;

	int* arr = new int[length];

	for (size_t i = 0; i < length; i++){
		std::cin >> arr[i];
	}

	popFront(arr, length);

	for (size_t i = 0; i < length; i++){
		std::cout << arr[i] << " ";
	}

	return 0;
}
