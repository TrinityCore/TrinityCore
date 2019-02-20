#pragma once
#include "../Value.h"

namespace ai
{
    class AoeHealValue : public Uint8CalculatedValue, public Qualified
	{
	public:
    	AoeHealValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

    public:
    	virtual uint8 Calculate();
    };
}
