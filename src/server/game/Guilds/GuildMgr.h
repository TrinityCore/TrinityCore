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

#ifndef _GUILDMGR_H
#define _GUILDMGR_H

#include "Define.h"
#include "ObjectGuid.h"
#include <unordered_map>
#include <vector>

class Guild;
struct GuildReward;

class TC_GAME_API GuildMgr
{
private:
    GuildMgr();
    ~GuildMgr();
    GuildMgr(GuildMgr const&) = delete;
    GuildMgr& operator=(GuildMgr const&) = delete;

public:
    static GuildMgr* instance();

    Guild* GetGuildByLeader(ObjectGuid guid) const;
    Guild* GetGuildById(ObjectGuid::LowType guildId) const;
    Guild* GetGuildByGuid(ObjectGuid guid) const;
    Guild* GetGuildByName(std::string_view guildName) const;
    std::string GetGuildNameById(ObjectGuid::LowType guildId) const;

    void LoadGuildRewards();

    void LoadGuilds();
    void AddGuild(Guild* guild);
    void RemoveGuild(ObjectGuid::LowType guildId);

    void SaveGuilds();

    void ResetReputationCaps();

    ObjectGuid::LowType GenerateGuildId();
    void SetNextGuildId(ObjectGuid::LowType Id) { NextGuildId = Id; }

    std::vector<GuildReward> const& GetGuildRewards() const { return GuildRewards; }

    void ResetTimes(bool week);
protected:
    typedef std::unordered_map<ObjectGuid::LowType, Guild*> GuildContainer;
    ObjectGuid::LowType NextGuildId;
    GuildContainer GuildStore;
    std::vector<GuildReward> GuildRewards;
};

#define sGuildMgr GuildMgr::instance()

#endif
