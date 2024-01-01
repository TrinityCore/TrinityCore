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

#ifndef BattlenetAccountMgr_h__
#define BattlenetAccountMgr_h__

#include "Define.h"
#include <string>

class QueryCallback;
enum class AccountOpResult : uint8;

#define MAX_BNET_EMAIL_STR 320
#define MAX_BNET_PASS_STR 128

namespace Battlenet
{
    namespace AccountMgr
    {
        TC_GAME_API AccountOpResult CreateBattlenetAccount(std::string email, std::string password, bool withGameAccount, std::string* gameAccountName);
        TC_GAME_API AccountOpResult ChangePassword(uint32 accountId, std::string newPassword);
        TC_GAME_API bool CheckPassword(uint32 accountId, std::string password);
        TC_GAME_API AccountOpResult LinkWithGameAccount(std::string_view email, std::string_view gameAccountName);
        TC_GAME_API AccountOpResult UnlinkGameAccount(std::string_view gameAccountName);

        TC_GAME_API uint32 GetId(std::string_view username);
        TC_GAME_API bool GetName(uint32 accountId, std::string& name);
        TC_GAME_API uint32 GetIdByGameAccount(uint32 gameAccountId);
        [[nodiscard]] TC_GAME_API QueryCallback GetIdByGameAccountAsync(uint32 gameAccountId);
        TC_GAME_API uint8 GetMaxIndex(uint32 accountId);

        TC_GAME_API std::string GetSrpUsername(std::string name);
    }
}

#endif // BattlenetAccountMgr_h__
