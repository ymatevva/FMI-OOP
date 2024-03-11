#include<iostream>
#include<fstream>


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

int main() {

	copyInformation("source.txt", "dest.txt");

	return 0;
}