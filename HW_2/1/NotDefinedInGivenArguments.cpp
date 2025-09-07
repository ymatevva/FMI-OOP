#include "NotDefinedInGivenArguments.h"

NotDefinedInGivenArguments::NotDefinedInGivenArguments(Vector<int32_t>& elements, uint16_t N)
    : undefinedPoints(std::move(elements)), N(N) {}


int32_t NotDefinedInGivenArguments::operator()(int32_t element) const {

    for (uint16_t i = 0; i < N; i++) {
        if (undefinedPoints[i] == element) {
            throw std::invalid_argument("The point is not defined.");
        }
    }
    return element;
}