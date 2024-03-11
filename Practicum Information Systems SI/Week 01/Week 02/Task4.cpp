#include<iostream>
#include<fstream>
#pragma warning (disable : 4996)

void printDiff(const char* firstFile, const char* secondFile) {

	if (!firstFile || !secondFile)
		return;

	std::ifstream firstPath(firstFile);
	if (!firstPath.is_open())
		return;

	std::ifstream secPath(secondFile);
	if (!secPath.is_open())
		return;

	char buff1[1024];
	char buff2[1024];

	while (!firstPath.eof() && !secPath.eof()) {

		
		firstPath.getline(buff1,1024);

		
		secPath.getline(buff2, 1024);

		if (strcmp(buff1, buff2) != 0){
			std::cout << "First file: " << buff1 << std::endl;
			std::cout << "Second file: " << buff2 << std::endl;
			return;
		}

	}

    bool firstFinished = firstPath.eof();
	bool secondFinished = secPath.eof();

	if (firstFinished && !secondFinished) {
		strcpy(buff1, "EOF");
		secPath.getline(buff2, 1024);
	}

	else if (!firstFinished && secondFinished) {
		strcpy(buff2, "EOF");
		firstPath.getline(buff1, 1024);
	}
	
	else if (firstFinished && secondFinished){
		std::cout << "No diff" << std::endl;
		return;
	}

	std::cout << "First file: " << buff1 << std::endl;
	std::cout << "Second file: " << buff2 << std::endl;
}

int main() {

	printDiff("First.txt", "Second.txt");
	return 0;
}