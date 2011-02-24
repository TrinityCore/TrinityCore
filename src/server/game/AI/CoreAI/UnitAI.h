/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_UNITAI_H
#define TRINITY_UNITAI_H

#include "Define.h"
#include <list>
#include "Unit.h"

class Unit;
class Player;
struct AISpellInfoType;

// Default script texts
enum GeneralScriptTexts
{
    DEFAULT_TEXT                = -1000000,
    EMOTE_GENERIC_FRENZY_KILL   = -1000001,
    EMOTE_GENERIC_FRENZY        = -1000002,
    EMOTE_GENERIC_ENRAGED       = -1000003,
    EMOTE_GENERIC_BERSERK       = -1000004,
    EMOTE_GENERIC_BERSERK_RAID  = -1000005, // RaidBossEmote version of the previous one
};

//Selection method used by SelectTarget
enum SelectAggroTarget
{
    SELECT_TARGET_RANDOM = 0,                               //Just selects a random target
    SELECT_TARGET_TOPAGGRO,                                 //Selects targes from top aggro to bottom
    SELECT_TARGET_BOTTOMAGGRO,                              //Selects targets from bottom aggro to top
    SELECT_TARGET_NEAREST,
    SELECT_TARGET_FARTHEST,
};

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
                if (pTarget->HasAura(-m_aura))
                    return false;
            }
        }

        return true;
    }
};

class UnitAI
{
    protected:
        Unit * const me;
    public:
        explicit UnitAI(Unit *u) : me(u) {}
        virtual ~UnitAI() {}

        virtual bool CanAIAttack(const Unit * /*who*/) const { return true; }
        virtual void AttackStart(Unit *);
        virtual void UpdateAI(const uint32 diff) = 0;

        virtual void InitializeAI() { if (!me->isDead()) Reset(); }

        virtual void Reset() {};

        // Called when unit is charmed
        virtual void OnCharmed(bool apply) = 0;

        // Pass parameters between AI
        virtual void DoAction(const int32 /*param*/ = 0) {}
        virtual uint32 GetData(uint32 /*id = 0*/) { return 0; }
        virtual void SetData(uint32 /*id*/, uint32 /*value*/) {}
        virtual void SetGUID(const uint64 &/*guid*/, int32 /*id*/ = 0) {}
        virtual uint64 GetGUID(int32 /*id*/ = 0) { return 0; }

        Unit* SelectTarget(SelectAggroTarget targetType, uint32 position = 0, float dist = 0.0f, bool playerOnly = false, int32 aura = 0);
        // Select the targets satifying the predicate.
        // predicate shall extend std::unary_function<Unit *, bool>
        template<class PREDICATE> Unit* SelectTarget(SelectAggroTarget targetType, uint32 position, PREDICATE predicate)
        {
            const std::list<HostileReference *> &threatlist = me->getThreatManager().getThreatList();
            std::list<Unit*> targetList;

            if (position >= threatlist.size())
                return NULL;

            for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
            {
                HostileReference* ref = (*itr);
                if (predicate(ref->getTarget()))
                    targetList.push_back(ref->getTarget());
            }

            if (position >= targetList.size())
                return NULL;

            if (targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
                targetList.sort(Trinity::ObjectDistanceOrderPred(me));

            switch(targetType)
            {
                case SELECT_TARGET_NEAREST:
                case SELECT_TARGET_TOPAGGRO:
                {
                    std::list<Unit*>::iterator itr = targetList.begin();
                    advance(itr, position);
                    return *itr;
                }
                break;

                case SELECT_TARGET_FARTHEST:
                case SELECT_TARGET_BOTTOMAGGRO:
                {
                    std::list<Unit*>::reverse_iterator ritr = targetList.rbegin();
                    advance(ritr, position);
                    return *ritr;
                }
                break;

                case SELECT_TARGET_RANDOM:
                {
                    std::list<Unit*>::iterator itr = targetList.begin();
                    advance(itr, urand(position, targetList.size()-1));
                    return *itr;
                }
                break;
            }

            return NULL;
        }

        void SelectTargetList(std::list<Unit*> &targetList, uint32 num, SelectAggroTarget targetType, float dist = 0.0f, bool playerOnly = false, int32 aura = 0);
        // Select the targets satifying the predicate.
        // predicate shall extend std::unary_function<Unit *, bool>
        template<class PREDICATE> void SelectTargetList(std::list<Unit*> &targetList, PREDICATE predicate, uint32 maxTargets, SelectAggroTarget targetType)
        {
            std::list<HostileReference *> const &threatlist = me->getThreatManager().getThreatList();
            std::list<HostileReference*>::const_iterator itr;

            for (itr = threatlist.begin(); itr != threatlist.end(); ++itr)
            {
                HostileReference* ref = (*itr);
                if (predicate(ref->getTarget()))
                    targetList.push_back(ref->getTarget());
            }

            if (targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
                targetList.sort(Trinity::ObjectDistanceOrderPred(me));

            switch(targetType)
            {
                case SELECT_TARGET_NEAREST:
                case SELECT_TARGET_TOPAGGRO:
                {
                    // Already sorted
                    if (!maxTargets || maxTargets >= targetList.size())    // Do not filter
                        return;     

                    std::list<Unit*>::iterator itr = targetList.begin();
                    advance(itr, maxTargets);
                    for (; itr != targetList.end();)
                        targetList.erase(itr++);        // Filter out any element more than maxTargets
                }
                break;

                case SELECT_TARGET_FARTHEST:
                case SELECT_TARGET_BOTTOMAGGRO:
                {
                    if (maxTargets >= targetList.size())                 // Do not filter
                        return;

                    // Sort (reverse)
                    targetList.reverse();
                    std::list<Unit*>::iterator itr = targetList.begin();
                    for (uint32 i = 0; i < maxTargets; ++i)
                        targetList.pop_back();          // Filter out any element more than maxTarget
                }
                break;

                case SELECT_TARGET_RANDOM:
                {
                    while (maxTargets < targetList.size())
                    {
                        std::list<Unit*>::iterator itr = targetList.begin();
                        advance(itr, urand(0, targetList.size()-1));
                        targetList.erase(itr);
                    }
                }
                break;
            }
        }

        // Called at any Damage to any victim (before damage apply)
        virtual void DamageDealt(Unit* /*victim*/, uint32& /*damage*/, DamageEffectType /*damageType*/) { }

        // Called at any Damage from any attacker (before damage apply)
        // Note: it for recalculation damage or special reaction at damage
        // for attack reaction use AttackedBy called for not DOT damage in Unit::DealDamage also
        virtual void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) {}

        // Called when the creature receives heal
        virtual void HealReceived(Unit* /*done_by*/, uint32& /*addhealth*/) {}

        // Called when the unit heals
        virtual void HealDone(Unit* /*done_to*/, uint32& /*addhealth*/) {}

        void AttackStartCaster(Unit *victim, float dist);

        void DoAddAuraToAllHostilePlayers(uint32 spellid);
        void DoCast(uint32 spellId);
        void DoCast(Unit* victim, uint32 spellId, bool triggered = false);
        void DoCastToAllHostilePlayers(uint32 spellid, bool triggered = false);
        void DoCastVictim(uint32 spellId, bool triggered = false);
        void DoCastAOE(uint32 spellId, bool triggered = false);

        float DoGetSpellMaxRange(uint32 spellId, bool positive = false);

        void DoMeleeAttackIfReady();
        bool DoSpellAttackIfReady(uint32 spell);

        static AISpellInfoType *AISpellInfo;
        static void FillAISpellInfo();

        virtual void sGossipHello(Player* /*player*/) {}
        virtual void sGossipSelect(Player* /*player*/, uint32 /*sender*/, uint32 /*action*/) {}
        virtual void sGossipSelectCode(Player* /*player*/, uint32 /*sender*/, uint32 /*action*/, const char* /*code*/) {}
        virtual void sQuestAccept(Player* /*player*/, Quest const* /*quest*/) {}
        virtual void sQuestSelect(Player* /*player*/, Quest const* /*quest*/) {}
        virtual void sQuestComplete(Player* /*player*/, Quest const* /*quest*/) {}
        virtual void sQuestReward(Player* /*player*/, Quest const* /*quest*/, uint32 /*opt*/) {}
        virtual bool sOnDummyEffect(Unit* /*caster*/, uint32 /*spellId*/, SpellEffIndex /*effIndex*/) { return false; }
};

class PlayerAI : public UnitAI
{
    protected:
        Player* const me;
    public:
        explicit PlayerAI(Player *p) : UnitAI((Unit*)p), me(p) {}

        void OnCharmed(bool apply);
};

class SimpleCharmedAI : public PlayerAI
{
    public:
        void UpdateAI(const uint32 diff);
        SimpleCharmedAI(Player *p): PlayerAI(p) {}
};

#endif
