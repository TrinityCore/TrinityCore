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

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Opcodes.h"
#include "World.h"
#include "Player.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "Language.h"
#include "AccountMgr.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "GuildMgr.h"
#include "SystemConfig.h"
#include "Config/Config.h"
#include "revision.h"
#include "Util.h"
#include "Weather.h"
#include "Anticheat.h"
#include "GameEventMgr.h"
#include "BattleGroundMgr.h"
#include "CreatureEventAIMgr.h"
#include "CharacterDatabaseCache.h"
#include "AuraRemovalMgr.h"
#include "AutoBroadCastMgr.h"
#include "SpellModMgr.h"
#include "CreatureGroups.h"

bool ChatHandler::HandleAnnounceCommand(char* args)
{
    if (!*args)
        return false;

    sWorld.SendWorldText(LANG_SYSTEMMESSAGE, args);
    return true;
}

bool ChatHandler::HandleNotifyCommand(char* args)
{
    if (!*args)
        return false;

    std::string str = GetMangosString(LANG_GLOBAL_NOTIFY);
    str += args;

    WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
    data << str;
    sWorld.SendGlobalMessage(&data);

    return true;
}

bool ChatHandler::HandleVariableCommand(char *args)
{
    uint32 index = 0;
    uint32 value = 0;
    sscanf(args, "%u %u", &index, &value);
    if (!index)
        return false;

    if (value)
    {
        uint32 oldValue = sObjectMgr.GetSavedVariable(index, 666);
        sObjectMgr.SetSavedVariable(index, value, true);
        if (oldValue == 666) // La valeur par default
            PSendSysMessage("New variable %u set to %u", index, value);
        else
            PSendSysMessage("Variable %u changed from %u to %u", index, oldValue, value);
    }
    else
    {
        value = sObjectMgr.GetSavedVariable(index, 666);
        if (value == 666)
            PSendSysMessage("Not found variable %u", index);
        else
            PSendSysMessage("Variable %u value is %u", index, value);
    }
    return true;
}

bool ChatHandler::HandleChangeWeatherCommand(char* args)
{
    // Weather is OFF
    if (!sWorld.getConfig(CONFIG_BOOL_WEATHER))
    {
        SendSysMessage(LANG_WEATHER_DISABLED);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 type;
    if (!ExtractUInt32(&args, type))
        return false;

    // see enum WeatherType
    if (!Weather::IsValidWeatherType(type))
        return false;

    float grade;
    if (!ExtractFloat(&args, grade))
        return false;

    // clamp grade from 0 to 1
    if (grade < 0.0f)
        grade = 0.0f;
    else if (grade > 1.0f)
        grade = 1.0f;

    Player* player = m_session->GetPlayer();
    uint32 zoneId = player->GetZoneId();
    player->GetMap()->SetWeather(zoneId, (WeatherType)type, grade, false);
    return true;
}

 //Save all players in the world
bool ChatHandler::HandleSaveAllCommand(char* /*args*/)
{
    sObjectAccessor.SaveAllPlayers();
    SendSysMessage(LANG_PLAYERS_SAVED);
    return true;
}

bool ChatHandler::HandleAntiSpamAdd(char* args)
{
    if (!*args || !sAnticheatMgr->GetAntispam())
        return false;

    char* wordStr = ExtractQuotedArg(&args);
    if (!wordStr)
    {
        PSendSysMessage("[AntiSpam]: No word given.");
        return false;
    }
    std::string word = wordStr;

    uint32 ban = 0;
    if (!ExtractUInt32(&args, ban))
    {
        PSendSysMessage("[AntiSpam]: No ban value given.");
        return false;
    }

    LoginDatabase.PExecute("INSERT INTO `antispam_blacklist` (`word`, `ban`) VALUES('%s', %u);", word.c_str(), ban);
    PSendSysMessage("[AntiSpam]: Word %s with ban value %u added to antispam_blacklist table.", word.c_str(), ban);

    return true;
}

bool ChatHandler::HandleAntiSpamRemove(char* args)
{
    if (!*args || !sAnticheatMgr->GetAntispam())
        return false;

    char* wordStr = ExtractQuotedArg(&args);
    if (!wordStr)
    {
        PSendSysMessage("[AntiSpam]: No word given.");
        return false;
    }
    std::string word = wordStr;

    LoginDatabase.PExecute("DELETE FROM `antispam_blacklist` WHERE `word`='%s';", word.c_str());

    PSendSysMessage("[AntiSpam]: Word %s has been removed from antispam_blacklist table.", word.c_str());

    return true;
}

bool ChatHandler::HandleAntiSpamReplace(char* args)
{
    if (!*args || !sAnticheatMgr->GetAntispam())
        return false;

    char* fromStr = ExtractQuotedArg(&args);
    if (!fromStr)
    {
        PSendSysMessage("[AntiSpam]: No from given.");
        return false;
    }

    std::string from = fromStr;

    char* toStr = ExtractQuotedArg(&args);
    if (!toStr)
    {
        PSendSysMessage("[AntiSpam]: No to given.");
        return false;
    }

    std::string to = toStr;

    LoginDatabase.PExecute("INSERT INTO `antispam_replacement` (`from`, `to`) VALUES('%s', '%s');", from.c_str(), to.c_str());
    PSendSysMessage("[AntiSpam]: Added replace letter %s to %s added to antispam_replacement table.", from.c_str(), to.c_str());

    return true;
}

bool ChatHandler::HandleAntiSpamRemoveReplace(char* args)
{
    if (!*args || !sAnticheatMgr->GetAntispam())
        return false;

    char* fromStr = ExtractQuotedArg(&args);
    if (!fromStr)
    {
        PSendSysMessage("[AntiSpam]: No from given.");
        return false;
    }

    std::string from = fromStr;

    LoginDatabase.PExecute("DELETE FROM `antispam_replacement` WHERE `from`='%s';", from.c_str());
    PSendSysMessage("[AntiSpam]: From word %s is removed from antispam_replacement table.", from.c_str());

    return true;
}

bool ChatHandler::HandleUpdateWorldStateCommand(char *args)
{
    uint32 value = 0;
    uint32 index = 0;
    sscanf(args, "%u %u", &index, &value);
    if (index == 0)
    {
        SendSysMessage("Usage :");
        SendSysMessage(".ws update index [value=0]");
        SetSentErrorMessage(true);
        return false;
    }
    m_session->GetPlayer()->SendUpdateWorldState(index, value);
    PSendSysMessage("WorldState %u is %u for player.", index, value);
    return true;
}

bool ChatHandler::HandleWorldUpdateCommand(char *args)
{
    bool modify = true;
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }
    if (!args)
    {
        // Show the World
        modify = false;
    }

    char* newWorldStr = strtok((char*)args, " ");

    if (!newWorldStr)
        modify = false;

    if (!modify)
    {
        PSendSysMessage("Target worldmask (GUID=%u) is 0x%x (%u)", target->GetGUIDLow(), target->GetWorldMask(), target->GetWorldMask());
        return true;
    }
    uint32 newWorld = (uint32)atoi(newWorldStr);
    target->SetWorldMask(newWorld);
    PSendSysMessage("New worldMask=0x%x (%u) for selection (GUID=%u)", newWorld, newWorld, target->GetGUIDLow());
    return true;
}

bool ChatHandler::HandleWorldTestCommand(char *args)
{
    Unit* target = GetSelectedUnit();
    Player* me = m_session->GetPlayer();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }
    PSendSysMessage("My worldmask is 0x%x. My target worldmask is 0x%x.", me->GetWorldMask(), target->GetWorldMask());
    PSendSysMessage("I see the target ? %s", me->CanSeeInWorld(target) ? "oui" : "non");
    PSendSysMessage("My target sees me ? %s", target->CanSeeInWorld(me) ? "oui" : "non");
    return true;
}

bool ChatHandler::HandleWorldDetailCommand(char *args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }
    uint32 mask = target->GetWorldMask();
    PSendSysMessage("WorldMask = 0x%x (%u)", mask, mask);
    for (uint32 i = 1; i <= mask; i = i * 2)
    {
        if (mask & i)
            PSendSysMessage("-> World 0x%x", i);
    }
    return true;
}

bool ChatHandler::HandleServerInfoCommand(char* /*args*/)
{
    uint32 activeClientsNum = sWorld.GetActiveSessionCount();
    uint32 queuedClientsNum = sWorld.GetQueuedSessionCount();
    uint32 maxActiveClientsNum = sWorld.GetMaxActiveSessionCount();
    uint32 maxQueuedClientsNum = sWorld.GetMaxQueuedSessionCount();
    std::string str = secsToTimeString(sWorld.GetUptime());

    SendSysMessage("Core revision: " _FULLVERSION);
    PSendSysMessage("Players online: %i (%i queued). Max online: %i (%i queued).", activeClientsNum, queuedClientsNum, maxActiveClientsNum, maxQueuedClientsNum);
    PSendSysMessage(LANG_UPTIME, str.c_str());

    return true;
}

// Display the 'Message of the day' for the realm
bool ChatHandler::HandleServerMotdCommand(char* /*args*/)
{
    PSendSysMessage(LANG_MOTD_CURRENT, sWorld.GetMotd());
    return true;
}

// Define the 'Message of the day' for the realm
bool ChatHandler::HandleServerSetMotdCommand(char* args)
{
    sWorld.SetMotd(args);
    PSendSysMessage(LANG_MOTD_NEW, args);
    return true;
}

bool ChatHandler::HandleServerPLimitCommand(char *args)
{
    if (*args)
    {
        char* param = ExtractLiteralArg(&args);
        if (!param)
            return false;

        int l = strlen(param);

        int val;
        if (strncmp(param, "player", l) == 0)
            sWorld.SetPlayerLimit(-SEC_PLAYER);
        else if (strncmp(param, "moderator", l) == 0)
            sWorld.SetPlayerLimit(-SEC_MODERATOR);
        else if (strncmp(param, "gamemaster", l) == 0)
            sWorld.SetPlayerLimit(-SEC_GAMEMASTER);
        else if (strncmp(param, "administrator", l) == 0)
            sWorld.SetPlayerLimit(-SEC_ADMINISTRATOR);
        else if (strncmp(param, "reset", l) == 0)
            sWorld.SetPlayerLimit(sConfig.GetIntDefault("PlayerLimit", DEFAULT_PLAYER_LIMIT));
        else if (ExtractInt32(&param, val))
        {
            if (val < -SEC_ADMINISTRATOR)
                val = -SEC_ADMINISTRATOR;

            sWorld.SetPlayerLimit(val);
        }
        else
            return false;

        // kick all low security level players
        if (sWorld.GetPlayerAmountLimit() > SEC_PLAYER)
            sWorld.KickAllLess(sWorld.GetPlayerSecurityLimit());
    }

    uint32 pLimit = sWorld.GetPlayerAmountLimit();
    AccountTypes allowedAccountType = sWorld.GetPlayerSecurityLimit();
    char const* secName = "";
    switch (allowedAccountType)
    {
        case SEC_PLAYER:
            secName = "Player";
            break;
        case SEC_MODERATOR:
            secName = "Moderator";
            break;
        case SEC_GAMEMASTER:
            secName = "Gamemaster";
            break;
        case SEC_ADMINISTRATOR:
            secName = "Administrator";
            break;
        default:
            secName = "<unknown>";
            break;
    }

    PSendSysMessage("Player limits: amount %u, min. security level %s.", pLimit, secName);

    return true;
}

/// Triggering corpses expire check in world
bool ChatHandler::HandleServerCorpsesCommand(char* /*args*/)
{
    sObjectAccessor.RemoveOldCorpses();
    return true;
}

bool ChatHandler::HandleServerResetAllRaidCommand(char* /*args*/)
{
    SendSysMessage("Global raid instances reset, all players in raid instances will be teleported to homebind!");
    sMapPersistentStateMgr.GetScheduler().ResetAllRaid();
    return true;
}

bool ChatHandler::HandleServerShutDownCancelCommand(char* /*args*/)
{
    sWorld.ShutdownCancel();
    return true;
}

bool ChatHandler::HandleServerShutDownCommand(char* args)
{
    uint32 delay;
    if (!ExtractUInt32(&args, delay))
        return false;

    uint32 exitcode;
    if (!ExtractOptUInt32(&args, exitcode, SHUTDOWN_EXIT_CODE))
        return false;

    // Exit code should be in range of 0-125, 126-255 is used
    // in many shells for their own return codes and code > 255
    // is not supported in many others
    if (exitcode > 125)
        return false;

    sWorld.ShutdownServ(delay, 0, exitcode);
    return true;
}

bool ChatHandler::HandleServerRestartCommand(char* args)
{
    uint32 delay;
    if (!ExtractUInt32(&args, delay))
        return false;

    uint32 exitcode;
    if (!ExtractOptUInt32(&args, exitcode, RESTART_EXIT_CODE))
        return false;

    // Exit code should be in range of 0-125, 126-255 is used
    // in many shells for their own return codes and code > 255
    // is not supported in many others
    if (exitcode > 125)
        return false;

    sWorld.ShutdownServ(delay, SHUTDOWN_MASK_RESTART, exitcode);
    return true;
}

bool ChatHandler::HandleServerIdleRestartCommand(char* args)
{
    uint32 delay;
    if (!ExtractUInt32(&args, delay))
        return false;

    uint32 exitcode;
    if (!ExtractOptUInt32(&args, exitcode, RESTART_EXIT_CODE))
        return false;

    // Exit code should be in range of 0-125, 126-255 is used
    // in many shells for their own return codes and code > 255
    // is not supported in many others
    if (exitcode > 125)
        return false;

    sWorld.ShutdownServ(delay, SHUTDOWN_MASK_RESTART | SHUTDOWN_MASK_IDLE, exitcode);
    return true;
}

bool ChatHandler::HandleServerIdleShutDownCommand(char* args)
{
    uint32 delay;
    if (!ExtractUInt32(&args, delay))
        return false;

    uint32 exitcode;
    if (!ExtractOptUInt32(&args, exitcode, SHUTDOWN_EXIT_CODE))
        return false;

    // Exit code should be in range of 0-125, 126-255 is used
    // in many shells for their own return codes and code > 255
    // is not supported in many others
    if (exitcode > 125)
        return false;

    sWorld.ShutdownServ(delay, SHUTDOWN_MASK_IDLE, exitcode);
    return true;
}

/// Close RA connection
bool ChatHandler::HandleQuitCommand(char* /*args*/)
{
    // processed in RASocket
    SendSysMessage(LANG_QUIT_WRONG_USE_ERROR);
    return true;
}

/// Exit the realm
bool ChatHandler::HandleServerExitCommand(char* /*args*/)
{
    SendSysMessage(LANG_COMMAND_EXIT);
    World::StopNow(SHUTDOWN_EXIT_CODE);
    return true;
}

bool ChatHandler::HandleViewLogCommand(char* args)
{
    uint32 logId;
    if (!ExtractUInt32(&args, logId))
        return false;
    World::ArchivedLogMessage* msg = sWorld.GetLog(logId, GetAccessLevel());
    if (!msg)
    {
        PSendSysMessage("Log #%u not found.", logId);
        SetSentErrorMessage(true);
        return false;
    }
    SendSysMessage(msg->msg.c_str());
    return true;
}

/// Set the filters of logging
bool ChatHandler::HandleServerLogFilterCommand(char* args)
{
    if (!*args)
    {
        SendSysMessage(LANG_LOG_FILTERS_STATE_HEADER);
        for (int i = 0; i < LOG_FILTER_COUNT; ++i)
            if (*logFilterData[i].name)
                PSendSysMessage("  %-20s = %s", logFilterData[i].name, GetOnOffStr(sLog.HasLogFilter(1 << i)));
        return true;
    }

    char *filtername = ExtractLiteralArg(&args);
    if (!filtername)
        return false;

    bool value;
    if (!ExtractOnOff(&args, value))
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    if (strncmp(filtername, "all", 4) == 0)
    {
        sLog.SetLogFilter(LogFilters(0xFFFFFFFF), value);
        PSendSysMessage(LANG_ALL_LOG_FILTERS_SET_TO_S, GetOnOffStr(value));
        return true;
    }

    for (int i = 0; i < LOG_FILTER_COUNT; ++i)
    {
        if (!*logFilterData[i].name)
            continue;

        if (!strncmp(filtername, logFilterData[i].name, strlen(filtername)))
        {
            sLog.SetLogFilter(LogFilters(1 << i), value);
            PSendSysMessage("  %-20s = %s", logFilterData[i].name, GetOnOffStr(value));
            return true;
        }
    }

    return false;
}

/// Set the level of logging
bool ChatHandler::HandleServerLogLevelCommand(char *args)
{
    if (!*args)
    {
        PSendSysMessage("Log level: %u", sLog.GetLogLevel());
        return true;
    }

    sLog.SetLogLevel(args);
    return true;
}

 // SPELL GROUPS

bool ChatHandler::HandleGroupAddSpellCommand(char *args)
{
    uint32 spellId = ExtractSpellIdFromLink(&args);
    uint32 groupId = 0;
    if (!spellId || !ExtractUInt32(&args, groupId))
        return false;

    SpellEntry const* pSpell = sSpellMgr.GetSpellEntry(spellId);
    if (!pSpell)
    {
        PSendSysMessage("Spell %u does not exist.", spellId);
        SetSentErrorMessage(true);
        return false;
    }
    LocaleConstant loc = GetSessionDbcLocale();
    ShowSpellListHelper(nullptr, pSpell, loc);

    WorldDatabase.PExecute("INSERT INTO `spell_group` SET id=%u, spell_id=%u", groupId, spellId);
    PSendSysMessage("Spell added to group %u in DB.", groupId);
    return true;
}

bool ChatHandler::HandleGroupSetRuleCommand(char *args)
{
    uint32 groupId = 0, ruleId = SPELL_GROUP_STACK_RULE_EXCLUSIVE;
    if (!ExtractUInt32(&args, groupId))
        return false;

    // 'ruleId' optional
    ExtractUInt32(&args, ruleId);
    WorldDatabase.PExecute("REPLACE INTO `spell_group_stack_rules` SET group_id=%u, stack_rule=%u", groupId, ruleId);
    PSendSysMessage("Group %u : rule %u.", groupId, ruleId);
    return true;
}

bool ChatHandler::HandleReloadSpellGroupCommand(char*)
{
    sSpellMgr.LoadSpellGroups();
    SendSysMessage("Table `spell_group` rechargee.");
    return true;
}

bool ChatHandler::HandleReloadSpellGroupStackRulesCommand(char*)
{
    sSpellMgr.LoadSpellGroupStackRules();
    SendSysMessage("Table `spell_group_stack_rules` rechargee.");
    return true;
}

bool ChatHandler::HandleEventListCommand(char* args)
{
    uint32 counter = 0;
    bool all = false;
    std::string arg = args;
    if (arg == "all")
        all = true;

    GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();

    char const* active = GetMangosString(LANG_ACTIVE);
    char const* inactive = GetMangosString(LANG_FACTION_INACTIVE);
    char const* state = "";

    for (uint32 event_id = 0; event_id < events.size(); ++event_id)
    {
        if (!sGameEventMgr.IsValidEvent(event_id))
            continue;

        if (!sGameEventMgr.IsActiveEvent(event_id))
        {
            if (!all)
                continue;
            state = inactive;
        }
        else
            state = active;

        GameEventData const& eventData = events[event_id];

        if (m_session)
            PSendSysMessage(LANG_EVENT_ENTRY_LIST_CHAT, event_id, event_id, eventData.description.c_str(), state);
        else
            PSendSysMessage(LANG_EVENT_ENTRY_LIST_CONSOLE, event_id, eventData.description.c_str(), state);

        ++counter;
    }

    if (counter == 0)
        SendSysMessage(LANG_NOEVENTFOUND);

    return true;
}

bool ChatHandler::HandleEventInfoCommand(char* args)
{
    if (!*args)
        return false;

    // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
    uint32 event_id;
    if (!ExtractUint32KeyFromLink(&args, "Hgameevent", event_id))
        return false;

    GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();

    if (!sGameEventMgr.IsValidEvent(event_id))
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventData const& eventData = events[event_id];

    char const* activeStr = sGameEventMgr.IsActiveEvent(event_id) ? GetMangosString(LANG_ACTIVE) : "";

    std::string startTimeStr = TimeToTimestampStr(eventData.start);
    std::string endTimeStr = TimeToTimestampStr(eventData.end);

    uint32 delay = sGameEventMgr.NextCheck(event_id);
    time_t nextTime = time(nullptr) + delay;
    std::string nextStr = nextTime >= eventData.start && nextTime < eventData.end ? TimeToTimestampStr(time(nullptr) + delay) : "-";

    std::string occurenceStr = secsToTimeString(eventData.occurence * MINUTE);
    std::string lengthStr = secsToTimeString(eventData.length * MINUTE);

    PSendSysMessage(LANG_EVENT_INFO, event_id, eventData.description.c_str(), activeStr,
        startTimeStr.c_str(), endTimeStr.c_str(), occurenceStr.c_str(), lengthStr.c_str(),
        nextStr.c_str());
    return true;
}

bool ChatHandler::HandleEventStartCommand(char* args)
{
    if (!*args)
        return false;

    // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
    uint32 event_id;
    if (!ExtractUint32KeyFromLink(&args, "Hgameevent", event_id))
        return false;

    GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();

    if (!sGameEventMgr.IsValidEvent(event_id))
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventData const& eventData = events[event_id];
    if (!eventData.isValid())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    if (sGameEventMgr.IsActiveEvent(event_id))
    {
        PSendSysMessage(LANG_EVENT_ALREADY_ACTIVE, event_id);
        SetSentErrorMessage(true);
        return false;
    }

    if (!sGameEventMgr.IsEnabled(event_id))
    {
        PSendSysMessage(LANG_EVENT_DISABLED, event_id);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_EVENT_STARTED, event_id, eventData.description.c_str());
    sGameEventMgr.StartEvent(event_id, true);
    return true;
}

bool ChatHandler::HandleEventStopCommand(char* args)
{
    if (!*args)
        return false;

    // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
    uint32 event_id;
    if (!ExtractUint32KeyFromLink(&args, "Hgameevent", event_id))
        return false;

    GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();

    if (!sGameEventMgr.IsValidEvent(event_id))
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventData const& eventData = events[event_id];
    if (!eventData.isValid())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    if (!sGameEventMgr.IsActiveEvent(event_id))
    {
        PSendSysMessage(LANG_EVENT_NOT_ACTIVE, event_id);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_EVENT_STOPPED, event_id, eventData.description.c_str());
    sGameEventMgr.StopEvent(event_id, true);
    return true;
}

bool ChatHandler::HandleEventEnableCommand(char* args)
{
    if (!*args)
        return false;

    // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
    uint32 event_id;
    if (!ExtractUint32KeyFromLink(&args, "Hgameevent", event_id))
        return false;

    GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();

    if (!sGameEventMgr.IsValidEvent(event_id))
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventData const& eventData = events[event_id];
    if (!eventData.isValid())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    if (sGameEventMgr.IsEnabled(event_id))
    {
        PSendSysMessage(LANG_EVENT_ALREADY_ENABLED, event_id);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_EVENT_ENABLED, event_id, eventData.description.c_str());
    sGameEventMgr.EnableEvent(event_id, true);
    return true;
}

bool ChatHandler::HandleEventDisableCommand(char* args)
{
    if (!*args)
        return false;

    // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
    uint32 event_id;
    if (!ExtractUint32KeyFromLink(&args, "Hgameevent", event_id))
        return false;

    GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();

    if (!sGameEventMgr.IsValidEvent(event_id))
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventData const& eventData = events[event_id];
    if (!eventData.isValid())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    if (!sGameEventMgr.IsEnabled(event_id))
    {
        PSendSysMessage(LANG_EVENT_ALREADY_DISABLED, event_id);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_EVENT_DISABLED, event_id, eventData.description.c_str());
    sGameEventMgr.EnableEvent(event_id, false);
    return true;
}

bool ChatHandler::HandleReloadAllCommand(char* /*args*/)
{
    HandleReloadSkillFishingBaseLevelCommand((char*)"");

    HandleReloadAllAreaCommand((char*)"");
    HandleReloadEventAIEventsCommand((char*)"");
    HandleReloadAllLootCommand((char*)"");
    HandleReloadAllNpcCommand((char*)"");
    HandleReloadAllQuestCommand((char*)"");
    HandleReloadAllSpellCommand((char*)"");
    HandleReloadAllItemCommand((char*)"");
    HandleReloadAllGossipsCommand((char*)"");
    HandleReloadAllLocalesCommand((char*)"");

    HandleReloadCommandCommand((char*)"");
    HandleReloadReservedNameCommand((char*)"");
    HandleReloadMangosStringCommand((char*)"");
    HandleReloadGameTeleCommand((char*)"");
    HandleReloadBattleEventCommand((char*)"");
    return true;
}

bool ChatHandler::HandleReloadAllAreaCommand(char* /*args*/)
{
    //HandleReloadQuestAreaTriggersCommand((char*)""); -- reloaded in HandleReloadAllQuestCommand
    HandleReloadAreaTriggerTeleportCommand((char*)"");
    HandleReloadAreaTriggerTavernCommand((char*)"");
    HandleReloadGameGraveyardZoneCommand((char*)"");
    return true;
}

bool ChatHandler::HandleReloadAllLootCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables...");
    LoadLootTables();
    SendSysMessage("DB tables `*_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAllNpcCommand(char* args)
{
    if (*args != 'a')                                       // will be reloaded from all_gossips
        HandleReloadNpcGossipCommand((char*)"a");
    HandleReloadNpcTrainerCommand((char*)"a");
    HandleReloadNpcVendorCommand((char*)"a");
    HandleReloadPointsOfInterestCommand((char*)"a");
    return true;
}

bool ChatHandler::HandleReloadAllQuestCommand(char* /*args*/)
{
    HandleReloadQuestAreaTriggersCommand((char*)"a");
    HandleReloadQuestTemplateCommand((char*)"a");

    sLog.outString("Re-Loading Quests Relations...");
    sObjectMgr.LoadQuestRelations();
    SendSysMessage("DB tables `*_questrelation` and `*_involvedrelation` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAllScriptsCommand(char* /*args*/)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        PSendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    sLog.outString("Re-Loading Scripts...");
    HandleReloadGameObjectScriptsCommand((char*)"a");
    HandleReloadGossipScriptsCommand((char*)"a");
    HandleReloadGenericScriptsCommand((char*)"a");
    HandleReloadEventScriptsCommand((char*)"a");
    HandleReloadQuestEndScriptsCommand((char*)"a");
    HandleReloadQuestStartScriptsCommand((char*)"a");
    HandleReloadSpellScriptsCommand((char*)"a");
    HandleReloadCreatureSpellScriptsCommand((char*)"a");
    SendSysMessage("DB tables `*_scripts` reloaded.");
    sScriptMgr.CheckAllScriptTexts();
    return true;
}

bool ChatHandler::HandleReloadAllSpellCommand(char* /*args*/)
{
    HandleReloadSpellAffectCommand((char*)"a");
    HandleReloadSpellAreaCommand((char*)"a");
    HandleReloadSpellChainCommand((char*)"a");
    HandleReloadSpellElixirCommand((char*)"a");
    HandleReloadSpellLearnSpellCommand((char*)"a");
    HandleReloadSpellProcEventCommand((char*)"a");
    HandleReloadSpellProcItemEnchantCommand((char*)"a");
    HandleReloadSpellScriptTargetCommand((char*)"a");
    HandleReloadSpellTargetPositionCommand((char*)"a");
    HandleReloadSpellThreatsCommand((char*)"a");
    HandleReloadSpellPetAurasCommand((char*)"a");
    return true;
}

bool ChatHandler::HandleReloadAllGossipsCommand(char* args)
{
    HandleReloadGossipMenuCommand((char*)"a");
    HandleReloadGossipMenuOptionCommand((char*)"a");
    if (*args != 'a')                                       // already reload from all_scripts
        HandleReloadGossipScriptsCommand((char*)"a");
    HandleReloadNpcGossipCommand((char*)"a");
    HandleReloadPointsOfInterestCommand((char*)"a");
    return true;
}

bool ChatHandler::HandleReloadAllItemCommand(char* /*args*/)
{
    HandleReloadPageTextsCommand((char*)"a");
    HandleReloadItemEnchantementsCommand((char*)"a");
    HandleReloadItemRequiredTragetCommand((char*)"a");
    return true;
}

bool ChatHandler::HandleReloadAllLocalesCommand(char* /*args*/)
{
    HandleReloadLocalesCreatureCommand((char*)"a");
    HandleReloadLocalesGameobjectCommand((char*)"a");
    HandleReloadLocalesGossipMenuOptionCommand((char*)"a");
    HandleReloadLocalesItemCommand((char*)"a");
    HandleReloadLocalesPageTextCommand((char*)"a");
    HandleReloadLocalesPointsOfInterestCommand((char*)"a");
    HandleReloadLocalesQuestCommand((char*)"a");
    return true;
}

bool ChatHandler::HandleReloadConfigCommand(char* /*args*/)
{
    sLog.outString("Re-Loading config settings...");
    sWorld.LoadConfigSettings(true);
    SendSysMessage("World config settings reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAreaTriggerTavernCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Tavern Area Triggers...");
    sObjectMgr.LoadTavernAreaTriggers();
    SendSysMessage("DB table `areatrigger_tavern` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAreaTriggerTeleportCommand(char* /*args*/)
{
    sLog.outString("Re-Loading AreaTrigger teleport definitions...");
    sObjectMgr.LoadAreaTriggerTeleports();
    SendSysMessage("DB table `areatrigger_teleport` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCommandCommand(char* /*args*/)
{
    load_command_table = true;
    SendSysMessage("DB table `command` will be reloaded at next chat command use.");
    return true;
}

bool ChatHandler::HandleReloadCreatureSpellsCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Creature Spells... (`creature_spells`)");
    sObjectMgr.LoadCreatureSpells();
    SendSysMessage("DB table `creature_spells` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureQuestRelationsCommand(char* /*args*/)
{
    sLog.outString("Loading Quests Relations... (`creature_questrelation`)");
    sObjectMgr.LoadCreatureQuestRelations();
    SendSysMessage("DB table `creature_questrelation` (creature quest givers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureQuestInvRelationsCommand(char* /*args*/)
{
    sLog.outString("Loading Quests Relations... (`creature_involvedrelation`)");
    sObjectMgr.LoadCreatureInvolvedRelations();
    SendSysMessage("DB table `creature_involvedrelation` (creature quest takers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGossipMenuCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `gossip_menu` Table!");
    std::set<uint32> gossipScriptSet;
    for (const auto& itr : sGossipScripts)
        gossipScriptSet.insert(itr.first);
    sObjectMgr.LoadGossipMenu(gossipScriptSet);
    SendSysMessage("DB table `gossip_menu` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGossipMenuOptionCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `gossip_menu_option` Table!");
    std::set<uint32> gossipScriptSet;
    for (const auto& itr : sGossipScripts)
        gossipScriptSet.insert(itr.first);
    sObjectMgr.LoadGossipMenuItems(gossipScriptSet);
    SendSysMessage("DB table `gossip_menu_option` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGossipScriptsCommand(char* args)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `gossip_scripts`...");

    sScriptMgr.LoadGossipScripts();

    if (*args != 'a')
        SendSysMessage("DB table `gossip_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadGOQuestRelationsCommand(char* /*args*/)
{
    sLog.outString("Loading Quests Relations... (`gameobject_questrelation`)");
    sObjectMgr.LoadGameobjectQuestRelations();
    SendSysMessage("DB table `gameobject_questrelation` (gameobject quest givers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGORequirementsCommand(char* /*args*/)
{
    sLog.outString("Loading Game Objects requirements... (`gameobject_requirement`)");
    sObjectMgr.LoadGameobjectsRequirements();
    SendSysMessage("DB table `gameobject_requirement` (Game Objects requirements) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGOQuestInvRelationsCommand(char* /*args*/)
{
    sLog.outString("Loading Quests Relations... (`gameobject_involvedrelation`)");
    sObjectMgr.LoadGameobjectInvolvedRelations();
    SendSysMessage("DB table `gameobject_involvedrelation` (gameobject quest takers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadQuestAreaTriggersCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Quest Area Triggers...");
    sObjectMgr.LoadQuestAreaTriggers();
    SendSysMessage("DB table `areatrigger_involvedrelation` (quest area triggers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadQuestTemplateCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Quest Templates...");
    sObjectMgr.LoadQuests();
    SendSysMessage("DB table `quest_template` (quest definitions) reloaded.");

    /// dependent also from `gameobject` but this table not reloaded anyway
    sLog.outString("Re-Loading GameObjects for quests...");
    sObjectMgr.LoadGameObjectForQuests();
    SendSysMessage("Data GameObjects for quests reloaded.");
    return true;
}

bool ChatHandler::HandleReloadQuestGreetingCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Quest Greetings...");
    sObjectMgr.LoadQuestGreetings();
    SendSysMessage("DB table `quest_greeting` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadTrainerGreetingCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Trainer Greetings...");
    sObjectMgr.LoadTrainerGreetings();
    SendSysMessage("DB table `npc_trainer_greeting` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesCreatureCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`creature_loot_template`)");
    LoadLootTemplates_Creature();
    LootTemplates_Creature.CheckLootRefs();
    SendSysMessage("DB table `creature_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesDisenchantCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`disenchant_loot_template`)");
    LoadLootTemplates_Disenchant();
    LootTemplates_Disenchant.CheckLootRefs();
    SendSysMessage("DB table `disenchant_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesFishingCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`fishing_loot_template`)");
    LoadLootTemplates_Fishing();
    LootTemplates_Fishing.CheckLootRefs();
    SendSysMessage("DB table `fishing_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesGameobjectCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`gameobject_loot_template`)");
    LoadLootTemplates_Gameobject();
    LootTemplates_Gameobject.CheckLootRefs();
    SendSysMessage("DB table `gameobject_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesItemCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`item_loot_template`)");
    LoadLootTemplates_Item();
    LootTemplates_Item.CheckLootRefs();
    SendSysMessage("DB table `item_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesPickpocketingCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`pickpocketing_loot_template`)");
    LoadLootTemplates_Pickpocketing();
    LootTemplates_Pickpocketing.CheckLootRefs();
    SendSysMessage("DB table `pickpocketing_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesMailCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`mail_loot_template`)");
    LoadLootTemplates_Mail();
    LootTemplates_Mail.CheckLootRefs();
    SendSysMessage("DB table `mail_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesReferenceCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`reference_loot_template`)");
    LoadLootTemplates_Reference();
    SendSysMessage("DB table `reference_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesSkinningCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Loot Tables... (`skinning_loot_template`)");
    LoadLootTemplates_Skinning();
    LootTemplates_Skinning.CheckLootRefs();
    SendSysMessage("DB table `skinning_loot_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadMangosStringCommand(char* /*args*/)
{
    sLog.outString("Re-Loading mangos_string Table!");
    sObjectMgr.LoadMangosStrings();
    SendSysMessage("DB table `mangos_string` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadNpcGossipCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `npc_gossip` Table!");
    sObjectMgr.LoadNpcGossips();
    SendSysMessage("DB table `npc_gossip` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadNpcTextCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `npc_text` Table!");
    sObjectMgr.LoadNPCText();
    SendSysMessage("DB table `npc_text` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadNpcTrainerCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `npc_trainer_template` Table!");
    sObjectMgr.LoadTrainerTemplates();
    SendSysMessage("DB table `npc_trainer_template` reloaded.");

    sLog.outString("Re-Loading `npc_trainer` Table!");
    sObjectMgr.LoadTrainers();
    SendSysMessage("DB table `npc_trainer` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadNpcVendorCommand(char* /*args*/)
{
    // not safe reload vendor template tables independent...
    sLog.outString("Re-Loading `npc_vendor_template` Table!");
    sObjectMgr.LoadVendorTemplates();
    SendSysMessage("DB table `npc_vendor_template` reloaded.");

    sLog.outString("Re-Loading `npc_vendor` Table!");
    sObjectMgr.LoadVendors();
    SendSysMessage("DB table `npc_vendor` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadPointsOfInterestCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `points_of_interest` Table!");
    sObjectMgr.LoadPointsOfInterest();
    SendSysMessage("DB table `points_of_interest` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadReservedNameCommand(char* /*args*/)
{
    sLog.outString("Loading ReservedNames... (`reserved_name`)");
    sObjectMgr.LoadReservedPlayersNames();
    SendSysMessage("DB table `reserved_name` (player reserved names) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadReputationRewardRateCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `reputation_reward_rate` Table!");
    sObjectMgr.LoadReputationRewardRate();
    SendSysMessage("DB table `reputation_reward_rate` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadReputationSpilloverTemplateCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `reputation_spillover_template` Table!");
    sObjectMgr.LoadReputationSpilloverTemplate();
    SendSysMessage("DB table `reputation_spillover_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSkillFishingBaseLevelCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Skill Fishing base level requirements...");
    sObjectMgr.LoadFishingBaseSkillLevel();
    SendSysMessage("DB table `skill_fishing_base_level` (fishing base level for zone/subzone) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellAffectCommand(char* /*args*/)
{
    sLog.outString("Re-Loading SpellAffect definitions...");
    sSpellMgr.LoadSpellAffects();
    SendSysMessage("DB table `spell_affect` (spell mods apply requirements) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellAreaCommand(char* /*args*/)
{
    sLog.outString("Re-Loading SpellArea Data...");
    sSpellMgr.LoadSpellAreas();
    SendSysMessage("DB table `spell_area` (spell dependences from area/quest/auras state) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellChainCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Spell Chain Data... ");
    sSpellMgr.LoadSpellChains();
    SendSysMessage("DB table `spell_chain` (spell ranks) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellElixirCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Spell Elixir types...");
    sSpellMgr.LoadSpellElixirs();
    SendSysMessage("DB table `spell_elixir` (spell elixir types) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellLearnSpellCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Spell Learn Spells...");
    sSpellMgr.LoadSpellLearnSpells();
    SendSysMessage("DB table `spell_learn_spell` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellProcEventCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Spell Proc Event conditions...");
    sSpellMgr.LoadSpellProcEvents();
    SendSysMessage("DB table `spell_proc_event` (spell proc trigger requirements) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellProcItemEnchantCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Spell Proc Item Enchant...");
    sSpellMgr.LoadSpellProcItemEnchant();
    SendSysMessage("DB table `spell_proc_item_enchant` (item enchantment ppm) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellScriptTargetCommand(char* /*args*/)
{
    sLog.outString("Re-Loading SpellsScriptTarget...");
    sSpellMgr.LoadSpellScriptTarget();
    SendSysMessage("DB table `spell_script_target` (spell targets selection in case specific creature/GO requirements) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellTargetPositionCommand(char* /*args*/)
{
    sLog.outString("Re-Loading spell target destination coordinates...");
    sSpellMgr.LoadSpellTargetPositions();
    SendSysMessage("DB table `spell_target_position` (destination coordinates for spell targets) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellThreatsCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Aggro Spells Definitions...");
    sSpellMgr.LoadSpellThreats();
    SendSysMessage("DB table `spell_threat` (spell aggro definitions) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellPetAurasCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Spell pet auras...");
    sSpellMgr.LoadSpellPetAuras();
    SendSysMessage("DB table `spell_pet_auras` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadPageTextsCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Page Texts...");
    sObjectMgr.LoadPageTexts();
    SendSysMessage("DB table `page_texts` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadItemEnchantementsCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Item Random Enchantments Table...");
    LoadRandomEnchantmentsTable();
    SendSysMessage("DB table `item_enchantment_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadItemRequiredTragetCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Item Required Targets Table...");
    sObjectMgr.LoadItemRequiredTarget();
    SendSysMessage("DB table `item_required_target` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadBattleEventCommand(char* /*args*/)
{
    sLog.outString("Re-Loading BattleGround Eventindexes...");
    sBattleGroundMgr.LoadBattleEventIndexes();
    SendSysMessage("DB table `gameobject_battleground` and `creature_battleground` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGameObjectScriptsCommand(char* args)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `gameobject_scripts`...");

    sScriptMgr.LoadGameObjectScripts();

    if (*args != 'a')
        SendSysMessage("DB table `gameobject_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadGenericScriptsCommand(char* args)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `generic_scripts`...");

    sScriptMgr.LoadGenericScripts();

    if (*args != 'a')
        SendSysMessage("DB table `generic_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadEventScriptsCommand(char* args)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `event_scripts`...");

    sScriptMgr.LoadEventScripts();

    if (*args != 'a')
        SendSysMessage("DB table `event_scripts` reloaded.");

    return true;
}

// Do not add separate reload command for scripts!
// EventAI events must be loaded right after.
bool ChatHandler::HandleReloadEventAIEventsCommand(char* args)
{
    sEventAIMgr.ClearEventData();

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `creature_ai_scripts`...");

    sScriptMgr.LoadCreatureEventAIScripts();

    if (*args != 'a')
        SendSysMessage("DB table `creature_ai_scripts` reloaded.");

    sLog.outString("Re-Loading Events from `creature_ai_events`...");
    sEventAIMgr.LoadCreatureEventAI_Events();
    SendSysMessage("DB table `creature_ai_events` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadQuestEndScriptsCommand(char* args)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `quest_end_scripts`...");

    sScriptMgr.LoadQuestEndScripts();

    if (*args != 'a')
        SendSysMessage("DB table `quest_end_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadQuestStartScriptsCommand(char* args)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `quest_start_scripts`...");

    sScriptMgr.LoadQuestStartScripts();

    if (*args != 'a')
        SendSysMessage("DB table `quest_start_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadCreatureSpellScriptsCommand(char* args)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `creature_spells_scripts`...");

    sScriptMgr.LoadCreatureSpellScripts();

    if (*args != 'a')
        SendSysMessage("DB table `creature_spells_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadSpellScriptsCommand(char* args)
{
    if (sScriptMgr.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*args != 'a')
        sLog.outString("Re-Loading Scripts from `spell_scripts`...");

    sScriptMgr.LoadSpellScripts();

    if (*args != 'a')
        SendSysMessage("DB table `spell_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadGameGraveyardZoneCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Graveyard-zone links...");

    sObjectMgr.LoadGraveyardZones();

    SendSysMessage("DB table `game_graveyard_zone` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadGameTeleCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Game Tele coordinates...");

    sObjectMgr.LoadGameTele();

    SendSysMessage("DB table `game_tele` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadTaxiPathTransitionsCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Taxi path transitions...");

    sObjectMgr.LoadTaxiPathTransitions();

    SendSysMessage("DB table `taxi_path_transitions` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadLocalesCreatureCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Locales Creature ...");
    sObjectMgr.LoadCreatureLocales();
    SendSysMessage("DB table `locales_creature` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesGameobjectCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Locales Gameobject ... ");
    sObjectMgr.LoadGameObjectLocales();
    SendSysMessage("DB table `locales_gameobject` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesGossipMenuOptionCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Locales Gossip Menu Option ... ");
    sObjectMgr.LoadGossipMenuItemsLocales();
    SendSysMessage("DB table `locales_gossip_menu_option` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesItemCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Locales Item ... ");
    sObjectMgr.LoadItemLocales();
    SendSysMessage("DB table `locales_item` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesPageTextCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Locales Page Text ... ");
    sObjectMgr.LoadPageTextLocales();
    SendSysMessage("DB table `locales_page_text` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesPointsOfInterestCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Locales Points Of Interest ... ");
    sObjectMgr.LoadPointOfInterestLocales();
    SendSysMessage("DB table `locales_points_of_interest` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesQuestCommand(char* /*args*/)
{
    sLog.outString("Re-Loading Locales Quest ... ");
    sObjectMgr.LoadQuestLocales();
    SendSysMessage("DB table `locales_quest` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCharacterPetCommand(char *args)
{
    uint32 petId = 0;
    if (!ExtractUInt32(&args, petId))
        return false;
    if (!petId)
        return false;
    sCharacterDatabaseCache.LoadAll(petId);
    PSendSysMessage(">> Pet #%u reloaded from database.", petId);
    return true;
}

bool ChatHandler::HandleReloadCreatureCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `creature` table ...");
    sObjectMgr.LoadCreatures(true);
    SendSysMessage("DB table `creature` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGameObjectCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `gameobject` table ...");
    sObjectMgr.LoadGameobjects(true);
    SendSysMessage("DB table `gameobject` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureTemplate(char*)
{
    sObjectMgr.LoadCreatureTemplates();
    SendSysMessage(">> Table `creature_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadItemTemplate(char*)
{
    sObjectMgr.LoadItemPrototypes();
    SendSysMessage(">> Table `item_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadMapTemplate(char*)
{
    sObjectMgr.LoadMapTemplate();
    SendSysMessage(">> Table `map_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGameObjectTemplate(char*)
{
    sObjectMgr.LoadGameobjectInfo();
    SendSysMessage(">> Table `gameobject_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadExplorationBaseXp(char*)
{
    sObjectMgr.LoadExplorationBaseXP();
    SendSysMessage(">> Table `exploration_basexp` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadPetNameGeneration(char*)
{
    sObjectMgr.LoadPetNames();
    SendSysMessage(">> Table `pet_name_generation` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureOnKillReputation(char*)
{
    sObjectMgr.LoadReputationOnKill();
    SendSysMessage(">> Table `creature_onkill_reputation` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGameWeather(char*)
{
    sWeatherMgr.LoadWeatherZoneChances();
    SendSysMessage(">> Table `game_weather` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadFactionChangeReputations(char*)
{
    sObjectMgr.LoadFactionChangeReputations();
    SendSysMessage(">> Table `player_factionchange_reputations` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadFactionChangeSpells(char*)
{
    sObjectMgr.LoadFactionChangeSpells();
    SendSysMessage(">> Table `player_factionchange_spells` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadFactionChangeItems(char*)
{
    sObjectMgr.LoadFactionChangeItems();
    SendSysMessage(">> Table `player_factionchange_items` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadFactionChangeQuests(char*)
{
    sObjectMgr.LoadFactionChangeQuests();
    SendSysMessage(">> Table `player_factionchange_quests` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadFactionChangeMounts(char*)
{
    sObjectMgr.LoadFactionChangeMounts();
    SendSysMessage(">> Table `player_factionchange_mounts` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureDisplayInfoAddon(char*)
{
    sObjectMgr.LoadCreatureDisplayInfoAddon();
    SendSysMessage(">> Table `creature_display_info_addon` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadIPBanList(char*)
{
    sAccountMgr.LoadIPBanList();
    SendSysMessage(">> Table `ip_banned` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAccountBanList(char*)
{
    sAccountMgr.LoadAccountBanList();
    SendSysMessage(">> Table `account_banned` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadInstanceBuffRemoval(char*)
{
    sAuraRemovalMgr.LoadFromDB();
    SendSysMessage(">> Table `instance_buff_removal` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadPetitions(char*)
{
    sGuildMgr.LoadPetitions();
    SendSysMessage(">> Table `petition` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadVariablesCommand(char*)
{
    sObjectMgr.LoadSavedVariable();
    SendSysMessage("Table `variables` has been reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureGroupsCommand(char *args)
{
    sCreatureGroupsManager->Load();
    SendSysMessage("DB table `creature_groups` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCinematicWaypointsCommand(char *args)
{
    sObjectMgr.LoadCinematicsWaypoints();
    SendSysMessage("DB table `cinematic_waypoints` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellDisabledCommand(char *args)
{
    sObjectMgr.LoadSpellDisabledEntrys();
    SendSysMessage("DB table `spell_disabed` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAutoBroadcastCommand(char *args)
{
    sAutoBroadCastMgr.Load();
    SendSysMessage("DB table `autobroadcast` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellModsCommand(char *args)
{
    sSpellModMgr.LoadSpellMods();
    SendSysMessage("DB table `spell_mod` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadMapLootDisabledCommand(char *args)
{
    sObjectMgr.LoadMapLootDisabled();
    SendSysMessage("DB table `map_loot_disabled` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadConditionsCommand(char* /*args*/)
{
    sLog.outString("Re-Loading `conditions`... ");
    sObjectMgr.LoadConditions();
    SendSysMessage("DB table `conditions` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAnticheatCommand(char*)
{
    sAnticheatMgr->LoadAnticheatData();
    SendSysMessage(">> Anticheat data reloaded");
    return true;
}