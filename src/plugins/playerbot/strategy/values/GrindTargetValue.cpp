#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GrindTargetValue.h"
#include "../../PlayerbotAIConfig.h"
#include "../../RandomPlayerbotMgr.h"

using namespace ai;

Unit* GrindTargetValue::Calculate()
{
    uint32 memberCount = 1;
    Group* group = bot->GetGroup();
    if (group)
        memberCount = group->GetMembersCount();

    Unit* target = NULL;
    uint32 assistCount = 0;
    while (!target && assistCount < memberCount)
    {
        target = FindTargetForGrinding(assistCount++);
    }

    return target;
}


Unit* GrindTargetValue::FindTargetForGrinding(int assistCount)
{
    uint32 memberCount = 1;
    Group* group = bot->GetGroup();
    Player* master = GetMaster();

    list<ObjectGuid> attackers = context->GetValue<list<ObjectGuid> >("attackers")->Get();
    for (list<ObjectGuid>::iterator i = attackers.begin(); i != attackers.end(); i++)
    {
        Unit* unit = ai->GetUnit(*i);
        if (!unit || !unit->IsAlive())
            continue;

        return unit;
    }

    list<ObjectGuid> targets = *context->GetValue<list<ObjectGuid> >("possible targets");

    if(targets.empty())
        return NULL;

    float distance = 0;
    Unit* result = NULL;
    for(list<ObjectGuid>::iterator tIter = targets.begin(); tIter != targets.end(); tIter++)
    {
        Unit* unit = ai->GetUnit(*tIter);
        if (!unit)
            continue;

        if (abs(bot->GetPositionZ() - unit->GetPositionZ()) > sPlayerbotAIConfig.spellDistance)
            continue;

        if (GetTargetingPlayerCount(unit) > assistCount)
            continue;

		if (master && master->GetDistance(unit) >= sPlayerbotAIConfig.grindDistance && !sRandomPlayerbotMgr.IsRandomBot(bot))
            continue;

		if ((int)unit->getLevel() - (int)bot->getLevel() > 4 && !unit->GetGUID().IsPlayer())
		    continue;

		Creature* creature = dynamic_cast<Creature*>(unit);
		if (creature && creature->GetCreatureTemplate() && creature->GetCreatureTemplate()->rank > CREATURE_ELITE_NORMAL)
		    continue;

        if (group)
        {
            Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
            for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
            {
                Player *member = sObjectMgr->GetPlayerByLowGUID(itr->guid);
                if( !member || !member->IsAlive())
                    continue;

                float d = member->GetDistance(unit);
                if (!result || d < distance)
                {
                    distance = d;
                    result = unit;
                }
            }
        }
        else
        {
            float d = bot->GetDistance(unit);
            if (!result || d < distance)
            {
                distance = d;
                result = unit;
            }
        }
    }

    return result;
}


int GrindTargetValue::GetTargetingPlayerCount( Unit* unit )
{
    Group* group = bot->GetGroup();
    if (!group)
        return 0;

    int count = 0;
    Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
    for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
    {
        Player *member = sObjectMgr->GetPlayerByLowGUID(itr->guid);
        if( !member || !member->IsAlive() || member == bot)
            continue;

        PlayerbotAI* ai = member->GetPlayerbotAI();
        if ((ai && *ai->GetAiObjectContext()->GetValue<Unit*>("current target") == unit) ||
            (!ai && member->GetSelectedUnit() == unit))
            count++;
    }

    return count;
}

