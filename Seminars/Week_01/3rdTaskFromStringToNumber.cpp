#include<iostream>
constexpr int MAX_SIZE = 256;

bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

int convertCharToInt(char ch) {
	return ch - '0';
}

enum class ErrorCode {

	OK,
	NullPtr,
	WrongCharInStr,
	EmptyStr
};

struct ConvertResult {
	
	ErrorCode errCode;
	unsigned result;
};

ConvertResult fromStrToNum(const char* str)
{
	if (!str)
		return{ ErrorCode::NullPtr,0 };

	unsigned num = 0;

	if (!*str)
		return { ErrorCode::EmptyStr, num };

	while (*str)
	{
		if (!isDigit(*str))
			return{ ErrorCode::WrongCharInStr, 0};

		(num *= 10) += convertCharToInt(*str);
		str++;
	}
	return { ErrorCode::OK, num };
}
int main()
{
	ConvertResult str = fromStrToNum("1234");

	if (str.errCode == ErrorCode::OK) {
		std::cout << str.result << std::endl;
	}

	else {
		std::cout << "Error!" << std::endl;
	}
}