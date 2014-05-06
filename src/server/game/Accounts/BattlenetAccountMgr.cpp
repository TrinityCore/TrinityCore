/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "BattlenetAccountMgr.h"
#include "DatabaseEnv.h"
#include "Util.h"
#include "SHA256.h"

AccountOpResult Battlenet::AccountMgr::CreateBattlenetAccount(std::string email, std::string password)
{
    if (utf8length(email) > 64)
        return AccountOpResult::AOR_NAME_TOO_LONG;

    Utf8ToUpperOnlyLatin(email);
    Utf8ToUpperOnlyLatin(password);

    if (GetId(email))
         return AccountOpResult::AOR_NAME_ALREADY_EXIST;

    LoginDatabase.EscapeString(email);
    LoginDatabase.DirectPExecute("INSERT INTO battlenet_accounts (`email`,`sha_pass_hash`) VALUES ('%s', '%s')", email.c_str(), CalculateShaPassHash(email, password).c_str());

    return AccountOpResult::AOR_OK;
}

AccountOpResult Battlenet::AccountMgr::ChangeUsername(uint32 accountId, std::string newUsername, std::string newPassword)
{
    // Check if accounts exists
    QueryResult result = LoginDatabase.PQuery("SELECT 1 FROM battlenet_accounts WHERE id = %u", accountId);

    if (!result)
        return AccountOpResult::AOR_NAME_NOT_EXIST;

    if (utf8length(newUsername) > MAX_ACCOUNT_STR)
        return AccountOpResult::AOR_NAME_TOO_LONG;

    if (utf8length(newPassword) > MAX_PASS_STR)
        return AccountOpResult::AOR_PASS_TOO_LONG;

    Utf8ToUpperOnlyLatin(newUsername);
    Utf8ToUpperOnlyLatin(newPassword);

    LoginDatabase.EscapeString(newUsername);
    LoginDatabase.EscapeString(newPassword);
    LoginDatabase.PExecute("UPDATE account SET v = '', s = '', username = '%s', sha_pass_hash = '%s' WHERE id = '%u'",
        newUsername.c_str(), CalculateShaPassHash(newUsername, newPassword).c_str(), newPassword.c_str(), accountId);

    return AccountOpResult::AOR_OK;
}

AccountOpResult Battlenet::AccountMgr::ChangePassword(uint32 accountId, std::string newPassword)
{
    std::string username;
    if (!GetName(accountId, username))
        return AccountOpResult::AOR_NAME_NOT_EXIST;                          // account doesn't exist

    if (utf8length(newPassword) > MAX_PASS_STR)
        return AccountOpResult::AOR_PASS_TOO_LONG;

    Utf8ToUpperOnlyLatin(username);
    Utf8ToUpperOnlyLatin(newPassword);

    LoginDatabase.EscapeString(newPassword);
    LoginDatabase.PExecute("UPDATE account SET v = '', s = '',  sha_pass_hash = '%s' WHERE id = '%u'",
        CalculateShaPassHash(username, newPassword).c_str(), newPassword.c_str(), accountId);

    return AccountOpResult::AOR_OK;
}

uint32 Battlenet::AccountMgr::GetId(std::string const& username)
{
    QueryResult result = LoginDatabase.PQuery("SELECT id FROM battlenet_accounts WHERE email = '%s'", username.c_str());

    return result ? (*result)[0].GetUInt32() : 0;
}

bool Battlenet::AccountMgr::GetName(uint32 accountId, std::string& name)
{
    QueryResult result = LoginDatabase.PQuery("SELECT email FROM battlenet_accounts WHERE id = '%u'", accountId);

    if (result)
    {
        name = (*result)[0].GetString();
        return true;
    }

    return false;
}

bool Battlenet::AccountMgr::CheckPassword(uint32 accountId, std::string password)
{
    std::string username;

    if (!GetName(accountId, username))
        return false;

    Utf8ToUpperOnlyLatin(username);
    Utf8ToUpperOnlyLatin(password);

    QueryResult result = LoginDatabase.PQuery("SELECT 1 FROM battlenet_accounts WHERE id = %u AND sha_pass_hash = '%s'", accountId, CalculateShaPassHash(username, password));

    return (result) ? true : false;
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
