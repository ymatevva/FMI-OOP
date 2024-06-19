#include "UnaryOperation.h"

UnaryOperation::UnaryOperation(SetExpression* expr):expr(expr)
{
}

void UnaryOperation::populateVars(SetInterpret& inter) const
{
	expr->populateVars(inter);
}

UnaryOperation::~UnaryOperation()
{
	delete expr;
}
