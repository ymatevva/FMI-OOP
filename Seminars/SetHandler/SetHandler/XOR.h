#pragma once
#include"BinaryOperation.h"

class XOR : public BinaryOperation
{
public:
	XOR(SetExpression* left, SetExpression* right);
	bool isElementIn(const SetInterpret& inter)const override;
	SetExpression* clone() const override;
};

