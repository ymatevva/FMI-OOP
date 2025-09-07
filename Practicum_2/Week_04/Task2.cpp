#include<iostream>
#include<fstream>


int* arrFromFile(std::ifstream& ifs,size_t& sizeArr) {

	sizeArr = 0;
	ifs.read((char*)&sizeArr, sizeof(sizeArr));

	int* newArr = new int[sizeArr];
	for (size_t i = 0; i < sizeArr; i++){
		ifs.read((char*)&newArr[i], sizeof(newArr[i]));
	}
	return newArr;
}
int* readFile(const char* fromFile,size_t& sizeArr) {
	
	if (!fromFile)
		return nullptr;

	std::ifstream ifs(fromFile, std::ios::binary);

	int* arr = arrFromFile(ifs,sizeArr);

	ifs.close();
	return arr;
}
void printArr(const int* arr, size_t sizeArr) {
	if (!arr)
		return;
	for (size_t i = 0; i < sizeArr; i++)
	{
		std::cout << arr[i] << " ";
	}
}
int main() {

	size_t sizeArr = 0;
	int* arrNumbers = readFile("numbers.dat",sizeArr);
	printArr(arrNumbers, sizeArr);

	return 0;
}