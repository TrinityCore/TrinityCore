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
#include "Database/DatabaseImpl.h"
#include "World.h"
#include "Player.h"
#include "SpellAuras.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "Language.h"
#include "AccountMgr.h"
#include "ObjectMgr.h"
#include "SystemConfig.h"
#include "Util.h"
#include "AsyncCommandHandlers.h"
#include "Anticheat.h"

bool ChatHandler::HandleAccountCommand(char* args)
{
    // let show subcommands at unexpected data in args
    if (*args)
        return false;

    AccountTypes gmlevel = GetAccessLevel();
    PSendSysMessage(LANG_ACCOUNT_LEVEL, uint32(gmlevel));
    return true;
}

 /// Set/Unset the expansion level for an account
bool ChatHandler::HandleAccountSetAddonCommand(char* args)
{
    ///- Get the command line arguments
    char* accountStr = ExtractOptNotLastArg(&args);

    std::string account_name;
    uint32 account_id = ExtractAccountId(&accountStr, &account_name);
    if (!account_id)
        return false;

    // Let set addon state only for lesser (strong) security level
    // or to self account
    if (GetAccountId() && GetAccountId() != account_id &&
        HasLowerSecurityAccount(nullptr, account_id, true))
        return false;

    uint32 lev;
    if (!ExtractUInt32(&args, lev))
        return false;

    // No SQL injection
    LoginDatabase.PExecute("UPDATE `account` SET `expansion` = '%u' WHERE `id` = '%u'", lev, account_id);
    PSendSysMessage(LANG_ACCOUNT_SETADDON, account_name.c_str(), account_id, lev);
    return true;
}

bool ChatHandler::HandleAccountSetGmLevelCommand(char* args)
{
    char* accountStr = ExtractOptNotLastArg(&args);

    std::string targetAccountName;
    Player* targetPlayer = nullptr;
    uint32 targetAccountId = ExtractAccountId(&accountStr, &targetAccountName, &targetPlayer);
    if (!targetAccountId)
        return false;

    /// only target player different from self allowed
    if (GetAccountId() == targetAccountId)
        return false;

    int32 gm;
    if (!ExtractInt32(&args, gm))
        return false;

    if (gm < SEC_PLAYER || gm > SEC_ADMINISTRATOR)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    /// can set security level only for target with less security and to less security that we have
    /// This is also reject self apply in fact
    if (HasLowerSecurityAccount(nullptr, targetAccountId, true))
        return false;

    /// account can't set security to same or grater level, need more power GM or console
    AccountTypes plSecurity = GetAccessLevel();
    if (AccountTypes(gm) >= plSecurity)
    {
        SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
        SetSentErrorMessage(true);
        return false;
    }

    if (targetPlayer)
    {
        ChatHandler(targetPlayer).PSendSysMessage(LANG_YOURS_SECURITY_CHANGED, GetNameLink().c_str(), gm);
        targetPlayer->GetSession()->SetSecurity(AccountTypes(gm));
    }

    PSendSysMessage(LANG_YOU_CHANGE_SECURITY, targetAccountName.c_str(), gm);
    sAccountMgr.SetSecurity(targetAccountId, AccountTypes(gm));

    return true;
}

/// Set password for account
bool ChatHandler::HandleAccountSetPasswordCommand(char* args)
{
    ///- Get the command line arguments
    std::string account_name;
    uint32 targetAccountId = ExtractAccountId(&args, &account_name);
    if (!targetAccountId)
        return false;

    // allow or quoted string with possible spaces or literal without spaces
    char *szPassword1 = ExtractQuotedOrLiteralArg(&args);
    char *szPassword2 = ExtractQuotedOrLiteralArg(&args);
    if (!szPassword1 || !szPassword2)
        return false;

    /// can set password only for target with less security
    /// This is also reject self apply in fact
    if (HasLowerSecurityAccount(nullptr, targetAccountId, true))
        return false;

    if (strcmp(szPassword1, szPassword2))
    {
        SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
        SetSentErrorMessage(true);
        return false;
    }

    AccountOpResult result = sAccountMgr.ChangePassword(targetAccountId, szPassword1);

    switch (result)
    {
        case AOR_OK:
            SendSysMessage(LANG_COMMAND_PASSWORD);
            break;
        case AOR_NAME_NOT_EXIST:
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        case AOR_PASS_TOO_LONG:
            SendSysMessage(LANG_PASSWORD_TOO_LONG);
            SetSentErrorMessage(true);
            return false;
        default:
            SendSysMessage(LANG_COMMAND_NOTCHANGEPASSWORD);
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

/// Set locked status for account
bool ChatHandler::HandleAccountSetLockedCommand(char* args)
{
    ///- Get the command line arguments
    char* accountStr = ExtractOptNotLastArg(&args);

    std::string account_name;
    uint32 account_id = ExtractAccountId(&accountStr, &account_name);
    if (!account_id)
        return false;

    // Let set locked state only for lesser (strong) security level
    // or to self account
    if (GetAccountId() && GetAccountId() != account_id &&
        HasLowerSecurityAccount(nullptr, account_id, true))
        return false;

    uint32 value;
    if (!ExtractUInt32(&args, value))
    {
        PSendSysMessage(LANG_SET_LOCK_USAGE);
        return false;
    }

    if (value < 16)
    {
        LoginDatabase.PExecute("UPDATE `account` SET `locked` = '%u' WHERE `id` = '%u'", value, account_id);
        PSendSysMessage(LANG_SET_LOCK_SUCCESS, account_name.c_str(), account_id, value);
    }
    else
    {
        PSendSysMessage(LANG_SET_LOCK_USAGE);
        return false;
    }

    return true;
}

/// Output list of character for account
bool ChatHandler::HandleAccountCharactersCommand(char* args)
{
    ///- Get the command line arguments
    std::string account_name;
    Player* target = nullptr;                                  // only for triggering use targeted player account
    uint32 account_id = ExtractAccountId(&args, &account_name, &target);
    if (!account_id)
        return false;

    ///- Get the characters for account id
    CharacterDatabase.AsyncPQuery(&PlayerSearchHandler::HandlePlayerCharacterLookupResult,
        GetAccountId(), 100u,
        "SELECT `guid`, `name`, `race`, `class`, `level` FROM `characters` WHERE `account` = %u",
        account_id);

    return true;
}

/// Create an account
bool ChatHandler::HandleAccountCreateCommand(char* args)
{
    ///- %Parse the command line arguments
    char *szAcc = ExtractQuotedOrLiteralArg(&args);
    char *szPassword = ExtractQuotedOrLiteralArg(&args);
    if (!szAcc || !szPassword)
        return false;

    // normalized in accmgr.CreateAccount
    std::string account_name = szAcc;
    std::string password = szPassword;

    AccountOpResult result = sAccountMgr.CreateAccount(account_name, password);
    switch(result)
    {
        case AOR_OK:
            PSendSysMessage(LANG_ACCOUNT_CREATED,account_name.c_str());
            break;
        case AOR_NAME_TOO_LONG:
            SendSysMessage(LANG_ACCOUNT_TOO_LONG);
            SetSentErrorMessage(true);
            return false;
        case AOR_NAME_ALREDY_EXIST:
            SendSysMessage(LANG_ACCOUNT_ALREADY_EXIST);
            SetSentErrorMessage(true);
            return false;
        case AOR_DB_INTERNAL_ERROR:
            PSendSysMessage(LANG_ACCOUNT_NOT_CREATED_SQL_ERROR,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        default:
            PSendSysMessage(LANG_ACCOUNT_NOT_CREATED,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

/// Delete a user account and all associated characters in this realm
/// \todo This function has to be enhanced to respect the login/realm split (delete char, delete account chars in realm, delete account chars in realm then delete account
bool ChatHandler::HandleAccountDeleteCommand(char* args)
{
    if (!*args)
        return false;

    std::string account_name;
    uint32 account_id = ExtractAccountId(&args, &account_name);
    if (!account_id)
        return false;

    /// Commands not recommended call from chat, but support anyway
    /// can delete only for account with less security
    /// This is also reject self apply in fact
    if (HasLowerSecurityAccount (nullptr, account_id, true))
        return false;

    AccountOpResult result = sAccountMgr.DeleteAccount(account_id);
    switch(result)
    {
        case AOR_OK:
            PSendSysMessage(LANG_ACCOUNT_DELETED,account_name.c_str());
            break;
        case AOR_NAME_NOT_EXIST:
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        case AOR_DB_INTERNAL_ERROR:
            PSendSysMessage(LANG_ACCOUNT_NOT_DELETED_SQL_ERROR,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        default:
            PSendSysMessage(LANG_ACCOUNT_NOT_DELETED,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

/// Display info on users currently in the realm
bool ChatHandler::HandleAccountOnlineListCommand(char* args)
{
    uint32 limit;
    if (!ExtractOptUInt32(&args, limit, 100))
        return false;

    ///- Get the list of accounts ID logged to the realm
    //                                                  0     1           2          3          4
    QueryResult* result = LoginDatabase.PQuery("SELECT `id`, `username`, `last_ip`, `gmlevel`, `expansion` FROM `account` WHERE `current_realm` = %u LIMIT %u", realmID, limit);
    if (!result)
    {
        SendSysMessage(LANG_ACCOUNT_LIST_EMPTY);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 count = 0;
    AccountSearchHandler::ShowAccountListHelper(result, *this, count, limit, true);
    delete result;
    return true;
}

bool ChatHandler::HandleAccountLockCommand(char* args)
{
    // allow use from RA, but not from console (not have associated account id)
    if (!GetAccountId())
    {
        SendSysMessage(LANG_RA_ONLY_COMMAND);
        SetSentErrorMessage(true);
        return false;
    }

    bool value;
    if (!ExtractOnOff(&args, value))
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    if (value)
    {
        LoginDatabase.PExecute("UPDATE `account` SET `locked` = '1' WHERE `id` = '%u'", GetAccountId());
        PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
    }
    else
    {
        LoginDatabase.PExecute("UPDATE `account` SET `locked` = '0' WHERE `id` = '%u'", GetAccountId());
        PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);
    }

    return true;
}

bool ChatHandler::HandleAccountPasswordCommand(char* args)
{
    // allow use from RA, but not from console (not have associated account id)
    if (!GetAccountId())
    {
        SendSysMessage(LANG_RA_ONLY_COMMAND);
        SetSentErrorMessage(true);
        return false;
    }

    // allow or quoted string with possible spaces or literal without spaces
    char *old_pass = ExtractQuotedOrLiteralArg(&args);
    char *new_pass = ExtractQuotedOrLiteralArg(&args);
    char *new_pass_c = ExtractQuotedOrLiteralArg(&args);

    if (!old_pass || !new_pass || !new_pass_c)
        return false;

    std::string password_old = old_pass;
    std::string password_new = new_pass;
    std::string password_new_c = new_pass_c;

    if (password_new != password_new_c)
    {
        SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
        SetSentErrorMessage(true);
        return false;
    }

    if (!sAccountMgr.CheckPassword(GetAccountId(), password_old, m_session->GetUsername()))
    {
        SendSysMessage(LANG_COMMAND_WRONGOLDPASSWORD);
        SetSentErrorMessage(true);
        return false;
    }

    AccountOpResult result = sAccountMgr.ChangePassword(GetAccountId(), password_new, m_session->GetUsername());

    switch (result)
    {
        case AOR_OK:
            SendSysMessage(LANG_COMMAND_PASSWORD);
            break;
        case AOR_PASS_TOO_LONG:
            SendSysMessage(LANG_PASSWORD_TOO_LONG);
            SetSentErrorMessage(true);
            return false;
        case AOR_NAME_NOT_EXIST:                            // not possible case, don't want get account name for output
        default:
            SendSysMessage(LANG_COMMAND_NOTCHANGEPASSWORD);
            SetSentErrorMessage(true);
            return false;
    }
    SetSentErrorMessage(true);
    return false;
}

bool ChatHandler::HandleAddCharacterNoteCommand(char* args)
{
    ObjectGuid playerGuid;
    if (!ExtractPlayerTarget(&args, nullptr, &playerGuid))
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }
    PlayerCacheData const* playerData = sObjectMgr.GetPlayerDataByGUID(playerGuid.GetCounter());
    if (!playerData)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }
    std::string authorName = m_session ? m_session->GetPlayerName() : "Console";
    char const* reason = ExtractQuotedOrLiteralArg(&args);
    if (!reason)
        reason = "<no reason given>";

    sWorld.WarnAccount(playerData->uiAccount, authorName, reason, "NOTE");

    PSendSysMessage("Account #%u (character %s): a note has been added \"%s\"", playerData->uiAccount, playerData->sName.c_str(), reason);
    return true;
}

bool ChatHandler::HandleWarnCharacterCommand(char* args)
{
    ObjectGuid playerGuid;
    if (!ExtractPlayerTarget(&args, nullptr, &playerGuid))
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }
    PlayerCacheData const* playerData = sObjectMgr.GetPlayerDataByGUID(playerGuid.GetCounter());
    if (!playerData)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }
    std::string authorName = m_session ? m_session->GetPlayerName() : "Console";
    char const* reason = ExtractQuotedOrLiteralArg(&args);
    if (!reason)
        reason = "<no reason given>";

    sWorld.WarnAccount(playerData->uiAccount, authorName, reason, "WARN");

    PSendSysMessage("Account #%u (character %s) has been warned for \"%s\"", playerData->uiAccount, playerData->sName.c_str(), reason);
    return true;
}

bool ChatHandler::HandleKickPlayerCommand(char *args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    if (m_session && target == m_session->GetPlayer())
    {
        SendSysMessage(LANG_COMMAND_KICKSELF);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target))
        return false;

    // send before target pointer invalidate
    PSendSysMessage(LANG_COMMAND_KICKMESSAGE, GetNameLink(target).c_str());
    // First kick: close socket but keep player online
    if (target->GetSession()->IsConnected())
        target->GetSession()->KickPlayer();
    else
        target->GetSession()->KickDisconnectedFromWorld();
    return true;
}

bool ChatHandler::HandleBanAccountCommand(char* args)
{
    return HandleBanHelper(BAN_ACCOUNT, args);
}

bool ChatHandler::HandleBanCharacterCommand(char* args)
{
    return HandleBanHelper(BAN_CHARACTER, args);
}

bool ChatHandler::HandleBanIPCommand(char* args)
{
    return HandleBanHelper(BAN_IP, args);
}

bool ChatHandler::HandleBanAllIPCommand(char* args)
{
    char* ipStr = ExtractQuotedOrLiteralArg(&args);
    if (!ipStr)
        return false;

    char const* reason = ExtractQuotedOrLiteralArg(&args);
    if (!reason)
        reason = "<no reason given>";

    uint32 maxLevel = 10;
    uint32 minId = GetAccessLevel() < SEC_ADMINISTRATOR ? 100 : 0; // Don't show GM accounts

    std::string ip = ipStr;
    LoginDatabase.escape_string(ip);
    QueryResult* result = LoginDatabase.PQuery("SELECT `id`, `username` FROM `account` WHERE `id` >= %u AND `last_ip` " _LIKE_ " " _CONCAT2_("'%s'", "'%%'"), minId, ip.c_str());
    if (!result)
    {
        PSendSysMessage("No account found on IP '%s'", ip.c_str());
        SetSentErrorMessage(true);
        return false;
    }
    std::set<uint32> accountsToBan;
    std::map<uint32, std::string> accountsIdToName;
    std::stringstream allAccounts;
    do
    {
        Field* fields = result->Fetch();
        if (!allAccounts.str().empty())
            allAccounts << ",";
        allAccounts << fields[0].GetUInt32();
        accountsToBan.insert(fields[0].GetUInt32());
        accountsIdToName[fields[0].GetUInt32()] = fields[1].GetCppString();
    } while (result->NextRow());

    delete result;
    if (result = CharacterDatabase.PQuery("SELECT `account` FROM `characters` WHERE `account` IN (%s) AND `level` > %u GROUP BY `account`", allAccounts.str().c_str(), maxLevel))
    {
        do
        {
            Field* fields = result->Fetch();
            accountsToBan.erase(fields[0].GetUInt32());
        } while (result->NextRow());
        delete result;
    }

    uint32 bannedCount = 0;
    for (const auto it : accountsToBan)
    {
        if (sAccountMgr.IsAccountBanned(it))
            continue;
        sWorld.BanAccount(BAN_ACCOUNT, accountsIdToName[it], 0, reason, m_session ? m_session->GetPlayerName() : "");
        PSendSysMessage("Account '%s' permanently banned.", accountsIdToName[it].c_str(), reason);
        ++bannedCount;
    }
    PSendSysMessage("%u accounts banned for %s (%u on this IP)", bannedCount, reason, accountsIdToName.size());
    return true;
}

bool ChatHandler::HandleBanHelper(BanMode mode, char* args)
{
    if (!*args)
        return false;

    char* cnameOrIP = ExtractArg(&args);
    if (!cnameOrIP)
        return false;

    std::string nameOrIP = cnameOrIP;

    char* duration = ExtractArg(&args);                     // time string
    if (!duration)
        return false;

    uint32 duration_secs = TimeStringToSecs(duration);

    char* cReason = ExtractArg(&args);
    if (!cReason)
        return false;

    std::string reason(cReason);

    switch (mode)
    {
        case BAN_ACCOUNT:
            if (!AccountMgr::normalizeString(nameOrIP))
            {
                PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, nameOrIP.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            break;
        case BAN_CHARACTER:
            if (!normalizePlayerName(nameOrIP))
            {
                SendSysMessage(LANG_PLAYER_NOT_FOUND);
                SetSentErrorMessage(true);
                return false;
            }
            break;
        case BAN_IP:
            if (!IsIPAddress(nameOrIP.c_str()))
                return false;
            break;
    }

    sWorld.BanAccount(mode, nameOrIP, duration_secs, reason, m_session ? m_session->GetPlayerName() : "");

    return true;
}

void ChatHandler::SendBanResult(BanMode mode, BanReturn result, std::string& banTarget, uint32 duration_secs, std::string& reason)
{
    switch (result)
    {
        case BAN_SUCCESS:
            if (duration_secs > 0)
                PSendSysMessage(LANG_BAN_YOUBANNED, banTarget.c_str(), secsToTimeString(duration_secs, true).c_str(), reason.c_str());
            else
                PSendSysMessage(LANG_BAN_YOUPERMBANNED, banTarget.c_str(), reason.c_str());
            break;
        case BAN_SYNTAX_ERROR:
            return;
        case BAN_NOTFOUND:
            switch (mode)
            {
                default:
                    PSendSysMessage(LANG_BAN_NOTFOUND, "account", banTarget.c_str());
                    break;
                case BAN_CHARACTER:
                    PSendSysMessage(LANG_BAN_NOTFOUND, "character", banTarget.c_str());
                    break;
                case BAN_IP:
                    PSendSysMessage(LANG_BAN_NOTFOUND, "ip", banTarget.c_str());
                    break;
            }
            SetSentErrorMessage(true);
            return;
    }
}

bool ChatHandler::HandleUnBanAccountCommand(char* args)
{
    return HandleUnBanHelper(BAN_ACCOUNT, args);
}

bool ChatHandler::HandleUnBanCharacterCommand(char* args)
{
    return HandleUnBanHelper(BAN_CHARACTER, args);
}

bool ChatHandler::HandleUnBanIPCommand(char* args)
{
    return HandleUnBanHelper(BAN_IP, args);
}

bool ChatHandler::HandleUnBanHelper(BanMode mode, char* args)
{
    if (!*args)
        return false;

    char* cnameOrIP = ExtractArg(&args);
    if (!cnameOrIP)
        return false;

    std::string nameOrIP = cnameOrIP;

    char* message = ExtractQuotedOrLiteralArg(&args);
    if (!message)
        return false;

    std::string unbanMessage(message);

    switch (mode)
    {
        case BAN_ACCOUNT:
            if (!AccountMgr::normalizeString(nameOrIP))
            {
                PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, nameOrIP.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            break;
        case BAN_CHARACTER:
            if (!normalizePlayerName(nameOrIP))
            {
                SendSysMessage(LANG_PLAYER_NOT_FOUND);
                SetSentErrorMessage(true);
                return false;
            }
            break;
        case BAN_IP:
            if (!IsIPAddress(nameOrIP.c_str()))
                return false;
            break;
    }

    std::string source = m_session ? m_session->GetPlayerName() : "CONSOLE";

    if (sWorld.RemoveBanAccount(mode, source, unbanMessage, nameOrIP))
        PSendSysMessage(LANG_UNBAN_UNBANNED, nameOrIP.c_str(), unbanMessage.c_str());
    else
        PSendSysMessage(LANG_UNBAN_ERROR, nameOrIP.c_str());

    return true;
}

bool ChatHandler::HandleBanInfoAccountCommand(char* args)
{
    if (!*args)
        return false;

    std::string account_name;
    uint32 accountid = ExtractAccountId(&args, &account_name);
    if (!accountid)
        return false;

    return HandleBanInfoHelper(accountid, account_name.c_str());
}

bool ChatHandler::HandleBanInfoCharacterCommand(char* args)
{
    Player* target;
    ObjectGuid target_guid;
    if (!ExtractPlayerTarget(&args, &target, &target_guid,nullptr,true))
        return false;

    uint32 accountid = target ? target->GetSession()->GetAccountId() : sObjectMgr.GetPlayerAccountIdByGUID(target_guid);

    std::string accountname;
    if (!sAccountMgr.GetName(accountid, accountname))
    {
        PSendSysMessage(LANG_BANINFO_NOCHARACTER);
        return true;
    }

    return HandleBanInfoHelper(accountid, accountname.c_str());
}

bool ChatHandler::HandleBanInfoHelper(uint32 accountid, char const* accountname)
{
    QueryResult* result = LoginDatabase.PQuery(
    "SELECT FROM_UNIXTIME(`bandate`), `unbandate`-`bandate`, `active`, `unbandate`,`banreason`,`bannedby`,COALESCE(`name`, \"NoRealm\") , `gmlevel` "
    "FROM `account_banned` LEFT JOIN `realmlist` ON `realmlist`.`id` = `realm` "
    "WHERE `account_banned`.`id` = '%u' ORDER BY `bandate` ASC", accountid);
    if (!result)
    {
        PSendSysMessage(LANG_BANINFO_NOACCOUNTBAN, accountname);
        return true;
    }

    PSendSysMessage(LANG_BANINFO_BANHISTORY, accountname);
    do
    {
        Field* fields = result->Fetch();

        time_t unbandate = time_t(fields[3].GetUInt64());
        bool active = false;
        if (fields[2].GetBool() && (fields[1].GetUInt64() == (uint64)0 || unbandate >= time(nullptr)))
            active = true;
        bool permanent = (fields[1].GetUInt64() == (uint64)0);
        uint32 reqGmLevel = fields[6].GetUInt8();
        std::string banreason = fields[4].GetString();
        if (reqGmLevel > uint8(GetAccessLevel()))
            banreason = "<hidden>";

        std::string authorName = fields[5].GetCppString() + " (" + fields[6].GetCppString() + ")";
        std::string bantime = permanent ? GetMangosString(LANG_BANINFO_INFINITE) : secsToTimeString(fields[1].GetUInt64(), true);
        PSendSysMessage(LANG_BANINFO_HISTORYENTRY,
                        fields[0].GetString(), bantime.c_str(), active ? GetMangosString(LANG_BANINFO_YES) : GetMangosString(LANG_BANINFO_NO), banreason.c_str(), authorName.c_str());
    }
    while (result->NextRow());

    delete result;
    return true;
}

bool ChatHandler::HandleBanInfoIPCommand(char* args)
{
    if (!*args)
        return false;

    char* cIP = ExtractQuotedOrLiteralArg(&args);
    if (!cIP)
        return false;

    if (!IsIPAddress(cIP))
        return false;

    std::string IP = cIP;

    LoginDatabase.escape_string(IP);
    QueryResult* result = LoginDatabase.PQuery("SELECT `ip`, FROM_UNIXTIME(`bandate`), FROM_UNIXTIME(`unbandate`), `unbandate`-UNIX_TIMESTAMP(), `banreason`,`bannedby`,`unbandate`-`bandate` FROM `ip_banned` WHERE `ip` = '%s'", IP.c_str());
    if (!result)
    {
        PSendSysMessage(LANG_BANINFO_NOIP);
        return true;
    }

    Field* fields = result->Fetch();
    bool permanent = !fields[6].GetUInt64();
    PSendSysMessage(LANG_BANINFO_IPENTRY,
                    fields[0].GetString(), fields[1].GetString(), permanent ? GetMangosString(LANG_BANINFO_NEVER) : fields[2].GetString(),
                    permanent ? GetMangosString(LANG_BANINFO_INFINITE) : secsToTimeString(fields[3].GetUInt64(), true).c_str(), fields[4].GetString(), fields[5].GetString());
    delete result;
    return true;
}

bool ChatHandler::HandleBanListCharacterCommand(char* args)
{
    LoginDatabase.Execute("DELETE FROM `ip_banned` WHERE `unbandate`<=UNIX_TIMESTAMP() AND `unbandate`<>`bandate`");

    char* cFilter = ExtractLiteralArg(&args);
    if (!cFilter)
        return false;

    std::string filter = cFilter;
    CharacterDatabase.escape_string(filter);
    QueryResult* result = CharacterDatabase.PQuery("SELECT `account` FROM `characters` WHERE `name` " _LIKE_ " " _CONCAT2_("'%s'", "'%%'"), filter.c_str());
    if (!result)
    {
        PSendSysMessage(LANG_BANLIST_NOCHARACTER);
        return true;
    }

    return HandleBanListHelper(result);
}

bool ChatHandler::HandleBanListAccountCommand(char* args)
{
    LoginDatabase.Execute("DELETE FROM `ip_banned` WHERE `unbandate`<=UNIX_TIMESTAMP() AND `unbandate`<>`bandate`");

    char* cFilter = ExtractLiteralArg(&args);
    std::string filter = cFilter ? cFilter : "";
    LoginDatabase.escape_string(filter);

    QueryResult* result;

    if (filter.empty())
    {
        result = LoginDatabase.Query("SELECT `account`.`id`, `username` FROM `account`, `account_banned`"
                                     " WHERE `account`.`id` = `account_banned`.`id` AND `active` = 1 GROUP BY `account`.`id`");
    }
    else
    {
        result = LoginDatabase.PQuery("SELECT `account`.`id`, `username` FROM `account`, `account_banned`"
                                      " WHERE `account`.`id` = `account_banned`.`id` AND `active` = 1 AND `username` " _LIKE_ " " _CONCAT2_("'%s'", "'%%'") " GROUP BY `account`.`id`",
                                      filter.c_str());
    }

    if (!result)
    {
        PSendSysMessage(LANG_BANLIST_NOACCOUNT);
        return true;
    }

    return HandleBanListHelper(result);
}

bool ChatHandler::HandleBanListHelper(QueryResult* result)
{
    PSendSysMessage(LANG_BANLIST_MATCHINGACCOUNT);

    // Chat short output
    if (m_session)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 accountid = fields[0].GetUInt32();

            QueryResult* banresult = LoginDatabase.PQuery("SELECT `account`.`username` FROM `account`,`account_banned` WHERE `account_banned`.`id`='%u' AND `account_banned`.`id`=`account`.`id`", accountid);
            if (banresult)
            {
                Field* fields2 = banresult->Fetch();
                PSendSysMessage("%s", fields2[0].GetString());
                delete banresult;
            }
        }
        while (result->NextRow());
    }
    // Console wide output
    else
    {
        SendSysMessage(LANG_BANLIST_ACCOUNTS);
        SendSysMessage("===============================================================================");
        SendSysMessage(LANG_BANLIST_ACCOUNTS_HEADER);
        do
        {
            SendSysMessage("-------------------------------------------------------------------------------");
            Field* fields = result->Fetch();
            uint32 account_id = fields[0].GetUInt32();

            std::string account_name;

            // "account" case, name can be get in same query
            if (result->GetFieldCount() > 1)
                account_name = fields[1].GetCppString();
            // "character" case, name need extract from another DB
            else
                sAccountMgr.GetName(account_id, account_name);

            // No SQL injection. id is uint32.
            QueryResult* banInfo = LoginDatabase.PQuery("SELECT `bandate`,`unbandate`,`bannedby`,`banreason` FROM `account_banned` WHERE `id` = %u ORDER BY `unbandate`", account_id);
            if (banInfo)
            {
                Field* fields2 = banInfo->Fetch();
                do
                {
                    time_t t_ban = fields2[0].GetUInt64();
                    tm* aTm_ban = localtime(&t_ban);

                    if (fields2[0].GetUInt64() == fields2[1].GetUInt64())
                    {
                        PSendSysMessage("|%-15.15s|%02d-%02d-%02d %02d:%02d|   permanent  |%-15.15s|%-15.15s|",
                                        account_name.c_str(), aTm_ban->tm_year % 100, aTm_ban->tm_mon + 1, aTm_ban->tm_mday, aTm_ban->tm_hour, aTm_ban->tm_min,
                                        fields2[2].GetString(), fields2[3].GetString());
                    }
                    else
                    {
                        time_t t_unban = fields2[1].GetUInt64();
                        tm* aTm_unban = localtime(&t_unban);
                        PSendSysMessage("|%-15.15s|%02d-%02d-%02d %02d:%02d|%02d-%02d-%02d %02d:%02d|%-15.15s|%-15.15s|",
                                        account_name.c_str(), aTm_ban->tm_year % 100, aTm_ban->tm_mon + 1, aTm_ban->tm_mday, aTm_ban->tm_hour, aTm_ban->tm_min,
                                        aTm_unban->tm_year % 100, aTm_unban->tm_mon + 1, aTm_unban->tm_mday, aTm_unban->tm_hour, aTm_unban->tm_min,
                                        fields2[2].GetString(), fields2[3].GetString());
                    }
                }
                while (banInfo->NextRow());
                delete banInfo;
            }
        }
        while (result->NextRow());
        SendSysMessage("===============================================================================");
    }

    delete result;
    return true;
}

bool ChatHandler::HandleBanListIPCommand(char* args)
{
    LoginDatabase.Execute("DELETE FROM `ip_banned` WHERE `unbandate`<=UNIX_TIMESTAMP() AND `unbandate`<>`bandate`");

    char* cFilter = ExtractLiteralArg(&args);
    std::string filter = cFilter ? cFilter : "";
    LoginDatabase.escape_string(filter);

    QueryResult* result;

    if (filter.empty())
    {
        result = LoginDatabase.Query("SELECT `ip`,`bandate`,`unbandate`,`bannedby`,`banreason` FROM `ip_banned`"
                                     " WHERE (`bandate`=`unbandate` OR `unbandate`>UNIX_TIMESTAMP())"
                                     " ORDER BY `unbandate`");
    }
    else
    {
        result = LoginDatabase.PQuery("SELECT `ip`,`bandate`,`unbandate`,`bannedby`,`banreason` FROM `ip_banned`"
                                      " WHERE (`bandate`=`unbandate` OR `unbandate`>UNIX_TIMESTAMP()) AND `ip` " _LIKE_ " " _CONCAT2_("'%s'", "'%%'")
                                      " ORDER BY `unbandate`", filter.c_str());
    }

    if (!result)
    {
        PSendSysMessage(LANG_BANLIST_NOIP);
        return true;
    }

    PSendSysMessage(LANG_BANLIST_MATCHINGIP);
    // Chat short output
    if (m_session)
    {
        do
        {
            Field* fields = result->Fetch();
            PSendSysMessage("%s", fields[0].GetString());
        }
        while (result->NextRow());
    }
    // Console wide output
    else
    {
        SendSysMessage(LANG_BANLIST_IPS);
        SendSysMessage("===============================================================================");
        SendSysMessage(LANG_BANLIST_IPS_HEADER);
        do
        {
            SendSysMessage("-------------------------------------------------------------------------------");
            Field* fields = result->Fetch();
            time_t t_ban = fields[1].GetUInt64();
            tm* aTm_ban = localtime(&t_ban);
            if (fields[1].GetUInt64() == fields[2].GetUInt64())
            {
                PSendSysMessage("|%-15.15s|%02d-%02d-%02d %02d:%02d|   permanent  |%-15.15s|%-15.15s|",
                                fields[0].GetString(), aTm_ban->tm_year % 100, aTm_ban->tm_mon + 1, aTm_ban->tm_mday, aTm_ban->tm_hour, aTm_ban->tm_min,
                                fields[3].GetString(), fields[4].GetString());
            }
            else
            {
                time_t t_unban = fields[2].GetUInt64();
                tm* aTm_unban = localtime(&t_unban);
                PSendSysMessage("|%-15.15s|%02d-%02d-%02d %02d:%02d|%02d-%02d-%02d %02d:%02d|%-15.15s|%-15.15s|",
                                fields[0].GetString(), aTm_ban->tm_year % 100, aTm_ban->tm_mon + 1, aTm_ban->tm_mday, aTm_ban->tm_hour, aTm_ban->tm_min,
                                aTm_unban->tm_year % 100, aTm_unban->tm_mon + 1, aTm_unban->tm_mday, aTm_unban->tm_hour, aTm_unban->tm_min,
                                fields[3].GetString(), fields[4].GetString());
            }
        }
        while (result->NextRow());
        SendSysMessage("===============================================================================");
    }

    delete result;
    return true;
}

bool ChatHandler::HandleAnticheatCommand(char* args)
{
    Player* player = nullptr;
    if (!ExtractPlayerTarget(&args, &player) && m_session)
        player = m_session->GetPlayer();
    if (!player)
        return false;

    PSendSysMessage("Cheat report on player '%s' (GUID %u)", player->GetName(), player->GetGUIDLow());
    if (player->GetCheatData())
        player->GetCheatData()->HandleCommand(this);

    return true;
}

bool ChatHandler::HandleListAddonsCommand(char* args)
{
    Player* player = GetSelectedPlayer();
    if (!player)
        return false;

    std::set<std::string> const& addons = player->GetSession()->GetAddons();
    PSendSysMessage("%u addons on target.", addons.size());
    for (const auto& addon : addons)
        PSendSysMessage(">> %s", addon.c_str());
    return true;
}

bool ChatHandler::HandleClientInfosCommand(char* args)
{
    Player* player = nullptr;
    if (!ExtractPlayerTarget(&args, &player) && m_session)
        player = m_session->GetPlayer();
    if (!player)
        return false;

    PSendSysMessage("Account %s has %u client identifiers.", player->GetSession()->GetUsername().c_str(), player->GetSession()->GetClientIdentifiers().size());
    for (const auto& it : player->GetSession()->GetClientIdentifiers())
        PSendSysMessage("%u: %s", it.first, it.second.c_str());
    player->GetSession()->ComputeClientHash();
    PSendSysMessage("Hash is %s", playerLink(player->GetSession()->GetClientHash()).c_str());
    return true;
}

bool ChatHandler::HandleClientSearchCommand(char* args)
{
    ASSERT(args);
    std::string searchedHash = args;
    uint32 i = 0;
    World::SessionMap const& sessMap = sWorld.GetAllSessions();
    for (const auto& itr : sessMap)
    {
        if (!itr.second)
            continue;

        std::string currentHash = itr.second->GetClientHash();
        if (currentHash.find(searchedHash) != std::string::npos)
        {
            PSendSysMessage("%s on account %s, %s",
                            playerLink(itr.second->GetPlayerName()).c_str(),
                            playerLink(itr.second->GetUsername()).c_str(),
                            playerLink(itr.second->GetRemoteAddress()).c_str());
            ++i;
        }
    }
    if (i == 0)
        PSendSysMessage("Not result for hash %s", playerLink(searchedHash).c_str());
    else
        PSendSysMessage("%u result(s) for %s", i, playerLink(searchedHash).c_str());
    return true;
}

bool ChatHandler::HandleSpamerMute(char* args)
{
    if (!*args)
        return false;

    char* cname = ExtractArg(&args);
    if (!cname)
        return false;

    if (Player* player = ObjectAccessor::FindPlayerByName(cname))
    {
        if (AntispamInterface *a = sAnticheatMgr->GetAntispam())
        {
            a->mute(player->GetSession()->GetAccountId());
            PSendSysMessage("Spamer %s was muted", cname);
        }
    }

    return true;
}

bool ChatHandler::HandleSpamerUnmute(char* args)
{
    if (!*args)
        return false;

    char* cname = ExtractArg(&args);
    if (!cname)
        return false;

    if (Player* player = ObjectAccessor::FindPlayerByName(cname))
    {
        if (AntispamInterface *a = sAnticheatMgr->GetAntispam())
        {
            a->unmute(player->GetSession()->GetAccountId());
            PSendSysMessage("Spamer %s was unmuted", cname);
        }
    }

    return true;
}

bool ChatHandler::HandleSpamerList(char* args)
{
    if (AntispamInterface *a = sAnticheatMgr->GetAntispam())
        a->showMuted(GetSession());
    return true;
}

//mute player for some times
bool ChatHandler::HandleMuteCommand(char* args)
{
    char* nameStr = ExtractOptNotLastArg(&args);

    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&nameStr, &target, &target_guid, &target_name))
        return false;

    uint32 notspeaktime;
    if (!ExtractUInt32(&args, notspeaktime))
        return false;

    std::string givenReason;
    if (char* givenReasonC = ExtractQuotedOrLiteralArg(&args))
        givenReason = givenReasonC;

    uint32 account_id = target ? target->GetSession()->GetAccountId() : sObjectMgr.GetPlayerAccountIdByGUID(target_guid);

    // find only player from same account if any
    if (!target)
    {
        if (WorldSession* session = sWorld.FindSession(account_id))
            target = session->GetPlayer();
    }

    // must have strong lesser security level
    if (HasLowerSecurity(target, target_guid, true))
        return false;

    time_t mutetime = time(nullptr) + notspeaktime * MINUTE;

    if (target)
        target->GetSession()->m_muteTime = mutetime;

    LoginDatabase.PExecute("UPDATE `account` SET `mutetime` = " UI64FMTD " WHERE `id` = '%u'", uint64(mutetime), account_id);

    if (target)
    {
        if (SpellAuraHolder* pAura = target->AddAura(SPELL_PLAYER_MUTED_VISUAL, 0, nullptr))
        {
            pAura->SetAuraDuration(notspeaktime * MINUTE * IN_MILLISECONDS);
            pAura->SetAuraMaxDuration(notspeaktime * MINUTE * IN_MILLISECONDS);
            pAura->RefreshHolder();
        }
            
        ChatHandler(target).PSendSysMessage(LANG_YOUR_CHAT_DISABLED, notspeaktime);
    }

    std::string nameLink = playerLink(target_name);

    PSendSysMessage(LANG_YOU_DISABLE_CHAT, nameLink.c_str(), notspeaktime);

    // Add warning to the account
    std::string authorName = m_session ? m_session->GetPlayerName() : "Console";
    PlayerCacheData const* playerData = sObjectMgr.GetPlayerDataByGUID(target_guid);
    ASSERT(playerData);
    std::stringstream reason;
    reason << playerData->sName << " muted " << notspeaktime << " minutes";
    if (!givenReason.empty())
        reason << " for \"" << givenReason << "\"";
    sWorld.WarnAccount(playerData->uiAccount, authorName, reason.str(), "WARNING");
    return true;
}

//unmute player
bool ChatHandler::HandleUnmuteCommand(char* args)
{
    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&args, &target, &target_guid, &target_name))
        return false;

    uint32 account_id = target ? target->GetSession()->GetAccountId() : sObjectMgr.GetPlayerAccountIdByGUID(target_guid);

    // find only player from same account if any
    if (!target)
    {
        if (WorldSession* session = sWorld.FindSession(account_id))
            target = session->GetPlayer();
    }

    // must have strong lesser security level
    if (HasLowerSecurity(target, target_guid, true))
        return false;

    if (target)
    {
        if (target->CanSpeak())
        {
            SendSysMessage(LANG_CHAT_ALREADY_ENABLED);
            SetSentErrorMessage(true);
            return false;
        }

        target->GetSession()->m_muteTime = 0;
    }

    LoginDatabase.PExecute("UPDATE `account` SET `mutetime` = '0' WHERE `id` = '%u'", account_id);

    if (target)
    {
        target->RemoveAurasDueToSpell(SPELL_PLAYER_MUTED_VISUAL);
        ChatHandler(target).PSendSysMessage(LANG_YOUR_CHAT_ENABLED);
    } 

    std::string nameLink = playerLink(target_name);

    PSendSysMessage(LANG_YOU_ENABLE_CHAT, nameLink.c_str());
    return true;
}