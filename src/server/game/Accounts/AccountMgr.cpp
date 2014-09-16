/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "AccountMgr.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Util.h"
#include "SHA1.h"
#include "WorldSession.h"

AccountMgr::AccountMgr() { }

AccountMgr::~AccountMgr()
{
    ClearRBAC();
}

AccountOpResult AccountMgr::CreateAccount(std::string username, std::string password, std::string email = "")
{
    if (utf8length(username) > MAX_ACCOUNT_STR)
        return AOR_NAME_TOO_LONG;                           // username's too long

    normalizeString(username);
    normalizeString(password);
    normalizeString(email);

    if (GetId(username))
        return AOR_NAME_ALREADY_EXIST;                       // username does already exist

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_ACCOUNT);

    stmt->setString(0, username);
    stmt->setString(1, CalculateShaPassHash(username, password));
    stmt->setString(2, email);
    stmt->setString(3, email);

    LoginDatabase.DirectExecute(stmt); // Enforce saving, otherwise AddGroup can fail

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_REALM_CHARACTERS_INIT);
    LoginDatabase.Execute(stmt);

    return AOR_OK;                                          // everything's fine
}

AccountOpResult AccountMgr::DeleteAccount(uint32 accountId)
{
    // Check if accounts exists
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_BY_ID);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
        return AOR_NAME_NOT_EXIST;

    // Obtain accounts characters
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARS_BY_ACCOUNT_ID);

    stmt->setUInt32(0, accountId);

    result = CharacterDatabase.Query(stmt);

    if (result)
    {
        do
        {
            ObjectGuid guid(HIGHGUID_PLAYER, (*result)[0].GetUInt32());

            // Kick if player is online
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
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_TUTORIALS);
    stmt->setUInt32(0, accountId);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ACCOUNT_DATA);
    stmt->setUInt32(0, accountId);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_BAN);
    stmt->setUInt32(0, accountId);
    CharacterDatabase.Execute(stmt);

    SQLTransaction trans = LoginDatabase.BeginTransaction();

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_ACCOUNT);
    stmt->setUInt32(0, accountId);
    trans->Append(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_ACCOUNT_ACCESS);
    stmt->setUInt32(0, accountId);
    trans->Append(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_REALM_CHARACTERS);
    stmt->setUInt32(0, accountId);
    trans->Append(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_ACCOUNT_BANNED);
    stmt->setUInt32(0, accountId);
    trans->Append(stmt);

    LoginDatabase.CommitTransaction(trans);

    return AOR_OK;
}

AccountOpResult AccountMgr::ChangeUsername(uint32 accountId, std::string newUsername, std::string newPassword)
{
    // Check if accounts exists
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_BY_ID);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
        return AOR_NAME_NOT_EXIST;

    if (utf8length(newUsername) > MAX_ACCOUNT_STR)
        return AOR_NAME_TOO_LONG;

    if (utf8length(newPassword) > MAX_ACCOUNT_STR)
        return AOR_PASS_TOO_LONG;

    normalizeString(newUsername);
    normalizeString(newPassword);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_USERNAME);

    stmt->setString(0, newUsername);
    stmt->setString(1, CalculateShaPassHash(newUsername, newPassword));
    stmt->setUInt32(2, accountId);

    LoginDatabase.Execute(stmt);

    return AOR_OK;
}

AccountOpResult AccountMgr::ChangePassword(uint32 accountId, std::string newPassword)
{
    std::string username;

    if (!GetName(accountId, username))
    {
        sScriptMgr->OnFailedPasswordChange(accountId);
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist
    }

    if (utf8length(newPassword) > MAX_ACCOUNT_STR)
    {
        sScriptMgr->OnFailedPasswordChange(accountId);
        return AOR_PASS_TOO_LONG;
    }

    normalizeString(username);
    normalizeString(newPassword);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_PASSWORD);

    stmt->setString(0, CalculateShaPassHash(username, newPassword));
    stmt->setUInt32(1, accountId);

    LoginDatabase.Execute(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_VS);

    stmt->setString(0, "");
    stmt->setString(1, "");
    stmt->setString(2, username);

    LoginDatabase.Execute(stmt);

    sScriptMgr->OnPasswordChange(accountId);
    return AOR_OK;
}

AccountOpResult AccountMgr::ChangeEmail(uint32 accountId, std::string newEmail)
{
    std::string username;

    if (!GetName(accountId, username))
    {
        sScriptMgr->OnFailedEmailChange(accountId);
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist
    }

    if (utf8length(newEmail) > MAX_EMAIL_STR)
    {
        sScriptMgr->OnFailedEmailChange(accountId);
        return AOR_EMAIL_TOO_LONG;
    }

    normalizeString(username);
    normalizeString(newEmail);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_EMAIL);

    stmt->setString(0, newEmail);
    stmt->setUInt32(1, accountId);

    LoginDatabase.Execute(stmt);

    sScriptMgr->OnEmailChange(accountId);
    return AOR_OK;
}

AccountOpResult AccountMgr::ChangeRegEmail(uint32 accountId, std::string newEmail)
{
    std::string username;

    if (!GetName(accountId, username))
    {
        sScriptMgr->OnFailedEmailChange(accountId);
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist
    }

    if (utf8length(newEmail) > MAX_EMAIL_STR)
    {
        sScriptMgr->OnFailedEmailChange(accountId);
        return AOR_EMAIL_TOO_LONG;
    }

    normalizeString(username);
    normalizeString(newEmail);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_REG_EMAIL);

    stmt->setString(0, newEmail);
    stmt->setUInt32(1, accountId);

    LoginDatabase.Execute(stmt);

    sScriptMgr->OnEmailChange(accountId);
    return AOR_OK;
}

uint32 AccountMgr::GetId(std::string const& username)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_ACCOUNT_ID_BY_USERNAME);
    stmt->setString(0, username);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    return (result) ? (*result)[0].GetUInt32() : 0;
}

uint32 AccountMgr::GetSecurity(uint32 accountId)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_ACCOUNT_ACCESS_GMLEVEL);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    return (result) ? (*result)[0].GetUInt8() : uint32(SEC_PLAYER);
}

uint32 AccountMgr::GetSecurity(uint32 accountId, int32 realmId)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_GMLEVEL_BY_REALMID);
    stmt->setUInt32(0, accountId);
    stmt->setInt32(1, realmId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    return (result) ? (*result)[0].GetUInt8() : uint32(SEC_PLAYER);
}

bool AccountMgr::GetName(uint32 accountId, std::string& name)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_USERNAME_BY_ID);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (result)
    {
        name = (*result)[0].GetString();
        return true;
    }

    return false;
}

bool AccountMgr::GetEmail(uint32 accountId, std::string& email)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_EMAIL_BY_ID);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (result)
    {
        email = (*result)[0].GetString();
        return true;
    }

    return false;
}

bool AccountMgr::CheckPassword(uint32 accountId, std::string password)
{
    std::string username;

    if (!GetName(accountId, username))
        return false;

    normalizeString(username);
    normalizeString(password);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_CHECK_PASSWORD);
    stmt->setUInt32(0, accountId);
    stmt->setString(1, CalculateShaPassHash(username, password));
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    return (result) ? true : false;
}

bool AccountMgr::CheckEmail(uint32 accountId, std::string newEmail)
{
    std::string oldEmail;

    // We simply return false for a non-existing email
    if (!GetEmail(accountId, oldEmail))
        return false;

    normalizeString(oldEmail);
    normalizeString(newEmail);

    if (strcmp(oldEmail.c_str(), newEmail.c_str()) == 0)
        return true;

    return false;
}

uint32 AccountMgr::GetCharactersCount(uint32 accountId)
{
    // check character count
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_SUM_CHARS);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    return (result) ? (*result)[0].GetUInt64() : 0;
}

bool AccountMgr::normalizeString(std::string& utf8String)
{
    wchar_t buffer[MAX_ACCOUNT_STR+1];

    size_t maxLength = MAX_ACCOUNT_STR;
    if (!Utf8toWStr(utf8String, buffer, maxLength))
        return false;

    std::transform(&buffer[0], buffer+maxLength, &buffer[0], wcharToUpperOnlyLatin);

    return WStrToUtf8(buffer, maxLength, utf8String);
}

std::string AccountMgr::CalculateShaPassHash(std::string const& name, std::string const& password)
{
    SHA1Hash sha;
    sha.Initialize();
    sha.UpdateData(name);
    sha.UpdateData(":");
    sha.UpdateData(password);
    sha.Finalize();

    return ByteArrayToHexStr(sha.GetDigest(), sha.GetLength());
}

bool AccountMgr::IsPlayerAccount(uint32 gmlevel)
{
    return gmlevel == SEC_PLAYER;
}

bool AccountMgr::IsAdminAccount(uint32 gmlevel)
{
    return gmlevel >= SEC_ADMINISTRATOR && gmlevel <= SEC_CONSOLE;
}

bool AccountMgr::IsConsoleAccount(uint32 gmlevel)
{
    return gmlevel == SEC_CONSOLE;
}

void AccountMgr::LoadRBAC()
{
    ClearRBAC();

    TC_LOG_DEBUG("rbac", "AccountMgr::LoadRBAC");
    uint32 oldMSTime = getMSTime();
    uint32 count1 = 0;
    uint32 count2 = 0;
    uint32 count3 = 0;

    TC_LOG_DEBUG("rbac", "AccountMgr::LoadRBAC: Loading permissions");
    QueryResult result = LoginDatabase.Query("SELECT id, name FROM rbac_permissions");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 account permission definitions. DB table `rbac_permissions` is empty.");
        return;
    }

    do
    {
        Field* field = result->Fetch();
        uint32 id = field[0].GetUInt32();
        _permissions[id] = new rbac::RBACPermission(id, field[1].GetString());
        ++count1;
    }
    while (result->NextRow());

    TC_LOG_DEBUG("rbac", "AccountMgr::LoadRBAC: Loading linked permissions");
    result = LoginDatabase.Query("SELECT id, linkedId FROM rbac_linked_permissions ORDER BY id ASC");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 linked permissions. DB table `rbac_linked_permissions` is empty.");
        return;
    }

    uint32 permissionId = 0;
    rbac::RBACPermission* permission = NULL;

    do
    {
        Field* field = result->Fetch();
        uint32 newId = field[0].GetUInt32();
        if (permissionId != newId)
        {
            permissionId = newId;
            permission = _permissions[newId];
        }

        uint32 linkedPermissionId = field[1].GetUInt32();
        if (linkedPermissionId == permissionId)
        {
            TC_LOG_ERROR("sql.sql", "RBAC Permission %u has itself as linked permission. Ignored", permissionId);
            continue;
        }
        permission->AddLinkedPermission(linkedPermissionId);
        ++count2;
    }
    while (result->NextRow());

    TC_LOG_DEBUG("rbac", "AccountMgr::LoadRBAC: Loading default permissions");
    result = LoginDatabase.Query("SELECT secId, permissionId FROM rbac_default_permissions ORDER BY secId ASC");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 default permission definitions. DB table `rbac_default_permissions` is empty.");
        return;
    }

    uint8 secId = 255;
    rbac::RBACPermissionContainer* permissions = NULL;
    do
    {
        Field* field = result->Fetch();
        uint32 newId = field[0].GetUInt32();
        if (secId != newId || permissions == NULL)
        {
            secId = newId;
            permissions = &_defaultPermissions[secId];
        }

        permissions->insert(field[1].GetUInt32());
        ++count3;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u permission definitions, %u linked permissions and %u default permissions in %u ms", count1, count2, count3, GetMSTimeDiffToNow(oldMSTime));
}

void AccountMgr::UpdateAccountAccess(rbac::RBACData* rbac, uint32 accountId, uint8 securityLevel, int32 realmId)
{
    if (rbac && securityLevel == rbac->GetSecurityLevel())
        rbac->SetSecurityLevel(securityLevel);

    // Delete old security level from DB
    if (realmId == -1)
    {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_ACCOUNT_ACCESS);
        stmt->setUInt32(0, accountId);
        LoginDatabase.Execute(stmt);
    }
    else
    {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_ACCOUNT_ACCESS_BY_REALM);
        stmt->setUInt32(0, accountId);
        stmt->setUInt32(1, realmId);
        LoginDatabase.Execute(stmt);
    }

    // Add new security level
    if (securityLevel)
    {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_ACCOUNT_ACCESS);
        stmt->setUInt32(0, accountId);
        stmt->setUInt8(1, securityLevel);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);
    }
}

rbac::RBACPermission const* AccountMgr::GetRBACPermission(uint32 permissionId) const
{
    TC_LOG_TRACE("rbac", "AccountMgr::GetRBACPermission: %u", permissionId);
    rbac::RBACPermissionsContainer::const_iterator it = _permissions.find(permissionId);
    if (it != _permissions.end())
        return it->second;

    return NULL;
}

bool AccountMgr::HasPermission(uint32 accountId, uint32 permissionId, uint32 realmId)
{
    if (!accountId)
    {
        TC_LOG_ERROR("rbac", "AccountMgr::HasPermission: Wrong accountId 0");
        return false;
    }

    rbac::RBACData rbac(accountId, "", realmId, GetSecurity(accountId));
    rbac.LoadFromDB();
    bool hasPermission = rbac.HasPermission(permissionId);

    TC_LOG_DEBUG("rbac", "AccountMgr::HasPermission [AccountId: %u, PermissionId: %u, realmId: %d]: %u",
                   accountId, permissionId, realmId, hasPermission);
    return hasPermission;
}

void AccountMgr::ClearRBAC()
{
    for (rbac::RBACPermissionsContainer::iterator itr = _permissions.begin(); itr != _permissions.end(); ++itr)
        delete itr->second;

    _permissions.clear();
    _defaultPermissions.clear();
}

rbac::RBACPermissionContainer const& AccountMgr::GetRBACDefaultPermissions(uint8 secLevel)
{
    TC_LOG_TRACE("rbac", "AccountMgr::GetRBACDefaultPermissions: secLevel %u - size: %u", secLevel, uint32(_defaultPermissions[secLevel].size()));
    return _defaultPermissions[secLevel];
}
