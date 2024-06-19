#pragma once
#include "BinaryOperation.h"

class Intersection : public BinaryOperation
{
public:
	Intersection(SetExpression* left, SetExpression* right);
	bool isElementIn(const SetInterpret& inter) const override;
	SetExpression* clone() const override;
};

