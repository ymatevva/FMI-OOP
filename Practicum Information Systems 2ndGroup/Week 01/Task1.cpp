#include<iostream>


void resize(int*& arr, size_t& capacity, size_t size) {

	capacity *= 2;
	int* newArr = new int[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;
}

void pushFront(int*& arr, size_t& capacity, size_t size, int num) {

	if (size == capacity) {
		resize(arr, capacity, size);
	}

	for (size_t i = 0; i < size; i++)
	{
		arr[size - i] = arr[size - (i + 1)];
	}

	arr[0] = num;
	size++;
}
int main() {

	size_t capacity = 5, size = 0;
	int* arr = new int[capacity];

	for (int i = 0; i < 10; i++)
	{
		pushFront(arr, capacity, size, i);

		std::cout << "CAP = " << capacity << "\n";
		std::cout << "SIZE= " << size << "\n";
		for (int j = 0; j < size; j++)
		{
			std::cout << arr[j] << ' ';
		}
		std::cout << "\n";
	}

}
