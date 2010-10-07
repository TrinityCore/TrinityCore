/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _ACCMGR_H
#define _ACCMGR_H

#include <string>

#include "Common.h"

enum AccountOpResult
{
    AOR_OK,
    AOR_NAME_TOO_LONG,
    AOR_PASS_TOO_LONG,
    AOR_NAME_ALREDY_EXIST,
    AOR_NAME_NOT_EXIST,
    AOR_DB_INTERNAL_ERROR
};

#define MAX_ACCOUNT_STR 16

class AccountMgr
{
    public:
        AccountMgr();
        ~AccountMgr();

        AccountOpResult CreateAccount(std::string username, std::string password);
        AccountOpResult DeleteAccount(uint32 accid);
        AccountOpResult ChangeUsername(uint32 accid, std::string new_uname, std::string new_passwd);
        AccountOpResult ChangePassword(uint32 accid, std::string new_passwd);
        bool CheckPassword(uint32 accid, std::string passwd);

        uint32 GetId(std::string username);
        uint32 GetSecurity(uint32 acc_id);
        uint32 GetSecurity(uint64 acc_id, int32 realm_id);
        bool GetName(uint32 acc_id, std::string &name);
        uint32 GetCharactersCount(uint32 acc_id);
        std::string CalculateShaPassHash(std::string& name, std::string& password);

        static bool normalizeString(std::string& utf8str);
};

#define sAccountMgr (*ACE_Singleton<AccountMgr, ACE_Null_Mutex>::instance())
#endif

