#pragma once
#include <cstdint>

class Criteria {

public:
    virtual int32_t operator()(int element) const = 0;
    virtual ~Criteria() = default;
};