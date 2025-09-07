#include<iostream>
#include<fstream>

unsigned int countSymbol(std::ifstream& ifs, char symb)
{
	

	if(!ifs.is_open())
		return 0;

	unsigned int count = 0;

	while (true)
	{
		char ch = ifs.get();
		
		if (ifs.eof())
			break;

		if (ch == symb)
			count++;
	}

	return count;
}

unsigned int countNewLines(const char* file)
{
	std::ifstream myFile(file);

	if (!myFile.is_open())
		return 0;

	return countSymbol(myFile, '\n') + 1;
}
int main()
{
	std::cout << countNewLines("2ndTaskCountNewLines.cpp");

	return 0;
}