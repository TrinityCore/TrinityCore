/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "DatabaseEnv.h"
#include "AccountMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Util.h"
#include "SHA1.h"

namespace AccountMgr
{

AccountOpResult CreateAccount(std::string username, std::string password)
{
    if (utf8length(username) > MAX_ACCOUNT_STR)
        return AOR_NAME_TOO_LONG;                           // username's too long

    normalizeString(username);
    normalizeString(password);

    if (GetId(username))
        return AOR_NAME_ALREDY_EXIST;                       // username does already exist

    LoginDatabase.PExecute("INSERT INTO account(username, sha_pass_hash, joindate) VALUES('%s', '%s', NOW())", username.c_str(), CalculateShaPassHash(username, password).c_str());
    LoginDatabase.Execute("INSERT INTO realmcharacters (realmid, acctid, numchars) SELECT realmlist.id, account.id, 0 FROM realmlist, account LEFT JOIN realmcharacters ON acctid=account.id WHERE acctid IS NULL");

    return AOR_OK;                                          // everything's fine
}

AccountOpResult DeleteAccount(uint32 accountId)
{
    QueryResult result = LoginDatabase.PQuery("SELECT 1 FROM account WHERE id='%d'", accountId);
    if (!result)
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist

    // existed characters list
    result = CharacterDatabase.PQuery("SELECT guid FROM characters WHERE account='%d'", accountId);
    if (result)
    {
        do
        {
            uint32 guidLow = (*result)[0].GetUInt32();
            uint64 guid = MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER);

            // kick if player is online
            if (Player* p = ObjectAccessor::FindPlayer(guid))
            {
                WorldSession* s = p->GetSession();
                s->KickPlayer();                            // mark session to remove at next session list update
                s->LogoutPlayer(false);                     // logout player without waiting next session list update
            }

            Player::DeleteFromDB(guid, accountId, false);       // no need to update realm characters
        } while (result->NextRow());
    }

    // table realm specific but common for all characters of account for realm
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_TUTORIALS);
    stmt->setUInt32(0, accountId);
    CharacterDatabase.Execute(stmt);
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ACCOUNT_DATA);
    stmt->setUInt32(0, accountId);
    CharacterDatabase.Execute(stmt);

    SQLTransaction trans = LoginDatabase.BeginTransaction();

    trans->PAppend("DELETE FROM account WHERE id='%d'", accountId);
    trans->PAppend("DELETE FROM account_access WHERE id ='%d'", accountId);
    trans->PAppend("DELETE FROM realmcharacters WHERE acctid='%d'", accountId);

    LoginDatabase.CommitTransaction(trans);

    return AOR_OK;
}

AccountOpResult ChangeUsername(uint32 accountId, std::string newUsername, std::string newPassword)
{
    QueryResult result = LoginDatabase.PQuery("SELECT 1 FROM account WHERE id='%d'", accountId);
    if (!result)
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist

    if (utf8length(newUsername) > MAX_ACCOUNT_STR)
        return AOR_NAME_TOO_LONG;

    if (utf8length(newPassword) > MAX_ACCOUNT_STR)
        return AOR_PASS_TOO_LONG;

    normalizeString(newUsername);
    normalizeString(newPassword);

    std::string safeNewUsername = newUsername;
    LoginDatabase.EscapeString(safeNewUsername);

    LoginDatabase.PExecute("UPDATE account SET v='0', s='0', username='%s', sha_pass_hash='%s' WHERE id='%d'", safeNewUsername.c_str(),
                CalculateShaPassHash(newUsername, newPassword).c_str(), accountId);

    return AOR_OK;
}

AccountOpResult ChangePassword(uint32 accountId, std::string newPassword)
{
    std::string username;

    if (!GetName(accountId, username))
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist

    if (utf8length(newPassword) > MAX_ACCOUNT_STR)
        return AOR_PASS_TOO_LONG;

    normalizeString(username);
    normalizeString(newPassword);

    // also reset s and v to force update at next realmd login
    LoginDatabase.PExecute("UPDATE account SET v='0', s='0', sha_pass_hash='%s' WHERE id='%d'",
                CalculateShaPassHash(username, newPassword).c_str(), accountId);

    return AOR_OK;
}

uint32 GetId(std::string username)
{
    LoginDatabase.EscapeString(username);
    QueryResult result = LoginDatabase.PQuery("SELECT id FROM account WHERE username = '%s'", username.c_str());
    return (result) ? (*result)[0].GetUInt32() : 0;
}

uint32 GetSecurity(uint32 accountId)
{
    QueryResult result = LoginDatabase.PQuery("SELECT gmlevel FROM account_access WHERE id = '%u'", accountId);
    return (result) ? (*result)[0].GetUInt32() : 0;
}

uint32 GetSecurity(uint64 accountId, int32 realmId)
{
    QueryResult result = (realmId == -1)
        ? LoginDatabase.PQuery("SELECT gmlevel FROM account_access WHERE id = '%u' AND RealmID = '%d'", accountId, realmId)
        : LoginDatabase.PQuery("SELECT gmlevel FROM account_access WHERE id = '%u' AND (RealmID = '%d' OR RealmID = '-1')", accountId, realmId);
    return (result) ? (*result)[0].GetUInt32() : 0;
}

bool GetName(uint32 accountId, std::string& name)
{
    QueryResult result = LoginDatabase.PQuery("SELECT username FROM account WHERE id = '%u'", accountId);
    if (result)
    {
        name = (*result)[0].GetString();
        return true;
    }

    return false;
}

bool CheckPassword(uint32 accountId, std::string password)
{
    std::string username;

    if (!GetName(accountId, username))
        return false;

    normalizeString(username);
    normalizeString(password);

    QueryResult result = LoginDatabase.PQuery("SELECT 1 FROM account WHERE id='%d' AND sha_pass_hash='%s'", accountId, CalculateShaPassHash(username, password).c_str());
    return (result) ? true : false;
}

uint32 GetCharactersCount(uint32 accountId)
{
    // check character count
    QueryResult result = CharacterDatabase.PQuery("SELECT COUNT(guid) FROM characters WHERE account = '%d'", accountId);
    return (result) ? (*result)[0].GetUInt32() : 0;
}

bool normalizeString(std::string& utf8String)
{
    wchar_t buffer[MAX_ACCOUNT_STR+1];

    size_t maxLength = MAX_ACCOUNT_STR;
    if (!Utf8toWStr(utf8String, buffer, maxLength))
        return false;
#ifdef _MSC_VER
#pragma warning(disable: 4996)
#endif
    std::transform(&buffer[0], buffer+maxLength, &buffer[0], wcharToUpperOnlyLatin);
#ifdef _MSC_VER
#pragma warning(default: 4996)
#endif

    return WStrToUtf8(buffer, maxLength, utf8String);
}

std::string CalculateShaPassHash(std::string& name, std::string& password)
{
    SHA1Hash sha;
    sha.Initialize();
    sha.UpdateData(name);
    sha.UpdateData(":");
    sha.UpdateData(password);
    sha.Finalize();

    std::string encoded;
    hexEncodeByteArray(sha.GetDigest(), sha.GetLength(), encoded);

    return encoded;
}

bool IsPlayerAccount(uint32 gmlevel)
{
    return gmlevel = SEC_PLAYER;
}

bool IsModeratorAccount(uint32 gmlevel)
{
    return gmlevel >= SEC_MODERATOR && gmlevel <= SEC_CONSOLE;
}

bool IsGMAccount(uint32 gmlevel)
{
    return gmlevel >= SEC_GAMEMASTER && gmlevel <= SEC_CONSOLE;
}

bool IsAdminAccount(uint32 gmlevel)
{
    return gmlevel >= SEC_ADMINISTRATOR && gmlevel <= SEC_CONSOLE;
}

bool IsConsoleAccount(uint32 gmlevel)
{
    return gmlevel = SEC_CONSOLE;
}

} // Namespace AccountMgr
