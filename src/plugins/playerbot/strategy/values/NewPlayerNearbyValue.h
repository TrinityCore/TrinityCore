#pragma once
#include "../Value.h"

namespace ai
{
    class NewPlayerNearbyValue : public CalculatedValue<ObjectGuid>
	{
	public:
        NewPlayerNearbyValue(PlayerbotAI* ai) : CalculatedValue<ObjectGuid>(ai, "new player nearby") {}
        virtual ObjectGuid Calculate();
    };

    class AlreadySeenPlayersValue : public ManualSetValue<set<ObjectGuid>& >
	{
	public:
        AlreadySeenPlayersValue(PlayerbotAI* ai) : ManualSetValue<set<ObjectGuid>& >(ai, data, "already seen players") {}

    private:
        set<ObjectGuid> data;
    };
}
