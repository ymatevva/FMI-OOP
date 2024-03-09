#include<iostream>
#include<fstream>

constexpr int MAX_SIZE = 256;

void encryptText(char* str, int shiftKey) {

	if (!str)
		return;

	while (*str) {

		*str = *str + shiftKey;

		str++;
	}

}

void decryptText(char* str, int shiftKey) {

	if (!str)
		return;

	while (*str) {

		*str = *str - shiftKey;

		str++;
	}

}


void encryptText(char* source, int shiftKey, const char* encryptedResult) {

	if (!source)
		return;


	std::ofstream ofs(encryptedResult);

	if (!ofs.is_open())
		return;

	encryptText(source, shiftKey);
	ofs << source;
}

void decryptText(const char* encryptedText, int shiftKey, const char* decryptedResult) {

	if (!encryptedText || !decryptedResult)
		return;

	std::ifstream ifs(encryptedText);

	if (!ifs.is_open())
		return;

	std::ofstream ofs(decryptedResult);

	if (!ofs.is_open())
		return;

	while (!ifs.eof()) {

		char buff[1024];
		ifs.getline(buff, 1024);
		decryptText(buff, shiftKey);
		ofs << buff;
	}
}





int main() {

	std::ofstream ofs("encrypted.txt");

	int shifferNum;
	std::cin >> shifferNum;

	std::cin.ignore();

	char input[MAX_SIZE];
	std::cin.getline(input, MAX_SIZE);


	encryptText(input, shifferNum, "encrypted.txt");
	decryptText("encrypted.txt", shifferNum, "decrypted.txt");

	return 0;
}