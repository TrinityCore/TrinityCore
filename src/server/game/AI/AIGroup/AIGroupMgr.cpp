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
            case OnGeneralTrigger:
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

    if (!IsEmoteValid(action))
        return false;

    if (!IsSoundValid(action))
        return false;

    if (!IsQuestValid(action))
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

AIGroupMgr::ActionSetTypeInfo const AIGroupMgr::StaticActionSetTypeData[AI_GROUP_MAX] =
{
    { "Spawn", { FieldTimeA, FieldExtra2 } },
    { "Idle", { FieldTimeA, FieldTimeB } },
    { "Move within distance of a point", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "Teleport to a point in the world", { FieldPoint, FieldStringId, FieldExtra0 } },
    { "Wander", { FieldPoint, FieldTimeA, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2 } },
    { "Attack all players within a given radius", { FieldExtra0 } },
    { "Wander a convex poly area (not yet implemented)", {  } },
    { "Follow a unit", { FieldTimeA, FieldStringId, FieldExtra0, FieldExtra1 } },
    { "Follow a path", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldExtra3 } },
    { "Patrol back and forth along a path", { FieldPath, FieldTimeA, FieldMoveSpeed, FieldLinearPath, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Patrol in a circular path", { FieldPath, FieldTimeA, FieldMoveSpeed, FieldCircularPath, FieldExtra3 } },
    { "Guard a unit", { FieldTimeA, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "Guard an area (not yet implemented)", {  } },
    { "Set a specific formation and spread", { FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra4 } },
    { "Change mode on unit(s) in the group (obsolete)", {  } },
    { "Unit(s) say something", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "Unit(s) cast a spell", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Unit(s) activate a game object", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "Generate an event", { FieldExtra2 } },
    { "Despawn", {  } },
    { "Unit(s) start a conversation (public unless target is a player)", { FieldUnit, FieldExtra2 } },
    { "Unit(s) cancel a conversation (public unless target is a player)", { FieldUnit, FieldExtra2 } },
    { "Unit(s) face a particular angle", { FieldUnit, FieldExtra2 } },
    { "Unit(s) face a unit or game object or point", { FieldUnit, FieldStringId, FieldExtra0 } },
    { "Emote State - Set and Forget (formerly perform an emote)", { FieldUnit, FieldExtra2 } },
    { "Move within distance of a unit or game object", { FieldTimeA, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "Attack unit", { FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Unit(s) mount a creature", { FieldUnit, FieldExtra2 } },
    { "Unit(s) dismount", { FieldUnit } },
    { "Set \"Uninteractible\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"Uninteractible\" flag for unit(s)", { FieldUnit } },
    { "Change mode for unit(s)", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Reset mode for unit(s)", { FieldUnit } },
    { "Change faction template for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset faction template for unit(s)", { FieldUnit } },
    { "Change radius record for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset radius record for unit(s)", { FieldUnit } },
    { "Escort quest actions completed", {  } },
    { "Unit(s) become a quest giver", { FieldUnit, FieldExtra2 } },
    { "Unit(s) become a trainer", { FieldUnit, FieldExtra2 } },
    { "Follow a short path exactly (no pathing)", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldExtra3 } },
    { "Player performs an action (Programmer -Internal Use Only)", { FieldExtra2 } },
    { "Move everybody back to spawn positions", { FieldTimeA, FieldMoveSpeed } },
    { "Unit(s) say something random", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "Unit(s) yell something", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "Unit(s) yell something random", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "Set the item in the mainhand slot for unit(s)", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "Reset the item in the mainhand slot for unit(s)", { FieldUnit } },
    { "Unit(s) chat emote something", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Unit(s) chat emote something random", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Unit(s) in the group generates an event", { FieldUnit, FieldExtra2 } },
    { "Vendor wander + face + idle action sequence (obsolete)", {  } },
    { "Escort quest actions failed", {  } },
    { "Change action triggers for unit(s)", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Reset action triggers for unit(s)", { FieldUnit } },
    { "Leave combat (combat action only)", { FieldExtra2 } },
    { "Idle until group goes into combat", { FieldTimeA, FieldTimeB } },
    { "Idle until group returns from combat", { FieldTimeA, FieldTimeB } },
    { "Set \"ImmunePC\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"ImmunePC\" flag for unit(s)", { FieldUnit } },
    { "Set \"ImmuneNPC\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"ImmuneNPC\" flag for unit(s)", { FieldUnit } },
    { "Set \"Unkillable\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"Unkillable\" flag for unit(s)", { FieldUnit } },
    { "Set the spells record for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset the spells record for unit(s)", { FieldUnit } },
    { "Attack everybody in the instance", {  } },
    { "Unit(s) send a local event", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Unit(s) broadcast a local event", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "Flee combat (combat action only)", { FieldTimeA } },
    { "Retreat (combat action only)", { FieldTimeA } },
    { "Object(s) chat emote something", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Object(s) chat emote something random", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Move outside a certain distance of a point", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "Move outside a certain distance of a unit or game object", { FieldTimeA, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "Activate object(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Unit(s) activate nearby game objects", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Set the string ID for unit(s)", { FieldUnit, FieldStringId, FieldExtra2 } },
    { "Reset the string ID for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Set a periodic event for the group", { FieldTimeA, FieldExtra2 } },
    { "Set the item in the offhand slot for unit(s)", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "Reset the item in the offhand slot for unit(s)", { FieldUnit } },
    { "Set the item in the ranged slot for unit(s)", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "Reset the item in the ranged slot for unit(s)", { FieldUnit } },
    { "Unit(s) sheathe their weapons", { FieldUnit } },
    { "Unit(s) unsheathe their melee weapons", { FieldUnit } },
    { "Unit(s) cancel casting a spell", { FieldUnit, FieldExtra2 } },
    { "Unit(s) cancel an aura on themselves", { FieldUnit, FieldExtra2 } },
    { "Unit(s) wait until they finish casting", { FieldUnit, FieldTimeA, FieldTimeB } },
    { "Emote State with Idle (formerly continually emote)", { FieldTimeA, FieldTimeB, FieldExtra2 } },
    { "Call for help (combat action only)", { FieldStringId, FieldExtra0 } },
    { "Follow a flight spline path exactly", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldFlightPath, FieldExtra3 } },
    { "Trigger actions on units in combat", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Unit(s) become a gossip", { FieldUnit, FieldExtra2 } },
    { "Unit(s) assign kill credit", { FieldUnit, FieldExtra2 } },
    { "Unit(s) whisper to a player", { FieldUnit, FieldExtra2 } },
    { "Unit(s) whisper to a player something random", { FieldUnit, FieldExtra2 } },
    { "Set \"No Loot\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"No Loot\" flag for unit(s) in the group", { FieldUnit } },
    { "Set \"No XP\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"No XP\" flag for unit(s) in the group", { FieldUnit } },
    { "Set \"PVP\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"PVP\" flag for unit(s) in the group", { FieldUnit } },
    { "Unit(s) play music", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Unit(s) play a sound", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Set the loot for a unit", { FieldUnit, FieldExtra2 } },
    { "Set \"Floating\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"Floating\" flag for unit(s) in the group", { FieldUnit } },
    { "Object(s) play music", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Object(s) play a sound", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Spawn (forced)", { FieldTimeA, FieldExtra2 } },
    { "Unit(s) unsheathe their range weapons", { FieldUnit } },
    { "Unit(s) chat emote something to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) chat emote something random to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) yell something to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) yell something random to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) play music to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) play a sound to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Object(s) chat emote something to the zone", { FieldUnit, FieldExtra2 } },
    { "Object(s) chat emote something random to the zone", { FieldUnit, FieldExtra2 } },
    { "Object(s) play music to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Object(s) play a sound to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Set \"Ignore combat\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"Ignore combat\" flag for unit(s)", { FieldUnit } },
    { "Perform a random set of actions", { FieldExtra2 } },
    { "Restart the current actions if world state expression is true", { FieldExtra2 } },
    { "Abort action set if world state expression is true", { FieldExtra2 } },
    { "Unit(s) boss emote something", { FieldUnit, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "Unit(s) boss emote something to the zone", { FieldUnit, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Trigger actions on nearest unit in combat", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Unit(s) cast a spell and report failure to owner", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Set \"No Reputation\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"No Reputation\" flag for unit(s) in the group", { FieldUnit } },
    { "Follow a flight spline path exactly, and loop forever", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldFlightPath, FieldExtra3 } },
    { "Unit(s) become a vendor", { FieldUnit, FieldExtra2 } },
    { "Reset vendor lists for unit(s) in the group", { FieldUnit } },
    { "Trigger actions on units", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Trigger actions on nearest unit", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Unit(s) say something to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) say something random to the zone", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) send a local event to self (if outside of combat)", { FieldUnit, FieldExtra2 } },
    { "Set \"Sessile\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"Sessile\" flag for unit(s)", { FieldUnit } },
    { "Set \"RAID_LOCK_ON_DEATH\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"RAID_LOCK_ON_DEATH\" flag for unit(s)", { FieldUnit } },
    { "Quest complete for triggering player", { FieldExtra2 } },
    { "Quest cleared for triggering player", { FieldExtra2 } },
    { "Unit(s) chat to a player's party", { FieldUnit, FieldExtra2 } },
    { "Unit(s) clear cooldowns", { FieldUnit } },
    { "Unit(s) play a targeted sound", { FieldUnit, FieldExtra2 } },
    { "Unit(s) play targeted music", { FieldUnit, FieldExtra2 } },
    { "Unit(s) reset initial spell cooldowns", { FieldUnit } },
    { "Set \"No Melee\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"No Melee\" flag for unit(s) in the group", { FieldUnit } },
    { "Fall to the ground", {  } },
    { "Unit(s) update interaction", { FieldUnit } },
    { "Unit(s) boss whispers someone", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "Unit(s) boss whispers someone randomly", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "Move relative to current facing", { FieldTimeA, FieldMoveSpeed, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Unit(s) don't clear tap when leaving combat", { FieldUnit } },
    { "Unit(s) assign kill credit to tap list", { FieldUnit, FieldExtra2 } },
    { "Unit(s) cast a spell with points", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "Unit(s) ride a vehicle", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "Unit(s) abandon their vehicles", { FieldUnit } },
    { "Vehicle(s) recall or respawn each passenger", { FieldUnit, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "Target player plays a movie file", { FieldUnit, FieldExtra2 } },
    { "Jump to a point", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "Jump to an object or unit", { FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "Move to a point, then jump to end of path", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "Vehicle(s) recall each living passenger", { FieldUnit, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra3 } },
    { "Vehicle(s) respawn all passengers", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra3 } },
    { "Unit(s) Set fatal fall distance", { FieldUnit, FieldExtra1 } },
    { "Unit(s) Reset fatal fall distance", { FieldUnit } },
    { "Unit(s) Set Animation/Movement Tier", { FieldUnit, FieldExtra2 } },
    { "Unit(s) send their tap list to another unit", { FieldUnit, FieldStringId, FieldExtra0 } },
    { "Unit(s) get their tap list from another unit", { FieldUnit, FieldStringId, FieldExtra0 } },
    { "Unit(s) set their hover height", { FieldUnit, FieldExtra1 } },
    { "Unit(s) Reset their hover height", { FieldUnit } },
    { "Tier Transition Land", { FieldMoveSpeed, FieldExtra2, FieldExtra3 } },
    { "Tier Transition Take off", { FieldMoveSpeed, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "Tier Transition Move To", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldFlightPath, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "Tier Transition Move To a Unit or Game Object", { FieldMoveSpeed, FieldStringId, FieldFlightPath, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3 } },
    { "Tier Transition Follow Path", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldFlightPath, FieldExtra2, FieldExtra3 } },
    { "Unit(s) assign kill credit to player", { FieldUnit, FieldExtra2 } },
    { "Suspend Trigger action (creature action only)", { FieldTimeA, FieldTimeB } },
    { "Unit(s) change their vehicle record ID", { FieldUnit, FieldExtra2 } },
    { "Unit(s) reset their vehicle record ID", { FieldUnit } },
    { "Unit(s) change their creature immunity template ID", { FieldUnit, FieldExtra2 } },
    { "Unit(s) reset their creature immunity template ID", { FieldUnit } },
    { "Send a content alert", { FieldUnit } },
    { "Unit(s) says something only to a player", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) yells something only to a player", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Unit(s) starts a quest", { FieldUnit, FieldExtra2 } },
    { "Unit(s) says something random only to a player", { FieldUnit, FieldExtra2 } },
    { "Unit(s) yells something random only to a player", { FieldUnit, FieldExtra2 } },
    { "Unit(s) start a looping anim kit", { FieldUnit, FieldExtra2 } },
    { "Unit(s) stop their looping anim kit", { FieldUnit } },
    { "Unit(s) play a one-shot anim kit", { FieldUnit, FieldExtra2 } },
    { "Unit(s) set their movement anim kit", { FieldUnit, FieldExtra2 } },
    { "Unit(s) set their melee anim kit", { FieldUnit, FieldExtra2 } },
    { "Set InteractSpell for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset InteractSpell for unit(s) in the group", { FieldUnit } },
    { "Set InteractSpellCondition for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset InteractSpellCondition for unit(s) in the group", { FieldUnit } },
    { "Set \"No NPC damage below 85%\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"No NPC damage below 85%\" flag for unit(s)", { FieldUnit } },
    { "Unit(s) face angle relative to current", { FieldUnit, FieldExtra2 } },
    { "Unit(s) sets his boss unit frames priority", { FieldUnit, FieldExtra2 } },
    { "Unit(s) resets his boss unit frames priority", { FieldUnit } },
    { "Set \"No Threat Feedback\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"No Threat Feedback\" flag for unit(s)", { FieldUnit } },
    { "Unit(s) chat emote something to a player", { FieldUnit, FieldExtra2 } },
    { "Unit(s) chat emote something random to a player", { FieldUnit, FieldExtra2 } },
    { "Unit(s) perform an emote to a player", { FieldUnit, FieldExtra2 } },
    { "Set the quest loot for a unit", { FieldUnit, FieldExtra2 } },
    { "Unit(s) cast a spell on a random unit", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Unit(s) cast a spell on a random player", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Unit(s) tell some other unit to cast a spell", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra4 } },
    { "Move in a circle relative to position", { FieldTimeA, FieldMoveSpeed, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Move everybody back to spawn positions instantly", {  } },
    { "Abort action set if stringID is not found", { FieldStringId, FieldExtra0 } },
    { "Abort action set if combat condition is true", { FieldExtra2 } },
    { "Force combat with a unit", { FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Stop Force combat", {  } },
    { "Unit(s) Set Untargetable By Client", { FieldUnit, FieldExtra2 } },
    { "Unit(s) Reset Untargetable By Client", { FieldUnit } },
    { "Set \"No Melee Approach\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"No Melee Approach\" flag for unit(s) in the group", { FieldUnit } },
    { "Unit(s) Raid Lock everyone on their tap list", { FieldUnit, FieldExtra2 } },
    { "Set \"Cannot Turn\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"Cannot Turn\" flag for unit(s) in the group", { FieldUnit } },
    { "Set \"Prefer NPCs When Searching For Enemies\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"Prefer NPCs When Searching For Enemies\" flag for unit(s) in the group", { FieldUnit } },
    { "Change faction template for object(s)", { FieldUnit, FieldExtra2 } },
    { "Reset faction template for object(s)", { FieldUnit } },
    { "Unit(s) perform spell visual kit on self", { FieldUnit, FieldTimeA, FieldTimeB, FieldExtra0, FieldExtra2 } },
    { "Unit(s) perform spell visual", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3 } },
    { "Unit(s) perform spell visual and trigger actions", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Unit(s) Set \"No LeaveCombat State Restore\" flag", { FieldUnit, FieldExtra2 } },
    { "Set the string ID for object(s)", { FieldUnit, FieldStringId, FieldExtra2 } },
    { "Reset the string ID for object(s)", { FieldUnit, FieldExtra2 } },
    { "Unit(s) despawn persistent area aura objects", { FieldUnit, FieldExtra0 } },
    { "Unit(s) set the default mount", { FieldUnit, FieldExtra2 } },
    { "Unit(s) reset the default mount", { FieldUnit } },
    { "Abort action set if stringID is found", { FieldStringId, FieldExtra0 } },
    { "NPC Greetings - Un-Suppress them", {  } },
    { "NPC Greetings - Suppress Them", {  } },
    { "Unit(s) clears boss emotes", { FieldUnit, FieldExtra0 } },
    { "Unit(s) clears boss emotes for the zone", { FieldUnit, FieldExtra4 } },
    { "Unit(s) clears boss emotes for a player", { FieldUnit } },
    { "Unit(s) Set Interact While Hostile", { FieldUnit, FieldExtra2 } },
    { "Unit(s) Reset Interact While Hostile", { FieldUnit } },
    { "Unit(s) set the model highlight suppression", { FieldUnit, FieldExtra2 } },
    { "Unit(s) reset the model highlight suppression", { FieldUnit } },
    { "Follow a taxi path", { FieldMoveSpeed, FieldLinearPath, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Follow a taxi path relative", { FieldMoveSpeed, FieldLinearPath, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Start a Dungeon Encounter", { FieldExtra2 } },
    { "End a Dungeon Encounter", { FieldExtra2, FieldExtra4 } },
    { "Unit(s) set Wild BattlePet Level", { FieldUnit, FieldExtra2 } },
    { "Unit(s) reset Wild BattlePet Level", { FieldUnit } },
    { "Unit(s) track player stat", { FieldUnit, FieldExtra2, FieldExtra4 } },
    { "Set \"Cannot Penetrate Water\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Reset \"Cannot Penetrate Water\" flag for unit(s) in the group", { FieldUnit } },
    { "Unit(s) Despawn units/objects matching string ID", { FieldUnit, FieldStringId, FieldExtra0 } },
    { "Unit(s) Set Safe Location", { FieldStringId } },
    { "Set \"Treat Unit As Raid Unit\" flag for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"Treat Unit As Raid Unit\" flag for unit(s)", { FieldUnit } },
    { "Unit(s) Despawn all summoned area triggers", { FieldUnit, FieldExtra0 } },
    { "Add permanent World Effect to unit(s)", { FieldUnit, FieldExtra2 } },
    { "Remove permanent World Effect from unit(s)", { FieldUnit, FieldExtra2 } },
    { "Unit(s) tell some other unit to cast a spell with points", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Unit(s) Set Anchor Point", { FieldUnit } },
    { "Circle a Unit", { FieldTimeA, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Run a spell script", { FieldPoint, FieldStringId, FieldExtra2, FieldExtra3 } },
    { "Turn in Place(Degrees)", { FieldUnit, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Turn in Place(Timed)", { FieldUnit, FieldTimeA, FieldTimeB, FieldExtra2, FieldExtra3 } },
    { "Set \"Prefer Unengaged Targets\" flag for unit(s) in the group", { FieldUnit, FieldExtra2 } },
    { "Unit(s) in the group generates a spawngroup event", { FieldUnit, FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Push Actionset", { FieldStringId, FieldExtra0, FieldExtra2 } },
    { "Move on path graph to point", { FieldPoint, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Trigger actions on self", { FieldUnit, FieldExtra2 } },
    { "Unit(s) eject passenger", { FieldUnit, FieldExtra2 } },
    { "Perform actionset", { FieldExtra2, FieldExtra4 } },
    { "Unit(s) Pause Spell Cooldowns", { FieldUnit } },
    { "Unit(s) Resume Spell Cooldowns", { FieldUnit } },
    { "Unit(s) Trigger a Spell Category Cooldown", { FieldUnit, FieldExtra2, FieldExtra3 } },
    { "Unit(s) Plays a sound on itself [Speakerbot]", { FieldUnit, FieldExtra0, FieldExtra2 } },
    { "Unit(s) Stops the [Speakerbot] sound it is playing", { FieldUnit, FieldExtra0 } },
    { "Unit(s) Becomes a personal invis clone for triggering player", { FieldUnit } },
    { "Move on path graph to unit or game object", { FieldTimeA, FieldMoveSpeed, FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Move on path graph - multiple points", { FieldPath, FieldMoveSpeed, FieldLinearPath, FieldExtra2, FieldExtra3, FieldExtra4 } },
    { "Unit(s) \"Never Evade\" flag", { FieldUnit, FieldExtra2 } },
    { "Reset Unit(s) \"Never Evade\" flag", { FieldUnit } },
    { "Unit(s) Set \"Don't leave combat\" flag", { FieldUnit, FieldExtra2 } },
    { "Unit(s) Cancel Current Spell", { FieldUnit } },
    { "Unit(s) say something to the entire game region", { FieldUnit, FieldExtra2 } },
    { "Unit(s) say something random to the entire game region", { FieldUnit, FieldExtra2 } },
    { "Unit(s) yell something to the entire game region", { FieldUnit, FieldExtra2 } },
    { "Unit(s) yell something random to the entire game region", { FieldUnit, FieldExtra2 } },
    { "Combat Position", { FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2, FieldExtra4 } },
    { "Combat Chase", { FieldStringId, FieldExtra0, FieldExtra1, FieldExtra2 } },
    { "Set \"Don't Dismiss On Flying Mount\" for unit(s)", { FieldUnit, FieldExtra2 } },
    { "Reset \"Don't Dismiss On Flying Mount\" for unit(s)", { FieldUnit } },
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
