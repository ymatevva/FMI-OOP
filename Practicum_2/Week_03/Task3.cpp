#include<iostream>
#include<fstream>

constexpr int BUFF_SIZE = 1024;

unsigned int countWords(std::ifstream& ifs) {

	unsigned int count = 0;

	char buff[BUFF_SIZE];
	while (ifs >> buff) {
		count++;
	}

	return count;
}

unsigned getWordsCount(const char* fileName) {

	if (!fileName)
		return 0;

	std::ifstream ifs(fileName);

	if (!ifs.is_open()){
		std::cout << "The file was not opened." << std::endl;
		return 0;
	}

	return countWords(ifs);

}
int main() {

	std::cout << getWordsCount("Task3.cpp") << std::endl;

	return 0;
}