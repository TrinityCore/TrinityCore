#pragma once

#include "TSString.h"

class TSClass
{
public:
  virtual TSString stringify(int indention = 0) { return JSTR("[TSClass (stringify not implemented)]"); };
};

class DBTable : public TSClass
{
};