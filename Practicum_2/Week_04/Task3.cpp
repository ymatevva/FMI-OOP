#include<iostream>
#include<fstream>

unsigned getFileSize(std::ifstream& ifs) {

	unsigned currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	unsigned size = ifs.tellg();
	ifs.seekg(currPos);

	return size;
}

int* readNumbersFromFile(std::ifstream& ifs, size_t fileSize) {

	int* arr = new int[fileSize];
	for (size_t i = 0; i < fileSize; i++){
		ifs.read((char*)&arr[i], sizeof(arr[i]));
	}
	return arr;
}

void printArr(const int* arr, size_t sizeArr) {
	for (size_t i = 0; i < sizeArr; i++){
		std::cout << arr[i] << " ";
	}
}
void readFromFile(const char* fromFile) {

	if (!fromFile)
		return;

	std::ifstream ifs(fromFile);
	if (!ifs.is_open())
		return;

	size_t sizeFile = getFileSize(ifs) / sizeof(int);

	int* arr = readNumbersFromFile(ifs, sizeFile);
	printArr(arr, sizeFile);

	delete[] arr;
}

int main() {

	readFromFile("numsToFile.dat");

	return 0;
}