
#pragma once

#include "globals.hpp"

class Container
{
private:

public:
    Container() {}
    virtual ~Container() = default;
    virtual void init() = 0;
    virtual void render() = 0;
    virtual int update(bool down) = 0;
};
