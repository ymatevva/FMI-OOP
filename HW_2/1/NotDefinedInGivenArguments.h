#pragma once
#include "Criteria.h"
#include "Vector.hpp"

class NotDefinedInGivenArguments : public Criteria {

    Vector<int32_t>undefinedPoints;
    uint16_t N;

public:
    NotDefinedInGivenArguments(Vector<int32_t>& elements, uint16_t N);
    int32_t operator()(int32_t element) const override;
};