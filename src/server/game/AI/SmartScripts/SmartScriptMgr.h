/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_SMARTSCRIPTMGR_H
#define TRINITY_SMARTSCRIPTMGR_H

#include "Common.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "ConditionMgr.h"
#include "CreatureTextMgr.h"
#include "Spell.h"

//#include "SmartScript.h"
//#include "SmartAI.h"

struct WayPoint
{
    WayPoint(uint32 _id, float _x, float _y, float _z)
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

enum SMART_EVENT_PHASE
{
    SMART_EVENT_PHASE_ALWAYS  = 0,
    SMART_EVENT_PHASE_1       = 1,
    SMART_EVENT_PHASE_2       = 2,
    SMART_EVENT_PHASE_3       = 3,
    SMART_EVENT_PHASE_4       = 4,
    SMART_EVENT_PHASE_5       = 5,
    SMART_EVENT_PHASE_6       = 6,
    SMART_EVENT_PHASE_MAX     = 7,

    SMART_EVENT_PHASE_COUNT   = 6,
};

enum SMART_EVENT_PHASE_BITS
{
    SMART_EVENT_PHASE_ALWAYS_BIT   = 0,
    SMART_EVENT_PHASE_1_BIT        = 1,
    SMART_EVENT_PHASE_2_BIT        = 2,
    SMART_EVENT_PHASE_3_BIT        = 4,
    SMART_EVENT_PHASE_4_BIT        = 8,
    SMART_EVENT_PHASE_5_BIT        = 16,
    SMART_EVENT_PHASE_6_BIT        = 32,
    SMART_EVENT_PHASE_ALL          = SMART_EVENT_PHASE_1_BIT + SMART_EVENT_PHASE_2_BIT + SMART_EVENT_PHASE_3_BIT + SMART_EVENT_PHASE_4_BIT + SMART_EVENT_PHASE_5_BIT + SMART_EVENT_PHASE_6_BIT,
};

const uint32 SmartPhaseMask[SMART_EVENT_PHASE_COUNT][2] =
{
    {SMART_EVENT_PHASE_1, SMART_EVENT_PHASE_1_BIT },
    {SMART_EVENT_PHASE_2, SMART_EVENT_PHASE_2_BIT },
    {SMART_EVENT_PHASE_3, SMART_EVENT_PHASE_3_BIT },
    {SMART_EVENT_PHASE_4, SMART_EVENT_PHASE_4_BIT },
    {SMART_EVENT_PHASE_5, SMART_EVENT_PHASE_5_BIT },
    {SMART_EVENT_PHASE_6, SMART_EVENT_PHASE_6_BIT },
};

enum SMART_EVENT
{
    SMART_EVENT_UPDATE_IC                = 0,       //1             // InitialMin, InitialMax, RepeatMin, RepeatMax
    SMART_EVENT_UPDATE_OOC               = 1,       //1             // InitialMin, InitialMax, RepeatMin, RepeatMax
    SMART_EVENT_HEALT_PCT                = 2,       //1             // HPMin%, HPMax%,  RepeatMin, RepeatMax
    SMART_EVENT_MANA_PCT                 = 3,       //1             // ManaMin%, ManaMax%, RepeatMin, RepeatMax
    SMART_EVENT_AGGRO                    = 4,       //1             // NONE
    SMART_EVENT_KILL                     = 5,       //1             // CooldownMin0, CooldownMax1, playerOnly2, else creature entry3
    SMART_EVENT_DEATH                    = 6,       //1             // NONE
    SMART_EVENT_EVADE                    = 7,       //1             // NONE
    SMART_EVENT_SPELLHIT                 = 8,       //1             // SpellID, School, CooldownMin, CooldownMax
    SMART_EVENT_RANGE                    = 9,       //1             // MinDist, MaxDist, RepeatMin, RepeatMax
    SMART_EVENT_OOC_LOS                  = 10,      //1             // NoHostile, MaxRnage, CooldownMin, CooldownMax
    SMART_EVENT_RESPAWN                  = 11,      //1             // type, MapId, ZoneId
    SMART_EVENT_TARGET_HEALTH_PCT        = 12,      //1             // HPMin%, HPMax%, RepeatMin, RepeatMax
    SMART_EVENT_TARGET_CASTING           = 13,      //1             // RepeatMin, RepeatMax
    SMART_EVENT_FRIENDLY_HEALTH          = 14,      //1             // HPDeficit, Radius, RepeatMin, RepeatMax
    SMART_EVENT_FRIENDLY_IS_CC           = 15,      //1             // Radius, RepeatMin, RepeatMax
    SMART_EVENT_FRIENDLY_MISSING_BUFF    = 16,      //1             // SpellId, Radius, RepeatMin, RepeatMax
    SMART_EVENT_SUMMONED_UNIT            = 17,      //1             // CreatureId(0 all), CooldownMin, CooldownMax
    SMART_EVENT_TARGET_MANA_PCT          = 18,      //1             // ManaMin%, ManaMax%, RepeatMin, RepeatMax
    SMART_EVENT_ACCEPTED_QUEST           = 19,      //1             // QuestID(0any)
    SMART_EVENT_REWARD_QUEST             = 20,      //1             // QuestID(0any)
    SMART_EVENT_REACHED_HOME             = 21,      //1             // NONE
    SMART_EVENT_RECEIVE_EMOTE            = 22,      //1             // EmoteId, CooldownMin, CooldownMax, condition, val1, val2, val3
    SMART_EVENT_HAS_AURA                 = 23,      //1             // Param1 = SpellID, Param2 = Number of Time STacked, Param3/4 RepeatMin, RepeatMax
    SMART_EVENT_TARGET_BUFFED            = 24,      //1             // Param1 = SpellID, Param2 = Number of Time STacked, Param3/4 RepeatMin, RepeatMax
    SMART_EVENT_RESET                    = 25,      //1             // Called after combat, when the creature respawn and spawn.

    SMART_EVENT_IC_LOS                   = 26,      //1             // NoHostile, MaxRnage, CooldownMin, CooldownMax
    SMART_EVENT_PASSENGER_BOARDED        = 27,      //1             // CooldownMin, CooldownMax
    SMART_EVENT_PASSENGER_REMOVED        = 28,      //1             // CooldownMin, CooldownMax
    SMART_EVENT_CHARMED                  = 29,      //1             // NONE
    SMART_EVENT_CHARMED_TARGET           = 30,      //1             // NONE
    SMART_EVENT_SPELLHIT_TARGET          = 31,      //1             // SpellID, School, CooldownMin, CooldownMax
    SMART_EVENT_DAMAGED                  = 32,      //1             // MinDmg, MaxDmg, CooldownMin, CooldownMax
    SMART_EVENT_DAMAGED_TARGET           = 33,      //1             // MinDmg, MaxDmg, CooldownMin, CooldownMax
    SMART_EVENT_MOVEMENTINFORM           = 34,      //1             // MovementType(any), PointID
    SMART_EVENT_SUMMON_DESPAWNED         = 35,      //1             // Entry, CooldownMin, CooldownMax
    SMART_EVENT_CORPSE_REMOVED           = 36,      //1             // NONE
    SMART_EVENT_AI_INIT                  = 37,      //1             // NONE
    SMART_EVENT_DATA_SET                 = 38,      //1             // Id, Value, CooldownMin, CooldownMax
    SMART_EVENT_WAYPOINT_START           = 39,      //1             // PointId(0any), pathID(0any)
    SMART_EVENT_WAYPOINT_REACHED         = 40,      //1             // PointId(0any), pathID(0any)
    SMART_EVENT_TRANSPORT_ADDPLAYER      = 41,      //1             // NONE
    SMART_EVENT_TRANSPORT_ADDCREATURE    = 42,      //1             // Entry (0 any)
    SMART_EVENT_TRANSPORT_REMOVE_PLAYER  = 43,      //1             // NONE
    SMART_EVENT_TRANSPORT_RELOCATE       = 44,      //1             // PointId
    SMART_EVENT_INSTANCE_PLAYER_ENTER    = 45,      //1             // Team (0 any), CooldownMin, CooldownMax
    SMART_EVENT_AREATRIGGER_ONTRIGGER    = 46,      //1             // TriggerId(0 any)
    SMART_EVENT_QUEST_ACCEPTED           = 47,      //1             // none
    SMART_EVENT_QUEST_OBJ_COPLETETION    = 48,      //1             // none
    SMART_EVENT_QUEST_COMPLETION         = 49,      //1             // none
    SMART_EVENT_QUEST_REWARDED           = 50,      //1             // none
    SMART_EVENT_QUEST_FAIL               = 51,      //1             // none
    SMART_EVENT_TEXT_OVER                = 52,      //1             // GroupId from creature_text,  creature entry who talks (0 any)
    SMART_EVENT_RECEIVE_HEAL             = 53,      //1             // MinHeal, MaxHeal, CooldownMin, CooldownMax
    SMART_EVENT_JUST_SUMMONED            = 54,      //1             // none
    SMART_EVENT_WAYPOINT_PAUSED          = 55,      //1             // PointId(0any), pathID(0any)
    SMART_EVENT_WAYPOINT_RESUMED         = 56,      //1             // PointId(0any), pathID(0any)
    SMART_EVENT_WAYPOINT_STOPPED         = 57,      //1             // PointId(0any), pathID(0any)
    SMART_EVENT_WAYPOINT_ENDED           = 58,      //1             // PointId(0any), pathID(0any)
    SMART_EVENT_TIMED_EVENT_TRIGGERED    = 59,      //1             // id
    SMART_EVENT_UPDATE                   = 60,      //1             // InitialMin, InitialMax, RepeatMin, RepeatMax
    SMART_EVENT_LINK                     = 61,      //1             // INTERNAL USAGE, no params, used to link together multiple events, does not use any extra resources to iterate event lists needlessly
    SMART_EVENT_GOSSIP_SELECT            = 62,      //1             // menuID, actionID
    SMART_EVENT_JUST_CREATED             = 63,      //1             // none
    SMART_EVENT_GOSSIP_HELLO             = 64,      //1             // none
    SMART_EVENT_FOLLOW_COMPLETED         = 65,      //1             // none
    SMART_EVENT_DUMMY_EFFECT             = 66,      //1             // spellId, effectIndex
    SMART_EVENT_IS_BEHIND_TARGET         = 67,      //1             // cooldownMin, CooldownMax
    SMART_EVENT_GAME_EVENT_START         = 68,      //1             // game_event.Entry
    SMART_EVENT_GAME_EVENT_END           = 69,      //1             // game_event.Entry
    SMART_EVENT_GO_STATE_CHANGED         = 70,      //                 go state    

    SMART_EVENT_END                      = 71,
};

struct SmartEvent
{
    SMART_EVENT type;
    uint32 event_phase_mask;
    uint32 event_chance;
    uint32 event_flags;
    union
    {
        struct
        {
            uint32 min;
            uint32 max;
            uint32 repeatMin;
            uint32 repeatMax;
        } minMaxRepeat;

        struct
        {
            uint32 cooldownMin;
            uint32 cooldownMax;
            uint32 playerOnly;
            uint32 creature;
        } kill;

        struct
        {
            uint32 spell;
            uint32 school;
            uint32 cooldownMin;
            uint32 cooldownMax;
        } spellHit;

        struct
        {
            uint32 noHostile;
            uint32 maxDist;
            uint32 cooldownMin;
            uint32 cooldownMax;
        } los;

        struct
        {
            uint32 type;
            uint32 map;
            uint32 area;
        } respawn;

        struct
        {
            uint32 repeatMin;
            uint32 repeatMax;
        } minMax;

        struct
        {
            uint32 hpDeficit;
            uint32 radius;
            uint32 repeatMin;
            uint32 repeatMax;
        } friendlyHealt;

        struct
        {
            uint32 radius;
            uint32 repeatMin;
            uint32 repeatMax;
        } friendlyCC;

        struct
        {
            uint32 spell;
            uint32 radius;
            uint32 repeatMin;
            uint32 repeatMax;
        } missingBuff;

        struct
        {
            uint32 creature;
            uint32 cooldownMin;
            uint32 cooldownMax;
        } summoned;

        struct
        {
            uint32 quest;
        } quest;

        struct
        {
            uint32 emote;
            uint32 cooldownMin;
            uint32 cooldownMax;
        } emote;

        struct
        {
            uint32 spell;
            uint32 count;
            uint32 repeatMin;
            uint32 repeatMax;
        } aura;

        struct
        {
            uint32 spell;
            uint32 count;
            uint32 repeatMin;
            uint32 repeatMax;
        } targetAura;

        struct
        {
            uint32 type;
            uint32 id;
        } movementInform;

        struct
        {
            uint32 id;
            uint32 value;
            uint32 cooldownMin;
            uint32 cooldownMax;
        } dataSet;

        struct
        {
            uint32 pointID;
            uint32 pathID;
        } waypoint;

        struct
        {
            uint32 creature;
        } transportAddCreature;

        struct
        {
            uint32 pointID;
        } transportRelocate;

        struct
        {
            uint32 team;
            uint32 cooldownMin;
            uint32 cooldownMax;
        } instancePlayerEnter;

        struct
        {
            uint32 id;
        } areatrigger;

        struct
        {
            uint32 textGroupID;
            uint32 creatureEntry;
        } textOver;

        struct
        {
            uint32 id;
        } timedEvent;

        struct
        {
            uint32 sender;
            uint32 action;
        } gossip;

        struct
        {
            uint32 spell;
            uint32 effIndex;
        } dummy;

        struct
        {
            uint32 cooldownMin;
            uint32 cooldownMax;
        } behindTarget;

        struct 
        {
            uint32 gameEventId;
        } gameEvent;
        
        struct
        {
            uint32 state;
        } goStateChanged;
        
        struct
        {
            uint32 param1;
            uint32 param2;
            uint32 param3;
            uint32 param4;
        } raw;
    };
};

enum SMART_SCRIPT_RESPAWN_CONDITION
{
    SMART_SCRIPT_RESPAWN_CONDITION_NONE = 0,
    SMART_SCRIPT_RESPAWN_CONDITION_MAP = 1,
    SMART_SCRIPT_RESPAWN_CONDITION_AREA = 2,
    SMART_SCRIPT_RESPAWN_CONDITION_END = 3,
};

enum SMART_ACTION
{
    SMART_ACTION_NONE                               = 0,      // No action
    SMART_ACTION_TALK                               = 1,      // groupID from creature_text, duration to wait before TEXT_OVER event is triggered
    SMART_ACTION_SET_FACTION                        = 2,      // FactionId (or 0 for default)
    SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL            = 3,      // Creature_template entry(param1) OR ModelId (param2) (or 0 for both to demorph)
    SMART_ACTION_SOUND                              = 4,      // SoundId, TextRange
    SMART_ACTION_PLAY_EMOTE                         = 5,      // EmoteId
    SMART_ACTION_FAIL_QUEST                         = 6,      // QuestID
    SMART_ACTION_ADD_QUEST                          = 7,      // QuestID
    SMART_ACTION_SET_REACT_STATE                    = 8,      // state
    SMART_ACTION_ACTIVATE_GOBJECT                   = 9,      //
    SMART_ACTION_RANDOM_EMOTE                       = 10,     // EmoteId1, EmoteId2, EmoteId3...
    SMART_ACTION_CAST                               = 11,     // SpellId, CastFlags
    SMART_ACTION_SUMMON_CREATURE                    = 12,     // CreatureID, summonType, duration in ms, storageID, attackInvoker,
    SMART_ACTION_THREAT_SINGLE_PCT                  = 13,     // Threat%
    SMART_ACTION_THREAT_ALL_PCT                     = 14,     // Threat%
    SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS    = 15,     // QuestID
    SMART_ACTION_SEND_CASTCREATUREORGO              = 16,     // QuestID, SpellId
    SMART_ACTION_SET_EMOTE_STATE                    = 17,     // emoteID
    SMART_ACTION_SET_UNIT_FLAG                      = 18,     // Flags (may be more than one field OR'd together), Target
    SMART_ACTION_REMOVE_UNIT_FLAG                   = 19,     // Flags (may be more than one field OR'd together), Target
    SMART_ACTION_AUTO_ATTACK                        = 20,     // AllowAttackState (0 = stop attack, anything else means continue attacking)
    SMART_ACTION_ALLOW_COMBAT_MOVEMENT              = 21,     // AllowCombatMovement (0 = stop combat based movement, anything else continue attacking)
    SMART_ACTION_SET_EVENT_PHASE                    = 22,     // Phase
    SMART_ACTION_INC_EVENT_PHASE                    = 23,     // Value (may be negative to decrement phase, should not be 0)
    SMART_ACTION_EVADE                              = 24,     // No Params
    SMART_ACTION_FLEE_FOR_ASSIST                    = 25,     // With Emote
    SMART_ACTION_CALL_GROUPEVENTHAPPENS             = 26,     // QuestID
    SMART_ACTION_CALL_CASTEDCREATUREORGO            = 27,     // CreatureId, SpellId
    SMART_ACTION_REMOVEAURASFROMSPELL               = 28,     // Spellid
    SMART_ACTION_FOLLOW                             = 29,     // Distance (0 = default), Angle (0 = default), EndCreatureEntry, credit, creditType (0monsterkill, 1event)
    SMART_ACTION_RANDOM_PHASE                       = 30,     // PhaseId1, PhaseId2, PhaseId3...
    SMART_ACTION_RANDOM_PHASE_RANGE                 = 31,     // PhaseMin, PhaseMax
    SMART_ACTION_RESET_GOBJECT                      = 32,     //
    SMART_ACTION_CALL_KILLEDMONSTER                 = 33,     // CreatureId,
    SMART_ACTION_SET_INST_DATA                      = 34,     // Field, Data
    SMART_ACTION_SET_INST_DATA64                    = 35,     // Field,
    SMART_ACTION_UPDATE_TEMPLATE                    = 36,     // Entry, Team
    SMART_ACTION_DIE                                = 37,     // No Params
    SMART_ACTION_SET_IN_COMBAT_WITH_ZONE            = 38,     // No Params
    SMART_ACTION_CALL_FOR_HELP                      = 39,     // Radius
    SMART_ACTION_SET_SHEATH                         = 40,     // Sheath (0-unarmed, 1-melee, 2-ranged)
    SMART_ACTION_FORCE_DESPAWN                      = 41,     // timer
    SMART_ACTION_SET_INVINCIBILITY_HP_LEVEL         = 42,     // MinHpValue(+pct, -flat)
    SMART_ACTION_MOUNT_TO_ENTRY_OR_MODEL            = 43,     // Creature_template entry(param1) OR ModelId (param2) (or 0 for both to dismount)
    SMART_ACTION_SET_INGAME_PHASE_MASK              = 44,     // mask

    SMART_ACTION_SET_DATA                           = 45,     // Field, Data (only creature TODO)
    SMART_ACTION_MOVE_FORWARD                       = 46,     // distance
    SMART_ACTION_SET_VISIBILITY                     = 47,     // on/off
    SMART_ACTION_SET_ACTIVE                         = 48,     // No Params
    SMART_ACTION_ATTACK_START                       = 49,     //
    SMART_ACTION_SUMMON_GO                          = 50,     // GameObjectID, DespawnTime in ms,
    SMART_ACTION_KILL_UNIT                          = 51,     //
    SMART_ACTION_ACTIVATE_TAXI                      = 52,     // TaxiID
    SMART_ACTION_WP_START                           = 53,     // run/walk, pathID, canRepeat, quest, despawntime, reactState
    SMART_ACTION_WP_PAUSE                           = 54,     // time
    SMART_ACTION_WP_STOP                            = 55,     // despawnTime, quest, fail?
    SMART_ACTION_ADD_ITEM                           = 56,     // itemID, count
    SMART_ACTION_REMOVE_ITEM                        = 57,     // itemID, count
    SMART_ACTION_INSTALL_AI_TEMPLATE                = 58,     // AITemplateID
    SMART_ACTION_SET_RUN                            = 59,     // 0/1
    SMART_ACTION_SET_FLY                            = 60,     // 0/1
    SMART_ACTION_SET_SWIM                           = 61,     // 0/1
    SMART_ACTION_TELEPORT                           = 62,     // mapID,
    SMART_ACTION_STORE_VARIABLE_DECIMAL             = 63,     // varID, number
    SMART_ACTION_STORE_TARGET_LIST                  = 64,     // varID,
    SMART_ACTION_WP_RESUME                          = 65,     // none
    SMART_ACTION_SET_ORIENTATION                    = 66,     //

    SMART_ACTION_CREATE_TIMED_EVENT                 = 67,     // id, InitialMin, InitialMax, RepeatMin(only if it repeats), RepeatMax(only if it repeats), chance
    SMART_ACTION_PLAYMOVIE                          = 68,     // entry
    SMART_ACTION_MOVE_TO_POS                        = 69,     // xyz
    SMART_ACTION_RESPAWN_TARGET                     = 70,     //
    SMART_ACTION_EQUIP                              = 71,     // entry, slotmask slot1, slot2, slot3   , only slots with mask set will be sent to client, bits are 1, 2, 4, leaving mask 0 is defaulted to mask 7 (send all), slots1-3 are only used if no entry is set
    SMART_ACTION_CLOSE_GOSSIP                       = 72,     // none
    SMART_ACTION_TRIGGER_TIMED_EVENT                = 73,     // id(>1)
    SMART_ACTION_REMOVE_TIMED_EVENT                 = 74,     // id(>1)
    SMART_ACTION_ADD_AURA                           = 75,     // spellid,  targets
    SMART_ACTION_OVERRIDE_SCRIPT_BASE_OBJECT        = 76,     // WARNING: CAN CRASH CORE, do not use if you dont know what you are doing
    SMART_ACTION_RESET_SCRIPT_BASE_OBJECT           = 77,     // none
    SMART_ACTION_CALL_SCRIPT_RESET                  = 78,     // none
    // Unused                                       = 79,
    SMART_ACTION_CALL_TIMED_ACTIONLIST              = 80,     // ID (overwrites already running actionlist), stop after combat?(0/1), timer update type(0-OOC, 1-IC, 2-ALWAYS)
    SMART_ACTION_SET_NPC_FLAG                       = 81,     // Flags
    SMART_ACTION_ADD_NPC_FLAG                       = 82,     // Flags
    SMART_ACTION_REMOVE_NPC_FLAG                    = 83,     // Flags
    SMART_ACTION_SIMPLE_TALK                        = 84,     // groupID, can be used to make players say groupID, Text_over event is not triggered, whisper can not be used (Target units will say the text)
    SMART_ACTION_INVOKER_CAST                       = 85,     // spellID, castFlags,   if avaliable, last used invoker will cast spellId with castFlags on targets
    SMART_ACTION_CROSS_CAST                         = 86,     // spellID, castFlags, CasterTargetType, CasterTarget param1, CasterTarget param2, CasterTarget param3, ( + the origonal target fields as Destination target),   CasterTargets will cast spellID on all Targets (use with caution if targeting multiple * multiple units)
    SMART_ACTION_CALL_RANDOM_TIMED_ACTIONLIST       = 87,     // script9 ids 1-9
    SMART_ACTION_CALL_RANDOM_RANGE_TIMED_ACTIONLIST = 88,     // script9 id min, max
    SMART_ACTION_RANDOM_MOVE                        = 89,     // maxDist
    SMART_ACTION_SET_UNIT_FIELD_BYTES_1             = 90,     // bytes, target
    SMART_ACTION_REMOVE_UNIT_FIELD_BYTES_1          = 91,     // bytes, target
    SMART_ACTION_INTERRUPT_SPELL                    = 92,
    SMART_ACTION_SEND_GO_CUSTOM_ANIM                = 93,     // anim id
    SMART_ACTION_SET_DYNAMIC_FLAG                   = 94,     // Flags
    SMART_ACTION_ADD_DYNAMIC_FLAG                   = 95,     // Flags
    SMART_ACTION_REMOVE_DYNAMIC_FLAG                = 96,     // Flags
    SMART_ACTION_JUMP_TO_POS                        = 97,     // speedXY, speedZ, targetX, targetY, targetZ
    SMART_ACTION_SEND_GOSSIP_MENU                   = 98,     // menuId, optionId
    SMART_ACTION_GO_SET_LOOT_STATE                  = 99,     // state

    SMART_ACTION_END                                = 100,
};

struct SmartAction
{
    SMART_ACTION type;

    union
    {
        struct
        {
            uint32 textGroupID;
            uint32 duration;
        } talk;

        struct
        {
            uint32 factionID;
        } faction;

        struct
        {
            uint32 creature;
            uint32 model;
        } morphOrMount;

        struct
        {
            uint32 sound;
            uint32 range;
        } sound;

        struct
        {
            uint32 emote;
        } emote;

        struct
        {
            uint32 quest;
        } quest;

        struct
        {
            uint32 state;
        } react;

        struct
        {

            uint32 emote1;
            uint32 emote2;
            uint32 emote3;
            uint32 emote4;
            uint32 emote5;
            uint32 emote6;
        } randomEmote;

        struct
        {
            uint32 spell;
            uint32 flags;
            uint32 targetType;
            uint32 targetParam1;
            uint32 targetParam2;
            uint32 targetParam3;
        } cast;

        struct
        {
            uint32 creature;
            uint32 type;
            uint32 duration;
            uint32 storageID;
            uint32 attackInvoker;
        } summonCreature;

        struct
        {
            uint32 threatINC;
            uint32 threatDEC;
        } threatPCT;

        struct
        {
            uint32 quest;
            uint32 spell;
        } castCreatureOrGO;

        struct
        {
            uint32 flag1;
            uint32 flag2;
            uint32 flag3;
            uint32 flag4;
            uint32 flag5;
            uint32 flag6;
        } addUnitFlag;

        struct
        {
            uint32 flag1;
            uint32 flag2;
            uint32 flag3;
            uint32 flag4;
            uint32 flag5;
            uint32 flag6;
        } removeUnitFlag;

        struct
        {
            uint32 attack;
        } autoAttack;

        struct
        {
            uint32 move;
        } combatMove;

        struct
        {
            uint32 phase;
        } setEventPhase;

        struct
        {
            uint32 inc;
            uint32 dec;
        } incEventPhase;

        struct
        {
            uint32 creature;
            uint32 spell;
        } castedCreatureOrGO;

        struct
        {
            uint32 spell;
        } removeAura;

        struct
        {
            uint32 dist;
            uint32 angle;
            uint32 entry;
            uint32 credit;
            uint32 creditType;
        } follow;

        struct
        {
            uint32 phase1;
            uint32 phase2;
            uint32 phase3;
            uint32 phase4;
            uint32 phase5;
            uint32 phase6;
        } randomPhase;

        struct
        {
            uint32 phaseMin;
            uint32 phaseMax;
        } randomPhaseRange;

        struct
        {
            uint32 creature;
        } killedMonster;

        struct
        {
            uint32 field;
            uint32 data;
        } setInstanceData;

        struct
        {
            uint32 field;
        } setInstanceData64;

        struct
        {
            uint32 creature;
            uint32 team;
        } updateTemplate;

        struct
        {
            uint32 range;
        } callHelp;

        struct
        {
            uint32 sheath;
        } setSheath;

        struct
        {
            uint32 delay;
        } forceDespawn;

        struct
        {
            uint32 minHP;
            uint32 percent;
        } invincHP;

        struct
        {
            uint32 mask;
        } ingamePhaseMask;

        struct
        {
            uint32 field;
            uint32 data;
        } setData;

        struct
        {
            uint32 distance;
        } moveRandom;

        struct
        {
            uint32 state;
        } visibility;

        struct
        {
            uint32 entry;
            uint32 despawnTime;
        } summonGO;

        struct
        {
            uint32 id;
        } taxi;

        struct
        {
            uint32 run;
            uint32 pathID;
            uint32 repeat;
            uint32 quest;
            uint32 despawnTime;
            uint32 reactState;
        } wpStart;

        struct
        {
            uint32 delay;
        } wpPause;

        struct
        {
            uint32 despawnTime;
            uint32 quest;
            uint32 fail;
        } wpStop;

        struct
        {
            uint32 entry;
            uint32 count;
        } item;

        struct
        {
            uint32 id;
            uint32 param1;
            uint32 param2;
            uint32 param3;
            uint32 param4;
            uint32 param5;
        } installTtemplate;

        struct
        {
            uint32 run;
        } setRun;

        struct
        {
            uint32 fly;
        } setFly;

        struct
        {
            uint32 swim;
        } setSwim;

        struct
        {
            uint32 mapID;
        } teleport;

        struct
        {
            uint32 id;
            uint32 number;
        } storeVar;

        struct
        {
            uint32 id;
        } storeTargets;

        struct
        {
            uint32 id;
            uint32 min;
            uint32 max;
            uint32 repeatMin;
            uint32 repeatMax;
            uint32 chance;
        } timeEvent;

        struct
        {
            uint32 entry;
        } movie;

        struct
        {
            uint32 entry;
            uint32 mask;
            uint32 slot1;
            uint32 slot2;
            uint32 slot3;
        } equip;

        struct
        {
            uint32 flag;
        } unitFlag;

        struct
        {
            uint32 byte1;
        } setunitByte;

        struct
        {
            uint32 byte1;
        } delunitByte;

        struct
        {
            uint32 seat;
        } enterVehicle;

        struct
        {
            uint32 id;
            uint32 dontResume;
            uint32 timerType;
        } timedActionList;

        struct
        {
            uint32 entry1;
            uint32 entry2;
            uint32 entry3;
            uint32 entry4;
            uint32 entry5;
            uint32 entry6;
        } randTimedActionList;

        struct
        {
            bool withDelayed;
            uint32 spell_id;
            bool withInstant;
        } interruptSpellCasting;

        struct
        {
            uint32 anim;
        } sendGoCustomAnim;

        struct
        {
            uint32 speedxy;
            uint32 speedz;
        } jump;

        struct
        {
            uint32 withEmote;
        } flee;

        struct
        {
            uint32 goRespawnTime;
        } RespawnTarget;
        
        struct
        {
            uint32 gossipMenuId;
            uint32 gossipNpcTextId;
        } sendGossipMenu;

        struct
        {
            uint32 state;
        } setGoLootState;
        
        struct
        {
            uint32 param1;
            uint32 param2;
            uint32 param3;
            uint32 param4;
            uint32 param5;
            uint32 param6;
        } raw;
    };
};

enum SMARTAI_TEMPLATE
{
    SMARTAI_TEMPLATE_BASIC          = 0, //nothing is preset
    SMARTAI_TEMPLATE_CASTER         = 1, //spellid, repeatMin, repeatMax, range, manaPCT +JOIN: target_param1 as castFlag
    SMARTAI_TEMPLATE_TURRET         = 2, //spellid, repeatMin, repeatMax +JOIN: target_param1 as castFlag
    SMARTAI_TEMPLATE_PASSIVE        = 3,
    SMARTAI_TEMPLATE_CAGED_GO_PART  = 4, //creatureID, give credit at point end?,
    SMARTAI_TEMPLATE_CAGED_NPC_PART = 5, //gameObjectID, despawntime, run?, dist, TextGroupID
    SMARTAI_TEMPLATE_END            = 6,
};

enum SMARTAI_TARGETS
{
    SMART_TARGET_NONE                           = 0,    // NONE, defaulting to invoket
    SMART_TARGET_SELF                           = 1,    // Self cast
    SMART_TARGET_VICTIM                         = 2,    // Our current target (ie: highest aggro)
    SMART_TARGET_HOSTILE_SECOND_AGGRO           = 3,    // Second highest aggro
    SMART_TARGET_HOSTILE_LAST_AGGRO             = 4,    // Dead last on aggro
    SMART_TARGET_HOSTILE_RANDOM                 = 5,    // Just any random target on our threat list
    SMART_TARGET_HOSTILE_RANDOM_NOT_TOP         = 6,    // Any random target except top threat
    SMART_TARGET_ACTION_INVOKER                 = 7,    // Unit who caused this Event to occur
    SMART_TARGET_POSITION                       = 8,    // use xyz from event params
    SMART_TARGET_CREATURE_RANGE                 = 9,    // CreatureEntry(0any), minDist, maxDist
    SMART_TARGET_CREATURE_GUID                  = 10,   // guid, entry
    SMART_TARGET_CREATURE_DISTANCE              = 11,   // CreatureEntry(0any), maxDist
    SMART_TARGET_STORED                         = 12,   // id, uses pre-stored target(list)
    SMART_TARGET_GAMEOBJECT_RANGE               = 13,   // entry(0any), min, max
    SMART_TARGET_GAMEOBJECT_GUID                = 14,   // guid, entry
    SMART_TARGET_GAMEOBJECT_DISTANCE            = 15,   // entry(0any), maxDist
    SMART_TARGET_INVOKER_PARTY                  = 16,   // invoker's party members
    SMART_TARGET_PLAYER_RANGE                   = 17,   // min, max
    SMART_TARGET_PLAYER_DISTANCE                = 18,   // maxDist
    SMART_TARGET_CLOSEST_CREATURE               = 19,   // CreatureEntry(0any), maxDist, dead?
    SMART_TARGET_CLOSEST_GAMEOBJECT             = 20,   // entry(0any), maxDist
    SMART_TARGET_CLOSEST_PLAYER                 = 21,   // maxDist
    SMART_TARGET_ACTION_INVOKER_VEHICLE         = 22,   // Unit's vehicle who caused this Event to occur
    SMART_TARGET_OWNER_OR_SUMMONER              = 23,   // Unit's owner or summoner
    SMART_TARGET_THREAT_LIST                    = 24,   // All units on creature's threat list
    SMART_TARGET_END                            = 25,
};

struct SmartTarget
{
    SmartTarget (SMARTAI_TARGETS t = SMART_TARGET_NONE, uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0)
    {
        type = t;
        raw.param1 = p1;
        raw.param2 = p2;
        raw.param3 = p3;
    }
    SMARTAI_TARGETS type;
    float x, y, z, o;
    union
    {
        struct
        {
            uint32 creature;
            uint32 minDist;
            uint32 maxDist;
        } unitRange;

        struct
        {
            uint32 guid;
            uint32 entry;
        } unitGUID;

        struct
        {
            uint32 creature;
            uint32 dist;
        } unitDistance;

        struct
        {
            uint32 dist;
        } playerDistance;

        struct
        {
            uint32 minDist;
            uint32 maxDist;
        } playerRange;

        struct
        {
            uint32 id;
        } stored;

        struct
        {
            uint32 entry;
            uint32 minDist;
            uint32 maxDist;
        } goRange;

        struct
        {
            uint32 guid;
            uint32 entry;
        } goGUID;

        struct
        {
            uint32 entry;
            uint32 dist;
        } goDistance;

        struct
        {
            uint32 map;
        } position;

        struct
        {
            uint32 entry;
            uint32 dist;
            uint32 dead;
        } closest;

        struct
        {
            uint32 param1;
            uint32 param2;
            uint32 param3;
        } raw;
    };
};

enum eSmartAI
{
    SMART_EVENT_PARAM_COUNT = 4,
    SMART_ACTION_PARAM_COUNT = 6,
    SMART_SUMMON_COUNTER = 0xFFFFFF,
    SMART_ESCORT_LAST_OOC_POINT = 0xFFFFFF,
    SMART_RANDOM_POINT = 0xFFFFFE,
    SMART_ESCORT_TARGETS = 0xFFFFFF
};

enum SmartScriptType
{
    SMART_SCRIPT_TYPE_CREATURE = 0, //done
    SMART_SCRIPT_TYPE_GAMEOBJECT = 1, //done
    SMART_SCRIPT_TYPE_AREATRIGGER = 2, //done
    SMART_SCRIPT_TYPE_EVENT = 3, //
    SMART_SCRIPT_TYPE_GOSSIP = 4, //
    SMART_SCRIPT_TYPE_QUEST = 5, //
    SMART_SCRIPT_TYPE_SPELL = 6, //
    SMART_SCRIPT_TYPE_TRANSPORT = 7, //
    SMART_SCRIPT_TYPE_INSTANCE = 8, //
    SMART_SCRIPT_TYPE_TIMED_ACTIONLIST = 9, //
    SMART_SCRIPT_TYPE_MAX = 10
};

enum SmartAITypeMaskId
{
    SMART_SCRIPT_TYPE_MASK_CREATURE = 1,
    SMART_SCRIPT_TYPE_MASK_GAMEOBJECT = 2,
    SMART_SCRIPT_TYPE_MASK_AREATRIGGER = 4,
    SMART_SCRIPT_TYPE_MASK_EVENT = 8,
    SMART_SCRIPT_TYPE_MASK_GOSSIP = 16,
    SMART_SCRIPT_TYPE_MASK_QUEST = 32,
    SMART_SCRIPT_TYPE_MASK_SPELL = 64,
    SMART_SCRIPT_TYPE_MASK_TRANSPORT = 128,
    SMART_SCRIPT_TYPE_MASK_INSTANCE = 256,
    SMART_SCRIPT_TYPE_MASK_TIMED_ACTIONLIST = 512,
};

const uint32 SmartAITypeMask[SMART_SCRIPT_TYPE_MAX][2] =
{
    {SMART_SCRIPT_TYPE_CREATURE,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_SCRIPT_TYPE_GAMEOBJECT,          SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_SCRIPT_TYPE_AREATRIGGER,         SMART_SCRIPT_TYPE_MASK_AREATRIGGER },
    {SMART_SCRIPT_TYPE_EVENT,               SMART_SCRIPT_TYPE_MASK_EVENT },
    {SMART_SCRIPT_TYPE_GOSSIP,              SMART_SCRIPT_TYPE_MASK_GOSSIP },
    {SMART_SCRIPT_TYPE_QUEST,               SMART_SCRIPT_TYPE_MASK_QUEST },
    {SMART_SCRIPT_TYPE_SPELL,               SMART_SCRIPT_TYPE_MASK_SPELL },
    {SMART_SCRIPT_TYPE_TRANSPORT,           SMART_SCRIPT_TYPE_MASK_TRANSPORT },
    {SMART_SCRIPT_TYPE_INSTANCE,            SMART_SCRIPT_TYPE_MASK_INSTANCE },
    {SMART_SCRIPT_TYPE_TIMED_ACTIONLIST,    SMART_SCRIPT_TYPE_MASK_TIMED_ACTIONLIST }
};

const uint32 SmartAIEventMask[SMART_EVENT_END][2] =
{
    {SMART_EVENT_UPDATE_IC,                 SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_TIMED_ACTIONLIST},
    {SMART_EVENT_UPDATE_OOC,                SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT + SMART_SCRIPT_TYPE_MASK_INSTANCE },
    {SMART_EVENT_HEALT_PCT,                 SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_MANA_PCT,                  SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_AGGRO,                     SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_KILL,                      SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_DEATH,                     SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_EVADE,                     SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_SPELLHIT,                  SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_RANGE,                     SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_OOC_LOS,                   SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_RESPAWN,                   SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_TARGET_HEALTH_PCT,         SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_TARGET_CASTING,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_FRIENDLY_HEALTH,           SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_FRIENDLY_IS_CC,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_FRIENDLY_MISSING_BUFF,     SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_SUMMONED_UNIT,             SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_TARGET_MANA_PCT,           SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_ACCEPTED_QUEST,            SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_REWARD_QUEST,              SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_REACHED_HOME,              SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_RECEIVE_EMOTE,             SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_HAS_AURA,                  SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_TARGET_BUFFED,             SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_RESET,                     SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_IC_LOS,                    SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_PASSENGER_BOARDED,         SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_PASSENGER_REMOVED,         SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_CHARMED,                   SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_CHARMED_TARGET,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_SPELLHIT_TARGET,           SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_DAMAGED,                   SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_DAMAGED_TARGET,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_MOVEMENTINFORM,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_SUMMON_DESPAWNED,          SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_CORPSE_REMOVED,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_AI_INIT,                   SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_DATA_SET,                  SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_WAYPOINT_START,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_WAYPOINT_REACHED,          SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_TRANSPORT_ADDPLAYER,       SMART_SCRIPT_TYPE_MASK_TRANSPORT },
    {SMART_EVENT_TRANSPORT_ADDCREATURE,     SMART_SCRIPT_TYPE_MASK_TRANSPORT },
    {SMART_EVENT_TRANSPORT_REMOVE_PLAYER,   SMART_SCRIPT_TYPE_MASK_TRANSPORT },
    {SMART_EVENT_TRANSPORT_RELOCATE,        SMART_SCRIPT_TYPE_MASK_TRANSPORT },
    {SMART_EVENT_INSTANCE_PLAYER_ENTER,     SMART_SCRIPT_TYPE_MASK_INSTANCE },
    {SMART_EVENT_AREATRIGGER_ONTRIGGER,     SMART_SCRIPT_TYPE_MASK_AREATRIGGER },
    {SMART_EVENT_QUEST_ACCEPTED,            SMART_SCRIPT_TYPE_MASK_QUEST },
    {SMART_EVENT_QUEST_OBJ_COPLETETION,     SMART_SCRIPT_TYPE_MASK_QUEST },
    {SMART_EVENT_QUEST_REWARDED,            SMART_SCRIPT_TYPE_MASK_QUEST },
    {SMART_EVENT_QUEST_COMPLETION,          SMART_SCRIPT_TYPE_MASK_QUEST },
    {SMART_EVENT_QUEST_FAIL,                SMART_SCRIPT_TYPE_MASK_QUEST },
    {SMART_EVENT_TEXT_OVER,                 SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_RECEIVE_HEAL,              SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_JUST_SUMMONED,             SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_WAYPOINT_PAUSED,           SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_WAYPOINT_RESUMED,          SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_WAYPOINT_STOPPED,          SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_WAYPOINT_ENDED,            SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_TIMED_EVENT_TRIGGERED,     SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_UPDATE,                    SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_LINK,                      SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT + SMART_SCRIPT_TYPE_MASK_AREATRIGGER + SMART_SCRIPT_TYPE_MASK_EVENT + SMART_SCRIPT_TYPE_MASK_GOSSIP + SMART_SCRIPT_TYPE_MASK_QUEST + SMART_SCRIPT_TYPE_MASK_SPELL + SMART_SCRIPT_TYPE_MASK_TRANSPORT + SMART_SCRIPT_TYPE_MASK_INSTANCE },
    {SMART_EVENT_GOSSIP_SELECT,             SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_JUST_CREATED,              SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_GOSSIP_HELLO,              SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_FOLLOW_COMPLETED,          SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_DUMMY_EFFECT,              SMART_SCRIPT_TYPE_MASK_SPELL    },
    {SMART_EVENT_IS_BEHIND_TARGET,          SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_GAME_EVENT_START,          SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_GAME_EVENT_END,            SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_GO_STATE_CHANGED,          SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },

};

enum SmartEventFlags
{
    SMART_EVENT_FLAG_NOT_REPEATABLE        = 0x01,                     //Event can not repeat
    SMART_EVENT_FLAG_DIFFICULTY_0          = 0x02,                     //Event only occurs in instance difficulty 0
    SMART_EVENT_FLAG_DIFFICULTY_1          = 0x04,                     //Event only occurs in instance difficulty 1
    SMART_EVENT_FLAG_DIFFICULTY_2          = 0x08,                     //Event only occurs in instance difficulty 2
    SMART_EVENT_FLAG_DIFFICULTY_3          = 0x10,                     //Event only occurs in instance difficulty 3
    SMART_EVENT_FLAG_RESERVED_5            = 0x20,
    SMART_EVENT_FLAG_RESERVED_6            = 0x40,
    SMART_EVENT_FLAG_DEBUG_ONLY            = 0x80,                     //Event only occurs in debug build

    SMART_EVENT_FLAG_DIFFICULTY_ALL        = (SMART_EVENT_FLAG_DIFFICULTY_0|SMART_EVENT_FLAG_DIFFICULTY_1|SMART_EVENT_FLAG_DIFFICULTY_2|SMART_EVENT_FLAG_DIFFICULTY_3)
};

enum SmartCastFlags
{
    SMARTCAST_INTERRUPT_PREVIOUS     = 0x01,                     //Interrupt any spell casting
    SMARTCAST_TRIGGERED              = 0x02,                     //Triggered (this makes spell cost zero mana and have no cast time)
    //CAST_FORCE_CAST             = 0x04,                     //Forces cast even if creature is out of mana or out of range
    //CAST_NO_MELEE_IF_OOM        = 0x08,                     //Prevents creature from entering melee if out of mana or out of range
    //CAST_FORCE_TARGET_SELF      = 0x10,                     //Forces the target to cast this spell on itself
    //CAST_AURA_NOT_PRESENT       = 0x20,                     //Only casts the spell if the target does not have an aura from the spell
};

// one line in DB is one event
struct SmartScriptHolder
{
    SmartScriptHolder()
    {
        timer = 0;
        active = false;
        runOnce = false;
        link = 0;
        entryOrGuid = 0;
        event_id = 0;
        enableTimed = false;
    }
    int32 entryOrGuid;
    SmartScriptType source_type;
    uint32 event_id;
    uint32 link;

    SmartEvent event;
    SmartAction action;
    SmartTarget target;

    public:
        uint32 GetScriptType() const { return (uint32)source_type; }
        uint32 GetEventType() const { return (uint32)event.type; }
        uint32 GetActionType() const { return (uint32)action.type; }
        uint32 GetTargetType() const { return (uint32)target.type; }

    uint32 timer;
    bool active;
    bool runOnce;
    bool enableTimed;

};

typedef UNORDERED_MAP<uint32, WayPoint*> WPPath;

typedef std::list<WorldObject*> ObjectList;
typedef UNORDERED_MAP<uint32, ObjectList*> ObjectListMap;

class SmartWaypointMgr
{
    friend class ACE_Singleton<SmartWaypointMgr, ACE_Null_Mutex>;
    SmartWaypointMgr(){};
    public:
        ~SmartWaypointMgr(){};

        void LoadFromDB();

        WPPath* GetPath(uint32 id)
        {
            if (waypoint_map.find(id) != waypoint_map.end())
                return waypoint_map[id];
            else return 0;
        }

    private:
        UNORDERED_MAP<uint32, WPPath*> waypoint_map;
};

// all events for a single entry
typedef std::vector<SmartScriptHolder> SmartAIEventList;

// all events for all entries / guids
typedef UNORDERED_MAP<int32, SmartAIEventList> SmartAIEventMap;

class SmartAIMgr
{
    friend class ACE_Singleton<SmartAIMgr, ACE_Null_Mutex>;
    SmartAIMgr(){};
    public:
        ~SmartAIMgr(){};

        void LoadSmartAIFromDB();

        SmartAIEventList GetScript(int32 entry, SmartScriptType type)
        {
            SmartAIEventList temp;
            if (mEventMap[uint32(type)].find(entry) != mEventMap[uint32(type)].end())
                return mEventMap[uint32(type)][entry];
            else
            {
                if (entry > 0)//first search is for guid (negative), do not drop error if not found
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartAIMgr::GetScript: Could not load Script for Entry %d ScriptType %u.", entry, uint32(type));
                return temp;
            }
        }

    private:
        //event stores
        SmartAIEventMap mEventMap[SMART_SCRIPT_TYPE_MAX];

        bool IsEventValid(SmartScriptHolder& e);
        bool IsTargetValid(SmartScriptHolder const& e);

        /*inline bool IsTargetValid(SmartScriptHolder e, int32 target)
        {
            if (target < SMART_TARGET_NONE || target >= SMART_TARGET_END)
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses invalid Target type %d, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), target);
                return false;
            }
            return true;
        }*/

        bool IsMinMaxValid(SmartScriptHolder const& e, uint32 min, uint32 max)
        {
            if (max < min)
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses min/max params wrong (%u/%u), skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), min, max);
                return false;
            }
            return true;
        }

        /*inline bool IsPercentValid(SmartScriptHolder e, int32 pct)
        {
            if (pct < -100 || pct > 100)
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u has invalid Percent set (%d), skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), pct);
                return false;
            }
            return true;
        }*/

        bool NotNULL(SmartScriptHolder const& e, uint32 data)
        {
            if (!data)
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u Parameter can not be NULL, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            return true;
        }

        bool IsCreatureValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sObjectMgr->GetCreatureTemplate(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Creature entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }

        bool IsQuestValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sObjectMgr->GetQuestTemplate(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Quest entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }

        bool IsGameObjectValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sObjectMgr->GetGameObjectTemplate(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent GameObject entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }

        bool IsSpellValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sSpellMgr->GetSpellInfo(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Spell entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }

        bool IsItemValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sItemStore.LookupEntry(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Item entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }
        /*inline bool IsConditionValid(SmartScriptHolder e, int32 t, int32 v1, int32 v2, int32 v3)
        {
            bool error = false;
            if (t > 0 && v1 >= 0 && v2 >= 0 && v3 >= 0)
            {
                Condition cond;
                cond.mConditionType = ConditionType(t);
                cond.mConditionValue1 = uint32(v1);
                cond.mConditionValue2 = uint32(v2);
                cond.mConditionValue3 = uint32(v3);
                if (!sConditionMgr->isConditionTypeValid(&cond))
                    error = true;
            }
            if (error)
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses invalid Condition, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            return true;
        }*/

        bool IsTextEmoteValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sEmotesTextStore.LookupEntry(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Text Emote entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }

        bool IsEmoteValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sEmotesStore.LookupEntry(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Emote entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }

        bool IsAreaTriggerValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sAreaTriggerStore.LookupEntry(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent AreaTrigger entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }

        bool IsSoundValid(SmartScriptHolder const& e, uint32 entry)
        {
            if (!sSoundEntriesStore.LookupEntry(entry))
            {
                sLog->outErrorDb("SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Sound entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
                return false;
            }
            return true;
        }

        bool IsTextValid(SmartScriptHolder const& e, uint32 id);
};

#define sSmartScriptMgr ACE_Singleton<SmartAIMgr, ACE_Null_Mutex>::instance()
#define sSmartWaypointMgr ACE_Singleton<SmartWaypointMgr, ACE_Null_Mutex>::instance()
#endif
