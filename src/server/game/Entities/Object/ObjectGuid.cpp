/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectGuid.h"
#include "World.h"
#include "ObjectMgr.h"
#include <sstream>
#include <iomanip>

char const* TypeNames[] =
{
    "Null",
    "Uniq",
    "Player",
    "Item",
    "StaticDoor",
    "Transport",
    "Conversation",
    "Creature",
    "Vehicle",
    "Pet",
    "GameObject",
    "DynamicObject",
    "AreaTrigger",
    "Corpse",
    "LootObject",
    "SceneObject",
    "Scenario",
    "AIGroup",
    "DynamicDoor",
    "ClientActor",
    "Vignette",
    "CallForHelp",
    "AIResource",
    "AILock",
    "AILockTicket",
    "ChatChannel",
    "Party",
    "Guild",
    "WowAccount",
    "BNetAccount",
    "GMTask",
    "MobileSession",
    "RaidGroup",
    "Spell",
    "Mail",
    "WebObj",
    "LFGObject",
    "LFGList",
    "UserRouter",
    "PVPQueueGroup",
    "UserClient",
    "PetBattle",
    "UniqueUserClient",
    "BattlePet",
};

char const* ObjectGuid::GetTypeName(HighGuid high)
{
    if (high > HighGuid::Count)
        return "<unknown>";

    return TypeNames[uint32(high)];
}

std::string ObjectGuid::ToString() const
{
    std::ostringstream str;
    str << "GUID Full: 0x" << std::hex << std::setw(16) << std::setfill('0') << _low << std::dec;
    str << " Type: " << GetTypeName();
    if (HasEntry())
        str << (IsPet() ? " Pet number: " : " Entry: ") << GetEntry() << " ";

    str << " Low: " << GetCounter();
    return str.str();
}

std::vector<uint8> ObjectGuid::GetRawValue() const
{
    std::vector<uint8> raw(16);
    memcpy(raw.data(), this, sizeof(*this));
    return raw;
}

void ObjectGuid::SetRawValue(std::vector<uint8> const& guid)
{
    ASSERT(guid.size() == sizeof(*this));
    memcpy(this, guid.data(), sizeof(*this));
}

void PackedGuid::Set(ObjectGuid const& guid)
{
    uint8 lowMask = 0;
    uint8 highMask = 0;
    _packedGuid.clear();
    _packedGuid << uint8(lowMask);
    _packedGuid << uint8(highMask);

    uint8 packed[8];
    if (size_t packedSize = _packedGuid.PackUInt64(guid._low, &lowMask, packed))
        _packedGuid.append(packed, packedSize);
    if (size_t packedSize = _packedGuid.PackUInt64(guid._high, &highMask, packed))
        _packedGuid.append(packed, packedSize);

    _packedGuid.put(0, lowMask);
    _packedGuid.put(1, highMask);
}

template<HighGuid high>
ObjectGuid::LowType ObjectGuidGenerator<high>::Generate()
{
    if (_nextGuid >= ObjectGuid::GetMaxCounter(high) - 1)
    {
        TC_LOG_ERROR("", "%s guid overflow!! Can't continue, shutting down server. ", ObjectGuid::GetTypeName(high));
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _nextGuid++;
}

ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid)
{
    buf << guid.WriteAsPacked();
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid& guid)
{
    buf >> guid.ReadAsPacked();
    return buf;
}

ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid)
{
    buf.append(guid._packedGuid);
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, PackedGuidReader const& guid)
{
    uint8 lowMask, highMask;
    buf >> lowMask >> highMask;
    buf.ReadPackedUInt64(lowMask, guid.GuidPtr->_low);
    buf.ReadPackedUInt64(highMask, guid.GuidPtr->_high);
    return buf;
}

std::ostream& operator<<(std::ostream& stream, ObjectGuid const& guid)
{
    std::ostringstream tmp;
    tmp << std::hex << std::setw(16) << std::setfill('0') << guid._high << std::setw(16) << std::setfill('0') << guid._low;
    stream << tmp.str();
    return stream;
}

class GuidFormat
{
public:
    inline static ObjectGuid Global(HighGuid type, ObjectGuid::LowType counter)
    {
        return ObjectGuid(uint64(uint64(type) << 58), counter);
    }

    inline static ObjectGuid RealmSpecific(HighGuid type, ObjectGuid::LowType counter)
    {
        return ObjectGuid(uint64(uint64(type) << 58 | uint64(realmHandle.Index) << 42), counter);
    }

    inline static ObjectGuid MapSpecific(HighGuid type, uint8 subType, uint16 mapId, uint32 serverId, uint32 entry, ObjectGuid::LowType counter)
    {
        return ObjectGuid(uint64((uint64(type) << 58) | (uint64(realmHandle.Index & 0x1FFF) << 42) | (uint64(mapId & 0x1FFF) << 29) | (uint64(entry & 0x7FFFFF) << 6) | (uint64(subType) & 0x3F)),
            uint64((uint64(serverId & 0xFFFFFF) << 40) | (counter & UI64LIT(0xFFFFFFFFFF))));
    }
};

#define GLOBAL_GUID_CREATE(highguid) template<> ObjectGuid ObjectGuid::Create<highguid>(LowType counter) { return GuidFormat::Global(highguid, counter); }
#define REALM_GUID_CREATE(highguid) template<> ObjectGuid ObjectGuid::Create<highguid>(LowType counter) { return GuidFormat::RealmSpecific(highguid, counter); }
#define MAP_GUID_CREATE(highguid) template<> ObjectGuid ObjectGuid::Create<highguid>(uint16 mapId, uint32 entry, LowType counter) { return GuidFormat::MapSpecific(highguid, 0, mapId, 0, entry, counter); }

GLOBAL_GUID_CREATE(HighGuid::Uniq)
GLOBAL_GUID_CREATE(HighGuid::Party)
GLOBAL_GUID_CREATE(HighGuid::WowAccount)
GLOBAL_GUID_CREATE(HighGuid::BNetAccount)
GLOBAL_GUID_CREATE(HighGuid::GMTask)
GLOBAL_GUID_CREATE(HighGuid::RaidGroup)
GLOBAL_GUID_CREATE(HighGuid::Spell)
GLOBAL_GUID_CREATE(HighGuid::Mail)
GLOBAL_GUID_CREATE(HighGuid::UserRouter)
GLOBAL_GUID_CREATE(HighGuid::PVPQueueGroup)
GLOBAL_GUID_CREATE(HighGuid::UserClient)
GLOBAL_GUID_CREATE(HighGuid::UniqueUserClient)
GLOBAL_GUID_CREATE(HighGuid::BattlePet)
REALM_GUID_CREATE(HighGuid::Player)
REALM_GUID_CREATE(HighGuid::Item)   // This is not exactly correct, there are 2 more unknown parts in highguid: (high >> 10 & 0xFF), (high >> 18 & 0xFFFFFF)
REALM_GUID_CREATE(HighGuid::Transport)
REALM_GUID_CREATE(HighGuid::Guild)
MAP_GUID_CREATE(HighGuid::Conversation)
MAP_GUID_CREATE(HighGuid::Creature)
MAP_GUID_CREATE(HighGuid::Vehicle)
MAP_GUID_CREATE(HighGuid::Pet)
MAP_GUID_CREATE(HighGuid::GameObject)
MAP_GUID_CREATE(HighGuid::DynamicObject)
MAP_GUID_CREATE(HighGuid::AreaTrigger)
MAP_GUID_CREATE(HighGuid::Corpse)
MAP_GUID_CREATE(HighGuid::LootObject)
MAP_GUID_CREATE(HighGuid::SceneObject)
MAP_GUID_CREATE(HighGuid::Scenario)
MAP_GUID_CREATE(HighGuid::AIGroup)
MAP_GUID_CREATE(HighGuid::DynamicDoor)
MAP_GUID_CREATE(HighGuid::Vignette)
MAP_GUID_CREATE(HighGuid::CallForHelp)
MAP_GUID_CREATE(HighGuid::AIResource)
MAP_GUID_CREATE(HighGuid::AILock)
MAP_GUID_CREATE(HighGuid::AILockTicket)

ObjectGuid const ObjectGuid::Empty = ObjectGuid();
ObjectGuid const ObjectGuid::TradeItem = ObjectGuid::Create<HighGuid::Uniq>(uint64(10));

template<HighGuid type>
ObjectGuid ObjectGuid::Create(LowType /*counter*/)
{
    static_assert(type == HighGuid::Count, "This guid type cannot be constructed using Create(LowType counter).");
}

template<HighGuid type>
ObjectGuid ObjectGuid::Create(uint16 /*mapId*/, uint32 /*entry*/, LowType /*counter*/)
{
    static_assert(type == HighGuid::Count, "This guid type cannot be constructed using Create(uint16 mapId, uint32 entry, LowType counter).");
}

template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::Player>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::Creature>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::Pet>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::Vehicle>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::Item>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::GameObject>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::DynamicObject>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::Corpse>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::AreaTrigger>::Generate();
template ObjectGuid::LowType ObjectGuidGenerator<HighGuid::Transport>::Generate();
