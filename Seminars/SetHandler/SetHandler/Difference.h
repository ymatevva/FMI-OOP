#pragma once
#include "BinaryOperation.h"
class Difference :  public BinaryOperation
{
public:
	Difference(SetExpression* left, SetExpression* right);
	bool isElementIn(const SetInterpret& inter) const override;
	SetExpression* clone() const override;
};

