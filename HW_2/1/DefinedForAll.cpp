#include "DefinedForAll.h"

DefinedForAll::DefinedForAll(Vector <int32_t>& elements, uint16_t N) : positiveValues(std::move(elements)), N(N) {
}

int32_t DefinedForAll::operator()(int32_t element) const {
   
    for (uint16_t i = 0; i < N; i++) {
        if (positiveValues[i] == element) {
            return 1;
        }
    }
    return 0;
}