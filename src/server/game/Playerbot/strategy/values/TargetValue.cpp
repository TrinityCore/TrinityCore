#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TargetValue.h"

using namespace ai;

Unit* TargetValue::FindTarget(FindTargetStrategy* strategy)
{
    list<ObjectGuid> attackers = ai->GetAiObjectContext()->GetValue<list<ObjectGuid> >("attackers")->Get();
    for (list<ObjectGuid>::iterator i = attackers.begin(); i != attackers.end(); ++i)
    {
        Unit* unit = ai->GetUnit(*i);
        if (!unit)
            continue;

        ThreatManager &threatManager = unit->getThreatManager();
        strategy->CheckAttacker(unit, &threatManager);
    }

    return strategy->GetResult();
}

void FindTargetStrategy::GetPlayerCount(Unit* creature, int* tankCount, int* dpsCount)
{
    Player* bot = ai->GetBot();
    if (tankCountCache.find(creature) != tankCountCache.end())
    {
        *tankCount = tankCountCache[creature];
        *dpsCount = dpsCountCache[creature];
        return;
    }

    *tankCount = 0;
    *dpsCount = 0;

    for (HostileReference *ref = creature->getHostileRefManager().getFirst(); ref; ref = ref->next())
    {
        ThreatManager *threatManager = ref->GetSource();
        Unit *attacker = threatManager->GetOwner();
        Unit *victim = attacker->GetVictim();
        Player *player = dynamic_cast<Player*>(victim);

        if (!player)
            continue;

        if (ai->IsTank(player))
            (*tankCount)++;
        else
            (*dpsCount)++;
    }

    tankCountCache[creature] = *tankCount;
    dpsCountCache[creature] = *dpsCount;
}
