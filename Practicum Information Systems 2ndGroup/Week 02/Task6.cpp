#include<iostream>


union Number {
	unsigned long num;
	char arr[sizeof(int)];
};

int main() {

	Number number;
	std::cout << "Original number: " << number.num << std::endl;
	int result = 0;

	for (size_t i = 0; i < sizeof(int); i++){
		result |= ((0xff & number.arr[i])) << (i * 8);
	}

	std::cout << "Number in bytes: " << result << std::endl;

	return 0;
}