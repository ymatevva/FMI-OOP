#pragma once
#include"UnaryOperation.h"

class Addition : public UnaryOperation
{
public:
	Addition(SetExpression* expr);
	SetExpression* clone() const override;
	bool isElementIn(const SetInterpret& inter) const override;
};

