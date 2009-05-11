/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "Creature.h"
#include "World.h"
#include "SpellMgr.h"

//Disable CreatureAI when charmed
void CreatureAI::OnCharmed(bool apply)
{
    //me->IsAIEnabled = !apply;*/
    me->NeedChangeAI = true;
    me->IsAIEnabled = false;
}

AISpellInfoType * CreatureAI::AISpellInfo;

void CreatureAI::DoZoneInCombat(Creature* creature)
{
    if (!creature)
        creature = me;

    Map *map = creature->GetMap();
    if (!map->IsDungeon())                                  //use IsDungeon instead of Instanceable, in case battlegrounds will be instantiated
    {
        sLog.outError("DoZoneInCombat call for map that isn't an instance (creature entry = %d)", creature->GetTypeId() == TYPEID_UNIT ? ((Creature*)creature)->GetEntry() : 0);
        return;
    }

    if(!creature->getVictim())
    {
        if(Unit *target = creature->SelectNearestTarget())
            creature->AI()->AttackStart(target);
        else if(creature->isSummon())
        {
            if(Unit *summoner = ((TempSummon*)creature)->GetSummoner())
            {
                if(summoner->getVictim()
                    && (creature->IsFriendlyTo(summoner) || creature->IsHostileTo(summoner->getVictim())))
                    creature->AI()->AttackStart(summoner->getVictim());
            }
        }
    }

    if (!creature->CanHaveThreatList() || !creature->getVictim())
    {
        sLog.outError("DoZoneInCombat called for creature that either cannot have threat list or has empty threat list (creature entry = %d)", creature->GetTypeId() == TYPEID_UNIT ? ((Creature*)creature)->GetEntry() : 0);
        return;
    }

    Map::PlayerList const &PlayerList = map->GetPlayers();
    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
    {
        if (Player* i_pl = i->getSource())
            if (i_pl->isAlive())
            {
                creature->SetInCombatWith(i_pl);
                i_pl->SetInCombatWith(creature);
                creature->AddThreat(i_pl, 0.0f);
            }
    }
}

void CreatureAI::MoveInLineOfSight(Unit *who)
{
    if(me->getVictim())
        return;

    if(me->canStartAttack(who))
        AttackStart(who);
    else if(who->getVictim() && me->IsFriendlyTo(who)
        && me->IsWithinDistInMap(who, sWorld.getConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS))
        && me->canAttack(who->getVictim()))
        AttackStart(who->getVictim());
}

bool CreatureAI::UpdateVictim()
{
    if(!me->isInCombat())
        return false;
    if(Unit *victim = me->SelectVictim())
        AttackStart(victim);
    return me->getVictim();
}

void CreatureAI::EnterEvadeMode()
{
    me->RemoveAllAuras();
    me->DeleteThreatList();
    me->CombatStop();
    me->LoadCreaturesAddon();
    me->SetLootRecipient(NULL);

    if(me->isAlive())
        me->GetMotionMaster()->MoveTargetedHome();
}

inline bool SelectTargetHelper(const Unit * me, const Unit * target, const bool &playerOnly, const float &dist, const int32 &aura)
{
    if(playerOnly && target->GetTypeId() != TYPEID_PLAYER)
        return false;

    if(dist && !me->IsWithinCombatRange(target, dist))
        return false;

    if(aura)
    {
        if(aura > 0)
        {
            if(!target->HasAura(aura))
                return false;
        }
        else
        {
            if(target->HasAura(aura))
                return false;
        }
    }

    return true;
}

struct TargetDistanceOrder : public std::binary_function<const Unit *, const Unit *, bool>
{
    const Unit * me;
    TargetDistanceOrder(const Unit* Target) : me(Target) {};
    // functor for operator ">"
    bool operator()(const Unit * _Left, const Unit * _Right) const
    {
        return (me->GetDistanceSq(_Left) < me->GetDistanceSq(_Right));
    }
};

Unit* CreatureAI::SelectTarget(SelectAggroTarget targetType, uint32 position, float dist, bool playerOnly, int32 aura)
{
    if(targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
    {
        std::list<HostilReference*> &m_threatlist = me->getThreatManager().getThreatList();
        if(position >= m_threatlist.size())
            return NULL;

        std::list<Unit*> targetList;
        for(std::list<HostilReference*>::iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
            if(SelectTargetHelper(me, (*itr)->getTarget(), playerOnly, dist, aura))
                targetList.push_back((*itr)->getTarget());

        if(position >= targetList.size())
            return NULL;

        targetList.sort(TargetDistanceOrder(m_creature));

        if(targetType == SELECT_TARGET_NEAREST)
        {
            std::list<Unit*>::iterator i = targetList.begin();
            advance(i, position);
            return *i;
        }
        else
        {
            std::list<Unit*>::reverse_iterator i = targetList.rbegin();
            advance(i, position);
            return *i;
        }
    }
    else
    {
        std::list<HostilReference*> m_threatlist = me->getThreatManager().getThreatList();
        std::list<HostilReference*>::iterator i;
        while(position < m_threatlist.size())
        {
            if(targetType == SELECT_TARGET_BOTTOMAGGRO)
            {
                i = m_threatlist.end();
                advance(i, - (int32)position - 1);
            }
            else
            {
                i = m_threatlist.begin();
                if(targetType == SELECT_TARGET_TOPAGGRO)
                    advance(i, position);
                else // random
                    advance(i, position + rand()%(m_threatlist.size() - position));
            }

            if(SelectTargetHelper(me, (*i)->getTarget(), playerOnly, dist, aura))
                return (*i)->getTarget();
            else
                m_threatlist.erase(i);
        }
    }

    return NULL;
}

void CreatureAI::SelectTargetList(std::list<Unit*> &targetList, uint32 num, SelectAggroTarget targetType, float dist, bool playerOnly, int32 aura)
{
    if(targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
    {
        std::list<HostilReference*> &m_threatlist = m_creature->getThreatManager().getThreatList();
        if(m_threatlist.empty())
            return;

        for(std::list<HostilReference*>::iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
            if(SelectTargetHelper(me, (*itr)->getTarget(), playerOnly, dist, aura))
                targetList.push_back((*itr)->getTarget());

        targetList.sort(TargetDistanceOrder(me));
        targetList.resize(num);
        if(targetType == SELECT_TARGET_FARTHEST)
            targetList.reverse();
    }
    else
    {
        std::list<HostilReference*> m_threatlist = me->getThreatManager().getThreatList();
        std::list<HostilReference*>::iterator i;
        while(!m_threatlist.empty() && num)
        {
            if(targetType == SELECT_TARGET_BOTTOMAGGRO)
            {
                i = m_threatlist.end();
                --i;
            }
            else
            {
                i = m_threatlist.begin();
                if(targetType == SELECT_TARGET_RANDOM)
                    advance(i, rand()%m_threatlist.size());
            }

            if(SelectTargetHelper(me, (*i)->getTarget(), playerOnly, dist, aura))
            {
                targetList.push_back((*i)->getTarget());
                --num;
            }
            m_threatlist.erase(i);
        }
    }
}

void CreatureAI::FillAISpellInfo()
{
    AISpellInfo = new AISpellInfoType[GetSpellStore()->GetNumRows()];

    AISpellInfoType *AIInfo = AISpellInfo;
    const SpellEntry * spellInfo;

    for(uint32 i = 0; i < GetSpellStore()->GetNumRows(); ++i, ++AIInfo)
    {
        spellInfo = GetSpellStore()->LookupEntry(i);
        if(!spellInfo)
            continue;

        if(spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_DEAD)
            AIInfo->condition = AICOND_DIE;
        else if(IsPassiveSpell(i) || GetSpellDuration(spellInfo) == -1)
            AIInfo->condition = AICOND_AGGRO;
        else
            AIInfo->condition = AICOND_COMBAT;

        if(AIInfo->cooldown < spellInfo->RecoveryTime)
            AIInfo->cooldown = spellInfo->RecoveryTime;

        for(uint32 j = 0; j < 3; ++j)
        {
            if(spellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_ENEMY
                || spellInfo->EffectImplicitTargetA[j] == TARGET_DST_TARGET_ENEMY)
            {
                if(AIInfo->target < AITARGET_VICTIM)
                    AIInfo->target = AITARGET_VICTIM;
            }

            if(spellInfo->Effect[j] == SPELL_EFFECT_APPLY_AURA)
            {
                if(spellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_ENEMY)
                {
                    if(AIInfo->target < AITARGET_DEBUFF)
                        AIInfo->target = AITARGET_DEBUFF;
                }
                else if(IsPositiveSpell(i))
                {
                    if(AIInfo->target < AITARGET_BUFF)
                        AIInfo->target = AITARGET_BUFF;
                }
            }
        }
    }
}

/*void CreatureAI::AttackedBy( Unit* attacker )
{
    if(!m_creature->getVictim())
        AttackStart(attacker);
}*/
