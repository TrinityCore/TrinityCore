/*
* Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
* Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
* Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
* Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
* Copyright (C) 2017 Light's Hope <https://github.com/LightsHope>
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

#include "Database/DatabaseEnv.h"
#include "Database/Database.h"
#include "Database/DatabaseImpl.h"
#include "Database/SqlOperations.h"
#include "Language.h"
#include "Chat.h"
#include "AccountMgr.h"
#include "DBCStores.h"
#include "Util.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "ObjectGuid.h"
#include "AsyncCommandHandlers.h"

void PInfoHandler::HandlePInfoCommand(WorldSession* session, Player* target, ObjectGuid& target_guid, std::string& name)
{
    PInfoData* data = new PInfoData;
    data->m_accountId = session->GetAccountId();
    data->target_name = name;

    if (target)
    {
        data->accId = target->GetSession()->GetAccountId();
        data->money = target->GetMoney();
        data->total_player_time = target->GetTotalPlayedTime();
        data->level = target->GetLevel();
        data->latency = target->GetSession()->GetLatency();
        data->loc = target->GetSession()->GetSessionDbcLocale();
        data->race = target->GetRace();
        data->class_ = target->GetClass();

        data->target_guid = target->GetObjectGuid();
        data->online = true;

        HandleDataAfterPlayerLookup(data);
    }
    else
    {
        data->target_guid = target_guid;
        CharacterDatabase.AsyncPQuery(&PInfoHandler::HandlePlayerLookupResult, data,
            //       0                    1        2        3          4       5
            "SELECT `played_time_total`, `level`, `money`, `account`, `race`, `class` FROM `characters` WHERE `guid` = '%u'",
            target_guid.GetCounter());
    }
}

void PInfoHandler::HandlePlayerLookupResult(QueryResult* result, PInfoData *data)
{
    if (!result)
    {
        delete data;
        return;
    }

    Field* fields = result->Fetch();
    data->total_player_time = fields[0].GetUInt32();
    data->level = fields[1].GetUInt32();
    data->money = fields[2].GetUInt32();
    data->accId = fields[3].GetUInt32();
    data->race = fields[4].GetUInt8();
    data->class_ = fields[5].GetUInt8();

    delete result;

    HandleDataAfterPlayerLookup(data);
}

void PInfoHandler::HandleDataAfterPlayerLookup(PInfoData *data)
{
    SqlQueryHolder* charHolder = new SqlQueryHolder;
    charHolder->SetSize(2);
    charHolder->SetPQuery(PINFO_QUERY_GOLD_SENT, "SELECT SUM(`money`) FROM `mail` WHERE `sender_guid` = %u", data->target_guid.GetCounter());
    charHolder->SetPQuery(PINFO_QUERY_GOLD_RECEIVED, "SELECT SUM(`money`) FROM `mail` WHERE `receiver_guid` = %u", data->target_guid.GetCounter());

    CharacterDatabase.DelayQueryHolder(&PInfoHandler::HandleDelayedMoneyQuery, charHolder, data);
}

void PInfoHandler::HandleDelayedMoneyQuery(QueryResult*, SqlQueryHolder *holder, PInfoData *data)
{
    if (holder)
    {
        QueryResult* result = holder->GetResult(PINFO_QUERY_GOLD_SENT);
        if (result)
            data->mail_gold_outbox = result->Fetch()[0].GetUInt32();

        result = holder->GetResult(PINFO_QUERY_GOLD_RECEIVED);
        if (result)
            data->mail_gold_inbox = result->Fetch()[0].GetUInt32();

        // Delete all results now
        holder->DeleteAllResults();
        delete holder;
    }

    // Handle the callback in a thread-safe environment (the world
    // thread) since we are ready to access the caller's session
    // and print the result once it completes. We also read guild info
    // so this cannot be done in an async task
    LoginDatabase.AsyncPQueryUnsafe(&PInfoHandler::HandleAccountInfoResult, data,
        "SELECT `username`, `last_ip`, `last_login`, `locale`, `locked` FROM `account` WHERE `id` = '%u'",
        data->accId);
}

// Not threadsafe, executed in unsafe callback
void PInfoHandler::HandleAccountInfoResult(QueryResult* result, PInfoData *data)
{
    WorldSession* session = sWorld.FindSession(data->m_accountId);
    // Caller re-logged mid query. ChatHandler requires a player in the session
    if (!session || !session->GetPlayer())
    {
        delete data;
        delete result;
        return;
    }

    if (result)
    {
        Field* fields = result->Fetch();
        data->username = fields[0].GetCppString();
        data->security = sAccountMgr.GetSecurity(data->accId);
        data->loc = LocaleConstant(fields[3].GetUInt8());
        data->security_flag = fields[4].GetUInt8();

        bool showIp = true;
        if (session->GetSecurity() < data->security)
            showIp = false;
        else if (session->GetSecurity() < SEC_ADMINISTRATOR && data->security > SEC_PLAYER) // Only admins can see GM IPs
            showIp = false;
        if (showIp)
        {
            data->last_ip = fields[1].GetCppString();
            data->last_login = fields[2].GetCppString();
        }
        else
        {
            data->last_ip = "-";
            data->last_login = "-";
        }

        data->hasAccount = true;

        delete result;
    }

    HandleResponse(session, data);
}

// Not threadsafe, executed in thread unsafe callback
void PInfoHandler::HandleResponse(WorldSession* session, PInfoData *data)
{
    char const* raceName = GetUnitRaceName(data->race, session->GetSessionDbcLocale());
    char const* className = GetUnitClassName(data->class_, session->GetSessionDbcLocale());
    if (!raceName)
        raceName = "";
    if (!className)
        className = "";

    if (data->loc > LOCALE_esMX)
        data->loc = LOCALE_enUS;
    ChatHandler cHandler(session);

    data->two_factor_enabled = data->security_flag & 4 ? "Enabled" : "Disabled";
    if (!data->hasAccount)
    {
        data->username = cHandler.GetMangosString(LANG_ERROR);
        data->last_ip = cHandler.GetMangosString(LANG_ERROR);
        data->security = SEC_PLAYER;
    }

    std::string nameLink = cHandler.playerLink(data->target_name);

    cHandler.PSendSysMessage(LANG_PINFO_ACCOUNT, raceName, className,
        (data->online ? "" : cHandler.GetMangosString(LANG_OFFLINE)),
        nameLink.c_str(), data->target_guid.GetCounter(), cHandler.playerLink(data->username).c_str(),
        data->accId, sAccountMgr.IsAccountBanned(data->accId) ? ", banned" : "",
        data->security, cHandler.playerLink(data->last_ip).c_str(),
        sAccountMgr.IsIPBanned(data->last_ip) ? " [BANIP]" : "", data->last_login.c_str(),
        data->latency, localeNames[data->loc], data->two_factor_enabled.c_str());

    std::string timeStr = secsToTimeString(data->total_player_time, true, true);
    uint32 money = data->money;
    uint32 mail_gold_inbox = data->mail_gold_inbox;
    uint32 mail_gold_outbox = data->mail_gold_outbox;

    uint32 gold = money / GOLD;
    uint32 silv = (money % GOLD) / SILVER;
    uint32 copp = (money % GOLD) % SILVER;
    uint32 gold_in = mail_gold_inbox / GOLD;
    uint32 silv_in = (mail_gold_inbox % GOLD) / SILVER;
    uint32 copp_in = (mail_gold_inbox % GOLD) % SILVER;
    uint32 gold_out = mail_gold_outbox / GOLD;
    uint32 silv_out = (mail_gold_outbox % GOLD) / SILVER;
    uint32 copp_out = (mail_gold_outbox % GOLD) % SILVER;
    cHandler.PSendSysMessage(LANG_PINFO_LEVEL, timeStr.c_str(), data->level, gold, silv, copp, gold_in, silv_in, copp_in, gold_out, silv_out, copp_out);
    if (Guild* guild = sGuildMgr.GetPlayerGuild(data->target_guid))
        cHandler.PSendSysMessage("Guild: %s", cHandler.playerLink(guild->GetName()).c_str());

    delete data;
}

// Handles the query result and offloads display to an async task in
// the world update
void PlayerSearchHandler::HandlePlayerAccountSearchResult(QueryResult*, SqlQueryHolder* queryHolder, int)
{
    sWorld.AddAsyncTask(PlayerAccountSearchDisplayTask((PlayerSearchQueryHolder*)queryHolder));
}

void PlayerAccountSearchDisplayTask::operator ()()
{
    // NOTE: Do not currently support console access for these commands
    WorldSession* session = sWorld.FindSession(holder->GetAccountId());
    if (!session)
    {
        if (holder)
        {
            holder->DeleteAllResults();
            delete holder;
        }
        return;
    }

    ChatHandler cHandler(session);

    if (!holder)
    {
        cHandler.PSendSysMessage(LANG_NO_PLAYERS_FOUND);
        return;
    }

    uint32 count = 0;
    AccountTypes sessionAccess = session->GetSecurity();
    for (uint32 i = 0; i < holder->GetSize(); ++i)
    {
        QueryResult* query = holder->GetResult(i);
        if (!query)
            continue;

        std::pair<uint32, std::string> accountInfo;
        if (holder->GetAccountInfo(i, accountInfo))
        {
            uint32& acc_id = accountInfo.first;
            std::string &acc_name = accountInfo.second;

            AccountTypes security = sAccountMgr.GetSecurity(acc_id);

            // Cannot lookup accounts above the caller's security, nor can GMs below
            // administrator lookup other non-player accounts
            if (sessionAccess < security || (sessionAccess < SEC_ADMINISTRATOR && security > SEC_PLAYER))
                continue;

            bool banned = sAccountMgr.IsAccountBanned(acc_id);
            if (banned)
                acc_name = acc_name + " [BANNED]";

            cHandler.PSendSysMessage(LANG_LOOKUP_PLAYER_ACCOUNT, acc_name.c_str(), acc_id);

            PlayerSearchHandler::ShowPlayerListHelper(query, cHandler, count, holder->GetLimit(), true);
        }

        // Don't show any further accounts now that we're at the limit
        if (count == holder->GetLimit())
            break;
    }

    if (count == 0)
    {
        cHandler.PSendSysMessage(LANG_NO_PLAYERS_FOUND);
    }

    holder->DeleteAllResults();
    delete holder;
}

void PlayerCharacterLookupDisplayTask::operator()()
{
    WorldSession* session = sWorld.FindSession(accountId);
    if (!session)
    {
        delete query;
        return;
    }

    ChatHandler cHandler(session);
    if (!query)
    {
        cHandler.PSendSysMessage(LANG_NO_PLAYERS_FOUND);
        return;
    }

    uint32 count = 0;
    PlayerSearchHandler::ShowPlayerListHelper(query, cHandler, count, limit, true);

    delete query;
}

// Handle the result and create a display task to run in the world update
void PlayerSearchHandler::HandlePlayerCharacterLookupResult(QueryResult* result, uint32 accountId, uint32 limit)
{
    sWorld.AddAsyncTask({PlayerCharacterLookupDisplayTask(result, accountId, limit)});
}

void PlayerSearchHandler::ShowPlayerListHelper(QueryResult* result, ChatHandler& chatHandler, uint32& count, uint32 limit, bool title)
{
    if (!chatHandler.GetSession() && title)
    {
        chatHandler.SendSysMessage(LANG_CHARACTERS_LIST_BAR);
        chatHandler.SendSysMessage(LANG_CHARACTERS_LIST_HEADER);
        chatHandler.SendSysMessage(LANG_CHARACTERS_LIST_BAR);
    }

    if (result)
    {
        LocaleConstant locale = chatHandler.GetSession() ? chatHandler.GetSession()->GetSessionDbcLocale() : LOCALE_enUS;
        ///- Circle through them. Display username and GM level
        do
        {
            // check limit
            if (count == limit)
                break;

            Field* fields = result->Fetch();
            uint32 guid = fields[0].GetUInt32();
            std::string name = fields[1].GetCppString();
            uint8 race = fields[2].GetUInt8();
            uint8 class_ = fields[3].GetUInt8();
            uint32 level = fields[4].GetUInt32();

            ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race);
            ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(class_);

            char const* race_name = raceEntry ? raceEntry->name[locale] : "<?>";
            char const* class_name = classEntry ? classEntry->name[locale] : "<?>";

            if (!chatHandler.GetSession())
            {
                if (sObjectAccessor.FindPlayerNotInWorld(ObjectGuid(HIGHGUID_PLAYER, guid)))
                    name = "*" + name;
                chatHandler.PSendSysMessage(LANG_CHARACTERS_LIST_LINE_CONSOLE, guid, name.c_str(), race_name, class_name, level);
            }
            else if (sObjectAccessor.FindPlayerNotInWorld(ObjectGuid(HIGHGUID_PLAYER, guid)))
                chatHandler.PSendSysMessage(LANG_CHARACTERS_LIST_LINE_CHAT_ONLINE, guid, name.c_str(), name.c_str(), race_name, class_name, level);
            else
                chatHandler.PSendSysMessage(LANG_CHARACTERS_LIST_LINE_CHAT, guid, name.c_str(), name.c_str(), race_name, class_name, level);

            ++count;
        } while (result->NextRow());
    }

    if (!chatHandler.GetSession())
        chatHandler.SendSysMessage(LANG_CHARACTERS_LIST_BAR);
}

void PlayerSearchQueryHolder::AddAccountInfo(uint32 queryIndex, uint32& accId, std::string& accName)
{
    m_accounts[queryIndex] = std::pair<uint32, std::string>(accId, accName);
}

bool PlayerSearchQueryHolder::GetAccountInfo(uint32 queryIndex, std::pair<uint32, std::string>& pair)
{
    PlayerSearchAccountMap::const_iterator iter = m_accounts.find(queryIndex);
    if (iter == m_accounts.cend())
        return false;
    
    pair.first = (*iter).second.first;
    pair.second = (*iter).second.second;

    return true;
}

void AccountSearchDisplayTask::operator ()()
{
    WorldSession* session = sWorld.FindSession(accountId);
    if (!session)
    {
        delete query;
        return;
    }

    ChatHandler cHandler(session);

    if (!query)
    {
        cHandler.SendSysMessage(LANG_ACCOUNT_LIST_EMPTY);
        return;
    }

    uint32 count = 0;
    AccountSearchHandler::ShowAccountListHelper(query, cHandler, count, limit, true);

    delete query;
}

void AccountSearchHandler::HandleAccountLookupResult(QueryResult* result, uint32 accountId, uint32 limit)
{
    sWorld.AddAsyncTask({AccountSearchDisplayTask(result, accountId, limit)});
}

void AccountSearchHandler::ShowAccountListHelper(QueryResult* result, ChatHandler& chatHandler, uint32& count, uint32 limit, bool title)
{
    ///- Display the list of account/characters online
    if (!chatHandler.GetSession() && title)                                // not output header for online case
    {
        chatHandler.SendSysMessage(LANG_ACCOUNT_LIST_BAR);
        chatHandler.SendSysMessage(LANG_ACCOUNT_LIST_HEADER);
        chatHandler.SendSysMessage(LANG_ACCOUNT_LIST_BAR);
    }

    ///- Circle through accounts
    AccountTypes sessionAccess = chatHandler.GetSession() ? chatHandler.GetSession()->GetSecurity() : SEC_CONSOLE;
    do
    {
        // check limit
        if (count == limit)
            break;

        Field* fields = result->Fetch();
        uint32 account = fields[0].GetUInt32();

        WorldSession* session = sWorld.FindSession(account);
        Player* player = session ? session->GetPlayer() : nullptr;
        char const* char_name = player ? player->GetName() : " - ";

        std::string lastIp = chatHandler.GetMangosString(LANG_ERROR);
        bool showIp = true;

        AccountTypes security = sAccountMgr.GetSecurity(account);
        if (sessionAccess < security)
            showIp = false;
        else if (sessionAccess < SEC_ADMINISTRATOR && security > SEC_PLAYER) // Only admins can see GM IPs
            showIp = false;

        if (showIp)
        {
            lastIp = fields[2].GetCppString();
        }
        else
        {
            lastIp = "-";
        }

        std::string acc_name = fields[1].GetCppString();
        if (sAccountMgr.IsAccountBanned(account))
            acc_name = acc_name + " [BANNED]";

        if (chatHandler.GetSession())
            chatHandler.PSendSysMessage(LANG_ACCOUNT_LIST_LINE_CHAT,
                account, acc_name.c_str(), char_name,
                chatHandler.playerLink(lastIp).c_str(),
                security, fields[4].GetUInt32());
        else
            chatHandler.PSendSysMessage(LANG_ACCOUNT_LIST_LINE_CONSOLE,
                account, acc_name.c_str(), char_name,
                chatHandler.playerLink(lastIp).c_str(),
                security, fields[4].GetUInt32());

        ++count;
    } while (result->NextRow());

    if (!chatHandler.GetSession())                                         // not output header for online case
        chatHandler.SendSysMessage(LANG_ACCOUNT_LIST_BAR);
}

// Not thread-safe. Executed inside thread-unsafe callback
void PlayerGoldRemovalHandler::HandleGoldLookupResult(QueryResult* result, uint32 accountId, uint32 removeAmount)
{
    WorldSession* session = sWorld.FindSession(accountId);
    if (!session)
    {
        delete result;
        return;
    }

    ChatHandler chatHandler(session);
    if (!result)
    {
        chatHandler.PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        return;
    }

    uint32 prevMoney = 0;
    uint32 newMoney = 0;
    uint32 guidLow = 0;
    Field* fields = result->Fetch();
    prevMoney = fields[0].GetUInt32();
    guidLow = fields[1].GetUInt32();
    std::string name(fields[2].GetString());

    if (removeAmount > prevMoney)
        newMoney = 0;
    else
        newMoney = prevMoney - removeAmount;
    // Wrap inside user serial or they might login while the query is in progress and all the gold is back
    CharacterDatabase.BeginTransaction(guidLow);
    auto res = CharacterDatabase.PExecute("UPDATE characters SET money = %u WHERE guid = '%u'", newMoney, guidLow);
    CharacterDatabase.CommitTransaction();

    if (!res)
    {
        chatHandler.PSendSysMessage("Encountered a database error during gold removal - see log for details");
        return;
    }

    chatHandler.PSendSysMessage("Removed %ug %us %uc from %s", removeAmount / GOLD, (removeAmount % GOLD) / SILVER, (removeAmount % GOLD) % SILVER, name.c_str());
    chatHandler.PSendSysMessage("%s previously had %ug %us %uc", name.c_str(), prevMoney / GOLD, (prevMoney % GOLD) / SILVER, (prevMoney % GOLD) % SILVER);
    chatHandler.PSendSysMessage("%s now has %ug %us %uc", name.c_str(), newMoney / GOLD, (newMoney % GOLD) / SILVER, (newMoney % GOLD) % SILVER);

    delete result;
}
