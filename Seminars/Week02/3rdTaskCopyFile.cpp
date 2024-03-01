#include<iostream>
#include<fstream>

void copyFile(const char* dest, const char* source)
{
	std::ofstream outFile(dest);
	std::ifstream inFile(source);


	if (!inFile.is_open())
		return;

	if (!outFile.is_open())
		return;

	while (true)
	{
		char currSymbol = inFile. get();

		if (inFile.eof())
			break;

		outFile.put(currSymbol);
	}
}

int main()
{

	copyFile("file.txt", "result.txt");

	return 0;
}