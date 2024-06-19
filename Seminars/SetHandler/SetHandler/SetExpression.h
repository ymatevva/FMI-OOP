#pragma once
#include"SetInterpret.h"


class SetExpression
{
public:
	SetExpression() = default;
	SetExpression(const SetExpression& expr) = delete;
	SetExpression& operator=(const SetExpression& other) = delete;
	virtual ~SetExpression() = default;

	virtual SetExpression* clone() const = 0;
	virtual bool isElementIn(const SetInterpret& inter) const = 0;
	virtual void populateVars(SetInterpret& other) const = 0;
};
