#pragma once
#include "Criteria.h"
#include "Vector.hpp"

class DefinedOnlyInGivenArguments : public Criteria {

    Vector<int32_t>arguments;
    Vector<int32_t>results;
    uint16_t N;

public:
    DefinedOnlyInGivenArguments(Vector<int32_t>& elements, uint16_t N);
    int32_t operator()(int32_t element) const override;
};