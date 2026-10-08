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

#include "AIGroupMgr.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Timer.h"
#include "WaypointManager.h"

AIGroupMgr* AIGroupMgr::Instance()
{
    static AIGroupMgr instance;
    return &instance;
}

void AIGroupMgr::LoadActionSetsFromDB()
{
    uint32 oldMSTime = getMSTime();

    mActionSetMap.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ACTION_SET);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 action sets. DB table `action_set` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        ActionSetEventHolder eventHolder;

        Field* fields = result->Fetch();

        eventHolder.Id = fields[0].GetUInt32();
        eventHolder.Index = fields[1].GetUInt16();
        eventHolder.Type = fields[2].GetUInt16();
        eventHolder.Unit = fields[3].GetUInt8();
        eventHolder.Point = fields[4].GetUInt32();
        eventHolder.Path = fields[5].GetUInt32();
        eventHolder.TimeA = fields[6].GetUInt32();
        eventHolder.MoveSpeed = fields[7].GetUInt8();
        eventHolder.StringId = fields[8].GetString();
        eventHolder.TimeB = fields[9].GetUInt32();
        eventHolder.LinearPath = fields[10].GetBool();
        eventHolder.CircularPath = fields[11].GetBool();
        eventHolder.FlightPath = fields[12].GetBool();
        eventHolder.Extra0 = fields[13].GetDouble();
        eventHolder.Extra1 = fields[14].GetDouble();
        eventHolder.Extra2 = fields[15].GetDouble();
        eventHolder.Extra3 = fields[16].GetDouble();
        eventHolder.Extra4 = fields[17].GetDouble();
        eventHolder.TargetType = fields[18].GetUInt8();
        eventHolder.TargetParam1 = fields[19].GetUInt32();
        eventHolder.TargetParam2 = fields[20].GetUInt32();
        eventHolder.TargetParam3 = fields[21].GetUInt32();
        eventHolder.TargetParam4 = fields[22].GetUInt32();

        if (eventHolder.Unit && eventHolder.Unit >= uint8(AIGroupUnit::Max))
        {
            TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) has invalid Unit ({}), skipped.",
                eventHolder.Id, eventHolder.Index, eventHolder.Unit);
            continue;
        }

        if (eventHolder.Path && !sWaypointMgr->GetPath(eventHolder.Path))
        {
            TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) has invalid Path ({}), skipped.",
                eventHolder.Id, eventHolder.Index, eventHolder.Path);
            continue;
        }

        if (eventHolder.TimeB && eventHolder.TimeA > eventHolder.TimeB)
        {
            TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) has invalid TimeA ({}), greater than TimeB ({}), skipped.",
                eventHolder.Id, eventHolder.Index, eventHolder.TimeA, eventHolder.TimeB);
            continue;
        }

        if (eventHolder.MoveSpeed >= uint8(MoveSpeed::Max))
        {
            TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) has invalid MoveSpeed ({}), skipped.",
                eventHolder.Id, eventHolder.Index, eventHolder.MoveSpeed);
            continue;
        }

        if (!IsActionValid(eventHolder))
            continue;

        AIGroupActionSet& actionSet = mActionSetMap[eventHolder.Id];
        if (actionSet.empty())
            ++count;
        actionSet.push_back(eventHolder);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} action sets in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AIGroupMgr::LoadActionSetsNamesFromDB()
{
    uint32 oldMSTime = getMSTime();

    _actionSets.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ACTION_SET_NAME);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 action set names. DB table `action_set_name` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        ActionSetHolder set;

        Field* fields = result->Fetch();

        set.Id = fields[0].GetUInt32();
        set.Flags = fields[1].GetUInt32();
        set.Priority = fields[2].GetUInt8();
        set.Name = fields[3].GetString();

        if (set.Flags & ~uint32(ActionSetFlags::ActionSetFlagsAll))
        {
            TC_LOG_ERROR("sql.sql", "Table `action_set_name` (Id: {}) has invalid Flags ({}).",
                set.Id, set.Flags);
        }

        if (set.Priority >= uint8(ActionSetPriorityType::Max))
        {
            TC_LOG_ERROR("sql.sql", "Table `action_set_name` (Id: {}) has invalid Priority ({}), skipped.",
                set.Id, set.Priority);
            continue;
        }

        _actionSets[set.Id] = std::move(set);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} action set names in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AIGroupMgr::LoadRandomActionSetsFromDB()
{
    uint32 oldMSTime = getMSTime();

    mRandomActionSetMap.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_RANDOM_ACTION_SET);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 random action sets. DB table `random_action_set` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        RandomActionSetHolder randomActionSetHolder;

        randomActionSetHolder.Id = fields[0].GetUInt32();
        randomActionSetHolder.Index = fields[1].GetUInt16();
        randomActionSetHolder.Probability = fields[2].GetFloat();
        randomActionSetHolder.ActionSetId = fields[3].GetUInt32();

        if (!randomActionSetHolder.ActionSetId || mActionSetMap.find(randomActionSetHolder.ActionSetId) == mActionSetMap.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `random_action_set` (Id: {}, Index: {}) references an invalid ActionSetId ({}), skipped.",
                randomActionSetHolder.Id, randomActionSetHolder.Index, randomActionSetHolder.ActionSetId);
            continue;
        }

        AIGroupRandomActionSet& randomActionSet = mRandomActionSetMap[randomActionSetHolder.Id];
        if (randomActionSet.empty())
            ++count;
        randomActionSet.push_back(randomActionSetHolder);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} random action sets in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AIGroupMgr::LoadActionTriggersFromDB()
{
    uint32 oldMSTime = getMSTime();

    mEventMap.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ACTION_TRIGGERS);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 action triggers. DB table `action_triggers` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        ActionTriggersHolder triggers;

        Field* fields = result->Fetch();

        triggers.Id = fields[0].GetUInt32();
        triggers.Index = fields[1].GetUInt16();
        triggers.Chance = fields[2].GetUInt8();
        triggers.Flags = fields[3].GetUInt32();
        triggers.CombatCondition = fields[4].GetInt32();
        triggers.TriggerId = fields[5].GetUInt8();
        triggers.TriggerParam1 = fields[6].GetUInt32();
        triggers.TriggerParam2 = fields[7].GetUInt32();
        triggers.ActionSetId = fields[8].GetUInt32();
        triggers.RepeatMin = fields[9].GetUInt32();
        triggers.RepeatMax = fields[10].GetUInt32();

        if (triggers.TriggerId >= ActionTriggers::Max)
        {
            TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) has invalid TriggerId ({}), skipped.",
                triggers.Id, triggers.Index, triggers.TriggerId);
            continue;
        }

        ActionTriggerTypeInfo const& triggerType = StaticActionTriggerTypeData[triggers.TriggerId];

        if (!triggers.Chance || triggers.Chance > 100)
        {
            TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has an invalid Chance ({}), skipped.",
                triggers.Id, triggers.Index, triggerType.Name, triggers.Chance);
            continue;
        }

        if (triggers.Flags & ~ActionTriggersFlagsAll)
        {
            TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has invalid Flags ({}).",
                triggers.Id, triggers.Index, triggerType.Name, triggers.Flags);
        }

        switch (triggers.TriggerId)
        {
            case OnReaction:
                // Detection Type
                break;
            case OnHealthRange:
            case OnEnergyRange:
            case OnHealthRangeRandom:
            case OnEnergyRangeRandom:
                if (triggers.TriggerParam1 > 100)
                {
                    TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has trigger param 1 higner than 100 {}, skipped.",
                        triggers.Id, triggers.Index, triggerType.Name, triggers.TriggerParam1);
                    continue;
                }
                if (triggers.TriggerParam2 > 100)
                {
                    TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has trigger param 2 higner than 100 {}, skipped.",
                        triggers.Id, triggers.Index, triggerType.Name, triggers.TriggerParam2);
                    continue;
                }
                if (triggers.TriggerParam1 > triggers.TriggerParam2)
                {
                    TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has trigger param 1 higner than trigger param 2, skipped.",
                        triggers.Id, triggers.Index, triggerType.Name);
                    continue;
                }
                if (triggers.RepeatMin == 0 && triggers.RepeatMax == 0 && !(triggers.Flags & NotRepeatable))
                {
                    triggers.Flags |= NotRepeatable;
                    TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has missing NotRepeatable flag.",
                        triggers.Id, triggers.Index, triggerType.Name);
                }
                break;
            case OnEmote:
                if (!sEmotesStore.LookupEntry(triggers.TriggerParam1))
                {
                    TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} uses non-existent emote {}, skipped.",
                        triggers.Id, triggers.Index, triggerType.Name, triggers.TriggerParam1);
                    continue;
                }
                break;
            case OnCombatTrigger:
                // Trigger ID
                break;
            case OnSpell:
            case OnSpellCast:
            case OnSpellFailed:
            case OnSpellStart:
            case OnAuraApplied:
            case OnAuraRemoved:
            case OnChannelStart:
            case OnChannelInterrupted:
            case OnChannelFinished:
                if (!sSpellMgr->GetSpellInfo(triggers.TriggerParam1))
                {
                    TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} uses non-existent spell {}, skipped.",
                        triggers.Id, triggers.Index, triggerType.Name, triggers.TriggerParam1);
                    continue;
                }
                break;
            case OnPassengerControlEnd:
            case OnVehicleReturn:
            case OnVehicleRide:
            case OnVehicleAbandon:
            case OnPassengerRide:
            case OnPassengerAbandon:
            case OnPassengerSpawn:
                if (triggers.TriggerParam1 >= MAX_VEHICLE_SEATS)
                {
                    TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has invalid seat id {} (must be less than {}), skipped.",
                        triggers.Id, triggers.Index, triggerType.Name, triggers.TriggerParam1, MAX_VEHICLE_SEATS);
                    continue;
                }
                break;
            case OnLootLockReleased:
                // Loot Window
                break;
            default:
                break;
        }

        if (triggers.TriggerParam1 && !triggerType.HasTriggerParam1)
            TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has useless data in TriggerParam1 ({}).",
                triggers.Id, triggers.Index, triggerType.Name, triggers.TriggerParam1);

        if (triggers.TriggerParam2 && !triggerType.HasTriggerParam2)
            TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has useless data in TriggerParam2 ({}).",
                triggers.Id, triggers.Index, triggerType.Name, triggers.TriggerParam2);

        if (!triggers.ActionSetId || mActionSetMap.find(triggers.ActionSetId) == mActionSetMap.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} references an invalid ActionSetId ({}), skipped.",
                triggers.Id, triggers.Index, triggerType.Name, triggers.ActionSetId);
            continue;
        }

        if (triggers.RepeatMax < triggers.RepeatMin)
        {
            TC_LOG_ERROR("sql.sql", "Table `action_triggers` (Id: {}, Index: {}) with trigger {} has invalid RepeatMax data, skipped.",
                triggers.Id, triggers.Index, triggerType.Name);
            continue;
        }

        mEventMap[triggers.Id].push_back(triggers);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} action triggers in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AIGroupMgr::LoadActionTriggersNamesFromDB()
{
    uint32 oldMSTime = getMSTime();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ACTION_TRIGGERS_NAME);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 action trigger names. DB table `action_triggers_name` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 Id = fields[0].GetUInt32();
        std::string Name = fields[1].GetString();

        _actionTriggerNames[Id] = std::move(Name);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} action trigger names in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool AIGroupMgr::IsActionValid(ActionSetEventHolder const& action)
{
    if (!IsActionTypeValid(action))
        return false;

    LogUselessActionParams(action);

    if (action.TargetType >= AIGROUP_TARGET_END)
    {
        TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) has invalid target type {}, skipped.",
            action.Id, action.Index, action.TargetType);
        return false;
    }

    if (!IsSpellValid(action))
        return false;

    if (!IsBroadcastTextValid(action))
        return false;

    if (!IsCreatureValid(action))
        return false;

    if (!IsAnimTierValid(action))
        return false;

    if (!IsEmoteValid(action))
        return false;

    if (!IsSoundValid(action))
        return false;

    if (!IsQuestValid(action))
        return false;

    if (!IsZoneValid(action))
        return false;

    if (!IsItemValid(action))
        return false;

    if (!IsBooleanValid(action))
        return false;

    return true;
}

void AIGroupMgr::LogUselessActionParams(ActionSetEventHolder const& action)
{
    ActionSetTypeInfo const& typeInfo = StaticActionSetTypeData[action.Type];

    auto LogIfUseless = [&action, &typeInfo](bool isUsed, bool hasValue, char const* name, auto const& value)
    {
        if (hasValue && !isUsed)
            TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} ({}) has useless data in {} ({}).",
                action.Id, action.Index, action.Type, typeInfo.Name, name, value);
    };

    LogIfUseless(typeInfo.HasUnit, action.Unit != 0, "Unit", action.Unit);
    LogIfUseless(typeInfo.HasPoint, action.Point != 0, "Point", action.Point);
    LogIfUseless(typeInfo.HasPath, action.Path != 0, "Path", action.Path);
    LogIfUseless(typeInfo.HasTimeA, action.TimeA != 0, "TimeA", action.TimeA);
    LogIfUseless(typeInfo.HasMoveSpeed, action.MoveSpeed != 0, "MoveSpeed", action.MoveSpeed);
    LogIfUseless(typeInfo.HasStringId, !action.StringId.empty(), "StringId", action.StringId);
    LogIfUseless(typeInfo.HasTimeB, action.TimeB != 0, "TimeB", action.TimeB);
    LogIfUseless(typeInfo.HasLinearPath, action.LinearPath, "LinearPath", action.LinearPath);
    LogIfUseless(typeInfo.HasCircularPath, action.CircularPath, "CircularPath", action.CircularPath);
    LogIfUseless(typeInfo.HasFlightPath, action.FlightPath, "FlightPath", action.FlightPath);
    LogIfUseless(typeInfo.HasExtra0, action.Extra0 != 0, "Extra0", action.Extra0);
    LogIfUseless(typeInfo.HasExtra1, action.Extra1 != 0, "Extra1", action.Extra1);
    LogIfUseless(typeInfo.HasExtra2, action.Extra2 != 0, "Extra2", action.Extra2);
    LogIfUseless(typeInfo.HasExtra3, action.Extra3 != 0, "Extra3", action.Extra3);
    LogIfUseless(typeInfo.HasExtra4, action.Extra4 != 0, "Extra4", action.Extra4);
}

bool AIGroupMgr::IsActionTypeValid(ActionSetEventHolder const& action)
{
    if (action.Type >= AI_GROUP_MAX)
    {
        TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) has invalid action type {}, skipped.",
            action.Id, action.Index, action.Type);
        return false;
    }

    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_WANDER_AREA:
        case AI_GROUP_GUARD_AREA:
        case AI_GROUP_UNIT_CHANGE_MODE_OBSOLETE:
        case AI_GROUP_SET_RADIUS_OBSOLETE:
        case AI_GROUP_SET_FACTION_OBSOLETE:
        case AI_GROUP_PLAYER_ACTION:
        case AI_GROUP_VENDOR_IDLE_OBSOLETE:
            // ^ Officially unused \ obsolete \ reused \ not yet implemented
        case AI_GROUP_UNIT_CAST_RANDOM_UNIT:
        case AI_GROUP_UNIT_CAST_RANDOM_PLAYER:
        case AI_GROUP_UNIT_CAST_OTHER_UNIT:
        case AI_GROUP_MOVE_CIRCLE_RELATIVE:
        case AI_GROUP_RETURN_HOME_INSTANTLY:
        case AI_GROUP_ABORT_ACTION_SET_NO_STRINGID:
        case AI_GROUP_ABORT_ACTION_SET_COMBAT_CONDITION_TRUE:
        case AI_GROUP_FORCE_COMBAT:
        case AI_GROUP_STOP_FORCE_COMBAT:
        case AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT:
        case AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT_RESET:
        case AI_GROUP_UNIT_NO_MELEE_APPROACH:
        case AI_GROUP_UNIT_NO_MELEE_APPROACH_RESET:
        case AI_GROUP_UNIT_RAID_LOCK_TAP_LIST:
        case AI_GROUP_UNIT_CANNOT_TURN:
        case AI_GROUP_UNIT_CANNOT_TURN_RESET:
        case AI_GROUP_UNIT_PREFER_NPCS_ENEMIES:
        case AI_GROUP_UNIT_PREFER_NPCS_ENEMIES_RESET:
        case AI_GROUP_OBJECT_FACTION:
        case AI_GROUP_OBJECT_FACTION_RESET:
        case AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_KIT:
        case AI_GROUP_UNIT_PERFORM_SPELL_VISUAL:
        case AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_ACTIONS:
        case AI_GROUP_UNIT_NO_LEAVECOMBAT_STATE_RESTORE:
        case AI_GROUP_OBJECT_STRINGID:
        case AI_GROUP_OBJECT_STRINGID_RESET:
        case AI_GROUP_UNIT_DESPAWN_PERSISTENT_AURA_OBJECTS:
        case AI_GROUP_UNIT_DEFAULT_MOUNT:
        case AI_GROUP_UNIT_DEFAULT_MOUNT_RESET:
        case AI_GROUP_ABORT_ACTION_SET_FOUND_STRINGID:
        case AI_GROUP_UNSUPPRESS_NPC_GREETINGS:
        case AI_GROUP_SUPPRESS_NPC_GREETINGS:
        case AI_GROUP_UNIT_CLEAR_BOSS_EMOTES:
        case AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_ZONE:
        case AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_PLAYER:
        case AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE:
        case AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE_RESET:
        case AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION:
        case AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION_RESET:
        case AI_GROUP_FOLLOW_TAXI_PATH:
        case AI_GROUP_FOLLOW_TAXI_PATH_RELATIVE:
        case AI_GROUP_START_DUNGEON_ENCOUNTER:
        case AI_GROUP_END_DUNGEON_ENCOUNTER:
            // ^ 4.3.4
        case AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL:
        case AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL_RESET:
        case AI_GROUP_UNIT_TRACK_PLAYER_STAT:
        case AI_GROUP_UNIT_CANNOT_PENETRATE_WATER:
        case AI_GROUP_UNIT_CANNOT_PENETRATE_WATER_RESET:
        case AI_GROUP_UNIT_DESPAWN_STRINGID:
        case AI_GROUP_UNIT_SET_SAFE_LOCATION:
        case AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT:
        case AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT_RESET:
        case AI_GROUP_UNIT_DESPAWN_SUMMONED_AREA_TRIGGERS:
        case AI_GROUP_UNIT_ADD_PERMANENT_WORLD_EFFECT:
        case AI_GROUP_UNIT_REMOVE_PERMANENT_WORLD_EFFECT:
        case AI_GROUP_UNIT_CAST_WITH_POINTS_OTHER_UNIT:
        case AI_GROUP_UNIT_SET_ANCHOR_POINT:
        case AI_GROUP_CIRCLE_UNIT:
        case AI_GROUP_RUN_SPELL_SCRIPT:
        case AI_GROUP_TURN_IN_PLACE_DEGREES:
        case AI_GROUP_TURN_IN_PLACE_TIMED:
        case AI_GROUP_UNIT_PREFER_UNENGAGED_TARGETS:
        case AI_GROUP_UNIT_GENERATE_SPAWNGROUP_EVENT:
        case AI_GROUP_PUSH_ACTIONSET:
            // ^ 6.0.1 Build 18125
        case AI_GROUP_MOVE_ON_PATH_GRAPH_TO_POINT:
        case AI_GROUP_TRIGGER_ACTIONS_ON_SELF:
        case AI_GROUP_UNIT_EJECT_PASSENGER:
        case AI_GROUP_PERFORM_ACTIONSET:
        case AI_GROUP_UNIT_PAUSE_SPELL_COOLDOWNS:
        case AI_GROUP_UNIT_RESUME_SPELL_COOLDOWNS:
        case AI_GROUP_UNIT_TRIGGER_SPELL_CATEGORY_COOLDOWN:
        case AI_GROUP_UNIT_PLAY_SOUND_ON_ITSELF_SPEAKERBOT:
        case AI_GROUP_UNIT_STOP_SPEAKERBOT_SOUND:
            // ^ 6.0.3 Build 19342
            // ^ 6.1.2 Build 19865
            // ^ 6.2.0 Build 20253
        case AI_GROUP_UNIT_BECOME_PERSONAL_INVIS_CLONE:
        case AI_GROUP_MOVE_ON_PATH_GRAPH_TO_GUID:
        case AI_GROUP_MOVE_ON_PATH_GRAPH_MULTIPLE_POINTS:
        case AI_GROUP_UNIT_NEVER_EVADE:
        case AI_GROUP_UNIT_NEVER_EVADE_RESET:
        case AI_GROUP_UNIT_DONT_LEAVE_COMBAT:
        case AI_GROUP_UNIT_CANCEL_CURRENT_SPELL:
        case AI_GROUP_UNIT_SAY_GAME_REGION:
        case AI_GROUP_UNIT_SAY_GAME_REGION_RANDOM:
        case AI_GROUP_UNIT_YELL_GAME_REGION:
        case AI_GROUP_UNIT_YELL_GAME_REGION_RANDOM:
        case AI_GROUP_COMBAT_POSITION:
        case AI_GROUP_COMBAT_CHASE:
        case AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT:
        case AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT_RES:
            // ^ 7.3.5 Build 25717
        case AI_GROUP_RESERVED_1:
        case AI_GROUP_RESERVED_2:
        case AI_GROUP_RESERVED_3:
        case AI_GROUP_RESERVED_4:
        case AI_GROUP_RESERVED_5:
        case AI_GROUP_RESERVED_6:
        case AI_GROUP_RESERVED_7:
        case AI_GROUP_RESERVED_8:
        case AI_GROUP_RESERVED_9:
        case AI_GROUP_RESERVED_10:
        case AI_GROUP_RESERVED_11:
        case AI_GROUP_RESERVED_12:
        case AI_GROUP_RESERVED_13:
        case AI_GROUP_RESERVED_14:
        case AI_GROUP_RESERVED_15:
        case AI_GROUP_RESERVED_16:
        case AI_GROUP_RESERVED_17:
        case AI_GROUP_RESERVED_18:
        case AI_GROUP_RESERVED_19:
        case AI_GROUP_RESERVED_20:
        case AI_GROUP_RESERVED_21:
        case AI_GROUP_RESERVED_22:
        case AI_GROUP_RESERVED_23:
        case AI_GROUP_RESERVED_24:
        case AI_GROUP_RESERVED_25:
        case AI_GROUP_RESERVED_26:
        case AI_GROUP_RESERVED_27:
        case AI_GROUP_RESERVED_28:
        case AI_GROUP_RESERVED_29:
        case AI_GROUP_RESERVED_30:
        case AI_GROUP_RESERVED_31:
        case AI_GROUP_RESERVED_32:
        case AI_GROUP_RESERVED_33:
        case AI_GROUP_RESERVED_34:
        case AI_GROUP_RESERVED_35:
        case AI_GROUP_RESERVED_36:
        case AI_GROUP_RESERVED_37:
        case AI_GROUP_RESERVED_38:
        case AI_GROUP_RESERVED_39:
        case AI_GROUP_RESERVED_40:
        case AI_GROUP_RESERVED_41:
        case AI_GROUP_RESERVED_42:
        case AI_GROUP_RESERVED_43:
        case AI_GROUP_RESERVED_44:
        case AI_GROUP_RESERVED_45:
        case AI_GROUP_RESERVED_46:
        case AI_GROUP_RESERVED_47:
        case AI_GROUP_RESERVED_48:
        case AI_GROUP_RESERVED_49:
        case AI_GROUP_RESERVED_50:
        case AI_GROUP_RESERVED_51:
        case AI_GROUP_RESERVED_52:
        case AI_GROUP_RESERVED_53:
        case AI_GROUP_RESERVED_54:
        case AI_GROUP_RESERVED_55:
        case AI_GROUP_RESERVED_56:
        case AI_GROUP_RESERVED_57:
        case AI_GROUP_RESERVED_58:
        case AI_GROUP_RESERVED_59:
        case AI_GROUP_RESERVED_60:
        case AI_GROUP_RESERVED_61:
        case AI_GROUP_RESERVED_62:
        case AI_GROUP_RESERVED_63:
        case AI_GROUP_RESERVED_64:
        case AI_GROUP_RESERVED_65:
        case AI_GROUP_RESERVED_66:
        case AI_GROUP_RESERVED_67:
        case AI_GROUP_RESERVED_68:
        case AI_GROUP_RESERVED_69:
        case AI_GROUP_RESERVED_70:
        case AI_GROUP_RESERVED_71:
        case AI_GROUP_RESERVED_72:
        case AI_GROUP_RESERVED_73:
        case AI_GROUP_RESERVED_74:
        case AI_GROUP_RESERVED_75:
        case AI_GROUP_RESERVED_76:
        case AI_GROUP_RESERVED_77:
        case AI_GROUP_RESERVED_78:
        case AI_GROUP_RESERVED_79:
        case AI_GROUP_RESERVED_80:
        case AI_GROUP_RESERVED_81:
        case AI_GROUP_RESERVED_82:
        case AI_GROUP_RESERVED_83:
        case AI_GROUP_RESERVED_84:
        case AI_GROUP_RESERVED_85:
        case AI_GROUP_RESERVED_86:
        case AI_GROUP_RESERVED_87:
        case AI_GROUP_RESERVED_88:
        case AI_GROUP_RESERVED_89:
        case AI_GROUP_RESERVED_90:
        case AI_GROUP_RESERVED_91:
        case AI_GROUP_RESERVED_92:
        case AI_GROUP_RESERVED_93:
        case AI_GROUP_RESERVED_94:
        case AI_GROUP_RESERVED_95:
        case AI_GROUP_RESERVED_96:
        case AI_GROUP_RESERVED_97:
        case AI_GROUP_RESERVED_98:
        case AI_GROUP_RESERVED_99:
        case AI_GROUP_RESERVED_100:
            // ^ Reserved
        case AI_GROUP_CU_1:
        case AI_GROUP_CU_2:
        case AI_GROUP_CU_3:
        case AI_GROUP_CU_4:
        case AI_GROUP_CU_5:
        case AI_GROUP_CU_6:
        case AI_GROUP_CU_7:
        case AI_GROUP_CU_8:
        case AI_GROUP_CU_9:
        case AI_GROUP_CU_10:
            // ^ Custom
            TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) has invalid action type {}, skipped.",
                action.Id, action.Index, action.Type);
            return false;
        default:
            return true;
    }
}

bool AIGroupMgr::IsSpellValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_UNIT_CAST:
        case AI_GROUP_UNIT_CANCEL_CAST:
        case AI_GROUP_UNIT_CANCEL_AURA:
        case AI_GROUP_UNIT_CAST_FAILURE:
        case AI_GROUP_UNIT_CAST_WITH_POINTS:
        case AI_GROUP_UNIT_RIDE_VEHICLE:
        case AI_GROUP_UNIT_INTERACT_SPELL:
        case AI_GROUP_UNIT_CAST_RANDOM_UNIT:
        case AI_GROUP_UNIT_CAST_RANDOM_PLAYER:
        case AI_GROUP_UNIT_CAST_OTHER_UNIT:
        case AI_GROUP_UNIT_CAST_WITH_POINTS_OTHER_UNIT:
            if (!sSpellMgr->GetSpellInfo(uint32(action.Extra2)))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses non-existent spell {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra2));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsBroadcastTextValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_UNIT_SAY:
        case AI_GROUP_UNIT_YELL:
        case AI_GROUP_UNIT_CHAT_EMOTE:
        case AI_GROUP_OBJECT_CHAT_EMOTE:
        case AI_GROUP_UNIT_WHISPER:
        case AI_GROUP_UNIT_CHAT_EMOTE_ZONE:
        case AI_GROUP_UNIT_YELL_ZONE:
        case AI_GROUP_OBJECT_CHAT_EMOTE_ZONE:
        case AI_GROUP_UNIT_BOSS_EMOTE:
        case AI_GROUP_UNIT_BOSS_EMOTE_ZONE:
        case AI_GROUP_UNIT_SAY_ZONE:
        case AI_GROUP_UNIT_CHAT_PARTY:
        case AI_GROUP_UNIT_BOSS_WHISPER:
        case AI_GROUP_UNIT_SAY_PLAYER:
        case AI_GROUP_UNIT_YELL_PLAYER:
        case AI_GROUP_UNIT_CHAT_EMOTE_PLAYER:
        case AI_GROUP_UNIT_SAY_GAME_REGION:
        case AI_GROUP_UNIT_YELL_GAME_REGION:
            if (!sObjectMgr->GetBroadcastText(uint32(action.Extra2)))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses non-existent broadcast text {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra2));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsCreatureValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_UNIT_MOUNT:
        case AI_GROUP_UNIT_MODE:
        case AI_GROUP_UNIT_KILL_CREDIT:
        case AI_GROUP_UNIT_KILL_CREDIT_TAP:
        case AI_GROUP_UNIT_KILL_CREDIT_PLAYER:
        case AI_GROUP_UNIT_DEFAULT_MOUNT:
            if (!sObjectMgr->GetCreatureTemplate(uint32(action.Extra2)))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses non-existent creature entry {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra2));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsAnimTierValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_TIER_TRANSITION_LAND:
        case AI_GROUP_TIER_TRANSITION_TAKE_OFF:
        case AI_GROUP_TIER_TRANSITION_MOVETO:
        case AI_GROUP_TIER_TRANSITION_MOVETO_GUID:
        case AI_GROUP_TIER_TRANSITION_FOLLOW_PATH:
            if (action.Extra2 >= uint8(AnimTier::Max))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses invalid anim tier {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra2));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsEmoteValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_UNIT_EMOTE:
        case AI_GROUP_EMOTE_STATE:
        case AI_GROUP_UNIT_EMOTE_PLAYER:
            if (!sEmotesStore.LookupEntry(uint32(action.Extra2)))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses non-existent emote {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra2));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsSoundValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_UNIT_PLAY_SOUND:
        case AI_GROUP_OBJECT_PLAY_SOUND:
        case AI_GROUP_UNIT_PLAY_SOUND_ZONE:
        case AI_GROUP_OBJECT_PLAY_SOUND_ZONE:
        case AI_GROUP_UNIT_PLAY_TARGETED_SOUND:
        case AI_GROUP_UNIT_PLAY_SOUND_ON_ITSELF_SPEAKERBOT:
        case AI_GROUP_UNIT_PLAY_MUSIC:
        case AI_GROUP_OBJECT_PLAY_MUSIC:
        case AI_GROUP_UNIT_PLAY_MUSIC_ZONE:
        case AI_GROUP_OBJECT_PLAY_MUSIC_ZONE:
        case AI_GROUP_UNIT_PLAY_TARGETED_MUSIC:
            if (!sSoundEntriesStore.LookupEntry(uint32(action.Extra2)))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses non-existent sound {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra2));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsQuestValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_QUEST_COMPLETE_TRIGGERING_PLAYER:
        case AI_GROUP_QUEST_CLEARED_TRIGGERING_PLAYER:
        case AI_GROUP_UNIT_START_QUEST:
            if (!sObjectMgr->GetQuestTemplate(uint32(action.Extra2)))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses non-existent quest {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra2));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsZoneValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_UNIT_CHAT_EMOTE_ZONE:
        case AI_GROUP_UNIT_CHAT_EMOTE_ZONE_RANDOM:
        case AI_GROUP_UNIT_YELL_ZONE:
        case AI_GROUP_UNIT_YELL_ZONE_RANDOM:
        case AI_GROUP_UNIT_PLAY_MUSIC_ZONE:
        case AI_GROUP_UNIT_PLAY_SOUND_ZONE:
        case AI_GROUP_OBJECT_PLAY_MUSIC_ZONE:
        case AI_GROUP_OBJECT_PLAY_SOUND_ZONE:
        case AI_GROUP_UNIT_BOSS_EMOTE_ZONE:
        case AI_GROUP_UNIT_SAY_ZONE:
        case AI_GROUP_UNIT_SAY_ZONE_RANDOM:
        case AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_ZONE:
            if (uint32(action.Extra4) != 0 && !sAreaTableStore.LookupEntry(uint32(action.Extra4)))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses non-existent zone {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra4));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsItemValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_UNIT_SET_ITEM_MAINHAND:
        case AI_GROUP_UNIT_SET_ITEM_OFFHAND:
        case AI_GROUP_UNIT_SET_ITEM_RANGED:
            if (!sItemStore.LookupEntry(uint32(action.Extra2)))
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses non-existent Item {}, skipped.",
                    action.Id, action.Index, action.Type, uint32(action.Extra2));
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

bool AIGroupMgr::IsBooleanValid(ActionSetEventHolder const& action)
{
    switch (AI_GROUP_ACTION(action.Type))
    {
        case AI_GROUP_ATTACK_GUID:
        case AI_GROUP_UNIT_UNINTERACTIBLE:
        case AI_GROUP_UNIT_IMMUNEPC:
        case AI_GROUP_UNIT_IMMUNENPC:
        case AI_GROUP_UNIT_UNKILLABLE:
        case AI_GROUP_UNIT_NO_LOOT:
        case AI_GROUP_UNIT_NO_XP:
        case AI_GROUP_UNIT_PVP_ENABLING:
        case AI_GROUP_UNIT_FLOATING:
        case AI_GROUP_UNIT_IGNORE_COMBAT:
        case AI_GROUP_UNIT_NO_REPUTATION:
        case AI_GROUP_UNIT_SESSILE:
        case AI_GROUP_UNIT_RAID_LOCK:
        case AI_GROUP_UNIT_NO_MELEE:
        case AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC:
        case AI_GROUP_UNIT_NO_THREAT_FEEDBACK:
        case AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT:
        case AI_GROUP_UNIT_NO_MELEE_APPROACH:
        case AI_GROUP_UNIT_CANNOT_TURN:
        case AI_GROUP_UNIT_PREFER_NPCS_ENEMIES:
        case AI_GROUP_UNIT_NO_LEAVECOMBAT_STATE_RESTORE:
        case AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE:
        case AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION:
        case AI_GROUP_UNIT_CANNOT_PENETRATE_WATER:
        case AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT:
        case AI_GROUP_UNIT_PREFER_UNENGAGED_TARGETS:
        case AI_GROUP_UNIT_NEVER_EVADE:
        case AI_GROUP_UNIT_DONT_LEAVE_COMBAT:
        case AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT:
            if (action.Extra2 != 0 && action.Extra2 != 1)
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses invalid boolean value {}, skipped.",
                    action.Id, action.Index, action.Type, action.Extra2);
                return false;
            }
            break;
        case AI_GROUP_UNIT_SET_ITEM_MAINHAND:
        case AI_GROUP_UNIT_SET_ITEM_OFFHAND:
        case AI_GROUP_UNIT_SET_ITEM_RANGED:
            if (action.Extra3 != 0 && action.Extra3 != 1)
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses invalid boolean value {}, skipped.",
                    action.Id, action.Index, action.Type, action.Extra3);
                return false;
            }
            break;
        case AI_GROUP_UNIT_SAY:
        case AI_GROUP_UNIT_ACTIVATE_OBJECT:
        case AI_GROUP_UNIT_SAY_RANDOM:
        case AI_GROUP_UNIT_YELL:
        case AI_GROUP_UNIT_YELL_RANDOM:
        case AI_GROUP_MOVE_RELATIVE:
        case AI_GROUP_UNIT_SAY_PLAYER:
        case AI_GROUP_UNIT_YELL_PLAYER:
        case AI_GROUP_END_DUNGEON_ENCOUNTER:
            if (action.Extra4 != 0 && action.Extra4 != 1)
            {
                TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) with action type {} uses invalid boolean value {}, skipped.",
                    action.Id, action.Index, action.Type, action.Extra4);
                return false;
            }
            break;
        default:
            break;
    }

    return true;
}

AIGroupMgr::ActionSetTypeInfo const AIGroupMgr::StaticActionSetTypeData[AI_GROUP_MAX] =
{
    { "AI_GROUP_SPAWN", { FieldTimeA, FieldExtra2 } },
    { "AI_GROUP_IDLE", { FieldTimeA, FieldTimeB } },
    { "AI_GROUP_MOVETO", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_TELEPORT", { FieldPoint, FieldStringId, FieldExtra0 } },
    { "AI_GROUP_WANDER", { FieldPoint, FieldTimeA, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2 } },
    { "AI_GROUP_ATTACK_ALL", { FieldExtra0 } },
    { "AI_GROUP_WANDER_AREA", {  } },
    { "AI_GROUP_FOLLOW_GUID", { FieldTimeA, FieldStringId, FieldExtra0, FieldExtra1 } },
    { "AI_GROUP_FOLLOW_PATH", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldExtra3 } },
    { "AI_GROUP_PATROL_LINE", { FieldPath, FieldTimeA, FieldMoveSpeed, FieldLinearPath, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_PATROL_CIRCLE", { FieldPath, FieldTimeA, FieldMoveSpeed, FieldCircularPath, FieldExtra3 } },
    { "AI_GROUP_GUARD_GUID", { FieldTimeA, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "AI_GROUP_GUARD_AREA", {  } },
    { "AI_GROUP_SET_FORMATION", { FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_CHANGE_MODE_OBSOLETE", {  } },
    { "AI_GROUP_UNIT_SAY", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_CAST", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_ACTIVATE_OBJECT", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_GENERATE_EVENT", { FieldExtra2 } },
    { "AI_GROUP_DESPAWN", {  } },
    { "AI_GROUP_SET_RADIUS_OBSOLETE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_SET_FACTION_OBSOLETE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SET_FACING", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_FACE_GUID", { FieldUnit, FieldStringId, FieldExtra0 } },
    { "AI_GROUP_UNIT_EMOTE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_MOVETO_GUID", { FieldTimeA, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_ATTACK_GUID", { FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_MOUNT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_DISMOUNT", { FieldUnit } },
    { "AI_GROUP_UNIT_UNINTERACTIBLE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_UNINTERACTIBLE_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_MODE", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_MODE_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_FACTION", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_FACTION_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_RADIUS", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_RADIUS_RESET", { FieldUnit } },
    { "AI_GROUP_QUEST_COMPLETE", {  } },
    { "AI_GROUP_UNIT_QUESTGIVER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_TRAINER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_SPLINE_PATH", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldExtra3 } },
    { "AI_GROUP_PLAYER_ACTION", { FieldExtra2 } },
    { "AI_GROUP_RETURN_HOME", { FieldTimeA, FieldMoveSpeed } },
    { "AI_GROUP_UNIT_SAY_RANDOM", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_YELL", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_YELL_RANDOM", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_SET_ITEM_MAINHAND", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_RESET_ITEM_MAINHAND", { FieldUnit } },
    { "AI_GROUP_UNIT_CHAT_EMOTE", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_CHAT_EMOTE_RANDOM", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_GENERATE_EVENT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_VENDOR_IDLE_OBSOLETE", {  } },
    { "AI_GROUP_QUEST_FAILED", {  } },
    { "AI_GROUP_UNIT_TRIGGERS", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_TRIGGERS_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_LEAVE_COMBAT", { FieldExtra2 } },
    { "AI_GROUP_IDLE_COMBAT_START", { FieldTimeA, FieldTimeB } },
    { "AI_GROUP_IDLE_COMBAT_STOP", { FieldTimeA, FieldTimeB } },
    { "AI_GROUP_UNIT_IMMUNEPC", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_IMMUNEPC_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_IMMUNENPC", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_IMMUNENPC_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_UNKILLABLE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_UNKILLABLE_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_SPELLS", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SPELLS_RESET", { FieldUnit } },
    { "AI_GROUP_ATTACK_ALL_INSTANCE", {  } },
    { "AI_GROUP_UNIT_SEND_LOCAL_EVENT", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_BROADCAST_LOCAL_EVENT", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_FLEE", { FieldTimeA } },
    { "AI_GROUP_UNIT_RETREAT", { FieldTimeA } },
    { "AI_GROUP_OBJECT_CHAT_EMOTE", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_OBJECT_CHAT_EMOTE_RANDOM", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_AVOID", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "AI_GROUP_AVOID_GUID", { FieldTimeA, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "AI_GROUP_OBJECT_ACTIVATE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_ACTIVATE_OBJECTS", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_STRINGID", { FieldUnit, FieldStringId, FieldExtra2 } },
    { "AI_GROUP_UNIT_STRINGID_RESET", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_PERIODIC_EVENT", { FieldTimeA, FieldExtra2 } },
    { "AI_GROUP_UNIT_SET_ITEM_OFFHAND", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_RESET_ITEM_OFFHAND", { FieldUnit } },
    { "AI_GROUP_UNIT_SET_ITEM_RANGED", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_RESET_ITEM_RANGED", { FieldUnit } },
    { "AI_GROUP_UNIT_SHEATHE", { FieldUnit } },
    { "AI_GROUP_UNIT_UNSHEATHE", { FieldUnit } },
    { "AI_GROUP_UNIT_CANCEL_CAST", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CANCEL_AURA", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_FINISH_CAST", { FieldUnit, FieldTimeA, FieldTimeB } },
    { "AI_GROUP_EMOTE_STATE", { FieldTimeA, FieldTimeB, FieldExtra2 } },
    { "AI_GROUP_UNIT_CALL_FOR_HELP", { FieldStringId, FieldExtra0 } },
    { "AI_GROUP_FLIGHT_PATH", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldFlightPath, FieldExtra3 } },
    { "AI_GROUP_UNIT_COMBAT_TRIGGER", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_GOSSIP", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_KILL_CREDIT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_WHISPER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_WHISPER_RANDOM", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_LOOT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_LOOT_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_NO_XP", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_XP_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_PVP_ENABLING", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_PVP_ENABLING_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_PLAY_MUSIC", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_PLAY_SOUND", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_SET_LOOT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_FLOATING", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_FLOATING_RESET", { FieldUnit } },
    { "AI_GROUP_OBJECT_PLAY_MUSIC", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_OBJECT_PLAY_SOUND", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_SPAWN_FORCED", { FieldTimeA, FieldExtra2 } },
    { "AI_GROUP_UNIT_UNSHEATHE_RANGE", { FieldUnit } },
    { "AI_GROUP_UNIT_CHAT_EMOTE_ZONE", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_CHAT_EMOTE_ZONE_RANDOM", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_YELL_ZONE", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_YELL_ZONE_RANDOM", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_PLAY_MUSIC_ZONE", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_PLAY_SOUND_ZONE", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_OBJECT_CHAT_EMOTE_ZONE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_OBJECT_CHAT_EMOTE_ZONE_RANDOM", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_OBJECT_PLAY_MUSIC_ZONE", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_OBJECT_PLAY_SOUND_ZONE", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_IGNORE_COMBAT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_IGNORE_COMBAT_RESET", { FieldUnit } },
    { "AI_GROUP_RANDOM_ACTION_SET", { FieldExtra2 } },
    { "AI_GROUP_RESTART_ACTIONS_WSE", { FieldExtra2 } },
    { "AI_GROUP_ABORT_ACTION_SET_WSE", { FieldExtra2 } },
    { "AI_GROUP_UNIT_BOSS_EMOTE", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_BOSS_EMOTE_ZONE", { FieldUnit, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT_IC", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_CAST_FAILURE", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_REPUTATION", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_REPUTATION_RESET", { FieldUnit } },
    { "AI_GROUP_SPLINE_PATH_LOOP", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldFlightPath, FieldExtra3 } },
    { "AI_GROUP_UNIT_VENDOR", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_RESET_VENDOR_LISTS", { FieldUnit } },
    { "AI_GROUP_TRIGGER_ACTIONS_UNITS", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_SAY_ZONE", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_SAY_ZONE_RANDOM", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_SEND_LOCAL_EVENT_SELF", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SESSILE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SESSILE_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_RAID_LOCK", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_RAID_LOCK_RESET", { FieldUnit } },
    { "AI_GROUP_QUEST_COMPLETE_TRIGGERING_PLAYER", { FieldExtra2 } },
    { "AI_GROUP_QUEST_CLEARED_TRIGGERING_PLAYER", { FieldExtra2 } },
    { "AI_GROUP_UNIT_CHAT_PARTY", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CLEAR_COOLDOWNS", { FieldUnit } },
    { "AI_GROUP_UNIT_PLAY_TARGETED_SOUND", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_PLAY_TARGETED_MUSIC", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_RESET_INITIAL_SPELL_COOLDOWNS", { FieldUnit } },
    { "AI_GROUP_UNIT_NO_MELEE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_MELEE_RESET", { FieldUnit } },
    { "AI_GROUP_FALL_TO_THE_GROUND", {  } },
    { "AI_GROUP_UNIT_UPDATE_INTERACTION", { FieldUnit } },
    { "AI_GROUP_UNIT_BOSS_WHISPER", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_BOSS_WHISPER_RANDOM", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_MOVE_RELATIVE", { FieldTimeA, FieldMoveSpeed, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_UNIT_DONT_CLEAR_TAP", { FieldUnit } },
    { "AI_GROUP_UNIT_KILL_CREDIT_TAP", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CAST_WITH_POINTS", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_RIDE_VEHICLE", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_ABANDON_VEHICLE", { FieldUnit } },
    { "AI_GROUP_VEHICLE_RECALL_OR_RESPAWN_PASSENGERS", { FieldUnit, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "AI_GROUP_PLAY_MOVIE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_JUMP_POINT", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_JUMP_GUID", { FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_MOVETO_THEN_JUMP", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "AI_GROUP_VEHICLE_RECALL_LIVING_PASSENGERS", { FieldUnit, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "AI_GROUP_VEHICLE_RESPAWN_ALL_PASSENGERS", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra3 } },
    { "AI_GROUP_UNIT_FATAL_FALL_DISTANCE", { FieldUnit, FieldExtra1 } },
    { "AI_GROUP_UNIT_FATAL_FALL_DISTANCE_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_SET_ANIMATION_TIER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SEND_TAP_LIST", { FieldUnit, FieldStringId, FieldExtra0 } },
    { "AI_GROUP_UNIT_GET_TAP_LIST", { FieldUnit, FieldStringId, FieldExtra0 } },
    { "AI_GROUP_UNIT_HOVER_HEIGHT", { FieldUnit, FieldExtra1 } },
    { "AI_GROUP_UNIT_HOVER_HEIGHT_RESET", { FieldUnit } },
    { "AI_GROUP_TIER_TRANSITION_LAND", { FieldMoveSpeed, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_TIER_TRANSITION_TAKE_OFF", { FieldMoveSpeed, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_TIER_TRANSITION_MOVETO", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldFlightPath, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_TIER_TRANSITION_MOVETO_GUID", { FieldMoveSpeed, FieldStringId, FieldFlightPath, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_TIER_TRANSITION_FOLLOW_PATH", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldFlightPath, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_KILL_CREDIT_PLAYER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_SUSPEND_TRIGGER_ACTION", { FieldTimeA, FieldTimeB } },
    { "AI_GROUP_UNIT_VEHICLE_RECORD", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_VEHICLE_RECORD_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_IMMUNITIES", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_IMMUNITIES_RESET", { FieldUnit } },
    { "AI_GROUP_SEND_CONTENT_ALERT", { FieldUnit } },
    { "AI_GROUP_UNIT_SAY_PLAYER", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_YELL_PLAYER", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_START_QUEST", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SAY_PLAYER_RANDOM", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_YELL_PLAYER_RANDOM", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_START_LOOPING_ANIM_KIT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_STOP_LOOPING_ANIM_KIT", { FieldUnit } },
    { "AI_GROUP_UNIT_PLAY_ONESHOT_ANIM_KIT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SET_MOVEMENT_ANIM_KIT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SET_MELEE_ANIM_KIT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_INTERACT_SPELL", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_INTERACT_SPELL_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_INTERACT_SPELL_CONDITION", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_INTERACT_SPELL_CONDITION_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_FACE_ANGLE_RELATIVE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_BOSS_UNIT_FRAMES_PRIORITY", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_BOSS_UNIT_FRAMES_PRIORITY_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_NO_THREAT_FEEDBACK", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_THREAT_FEEDBACK_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_CHAT_EMOTE_PLAYER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CHAT_EMOTE_PLAYER_RANDOM", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_EMOTE_PLAYER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SET_QUEST_LOOT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CAST_RANDOM_UNIT", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_CAST_RANDOM_PLAYER", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_CAST_OTHER_UNIT", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_MOVE_CIRCLE_RELATIVE", { FieldTimeA, FieldMoveSpeed, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_RETURN_HOME_INSTANTLY", {  } },
    { "AI_GROUP_ABORT_ACTION_SET_NO_STRINGID", { FieldStringId, FieldExtra0 } },
    { "AI_GROUP_ABORT_ACTION_SET_COMBAT_CONDITION_TRUE", { FieldExtra2 } },
    { "AI_GROUP_FORCE_COMBAT", { FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_STOP_FORCE_COMBAT", {  } },
    { "AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_NO_MELEE_APPROACH", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NO_MELEE_APPROACH_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_RAID_LOCK_TAP_LIST", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CANNOT_TURN", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CANNOT_TURN_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_PREFER_NPCS_ENEMIES", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_PREFER_NPCS_ENEMIES_RESET", { FieldUnit } },
    { "AI_GROUP_OBJECT_FACTION", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_OBJECT_FACTION_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_KIT", { FieldUnit, FieldTimeA, FieldTimeB, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_PERFORM_SPELL_VISUAL", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_ACTIONS", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_UNIT_NO_LEAVECOMBAT_STATE_RESTORE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_OBJECT_STRINGID", { FieldUnit, FieldStringId, FieldExtra2 } },
    { "AI_GROUP_OBJECT_STRINGID_RESET", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_DESPAWN_PERSISTENT_AURA_OBJECTS", { FieldUnit, FieldExtra0 } },
    { "AI_GROUP_UNIT_DEFAULT_MOUNT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_DEFAULT_MOUNT_RESET", { FieldUnit } },
    { "AI_GROUP_ABORT_ACTION_SET_FOUND_STRINGID", { FieldStringId, FieldExtra0 } },
    { "AI_GROUP_UNSUPPRESS_NPC_GREETINGS", {  } },
    { "AI_GROUP_SUPPRESS_NPC_GREETINGS", {  } },
    { "AI_GROUP_UNIT_CLEAR_BOSS_EMOTES", { FieldUnit, FieldExtra0 } },
    { "AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_ZONE", { FieldUnit, FieldExtra4 } },
    { "AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_PLAYER", { FieldUnit } },
    { "AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION_RESET", { FieldUnit } },
    { "AI_GROUP_FOLLOW_TAXI_PATH", { FieldMoveSpeed, FieldLinearPath, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_FOLLOW_TAXI_PATH_RELATIVE", { FieldMoveSpeed, FieldLinearPath, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_START_DUNGEON_ENCOUNTER", { FieldExtra2 } },
    { "AI_GROUP_END_DUNGEON_ENCOUNTER", { FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_TRACK_PLAYER_STAT", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_CANNOT_PENETRATE_WATER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CANNOT_PENETRATE_WATER_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_DESPAWN_STRINGID", { FieldUnit, FieldStringId, FieldExtra0 } },
    { "AI_GROUP_UNIT_SET_SAFE_LOCATION", { FieldStringId } },
    { "AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_DESPAWN_SUMMONED_AREA_TRIGGERS", { FieldUnit, FieldExtra0 } },
    { "AI_GROUP_UNIT_ADD_PERMANENT_WORLD_EFFECT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_REMOVE_PERMANENT_WORLD_EFFECT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CAST_WITH_POINTS_OTHER_UNIT", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_UNIT_SET_ANCHOR_POINT", { FieldUnit } },
    { "AI_GROUP_CIRCLE_UNIT", { FieldTimeA, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_RUN_SPELL_SCRIPT", { FieldPoint, FieldStringId, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_TURN_IN_PLACE_DEGREES", { FieldUnit, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_TURN_IN_PLACE_TIMED", { FieldUnit, FieldTimeA, FieldTimeB, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_PREFER_UNENGAGED_TARGETS", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_GENERATE_SPAWNGROUP_EVENT", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_PUSH_ACTIONSET", { FieldStringId, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_MOVE_ON_PATH_GRAPH_TO_POINT", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_TRIGGER_ACTIONS_ON_SELF", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_EJECT_PASSENGER", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_PERFORM_ACTIONSET", { FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_UNIT_PAUSE_SPELL_COOLDOWNS", { FieldUnit } },
    { "AI_GROUP_UNIT_RESUME_SPELL_COOLDOWNS", { FieldUnit } },
    { "AI_GROUP_UNIT_TRIGGER_SPELL_CATEGORY_COOLDOWN", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "AI_GROUP_UNIT_PLAY_SOUND_ON_ITSELF_SPEAKERBOT", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "AI_GROUP_UNIT_STOP_SPEAKERBOT_SOUND", { FieldUnit, FieldExtra0 } },
    { "AI_GROUP_UNIT_BECOME_PERSONAL_INVIS_CLONE", { FieldUnit } },
    { "AI_GROUP_MOVE_ON_PATH_GRAPH_TO_GUID", { FieldTimeA, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_MOVE_ON_PATH_GRAPH_MULTIPLE_POINTS", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "AI_GROUP_UNIT_NEVER_EVADE", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_NEVER_EVADE_RESET", { FieldUnit } },
    { "AI_GROUP_UNIT_DONT_LEAVE_COMBAT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_CANCEL_CURRENT_SPELL", { FieldUnit } },
    { "AI_GROUP_UNIT_SAY_GAME_REGION", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_SAY_GAME_REGION_RANDOM", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_YELL_GAME_REGION", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_YELL_GAME_REGION_RANDOM", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_COMBAT_POSITION", { FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra4 } },
    { "AI_GROUP_COMBAT_CHASE", { FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2 } },
    { "AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT", { FieldUnit, FieldExtra2 } },
    { "AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT_RES", { FieldUnit } },
};

AIGroupMgr::ActionTriggerTypeInfo const AIGroupMgr::StaticActionTriggerTypeData[ActionTriggers::Max] =
{
    { "None",                       false, false },
    { "OnReaction",                 true,  false },
    { "OnEnterCombat",              false, false },
    { "OnLeaveCombat",              false, false },
    { "OnCombatTick",               false, false },
    { "OnHealthRange",              true,  true  },
    { "OnEnergyRange",              true,  true  },
    { "OnDeath",                    false, false },
    { "OnSpell",                    true,  false },
    { "OnKill",                     false, false },
    { "OnSpawn",                    false, false },
    { "OnEmote",                    true,  false },
    { "OnMelee",                    false, false },
    { "OnInteract",                 false, false },
    { "OnCombatTrigger",            true,  false },
    { "OnSpellCast",                true,  false },
    { "OnPickPocket",               false, false },
    { "OnSkinned",                  false, false },
    { "OnCombatReturn",             false, false },
    { "OnPathFailing",              true,  false },
    { "OnHealthRangeRandom",        true,  true  },
    { "OnEnergyRangeRandom",        true,  true  },
    { "OnGeneralTrigger",           true,  false },
    { "OnDespawn",                  false, false },
    { "OnSpellFailed",              true,  false },
    { "OnCharmBreak",               false, false },
    { "OnPassengerControlEnd",      true,  false },
    { "OnVehicleReturn",            true,  false },
    { "OnVehicleRide",              true,  false },
    { "OnVehicleAbandon",           true,  false },
    { "OnSpellStart",               true,  false },
    { "OnAuraApplied",              true,  false },
    { "OnAuraRemoved",              true,  false },
    { "OnPassengerRide",            true,  false },
    { "OnPassengerAbandon",         true,  false },
    { "OnPassengerSpawn",           true,  false },
    { "OnLootLockReleased",         true,  false },
    { "OnChannelStart",             true,  false },
    { "OnChannelInterrupted",       true,  false },
    { "OnChannelFinished",          true,  false },
    { "OnHealthDepleted",           false, false }
};

std::string AIGroupMgr::GetActionSetName(uint32 actionSetId) const
{
    auto itr = _actionSets.find(actionSetId);
    return itr != _actionSets.end() ? itr->second.Name : std::string();
}

uint32 AIGroupMgr::GetActionSetFlags(uint32 actionSetId) const
{
    auto itr = _actionSets.find(actionSetId);
    return itr != _actionSets.end() ? itr->second.Flags : 0;
}

uint8 AIGroupMgr::GetActionSetPriority(uint32 actionSetId) const
{
    auto itr = _actionSets.find(actionSetId);
    return itr != _actionSets.end() ? itr->second.Priority : uint8(ActionSetPriorityType::Any);
}

std::string AIGroupMgr::GetTriggersName(uint32 triggersId) const
{
    auto itr = _actionTriggerNames.find(triggersId);
    return itr != _actionTriggerNames.end() ? itr->second : std::string();
}

AIGroupEventList AIGroupMgr::GetScript(uint32 triggersId)
{
    auto itr = mEventMap.find(triggersId);
    if (itr != mEventMap.end())
        return itr->second;

    return AIGroupEventList();
}

AIGroupActionSet AIGroupMgr::GetActionSet(uint32 actionSetId)
{
    auto itr = mActionSetMap.find(actionSetId);
    if (itr != mActionSetMap.end())
        return itr->second;

    return AIGroupActionSet();
}

AIGroupRandomActionSet AIGroupMgr::GetRandomActionSet(uint32 randomActionSetId)
{
    auto itr = mRandomActionSetMap.find(randomActionSetId);
    if (itr != mRandomActionSetMap.end())
        return itr->second;

    return AIGroupRandomActionSet();
}

uint8 AIGroupMgr::GetPriorityPercentForPriorityType(ActionSetPriorityType type)
{
    switch (type)
    {
        case ActionSetPriorityType::Any:
            return 0;
        case ActionSetPriorityType::Low:
            return 20;
        case ActionSetPriorityType::LowToMid:
            return 49;
        case ActionSetPriorityType::MidToHigh:
            return 79;
        case ActionSetPriorityType::High:
            return 80;
        case ActionSetPriorityType::Medium:
            return 50;
        default:
            return 0;
    }
}
