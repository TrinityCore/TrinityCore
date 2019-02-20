#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PartyMemberValue.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;
using namespace std;

Unit* PartyMemberValue::FindPartyMember(list<Player*>* party, FindPlayerPredicate &predicate)
{
    for (list<Player*>::iterator i = party->begin(); i != party->end(); ++i)
    {
        Player* player = *i;

        if (!player)
            continue;

        if (Check(player) && predicate.Check(player))
            return player;

        Pet* pet = player->GetPet();
        if (!pet)
            continue;

        Unit* unit = (Unit*)pet;
        if (unit && Check(unit) && predicate.Check(unit))
            return unit;
    }

    return NULL;
}

Unit* PartyMemberValue::FindPartyMember(FindPlayerPredicate &predicate)
{
    Player* master = GetMaster();
    Group* group = bot->GetGroup();
    if (!group)
        return NULL;

    list<Player*> healers, tanks, others, masters;
    masters.push_back(master);
    for (GroupReference *gref = group->GetFirstMember(); gref; gref = gref->next())
    {
        Player* player = gref->GetSource();

        if (ai->IsHeal(player))
            healers.push_back(player);
        else if (ai->IsTank(player))
            tanks.push_back(player);
        else if (player != master)
            others.push_back(player);
    }

    list<list<Player*>* > lists;
    lists.push_back(&healers);
    lists.push_back(&tanks);
    lists.push_back(&masters);
    lists.push_back(&others);

    for (list<list<Player*>* >::iterator i = lists.begin(); i != lists.end(); ++i)
    {
        list<Player*>* party = *i;
        Unit* target = FindPartyMember(party, predicate);
        if (target)
            return target;
    }

    return NULL;
}

bool PartyMemberValue::Check(Unit* player)
{


    return player && player != bot && player->GetMapId() == bot->GetMapId() &&
        bot->GetDistance(player) < sPlayerbotAIConfig.spellDistance &&
        bot->IsWithinLOS(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
}

bool PartyMemberValue::IsTargetOfSpellCast(Player* target, SpellEntryPredicate &predicate)
{

    Group* group = bot->GetGroup();
    ObjectGuid targetGuid = target ? target->GetGUID() : bot->GetGUID();
    ObjectGuid corpseGuid = target && target->GetCorpse() ? target->GetCorpse()->GetGUID() : ObjectGuid();

    for (GroupReference *gref = group->GetFirstMember(); gref; gref = gref->next())
    {
        Player* player = gref->GetSource();
        if (player == bot)
            continue;

        if (player->IsNonMeleeSpellCast(true))
        {
            for (int type = CURRENT_GENERIC_SPELL; type < CURRENT_MAX_SPELL; type++) {
                Spell* spell = player->GetCurrentSpell((CurrentSpellTypes)type);
                if (spell && predicate.Check(spell->m_spellInfo)) {
                    ObjectGuid unitTarget = spell->m_targets.GetUnitTargetGUID();
                    if (unitTarget == targetGuid)
                        return true;

                    ObjectGuid corpseTarget = spell->m_targets.GetCorpseTargetGUID();
                    if (corpseTarget == corpseGuid)
                        return true;
                }
            }
        }
    }

    return false;
}
