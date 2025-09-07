#include "MinimumOfPartialFunctions.h"

MinimumOfPartialFunctions::MinimumOfPartialFunctions(PartialFunctionCollection& functions) : functions(std::move(functions)) {}

PartialFunction* MinimumOfPartialFunctions::clone() const
{
	return new MinimumOfPartialFunctions(*this);
}

MyPair MinimumOfPartialFunctions::executeFunc(int32_t input) const
{
	if (!isPointDefined(input)) {
		return { false, 0 };
	}

	int32_t minVal = FunctionConstants::MAX_VALUE;

	for (size_t i = 0; i < functions.getSize(); i++) {

		int32_t currRes = functions[i]->executeFunc(input).res;
		if (currRes < minVal) {
			minVal = currRes;
		}
	}
	return { true, minVal };
}

bool MinimumOfPartialFunctions::isPointDefined(int32_t input) const
{
	for (size_t i = 0; i < functions.getSize(); i++) {
		if (!functions[i]->isPointDefined(input)) {
			return false;
		}
	}
	return true;
}