#pragma once
#include "../Value.h"
#include "NearestUnitsValue.h"
#include "../../PlayerbotAIConfig.h"

namespace ai
{
    class PossibleRpgTargetsValue : public NearestUnitsValue
	{
	public:
        PossibleRpgTargetsValue(PlayerbotAI* ai, float range = sPlayerbotAIConfig.rpgDistance);

    protected:
        void FindUnits(list<Unit*> &targets);
        bool AcceptUnit(Unit* unit);

    public:
        static vector<uint32> allowedNpcFlags;
	};
}
