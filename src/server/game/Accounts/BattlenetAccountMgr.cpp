/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "BattlenetAccountMgr.h"
#include "AccountMgr.h"
#include "DatabaseEnv.h"
#include "Util.h"
#include "SHA256.h"

using GameAccountMgr = AccountMgr;

AccountOpResult Battlenet::AccountMgr::CreateBattlenetAccount(std::string email, std::string password, bool withGameAccount, std::string* gameAccountName)
{
    if (utf8length(email) > MAX_BNET_EMAIL_STR)
        return AccountOpResult::AOR_NAME_TOO_LONG;

    if (utf8length(password) > MAX_PASS_STR)
        return AccountOpResult::AOR_PASS_TOO_LONG;

    Utf8ToUpperOnlyLatin(email);
    Utf8ToUpperOnlyLatin(password);

    if (GetId(email))
        return AccountOpResult::AOR_NAME_ALREADY_EXIST;

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_ACCOUNT);
    stmt->setString(0, email);
    stmt->setString(1, CalculateShaPassHash(email, password));
    LoginDatabase.DirectExecute(stmt);

    uint32 newAccountId = GetId(email);
    ASSERT(newAccountId);

    if (withGameAccount)
    {
        *gameAccountName = std::to_string(newAccountId) + "#1";
        GameAccountMgr::instance()->CreateAccount(*gameAccountName, password, email, newAccountId, 1);
    }

    return AccountOpResult::AOR_OK;
}

AccountOpResult Battlenet::AccountMgr::ChangePassword(uint32 accountId, std::string newPassword)
{
    std::string username;
    if (!GetName(accountId, username))
        return AccountOpResult::AOR_NAME_NOT_EXIST;                          // account doesn't exist

    Utf8ToUpperOnlyLatin(username);
    Utf8ToUpperOnlyLatin(newPassword);
    if (utf8length(newPassword) > MAX_PASS_STR)
        return AccountOpResult::AOR_PASS_TOO_LONG;

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_PASSWORD);
    stmt->setString(0, CalculateShaPassHash(username, newPassword));
    stmt->setUInt32(1, accountId);
    LoginDatabase.Execute(stmt);

    return AccountOpResult::AOR_OK;
}

bool Battlenet::AccountMgr::CheckPassword(uint32 accountId, std::string password)
{
    std::string username;

    if (!GetName(accountId, username))
        return false;

    Utf8ToUpperOnlyLatin(username);
    Utf8ToUpperOnlyLatin(password);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_CHECK_PASSWORD);
    stmt->setUInt32(0, accountId);
    stmt->setString(1, CalculateShaPassHash(username, password));

    return LoginDatabase.Query(stmt) != nullptr;
}

AccountOpResult Battlenet::AccountMgr::LinkWithGameAccount(std::string const& email, std::string const& gameAccountName)
{
    uint32 bnetAccountId = GetId(email);
    if (!bnetAccountId)
        return AccountOpResult::AOR_NAME_NOT_EXIST;

    uint32 gameAccountId = GameAccountMgr::GetId(gameAccountName);
    if (!gameAccountId)
        return AccountOpResult::AOR_NAME_NOT_EXIST;

    if (GetIdByGameAccount(gameAccountId))
        return AccountOpResult::AOR_ACCOUNT_BAD_LINK;

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_GAME_ACCOUNT_LINK);
    stmt->setUInt32(0, bnetAccountId);
    stmt->setUInt8(1, GetMaxIndex(bnetAccountId) + 1);
    stmt->setUInt32(2, gameAccountId);
    LoginDatabase.Execute(stmt);
    return AccountOpResult::AOR_OK;
}

AccountOpResult Battlenet::AccountMgr::UnlinkGameAccount(std::string const& gameAccountName)
{
    uint32 gameAccountId = GameAccountMgr::GetId(gameAccountName);
    if (!gameAccountId)
        return AccountOpResult::AOR_NAME_NOT_EXIST;

    if (!GetIdByGameAccount(gameAccountId))
        return AccountOpResult::AOR_ACCOUNT_BAD_LINK;

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_GAME_ACCOUNT_LINK);
    stmt->setNull(0);
    stmt->setNull(1);
    stmt->setUInt32(2, gameAccountId);
    LoginDatabase.Execute(stmt);
    return AccountOpResult::AOR_OK;
}

uint32 Battlenet::AccountMgr::GetId(std::string const& username)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_ID_BY_EMAIL);
    stmt->setString(0, username);
    if (PreparedQueryResult result = LoginDatabase.Query(stmt))
        return (*result)[0].GetUInt32();

    return 0;
}

bool Battlenet::AccountMgr::GetName(uint32 accountId, std::string& name)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_EMAIL_BY_ID);
    stmt->setUInt32(0, accountId);
    if (PreparedQueryResult result = LoginDatabase.Query(stmt))
    {
        name = (*result)[0].GetString();
        return true;
    }

    return false;
}

uint32 Battlenet::AccountMgr::GetIdByGameAccount(uint32 gameAccountId)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_ID_BY_GAME_ACCOUNT);
    stmt->setUInt32(0, gameAccountId);
    if (PreparedQueryResult result = LoginDatabase.Query(stmt))
        return (*result)[0].GetUInt32();

    return 0;
}

uint8 Battlenet::AccountMgr::GetMaxIndex(uint32 accountId)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_MAX_ACCOUNT_INDEX);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (result)
        return (*result)[0].GetUInt8();

    return 0;
}

std::string Battlenet::AccountMgr::CalculateShaPassHash(std::string const& name, std::string const& password)
{
    SHA256Hash email;
    email.UpdateData(name);
    email.Finalize();

    SHA256Hash sha;
    sha.UpdateData(ByteArrayToHexStr(email.GetDigest(), email.GetLength()));
    sha.UpdateData(":");
    sha.UpdateData(password);
    sha.Finalize();

    return ByteArrayToHexStr(sha.GetDigest(), sha.GetLength(), true);
}
