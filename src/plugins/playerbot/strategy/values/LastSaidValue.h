#pragma once
#include "../Value.h"

namespace ai
{
    class LastSaidValue : public ManualSetValue<time_t>, public Qualified
	{
	public:
        LastSaidValue(PlayerbotAI* ai) : ManualSetValue<time_t>(ai, 0, "last said") {}
    };
}
