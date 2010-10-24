/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_SMARTAI_H
#define TRINITY_SMARTAI_H

#include "Common.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"

/*
N O T E S


movepoints:
    create ingame commands

commands:
    smartai
    smartai movepoints
    smartai movepoints start (id)
    smartai movepoints add
    smartai movepoints end
    smartai movepoints show (id)
    smartai reload
    smartai create [reload creature]


void passenger removed
void setcanrun
void setcanfly
void setcanswim
void setinhabittype

event change flags

need a local SendChat()

*/

//temp copied from eai, will be modded
enum SMARTAI_EVENT
{
    SMART_EVENT_TIMER_IC                = 0,                    // InitialMin, InitialMax, RepeatMin, RepeatMax
    SMART_EVENT_TIMER_OOC               = 1,                    // InitialMin, InitialMax, RepeatMin, RepeatMax
    SMART_EVENT_HP                      = 2,                    // HPMax%, HPMin%, RepeatMin, RepeatMax
    SMART_EVENT_MANA                    = 3,                    // ManaMax%,ManaMin% RepeatMin, RepeatMax
    SMART_EVENT_AGGRO                   = 4,                    // NONE
    SMART_EVENT_KILL                    = 5,                    // RepeatMin, RepeatMax
    SMART_EVENT_DEATH                   = 6,                    // NONE
    SMART_EVENT_EVADE                   = 7,                    // NONE
    SMART_EVENT_SPELLHIT                = 8,                    // SpellID, School, RepeatMin, RepeatMax
    SMART_EVENT_RANGE                   = 9,                    // MinDist, MaxDist, RepeatMin, RepeatMax
    SMART_EVENT_OOC_LOS                 = 10,                   // NoHostile, MaxRnage, RepeatMin, RepeatMax
    SMART_EVENT_SPAWNED                 = 11,                   // Condition, CondValue1
    SMART_EVENT_TARGET_HP               = 12,                   // HPMax%, HPMin%, RepeatMin, RepeatMax
    SMART_EVENT_TARGET_CASTING          = 13,                   // RepeatMin, RepeatMax
    SMART_EVENT_FRIENDLY_HP             = 14,                   // HPDeficit, Radius, RepeatMin, RepeatMax
    SMART_EVENT_FRIENDLY_IS_CC          = 15,                   // DispelType, Radius, RepeatMin, RepeatMax
    SMART_EVENT_FRIENDLY_MISSING_BUFF   = 16,                   // SpellId, Radius, RepeatMin, RepeatMax
    SMART_EVENT_SUMMONED_UNIT           = 17,                   // CreatureId, RepeatMin, RepeatMax
    SMART_EVENT_TARGET_MANA             = 18,                   // ManaMax%, ManaMin%, RepeatMin, RepeatMax
    SMART_EVENT_QUEST_ACCEPT            = 19,                   // QuestID
    SMART_EVENT_QUEST_COMPLETE          = 20,                   //
    SMART_EVENT_REACHED_HOME            = 21,                   // NONE
    SMART_EVENT_RECEIVE_EMOTE           = 22,                   // EmoteId, Condition, CondValue1, CondValue2
    SMART_EVENT_BUFFED                  = 23,                   // Param1 = SpellID, Param2 = Number of Time STacked, Param3/4 Repeat Min/Max
    SMART_EVENT_TARGET_BUFFED           = 24,                   // Param1 = SpellID, Param2 = Number of Time STacked, Param3/4 Repeat Min/Max
    SMART_EVENT_RESET                   = 35,                   // Is it called after combat, when the creature respawn and spawn. -- TRINITY ONLY

    SMART_EVENT_END                     = 36,
};

//temp copied from eai, will be modded
enum SMARTAI_ACTION
{
    SMART_ACTION_NONE                       = 0,                // No action
    SMART_ACTION_TEXT                       = 1,                // TextId1, optionally -TextId2, optionally -TextId3(if -TextId2 exist). If more than just -TextId1 is defined, randomize. Negative values.
    SMART_ACTION_SET_FACTION                = 2,                // FactionId (or 0 for default)
    SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL    = 3,                // Creature_template entry(param1) OR ModelId (param2) (or 0 for both to demorph)
    SMART_ACTION_SOUND                      = 4,                // SoundId
    SMART_ACTION_EMOTE                      = 5,                // EmoteId
    SMART_ACTION_RANDOM_SAY                 = 6,                // UNUSED
    SMART_ACTION_RANDOM_YELL                = 7,                // UNUSED
    SMART_ACTION_RANDOM_TEXTEMOTE           = 8,                // UNUSED
    SMART_ACTION_RANDOM_SOUND               = 9,                // SoundId1, SoundId2, SoundId3 (-1 in any field means no output if randomed that field)
    SMART_ACTION_RANDOM_EMOTE               = 10,               // EmoteId1, EmoteId2, EmoteId3 (-1 in any field means no output if randomed that field)
    SMART_ACTION_CAST                       = 11,               // SpellId, Target, CastFlags
    SMART_ACTION_SUMMON                     = 12,               // CreatureID, Target, Duration in ms
    SMART_ACTION_THREAT_SINGLE_PCT          = 13,               // Threat%, Target
    SMART_ACTION_THREAT_ALL_PCT             = 14,               // Threat%
    SMART_ACTION_QUEST_EVENT                = 15,               // QuestID, Target
    SMART_ACTION_CAST_EVENT                 = 16,               // QuestID, SpellId, Target - must be removed as hack?
    SMART_ACTION_SET_UNIT_FIELD             = 17,               // Field_Number, Value, Target
    SMART_ACTION_SET_UNIT_FLAG              = 18,               // Flags (may be more than one field OR'd together), Target
    SMART_ACTION_REMOVE_UNIT_FLAG           = 19,               // Flags (may be more than one field OR'd together), Target
    SMART_ACTION_AUTO_ATTACK                = 20,               // AllowAttackState (0 = stop attack, anything else means continue attacking)
    SMART_ACTION_COMBAT_MOVEMENT            = 21,               // AllowCombatMovement (0 = stop combat based movement, anything else continue attacking)
    SMART_ACTION_SET_PHASE                  = 22,               // Phase
    SMART_ACTION_INC_PHASE                  = 23,               // Value (may be negative to decrement phase, should not be 0)
    SMART_ACTION_EVADE                      = 24,               // No Params
    SMART_ACTION_FLEE_FOR_ASSIST            = 25,               // No Params
    SMART_ACTION_QUEST_EVENT_ALL            = 26,               // QuestID
    SMART_ACTION_CAST_EVENT_ALL             = 27,               // CreatureId, SpellId
    SMART_ACTION_REMOVEAURASFROMSPELL       = 28,               // Target, Spellid
    SMART_ACTION_RANGED_MOVEMENT            = 29,               // Distance, Angle
    SMART_ACTION_RANDOM_PHASE               = 30,               // PhaseId1, PhaseId2, PhaseId3
    SMART_ACTION_RANDOM_PHASE_RANGE         = 31,               // PhaseMin, PhaseMax
    SMART_ACTION_SUMMON_ID                  = 32,               // CreatureId, Target, SpawnId
    SMART_ACTION_KILLED_MONSTER             = 33,               // CreatureId, Target
    SMART_ACTION_SET_INST_DATA              = 34,               // Field, Data
    SMART_ACTION_SET_INST_DATA64            = 35,               // Field, Target
    SMART_ACTION_UPDATE_TEMPLATE            = 36,               // Entry, Team
    SMART_ACTION_DIE                        = 37,               // No Params
    SMART_ACTION_ZONE_COMBAT_PULSE          = 38,               // No Params
    SMART_ACTION_CALL_FOR_HELP              = 39,               // Radius
    SMART_ACTION_SET_SHEATH                 = 40,               // Sheath (0-passive,1-melee,2-ranged)
    SMART_ACTION_FORCE_DESPAWN              = 41,               // No Params
    SMART_ACTION_SET_INVINCIBILITY_HP_LEVEL = 42,               // MinHpValue, format(0-flat,1-percent from max health)
    SMART_ACTION_MOUNT_TO_ENTRY_OR_MODEL    = 43,               // Creature_template entry(param1) OR ModelId (param2) (or 0 for both to unmount)

    SMART_ACTION_SET_PHASE_MASK             = 97,
    SMART_ACTION_SET_STAND_STATE            = 98,
    SMART_ACTION_MOVE_RANDOM_POINT          = 99,
    SMART_ACTION_SET_VISIBILITY             = 100,
    SMART_ACTION_SET_ACTIVE                 = 101,  //Apply
    SMART_ACTION_SET_AGGRESSIVE             = 102,  //Apply
    SMART_ACTION_ATTACK_START_PULSE         = 103,  //Distance
    SMART_ACTION_SUMMON_GO                  = 104,  //GameObjectID, DespawnTime in ms

    SMART_ACTION_END                        = 105,
};

//temp copied from eai, will be modded
enum SMARTAI_TARGETS
{
    SMART_TARGET_SELF                           = 0,    //Self cast

    //Hostile targets (if pet then returns pet owner)
    SMART_TARGET_VICTIM                         = 1,    //Our current target (ie: highest aggro)
    SMART_TARGET_HOSTILE_SECOND_AGGRO           = 2,    //Second highest aggro (generaly used for cleaves and some special attacks)
    SMART_TARGET_HOSTILE_LAST_AGGRO             = 3,    //Dead last on aggro (no idea what this could be used for)
    SMART_TARGET_HOSTILE_RANDOM                 = 4,    //Just any random target on our threat list
    SMART_TARGET_HOSTILE_RANDOM_NOT_TOP         = 5,    //Any random target except top threat

    //Invoker targets (if pet then returns pet owner)
    SMART_TARGET_ACTION_INVOKER                 = 6,    //Unit who caused this Event to occur (only works for EVENT_T_AGGRO, EVENT_T_KILL, EVENT_T_DEATH, EVENT_T_SPELLHIT, EVENT_T_OOC_LOS, EVENT_T_FRIENDLY_HP, EVENT_T_FRIENDLY_IS_CC, EVENT_T_FRIENDLY_MISSING_BUFF)

    //Hostile targets (including pets)
    SMART_TARGET_HOSTILE_WPET                   = 7,    //Current target (can be a pet)
    SMART_TARGET_HOSTILE_WPET_SECOND_AGGRO      = 8,    //Second highest aggro (generaly used for cleaves and some special attacks)
    SMART_TARGET_HOSTILE_WPET_LAST_AGGRO        = 9,    //Dead last on aggro (no idea what this could be used for)
    SMART_TARGET_HOSTILE_WPET_RANDOM            = 10,   //Just any random target on our threat list
    SMART_TARGET_HOSTILE_WPET_RANDOM_NOT_TOP    = 11,   //Any random target except top threat

    SMART_TARGET_ACTION_INVOKER_WPET            = 12,

    SMART_TARGET_END                            = 13,
};

#define SMARTAI_EVENT_PARAM_COUNT 6
#define SMARTAI_ACTION_PARAM_COUNT 6

struct MovePoint
{
    MovePoint(uint32 _id, float _x, float _y, float _z)
    {
        id = _id;
        x = _x;
        y = _y;
        z = _z;
    }

    uint32 id;
    float x;
    float y;
    float z;
};

// one line in DB is one event
struct SMARTAI_EVENT_HOLDER
{
    uint32 event_id;
    SMARTAI_EVENT event_type;
    uint32 event_phase_mask;
    uint32 event_chance;
    uint32 event_flags;
    int32 event_param[SMARTAI_EVENT_PARAM_COUNT];

    SMARTAI_ACTION action_type;
    int32 action_param[SMARTAI_ACTION_PARAM_COUNT];

    float param_x;
    float param_y;
    float param_z;
    float param_o;
};

// all events for a single entry
typedef std::vector<SMARTAI_EVENT_HOLDER> SmartAIEventList;

// all events for all entries
typedef UNORDERED_MAP<int32, SmartAIEventList> SmartAIEventMap;

class SmartAIMgr
{
    SmartAIMgr(){};
    public:
        ~SmartAIMgr(){};

        void LoadSmartAIFromDB();

        // only use this after EntryExists() check
        SmartAIEventList const& GetEventList(int32 entry) const
        {
            SmartAIEventMap::const_iterator sList = m_EventMap.find(entry);
            return (*sList).second;
        }
        SmartAIEventMap const& GetEventMap() const { return m_EventMap; }

        // do we have entry's eventList from DB?
        bool EntryExists(int32 entry)
        {
            SmartAIEventMap::const_iterator sList = m_EventMap.find(entry);
            if (sList != m_EventMap.end())
                return true;
            return false;
        }

    private:
        SmartAIEventMap m_EventMap;
};

class SmartAI : public CreatureAI
{
    public:
        ~SmartAI(){};
        explicit SmartAI(Creature *c);

        // Called when creature is spawned or respawned
        void JustRespawned();

        // Called after InitializeAI(), EnterEvadeMode() for resetting variables
        void Reset();

        // Called at reaching home after evade
        void JustReachedHome();

        // Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
        void EnterCombat(Unit *enemy);

        // Called for reaction at stopping attack at no attackers or targets
        void EnterEvadeMode();

        // Called when the creature is killed
        void JustDied(Unit* killer);

        // Called when the creature kills a unit
        void KilledUnit(Unit* victim);

        // Called when the creature summon successfully other creature
        void JustSummoned(Creature* pUnit);

        // Tell creature to attack and follow the victim
        void AttackStart(Unit *who);

        // Called if IsVisible(Unit *who) is true at each *who move, reaction at visibility zone enter
        void MoveInLineOfSight(Unit *who);

        // Called when hit by a spell
        void SpellHit(Unit* pUnit, const SpellEntry* pSpell);

        // Called when spell hits a target
        void SpellHitTarget(Unit* target, const SpellEntry*);

        // Called at any Damage from any attacker (before damage apply)
        void DamageTaken(Unit* done_by, uint32& damage, DamageEffectType damagetype);

        // Called when the creature receives heal
        void HealReceived(Unit* done_by, uint32& addhealth);

        // Called at World update tick
        void UpdateAI(const uint32 diff);

        // Called at text emote receive from player
        void ReceiveEmote(Player* pPlayer, uint32 text_emote);

        // Called at waypoint reached or point movement finished
        void MovementInform(uint32 MovementType, uint32 Data);

        // Called when creature is summoned by another unit
        void IsSummonedBy(Unit* summoner);

        // Called at any Damage to any victim (before damage apply)
        void DamageDealt(Unit * done_to, uint32 & damage);

        // Called when a summoned creature dissapears (UnSommoned)
        void SummonedCreatureDespawn(Creature* unit);

        // called when the corpse of this creature gets removed
        void CorpseRemoved(uint32 & respawnDelay);

        // Called at World update tick if creature is charmed
        void UpdateAIWhileCharmed(const uint32 diff);

        // Called when a Player/Creature enters the creature (vehicle)
        void PassengerBoarded(Unit* who, int8 seatId, bool apply);

        // Called when gets initialized, when creature is added to world
        void InitializeAI();

        // Called when creature gets charmed by another unit
        void OnCharmed(bool apply);

        // Called when victim is in line of sight
        bool CanAIAttack(const Unit* who) const;

        // Used in scripts to share variables
        void DoAction(const int32 param = 0);

        // Used in scripts to share variables
        uint32 GetData(uint32 id = 0);

        // Used in scripts to share variables
        void SetData(uint32 id, uint32 value);

        // Used in scripts to share variables
        void SetGUID(const uint64 &guid, int32 id = 0);

        // Used in scripts to share variables
        uint64 GetGUID(int32 id = 0);

        //core related
        static int Permissible(const Creature *);

        // Called at movepoint reached
        void MovepointReached(uint32 id);

        // Start moving to the desired MovePoint
        void MovepointStart(uint32 id);

        // Makes the creature run/walk
        void SetRun(bool bRun = true);

        // Sets the action that will be called when creature reaches the last movepoint
        void SetMovePathEndAction(SMARTAI_ACTION action = SMART_ACTION_FORCE_DESPAWN);

    private:
};

#define sSmartAIMgr (*ACE_Singleton<SmartAIMgr, ACE_Null_Mutex>::instance())
#endif
