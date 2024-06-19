#include "SetHandler.h"

void SetHandler::copyFrom(const SetHandler& other)
{
    expr = other.expr->clone();
}

void SetHandler::moveFrom(SetHandler&& other)
{
    expr = other.expr;
    other.expr = nullptr;
}

void SetHandler::free()
{
    delete expr;
}

SetHandler::SetHandler(const char* str)
{
    expr = setFactory(str);
}

SetHandler::SetHandler(const SetHandler& other)
{
    copyFrom(other);
}

SetHandler::SetHandler(SetHandler&& other) noexcept
{
    moveFrom(std::move(other));
}

SetHandler& SetHandler::operator=(const SetHandler& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

SetHandler& SetHandler::operator=(SetHandler&& other) noexcept
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

SetHandler::~SetHandler()
{
    free();
}

bool SetHandler::isElementIn(const SetInterpret& inter) const
{
    return expr->isElementIn(inter);
}
