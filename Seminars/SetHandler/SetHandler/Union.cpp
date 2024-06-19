#include "Union.h"

Union::Union(SetExpression* left, SetExpression* right) : BinaryOperation(left,right)
{
}

bool Union::isElementIn(const SetInterpret& inter) const
{
    return left->isElementIn(inter) || right->isElementIn(inter);
}

SetExpression* Union::clone() const
{
    return new Union(left->clone(),right->clone());
}
