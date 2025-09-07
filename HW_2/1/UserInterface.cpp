#include "UserInterface.h"
#include<cstring>

namespace {
	constexpr char INPUT_FILE_NAME[] = "func.dat";
}

static void mySwap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

UserInterface::UserInterface() : partialFunctionFromFile(INPUT_FILE_NAME) {

	int input;
	std::cout << "Choose mode for work(1 or 2):";
	std::cin >> input;

	if (input == 1) {
		std::cout << "Input the start value of the interval:";
		std::cin >> a;

		std::cout << "Input the end value of the interval:";
		std::cin >> b;

		if (a > b) {
			mySwap(a, b);
		}

		interval();
	}
	else if (input == 2) {
		generatingAllElements();
	}
	else {
		std::cout << "The input is not valid." << std::endl;
	}
}
void UserInterface::interval()const {

	for (int element = a; element <= b; element++) {

		MyPair resultFromEvaluation = partialFunctionFromFile.getPartialFunction()->executeFunc(element);

		if (resultFromEvaluation.isDef) {
			std::cout << "f(" << element << ") = " << resultFromEvaluation.res << std::endl;
		}
	}
}


void UserInterface::generatingAllElements()const {

	int32_t element = FunctionConstants::MIN_VALUE;

	std::cout << "Type 'next' to get the result for the next element: " << std::endl;


	while (true) {
		char buffer[10];
		std::cin >> buffer;

		if (strcmp(buffer, "next") == 0) {

			MyPair resultFromEvaluation = partialFunctionFromFile.getPartialFunction()->executeFunc(element);

			while (!resultFromEvaluation.isDef) {

				if (element == FunctionConstants::MAX_VALUE) {
					break;
				}

				element++;
				resultFromEvaluation = partialFunctionFromFile.getPartialFunction()->executeFunc(element);
			}

			if (element == FunctionConstants::MAX_VALUE) {
				std::cout << "The limit of elements is reached.";
				break;
			}

			std::cout << "f(" << element << ") = " << resultFromEvaluation.res << std::endl;
			element++;
		}
		else {
			std::cout << "Type 'next' to get the result for the next element: " << std::endl;
		}
	}

}