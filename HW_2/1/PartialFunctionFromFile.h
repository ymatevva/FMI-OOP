#pragma once
#include<fstream>
#include"PartialFunction.h"
#include"UniquePtr.hpp"
#include"Vector.hpp"
#include"PartialFunctionCollection.h"
#include"MaximumOfPartialFunctions.h"
#include"MinimumOfPartialFunctions.h"
#include"DefinedForAll.h"
#include"NotDefinedInGivenArguments.h"
#include"DefinedOnlyInGivenArguments.h"
#include"PartialFunctionByCriteria.h"
#include"PartialFunctionCollection.h"


class PartialFunctionFromFile {

	UniquePointer<PartialFunction> partialFunctionFromFile;
	uint16_t N = 0;
	uint16_t T = 0;

	void buildPartialFunction(std::ifstream& fromFile);
	void buildFunctionIfTIsZero(std::ifstream& fromFile);
	void buildFunctionIfTIsOne(std::ifstream& fromFile);
	void buildFunctionIfTIsTwo(std::ifstream& fromFile);
	void buildFunctionIfTIsThree(std::ifstream& fromFile);
	void buildFunctionIfTIsFour(std::ifstream& fromFile);

public:
	PartialFunctionFromFile(const char* fileName);
	UniquePointer<PartialFunction>& getPartialFunction();
	const UniquePointer<PartialFunction>& getPartialFunction()const;
};

void readMultiplePartialFunctions(PartialFunctionCollection& partialFunctions, std::ifstream& fromFile, uint16_t N);
void readPartialFunctionFromFile(Vector<int32_t>& partialFunction, std::ifstream& fromFile, uint16_t N);