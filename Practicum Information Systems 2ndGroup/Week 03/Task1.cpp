#include<iostream>
#include<fstream>


unsigned int getSymbolCount(std::ifstream& ifs, char ch) {

	unsigned int count = 0;

	while (!ifs.eof()) {

		char currCh = ifs.get();
		if (currCh == ch)
			count++;
	}
	return count;
}

unsigned int getNewLinesCount(const char* fileName) {
	
	if (!fileName)
		return 0;

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
		return 0;

	return getSymbolCount(ifs,'\n') + 1;
}
int main() {

	std::cout << getNewLinesCount("Test.txt");

	return 0;
}