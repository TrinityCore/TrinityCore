/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#ifndef MANGOS_CREATURE_EAI_H
#define MANGOS_CREATURE_EAI_H

#include "Common.h"
#include "CreatureAI.h"
#include "ScriptMgr.h"

class Unit;
class Creature;
class Player;
class WorldObject;

#define EVENT_UPDATE_TIME               500
#define MAX_ACTIONS                     3
#define MAX_PHASE                       32

enum EventAI_Type
{
    EVENT_T_TIMER                   = 0,                    // InitialMin, InitialMax, RepeatMin, RepeatMax
    EVENT_T_TIMER_OOC               = 1,                    // InitialMin, InitialMax, RepeatMin, RepeatMax
    EVENT_T_HP                      = 2,                    // HPMax%, HPMin%, RepeatMin, RepeatMax
    EVENT_T_MANA                    = 3,                    // ManaMax%,ManaMin% RepeatMin, RepeatMax
    EVENT_T_AGGRO                   = 4,                    // NONE
    EVENT_T_KILL                    = 5,                    // RepeatMin, RepeatMax, PlayerOnly
    EVENT_T_DEATH                   = 6,                    // NONE
    EVENT_T_EVADE                   = 7,                    // NONE
    EVENT_T_HIT_BY_SPELL            = 8,                    // SpellID, School, RepeatMin, RepeatMax
    EVENT_T_RANGE                   = 9,                    // MinDist, MaxDist, RepeatMin, RepeatMax
    EVENT_T_OOC_LOS                 = 10,                   // Reaction, MaxRnage, RepeatMin, RepeatMax
    EVENT_T_SPAWNED                 = 11,                   // NONE
    EVENT_T_TARGET_HP               = 12,                   // HPMax%, HPMin%, RepeatMin, RepeatMax
    EVENT_T_TARGET_CASTING          = 13,                   // RepeatMin, RepeatMax
    EVENT_T_FRIENDLY_HP             = 14,                   // HPDeficit, Radius, RepeatMin, RepeatMax
    EVENT_T_FRIENDLY_IS_CC          = 15,                   // DispelType, Radius, RepeatMin, RepeatMax
    EVENT_T_FRIENDLY_MISSING_BUFF   = 16,                   // SpellId, Radius, RepeatMin, RepeatMax
    EVENT_T_SUMMONED_UNIT           = 17,                   // CreatureId, RepeatMin, RepeatMax
    EVENT_T_TARGET_MANA             = 18,                   // ManaMax%, ManaMin%, RepeatMin, RepeatMax
    EVENT_T_QUEST_ACCEPT            = 19,                   // QuestID
    EVENT_T_QUEST_COMPLETE          = 20,                   //
    EVENT_T_REACHED_HOME            = 21,                   // NONE
    EVENT_T_RECEIVE_EMOTE           = 22,                   // EmoteId, Condition, CondValue1, CondValue2
    EVENT_T_AURA                    = 23,                   // Param1 = SpellID, Param2 = Number of time stacked, Param3/4 Repeat Min/Max
    EVENT_T_TARGET_AURA             = 24,                   // Param1 = SpellID, Param2 = Number of time stacked, Param3/4 Repeat Min/Max
    EVENT_T_SUMMONED_JUST_DIED      = 25,                   // CreatureId, RepeatMin, RepeatMax
    EVENT_T_SUMMONED_JUST_DESPAWN   = 26,                   // CreatureId, RepeatMin, RepeatMax
    EVENT_T_MISSING_AURA            = 27,                   // Param1 = SpellID, Param2 = Number of time stacked expected, Param3/4 Repeat Min/Max
    EVENT_T_TARGET_MISSING_AURA     = 28,                   // Param1 = SpellID, Param2 = Number of time stacked expected, Param3/4 Repeat Min/Max
    EVENT_T_MOVEMENT_INFORM         = 29,                   // Param1 = motion type, Param2 = point ID, RepeatMin, RepeatMax
    EVENT_T_LEAVE_COMBAT            = 30,                   // NONE
    EVENT_T_MAP_SCRIPT_EVENT        = 31,                   // Param1 = EventID, Param2 = Data
    EVENT_T_GROUP_MEMBER_DIED       = 32,                   // Param1 = CreatureId, Param2 = IsLeader
    EVENT_T_VICTIM_ROOTED           = 33,                   // RepeatMin, RepeatMax
    EVENT_T_HIT_BY_AURA             = 34,                   // AuraType, Unused, RepeatMin, RepeatMax

    EVENT_T_END,
};

enum EventFlags
{
    EFLAG_REPEATABLE            = 0x01,                     //Event repeats
    EFLAG_RANDOM_ACTION         = 0x02,                     //Event only execute one from existed actions instead each action.
    EFLAG_DEBUG_ONLY            = 0x04,                     //Event only occurs in debug build
    // uint8 field
};

enum SpawnedEventMode
{
    SPAWNED_EVENT_ALWAY = 0,
    SPAWNED_EVENT_MAP   = 1,
    SPAWNED_EVENT_ZONE  = 2
};

enum UnitInLosReaction
{
    ULR_ANY             = 0,
    ULR_HOSTILE         = 1,
    ULR_NON_HOSTILE     = 2
};

struct CreatureEventAI_Event
{
    uint32 event_id;

    uint32 creature_id;

    uint32 condition_id;

    uint32 event_inverse_phase_mask;

    EventAI_Type event_type : 16;
    uint8 event_chance : 8;
    uint8 event_flags  : 8;

    union
    {
        // EVENT_T_TIMER                                    = 0
        // EVENT_T_TIMER_OOC                                = 1
        struct
        {
            uint32 initialMin;
            uint32 initialMax;
            uint32 repeatMin;
            uint32 repeatMax;
        } timer;
        // EVENT_T_HP                                       = 2
        // EVENT_T_MANA                                     = 3
        // EVENT_T_TARGET_HP                                = 12
        // EVENT_T_TARGET_MANA                              = 18
        struct
        {
            uint32 percentMax;
            uint32 percentMin;
            uint32 repeatMin;
            uint32 repeatMax;
        } percent_range;
        // EVENT_T_KILL                                     = 5
        struct
        {
            uint32 repeatMin;
            uint32 repeatMax;
            uint32 playerOnly;
        } kill;
        // EVENT_T_HIT_BY_SPELL                             = 8
        struct
        {
            uint32 spellId;
            uint32 schoolMask;                              // -1 (==0xffffffff) is ok value for full mask, or must be more limited mask like (0 < 1) = 1 for normal/physical school
            uint32 repeatMin;
            uint32 repeatMax;
        } hit_by_spell;
        // EVENT_T_RANGE                                    = 9
        struct
        {
            uint32 minDist;
            uint32 maxDist;
            uint32 repeatMin;
            uint32 repeatMax;
        } range;
        // EVENT_T_OOC_LOS                                  = 10
        struct
        {
            uint32 reaction;
            uint32 maxRange;
            uint32 repeatMin;
            uint32 repeatMax;
        } ooc_los;
        // EVENT_T_TARGET_CASTING                           = 13
        struct
        {
            uint32 repeatMin;
            uint32 repeatMax;
        } target_casting;
        // EVENT_T_FRIENDLY_HP                              = 14
        struct
        {
            uint32 hpDeficit;
            uint32 radius;
            uint32 repeatMin;
            uint32 repeatMax;
        } friendly_hp;
        // EVENT_T_FRIENDLY_IS_CC                           = 15
        struct
        {
            uint32 dispelType;                              // unused ?
            uint32 radius;
            uint32 repeatMin;
            uint32 repeatMax;
        } friendly_is_cc;
        // EVENT_T_FRIENDLY_MISSING_BUFF                    = 16
        struct
        {
            uint32 spellId;
            uint32 radius;
            uint32 repeatMin;
            uint32 repeatMax;
        } friendly_buff;
        // EVENT_T_SUMMONED_UNIT                            = 17
        //EVENT_T_SUMMONED_JUST_DIED                        = 25
        //EVENT_T_SUMMONED_JUST_DESPAWN                     = 26
        struct
        {
            uint32 creatureId;
            uint32 repeatMin;
            uint32 repeatMax;
        } summoned;
        // EVENT_T_QUEST_ACCEPT                             = 19
        // EVENT_T_QUEST_COMPLETE                           = 20
        struct
        {
            uint32 questId;
        } quest;
        // EVENT_T_RECEIVE_EMOTE                            = 22
        struct
        {
            uint32 emoteId;
        } receive_emote;
        // EVENT_T_AURA                                     = 23
        // EVENT_T_TARGET_AURA                              = 24
        // EVENT_T_MISSING_AURA                             = 27
        // EVENT_T_TARGET_MISSING_AURA                      = 28
        struct
        {
            uint32 spellId;
            uint32 amount;
            uint32 repeatMin;
            uint32 repeatMax;
        } buffed;
        // EVENT_T_MOVEMENT_INFORM                          = 29
        struct
        {
            uint32 motionType;
            uint32 pointId;
            uint32 repeatMin;
            uint32 repeatMax;
        } move_inform;
        // EVENT_T_MAP_SCRIPT_EVENT                         = 31
        struct
        {
            uint32 eventId;
            uint32 data;
        } map_event;
        // EVENT_T_GROUP_MEMBER_DIED                        = 32
        struct
        {
            uint32 creatureId;
            uint32 isLeader;
        } group_member_died;
        // EVENT_T_VICTIM_ROOTED                            = 33
        struct
        {
            uint32 repeatMin;
            uint32 repeatMax;
        } victim_rooted;
        // EVENT_T_HIT_BY_AURA                              = 33
        struct
        {
            uint32 auraType;
            uint32 unused;
            uint32 repeatMin;
            uint32 repeatMax;
        } hit_by_aura;
        // RAW
        struct
        {
            uint32 param1;
            uint32 param2;
            uint32 param3;
            uint32 param4;
        } raw;
    };

    ScriptMap* action[MAX_ACTIONS];
};

//Event_Map
typedef std::vector<CreatureEventAI_Event> CreatureEventAI_Event_Vec;
typedef std::unordered_map<uint32, CreatureEventAI_Event_Vec > CreatureEventAI_Event_Map;

struct CreatureEventAIHolder
{
    explicit CreatureEventAIHolder(CreatureEventAI_Event p) : Event(p), Time(0), Enabled(true) {}

    CreatureEventAI_Event Event;
    uint32 Time;
    bool Enabled;

    // helper
    bool UpdateRepeatTimer(Creature* creature, uint32 repeatMin, uint32 repeatMax);
};

class CreatureEventAI : public CreatureAI
{
    public:
        explicit CreatureEventAI(Creature* c);
        ~CreatureEventAI()
        {
            m_CreatureEventAIList.clear();
        }

        void GetAIInformation(ChatHandler& reader) override;

        void JustRespawned() override;
        void Reset();
        void JustReachedHome() override;
        void EnterCombat(Unit* enemy) override;
        void EnterEvadeMode() override;
        void OnCombatStop() override;
        void JustDied(Unit* killer) override;
        void KilledUnit(Unit* victim) override;
        void JustSummoned(Creature* pUnit) override;
        void AttackStart(Unit* who) override;
        void MoveInLineOfSight(Unit* who) override;
        void SpellHit(Unit* pUnit, SpellEntry const* pSpell) override;
        void MovementInform(uint32 type, uint32 id) override;
        void DamageTaken(Unit* done_by, uint32& damage) override;
        void UpdateAI(uint32 const diff) override;
        void ReceiveEmote(Player* pPlayer, uint32 text_emote) override;
        void GroupMemberJustDied(Creature* unit, bool isLeader) override;
        void SummonedCreatureJustDied(Creature* unit) override;
        void SummonedCreatureDespawn(Creature* unit) override;
        void OnScriptEventHappened(uint32 uiEvent, uint32 uiData, WorldObject* pInvoker) override;

        static int Permissible(Creature const*);

        bool ProcessEvent(CreatureEventAIHolder& pHolder, Unit* pActionInvoker = nullptr);
        void ProcessAction(ScriptMap* action, uint32 EventId, Unit* pActionInvoker);
        void SetInvincibilityHealthLevel(uint32 hp_level, bool is_percent);

        uint8  m_Phase;                                     // Current phase, max 32 phases

    protected:
        uint32 m_EventUpdateTime;                           //Time between event updates
        uint32 m_EventDiff;                                 //Time between the last event call
        bool   m_bEmptyList;

        //Variables used by Events themselves
        typedef std::vector<CreatureEventAIHolder> CreatureEventAIList;
        CreatureEventAIList m_CreatureEventAIList;          //Holder for events (stores enabled, time, and eventid)
        float  m_AttackDistance;                            // Distance to attack from
        float  m_AttackAngle;                               // Angle of attack
        uint32 m_InvinceabilityHpLevel;                     // Minimal health level allowed at damage apply
        bool m_bCanSummonGuards;

        void UpdateEventsOn_UpdateAI(uint32 const diff, bool Combat);
        void UpdateEventsOn_MoveInLineOfSight(Unit* pWho);
};

#endif
