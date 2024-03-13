#include<iostream>
#include<fstream>


int* getNumbers(size_t sizeArr) {

	int* arr = new int[sizeArr];
	for (size_t i = 0; i < sizeArr; i++){
		std::cin >> arr[i];
	}
	return arr;
}

void writeArrToFile(std::ofstream& ofs,const int* arr, size_t sizeArr) {

	if (!arr)
		return;

	ofs.write((const char*)&sizeArr, sizeof(sizeArr));

	for (size_t i = 0; i < sizeArr; i++) {
		ofs.write((const char*)&arr[i], sizeof(arr[i]));
	}

}

void writeToFile(const char* toFile) {
	
	if (!toFile)
		return;

	size_t sizeArr = 0;
	std::cin >> sizeArr;

	int* arr = getNumbers(sizeArr);

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
	{
		std::cout << "error";
		return;
	}


	writeArrToFile(ofs, arr, sizeArr);
	delete[] arr;
}



int main() {

	writeToFile("output.dat");
	return 0;
}