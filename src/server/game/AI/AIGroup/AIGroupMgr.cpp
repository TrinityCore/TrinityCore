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

        if (triggers.TriggerId >= UnitActionTriggers::Max)
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
    if (action.Type >= AI_GROUP_MAX)
    {
        TC_LOG_ERROR("sql.sql", "Table `action_set` (Id: {}, Index: {}) has invalid action type {}, skipped.",
            action.Id, action.Index, action.Type);
        return false;
    }

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

    return true;
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

AIGroupMgr::ActionTriggerTypeInfo const AIGroupMgr::StaticActionTriggerTypeData[UnitActionTriggers::Max] =
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
