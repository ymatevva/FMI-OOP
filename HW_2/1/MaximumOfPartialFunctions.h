#pragma once
#include"PartialFunctionCollection.h"
#include"PartialFunction.h"

class MaximumOfPartialFunctions : public PartialFunction {

	PartialFunctionCollection functions;

public:
	MaximumOfPartialFunctions(PartialFunctionCollection& functions);
	MyPair executeFunc(int32_t input) const override;
	bool isPointDefined(int32_t input) const override;
	PartialFunction* clone() const override;
};
