#pragma once
#include "../Value.h"

namespace ai
{
    class AlwaysLootListValue : public ManualSetValue<set<uint32>&>
	{
	public:
        AlwaysLootListValue(PlayerbotAI* ai) : ManualSetValue<set<uint32>&>(ai, list) {}

    private:
        set<uint32> list;
    };
}
