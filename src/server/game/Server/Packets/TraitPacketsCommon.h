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

#ifndef TRINITYCORE_TRAIT_PACKETS_COMMON_H
#define TRINITYCORE_TRAIT_PACKETS_COMMON_H

#include "PacketUtilities.h"

enum class TraitCombatConfigFlags : int32;
enum class TraitConfigType : int32;

namespace UF
{
struct TraitConfig;
struct TraitEntry;
struct TraitSubTreeCache;
}

namespace WorldPackets::Traits
{
struct TraitEntry
{
    TraitEntry();
    explicit TraitEntry(UF::TraitEntry const& ufEntry);

    int32 TraitNodeID = 0;
    int32 TraitNodeEntryID = 0;
    int32 Rank = 0;
    int32 GrantedRanks = 0;
};

struct TraitSubTreeCache
{
    TraitSubTreeCache();
    explicit TraitSubTreeCache(UF::TraitSubTreeCache const& ufSubTreeCache);

    int32 TraitSubTreeID = 0;
    std::vector<TraitEntry> Entries;
    bool Active = false;
};

struct TraitConfig
{
    TraitConfig();
    explicit TraitConfig(UF::TraitConfig const& ufConfig);

    int32 ID = 0;
    TraitConfigType Type = {};
    int32 ChrSpecializationID = 0;
    TraitCombatConfigFlags CombatConfigFlags = {};
    int32 LocalIdentifier = 0;  // Local to specialization
    int32 SkillLineID = 0;
    int32 TraitSystemID = 0;
    std::vector<TraitEntry> Entries;
    std::vector<TraitSubTreeCache> SubTrees;
    String<259> Name;
};

ByteBuffer& operator>>(ByteBuffer& data, TraitEntry& traitEntry);
ByteBuffer& operator<<(ByteBuffer& data, TraitEntry const& traitEntry);
ByteBuffer& operator>>(ByteBuffer& data, TraitSubTreeCache& traitSubTreeCache);
ByteBuffer& operator<<(ByteBuffer& data, TraitSubTreeCache const& traitSubTreeCache);
ByteBuffer& operator>>(ByteBuffer& data, TraitConfig& traitConfig);
ByteBuffer& operator<<(ByteBuffer& data, TraitConfig const& traitConfig);
}

#endif // TRINITYCORE_TRAIT_PACKETS_COMMON_H
