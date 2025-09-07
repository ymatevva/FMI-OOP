#pragma once
#include"PartialFunction.h"
#include"Vector.hpp"
#include "Criteria.h"
#include "SharedPtr.hpp"

class PartialFunctionByCriteria : public PartialFunction {

	SharedPtr<Criteria>criteria;

public:
	PartialFunctionByCriteria(const SharedPtr<Criteria>& criteria);
	MyPair executeFunc(int32_t input) const override;
	bool isPointDefined(int32_t input) const override;
	PartialFunction* clone() const override;
};