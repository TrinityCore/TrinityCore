#pragma once
#include "../Value.h"

namespace ai
{
    class ThreatValue : public Uint8CalculatedValue, public Qualified
	{
	public:
        ThreatValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

    public:
    	virtual uint8 Calculate();

    protected:
    	uint8 Calculate(Unit* target);
    };
}
