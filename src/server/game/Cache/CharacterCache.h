/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __CHARACTERCACHE_H
#define __CHARACTERCACHE_H

#include "Common.h"
#include "ObjectGuid.h"

#include <unordered_map>

struct CharacterCacheEntry
{
    std::string Name;
    uint32 AccountId;
    uint8 Class;
    uint8 Race;
    uint8 Sex;
    uint8 Level;
    ObjectGuid::LowType GuildId;
    uint32 ArenaTeamId[3];
};

typedef std::unordered_map<std::string, ObjectGuid> CharacterGuidByNameContainer;
typedef std::unordered_map<ObjectGuid, CharacterCacheEntry> CharacterCacheContainer;

class TC_GAME_API CharacterCache
{
    public:
        CharacterCache();
        ~CharacterCache();
        static CharacterCache* instance();

        void LoadCharacterCacheStorage();
        void AddCharacterCacheEntry(ObjectGuid const& guid, uint32 accountId, std::string const& name, uint8 gender, uint8 race, uint8 playerClass, uint8 level);
        void DeleteCharacterCacheEntry(ObjectGuid const& guid, std::string const& name);

        void UpdateCharacterData(ObjectGuid const& guid, std::string const& name, uint8 gender = GENDER_NONE, uint8 race = RACE_NONE);
        void UpdateCharacterLevel(ObjectGuid const& guid, uint8 level);
        void UpdateCharacterAccountId(ObjectGuid const& guid, uint32 accountId);
        void UpdateCharacterGuildId(ObjectGuid const& guid, ObjectGuid::LowType guildId);
        void UpdateCharacterArenaTeamId(ObjectGuid const& guid, uint8 slot, uint32 arenaTeamId);
        void UpdateCharacterGuidByName(ObjectGuid const& guid, std::string const& oldName, std::string const& newName);

        bool HasCharacterCacheEntry(ObjectGuid const& guid) const;
        CharacterCacheEntry const* GetCharacterCacheByGuid(ObjectGuid const& guid) const;
        CharacterCacheEntry const* GetCharacterCacheByName(std::string const& name) const;

        ObjectGuid GetCharacterGuidByName(std::string const& name) const;
        bool GetCharacterNameByGuid(ObjectGuid guid, std::string& name) const;
        uint32 GetCharacterTeamByGuid(ObjectGuid guid) const;
        uint32 GetCharacterAccountIdByGuid(ObjectGuid guid) const;
        uint32 GetCharacterAccountIdByName(std::string const& name) const;
        uint8 GetCharacterLevelByGuid(ObjectGuid guid) const;
        ObjectGuid::LowType CharacterCache::GetCharacterGuildIdByGuid(ObjectGuid guid) const;
        uint32 CharacterCache::GetCharacterArenaTeamIdByGuid(ObjectGuid guid, uint8 type) const;
};

#define sCharacterCache CharacterCache::instance()

#endif
