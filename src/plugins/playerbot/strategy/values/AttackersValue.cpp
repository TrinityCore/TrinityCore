#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "AttackersValue.h"

#include "../../../../server/game/Entities/Pet/Pet.h"

using namespace ai;

list<ObjectGuid> AttackersValue::Calculate()
{
    set<Unit*> targets;

    AddAttackersOf(bot, targets);

    Group* group = bot->GetGroup();
    if (group)
        AddAttackersOf(group, targets);

    RemoveNonThreating(targets);

    list<ObjectGuid> result;
	for (set<Unit*>::iterator i = targets.begin(); i != targets.end(); i++)
		result.push_back((*i)->GetGUID());

    if (bot->duel && bot->duel->opponent)
        result.push_back(bot->duel->opponent->GetGUID());

	return result;
}

void AttackersValue::AddAttackersOf(Group* group, set<Unit*>& targets)
{
    Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
    for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
    {
        Player *member = sObjectMgr->GetPlayerByLowGUID(itr->guid);
        if (!member || !member->IsAlive() || member == bot)
            continue;

        if (member->IsBeingTeleported())
            return;

        AddAttackersOf(member, targets);

        Pet* pet = member->GetPet();
        if (pet)
            AddAttackersOf(pet, targets);
    }
}

void AttackersValue::AddAttackersOf(Unit* unit, set<Unit*>& targets)
{
    HostileRefManager& refManager = unit->getHostileRefManager();
    HostileReference *ref = refManager.getFirst();
    if (!ref)
        return;

    while( ref )
    {
        ThreatManager *threatManager = ref->GetSource();
        Unit *attacker = threatManager->GetOwner();
        Unit *victim = attacker->GetVictim();
        if (victim == unit)
            targets.insert(attacker);
        ref = ref->next();
    }
}

void AttackersValue::RemoveNonThreating(set<Unit*>& targets)
{
    for(set<Unit *>::iterator tIter = targets.begin(); tIter != targets.end();)
    {
        Unit* unit = *tIter;
        if(!bot->IsWithinLOSInMap(unit) || bot->GetMapId() != unit->GetMapId() || !hasRealThreat(unit))
        {
            set<Unit *>::iterator tIter2 = tIter;
            ++tIter;
            targets.erase(tIter2);
        }
        else
            ++tIter;
    }
}

bool AttackersValue::hasRealThreat(Unit *attacker)
{
    return attacker &&
        attacker->IsInWorld() &&
        attacker->IsAlive() &&
        !attacker->IsPolymorphed() &&
        !attacker->isInRoots() &&
        !attacker->IsFriendlyTo(bot) &&
        (attacker->getThreatManager().getCurrentVictim() || dynamic_cast<Player*>(attacker));
}
