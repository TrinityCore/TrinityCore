/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "Guild.h"

class GuildMgr
{
private:
    GuildMgr();
    ~GuildMgr();

public:
    static GuildMgr* instance()
    {
        static GuildMgr instance;
        return &instance;
    }

    Guild* GetGuildByLeader(ObjectGuid guid) const;
    Guild* GetGuildById(ObjectGuid::LowType guildId) const;
    Guild* GetGuildByName(std::string const& guildName) const;
    std::string GetGuildNameById(ObjectGuid::LowType guildId) const;

    void LoadGuilds();
    void AddGuild(Guild* guild);
    void RemoveGuild(ObjectGuid::LowType guildId);

    ObjectGuid::LowType GenerateGuildId();
    void SetNextGuildId(ObjectGuid::LowType Id) { NextGuildId = Id; }

    void ResetTimes();
protected:
    typedef std::unordered_map<ObjectGuid::LowType, Guild*> GuildContainer;
    ObjectGuid::LowType NextGuildId;
    GuildContainer GuildStore;
};

#define sGuildMgr GuildMgr::instance()

#endif
