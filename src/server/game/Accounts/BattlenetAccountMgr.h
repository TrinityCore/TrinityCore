/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef BattlenetAccountMgr_h__
#define BattlenetAccountMgr_h__

#include "Define.h"
#include <string>

enum class AccountOpResult : uint8;

#define MAX_BNET_EMAIL_STR 320

namespace Battlenet
{
    namespace AccountMgr
    {
        TC_GAME_API AccountOpResult CreateBattlenetAccount(std::string email, std::string password, bool withGameAccount, std::string* gameAccountName);
        TC_GAME_API AccountOpResult ChangePassword(uint32 accountId, std::string newPassword);
        TC_GAME_API bool CheckPassword(uint32 accountId, std::string password);
        TC_GAME_API AccountOpResult LinkWithGameAccount(std::string const& email, std::string const& gameAccountName);
        TC_GAME_API AccountOpResult UnlinkGameAccount(std::string const& gameAccountName);

        TC_GAME_API uint32 GetId(std::string const& username);
        TC_GAME_API bool GetName(uint32 accountId, std::string& name);
        TC_GAME_API uint32 GetIdByGameAccount(uint32 gameAccountId);
        TC_GAME_API uint8 GetMaxIndex(uint32 accountId);

        TC_GAME_API std::string CalculateShaPassHash(std::string const& name, std::string const& password);
    }
}

#endif // BattlenetAccountMgr_h__
