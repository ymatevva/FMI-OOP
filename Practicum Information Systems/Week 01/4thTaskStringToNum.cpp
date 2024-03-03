#include<iostream>


namespace HelperFunctions {

	bool isDigit(char ch) {
		return ch >= '0' && ch <= '9';
	}

	unsigned fromCharToDigit(char ch) {
		return ch - '0';
	}
}

enum ErrorCode {

	OK,
	NullPtrGiven,
	InvalidDigit,
	EmptyStr
};

struct Result {

	unsigned res;
	ErrorCode errorCode;
};


Result turnStrToNum(const char* str) {

	if (!str) {
		return  { 0, ErrorCode::NullPtrGiven };
	}

	if (!*str) {
		return { 0,ErrorCode::EmptyStr };
	}


	unsigned res = 0;
	while (*str) {

		if (!HelperFunctions::isDigit(*str)) {
			return { res, ErrorCode::InvalidDigit };
		}

		unsigned digit = HelperFunctions :: fromCharToDigit(*str);

		(res *= 10) += digit;
		str++;
	}

	return { res, ErrorCode::OK };
}

int main() {

	Result str = turnStrToNum("1234567");

	if (str.errorCode == ErrorCode::OK) {
		std::cout << str.res << std::endl;
	}
	else {
		std::cout << "Error!" << std::endl;
	}


	return 0;
}