#include<iostream>
#include<fstream>

void printMyFile(const char* file){
	
	std::ifstream inFile(file);
	
	if (!inFile.is_open())
		return;

	while (true) {
		
		char nextSymb = inFile.get();

		if (inFile.eof())
			break;

		std::cout << nextSymb;
	}
}

int main()
{
	printMyFile("1stTask.cpp");
}

