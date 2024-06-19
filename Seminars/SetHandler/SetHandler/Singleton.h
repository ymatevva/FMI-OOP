#pragma once
#include "SetExpression.h"

class Singleton :  public SetExpression
{
protected:
	char ch;
public:
	Singleton(char ch);
	bool isElementIn(const SetInterpret& inter) const override;
	void populateVars(SetInterpret& inter) const override;
	SetExpression* clone() const override;
};

