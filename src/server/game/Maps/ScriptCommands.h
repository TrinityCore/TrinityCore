/*
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

#ifndef __SCRIPT_COMMANDS_H
#define __SCRIPT_COMMANDS_H

#include "Common.h"
#include "ObjectGuid.h"

// Legend:
// source - the type of object which executes the command
// target - the type of object used as target of the command if needed
// provided source - the "WorldObject* source" provided to the command
// provided target - the "WorldObject* target" provided to the command

// For example the talk command can be used by any WorldObject and the text will
// be said by this object. If there is also a target provided of type Unit, then
// any use of $n in the text will show the name of this unit.

// Command functions are defined in Map.h and implemented in ScriptCommands.cpp!

enum eScriptCommand
{
    SCRIPT_COMMAND_TALK                     = 0,            // source = WorldObject
                                                            // target = Unit/None
                                                            // datalong = chat_type (see enum ChatType)
                                                            // dataint = broadcast_text id. dataint2-4 optional for random selected text.
    SCRIPT_COMMAND_EMOTE                    = 1,            // source = Unit
                                                            // datalong1-4 = emote_id
                                                            // dataint = (bool) is_targeted
    SCRIPT_COMMAND_FIELD_SET                = 2,            // source = Object
                                                            // datalong = field_id
                                                            // datalong2 = value
    SCRIPT_COMMAND_MOVE_TO                  = 3,            // source = Creature
                                                            // target = WorldObject (for datalong > 0)
                                                            // datalong = coordinates_type (see enum eMoveToCoordinateTypes)
                                                            // datalong2 = time
                                                            // datalong3 = movement_options (see enum MoveOptions)
                                                            // datalong4 = eMoveToFlags
                                                            // dataint = path_id
                                                            // x/y/z/o = coordinates
    SCRIPT_COMMAND_MODIFY_FLAGS             = 4,            // source = Object
                                                            // datalong = field_id
                                                            // datalong2 = bitmask
                                                            // datalong3 = eModifyFlagsOptions
    SCRIPT_COMMAND_INTERRUPT_CASTS          = 5,            // source = Unit
                                                            // datalong = (bool) with_delayed
                                                            // datalong2 = spell_id (optional)
    SCRIPT_COMMAND_TELEPORT_TO              = 6,            // source = Unit
                                                            // datalong = map_id (only used for players but still required)
                                                            // datalong2 = teleport_options (see enum TeleportToOptions)
                                                            // x/y/z/o = coordinates
    SCRIPT_COMMAND_QUEST_EXPLORED           = 7,            // source = Player (from provided source or target)
                                                            // target = WorldObject (from provided source or target)
                                                            // datalong = quest_id
                                                            // datalong2 = distance or 0
                                                            // datalong3 = (bool) group
    SCRIPT_COMMAND_KILL_CREDIT              = 8,            // source = Player (from provided source or target)
                                                            // datalong = creature entry
                                                            // datalong2 = bool (0=personal credit, 1=group credit)
    SCRIPT_COMMAND_RESPAWN_GAMEOBJECT       = 9,            // source = Map
                                                            // target = GameObject (from datalong, provided source or target)
                                                            // datalong = db_guid
                                                            // datalong2 = despawn_delay
    SCRIPT_COMMAND_TEMP_SUMMON_CREATURE     = 10,           // source = WorldObject (from provided source or buddy)
                                                            // datalong = creature_entry
                                                            // datalong2 = despawn_delay
                                                            // datalong3 = unique_limit
                                                            // datalong4 = unique_distance
                                                            // dataint = eSummonCreatureFlags
                                                            // dataint2 = script_id
                                                            // dataint3 = attack_target (see enum ScriptTarget)
                                                            // dataint4 = despawn_type (see enum TempSummonType)
                                                            // x/y/z/o = coordinates
    SCRIPT_COMMAND_OPEN_DOOR                = 11,           // source = GameObject (from datalong, provided source or target)
                                                            // If provided target is BUTTON GameObject, command is run on it too.
                                                            // datalong = db_guid
                                                            // datalong2 = reset_delay
    SCRIPT_COMMAND_CLOSE_DOOR               = 12,           // source = GameObject (from datalong, provided source or target)
                                                            // If provided target is BUTTON GameObject, command is run on it too.
                                                            // datalong = db_guid
                                                            // datalong2 = reset_delay
    SCRIPT_COMMAND_ACTIVATE_OBJECT          = 13,           // source = GameObject
                                                            // target = Unit
    SCRIPT_COMMAND_REMOVE_AURA              = 14,           // source = Unit
                                                            // datalong = spell_id
    SCRIPT_COMMAND_CAST_SPELL               = 15,           // source = Unit
                                                            // target = Unit
                                                            // datalong = spell_id
                                                            // datalong2 = eCastSpellFlags
    SCRIPT_COMMAND_PLAY_SOUND               = 16,           // source = WorldObject
                                                            // target = Player/None
                                                            // datalong = sound_id
                                                            // datalong2 = ePlaySoundFlags
    SCRIPT_COMMAND_CREATE_ITEM              = 17,           // source = Player (from provided source or target)
                                                            // datalong = item_id
                                                            // datalong2 = amount
    SCRIPT_COMMAND_DESPAWN_CREATURE         = 18,           // source = Creature
                                                            // datalong = despawn_delay
    SCRIPT_COMMAND_SET_EQUIPMENT            = 19,           // source = Creature
                                                            // datalong = (bool) reset_default
                                                            // dataint = main-hand item_id
                                                            // dataint2 = off-hand item_id
                                                            // dataint3 = ranged item_id
    SCRIPT_COMMAND_MOVEMENT                 = 20,           // source = Creature
                                                            // datalong = see enum MovementGeneratorType (not all are supported)
                                                            // datalong2 = bool_param (meaning depends on the motion type)
                                                            // datalong3 = int_param (meaning depends on the motion type)
                                                            // datalong4 = (bool) clear
                                                            // x = distance (only for some motion types)
                                                            // o = angle (only for some motion types)
    SCRIPT_COMMAND_SET_ACTIVEOBJECT         = 21,           // source = Creature
                                                            // datalong = (bool) 0=off, 1=on
    SCRIPT_COMMAND_SET_FACTION              = 22,           // source = Creature
                                                            // datalong = faction_Id,
                                                            // datalong2 = see enum TemporaryFactionFlags
    SCRIPT_COMMAND_MORPH_TO_ENTRY_OR_MODEL  = 23,           // source = Unit
                                                            // datalong = creature_id/display_id (depend on datalong2)
                                                            // datalong2 = (bool) is_display_id
    SCRIPT_COMMAND_MOUNT_TO_ENTRY_OR_MODEL  = 24,           // source = Creature
                                                            // datalong = creature_id/display_id (depend on datalong2)
                                                            // datalong2 = (bool) is_display_id
                                                            // datalong3 = (bool) permanent
    SCRIPT_COMMAND_SET_RUN                  = 25,           // source = Creature
                                                            // datalong = (bool) 0 = off, 1 = on
    SCRIPT_COMMAND_ATTACK_START             = 26,           // source = Creature
                                                            // target = Player
    SCRIPT_COMMAND_UPDATE_ENTRY             = 27,           // source = Creature
                                                            // datalong = creature_entry
    SCRIPT_COMMAND_STAND_STATE              = 28,           // source = Unit
                                                            // datalong = stand_state (enum UnitStandStateType)
    SCRIPT_COMMAND_MODIFY_THREAT            = 29,           // source = Creature
                                                            // datalong = eModifyThreatTargets
                                                            // x = percent
    SCRIPT_COMMAND_SEND_TAXI_PATH           = 30,           // source = Player
                                                            // datalong = taxi_path_id
    SCRIPT_COMMAND_TERMINATE_SCRIPT         = 31,           // source = Any
                                                            // datalong = creature_entry
                                                            // datalong2 = search_distance
                                                            // datalong3 = eTerminateScriptOptions
    SCRIPT_COMMAND_TERMINATE_CONDITION      = 32,           // source = Any
                                                            // datalong = condition_id
                                                            // datalong2 = failed_quest_id
                                                            // datalong3 = eTerminateConditionFlags
    SCRIPT_COMMAND_ENTER_EVADE_MODE         = 33,           // source = Creature
    SCRIPT_COMMAND_SET_HOME_POSITION        = 34,           // source = Creature
                                                            // datalong = eSetHomePositionOptions
                                                            // x/y/z/o = coordinates
    SCRIPT_COMMAND_TURN_TO                  = 35,           // source = Unit
                                                            // target = WorldObject
                                                            // datalong = eTurnToFacingOptions
    SCRIPT_COMMAND_MEETINGSTONE             = 36,           // source = Player
                                                            // datalong = area_id
    SCRIPT_COMMAND_SET_INST_DATA            = 37,           // source = Map
                                                            // datalong = field
                                                            // datalong2 = data
                                                            // datalong3 = eSetInstDataOptions
    SCRIPT_COMMAND_SET_INST_DATA64          = 38,           // source = Map
                                                            // target = Object (when saving guid)
                                                            // datalong = field
                                                            // datalong2 = data
                                                            // datalong3 = eSetInstData64Options
    SCRIPT_COMMAND_START_SCRIPT             = 39,           // source = Map
                                                            // datalong1-4 = event_script id
                                                            // dataint1-4 = chance (total cant be above 100)
    SCRIPT_COMMAND_REMOVE_ITEM              = 40,           // source = Player (from provided source or target)
                                                            // datalong = item_id
                                                            // datalong2 = amount
    SCRIPT_COMMAND_REMOVE_OBJECT            = 41,           // source = GameObject
                                                            // target = Unit
    SCRIPT_COMMAND_SET_MELEE_ATTACK         = 42,           // source = Creature
                                                            // datalong = (bool) 0 = off, 1 = on
    SCRIPT_COMMAND_SET_COMBAT_MOVEMENT      = 43,           // source = Creature
                                                            // datalong = (bool) 0 = off, 1 = on
    SCRIPT_COMMAND_SET_PHASE                = 44,           // source = Creature
                                                            // datalong = phase
                                                            // datalong2 = eSetPhaseOptions
    SCRIPT_COMMAND_SET_PHASE_RANDOM         = 45,           // source = Creature
                                                            // datalong1-4 = phase
    SCRIPT_COMMAND_SET_PHASE_RANGE          = 46,           // source = Creature
                                                            // datalong = phase_min
                                                            // datalong2 = phase_max
    SCRIPT_COMMAND_FLEE                     = 47,           // source = Creature
                                                            // datalong = seek_assistance (bool) 0 = off, 1 = on
    SCRIPT_COMMAND_DEAL_DAMAGE              = 48,           // source = Unit
                                                            // target = Unit
                                                            // datalong = damage
                                                            // datalong2 = (bool) is_percent
    SCRIPT_COMMAND_ZONE_COMBAT_PULSE        = 49,           // source = Creature
                                                            // datalong = (bool) initialPulse
    SCRIPT_COMMAND_CALL_FOR_HELP            = 50,           // source = Creature
                                                            // x = radius
    SCRIPT_COMMAND_SET_SHEATH               = 51,           // source = Unit
                                                            // datalong = see enum SheathState
    SCRIPT_COMMAND_INVINCIBILITY            = 52,           // source = Creature
                                                            // datalong = health
                                                            // datalong2 = (bool) is_percent
    SCRIPT_COMMAND_GAME_EVENT               = 53,           // source = None
                                                            // datalong = event_id
                                                            // datalong2 = (bool) start
                                                            // datalong3 = (bool) overwrite
    SCRIPT_COMMAND_SET_SERVER_VARIABLE      = 54,           // source = None
                                                            // datalong = index
                                                            // datalong2 = value
    SCRIPT_COMMAND_CREATURE_SPELLS          = 55,           // source = Creature
                                                            // datalong1-4 = creature_spells id
                                                            // dataint1-4 = chance (total cant be above 100)
    SCRIPT_COMMAND_REMOVE_GUARDIANS         = 56,           // source = Unit
                                                            // datalong = creature_id
    SCRIPT_COMMAND_ADD_SPELL_COOLDOWN       = 57,           // source = Unit
                                                            // datalong = spell_id
                                                            // datalong2 = cooldown
    SCRIPT_COMMAND_REMOVE_SPELL_COOLDOWN    = 58,           // source = Unit
                                                            // datalong = spell_id
    SCRIPT_COMMAND_SET_REACT_STATE          = 59,           // source = Creature
                                                            // datalong = see enum ReactStates
    SCRIPT_COMMAND_START_WAYPOINTS          = 60,           // source = Creature
                                                            // datalong = waypoints_source
                                                            // datalong2 = start_point
                                                            // datalong3 = initial_delay
                                                            // datalong4 = (bool) repeat
                                                            // dataint = overwrite_guid
                                                            // dataint2 = overwrite_entry
    SCRIPT_COMMAND_START_MAP_EVENT          = 61,           // source = Map
                                                            // datalong = event_id
                                                            // datalong2 = time_limit
                                                            // dataint = success_condition
                                                            // dataint2 = success_script
                                                            // dataint3 = failure_condition
                                                            // dataint4 = failure_script
    SCRIPT_COMMAND_END_MAP_EVENT            = 62,           // source = Map
                                                            // datalong = event_id
                                                            // datalong2 = (bool) success
    SCRIPT_COMMAND_ADD_MAP_EVENT_TARGET     = 63,           // source = Map
                                                            // target = WorldObject
                                                            // datalong = event_id
                                                            // dataint = success_condition
                                                            // dataint2 = success_script
                                                            // dataint3 = failure_condition
                                                            // dataint4 = failure_script
    SCRIPT_COMMAND_REMOVE_MAP_EVENT_TARGET  = 64,           // source = Map
                                                            // target = WorldObject
                                                            // datalong = event_id
                                                            // datalong2 = condition_id
                                                            // datalong3 = eRemoveMapEventTargetOptions
    SCRIPT_COMMAND_SET_MAP_EVENT_DATA       = 65,           // source = Map
                                                            // datalong = event_id
                                                            // datalong2 = index
                                                            // datalong3 = data
                                                            // datalong4 = eSetMapScriptDataOptions
    SCRIPT_COMMAND_SEND_MAP_EVENT           = 66,           // source = Map
                                                            // datalong = event_id
                                                            // datalong2 = data
                                                            // datalong3 = eSendMapEventOptions
    SCRIPT_COMMAND_SET_DEFAULT_MOVEMENT     = 67,           // source = Creature
                                                            // datalong = movement_type
                                                            // datalong2 = (bool) always_replace
                                                            // datalong3 = param1
    SCRIPT_COMMAND_START_SCRIPT_FOR_ALL     = 68,           // source = WorldObject
                                                            // datalong = script_id
                                                            // datalong2 = eStartScriptForAllOptions
                                                            // datalong3 = object_entry
                                                            // datalong4 = search_radius
    SCRIPT_COMMAND_EDIT_MAP_EVENT           = 69,           // source = Map
                                                            // datalong = event_id
                                                            // dataint = success_condition
                                                            // dataint2 = success_script
                                                            // dataint3 = failure_condition
                                                            // dataint4 = failure_script
    SCRIPT_COMMAND_FAIL_QUEST               = 70,           // source = Player
                                                            // datalong = quest_id
    SCRIPT_COMMAND_RESPAWN_CREATURE         = 71,           // source = Creature
                                                            // datalong = (bool) even_if_alive
    SCRIPT_COMMAND_ASSIST_UNIT              = 72,           // source = Creature
                                                            // target = Unit
    SCRIPT_COMMAND_COMBAT_STOP              = 73,           // source = Unit
    SCRIPT_COMMAND_ADD_AURA                 = 74,           // source = Unit
                                                            // datalong = spell_id
                                                            // datalong2 = flags
    SCRIPT_COMMAND_ADD_THREAT               = 75,           // source = Creature
                                                            // target = Unit
    SCRIPT_COMMAND_SUMMON_OBJECT            = 76,           // source = WorldObject
                                                            // datalong = gameobject_entry
                                                            // datalong2 = respawn_time
                                                            // x/y/z/o = coordinates
    SCRIPT_COMMAND_SET_FLY                  = 77,           // source = Unit
                                                            // datalong = (bool) 0 = off, 1 = on
    SCRIPT_COMMAND_JOIN_CREATURE_GROUP      = 78,           // source = Creature
                                                            // target = Creature
                                                            // datalong = OptionFlags
                                                            // x = distance
                                                            // o = angle
    SCRIPT_COMMAND_LEAVE_CREATURE_GROUP     = 79,           // source = Creature
    SCRIPT_COMMAND_SET_GO_STATE             = 80,           // source = GameObject
                                                            // datalong = GOState
    SCRIPT_COMMAND_DESPAWN_GAMEOBJECT       = 81,           // source = GameObject (from datalong, provided source or target)
                                                            // datalong = db_guid
                                                            // datalong2 = despawn_delay
    SCRIPT_COMMAND_LOAD_GAMEOBJECT          = 82,           // source = Map
                                                            // datalong = db_guid
    SCRIPT_COMMAND_QUEST_CREDIT             = 83,           // source = Player (from provided source or target)
                                                            // target = WorldObject (from provided source or target)
    SCRIPT_COMMAND_SET_GOSSIP_MENU          = 84,           // source = Creature
                                                            // datalong = gossip_menu_id
    SCRIPT_COMMAND_SEND_SCRIPT_EVENT        = 85,           // source = Creature
                                                            // target = WorldObject
                                                            // datalong = event_id
                                                            // datalong2 = event_data
    SCRIPT_COMMAND_SET_PVP                  = 86,           // source = Player
                                                            // datalong = (bool) 0 = off, 1 = on
    SCRIPT_COMMAND_RESET_DOOR_OR_BUTTON     = 87,           // source = GameObject

    SCRIPT_COMMAND_MAX,

    SCRIPT_COMMAND_DISABLED                 = 9999          // Script action was disabled during loading.
};

#define MAX_TEXT_ID 4                                       // used for SCRIPT_COMMAND_TALK
static constexpr uint32 MAX_EMOTE_ID = 4;                   // used for SCRIPT_COMMAND_EMOTE

// Flags used by SCRIPT_COMMAND_MOVE_TO
enum eMoveToFlags
{
    SF_MOVETO_FORCED        = 0x1,                          // No check if creature can move.
    SF_MOVETO_POINT_MOVEGEN = 0x2,                          // Changes movement generator to point movement.
};

// Possible datalong3 values for SCRIPT_COMMAND_MOVE_TO
enum eMoveToCoordinateTypes
{
    SO_MOVETO_COORDINATES_NORMAL               = 0,
    SO_MOVETO_COORDINATES_RELATIVE_TO_TARGET   = 1,            // Coordinates are added to that of target.
    SO_MOVETO_COORDINATES_DISTANCE_FROM_TARGET = 2,            // X is distance from target, others not used.
    SO_MOVETO_COORDINATES_RANDOM_POINT         = 3,            // O is max distance from coordinates

    MOVETO_COORDINATES_MAX
};

// Possible datalong3 values for SCRIPT_COMMAND_MODIFY_FLAGS
enum eModifyFlagsOptions
{
    SO_MODIFYFLAGS_TOGGLE = 0,
    SO_MODIFYFLAGS_SET    = 1,
    SO_MODIFYFLAGS_REMOVE = 2
};

// Flags used by SCRIPT_COMMAND_TEMP_SUMMON_CREATURE
// Must start from 0x8 because of target selection flags.
enum eSummonCreatureFlags
{
    SF_SUMMONCREATURE_SET_RUN     = 0x01,                       // makes creature move at run speed
    SF_SUMMONCREATURE_ACTIVE      = 0x02,                       // active creatures are always updated
    SF_SUMMONCREATURE_UNIQUE      = 0x04,                       // not actually unique, just checks for same entry in certain range
    SF_SUMMONCREATURE_UNIQUE_TEMP = 0x08,                       // same as 0x10 but check for TempSummon only creatures
    SF_SUMMONCREATURE_NULL_AI     = 0x10                        // use Null AI instead of the normal creature script
};

// FLags used by SCRIPT_COMMAND_CAST_SPELL
enum CastFlags
{
    CF_INTERRUPT_PREVIOUS     = 0x001,                     // Interrupt any spell casting
    CF_TRIGGERED              = 0x002,                     // Triggered (this makes spell cost zero mana and have no cast time)
    CF_FORCE_CAST             = 0x004,                     // Bypasses extra checks in Creature::TryToCast
    CF_MAIN_RANGED_SPELL      = 0x008,                     // To be used by ranged mobs only. Creature will not chase target until cast fails.
    CF_TARGET_UNREACHABLE     = 0x010,                     // Will only use the ability if creature cannot currently get to target
    CF_AURA_NOT_PRESENT       = 0x020,                     // Only casts the spell if the target does not have an aura from the spell
    CF_ONLY_IN_MELEE          = 0x040,                     // Only casts if the creature is in melee range of the target
    CF_NOT_IN_MELEE           = 0x080,                     // Only casts if the creature is not in melee range of the target
    CF_TARGET_CASTING         = 0x100,                     // Only casts if the target is currently casting a spell
};

#define ALL_CAST_FLAGS (CF_INTERRUPT_PREVIOUS | CF_TRIGGERED | CF_FORCE_CAST | CF_MAIN_RANGED_SPELL | CF_TARGET_UNREACHABLE | CF_AURA_NOT_PRESENT | CF_ONLY_IN_MELEE | CF_NOT_IN_MELEE | CF_TARGET_CASTING)

// Flags used by SCRIPT_COMMAND_PLAY_SOUND
enum ePlaySoundFlags
{
    SF_PLAYSOUND_ONLY_TO_TARGET     = 0x1,
    SF_PLAYSOUND_DISTANCE_DEPENDENT = 0x2
};

// Possible datalong values for SCRIPT_COMMAND_MODIFY_THREAT
enum eModifyThreatTargets
{
    // 0 to 5 from Target enum.
    SO_MODIFYTHREAT_ALL_ATTACKERS   = 6
};

// Possible datalong3 values for SCRIPT_COMMAND_TERMINATE_SCRIPT
enum eTerminateScriptOptions
{
    SO_TERMINATESCRIPT_IF_NOT_FOUND = 0,
    SO_TERMINATESCRIPT_IF_FOUND     = 1
};

// Flags used by SCRIPT_COMMAND_TERMINATE_CONDITION
enum eTerminateConditionFlags
{
    SF_TERMINATECONDITION_WHEN_FALSE = 0x1
};

// Possible datalong values for SCRIPT_COMMAND_SET_HOME_POSITION
enum eSetHomePositionOptions
{
    SO_SETHOME_PROVIDED_POSITION = 0,
    SO_SETHOME_CURRENT_POSITION  = 1,
    SO_SETHOME_DEFAULT_POSITION  = 2
};

// Possible datalong values for SCRIPT_COMMAND_TURN_TO
enum eTurnToFacingOptions
{
    SO_TURNTO_FACE_TARGET          = 0,
    SO_TURNTO_PROVIDED_ORIENTATION = 1
};

// Possible datalong3 values for SCRIPT_COMMAND_SET_INST_DATA
enum eSetInstDataOptions
{
    SO_INSTDATA_RAW       = 0,
    SO_INSTDATA_INCREMENT = 1,
    SO_INSTDATA_DECREMENT = 2,

    SO_INSTDATA_MAX
};

// Possible datalong3 values for SCRIPT_COMMAND_SET_INST_DATA64
enum eSetInstData64Options
{
    SO_INSTDATA64_RAW         = 0,
    SO_INSTDATA64_SOURCE_GUID = 1,

    SO_INSTDATA64_MAX
};

// Possible datalong values for SCRIPT_COMMAND_SET_PHASE
enum eSetPhaseOptions
{
    SO_SETPHASE_RAW       = 0,
    SO_SETPHASE_INCREMENT = 1,
    SO_SETPHASE_DECREMENT = 2,

    SO_SETPHASE_MAX
};

// Possible datalong3 values for SCRIPT_COMMAND_REMOVE_MAP_EVENT_TARGET
enum eRemoveMapEventTargetOptions
{
    SO_REMOVETARGET_SELF = 0,
    SO_REMOVETARGET_ONE_FIT_CONDITION = 1,
    SO_REMOVETARGET_ALL_FIT_CONDITION = 2,
    SO_REMOVETARGET_ALL_TARGETS = 3,

    SO_REMOVETARGET_MAX
};

// Possible datalong4 values for SCRIPT_COMMAND_SET_MAP_EVENT_DATA
enum eSetMapScriptDataOptions
{
    SO_MAPEVENTDATA_RAW       = 0,
    SO_MAPEVENTDATA_INCREMENT = 1,
    SO_MAPEVENTDATA_DECREMENT = 2,

    SO_MAPEVENTDATA_MAX
};

// Possible datalong3 values for SCRIPT_COMMAND_SEND_MAP_EVENT
enum eSendMapEventOptions
{
    SO_SENDMAPEVENT_MAIN_TARGETS_ONLY  = 0,
    SO_SENDMAPEVENT_EXTRA_TARGETS_ONLY = 1,
    SO_SENDMAPEVENT_ALL_TARGETS        = 2,

    SO_SENDMAPEVENT_MAX
};

// Possible datalong2 values for SCRIPT_COMMAND_START_SCRIPT_FOR_ALL
enum eStartScriptForAllOptions
{
    SO_STARTFORALL_GAMEOBJECTS  = 0,
    SO_STARTFORALL_UNITS        = 1,
    SO_STARTFORALL_CREATURES    = 2,
    SO_STARTFORALL_PLAYERS      = 3,

    SO_STARTFORALL_MAX
};

enum eDataFlags
{
    SF_GENERAL_SWAP_INITIAL_TARGETS = 0x1,                  // Swaps the provided source and target, before buddy is checked.
    SF_GENERAL_SWAP_FINAL_TARGETS   = 0x2,                  // Swaps the local source and target, after buddy is assigned.
    SF_GENERAL_TARGET_SELF          = 0x4,                  // Replaces the provided target with the provided source.
    SF_GENERAL_ABORT_ON_FAILURE     = 0x8                   // Terminates the script if the command fails.
};

struct ScriptInfo
{
    uint32 id;
    uint32 delay;
    uint32 command;
    uint32 condition;

    union
    {
        struct                                              // SCRIPT_COMMAND_TALK (0)
        {
            uint32 chatType;                                // datalong
            uint32 unused1;                                 // datalong2
            uint32 unused2;                                 // datalong3
            uint32 unused3;                                 // datalong4
            uint32 unused4;                                 // data_flags
            int32  textId[MAX_TEXT_ID];                     // dataint to dataint4
        } talk;

        struct                                              // SCRIPT_COMMAND_EMOTE (1)
        {
            uint32 emoteId[MAX_EMOTE_ID];                   // datalong to datalong4
            uint32 unused;                                  // data_flags
            int32  isTargeted;                              // dataint
        } emote;

        struct                                              // SCRIPT_COMMAND_FIELD_SET (2)
        {
            uint32 fieldId;                                 // datalong
            uint32 fieldValue;                              // datalong2
        } setField;

        struct                                              // SCRIPT_COMMAND_MOVE_TO (3)
        {
            uint32 coordinatesType;                         // datalong
            uint32 travelTime;                              // datalong2
            uint32 movementOptions;                         // datalong3
            uint32 flags;                                   // datalong4
            uint32 unused;                                  // data_flags
            int32 pointId;                                  // dataint
        } moveTo;

        struct                                              // SCRIPT_COMMAND_MODIFY_FLAGS (4)
        {
            uint32 fieldId;                                 // datalong
            uint32 fieldValue;                              // datalong2
            uint32 mode;                                    // datalong3
        } modFlags;

        struct                                              // SCRIPT_COMMAND_INTERRUPT_CASTS (5)
        {
            uint32 withDelayed;                             // datalong
            uint32 spellId;                                 // datalong2
        } interruptCasts;

        struct                                              // SCRIPT_COMMAND_TELEPORT_TO (6)
        {
            uint32 mapId;                                   // datalong
            uint32 teleportOptions;                         // datalong2
        } teleportTo;

        struct                                              // SCRIPT_COMMAND_QUEST_EXPLORED (7)
        {
            uint32 questId;                                 // datalong
            uint32 distance;                                // datalong2
            uint32 group;                                   // datalong3
        } questExplored;

        struct                                              // SCRIPT_COMMAND_KILL_CREDIT (8)
        {
            uint32 creatureEntry;                           // datalong
            uint32 isGroupCredit;                           // datalong2
        } killCredit;

        struct                                              // SCRIPT_COMMAND_RESPAWN_GAMEOBJECT (9)
        {
            uint32 goGuid;                                  // datalong
            int32 despawnDelay;                             // datalong2
        } respawnGo;

        struct                                              // SCRIPT_COMMAND_TEMP_SUMMON_CREATURE (10)
        {
            uint32 creatureEntry;                           // datalong
            uint32 despawnDelay;                            // datalong2
            uint32 uniqueLimit;                             // datalong3
            uint32 uniqueDistance;                          // datalong4
            uint32 unused;                                  // data_flags
            int32 flags;                                    // dataint
            int32 scriptId;                                 // dataint2
            int32 attackTarget;                             // dataint3
            int32 despawnType;                              // dataint4
        } summonCreature;

        struct                                              // SCRIPT_COMMAND_OPEN_DOOR (11)
        {
            uint32 goGuid;                                  // datalong
            int32 resetDelay;                               // datalong2
        } openDoor;

        struct                                              // SCRIPT_COMMAND_CLOSE_DOOR (12)
        {
            uint32 goGuid;                                  // datalong
            int32 resetDelay;                               // datalong2
        } closeDoor;

                                                            // SCRIPT_COMMAND_ACTIVATE_OBJECT (13)

        struct                                              // SCRIPT_COMMAND_REMOVE_AURA (14)
        {
            uint32 spellId;                                 // datalong
        } removeAura;

        struct                                              // SCRIPT_COMMAND_CAST_SPELL (15)
        {
            uint32 spellId;                                 // datalong
            uint32 flags;                                   // datalong2
        } castSpell;

        struct                                              // SCRIPT_COMMAND_PLAY_SOUND (16)
        {
            uint32 soundId;                                 // datalong
            uint32 flags;                                   // datalong2
        } playSound;

        struct                                              // SCRIPT_COMMAND_CREATE_ITEM (17)
        {
            uint32 itemId;                                  // datalong
            uint32 amount;                                  // datalong2
        } createItem;

        struct                                              // SCRIPT_COMMAND_DESPAWN_CREATURE (18)
        {
            uint32 despawnDelay;                            // datalong
        } despawn;

        struct                                              // SCRIPT_COMMAND_SET_EQUIPMENT (19)
        {
            uint32 resetDefault;                            // datalong
            uint32 unused1;                                 // datalong2
            uint32 unused2;                                 // datalong3
            uint32 unused3;                                 // datalong4
            uint32 unused4;                                 // data_flags
            int32  slot[MAX_TEXT_ID];                       // dataint to dataint4
        } setEquipment;

        struct                                              // SCRIPT_COMMAND_MOVEMENT (20)
        {
            uint32 movementType;                            // datalong
            uint32 boolParam;                               // datalong2
            uint32 intParam;                                // datalong3
            uint32 clear;                                   // datalong4
        } movement;

        struct                                              // SCRIPT_COMMAND_SET_ACTIVEOBJECT (21)
        {
            uint32 activate;                                // datalong
        } activeObject;

        struct                                              // SCRIPT_COMMAND_SET_FACTION (22)
        {
            uint32 factionId;                               // datalong
            uint32 flags;                                   // datalong2
        } faction;

        struct                                              // SCRIPT_COMMAND_MORPH_TO_ENTRY_OR_MODEL (23)
        {
            uint32 creatureOrModelEntry;                    // datalong
            uint32 isDisplayId;                             // datalong2
        } morph;

        struct                                              // SCRIPT_COMMAND_MOUNT_TO_ENTRY_OR_MODEL (24)
        {
            uint32 creatureOrModelEntry;                    // datalong
            uint32 isDisplayId;                             // datalong2
            uint32 permanent;                               // datalong3
        } mount;

        struct                                              // SCRIPT_COMMAND_SET_RUN (25)
        {
            uint32 run;                                     // datalong
        } run;

                                                            // SCRIPT_COMMAND_ATTACK_START (26)

        struct                                              // SCRIPT_COMMAND_UPDATE_ENTRY (27)
        {
            uint32 creatureEntry;                           // datalong
        } updateEntry;

        struct                                              // SCRIPT_COMMAND_STAND_STATE (28)
        {
            uint32 standState;                             // datalong
        } standState;

        struct                                              // SCRIPT_COMMAND_MODIFY_THREAT (29)
        {
            uint32 target;                                  // datalong
        } modThreat;

        struct                                              // SCRIPT_COMMAND_SEND_TAXI_PATH (30)
        {
            uint32 taxiPathId;                              // datalong
        } sendTaxiPath;

        struct                                              // SCRIPT_COMMAND_TERMINATE_SCRIPT (31)
        {
            uint32 creatureEntry;                           // datalong
            uint32 searchRadius;                            // datalong2
            uint32 flags;                                   // datalong3
        } terminateScript;

        struct                                              // SCRIPT_COMMAND_TERMINATE_CONDITION (32)
        {
            uint32 conditionId;                             // datalong
            uint32 failQuest;                               // datalong2
            uint32 flags;                                   // datalong3
        } terminateCond;

                                                            // SCRIPT_COMMAND_ENTER_EVADE_MODE (33)

        struct                                              // SCRIPT_COMMAND_SET_HOME_POSITION (34)
        {
            uint32 mode;                                    // datalong
        } setHome;

        struct                                              // SCRIPT_COMMAND_TURN_TO (35)
        {
            uint32 facingLogic;                             // datalong
        } turnTo;

        struct                                              // SCRIPT_COMMAND_MEETINGSTONE (36)
        {
            uint32 areaId;                                  // datalong
        } meetingstone;

        struct                                              // SCRIPT_COMMAND_SET_INST_DATA (37)
        {
            uint32 field;                                   // datalong
            uint32 data;                                    // datalong2
            uint32 type;                                    // datalong3
        } setData;

        struct                                              // SCRIPT_COMMAND_SET_INST_DATA64 (38)
        {
            uint32 field;                                   // datalong
            uint32 data;                                    // datalong2
            uint32 type;                                    // datalong3
        } setData64;

        struct                                              // SCRIPT_COMMAND_START_SCRIPT (39)
        {
            uint32 scriptId[4];                             // datalong to datalong4
            uint32 unused;                                  // data_flags
            int32 chance[4];                                // dataint to dataint4
        } startScript;

        struct                                              // SCRIPT_COMMAND_REMOVE_ITEM (40)
        {
            uint32 itemId;                                  // datalong
            uint32 amount;                                  // datalong2
        } removeItem;

                                                            // SCRIPT_COMMAND_REMOVE_OBJECT (41)

        struct                                              // SCRIPT_COMMAND_SET_MELEE_ATTACK (42)
        {
            uint32 enabled;                                 // datalong
        } enableMelee;

        struct                                              // SCRIPT_COMMAND_SET_COMBAT_MOVEMENT (43)
        {
            uint32 enabled;                                 // datalong
        } combatMovement;

        struct                                              // SCRIPT_COMMAND_SET_PHASE (44)
        {
            uint32 phase;                                   // datalong
            uint32 mode;                                    // datalong2
        } setPhase;

        struct                                              // SCRIPT_COMMAND_SET_PHASE_RANDOM (45)
        {
            uint32 phase[MAX_TEXT_ID];                      // datalong
        } setPhaseRandom;

        struct                                              // SCRIPT_COMMAND_SET_PHASE_RANGE (46)
        {
            uint32 phaseMin;                                // datalong
            uint32 phaseMax;                                // datalong2
        } setPhaseRange;

        struct                                              // SCRIPT_COMMAND_FLEE (47)
        {
            uint32 seekAssistance;                          // datalong
        } flee;

        struct                                              // SCRIPT_COMMAND_DEAL_DAMAGE (48)
        {
            uint32 damage;                                  // datalong
            uint32 isPercent;                               // datalong2
        } dealDamage;

        struct                                              // SCRIPT_COMMAND_ZONE_COMBAT_PULSE (49)
        {
            uint32 initialPulse;                            // datalong
        } combatPulse;

                                                            // SCRIPT_COMMAND_CALL_FOR_HELP (50)

        struct                                              // SCRIPT_COMMAND_SET_SHEATH (51)
        {
            uint32 sheathState;                             // datalong
        } setSheath;

        struct                                              // SCRIPT_COMMAND_INVINCIBILITY (52)
        {
            uint32 health;                                  // datalong
            uint32 isPercent;                               // datalong2
        } invincibility;

        struct                                              // SCRIPT_COMMAND_GAME_EVENT (53)
        {
            uint32 eventId;                                 // datalong
            uint32 start;                                   // datalong2
            uint32 overwrite;                               // datalong3
        } gameEvent;

        struct                                              // SCRIPT_COMMAND_SET_SERVER_VARIABLE (54)
        {
            uint32 index;                                   // datalong
            uint32 value;                                   // datalong2
        } serverVariable;

        struct                                              // SCRIPT_COMMAND_CREATURE_SPELLS (55)
        {
            uint32 spellListId[4];                          // datalong to datalong4
            uint32 unused;                                  // data_flags
            int32 chance[4];                                // dataint to dataint4
        } creatureSpells;

        struct                                              // SCRIPT_COMMAND_REMOVE_GUARDIANS (56)
        {
            uint32 creatureId;                              // datalong
        } removeGuardian;

        struct                                              // SCRIPT_COMMAND_ADD_SPELL_COOLDOWN (57)
        {
            uint32 spellId;                                 // datalong
            uint32 cooldown;                                // datalong2
        } addCooldown;

        struct                                              // SCRIPT_COMMAND_REMOVE_SPELL_COOLDOWN (58)
        {
            uint32 spellId;                                 // datalong
        } removeCooldown;

        struct                                              // SCRIPT_COMMAND_SET_REACT_STATE (59)
        {
            uint32 state;                                   // datalong
        } setReactState;

        struct                                              // SCRIPT_COMMAND_START_WAYPOINTS (60)
        {
            uint32 wpSource;                                // datalong
            uint32 startPoint;                              // datalong2
            uint32 initialDelay;                            // datalong3
            uint32 canRepeat;                               // datalong4
            uint32 unused;                                  // data_flags
            int32  overwriteGuid;                           // dataint
            int32  overwriteEntry;                          // dataint2
        } startWaypoints;
        
        struct                                              // SCRIPT_COMMAND_START_MAP_EVENT (61)
        {
            uint32 eventId;                                 // datalong
            uint32 timeLimit;                               // datalong2
            uint32 unused1;                                 // datalong3
            uint32 unuded2;                                 // datalong4
            uint32 unused3;                                 // data_flags
            int32  successCondition;                        // dataint
            int32  successScript;                           // dataint2
            int32  failureCondition;                        // dataint3
            int32  failureScript;                           // dataint4
        } startMapEvent;

        struct                                              // SCRIPT_COMMAND_END_MAP_EVENT (62)
        {
            uint32 eventId;                                 // datalong
            uint32 success;                                 // datalong2
        } endMapEvent;

        struct                                              // SCRIPT_COMMAND_ADD_MAP_EVENT_TARGET (63)
        {
            uint32 eventId;                                 // datalong
            uint32 unused1;                                 // datalong2
            uint32 unused2;                                 // datalong3
            uint32 unused3;                                 // datalong4
            uint32 unused4;                                 // data_flags
            int32  successCondition;                        // dataint
            int32  successScript;                           // dataint2
            int32  failureCondition;                        // dataint3
            int32  failureScript;                           // dataint4
        } addMapEventTarget;

        struct                                              // SCRIPT_COMMAND_REMOVE_MAP_EVENT_TARGET (64)
        {
            uint32 eventId;                                 // datalong
            uint32 conditionId;                             // datalong2
            uint32 targets;                                 // datalong3
        } removeMapEventTarget;

        struct                                              // SCRIPT_COMMAND_SET_MAP_EVENT_DATA (65)
        {
            uint32 eventId;                                 // datalong
            uint32 index;                                   // datalong2
            uint32 data;                                    // datalong3
            uint32 type;                                    // datalong4
        } setMapEventData;

        struct                                              // SCRIPT_COMMAND_SEND_MAP_EVENT (66)
        {
            uint32 eventId;                                 // datalong
            uint32 data;                                    // datalong2
            uint32 targets;                                 // datalong3
        } sendMapEvent;

        struct                                              // SCRIPT_COMMAND_SET_DEFAULT_MOVEMENT (67)
        {
            uint32 movementType;                            // datalong
            uint32 alwaysReplace;                           // datalong2
            uint32 param1;                                  // datalong3
        } setDefaultMovement;

        struct                                              // SCRIPT_COMMAND_START_SCRIPT_FOR_ALL (68)
        {
            uint32 scriptId;                                // datalong
            uint32 objectType;                              // datalong2
            uint32 objectEntry;                             // datalong3
            uint32 searchRadius;                            // datalong4
        } startScriptForAll;

        struct                                              // SCRIPT_COMMAND_EDIT_MAP_EVENT (69)
        {
            uint32 eventId;                                 // datalong
            uint32 unused1;                                 // datalong2
            uint32 unused2;                                 // datalong3
            uint32 unused3;                                 // datalong4
            uint32 unused4;                                 // data_flags
            int32  successCondition;                        // dataint
            int32  successScript;                           // dataint2
            int32  failureCondition;                        // dataint3
            int32  failureScript;                           // dataint4
        } editMapEvent;

        struct                                              // SCRIPT_COMMAND_FAIL_QUEST (70)
        {
            uint32 questId;                                 // datalong
        } failQuest;

        struct                                              // SCRIPT_COMMAND_RESPAWN_CREATURE (71)
        {
            uint32 evenAlive;                               // datalong
        } respawnCreature;

                                                            // SCRIPT_COMMAND_ASSIST_UNIT (72)

                                                            // SCRIPT_COMMAND_COMBAT_STOP (73)

        struct                                              // SCRIPT_COMMAND_ADD_AURA (74)
        {
            uint32 spellId;                                 // datalong
            uint32 flags;                                   // datalong2
        } addAura;

                                                            // SCRIPT_COMMAND_ADD_THREAT (75)

        struct                                              // SCRIPT_COMMAND_SUMMON_OBJECT (76)
        {
            uint32 gameobject_entry;                        // datalong
            uint32 respawn_time;                            // datalong2
        } summonObject;

        struct                                              // SCRIPT_COMMAND_SET_FLY (77)
        {
            uint32 enabled;                                 // datalong
        } setFly;

        struct                                              // SCRIPT_COMMAND_JOIN_CREATURE_GROUP (78)
        {
            uint32 options;                                 // datalong
        } joinCreatureGroup;

                                                            // SCRIPT_COMMAND_LEAVE_CREATURE_GROUP (79)

        struct                                              // SCRIPT_COMMAND_SET_GO_STATE (80)
        {
            uint32 state;                                   // datalong
        } setGoState;

        struct                                              // SCRIPT_COMMAND_DESPAWN_GAMEOBJECT (81)
        {
            uint32 goGuid;                                  // datalong
            uint32 respawnDelay;                            // datalong2
        } despawnGo;

        struct                                              // SCRIPT_COMMAND_LOAD_GAMEOBJECT (82)
        {
            uint32 goGuid;                                  // datalong
        } loadGo;

                                                            // SCRIPT_COMMAND_QUEST_CREDIT (83)

        struct                                              // SCRIPT_COMMAND_SET_GOSSIP_MENU (84)
        {
            uint32 gossipMenuId;                            // datalong
        } setGossipMenu;

        struct                                              // SCRIPT_COMMAND_SEND_SCRIPT_EVENT (85)
        {
            uint32 eventId;                                 // datalong
            uint32 eventData;                               // datalong2
        } sendScriptEvent;

        struct                                              // SCRIPT_COMMAND_SET_PVP (86)
        {
            uint32 enabled;                                 // datalong
        } setPvP;

                                                            // SCRIPT_COMMAND_RESET_DOOR_OR_BUTTON (87)

        struct
        {
            uint32 data[9];
        } raw;
    };

    uint32 target_param1;
    uint32 target_param2;
    uint8 target_type;

    float x;
    float y;
    float z;
    float o;

    ScriptInfo() : id(0), delay(0), command(0), condition(0), target_param1(0), target_param2(0), target_type(0), x(0), y(0), z(0), o(0)
    {
        memset(raw.data, 0, sizeof(raw.data));
    }

    // helpers
    uint32 GetGOGuid() const
    {
        switch(command)
        {
            case SCRIPT_COMMAND_RESPAWN_GAMEOBJECT: return respawnGo.goGuid;
            case SCRIPT_COMMAND_DESPAWN_GAMEOBJECT: return despawnGo.goGuid;
            case SCRIPT_COMMAND_LOAD_GAMEOBJECT: return loadGo.goGuid;
            case SCRIPT_COMMAND_OPEN_DOOR: return openDoor.goGuid;
            case SCRIPT_COMMAND_CLOSE_DOOR: return closeDoor.goGuid;
            default: return 0;
        }
    }
};

struct ScriptAction
{
    ObjectGuid sourceGuid;
    ObjectGuid targetGuid;
    ScriptInfo const* script;                               // pointer to static script data

    bool IsSameScript(uint32 id, ObjectGuid sourceGuid, ObjectGuid targetGuid) const
    {
        return id == script->id &&
            (sourceGuid == this->sourceGuid || !sourceGuid) &&
            (targetGuid == this->targetGuid || !targetGuid);
    }
};

// Values used in target_type column
enum ScriptTarget
{
    TARGET_T_PROVIDED_TARGET                = 0,            //Object that was provided to the command.

    TARGET_T_HOSTILE                        = 1,            //Our current target (ie: highest aggro).
    TARGET_T_HOSTILE_SECOND_AGGRO           = 2,            //Second highest aggro (generaly used for cleaves and some special attacks).
                                                            //Param1 = select_flags
    TARGET_T_HOSTILE_LAST_AGGRO             = 3,            //Dead last on aggro (no idea what this could be used for).
                                                            //Param1 = select_flags
    TARGET_T_HOSTILE_RANDOM                 = 4,            //Just any random target on our threat list.
                                                            //Param1 = select_flags
    TARGET_T_HOSTILE_RANDOM_NOT_TOP         = 5,            //Any random target except top threat.
                                                            //Param1 = select_flags

    TARGET_T_OWNER_OR_SELF                  = 6,            //Either self or owner if pet or controlled.
    TARGET_T_OWNER                          = 7,            //The owner of the source.
    

    TARGET_T_NEAREST_CREATURE_WITH_ENTRY    = 8,            //Searches for closest nearby creature with the given entry.
                                                            //Param1 = creature_entry
                                                            //Param2 = search_radius

    TARGET_T_CREATURE_WITH_GUID             = 9,            //The creature with this database guid.
                                                            //Param1 = db_guid

    TARGET_T_CREATURE_FROM_INSTANCE_DATA    = 10,           //Find creature by guid stored in instance data.
                                                            //Param1 = instance_data_field

    TARGET_T_NEAREST_GAMEOBJECT_WITH_ENTRY  = 11,           //Searches for closest nearby gameobject with the given entry.
                                                            //Param1 = gameobject_entry
                                                            //Param2 = search_radius

    TARGET_T_GAMEOBJECT_WITH_GUID           = 12,           //The gameobject with this database guid.
                                                            //Param1 = db_guid

    TARGET_T_GAMEOBJECT_FROM_INSTANCE_DATA  = 13,           //Find gameobject by guid stored in instance data.
                                                            //Param1 = instance_data_field

    TARGET_T_FRIENDLY                       = 14,           //Random friendly unit.
                                                            //Param1 = search_radius
                                                            //Param2 = (bool) exclude_target
    TARGET_T_FRIENDLY_INJURED               = 15,           //Friendly unit missing the most health.
                                                            //Param1 = search_radius
                                                            //Param2 = hp_percent
    TARGET_T_FRIENDLY_INJURED_EXCEPT        = 16,           //Friendly unit missing the most health but not provided target.
                                                            //Param1 = search_radius
                                                            //Param2 = hp_percent
    TARGET_T_FRIENDLY_MISSING_BUFF          = 17,           //Friendly unit without aura.
                                                            //Param1 = search_radius
                                                            //Param2 = spell_id
    TARGET_T_FRIENDLY_MISSING_BUFF_EXCEPT   = 18,           //Friendly unit without aura but not provided target.
                                                            //Param1 = search_radius
                                                            //Param2 = spell_id
    TARGET_T_FRIENDLY_CC                    = 19,           //Friendly unit under crowd control.
                                                            //Param1 = search_radius
    TARGET_T_MAP_EVENT_SOURCE               = 20,           //The source WorldObject of a scripted map event.
                                                            //Param1 = eventId
    TARGET_T_MAP_EVENT_TARGET               = 21,           //The target WorldObject of a scripted map event.
                                                            //Param1 = eventId
    TARGET_T_MAP_EVENT_EXTRA_TARGET         = 22,           //An additional WorldObject target from a scripted map event.
                                                            //Param1 = eventId
                                                            //Param2 = creature_entry or gameobject_entry
    TARGET_T_NEAREST_PLAYER                 = 23,           //Nearest player within range.
                                                            //Param1 = search-radius
    TARGET_T_NEAREST_HOSTILE_PLAYER         = 24,           //Nearest hostile player within range.
                                                            //Param1 = search-radius
    TARGET_T_NEAREST_FRIENDLY_PLAYER        = 25,           //Nearest friendly player within range.
                                                            //Param1 = search-radius
    TARGET_T_RANDOM_CREATURE_WITH_ENTRY     = 26,           //Searches for random nearby creature with the given entry. Not Self.
                                                            //Param1 = creature_entry
                                                            //Param2 = search_radius
    TARGET_T_RANDOM_GAMEOBJECT_WITH_ENTRY   = 27,           //Searches for random nearby gameobject with the given entry.
                                                            //Param1 = gameobject_entry
                                                            //Param2 = search_radius
    TARGET_T_END
};

#endif