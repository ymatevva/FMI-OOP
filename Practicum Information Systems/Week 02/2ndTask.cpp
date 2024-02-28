#include<iostream>
#include<fstream>

namespace HelperFunctions {

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '0';
    }

    bool isLower(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    bool isUpper(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
}
void countSymbols(const char* path,unsigned& lowerLetters, unsigned& capLetters, unsigned& digits,unsigned& other){
    std::ifstream inFile(path);

    if (!inFile.is_open())
        return;

    while (true)
    {
        char ch = inFile.get();

        if (inFile.eof())
            break;

        if (HelperFunctions::isDigit(ch))
            digits++;
        else if (HelperFunctions::isLower(ch))
            lowerLetters++;
        else if (HelperFunctions::isUpper(ch))
            capLetters++;
        else
            other++;
     }
}

int main()
{
    unsigned lowerLetters = 0, capLetters = 0, digits = 0, other = 0;

    countSymbols("1stTaskPract1.cpp", lowerLetters, capLetters, digits, other);

    std::cout << lowerLetters << " " << capLetters << " " << digits << " " << other << std::endl;

	return 0;
}