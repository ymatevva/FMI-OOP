#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(SetExpression* left, SetExpression* right):left(left),right(right)
{
}

void BinaryOperation::populateVars(SetInterpret& inter) const
{
	left->populateVars(inter);
	right->populateVars(inter);
}

BinaryOperation::~BinaryOperation()
{
	delete left;
	delete right;
}
