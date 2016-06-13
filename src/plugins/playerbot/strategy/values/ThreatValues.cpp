#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ThreatValues.h"

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
            if (!unit || !unit->IsAlive())
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

    if (dynamic_cast<Player*>(target))
        return 0;

    Group* group = bot->GetGroup();
    if (!group)
        return 0;

    float botThreat = target->getThreatManager().getThreat(bot);
    float maxThreat = 0;

    Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
    for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
    {
        Player *player = sObjectMgr->GetPlayerByLowGUID(itr->guid);
        if( !player || !player->IsAlive() || player == bot)
            continue;

        float threat = target->getThreatManager().getThreat(player);
        if (maxThreat < threat)
            maxThreat = threat;
    }

    if (maxThreat <= 0)
        return 0;

    return botThreat * 100 / maxThreat;
}
