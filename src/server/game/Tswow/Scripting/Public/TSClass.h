#pragma once

#include "TSString.h"

class TSClass 
{
public:
    virtual TSString stringify(int indention = 0) { return JSTR("[Raw TSClass]"); };
};

class DBTable : public TSClass
{
};