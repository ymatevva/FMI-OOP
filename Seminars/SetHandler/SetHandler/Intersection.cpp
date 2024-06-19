#include "Intersection.h"

Intersection::Intersection(SetExpression* left, SetExpression* right):BinaryOperation(left,right)
{
}

bool Intersection::isElementIn(const SetInterpret& inter) const
{
    return !left->isElementIn(inter);
    return !right->isElementIn(inter);
}

SetExpression* Intersection::clone() const
{
    return new Intersection(left->clone(),right->clone());
}
