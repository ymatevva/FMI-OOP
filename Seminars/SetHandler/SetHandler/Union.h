#pragma once
#include "BinaryOperation.h"

class Union : public BinaryOperation
{
public:
	Union(SetExpression* left, SetExpression* right);
	bool isElementIn(const SetInterpret& expr)const override;
	SetExpression* clone() const override;
};

