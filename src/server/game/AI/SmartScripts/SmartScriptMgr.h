/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Define.h"
#include "ObjectGuid.h"
#include "WaypointDefines.h"
#include <map>
#include <string>
#include <unordered_map>

class WorldObject;
enum SpellEffIndex : uint8;

enum eSmartAI
{
    SMART_EVENT_PARAM_COUNT = 4,
    SMART_ACTION_PARAM_COUNT = 6,
    SMART_SUMMON_COUNTER = 0xFFFFFF,
    SMART_ESCORT_LAST_OOC_POINT = 0xFFFFFF,
    SMART_RANDOM_POINT = 0xFFFFFE,
    SMART_ESCORT_TARGETS = 0xFFFFFF
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
    SMART_EVENT_PHASE_7       = 7,
    SMART_EVENT_PHASE_8       = 8,
    SMART_EVENT_PHASE_9       = 9,
    SMART_EVENT_PHASE_10      = 10,
    SMART_EVENT_PHASE_11      = 11,
    SMART_EVENT_PHASE_12      = 12,
    SMART_EVENT_PHASE_MAX     = 13,

    SMART_EVENT_PHASE_COUNT   = 12
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
    SMART_EVENT_PHASE_7_BIT        = 64,
    SMART_EVENT_PHASE_8_BIT        = 128,
    SMART_EVENT_PHASE_9_BIT        = 256,
    SMART_EVENT_PHASE_10_BIT       = 512,
    SMART_EVENT_PHASE_11_BIT       = 1024,
    SMART_EVENT_PHASE_12_BIT       = 2048,
    SMART_EVENT_PHASE_ALL          = SMART_EVENT_PHASE_1_BIT + SMART_EVENT_PHASE_2_BIT + SMART_EVENT_PHASE_3_BIT + SMART_EVENT_PHASE_4_BIT + SMART_EVENT_PHASE_5_BIT +
                                     SMART_EVENT_PHASE_6_BIT + SMART_EVENT_PHASE_7_BIT + SMART_EVENT_PHASE_8_BIT + SMART_EVENT_PHASE_9_BIT + SMART_EVENT_PHASE_10_BIT +
                                     SMART_EVENT_PHASE_11_BIT + SMART_EVENT_PHASE_12_BIT
};

const uint32 SmartPhaseMask[SMART_EVENT_PHASE_COUNT][2] =
{
    {SMART_EVENT_PHASE_1, SMART_EVENT_PHASE_1_BIT },
    {SMART_EVENT_PHASE_2, SMART_EVENT_PHASE_2_BIT },
    {SMART_EVENT_PHASE_3, SMART_EVENT_PHASE_3_BIT },
    {SMART_EVENT_PHASE_4, SMART_EVENT_PHASE_4_BIT },
    {SMART_EVENT_PHASE_5, SMART_EVENT_PHASE_5_BIT },
    {SMART_EVENT_PHASE_6, SMART_EVENT_PHASE_6_BIT },
    {SMART_EVENT_PHASE_7, SMART_EVENT_PHASE_7_BIT },
    {SMART_EVENT_PHASE_8, SMART_EVENT_PHASE_8_BIT },
    {SMART_EVENT_PHASE_9, SMART_EVENT_PHASE_9_BIT },
    {SMART_EVENT_PHASE_10, SMART_EVENT_PHASE_10_BIT },
    {SMART_EVENT_PHASE_11, SMART_EVENT_PHASE_11_BIT },
    {SMART_EVENT_PHASE_12, SMART_EVENT_PHASE_12_BIT }
};

enum SMART_EVENT
{
    SMART_EVENT_UPDATE_IC                = 0,       // InitialMin, InitialMax, RepeatMin, RepeatMax
    SMART_EVENT_UPDATE_OOC               = 1,       // InitialMin, InitialMax, RepeatMin, RepeatMax
    SMART_EVENT_HEALT_PCT                = 2,       // HPMin%, HPMax%,  RepeatMin, RepeatMax
    SMART_EVENT_MANA_PCT                 = 3,       // ManaMin%, ManaMax%, RepeatMin, RepeatMax
    SMART_EVENT_AGGRO                    = 4,       // NONE
    SMART_EVENT_KILL                     = 5,       // CooldownMin0, CooldownMax1, playerOnly2, else creature entry3
    SMART_EVENT_DEATH                    = 6,       // NONE
    SMART_EVENT_EVADE                    = 7,       // NONE
    SMART_EVENT_SPELLHIT                 = 8,       // SpellID, School, CooldownMin, CooldownMax
    SMART_EVENT_RANGE                    = 9,       // MinDist, MaxDist, RepeatMin, RepeatMax
    SMART_EVENT_OOC_LOS                  = 10,      // NoHostile, MaxRnage, CooldownMin, CooldownMax
    SMART_EVENT_RESPAWN                  = 11,      // type, MapId, ZoneId
    SMART_EVENT_TARGET_HEALTH_PCT        = 12,      // HPMin%, HPMax%, RepeatMin, RepeatMax
    SMART_EVENT_VICTIM_CASTING           = 13,      // RepeatMin, RepeatMax, spellid
    SMART_EVENT_FRIENDLY_HEALTH          = 14,      // HPDeficit, Radius, RepeatMin, RepeatMax
    SMART_EVENT_FRIENDLY_IS_CC           = 15,      // Radius, RepeatMin, RepeatMax
    SMART_EVENT_FRIENDLY_MISSING_BUFF    = 16,      // SpellId, Radius, RepeatMin, RepeatMax
    SMART_EVENT_SUMMONED_UNIT            = 17,      // CreatureId(0 all), CooldownMin, CooldownMax
    SMART_EVENT_TARGET_MANA_PCT          = 18,      // ManaMin%, ManaMax%, RepeatMin, RepeatMax
    SMART_EVENT_ACCEPTED_QUEST           = 19,      // QuestID(0any)
    SMART_EVENT_REWARD_QUEST             = 20,      // QuestID(0any)
    SMART_EVENT_REACHED_HOME             = 21,      // NONE
    SMART_EVENT_RECEIVE_EMOTE            = 22,      // EmoteId, CooldownMin, CooldownMax, condition, val1, val2, val3
    SMART_EVENT_HAS_AURA                 = 23,      // Param1 = SpellID, Param2 = Stack amount, Param3/4 RepeatMin, RepeatMax
    SMART_EVENT_TARGET_BUFFED            = 24,      // Param1 = SpellID, Param2 = Stack amount, Param3/4 RepeatMin, RepeatMax
    SMART_EVENT_RESET                    = 25,      // Called after combat, when the creature respawn and spawn.
    SMART_EVENT_IC_LOS                   = 26,      // NoHostile, MaxRnage, CooldownMin, CooldownMax
    SMART_EVENT_PASSENGER_BOARDED        = 27,      // CooldownMin, CooldownMax
    SMART_EVENT_PASSENGER_REMOVED        = 28,      // CooldownMin, CooldownMax
    SMART_EVENT_CHARMED                  = 29,      // onRemove (0 - on apply, 1 - on remove)
    SMART_EVENT_CHARMED_TARGET           = 30,      // NONE
    SMART_EVENT_SPELLHIT_TARGET          = 31,      // SpellID, School, CooldownMin, CooldownMax
    SMART_EVENT_DAMAGED                  = 32,      // MinDmg, MaxDmg, CooldownMin, CooldownMax
    SMART_EVENT_DAMAGED_TARGET           = 33,      // MinDmg, MaxDmg, CooldownMin, CooldownMax
    SMART_EVENT_MOVEMENTINFORM           = 34,      // MovementType(any), PointID
    SMART_EVENT_SUMMON_DESPAWNED         = 35,      // Entry, CooldownMin, CooldownMax
    SMART_EVENT_CORPSE_REMOVED           = 36,      // NONE
    SMART_EVENT_AI_INIT                  = 37,      // NONE
    SMART_EVENT_DATA_SET                 = 38,      // Id, Value, CooldownMin, CooldownMax
    SMART_EVENT_WAYPOINT_START           = 39,      // PointId(0any), pathID(0any)
    SMART_EVENT_WAYPOINT_REACHED         = 40,      // PointId(0any), pathID(0any)
    SMART_EVENT_TRANSPORT_ADDPLAYER      = 41,      // NONE
    SMART_EVENT_TRANSPORT_ADDCREATURE    = 42,      // Entry (0 any)
    SMART_EVENT_TRANSPORT_REMOVE_PLAYER  = 43,      // NONE
    SMART_EVENT_TRANSPORT_RELOCATE       = 44,      // PointId
    SMART_EVENT_INSTANCE_PLAYER_ENTER    = 45,      // Team (0 any), CooldownMin, CooldownMax
    SMART_EVENT_AREATRIGGER_ONTRIGGER    = 46,      // TriggerId(0 any)
    SMART_EVENT_QUEST_ACCEPTED           = 47,      // none
    SMART_EVENT_QUEST_OBJ_COPLETETION    = 48,      // none
    SMART_EVENT_QUEST_COMPLETION         = 49,      // none
    SMART_EVENT_QUEST_REWARDED           = 50,      // none
    SMART_EVENT_QUEST_FAIL               = 51,      // none
    SMART_EVENT_TEXT_OVER                = 52,      // GroupId from creature_text,  creature entry who talks (0 any)
    SMART_EVENT_RECEIVE_HEAL             = 53,      // MinHeal, MaxHeal, CooldownMin, CooldownMax
    SMART_EVENT_JUST_SUMMONED            = 54,      // none
    SMART_EVENT_WAYPOINT_PAUSED          = 55,      // PointId(0any), pathID(0any)
    SMART_EVENT_WAYPOINT_RESUMED         = 56,      // PointId(0any), pathID(0any)
    SMART_EVENT_WAYPOINT_STOPPED         = 57,      // PointId(0any), pathID(0any)
    SMART_EVENT_WAYPOINT_ENDED           = 58,      // PointId(0any), pathID(0any)
    SMART_EVENT_TIMED_EVENT_TRIGGERED    = 59,      // id
    SMART_EVENT_UPDATE                   = 60,      // InitialMin, InitialMax, RepeatMin, RepeatMax
    SMART_EVENT_LINK                     = 61,      // INTERNAL USAGE, no params, used to link together multiple events, does not use any extra resources to iterate event lists needlessly
    SMART_EVENT_GOSSIP_SELECT            = 62,      // menuID, actionID
    SMART_EVENT_JUST_CREATED             = 63,      // none
    SMART_EVENT_GOSSIP_HELLO             = 64,      // noReportUse (for GOs)
    SMART_EVENT_FOLLOW_COMPLETED         = 65,      // none
    SMART_EVENT_EVENT_PHASE_CHANGE       = 66,      // event phase mask (<= SMART_EVENT_PHASE_ALL)
    SMART_EVENT_IS_BEHIND_TARGET         = 67,      // cooldownMin, CooldownMax
    SMART_EVENT_GAME_EVENT_START         = 68,      // game_event.Entry
    SMART_EVENT_GAME_EVENT_END           = 69,      // game_event.Entry
    SMART_EVENT_GO_LOOT_STATE_CHANGED    = 70,      // go LootState
    SMART_EVENT_GO_EVENT_INFORM          = 71,      // eventId
    SMART_EVENT_ACTION_DONE              = 72,      // eventId (SharedDefines.EventId)
    SMART_EVENT_ON_SPELLCLICK            = 73,      // clicker (unit)
    SMART_EVENT_FRIENDLY_HEALTH_PCT      = 74,      // minHpPct, maxHpPct, repeatMin, repeatMax
    SMART_EVENT_DISTANCE_CREATURE        = 75,      // guid, entry, distance, repeat
    SMART_EVENT_DISTANCE_GAMEOBJECT      = 76,      // guid, entry, distance, repeat
    SMART_EVENT_COUNTER_SET              = 77,      // id, value, cooldownMin, cooldownMax
    SMART_EVENT_SCENE_START              = 78,      // none
    SMART_EVENT_SCENE_TRIGGER            = 79,      // param_string : triggerName
    SMART_EVENT_SCENE_CANCEL             = 80,      // none
    SMART_EVENT_SCENE_COMPLETE           = 81,      // none

    SMART_EVENT_END                      = 82
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
            uint32 playerOnly;
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
            uint32 repeatMin;
            uint32 repeatMax;
            uint32 spellId;
        } targetCasting;

        struct
        {
            uint32 hpDeficit;
            uint32 radius;
            uint32 repeatMin;
            uint32 repeatMax;
        } friendlyHealth;

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
            uint32 id;
        } questObjective;

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
            uint32 onRemove;
        } charm;

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
            uint32 noReportUse;
        } gossipHello;

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
            uint32 phasemask;
        } eventPhaseChange;

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
            uint32 lootState;
        } goLootStateChanged;

        struct
        {
            uint32 eventId;
        } eventInform;

        struct
        {
            uint32 eventId;
        } doAction;

        struct
        {
            uint32 minHpPct;
            uint32 maxHpPct;
            uint32 repeatMin;
            uint32 repeatMax;
        } friendlyHealthPct;

        struct
        {
            uint32 guid;
            uint32 entry;
            uint32 dist;
            uint32 repeat;
        } distance;

        struct
        {
            uint32 id;
            uint32 value;
            uint32 cooldownMin;
            uint32 cooldownMax;
        } counter;

        struct
        {
            uint32 sceneId;
        } scene;

        struct
        {
            uint32 param1;
            uint32 param2;
            uint32 param3;
            uint32 param4;
            uint32 param5;
        } raw;
    };

    std::string param_string;
};

enum SMART_SCRIPT_RESPAWN_CONDITION
{
    SMART_SCRIPT_RESPAWN_CONDITION_NONE = 0,
    SMART_SCRIPT_RESPAWN_CONDITION_MAP = 1,
    SMART_SCRIPT_RESPAWN_CONDITION_AREA = 2,
    SMART_SCRIPT_RESPAWN_CONDITION_END = 3
};

enum SMART_ACTION
{
    SMART_ACTION_NONE                               = 0,      // No action
    SMART_ACTION_TALK                               = 1,      // groupID from creature_text, duration to wait before TEXT_OVER event is triggered, useTalkTarget (0/1) - use target as talk target
    SMART_ACTION_SET_FACTION                        = 2,      // FactionId (or 0 for default)
    SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL            = 3,      // Creature_template entry(param1) OR ModelId (param2) (or 0 for both to demorph)
    SMART_ACTION_SOUND                              = 4,      // SoundId, onlySelf
    SMART_ACTION_PLAY_EMOTE                         = 5,      // EmoteId
    SMART_ACTION_FAIL_QUEST                         = 6,      // QuestID
    SMART_ACTION_OFFER_QUEST                        = 7,      // QuestID, directAdd
    SMART_ACTION_SET_REACT_STATE                    = 8,      // state
    SMART_ACTION_ACTIVATE_GOBJECT                   = 9,      //
    SMART_ACTION_RANDOM_EMOTE                       = 10,     // EmoteId1, EmoteId2, EmoteId3...
    SMART_ACTION_CAST                               = 11,     // SpellId, CastFlags, TriggeredFlags
    SMART_ACTION_SUMMON_CREATURE                    = 12,     // CreatureID, summonType, duration in ms, attackInvoker, flags(SmartActionSummonCreatureFlags)
    SMART_ACTION_THREAT_SINGLE_PCT                  = 13,     // Threat%
    SMART_ACTION_THREAT_ALL_PCT                     = 14,     // Threat%
    SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS    = 15,     // QuestID
    SMART_ACTION_SET_INGAME_PHASE_GROUP             = 16,     // phaseGroupId, apply
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
    SMART_ACTION_COMBAT_STOP                        = 27,     //
    SMART_ACTION_REMOVEAURASFROMSPELL               = 28,     // Spellid (0 removes all auras), charges (0 removes aura)
    SMART_ACTION_FOLLOW                             = 29,     // Distance (0 = default), Angle (0 = default), EndCreatureEntry, credit, creditType (0monsterkill, 1event)
    SMART_ACTION_RANDOM_PHASE                       = 30,     // PhaseId1, PhaseId2, PhaseId3...
    SMART_ACTION_RANDOM_PHASE_RANGE                 = 31,     // PhaseMin, PhaseMax
    SMART_ACTION_RESET_GOBJECT                      = 32,     //
    SMART_ACTION_CALL_KILLEDMONSTER                 = 33,     // CreatureId,
    SMART_ACTION_SET_INST_DATA                      = 34,     // Field, Data, Type (0 = SetData, 1 = SetBossState)
    SMART_ACTION_SET_INST_DATA64                    = 35,     // Field,
    SMART_ACTION_UPDATE_TEMPLATE                    = 36,     // Entry
    SMART_ACTION_DIE                                = 37,     // No Params
    SMART_ACTION_SET_IN_COMBAT_WITH_ZONE            = 38,     // No Params
    SMART_ACTION_CALL_FOR_HELP                      = 39,     // Radius, With Emote
    SMART_ACTION_SET_SHEATH                         = 40,     // Sheath (0-unarmed, 1-melee, 2-ranged)
    SMART_ACTION_FORCE_DESPAWN                      = 41,     // timer
    SMART_ACTION_SET_INVINCIBILITY_HP_LEVEL         = 42,     // MinHpValue(+pct, -flat)
    SMART_ACTION_MOUNT_TO_ENTRY_OR_MODEL            = 43,     // Creature_template entry(param1) OR ModelId (param2) (or 0 for both to dismount)
    SMART_ACTION_SET_INGAME_PHASE_ID                = 44,     // PhaseId, apply
    SMART_ACTION_SET_DATA                           = 45,     // Field, Data (only creature @todo)
    SMART_ACTION_SET_VISIBILITY                     = 47,     // on/off
    SMART_ACTION_SET_ACTIVE                         = 48,     // on/off
    SMART_ACTION_ATTACK_START                       = 49,     //
    SMART_ACTION_SUMMON_GO                          = 50,     // GameObjectID, DespawnTime in s
    SMART_ACTION_KILL_UNIT                          = 51,     //
    SMART_ACTION_ACTIVATE_TAXI                      = 52,     // TaxiID
    SMART_ACTION_WP_START                           = 53,     // run/walk, pathID, canRepeat, quest, despawntime, reactState
    SMART_ACTION_WP_PAUSE                           = 54,     // time
    SMART_ACTION_WP_STOP                            = 55,     // despawnTime, quest, fail?
    SMART_ACTION_ADD_ITEM                           = 56,     // itemID, count
    SMART_ACTION_REMOVE_ITEM                        = 57,     // itemID, count
    SMART_ACTION_INSTALL_AI_TEMPLATE                = 58,     // AITemplateID
    SMART_ACTION_SET_RUN                            = 59,     // 0/1
    SMART_ACTION_SET_DISABLE_GRAVITY                = 60,     // 0/1
    SMART_ACTION_SET_SWIM                           = 61,     // 0/1
    SMART_ACTION_TELEPORT                           = 62,     // mapID,
    SMART_ACTION_SET_COUNTER                        = 63,     // id, value, reset (0/1)
    SMART_ACTION_STORE_TARGET_LIST                  = 64,     // varID,
    SMART_ACTION_WP_RESUME                          = 65,     // none
    SMART_ACTION_SET_ORIENTATION                    = 66,     //
    SMART_ACTION_CREATE_TIMED_EVENT                 = 67,     // id, InitialMin, InitialMax, RepeatMin(only if it repeats), RepeatMax(only if it repeats), chance
    SMART_ACTION_PLAYMOVIE                          = 68,     // entry
    SMART_ACTION_MOVE_TO_POS                        = 69,     // PointId, transport, disablePathfinding, ContactDistance
    SMART_ACTION_ENABLE_TEMP_GOBJ                   = 70,     // despawnTimer (sec)
    SMART_ACTION_EQUIP                              = 71,     // entry, slotmask slot1, slot2, slot3   , only slots with mask set will be sent to client, bits are 1, 2, 4, leaving mask 0 is defaulted to mask 7 (send all), slots1-3 are only used if no entry is set
    SMART_ACTION_CLOSE_GOSSIP                       = 72,     // none
    SMART_ACTION_TRIGGER_TIMED_EVENT                = 73,     // id(>1)
    SMART_ACTION_REMOVE_TIMED_EVENT                 = 74,     // id(>1)
    SMART_ACTION_ADD_AURA                           = 75,     // spellid,  targets
    SMART_ACTION_OVERRIDE_SCRIPT_BASE_OBJECT        = 76,     // WARNING: CAN CRASH CORE, do not use if you dont know what you are doing
    SMART_ACTION_RESET_SCRIPT_BASE_OBJECT           = 77,     // none
    SMART_ACTION_CALL_SCRIPT_RESET                  = 78,     // none
    SMART_ACTION_SET_RANGED_MOVEMENT                = 79,     // Distance, angle
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
    SMART_ACTION_SEND_GOSSIP_MENU                   = 98,     // menuId, optionIndex
    SMART_ACTION_GO_SET_LOOT_STATE                  = 99,     // state
    SMART_ACTION_SEND_TARGET_TO_TARGET              = 100,    // id
    SMART_ACTION_SET_HOME_POS                       = 101,    // none
    SMART_ACTION_SET_HEALTH_REGEN                   = 102,    // 0/1
    SMART_ACTION_SET_ROOT                           = 103,    // off/on
    SMART_ACTION_SET_GO_FLAG                        = 104,    // Flags
    SMART_ACTION_ADD_GO_FLAG                        = 105,    // Flags
    SMART_ACTION_REMOVE_GO_FLAG                     = 106,    // Flags
    SMART_ACTION_SUMMON_CREATURE_GROUP              = 107,    // Group, attackInvoker
    SMART_ACTION_SET_POWER                          = 108,    // PowerType, newPower
    SMART_ACTION_ADD_POWER                          = 109,    // PowerType, newPower
    SMART_ACTION_REMOVE_POWER                       = 110,    // PowerType, newPower
    SMART_ACTION_GAME_EVENT_STOP                    = 111,    // GameEventId
    SMART_ACTION_GAME_EVENT_START                   = 112,    // GameEventId
    SMART_ACTION_START_CLOSEST_WAYPOINT             = 113,    // wp1, wp2, wp3, wp4, wp5, wp6, wp7
    SMART_ACTION_MOVE_OFFSET                        = 114,
    SMART_ACTION_RANDOM_SOUND                       = 115,    // soundId1, soundId2, soundId3, soundId4, soundId5, onlySelf
    SMART_ACTION_SET_CORPSE_DELAY                   = 116,    // timer
    SMART_ACTION_DISABLE_EVADE                      = 117,    // 0/1 (1 = disabled, 0 = enabled)
    SMART_ACTION_GO_SET_GO_STATE                    = 118,    // state
    SMART_ACTION_SET_CAN_FLY                        = 119,    // 0/1
    SMART_ACTION_REMOVE_AURAS_BY_TYPE               = 120,    // type
    SMART_ACTION_SET_SIGHT_DIST                     = 121,    // sightDistance
    SMART_ACTION_FLEE                               = 122,    // fleeTime
    SMART_ACTION_ADD_THREAT                         = 123,    // +threat, -threat
    SMART_ACTION_LOAD_EQUIPMENT                     = 124,    // id
    SMART_ACTION_TRIGGER_RANDOM_TIMED_EVENT         = 125,    // id min range, id max range
    SMART_ACTION_REMOVE_ALL_GAMEOBJECTS             = 126,
    SMART_ACTION_STOP_MOTION                        = 127,    // stopMoving, movementExpired
    SMART_ACTION_PLAY_ANIMKIT                       = 128,    // id, type (0 = oneShot, 1 = aiAnim, 2 = meleeAnim, 3 = movementAnim)
    SMART_ACTION_SCENE_PLAY                         = 129,    // sceneId
    SMART_ACTION_SCENE_CANCEL                       = 130,    // sceneId
    SMART_ACTION_SPAWN_SPAWNGROUP                   = 131,    // Group ID, min secs, max secs, spawnflags
    SMART_ACTION_DESPAWN_SPAWNGROUP                 = 132,    // Group ID, min secs, max secs, spawnflags
    SMART_ACTION_RESPAWN_BY_SPAWNID                 = 133,    // spawnType, spawnId
    // 134 : 3.3.5 reserved
    SMART_ACTION_PLAY_CINEMATIC                     = 135,    // reserved for future uses
    SMART_ACTION_SET_MOVEMENT_SPEED                 = 136,    // movementType, speedInteger, speedFraction
    SMART_ACTION_PLAY_SPELL_VISUAL_KIT              = 137,    // spellVisualKitId, kitType (unknown values, copypaste from packet dumps), duration
    SMART_ACTION_CREATE_CONVERSATION                = 143,    // conversation_template.id
    SMART_ACTION_END                                = 144
};

enum class SmartActionSummonCreatureFlags
{
    None = 0,
    PersonalSpawn = 1,
    PreferUnit = 2,

    All = PersonalSpawn | PreferUnit,
};

DEFINE_ENUM_FLAG(SmartActionSummonCreatureFlags);

struct SmartAction
{
    SMART_ACTION type;

    union
    {
        struct
        {
            uint32 textGroupID;
            uint32 duration;
            uint32 useTalkTarget;
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
            uint32 onlySelf;
            uint32 distance;
            uint32 keyBroadcastTextId;
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
            uint32 questID;
            uint32 directAdd;
        } questOffer;

        struct
        {
            uint32 state;
        } react;

        struct
        {
            uint32 emotes[SMART_ACTION_PARAM_COUNT];
        } randomEmote;

        struct
        {
            uint32 spell;
            uint32 castFlags;
            uint32 triggerFlags;
            uint32 targetsLimit;
        } cast;

        struct
        {
            uint32 spell;
            uint32 castFlags;
            uint32 targetType;
            uint32 targetParam1;
            uint32 targetParam2;
            uint32 targetParam3;
        } crossCast;

        struct
        {
            uint32 creature;
            uint32 type;
            uint32 duration;
            uint32 attackInvoker;
            uint32 flags; // SmartActionSummonCreatureFlags
        } summonCreature;

        struct
        {
            uint32 threatINC;
            uint32 threatDEC;
        } threatPCT;

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
            uint32 spell;
            uint32 charges;
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
            uint32 phases[SMART_ACTION_PARAM_COUNT];
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
            uint32 type;
        } setInstanceData;

        struct
        {
            uint32 field;
        } setInstanceData64;

        struct
        {
            uint32 creature;
            uint32 updateLevel;
        } updateTemplate;

        struct
        {
            uint32 range;
            uint32 withEmote;
        } callHelp;

        struct
        {
            uint32 sheath;
        } setSheath;

        struct
        {
            uint32 delay;
            uint32 forceRespawnTimer;
        } forceDespawn;

        struct
        {
            uint32 minHP;
            uint32 percent;
        } invincHP;

        struct
        {
            uint32 id;
            uint32 apply;
        } ingamePhaseId;

        struct
        {
            uint32 groupId;
            uint32 apply;
        } ingamePhaseGroup;

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
            uint32 summonType;
        } summonGO;

        struct
        {
            uint32 state;
        } active;

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
            uint32 disable;
        } setDisableGravity;

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
            uint32 counterId;
            uint32 value;
            uint32 reset;
        } setCounter;

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
            uint32 type;
        } unitFlag;

        struct
        {
            uint32 byte1;
            uint32 type;
        } setunitByte;

        struct
        {
            uint32 byte1;
            uint32 type;
        } delunitByte;

        struct
        {
            uint32 seat;
        } enterVehicle;

        struct
        {
            uint32 id;
            uint32 timerType;
        } timedActionList;

        struct
        {
            uint32 actionLists[SMART_ACTION_PARAM_COUNT];
        } randTimedActionList;

        struct
        {
            uint32 withDelayed;
            uint32 spell_id;
            uint32 withInstant;
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
        } fleeAssist;

        struct
        {
            uint32 fleeTime;
        } flee;

        struct
        {
            uint32 duration;
        } enableTempGO;

        struct
        {
            uint32 pointId;
            uint32 transport;
            uint32 disablePathfinding;
            uint32 ContactDistance;
        } MoveToPos;

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
            uint32 id;
        } sendTargetToTarget;

        struct
        {
            uint32 distance;
            uint32 angle;
        } setRangedMovement;

        struct
        {
            uint32 regenHealth;
        } setHealthRegen;

        struct
        {
            uint32 root;
        } setRoot;

        struct
        {
            uint32 flag;
        } goFlag;

        struct
        {
            uint32 state;
        } goState;

        struct
        {
            uint32 group;
            uint32 attackInvoker;
        } creatureGroup;

        struct
        {
            uint32 powerType;
            uint32 newPower;
        } power;

        struct
        {
            uint32 id;
        } gameEventStop;

        struct
        {
            uint32 id;
        } gameEventStart;

        struct
        {
            uint32 wps[SMART_ACTION_PARAM_COUNT];
        } closestWaypointFromList;

        struct
        {
            uint32 sounds[SMART_ACTION_PARAM_COUNT - 2];
            uint32 onlySelf;
            uint32 distance;
        } randomSound;

        struct
        {
            uint32 timer;
        } corpseDelay;

        struct
        {
            uint32 disable;
        } disableEvade;
        struct
        {
            uint32 groupId;
            uint32 minDelay;
            uint32 maxDelay;
            uint32 spawnflags;
        } groupSpawn;

        struct
        {
            uint32 type;
        } auraType;

        struct
        {
            uint32 dist;
        } sightDistance;

        struct
        {
            uint32 id;
            uint32 force;
        } loadEquipment;

        struct
        {
            uint32 minId;
            uint32 maxId;
        } randomTimedEvent;

        struct
        {
            uint32 stopMovement;
            uint32 movementExpired;
        } stopMotion;

        struct
        {
            uint32 spawnType;
            uint32 spawnId;
        } respawnData;

        struct
        {
            uint32 animKit;
            uint32 type;
        } animKit;

        struct
        {
            uint32 sceneId;
        } scene;

        struct
        {
            uint32 movementType;
            uint32 speedInteger;
            uint32 speedFraction;
        } movementSpeed;

        struct
        {
            uint32 spellVisualKitId;
            uint32 kitType;
            uint32 duration;
        } spellVisualKit;

        struct
        {
            uint32 id;
        } conversation;

        //! Note for any new future actions
        //! All parameters must have type uint32

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

enum SMARTAI_SPAWN_FLAGS
{
    SMARTAI_SPAWN_FLAG_NONE                 = 0x00,
    SMARTAI_SPAWN_FLAG_IGNORE_RESPAWN       = 0x01,
    SMARTAI_SPAWN_FLAG_FORCE_SPAWN          = 0x02,
    SMARTAI_SPAWN_FLAG_NOSAVE_RESPAWN       = 0x04,
};

enum SMARTAI_TEMPLATE
{
    SMARTAI_TEMPLATE_BASIC          = 0, //nothing is preset
    SMARTAI_TEMPLATE_CASTER         = 1, //spellid, repeatMin, repeatMax, range, manaPCT +JOIN: target_param1 as castFlag
    SMARTAI_TEMPLATE_TURRET         = 2, //spellid, repeatMin, repeatMax +JOIN: target_param1 as castFlag
    SMARTAI_TEMPLATE_PASSIVE        = 3,
    SMARTAI_TEMPLATE_CAGED_GO_PART  = 4, //creatureID, give credit at point end?,
    SMARTAI_TEMPLATE_CAGED_NPC_PART = 5, //gameObjectID, despawntime, run?, dist, TextGroupID
    SMARTAI_TEMPLATE_END            = 6
};

enum SMARTAI_TARGETS
{
    SMART_TARGET_NONE                           = 0,    // NONE
    SMART_TARGET_SELF                           = 1,    // Self cast
    SMART_TARGET_VICTIM                         = 2,    // Our current target (ie: highest aggro)
    SMART_TARGET_HOSTILE_SECOND_AGGRO           = 3,    // Second highest aggro, maxdist, playerOnly, powerType + 1
    SMART_TARGET_HOSTILE_LAST_AGGRO             = 4,    // Dead last on aggro, maxdist, playerOnly, powerType + 1
    SMART_TARGET_HOSTILE_RANDOM                 = 5,    // Just any random target on our threat list, maxdist, playerOnly, powerType + 1
    SMART_TARGET_HOSTILE_RANDOM_NOT_TOP         = 6,    // Any random target except top threat, maxdist, playerOnly, powerType + 1
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
    SMART_TARGET_OWNER_OR_SUMMONER              = 23,   // Unit's owner or summoner, Use Owner/Charmer of this unit
    SMART_TARGET_THREAT_LIST                    = 24,   // All units on creature's threat list, maxdist
    SMART_TARGET_CLOSEST_ENEMY                  = 25,   // maxDist, playerOnly
    SMART_TARGET_CLOSEST_FRIENDLY               = 26,   // maxDist, playerOnly
    SMART_TARGET_LOOT_RECIPIENTS                = 27,   // all players that have tagged this creature (for kill credit)
    SMART_TARGET_FARTHEST                       = 28,   // maxDist, playerOnly, isInLos
    SMART_TARGET_VEHICLE_PASSENGER              = 29,   // seatMask (0 - all seats)

    SMART_TARGET_END                            = 30
};

struct SmartTarget
{
    SmartTarget (SMARTAI_TARGETS t = SMART_TARGET_NONE, uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0)
    {
        type = t;
        raw.param1 = p1;
        raw.param2 = p2;
        raw.param3 = p3;
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        o = 0.0f;
    }
    SMARTAI_TARGETS type;
    float x, y, z, o;
    union
    {
        struct
        {
            uint32 maxDist;
            uint32 playerOnly;
            uint32 powerType;
        } hostilRandom;

        struct
        {
            uint32 maxDist;
            uint32 playerOnly;
            uint32 isInLos;
        } farthest;

        struct
        {
            uint32 creature;
            uint32 minDist;
            uint32 maxDist;
        } unitRange;

        struct
        {
            uint32 dbGuid;
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
            uint32 dbGuid;
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
            uint32 maxDist;
            uint32 playerOnly;
        } closestAttackable;

        struct
        {
            uint32 maxDist;
            uint32 playerOnly;
        } closestFriendly;

        struct
        {
            uint32 useCharmerOrOwner;
        } owner;

        struct
        {
            uint32 param1;
            uint32 param2;
            uint32 param3;
        } raw;

        struct
        {
            uint32 seatMask;
        } vehicle;
    };
};

enum SmartScriptType
{
    SMART_SCRIPT_TYPE_CREATURE = 0, //done
    SMART_SCRIPT_TYPE_GAMEOBJECT = 1, //done
    SMART_SCRIPT_TYPE_AREATRIGGER = 2, //done
    SMART_SCRIPT_TYPE_EVENT = 3, //
    SMART_SCRIPT_TYPE_GOSSIP = 4, //
    SMART_SCRIPT_TYPE_QUEST = 5, //done
    SMART_SCRIPT_TYPE_SPELL = 6, //
    SMART_SCRIPT_TYPE_TRANSPORT = 7, //
    SMART_SCRIPT_TYPE_INSTANCE = 8, //
    SMART_SCRIPT_TYPE_TIMED_ACTIONLIST = 9, //
    SMART_SCRIPT_TYPE_SCENE = 10, //done
    SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY = 11,
    SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY_SERVERSIDE = 12,
    SMART_SCRIPT_TYPE_MAX
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
    SMART_SCRIPT_TYPE_MASK_SCENE = 1024,
    SMART_SCRIPT_TYPE_MASK_AREATRIGGER_ENTITY = 2048
};

const uint32 SmartAITypeMask[SMART_SCRIPT_TYPE_MAX][2] =
{
    {SMART_SCRIPT_TYPE_CREATURE,                      SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_SCRIPT_TYPE_GAMEOBJECT,                    SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_SCRIPT_TYPE_AREATRIGGER,                   SMART_SCRIPT_TYPE_MASK_AREATRIGGER },
    {SMART_SCRIPT_TYPE_EVENT,                         SMART_SCRIPT_TYPE_MASK_EVENT },
    {SMART_SCRIPT_TYPE_GOSSIP,                        SMART_SCRIPT_TYPE_MASK_GOSSIP },
    {SMART_SCRIPT_TYPE_QUEST,                         SMART_SCRIPT_TYPE_MASK_QUEST },
    {SMART_SCRIPT_TYPE_SPELL,                         SMART_SCRIPT_TYPE_MASK_SPELL },
    {SMART_SCRIPT_TYPE_TRANSPORT,                     SMART_SCRIPT_TYPE_MASK_TRANSPORT },
    {SMART_SCRIPT_TYPE_INSTANCE,                      SMART_SCRIPT_TYPE_MASK_INSTANCE },
    {SMART_SCRIPT_TYPE_TIMED_ACTIONLIST,              SMART_SCRIPT_TYPE_MASK_TIMED_ACTIONLIST },
    {SMART_SCRIPT_TYPE_SCENE,                         SMART_SCRIPT_TYPE_MASK_SCENE },
    {SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY,            SMART_SCRIPT_TYPE_MASK_AREATRIGGER_ENTITY },
    {SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY_SERVERSIDE, SMART_SCRIPT_TYPE_MASK_AREATRIGGER_ENTITY }
};

const uint32 SmartAIEventMask[SMART_EVENT_END][2] =
{
    {SMART_EVENT_UPDATE_IC,                 SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_TIMED_ACTIONLIST},
    {SMART_EVENT_UPDATE_OOC,                SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT + SMART_SCRIPT_TYPE_MASK_INSTANCE + SMART_SCRIPT_TYPE_MASK_AREATRIGGER_ENTITY },
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
    {SMART_EVENT_VICTIM_CASTING,            SMART_SCRIPT_TYPE_MASK_CREATURE },
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
    {SMART_EVENT_TARGET_BUFFED,             SMART_SCRIPT_TYPE_MASK_CREATURE },
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
    {SMART_EVENT_AREATRIGGER_ONTRIGGER,     SMART_SCRIPT_TYPE_MASK_AREATRIGGER + SMART_SCRIPT_TYPE_MASK_AREATRIGGER_ENTITY },
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
    {SMART_EVENT_UPDATE,                    SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT + SMART_SCRIPT_TYPE_MASK_AREATRIGGER_ENTITY },
    {SMART_EVENT_LINK,                      SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT + SMART_SCRIPT_TYPE_MASK_AREATRIGGER + SMART_SCRIPT_TYPE_MASK_EVENT + SMART_SCRIPT_TYPE_MASK_GOSSIP + SMART_SCRIPT_TYPE_MASK_QUEST + SMART_SCRIPT_TYPE_MASK_SPELL + SMART_SCRIPT_TYPE_MASK_TRANSPORT + SMART_SCRIPT_TYPE_MASK_INSTANCE + SMART_SCRIPT_TYPE_MASK_AREATRIGGER_ENTITY },
    {SMART_EVENT_GOSSIP_SELECT,             SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_JUST_CREATED,              SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_GOSSIP_HELLO,              SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_FOLLOW_COMPLETED,          SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_EVENT_PHASE_CHANGE,        SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_IS_BEHIND_TARGET,          SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_GAME_EVENT_START,          SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_GAME_EVENT_END,            SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_GO_LOOT_STATE_CHANGED,     SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_GO_EVENT_INFORM,           SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_ACTION_DONE,               SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_ON_SPELLCLICK,             SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_FRIENDLY_HEALTH_PCT,       SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_DISTANCE_CREATURE,         SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_DISTANCE_GAMEOBJECT,       SMART_SCRIPT_TYPE_MASK_CREATURE },
    {SMART_EVENT_COUNTER_SET,               SMART_SCRIPT_TYPE_MASK_CREATURE + SMART_SCRIPT_TYPE_MASK_GAMEOBJECT },
    {SMART_EVENT_SCENE_START,               SMART_SCRIPT_TYPE_MASK_SCENE },
    {SMART_EVENT_SCENE_TRIGGER,             SMART_SCRIPT_TYPE_MASK_SCENE },
    {SMART_EVENT_SCENE_CANCEL,              SMART_SCRIPT_TYPE_MASK_SCENE },
    {SMART_EVENT_SCENE_COMPLETE,            SMART_SCRIPT_TYPE_MASK_SCENE }
};

enum SmartEventFlags
{
    SMART_EVENT_FLAG_NOT_REPEATABLE        = 0x001,                     //Event can not repeat
    SMART_EVENT_FLAG_DIFFICULTY_0          = 0x002,                     //Event only occurs in instance difficulty 0
    SMART_EVENT_FLAG_DIFFICULTY_1          = 0x004,                     //Event only occurs in instance difficulty 1
    SMART_EVENT_FLAG_DIFFICULTY_2          = 0x008,                     //Event only occurs in instance difficulty 2
    SMART_EVENT_FLAG_DIFFICULTY_3          = 0x010,                     //Event only occurs in instance difficulty 3
    SMART_EVENT_FLAG_RESERVED_5            = 0x020,
    SMART_EVENT_FLAG_RESERVED_6            = 0x040,
    SMART_EVENT_FLAG_DEBUG_ONLY            = 0x080,                     //Event only occurs in debug build
    SMART_EVENT_FLAG_DONT_RESET            = 0x100,                     //Event will not reset in SmartScript::OnReset()
    SMART_EVENT_FLAG_WHILE_CHARMED         = 0x200,                     //Event occurs even if AI owner is charmed

    SMART_EVENT_FLAG_DIFFICULTY_ALL        = (SMART_EVENT_FLAG_DIFFICULTY_0|SMART_EVENT_FLAG_DIFFICULTY_1|SMART_EVENT_FLAG_DIFFICULTY_2|SMART_EVENT_FLAG_DIFFICULTY_3),
    SMART_EVENT_FLAGS_ALL                  = (SMART_EVENT_FLAG_NOT_REPEATABLE|SMART_EVENT_FLAG_DIFFICULTY_ALL|SMART_EVENT_FLAG_RESERVED_5|SMART_EVENT_FLAG_RESERVED_6|SMART_EVENT_FLAG_DEBUG_ONLY|SMART_EVENT_FLAG_DONT_RESET|SMART_EVENT_FLAG_WHILE_CHARMED)
};

enum SmartCastFlags
{
    SMARTCAST_INTERRUPT_PREVIOUS     = 0x01,                     // Interrupt any spell casting
    SMARTCAST_TRIGGERED              = 0x02,                     // Triggered (this makes spell cost zero mana and have no cast time)
    //SMARTCAST_FORCE_CAST             = 0x04,                     //Forces cast even if creature is out of mana or out of range
    //SMARTCAST_NO_MELEE_IF_OOM        = 0x08,                     //Prevents creature from entering melee if out of mana or out of range
    //SMARTCAST_FORCE_TARGET_SELF      = 0x10,                     //Forces the target to cast this spell on itself
    SMARTCAST_AURA_NOT_PRESENT       = 0x20,                     // Only casts the spell if the target does not have an aura from the spell
    SMARTCAST_COMBAT_MOVE            = 0x40                      // Prevents combat movement if cast successful. Allows movement on range, OOM, LOS
};

// one line in DB is one event
struct SmartScriptHolder
{
    SmartScriptHolder() : entryOrGuid(0), source_type(SMART_SCRIPT_TYPE_CREATURE)
        , event_id(0), link(0), event(), action(), target(), timer(0), active(false), runOnce(false)
        , enableTimed(false) { }

    int64 entryOrGuid;
    SmartScriptType source_type;
    uint32 event_id;
    uint32 link;

    SmartEvent event;
    SmartAction action;
    SmartTarget target;

    uint32 GetScriptType() const { return (uint32)source_type; }
    uint32 GetEventType() const { return (uint32)event.type; }
    uint32 GetActionType() const { return (uint32)action.type; }
    uint32 GetTargetType() const { return (uint32)target.type; }

    uint32 timer;
    bool active;
    bool runOnce;
    bool enableTimed;

    operator bool() const { return entryOrGuid != 0; }
};

typedef std::vector<WorldObject*> ObjectVector;

class ObjectGuidVector
{
    public:
        explicit ObjectGuidVector(ObjectVector const& objectVector);

        ObjectVector const* GetObjectVector(WorldObject const& ref) const
        {
            UpdateObjects(ref);
            return &_objectVector;
        }

        ~ObjectGuidVector() { }

    private:
        GuidVector _guidVector;
        mutable ObjectVector _objectVector;

        //sanitize vector using _guidVector
        void UpdateObjects(WorldObject const& ref) const;
};
typedef std::unordered_map<uint32, ObjectGuidVector> ObjectVectorMap;

class TC_GAME_API SmartWaypointMgr
{
    public:
        static SmartWaypointMgr* instance();

        void LoadFromDB();

        WaypointPath const* GetPath(uint32 id);

    private:
        SmartWaypointMgr() { }
        ~SmartWaypointMgr() { }

        std::unordered_map<uint32, WaypointPath> _waypointStore;
};

#define sSmartWaypointMgr SmartWaypointMgr::instance()

// all events for a single entry
typedef std::vector<SmartScriptHolder> SmartAIEventList;
typedef std::vector<SmartScriptHolder> SmartAIEventStoredList;

// all events for all entries / guids
typedef std::unordered_map<int64, SmartAIEventList> SmartAIEventMap;

// Helper Stores
typedef std::map<uint32 /*entry*/, std::pair<uint32 /*spellId*/, SpellEffIndex /*effIndex*/> > CacheSpellContainer;
typedef std::pair<CacheSpellContainer::const_iterator, CacheSpellContainer::const_iterator> CacheSpellContainerBounds;

class TC_GAME_API SmartAIMgr
{
    private:
        SmartAIMgr() { }
        ~SmartAIMgr() { }

    public:
        static SmartAIMgr* instance();

        void LoadSmartAIFromDB();

        SmartAIEventList GetScript(int32 entry, SmartScriptType type);

        static SmartScriptHolder& FindLinkedSourceEvent(SmartAIEventList& list, uint32 eventId);

        static SmartScriptHolder& FindLinkedEvent(SmartAIEventList& list, uint32 link);

    private:
        //event stores
        SmartAIEventMap mEventMap[SMART_SCRIPT_TYPE_MAX];

        static bool EventHasInvoker(SMART_EVENT event);

        bool IsEventValid(SmartScriptHolder& e);
        bool IsTargetValid(SmartScriptHolder const& e);

        bool IsMinMaxValid(SmartScriptHolder const& e, uint32 min, uint32 max);

        static bool NotNULL(SmartScriptHolder const& e, uint32 data);
        static bool IsCreatureValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsQuestValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsGameObjectValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsSpellValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsItemValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsTextEmoteValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsEmoteValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsAreaTriggerValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsSoundValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsAnimKitValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsSpellVisualKitValid(SmartScriptHolder const& e, uint32 entry);
        static bool IsTextValid(SmartScriptHolder const& e, uint32 id);

        // Helpers
        void LoadHelperStores();
        void UnLoadHelperStores();

        CacheSpellContainerBounds GetSummonCreatureSpellContainerBounds(uint32 creatureEntry) const;
        CacheSpellContainerBounds GetSummonGameObjectSpellContainerBounds(uint32 gameObjectEntry) const;
        CacheSpellContainerBounds GetKillCreditSpellContainerBounds(uint32 killCredit) const;
        CacheSpellContainerBounds GetCreateItemSpellContainerBounds(uint32 itemId) const;

        CacheSpellContainer SummonCreatureSpellStore;
        CacheSpellContainer SummonGameObjectSpellStore;
        CacheSpellContainer KillCreditSpellStore;
        CacheSpellContainer CreateItemSpellStore;
};

#define sSmartScriptMgr SmartAIMgr::instance()

#endif
