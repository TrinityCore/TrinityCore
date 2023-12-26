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

#include "BattlenetAccountMgr.h"
#include "AccountMgr.h"
#include "DatabaseEnv.h"
#include "SRP6.h"
#include "Util.h"

using GameAccountMgr = AccountMgr;
using BnetSRP6_OLD = Trinity::Crypto::SRP::BnetSRP6v1<Trinity::Crypto::SHA256>;
using BnetSRP6 = Trinity::Crypto::SRP::BnetSRP6v2<Trinity::Crypto::SHA256>;

enum class SrpVersion : int8
{
    v1 = 1, // password length limit 16 characters, case-insensitive, uses SHA256 to generate verifier
    v2 = 2  // password length limit 128 characters, case-sensitive, uses PBKDF2 with SHA512 to generate verifier
};

AccountOpResult Battlenet::AccountMgr::CreateBattlenetAccount(std::string email, std::string password, bool withGameAccount, std::string* gameAccountName)
{
    if (utf8length(email) > MAX_BNET_EMAIL_STR)
        return AccountOpResult::AOR_NAME_TOO_LONG;

    if (utf8length(password) > MAX_BNET_PASS_STR)
        return AccountOpResult::AOR_PASS_TOO_LONG;

    Utf8ToUpperOnlyLatin(email);

    if (GetId(email))
        return AccountOpResult::AOR_NAME_ALREADY_EXIST;

    std::string srpUsername = GetSrpUsername(email);
    auto [salt, verifier] = Trinity::Crypto::SRP6::MakeRegistrationData<BnetSRP6>(srpUsername, password);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_ACCOUNT);
    stmt->setString(0, email);
    stmt->setInt8(1, AsUnderlyingType(SrpVersion::v2));
    stmt->setBinary(2, salt);
    stmt->setBinary(3, verifier);
    LoginDatabase.DirectExecute(stmt);

    uint32 newAccountId = GetId(email);
    ASSERT(newAccountId);

    if (withGameAccount)
    {
        *gameAccountName = std::to_string(newAccountId) + "#1";
        std::string gameAccountPassword = password.substr(0, MAX_PASS_STR);
        Utf8ToUpperOnlyLatin(gameAccountPassword);
        GameAccountMgr::instance()->CreateAccount(*gameAccountName, gameAccountPassword, email, newAccountId, 1);
    }

    return AccountOpResult::AOR_OK;
}

AccountOpResult Battlenet::AccountMgr::ChangePassword(uint32 accountId, std::string newPassword)
{
    std::string username;
    if (!GetName(accountId, username))
        return AccountOpResult::AOR_NAME_NOT_EXIST;                          // account doesn't exist

    if (utf8length(newPassword) > MAX_BNET_PASS_STR)
        return AccountOpResult::AOR_PASS_TOO_LONG;

    std::string srpUsername = GetSrpUsername(username);
    auto [salt, verifier] = Trinity::Crypto::SRP6::MakeRegistrationData<BnetSRP6>(srpUsername, newPassword);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_LOGON);
    stmt->setInt8(0, AsUnderlyingType(SrpVersion::v2));
    stmt->setBinary(1, salt);
    stmt->setBinary(2, verifier);
    stmt->setUInt32(3, accountId);
    LoginDatabase.Execute(stmt);

    return AccountOpResult::AOR_OK;
}

bool Battlenet::AccountMgr::CheckPassword(uint32 accountId, std::string password)
{
    std::string username;

    if (!GetName(accountId, username))
        return false;

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_CHECK_PASSWORD);
    stmt->setUInt32(0, accountId);

    if (PreparedQueryResult result = LoginDatabase.Query(stmt))
    {
        Trinity::Crypto::SRP::Salt salt = (*result)[1].GetBinary<Trinity::Crypto::SRP::SALT_LENGTH>();
        Trinity::Crypto::SRP::Verifier verifier = (*result)[2].GetBinary();
        switch (SrpVersion((*result)[0].GetInt8()))
        {
            case SrpVersion::v1:
                Utf8ToUpperOnlyLatin(password);
                return BnetSRP6_OLD(username, salt, verifier).CheckCredentials(username, password);
            case SrpVersion::v2:
                return BnetSRP6(username, salt, verifier).CheckCredentials(username, password);
            default:
                break;
        }
    }

    return false;
}

AccountOpResult Battlenet::AccountMgr::LinkWithGameAccount(std::string_view email, std::string_view gameAccountName)
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

AccountOpResult Battlenet::AccountMgr::UnlinkGameAccount(std::string_view gameAccountName)
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

uint32 Battlenet::AccountMgr::GetId(std::string_view username)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_ID_BY_EMAIL);
    stmt->setStringView(0, username);
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

QueryCallback Battlenet::AccountMgr::GetIdByGameAccountAsync(uint32 gameAccountId)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_ID_BY_GAME_ACCOUNT);
    stmt->setUInt32(0, gameAccountId);
    return LoginDatabase.AsyncQuery(stmt);
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

std::string Battlenet::AccountMgr::GetSrpUsername(std::string name)
{
    Utf8ToUpperOnlyLatin(name);
    return ByteArrayToHexStr(Trinity::Crypto::SHA256::GetDigestOf(name));
}
