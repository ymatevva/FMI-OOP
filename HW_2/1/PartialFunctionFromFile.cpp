#include "PartialFunctionFromFile.h"
#include"PartialFunctionByCriteria.h"
#include"DefinedForAll.h"
#include"DefinedOnlyInGivenArguments.h"
#include"NotDefinedInGivenArguments.h"
#include"MinimumOfPartialFunctions.h"
#include"MaximumOfPartialFunctions.h"
#include<utility>

namespace {
	constexpr size_t MAX_SIZE_OF_N = 32;
	constexpr size_t BUFF_SIZE = 1024;
}

void readPartialFunctionFromFile(Vector<int32_t>& arguments, std::ifstream& fromFile, uint16_t N) {

	if (fromFile.is_open()) {
		for (uint16_t i = 0; i < N; i++) {
			int32_t currNum;
			fromFile.read((char*)&currNum, sizeof(int32_t));
			arguments.pushBack(currNum);
		}
	}
	else {
		throw std::runtime_error("The file could not be opened for reading.");
	}
}
void readMultiplePartialFunctions(PartialFunctionCollection& partialFunctions, std::ifstream& fromFile, uint16_t N) {
	
	for (uint16_t i = 0; i < N; i++) {
		char* buffer = new char[BUFF_SIZE];
		char ch;
		int buffIdx = 0;

		while (fromFile.get(ch)) {
			if (ch == '\0' || i == BUFF_SIZE - 1) {
				buffer[buffIdx] = '\0';
				break;
			}
			buffer[buffIdx++] = ch;
		}

		PartialFunctionFromFile currFunctionFromFile(buffer);
		partialFunctions.addPartialFunction(currFunctionFromFile.getPartialFunction());

		delete[] buffer;
	}
}

PartialFunctionFromFile::PartialFunctionFromFile(const char* fileName) {

	std::ifstream fromFile(fileName, std::ios::binary);

	if (!fromFile.is_open()) {
		throw std::runtime_error("The file could not be opened for reading.");
	}

	fromFile.read((char*)&N, sizeof(uint16_t));

	if (MAX_SIZE_OF_N < N) {
		throw std::invalid_argument("The input for N was invalid.");
	}

	fromFile.read((char*)&T, sizeof(uint16_t));
	buildPartialFunction(fromFile);
	fromFile.close();
}

void PartialFunctionFromFile::buildPartialFunction(std::ifstream& fromFile) {
	switch (T) {
	case 0: {
		buildFunctionIfTIsZero(fromFile);
		break;
	}
	case 1: {
		buildFunctionIfTIsOne(fromFile);
		break;
	}
	case 2: {
		buildFunctionIfTIsTwo(fromFile);
		break;
	}
	case 3: {
		buildFunctionIfTIsThree(fromFile);
		break;
	}
	case 4: {
		buildFunctionIfTIsFour(fromFile);
		break;
	}
	default: {
		throw std::invalid_argument("The argument for T is not valid.");
	}
	}
}


void PartialFunctionFromFile::buildFunctionIfTIsZero(std::ifstream& fromFile) {

	Vector<int32_t> arguments;
	readPartialFunctionFromFile(arguments, fromFile, 2 * N);
	SharedPtr<Criteria> criteria(new DefinedOnlyInGivenArguments(arguments, N));
	partialFunctionFromFile = new PartialFunctionByCriteria(criteria);
}

void PartialFunctionFromFile::buildFunctionIfTIsOne(std::ifstream& fromFile) {

	Vector<int32_t> arguments;
	readPartialFunctionFromFile(arguments, fromFile, N);
	SharedPtr<Criteria> criteria(new NotDefinedInGivenArguments(arguments, N));
	partialFunctionFromFile = new PartialFunctionByCriteria(criteria);
}


void PartialFunctionFromFile::buildFunctionIfTIsTwo(std::ifstream& fromFile) {
	Vector<int32_t> arguments;
	readPartialFunctionFromFile(arguments, fromFile, N);
	SharedPtr<Criteria> criteria(new DefinedForAll(arguments, N));
	partialFunctionFromFile = new PartialFunctionByCriteria(criteria);
}

void PartialFunctionFromFile::buildFunctionIfTIsThree(std::ifstream& fromFile) {
	PartialFunctionCollection partialFunctions;
	readMultiplePartialFunctions(partialFunctions, fromFile, N);
	partialFunctionFromFile = new MaximumOfPartialFunctions(partialFunctions);
}

void PartialFunctionFromFile::buildFunctionIfTIsFour(std::ifstream& fromFile) {
	PartialFunctionCollection partialFunctions;
	readMultiplePartialFunctions(partialFunctions, fromFile, N);
	partialFunctionFromFile = new MinimumOfPartialFunctions(partialFunctions);
}
const UniquePointer<PartialFunction>& PartialFunctionFromFile::getPartialFunction() const {
	return partialFunctionFromFile;
}
UniquePointer<PartialFunction>& PartialFunctionFromFile::getPartialFunction() {
	return partialFunctionFromFile;
}