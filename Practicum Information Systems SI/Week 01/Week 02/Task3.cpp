#include<iostream>
#include<fstream>

void printItself(const char* fileName) {

	if (!fileName)
		return;

	std::ifstream ifs(fileName);

	if (!ifs.is_open())
		return;

	while (!ifs.eof()){
		char buff[1024];
		ifs.getline(buff, 1024);
		std::cout << buff << std::endl;
	}
}

int main() {

	printItself("3rdTask.cpp");

	return 0;
}