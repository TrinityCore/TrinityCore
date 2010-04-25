/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "UnitAI.h"
#include "Player.h"
#include "Creature.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "CreatureAIImpl.h"

void UnitAI::AttackStart(Unit *victim)
{
    if (victim && me->Attack(victim, true))
        me->GetMotionMaster()->MoveChase(victim);
}

void UnitAI::AttackStartCaster(Unit *victim, float dist)
{
    if (victim && me->Attack(victim, false))
        me->GetMotionMaster()->MoveChase(victim, dist);
}

void UnitAI::DoMeleeAttackIfReady()
{
    if (me->hasUnitState(UNIT_STAT_CASTING))
        return;

    //Make sure our attack is ready and we aren't currently casting before checking distance
    if (me->isAttackReady())
    {
        //If we are within range melee the target
        if (me->IsWithinMeleeRange(me->getVictim()))
        {
            me->AttackerStateUpdate(me->getVictim());
            me->resetAttackTimer();
        }
    }
    if (me->haveOffhandWeapon() && me->isAttackReady(OFF_ATTACK))
    {
        //If we are within range melee the target
        if (me->IsWithinMeleeRange(me->getVictim()))
        {
            me->AttackerStateUpdate(me->getVictim(), OFF_ATTACK);
            me->resetAttackTimer(OFF_ATTACK);
        }
    }
}

bool UnitAI::DoSpellAttackIfReady(uint32 spell)
{
    if (me->hasUnitState(UNIT_STAT_CASTING))
        return true;

    if (me->isAttackReady())
    {
        if (me->IsWithinCombatRange(me->getVictim(), GetSpellMaxRange(spell, false)))
        {
            me->CastSpell(me->getVictim(), spell, false);
            me->resetAttackTimer();
        }
        else
            return false;
    }
    return true;
}

// default predicate function to select target based on distance, player and/or aura criteria
struct DefaultTargetSelector : public std::unary_function<Unit *, bool>
{
    const Unit *me;
    float m_dist;
    bool m_playerOnly;
    int32 m_aura;

    // pUnit: the reference unit
    // dist: if 0: ignored, if > 0: maximum distance to the reference unit, if < 0: minimum distance to the reference unit
    // playerOnly: self explaining
    // aura: if 0: ignored, if > 0: the target shall have the aura, if < 0, the target shall NOT have the aura
    DefaultTargetSelector(const Unit *pUnit, float dist, bool playerOnly, int32 aura) : me(pUnit), m_dist(dist), m_playerOnly(playerOnly), m_aura(aura) {}

    bool operator() (const Unit *pTarget)
    {
        if (!me)
            return false;

        if (!pTarget)
            return false;

        if (m_playerOnly && (pTarget->GetTypeId() != TYPEID_PLAYER))
            return false;

        if (m_dist > 0.0f && !me->IsWithinCombatRange(pTarget, m_dist))
            return false;

        if (m_dist < 0.0f && me->IsWithinCombatRange(pTarget, -m_dist))
            return false;

        if (m_aura)
        {
            if (m_aura > 0)
            {
                if (!pTarget->HasAura(m_aura))
                    return false;
            }
            else
            {
                if (pTarget->HasAura(m_aura))
                    return false;
            }
        }

        return true;
    }
};

Unit* UnitAI::SelectTarget(SelectAggroTarget targetType, uint32 position, float dist, bool playerOnly, int32 aura)
{
    return SelectTarget(targetType, position, DefaultTargetSelector(me, dist, playerOnly, aura));
}

void UnitAI::SelectTargetList(std::list<Unit*> &targetList, uint32 num, SelectAggroTarget targetType, float dist, bool playerOnly, int32 aura)
{
    const std::list<HostileReference*> &threatlist = me->getThreatManager().getThreatList();

    if (threatlist.empty())
        return;

    DefaultTargetSelector targetSelector(me, dist,playerOnly, aura);
    for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
        if (targetSelector((*itr)->getTarget()))
            targetList.push_back((*itr)->getTarget());

    if (targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
        targetList.sort(TargetDistanceOrder(me));

    if (targetType == SELECT_TARGET_FARTHEST || targetType == SELECT_TARGET_BOTTOMAGGRO)
        targetList.reverse();

    if (targetList.size() < num)
        return;

    if (targetType == SELECT_TARGET_RANDOM)
    {
        while (num < targetList.size()) {
            std::list<Unit*>::iterator itr = targetList.begin();
            advance(itr, urand(0, targetList.size()-1));
            targetList.erase(itr);
        }
    }
    else
        targetList.resize(num);
}

float UnitAI::DoGetSpellMaxRange(uint32 spellId, bool positive)
{
    return GetSpellMaxRange(spellId, positive);
}

void UnitAI::DoAddAuraToAllHostilePlayers(uint32 spellid)
{
    if (me->isInCombat())
    {
        std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();
        for (std::list<HostileReference*>::iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
        {
            if (Unit *pTemp = Unit::GetUnit(*me,(*itr)->getUnitGuid()))
                if (pTemp->GetTypeId() == TYPEID_PLAYER)
                    me->AddAura(spellid, pTemp);
        }
    }else
        return;
}

void UnitAI::DoCastToAllHostilePlayers(uint32 spellid, bool triggered)
{
    if (me->isInCombat())
    {
        std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();
        for (std::list<HostileReference*>::iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
        {
            if (Unit *pTemp = Unit::GetUnit(*me,(*itr)->getUnitGuid()))
                if (pTemp->GetTypeId() == TYPEID_PLAYER)
                    me->CastSpell(pTemp, spellid, triggered);
        }
    }else
        return;
}

void UnitAI::DoCast(uint32 spellId)
{
    Unit *target = NULL;
    //sLog.outError("aggre %u %u", spellId, (uint32)AISpellInfo[spellId].target);
    switch(AISpellInfo[spellId].target)
    {
        default:
        case AITARGET_SELF:     target = me; break;
        case AITARGET_VICTIM:   target = me->getVictim(); break;
        case AITARGET_ENEMY:
        {
            const SpellEntry * spellInfo = GetSpellStore()->LookupEntry(spellId);
            bool playerOnly = spellInfo->AttributesEx3 & SPELL_ATTR_EX3_PLAYERS_ONLY;
            //float range = GetSpellMaxRange(spellInfo, false);
            target = SelectTarget(SELECT_TARGET_RANDOM, 0, GetSpellMaxRange(spellInfo, false), playerOnly);
            break;
        }
        case AITARGET_ALLY:     target = me; break;
        case AITARGET_BUFF:     target = me; break;
        case AITARGET_DEBUFF:
        {
            const SpellEntry * spellInfo = GetSpellStore()->LookupEntry(spellId);
            bool playerOnly = spellInfo->AttributesEx3 & SPELL_ATTR_EX3_PLAYERS_ONLY;
            float range = GetSpellMaxRange(spellInfo, false);

            DefaultTargetSelector targetSelector(me, range, playerOnly, -(int32)spellId);
            if (!(spellInfo->Attributes & SPELL_ATTR_BREAKABLE_BY_DAMAGE)
                && !(spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_VICTIM)
                && targetSelector(me->getVictim()))
                target = me->getVictim();
            else
                target = SelectTarget(SELECT_TARGET_RANDOM, 0, targetSelector);
            break;
        }
    }

    if (target)
        me->CastSpell(target, spellId, false);
}

#define UPDATE_TARGET(a) {if (AIInfo->target<a) AIInfo->target=a;}

void UnitAI::FillAISpellInfo()
{
    AISpellInfo = new AISpellInfoType[GetSpellStore()->GetNumRows()];

    AISpellInfoType *AIInfo = AISpellInfo;
    const SpellEntry * spellInfo;

    for (uint32 i = 0; i < GetSpellStore()->GetNumRows(); ++i, ++AIInfo)
    {
        spellInfo = GetSpellStore()->LookupEntry(i);
        if (!spellInfo)
            continue;

        if (spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_DEAD)
            AIInfo->condition = AICOND_DIE;
        else if (IsPassiveSpell(i) || GetSpellDuration(spellInfo) == -1)
            AIInfo->condition = AICOND_AGGRO;
        else
            AIInfo->condition = AICOND_COMBAT;

        if (AIInfo->cooldown < spellInfo->RecoveryTime)
            AIInfo->cooldown = spellInfo->RecoveryTime;

        if (!GetSpellMaxRange(spellInfo, false))
            UPDATE_TARGET(AITARGET_SELF)
        else
        {
            for (uint32 j = 0; j < 3; ++j)
            {
                uint32 targetType = spellInfo->EffectImplicitTargetA[j];

                if (targetType == TARGET_UNIT_TARGET_ENEMY
                    || targetType == TARGET_DST_TARGET_ENEMY)
                    UPDATE_TARGET(AITARGET_VICTIM)
                else if (targetType == TARGET_UNIT_AREA_ENEMY_DST)
                    UPDATE_TARGET(AITARGET_ENEMY)

                if (spellInfo->Effect[j] == SPELL_EFFECT_APPLY_AURA)
                {
                    if (targetType == TARGET_UNIT_TARGET_ENEMY)
                        UPDATE_TARGET(AITARGET_DEBUFF)
                    else if (IsPositiveSpell(i))
                        UPDATE_TARGET(AITARGET_BUFF)
                }
            }
        }
        AIInfo->realCooldown = spellInfo->RecoveryTime + spellInfo->StartRecoveryTime;
        SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(spellInfo->rangeIndex);
        if (srange)
            AIInfo->maxRange = srange->maxRangeHostile * 3 / 4;
    }
}

//Enable PlayerAI when charmed
void PlayerAI::OnCharmed(bool apply) { me->IsAIEnabled = apply; }

void SimpleCharmedAI::UpdateAI(const uint32 /*diff*/)
{
  Creature *charmer = me->GetCharmer()->ToCreature();

    //kill self if charm aura has infinite duration
    if (charmer->IsInEvadeMode())
    {
        Unit::AuraEffectList const& auras = me->GetAuraEffectsByType(SPELL_AURA_MOD_CHARM);
        for (Unit::AuraEffectList::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
            if ((*iter)->GetCasterGUID() == charmer->GetGUID() && (*iter)->GetBase()->IsPermanent())
            {
                charmer->Kill(me);
                return;
            }
    }

    if (!charmer->isInCombat())
        me->GetMotionMaster()->MoveFollow(charmer, PET_FOLLOW_DIST, me->GetFollowAngle());

    Unit *target = me->getVictim();
    if (!target || !charmer->canAttack(target))
        AttackStart(charmer->SelectNearestTargetInAttackDistance());
}
