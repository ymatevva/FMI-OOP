#include "MaximumOfPartialFunctions.h"

MaximumOfPartialFunctions::MaximumOfPartialFunctions(PartialFunctionCollection& functions) : functions(std::move(functions)) {}

PartialFunction* MaximumOfPartialFunctions::clone() const
{
	return new MaximumOfPartialFunctions(*this);
}

MyPair MaximumOfPartialFunctions::executeFunc(int32_t input) const
{
	if (!isPointDefined(input)) {
		return { false, 0 };
	}

	int32_t maxVal = FunctionConstants::MIN_VALUE;

	for (size_t i = 0; i < functions.getSize(); i++) {

		int32_t currRes = functions[i]->executeFunc(input).res;
		if (currRes > maxVal) {
			maxVal = currRes;
		}
	}
	return { true, maxVal };
}

bool MaximumOfPartialFunctions::isPointDefined(int32_t input) const
{
	for (size_t i = 0; i < functions.getSize(); i++) {
		if (!functions[i]->isPointDefined(input)) {
			return false;
		}
	}
	return true;
}