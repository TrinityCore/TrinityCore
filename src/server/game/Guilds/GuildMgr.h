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

struct GuildReward
{
    uint32 Entry;
    int32 Racemask;
    uint64 Price;
    uint32 AchievementId;
    uint8 Standing;
};

struct GuildProfession
{
    uint32 SpellId;
    uint32 UniqueBits;
    bool AutoLearn;
};

struct GuildChallenge
{
    int32 ChallengeType;
    int32 ChallengeCount;
    int32 Experience;
    int32 Gold;
    int32 GoldMaxLevel;
};

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
    Guild* GetGuildByName(std::string const& guildName) const;
    std::string GetGuildNameById(ObjectGuid::LowType guildId) const;

    void LoadGuildXpForLevel();
    void LoadGuildRewards();
    void LoadGuildProfessionData();
    void LoadGuildChallenges();

    void LoadGuilds();
    void AddGuild(Guild* guild);
    void RemoveGuild(ObjectGuid::LowType guildId);
    void SaveGuilds();

    ObjectGuid::LowType GenerateGuildId();
    void SetNextGuildId(ObjectGuid::LowType Id) { NextGuildId = Id; }

    uint32 GetXPForGuildLevel(uint8 level) const;
    std::vector<GuildReward> const& GetGuildRewards() const { return GuildRewards; }
    std::vector<GuildProfession> const& GetGuildProfessionData(uint32 skillId) { return GuildProfessionStore[skillId]; }
    std::vector<GuildChallenge> const& GetGuildChallengeData() const { return GuildChallenges; }

    void ResetTimes(bool week);
    void ClearExpiredGuildNews();
protected:
    typedef std::unordered_map<ObjectGuid::LowType, Guild*> GuildContainer;
    typedef std::unordered_map<uint32 /*skillID*/, std::vector<GuildProfession>> GuildProfessionMap;
    ObjectGuid::LowType NextGuildId;
    GuildContainer GuildStore;
    GuildProfessionMap GuildProfessionStore;
    std::vector<uint64> GuildXPperLevel;
    std::vector<GuildReward> GuildRewards;
    std::vector<GuildChallenge> GuildChallenges;
};

#define sGuildMgr GuildMgr::instance()

#endif
