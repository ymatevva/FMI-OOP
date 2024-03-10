#include<iostream>
#include<fstream>


void getInput(std::ifstream& ifs, int* arr) {
	
	if (!arr)
		return;

	int index = 0;
	while (!ifs.eof()) {
		ifs >> arr[index++];
	}
}

int mostCommonNum(std::ifstream& ifs) {

	size_t size = 0;
	ifs >> size;

	int arr[64];

	getInput(ifs, arr);

	int mostOccurences = 0;
	int mostOccured = 0;

	for (size_t i = 0; i < size; i++){
		
		int currOcc = 0;
		for (size_t j = i + 1; j < size; j++) {
			if (arr[i] == arr[j])
				currOcc++;
		}

		if (currOcc > mostOccurences) {
			mostOccurences = currOcc;
			mostOccured = arr[i];
		}
	}
	return mostOccured;
}


 int getMostCommon(const char* fileName) {

	 if (!fileName)
		 return -1;

	 std::ifstream ifs(fileName);
	 if(!ifs.is_open())
		 return -1;

	 return mostCommonNum(ifs);
	
}
int main() {

	std::cout << getMostCommon("Test.txt");


	return 0;
}