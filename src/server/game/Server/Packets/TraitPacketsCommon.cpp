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

#include "TraitPacketsCommon.h"
#include "DBCEnums.h"
#include "UpdateFields.h"

namespace WorldPackets::Traits
{
TraitEntry::TraitEntry() = default;

TraitEntry::TraitEntry(UF::TraitEntry const& ufEntry)
{
    TraitNodeID = ufEntry.TraitNodeID;
    TraitNodeEntryID = ufEntry.TraitNodeEntryID;
    Rank = ufEntry.Rank;
    GrantedRanks = ufEntry.GrantedRanks;
}

TraitConfig::TraitConfig() = default;

TraitConfig::TraitConfig(UF::TraitConfig const& ufConfig)
{
    ID = ufConfig.ID;
    Type = static_cast<TraitConfigType>(*ufConfig.Type);
    ChrSpecializationID = ufConfig.ChrSpecializationID;
    CombatConfigFlags = static_cast<TraitCombatConfigFlags>(*ufConfig.CombatConfigFlags);
    LocalIdentifier = ufConfig.LocalIdentifier;
    SkillLineID = ufConfig.SkillLineID;
    TraitSystemID = ufConfig.TraitSystemID;
    for (UF::TraitEntry const& ufEntry : ufConfig.Entries)
        Entries.emplace_back(ufEntry);
    Name = ufConfig.Name;
}

ByteBuffer& operator>>(ByteBuffer& data, TraitEntry& traitEntry)
{
    data >> traitEntry.TraitNodeID;
    data >> traitEntry.TraitNodeEntryID;
    data >> traitEntry.Rank;
    data >> traitEntry.GrantedRanks;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TraitEntry const& traitEntry)
{
    data << int32(traitEntry.TraitNodeID);
    data << int32(traitEntry.TraitNodeEntryID);
    data << int32(traitEntry.Rank);
    data << int32(traitEntry.GrantedRanks);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, TraitConfig& traitConfig)
{
    data >> traitConfig.ID;
    traitConfig.Type = data.read<TraitConfigType, int32>();
    uint32 entriesSize = data.read<uint32>();
    if (entriesSize > 100)
        throw PacketArrayMaxCapacityException(entriesSize, 100);

    traitConfig.Entries.resize(entriesSize);
    switch (traitConfig.Type)
    {
        case TraitConfigType::Combat:
            data >> traitConfig.ChrSpecializationID;
            traitConfig.CombatConfigFlags = data.read<TraitCombatConfigFlags, int32>();
            data >> traitConfig.LocalIdentifier;
            break;
        case TraitConfigType::Profession:
            data >> traitConfig.SkillLineID;
            break;
        case TraitConfigType::Generic:
            data >> traitConfig.TraitSystemID;
            break;
        default:
            break;
    }

    for (TraitEntry& traitEntry : traitConfig.Entries)
        data >> traitEntry;

    uint32 nameLength = data.ReadBits(9);
    traitConfig.Name = data.ReadString(nameLength, false);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TraitConfig const& traitConfig)
{
    data << int32(traitConfig.ID);
    data << int32(traitConfig.Type);
    data << uint32(traitConfig.Entries.size());
    switch (traitConfig.Type)
    {
        case TraitConfigType::Combat:
            data << int32(traitConfig.ChrSpecializationID);
            data << int32(traitConfig.CombatConfigFlags);
            data << int32(traitConfig.LocalIdentifier);
            break;
        case TraitConfigType::Profession:
            data << int32(traitConfig.SkillLineID);
            break;
        case TraitConfigType::Generic:
            data << int32(traitConfig.TraitSystemID);
            break;
        default:
            break;
    }

    for (TraitEntry const& traitEntry : traitConfig.Entries)
        data << traitEntry;

    data.WriteBits(traitConfig.Name.length(), 9);
    data.FlushBits();

    data.WriteString(static_cast<std::string const&>(traitConfig.Name));

    return data;
}
}
