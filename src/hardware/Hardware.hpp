
#pragma once

#include "global.hpp"

class Hardware
{
private:

public:
    Hardware() {}
    virtual ~Hardware() = default;
    virtual void init() = 0;
    // virtual void update() = 0;
};

