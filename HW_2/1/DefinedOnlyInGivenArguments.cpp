#include"DefinedOnlyInGivenArguments.h"

DefinedOnlyInGivenArguments::DefinedOnlyInGivenArguments(Vector<int32_t>& elements, uint16_t N) : N(N) {

    arguments = Vector<int32_t>();

    uint16_t i = 0;
    for (; i < N; i++) {
        arguments.pushBack(elements[i]);
    }

    results = Vector<int32_t>();

    for (; i < 2 * N; i++) {
        results.pushBack(elements[i]);
    }
}

int32_t DefinedOnlyInGivenArguments::operator()(int32_t element) const {

    int16_t lastResPos = -1;

    for (uint16_t i = 0; i < N; i++) {
        if (arguments[i] == element) {
           lastResPos = i;
        }
    }

    if (lastResPos != -1) {
        return results[lastResPos];//the purpose of this check is to see if a point leads to more than one result and if so to return the last one
    }
    
     throw std::invalid_argument("The point is not defined.");
    
}