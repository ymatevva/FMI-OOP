#include<iostream>
#include<fstream>

void writeInFile(const char* file, int sum, int product){
	
	std::ofstream outFile(file);

	if (!outFile.is_open()) {
		std::cout << "Could not open file to write" << std::endl;
		return;
	}

	outFile << sum << " " << product;

	outFile.close();

}

int main() {

	int firstNum = 0, secondNum = 0, thirdNum = 0;
	std::cin >> firstNum >> secondNum >> thirdNum;

	int sum = firstNum + secondNum + thirdNum;
	int product = firstNum * secondNum * thirdNum;


	writeInFile("result.txt",sum, product);

	return 0;
}