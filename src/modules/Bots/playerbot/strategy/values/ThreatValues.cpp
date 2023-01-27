#include "botpch.h"
#include "../../playerbot.h"
#include "ThreatValues.h"

#include "../../ServerFacade.h"
#include "ThreatManager.h"

using namespace ai;

uint8 ThreatValue::Calculate()
{
    if (qualifier == "aoe")
    {
        uint8 maxThreat = 0;
        list<ObjectGuid> attackers = context->GetValue<list<ObjectGuid> >("attackers")->Get();
        for (list<ObjectGuid>::iterator i = attackers.begin(); i != attackers.end(); i++)
        {
            Unit* unit = ai->GetUnit(*i);
            if (!unit || !sServerFacade.IsAlive(unit))
                continue;

            uint8 threat = Calculate(unit);
            if (!maxThreat || threat > maxThreat)
                maxThreat = threat;
        }

        return maxThreat;
    }

    Unit* target = AI_VALUE(Unit*, qualifier);
    return Calculate(target);
}

uint8 ThreatValue::Calculate(Unit* target)
{
    if (!target)
        return 0;

    if (target->GetObjectGuid().IsPlayer())
        return 0;

    Group* group = bot->GetGroup();
    if (!group)
        return 0;

    float botThreat = sServerFacade.GetThreatManager(target).getThreat(bot);
    float maxThreat = 0;

    Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
    for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
    {
        Player *player = sObjectMgr.GetPlayer(itr->guid);
        if( !player || !sServerFacade.IsAlive(player) || player == bot)
            continue;

        float threat = sServerFacade.GetThreatManager(target).getThreat(player);
        if (maxThreat < threat)
            maxThreat = threat;
    }

    if (maxThreat <= 0)
        return 0;

    return botThreat * 100 / maxThreat;
}
