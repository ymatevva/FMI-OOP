#include<iostream>
#include<fstream>

namespace HelperFunctions {

	bool isLower(char ch) {
		return ch >= 'a' && ch <= 'z';
	}

	bool isUpper(char ch) {
		return ch >= 'A' && ch <= 'Z';
	}

	char toLower(char ch) {
		return ch - 'A' + 'a';
	}

	char toUpper(char ch) {
		return ch - 'a' + 'A';
	}
}

void transformSentence(char* str, bool toCaps) {
	
	if (!str)
		return;

	while (*str) {

		if (toCaps)
		{
			if(HelperFunctions::isLower(*str))
			*str = HelperFunctions::toUpper(*str);}

		else 
			if(HelperFunctions::isUpper(*str))
			*str = HelperFunctions::toLower(*str);

		str++;
	}
}


void copyInformation(const char* sourceFile, const char* outputFile) {

	if (!sourceFile || !outputFile)
		return;

	std::ifstream ifs(sourceFile);
	if (!ifs.is_open())
		return;

	std::ofstream ofs(outputFile);
	if (!ofs.is_open())
		return;

	while (!ifs.eof()) {
		char buff[1024];
		ifs.getline(buff, 1024);
		ofs << buff << std::endl;
	}
}


void convertLettersCaseInFile(const char* fileName, bool toCaps) {

	if (!fileName)
		return;

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
		return;


	std::ofstream ofs("temp.txt");

	if (!ofs.is_open()){
		std::cout << "The temp file was not opened" << std::endl;
		return;
	}


	char buffer[1024];

	while (ifs.getline(buffer, 1024)) {
		transformSentence(buffer, toCaps);
		ofs << buffer << std::endl;
	}

	copyInformation("temp.txt", fileName);
}

int main() {

	convertLettersCaseInFile("Test.txt", true);

	return 0;
}
