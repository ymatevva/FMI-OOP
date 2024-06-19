#include "Difference.h"

Difference::Difference(SetExpression* left, SetExpression* right) : BinaryOperation(left,right)
{
}

bool Difference::isElementIn(const SetInterpret& inter) const
{
    return left->isElementIn(inter) && !right->isElementIn(inter);
}

SetExpression* Difference::clone() const
{
    return new Difference(left->clone(),right->clone());
}
