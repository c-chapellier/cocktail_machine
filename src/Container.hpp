
#pragma once

#include "global.hpp"

class Container
{
private:

public:
    Container() {}
    virtual ~Container() = default;
    virtual void init() = 0;
    virtual void render() {};
    virtual int update(bool down) = 0;
};
