#pragma once
#include "SetExpression.h"

class BinaryOperation : public SetExpression
{
protected:
	SetExpression* left;
	SetExpression* right;
public:
	BinaryOperation(SetExpression* left, SetExpression* right);
	void populateVars(SetInterpret& inter) const override;
	~BinaryOperation();
};

