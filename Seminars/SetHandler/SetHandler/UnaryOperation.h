#pragma once
#include "SetExpression.h"

class UnaryOperation : public SetExpression
{
protected:
	SetExpression* expr;
public:
	UnaryOperation(SetExpression* expr);
	void populateVars(SetInterpret& inter) const override;
	~UnaryOperation();
};

