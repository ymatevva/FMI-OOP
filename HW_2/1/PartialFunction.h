#pragma once
#include<cstdint>

namespace FunctionConstants {
	constexpr int32_t MIN_VALUE = -2147483648;
	constexpr int32_t MAX_VALUE = 2147483647;
}

struct MyPair {
	bool isDef;
	int32_t res;
};

class PartialFunction {

public:

	virtual MyPair executeFunc(int32_t input) const = 0;
	virtual bool isPointDefined(int32_t input) const = 0;
	virtual PartialFunction* clone() const = 0;
	virtual ~PartialFunction() = default;
};