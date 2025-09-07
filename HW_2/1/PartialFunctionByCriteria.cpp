#include "PartialFunctionByCriteria.h"

PartialFunctionByCriteria::PartialFunctionByCriteria(const SharedPtr<Criteria>& criteria) : criteria(criteria) {}

PartialFunction* PartialFunctionByCriteria::clone() const
{
    return new PartialFunctionByCriteria(*this);
}

MyPair PartialFunctionByCriteria::executeFunc(int32_t input) const
{
    try {
        int32_t result = criteria->operator()(input);
        return { true, result };
    }
    catch (const std::invalid_argument& e) {
        return { false, 0 };
    }
}

bool PartialFunctionByCriteria::isPointDefined(int32_t input) const {
    return executeFunc(input).isDef;
}