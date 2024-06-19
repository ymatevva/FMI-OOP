#include "Singleton.h"

Singleton::Singleton(char ch) : ch(ch) {}

bool Singleton::isElementIn(const SetInterpret& inter) const
{
    return inter.getValue(ch);
}

void Singleton::populateVars(SetInterpret& inter) const
{
    inter.setValue(ch, true);
}

SetExpression* Singleton::clone() const
{
    return new Singleton(ch);
}
