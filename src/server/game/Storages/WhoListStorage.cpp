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

#include "WhoListStorage.h"
#include "World.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "GuildMgr.h"
#include "WorldSession.h"
#include "Guild.h"

WhoListStorageMgr* WhoListStorageMgr::instance()
{
    static WhoListStorageMgr instance;
    return &instance;
}

void WhoListStorageMgr::Update()
{
    // clear current list
    _whoListStorage.clear();
    _whoListStorage.reserve(sWorld->GetPlayerCount()+1);

    HashMapHolder<Player>::MapType const& m = ObjectAccessor::GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->second->FindMap() || itr->second->GetSession()->PlayerLoading())
            continue;

        std::string playerName = itr->second->GetName();
        std::wstring widePlayerName;
        if (!Utf8toWStr(playerName, widePlayerName))
            continue;

        wstrToLower(widePlayerName);

        std::string guildName = sGuildMgr->GetGuildNameById(itr->second->GetGuildId());
        std::wstring wideGuildName;
        if (!Utf8toWStr(guildName, wideGuildName))
            continue;

        wstrToLower(wideGuildName);

        Guild* guild = itr->second->GetGuild();
        ObjectGuid guildGuid;

        if (guild)
            guildGuid = guild->GetGUID();

        _whoListStorage.emplace_back(itr->second->GetGUID(), itr->second->GetTeam(), itr->second->GetSession()->GetSecurity(), itr->second->getLevel(),
            itr->second->getClass(), itr->second->getRace(), itr->second->GetZoneId(), itr->second->GetNativeSex(), itr->second->IsVisible(),
            itr->second->IsGameMaster(), widePlayerName, wideGuildName, playerName, guildName, guildGuid);
    }
}
