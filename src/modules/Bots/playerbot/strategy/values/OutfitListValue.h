#pragma once
#include "../Value.h"

namespace ai
{
    typedef list<string> Outfit;
    class OutfitListValue : public ManualSetValue<Outfit&>
	{
	public:
        OutfitListValue(PlayerbotAI* ai) : ManualSetValue<Outfit&>(ai, list) {}

    private:
        Outfit list;
    };
}
