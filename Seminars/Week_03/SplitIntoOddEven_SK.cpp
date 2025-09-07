#include<iostream>
#include<fstream>

size_t getFileSize(std::ifstream& ifs) {

	unsigned currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	size_t sizeFile = ifs.tellg();
	ifs.seekg(currPos);

	return sizeFile;
}

void countOddAndEven(const int* arr, size_t sizeArr, unsigned& evenCount, unsigned& oddCount) {

	if (!arr)
		return;

	for (size_t i = 0; i < sizeArr; i++) {
		if (arr[i] % 2 == 0)
			evenCount++;
		else
			oddCount++;
	}
}

void fillEven(const int* arr, size_t arrSize, int* evenArr, size_t evenCount) {

	if (!arr)
		return;

	size_t ind = 0;
	for (size_t i = 0; i < arrSize; i++) {

		if (arr[i] % 2 == 0)
			evenArr[ind++] = arr[i];

		if (ind >= evenCount)
			return;
	}
}

void fillOdd(const int* arr, size_t arrSize, int* oddArr, size_t oddCount) {

	if (!arr)
		return;

	size_t ind = 0;
	for (size_t i = 0; i < arrSize; i++) {

		if (arr[i] % 2 != 0)
			oddArr[ind++] = arr[i];

		if (ind >= oddCount)
			return;
	}
}

void writeArrToFile(const char* toFile, const int* arr, size_t arrSize) {
	if (!toFile || !arr)
		return;

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;

	ofs.write((const char*)arr, sizeof(int) * arrSize);///
}


void split(const char* fromFile, const char* evenFile, const char* oddFile) {

	if (!fromFile || !evenFile || !oddFile)
		return;


	std::ifstream fromPath(fromFile, std::ios::binary);
	if (!fromPath.is_open())
		return;

	size_t arrNumSize = getFileSize(fromPath) / sizeof(int);
	int* arrNumbers = new int[arrNumSize];
	fromPath.read((char*)arrNumbers, sizeof(int) * arrNumSize);

	unsigned evenCount = 0;
	unsigned oddCount = 0;
	countOddAndEven(arrNumbers, arrNumSize, evenCount, oddCount);

	int* evenArr = new int[evenCount];
	int* oddArr = new int[oddCount];

	fillEven(arrNumbers, arrNumSize, evenArr, evenCount);
	fillOdd(arrNumbers, arrNumSize, oddArr, oddCount);

	writeArrToFile(evenFile, evenArr, evenCount);
	writeArrToFile(oddFile, oddArr, oddCount);

	delete[] evenArr;
	delete[] oddArr;
}

int main() {

	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	writeArrToFile("NumsToFile.dat", arr, 10);

	split("NumsToFile.dat", "EvenFile.dat", "OddFile.dat");


	return 0;
}