
#pragma once

#include "global.hpp"

class UIContainer
{
private:

public:
    UIContainer() {}
    virtual ~UIContainer() = default;
    virtual void init() = 0;
    virtual void render() {};
    virtual int update(bool down) = 0;
};
