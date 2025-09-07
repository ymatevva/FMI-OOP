#pragma once
#include"PartialFunctionCollection.h"
#include"PartialFunction.h"

class MinimumOfPartialFunctions : public PartialFunction {

	PartialFunctionCollection functions;

public:
	MinimumOfPartialFunctions(PartialFunctionCollection& functions);
	MyPair executeFunc(int32_t input) const override;
	bool isPointDefined(int32_t input) const override;
	PartialFunction* clone() const override;
};
