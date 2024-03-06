#include<iostream>
#include<fstream>

namespace HelperFunctions {

	bool isUpper(char ch) {
		return ch >= 'A' && ch <= 'Z';
	}

	bool isLower(char ch) {
		return ch >= 'a' && ch <= 'z';
	}

	char turnToUpper(char ch) {
		return ch - 'a' + 'A';
	}

	bool isLetter(char ch) {
		return isUpper(ch) || isLower(ch);
	}

	bool isWhiteSpace(char ch) {
		return ch == ' ';
	}

	unsigned countSymbolsOnLine(std::ifstream& source) {

		unsigned int count = 0;

		while (true) {

			char ch = source.get();

			if (ch == '\n' || source.eof())
				break;

			count++;
		}

		return count;
	}

	void formatCode(char* str) {

		if (!str) 
			return;
		

		bool isFirst = true;
		while (*str) {

			if (HelperFunctions::isLetter(*str) && (isFirst || *(str - 1) == '-')) {
				*str = HelperFunctions::turnToUpper(*str);
				isFirst = false;
			}

			else if (HelperFunctions::isWhiteSpace(*str))
				*str = '-';

			str++;
		}

	}

}

void copyFile(const char* source, const char* dest) {

	
	if (!source || !dest)
		return;

	std::ifstream srcPath(source);

	if (!srcPath.is_open())
		return;

	std::ofstream destPath(dest);

	if (!destPath.is_open())
		return;

	while (!srcPath.eof()) {

		char buff[1024];
		srcPath.getline(buff, 1024);
		destPath << buff << std::endl;
	}
}

void formatCode(const char* sourceFile) {

	if (!sourceFile)
		return;

	const char* TEMP = "tempFile.txt";

	std::ifstream src(sourceFile);

	if (!src.is_open()) {
		return;
	}

	std::ofstream dest(TEMP);

	if (!dest.is_open()) {
		return;
	}

	while (!src.eof()) {

		int prevPos = src.tellg();
		size_t lineSize = HelperFunctions::countSymbolsOnLine(src);

		src.clear();
		src.seekg(prevPos);

		char* buff = new char[lineSize + 1];
		src.getline(buff, lineSize + 1);

		HelperFunctions::formatCode(buff);

		dest << buff << std::endl;

		delete[] buff;
	}

	dest.flush();
	copyFile(TEMP, sourceFile);

}

int main() {

	formatCode("Test.txt");

	return 0;
}