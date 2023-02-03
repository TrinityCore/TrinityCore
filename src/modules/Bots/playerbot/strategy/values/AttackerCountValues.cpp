#include "botpch.h"
#include "../../playerbot.h"
#include "AttackerCountValues.h"
#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"

using namespace ai;

uint8 MyAttackerCountValue::Calculate()
{
    return bot->getAttackers().size();
}

bool HasAggroValue::Calculate()
{
    Unit* target = GetTarget();
    if (!target)
        return true;

    HostileReference *ref = sServerFacade.GetHostileRefManager(bot).getFirst();
    if (!ref)
        return true; // simulate as target is not atacking anybody yet

    while( ref )
    {
        ThreatManager *threatManager = ref->getSource();
        Unit *attacker = threatManager->getOwner();
        Unit *victim = attacker->getVictim();
        if (victim == bot && target == attacker)
            return true;
        ref = ref->next();
    }
    return false;
}

uint8 AttackerCountValue::Calculate()
{
    int count = 0;
    float range = sPlayerbotAIConfig.sightDistance;

    list<ObjectGuid> attackers = context->GetValue<list<ObjectGuid> >("attackers")->Get();
    for (list<ObjectGuid>::iterator i = attackers.begin(); i != attackers.end(); i++)
    {
        Unit* unit = ai->GetUnit(*i);
        if (!unit || !sServerFacade.IsAlive(unit))
            continue;

        float distance = bot->GetDistance(unit);
        if (distance <= range)
            count++;
    }

    return count;
}

uint8 BalancePercentValue::Calculate()
{
    float playerLevel = 0,
        attackerLevel = 0;

    Group* group = bot->GetGroup();
    if (group)
    {
        Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
        for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
        {
            Player *player = sObjectMgr.GetPlayer(itr->guid);
            if( !player || !sServerFacade.IsAlive(player))
                continue;

            playerLevel += player->getLevel();
        }
    }

    list<ObjectGuid> v = context->GetValue<list<ObjectGuid> >("attackers")->Get();

    for (list<ObjectGuid>::iterator i = v.begin(); i!=v.end(); i++)
    {
        Creature* creature = ai->GetCreature((*i));
        if (!creature || !sServerFacade.IsAlive(creature))
            continue;

        uint32 level = creature->getLevel();

        switch (creature->GetCreatureInfo()->Rank) {
        case CREATURE_ELITE_RARE:
            level *= 2;
            break;
        case CREATURE_ELITE_ELITE:
            level *= 3;
            break;
        case CREATURE_ELITE_RAREELITE:
            level *= 3;
            break;
        case CREATURE_ELITE_WORLDBOSS:
            level *= 5;
            break;
        }
        attackerLevel += level;
    }

    if (!attackerLevel)
        return 100;

    float percent = playerLevel * 100 / attackerLevel;
    return percent <= 200 ? (uint8)percent : 200;
}

