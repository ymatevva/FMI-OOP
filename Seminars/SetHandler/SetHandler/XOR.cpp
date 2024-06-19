#include "XOR.h"

XOR::XOR(SetExpression* left, SetExpression* right):BinaryOperation(left,right)
{
}

bool XOR::isElementIn(const SetInterpret& inter) const{
    return (!left->isElementIn(inter) && right->isElementIn(inter) ) || (left->isElementIn(inter) && !right->isElementIn(inter));
}

SetExpression* XOR::clone() const{
    return new XOR(left->clone(),right->clone());
}
