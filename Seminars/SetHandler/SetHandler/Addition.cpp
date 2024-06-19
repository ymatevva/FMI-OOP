
#include "Addition.h"

Addition::Addition(SetExpression* expr):UnaryOperation(expr)
{
}

SetExpression* Addition::clone() const
{
    return new Addition(expr->clone());
}

bool Addition::isElementIn(const SetInterpret& inter) const
{
    return false;
}
