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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITY_CREATUREAI_H
#define TRINITY_CREATUREAI_H

#include "Common.h"
#include "Platform/Define.h"
#include "Policies/Singleton.h"
#include "Dynamic/ObjectRegistry.h"
#include "Dynamic/FactoryHolder.h"

class WorldObject;
class Unit;
class Creature;
class Player;
struct SpellEntry;

#define TIME_INTERVAL_LOOK   5000
#define VISIBILITY_RANGE    10000

//Spell targets used by SelectSpell
enum SelectTargetType
{
    SELECT_TARGET_DONTCARE = 0,                             //All target types allowed

    SELECT_TARGET_SELF,                                     //Only Self casting

    SELECT_TARGET_SINGLE_ENEMY,                             //Only Single Enemy
    SELECT_TARGET_AOE_ENEMY,                                //Only AoE Enemy
    SELECT_TARGET_ANY_ENEMY,                                //AoE or Single Enemy

    SELECT_TARGET_SINGLE_FRIEND,                            //Only Single Friend
    SELECT_TARGET_AOE_FRIEND,                               //Only AoE Friend
    SELECT_TARGET_ANY_FRIEND,                               //AoE or Single Friend
};

//Spell Effects used by SelectSpell
enum SelectEffect
{
    SELECT_EFFECT_DONTCARE = 0,                             //All spell effects allowed
    SELECT_EFFECT_DAMAGE,                                   //Spell does damage
    SELECT_EFFECT_HEALING,                                  //Spell does healing
    SELECT_EFFECT_AURA,                                     //Spell applies an aura
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

enum SCEquip
{
    EQUIP_NO_CHANGE = -1,
    EQUIP_UNEQUIP   = 0
};

enum AITarget
{
    AITARGET_SELF,
    AITARGET_VICTIM,
    AITARGET_ENEMY,
    AITARGET_ALLY,
    AITARGET_BUFF,
    AITARGET_DEBUFF,
};

enum AICondition
{
    AICOND_AGGRO,
    AICOND_COMBAT,
    AICOND_DIE,
};

#define AI_DEFAULT_COOLDOWN 5000

struct AISpellInfoType
{
    AISpellInfoType() : target(AITARGET_SELF), condition(AICOND_COMBAT), cooldown(AI_DEFAULT_COOLDOWN) {}
    AITarget target;
    AICondition condition;
    uint32 cooldown;
};

extern AISpellInfoType *AISpellInfo;

class EventMap : private std::map<uint32, uint32>
{
    private:
        uint32 m_time, m_phase;
    public:
        explicit EventMap() : m_phase(0), m_time(0) {}

        void Reset() { clear(); m_time = 0; m_phase = 0; }

        void Update(uint32 time) { m_time += time; }

        void SetPhase(uint32 phase)
        {
            if(phase && phase < 9)
                m_phase = (1 << (phase + 24));
        }

        void ScheduleEvent(uint32 eventId, uint32 time, uint32 gcd = 0, uint32 phase = 0)
        {
            time += m_time;
            if(gcd && gcd < 9)
                eventId |= (1 << (gcd + 16));
            if(phase && phase < 9)
                eventId |= (1 << (phase + 24));
            iterator itr = find(time);
            while(itr != end())
            {
                ++time;
                itr = find(time);
            }
            insert(std::make_pair(time, eventId));
        }

        uint32 ExecuteEvent()
        {
            while(!empty())
            {
                if(begin()->first > m_time)
                    return 0;
                else if(m_phase && (begin()->second & 0xFF000000) && !(begin()->second & m_phase))
                    erase(begin());
                else
                {
                    uint32 eventId = (begin()->second & 0x0000FFFF);
                    erase(begin());
                    return eventId;
                }
            }
            return 0;
        }

        void DelayEvents(uint32 time, uint32 gcd)
        {
            time += m_time;
            gcd = (1 << (gcd + 16));
            for(iterator itr = begin(); itr != end();)
            {
                if(itr->first >= time)
                    break;
                if(itr->second & gcd)
                {
                    ScheduleEvent(time, itr->second);
                    erase(itr++);
                }
                else
                    ++itr;
            }
        }
};

class TRINITY_DLL_SPEC UnitAI
{
    protected:
        Unit* const me;
    public:
        explicit UnitAI(Unit *u) : me(u) {}
        virtual void AttackStart(Unit *);
        virtual void UpdateAI(const uint32 diff) = 0;

        virtual void InitializeAI() { Reset(); }

        virtual void Reset() {};

        // Called when unit is charmed
        virtual void OnCharmed(bool apply) = 0;

        // Pass parameters between AI
        virtual void DoAction(const int32 param) {}

        //Do melee swing of current victim if in rnage and ready and not casting
        void DoMeleeAttackIfReady();
};

class TRINITY_DLL_SPEC PlayerAI : public UnitAI
{
    protected:
        Player* const me;
    public:
        explicit PlayerAI(Player *p) : UnitAI((Unit*)p), me(p) {}

        void OnCharmed(bool apply);
};

class TRINITY_DLL_SPEC SimpleCharmedAI : public PlayerAI
{
    public:
        void UpdateAI(const uint32 diff);
};

class TRINITY_DLL_SPEC CreatureAI : public UnitAI
{
    protected:
        Creature* const me;
        Creature* const m_creature;

        bool UpdateVictim();
    public:
        explicit CreatureAI(Creature *c) : UnitAI((Unit*)c), me(c), m_creature(c) {}

        virtual ~CreatureAI() {}

        ///== Reactions At =================================

        // Called if IsVisible(Unit *who) is true at each *who move, reaction at visibility zone enter
        virtual void MoveInLineOfSight(Unit *);

        // Called for reaction at stopping attack at no attackers or targets
        virtual void EnterEvadeMode();

        // Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
        virtual void EnterCombat(Unit* /*enemy*/) {}

        // Called at any Damage from any attacker (before damage apply)
        // Note: it for recalculation damage or special reaction at damage
        // for attack reaction use AttackedBy called for not DOT damage in Unit::DealDamage also
        virtual void DamageTaken(Unit *done_by, uint32 & /*damage*/) {}

        // Called when the creature is killed
        virtual void JustDied(Unit *) {}

        // Called when the creature kills a unit
        virtual void KilledUnit(Unit *) {}

        // Called when the creature summon successfully other creature
        virtual void JustSummoned(Creature* ) {}

        virtual void SummonedCreatureDespawn(Creature* /*unit*/) {}

        // Called when hit by a spell
        virtual void SpellHit(Unit*, const SpellEntry*) {}

        // Called when spell hits a target
        virtual void SpellHitTarget(Unit* target, const SpellEntry*) {}

        // Called when the creature is target of hostile action: swing, hostile spell landed, fear/etc)
        //virtual void AttackedBy(Unit* attacker);

        // Called when creature is spawned or respawned (for reseting variables)
        virtual void JustRespawned() {}

        // Called at waypoint reached or point movement finished
        virtual void MovementInform(uint32 /*MovementType*/, uint32 /*Data*/) {}

        void OnCharmed(bool apply);

        //virtual void SpellClick(Player *player) {}

        // Called at reaching home after evade
        virtual void JustReachedHome() {}

        void DoZoneInCombat(Creature* pUnit = NULL);

        // Called at text emote receive from player 
        virtual void ReceiveEmote(Player* pPlayer, uint32 text_emote) {}

        ///== Triggered Actions Requested ==================

        // Called when creature attack expected (if creature can and no have current victim)
        // Note: for reaction at hostile action must be called AttackedBy function.
        //virtual void AttackStart(Unit *) {}

        // Called at World update tick
        //virtual void UpdateAI(const uint32 diff ) {}

        ///== State checks =================================

        // Is unit visible for MoveInLineOfSight
        //virtual bool IsVisible(Unit *) const { return false; }

        // Called when victim entered water and creature can not enter water
        virtual bool canReachByRangeAttack(Unit*) { return false; }

        ///== Fields =======================================

        // Pointer to controlled by AI creature
        //Creature* const m_creature;

        Unit* SelectTarget(SelectAggroTarget target, uint32 position = 0, float dist = 0, bool playerOnly = false, int32 aura = 0);
        void SelectTargetList(std::list<Unit*> &targetList, uint32 num, SelectAggroTarget target, float dist = 0, bool playerOnly = false, int32 aura = 0);
};

struct SelectableAI : public FactoryHolder<CreatureAI>, public Permissible<Creature>
{

    SelectableAI(const char *id) : FactoryHolder<CreatureAI>(id) {}
};

template<class REAL_AI>
struct CreatureAIFactory : public SelectableAI
{
    CreatureAIFactory(const char *name) : SelectableAI(name) {}

    CreatureAI* Create(void *) const;

    int Permit(const Creature *c) const { return REAL_AI::Permissible(c); }
};

enum Permitions
{
    PERMIT_BASE_NO                 = -1,
    PERMIT_BASE_IDLE               = 1,
    PERMIT_BASE_REACTIVE           = 100,
    PERMIT_BASE_PROACTIVE          = 200,
    PERMIT_BASE_FACTION_SPECIFIC   = 400,
    PERMIT_BASE_SPECIAL            = 800
};

typedef FactoryHolder<CreatureAI> CreatureAICreator;
typedef FactoryHolder<CreatureAI>::FactoryHolderRegistry CreatureAIRegistry;
typedef FactoryHolder<CreatureAI>::FactoryHolderRepository CreatureAIRepository;
#endif

