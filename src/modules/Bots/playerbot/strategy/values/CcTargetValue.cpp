#include "botpch.h"
#include "../../playerbot.h"
#include "CcTargetValue.h"
#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"
#include "../Action.h"

using namespace ai;

class FindTargetForCcStrategy : public FindTargetStrategy
{
public:
    FindTargetForCcStrategy(PlayerbotAI* ai, string spell) : FindTargetStrategy(ai)
    {
        this->spell = spell;
        maxDistance = 0;
    }

public:
    virtual void CheckAttacker(Unit* creature, ThreatManager* threatManager)
    {
        Player* bot = ai->GetBot();
        if (*ai->GetAiObjectContext()->GetValue<Unit*>("current target") == creature)
            return;

        uint8 health = creature->GetHealthPercent();
        if (health < sPlayerbotAIConfig.mediumHealth)
            return;

        if (!ai->CanCastSpell(spell, creature, true))
            return;

        if (*ai->GetAiObjectContext()->GetValue<Unit*>("rti target") == creature)
        {
            result = creature;
            return;
        }

        float minDistance = sPlayerbotAIConfig.spellDistance;
        Group* group = bot->GetGroup();
        if (!group)
            return;

        if (group->GetTargetIcon(4) == creature->GetObjectGuid())
        {
            result = creature;
            return;
        }

        if (*ai->GetAiObjectContext()->GetValue<uint8>("aoe count") > 2)
        {
            WorldLocation aoe = *ai->GetAiObjectContext()->GetValue<WorldLocation>("aoe position");
            if (sServerFacade.IsDistanceLessOrEqualThan(sServerFacade.GetDistance2d(creature, aoe.coord_x, aoe.coord_y), sPlayerbotAIConfig.aoeRadius))
                return;
        }

        int tankCount, dpsCount;
        GetPlayerCount(creature, &tankCount, &dpsCount);
        if (!tankCount || !dpsCount)
        {
            result = creature;
            return;
        }

        Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
        for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
        {
            Player *member = sObjectMgr.GetPlayer(itr->guid);
            if( !member || !sServerFacade.IsAlive(member) || member == bot)
                continue;

            if (!ai->IsTank(member))
                continue;

            float distance = member->GetDistance(creature);
            if (distance < minDistance)
                minDistance = distance;
        }

        if (!result || minDistance > maxDistance)
        {
            result = creature;
            maxDistance = minDistance;
        }
    }

private:
    string spell;
    float maxDistance;
};

Unit* CcTargetValue::Calculate()
{
    FindTargetForCcStrategy strategy(ai, qualifier);
    return FindTarget(&strategy);
}
