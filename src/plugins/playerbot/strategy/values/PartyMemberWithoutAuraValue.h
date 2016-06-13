#pragma once
#include "../Value.h"
#include "PartyMemberValue.h"
#include "../../PlayerbotAIConfig.h"

namespace ai
{
    class PartyMemberWithoutAuraValue : public PartyMemberValue, public Qualified
	{
	public:
        PartyMemberWithoutAuraValue(PlayerbotAI* ai, float range = sPlayerbotAIConfig.sightDistance) :
          PartyMemberValue(ai) {}

    protected:
        virtual Unit* Calculate();
	};
}
