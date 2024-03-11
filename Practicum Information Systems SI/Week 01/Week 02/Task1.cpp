#include<iostream>
#include<fstream>

void sumProductToFile(const char* fileName, int num1, int num2) {
	
	if (!fileName)
		return;

	std::ofstream ofs(fileName);
	if (!ofs.is_open())
		return;

	int sum = num1 + num2;
	int diff = num1 - num2;

	ofs << sum << " " <<  diff << std::endl;
}

 void printOriginal(const char* fileName) {

	 if (!fileName)
		 return;

	 std::ifstream ifs(fileName);
	 if (!ifs.is_open())
		 return;

	
	 int sum = 0, diff = 0;

	 ifs >> sum >> diff;

	 int num1 = 0;
	 int num2 = 0;

	 num1 = (sum + diff) / 2;
	 num2 = (diff - sum) / (-2);

	 std::cout << num1 << " " << num2 << std::endl;
	 
 }
int main() {

	int num1 = 0, num2 = 0;
	std::cin >> num1 >> num2;

	sumProductToFile("SumPr.txt", num1, num2);
	printOriginal("SumPr.txt");

	return 0;
}
