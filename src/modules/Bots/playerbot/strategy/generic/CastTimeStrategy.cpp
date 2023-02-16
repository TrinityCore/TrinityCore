#include "botpch.h"
#include "../../playerbot.h"
#include "CastTimeStrategy.h"

#include "../../ServerFacade.h"
#include "../actions/GenericSpellActions.h"

using namespace ai;

float CastTimeMultiplier::GetValue(Action* action)
{
    if (action == NULL) return 1.0f;

    uint8 targetHealth = AI_VALUE2(uint8, "health", "current target");
    string name = action->getName();

    if (action->GetTarget() != AI_VALUE(Unit*, "current target"))
        return 1.0f;

    if (targetHealth < sPlayerbotAIConfig.lowHealth && dynamic_cast<CastSpellAction*>(action))
    {
        uint32 spellId = AI_VALUE2(uint32, "spell id", name);
        const SpellEntry* const pSpellInfo = sServerFacade.LookupSpellInfo(spellId);
        if (!pSpellInfo) return 1.0f;

        if (spellId && pSpellInfo->Targets & TARGET_FLAG_DEST_LOCATION)
            return 1.0f;
        else if (spellId && pSpellInfo->Targets & TARGET_FLAG_SOURCE_LOCATION)
            return 1.0f;
        else if (spellId && GetSpellCastTime(pSpellInfo) >= 3000)
            return 0.0f;
        else if (spellId && GetSpellCastTime(pSpellInfo) >= 1500)
            return 0.5f;
    }

    return 1.0f;
}


void CastTimeStrategy::InitMultipliers(std::list<Multiplier*> &multipliers)
{
    multipliers.push_back(new CastTimeMultiplier(ai));
}
