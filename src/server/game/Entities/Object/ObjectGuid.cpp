/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "ByteBuffer.h"
#include "Errors.h"
#include "Hash.h"
#include "Log.h"
#include "Realm.h"
#include "World.h"
#include <sstream>
#include <iomanip>

namespace
{
    struct GuidTypeNames
    {
        char const* Values[uint32(HighGuid::Count)];

        GuidTypeNames();
    } Names;

    GuidTypeNames::GuidTypeNames()
    {
#define SET_GUID_NAME(type) Values[uint32(HighGuid::type)] = #type;

        SET_GUID_NAME(Null);
        SET_GUID_NAME(Uniq);
        SET_GUID_NAME(Player);
        SET_GUID_NAME(Item);
        SET_GUID_NAME(WorldTransaction);
        SET_GUID_NAME(StaticDoor);
        SET_GUID_NAME(Transport);
        SET_GUID_NAME(Conversation);
        SET_GUID_NAME(Creature);
        SET_GUID_NAME(Vehicle);
        SET_GUID_NAME(Pet);
        SET_GUID_NAME(GameObject);
        SET_GUID_NAME(DynamicObject);
        SET_GUID_NAME(AreaTrigger);
        SET_GUID_NAME(Corpse);
        SET_GUID_NAME(LootObject);
        SET_GUID_NAME(SceneObject);
        SET_GUID_NAME(Scenario);
        SET_GUID_NAME(AIGroup);
        SET_GUID_NAME(DynamicDoor);
        SET_GUID_NAME(ClientActor);
        SET_GUID_NAME(Vignette);
        SET_GUID_NAME(CallForHelp);
        SET_GUID_NAME(AIResource);
        SET_GUID_NAME(AILock);
        SET_GUID_NAME(AILockTicket);
        SET_GUID_NAME(ChatChannel);
        SET_GUID_NAME(Party);
        SET_GUID_NAME(Guild);
        SET_GUID_NAME(WowAccount);
        SET_GUID_NAME(BNetAccount);
        SET_GUID_NAME(GMTask);
        SET_GUID_NAME(MobileSession);
        SET_GUID_NAME(RaidGroup);
        SET_GUID_NAME(Spell);
        SET_GUID_NAME(Mail);
        SET_GUID_NAME(WebObj);
        SET_GUID_NAME(LFGObject);
        SET_GUID_NAME(LFGList);
        SET_GUID_NAME(UserRouter);
        SET_GUID_NAME(PVPQueueGroup);
        SET_GUID_NAME(UserClient);
        SET_GUID_NAME(PetBattle);
        SET_GUID_NAME(UniqUserClient);
        SET_GUID_NAME(BattlePet);
        SET_GUID_NAME(CommerceObj);
        SET_GUID_NAME(ClientSession);
        SET_GUID_NAME(Cast);
        SET_GUID_NAME(ClientConnection);

#undef SET_GUID_NAME
    }

}

char const* ObjectGuid::GetTypeName(HighGuid high)
{
    if (high >= HighGuid::Count)
        return "<unknown>";

    return Names.Values[uint32(high)];
}

std::string ObjectGuid::ToString() const
{
    std::ostringstream str;
    str << "GUID Full: 0x" << std::hex << std::uppercase << std::setw(16) << std::setfill('0') << _high << std::setw(16) << _low << std::dec << std::nouppercase;
    str << " Type: " << GetTypeName();
    if (HasEntry())
        str << (IsPet() ? " Pet number: " : " Entry: ") << GetEntry();

    str << " Low: " << GetCounter();
    return str.str();
}

std::size_t ObjectGuid::GetHash() const
{
    std::size_t hashVal = 0;
    Trinity::hash_combine(hashVal, _low);
    Trinity::hash_combine(hashVal, _high);
    return hashVal;
}

ObjectGuid ObjectGuid::Global(HighGuid type, LowType counter)
{
    return ObjectGuid(uint64(uint64(type) << 58), counter);
}

ObjectGuid ObjectGuid::RealmSpecific(HighGuid type, LowType counter)
{
    return ObjectGuid(uint64(uint64(type) << 58 | uint64(realm.Id.Realm) << 42), counter);
}

ObjectGuid ObjectGuid::MapSpecific(HighGuid type, uint8 subType, uint16 mapId, uint32 serverId, uint32 entry, LowType counter)
{
    return ObjectGuid(uint64((uint64(type) << 58) | (uint64(realm.Id.Realm & 0x1FFF) << 42) | (uint64(mapId & 0x1FFF) << 29) | (uint64(entry & 0x7FFFFF) << 6) | (uint64(subType) & 0x3F)),
        uint64((uint64(serverId & 0xFFFFFF) << 40) | (counter & UI64LIT(0xFFFFFFFFFF))));
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

ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid)
{
    uint8 lowMask = 0;
    uint8 highMask = 0;
    buf.FlushBits();    // flush any unwritten bits to make wpos return a meaningful value
    std::size_t pos = buf.wpos();
    buf << uint8(lowMask);
    buf << uint8(highMask);

    uint8 packed[8];
    if (size_t packedSize = ByteBuffer::PackUInt64(guid._low, &lowMask, packed))
        buf.append(packed, packedSize);
    if (size_t packedSize = ByteBuffer::PackUInt64(guid._high, &highMask, packed))
        buf.append(packed, packedSize);

    buf.put(pos, lowMask);
    buf.put(pos + 1, highMask);

    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid& guid)
{
    uint8 lowMask, highMask;
    buf >> lowMask >> highMask;
    buf.ReadPackedUInt64(lowMask, guid._low);
    buf.ReadPackedUInt64(highMask, guid._high);
    return buf;
}

std::ostream& operator<<(std::ostream& stream, ObjectGuid const& guid)
{
    std::ostringstream tmp;
    tmp << std::hex << std::setw(16) << std::setfill('0') << guid._high << std::setw(16) << std::setfill('0') << guid._low;
    stream << tmp.str();
    return stream;
}

ObjectGuid const ObjectGuid::Empty = ObjectGuid();
ObjectGuid const ObjectGuid::TradeItem = ObjectGuid::Create<HighGuid::Uniq>(uint64(10));

void ObjectGuidGeneratorBase::HandleCounterOverflow(HighGuid high)
{
    TC_LOG_ERROR("misc", "%s guid overflow!! Can't continue, shutting down server. ", ObjectGuid::GetTypeName(high));
    World::StopNow(ERROR_EXIT_CODE);
}

#define GUID_TRAIT_INSTANTIATE_GUID( HIGH_GUID ) \
    template class TC_GAME_API ObjectGuidGenerator< HIGH_GUID >;

GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Player)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Item)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Transport)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Guild)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Conversation)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Creature)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Vehicle)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Pet)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::GameObject)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::DynamicObject)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::AreaTrigger)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Corpse)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::LootObject)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::SceneObject)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Scenario)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::AIGroup)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::DynamicDoor)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Vignette)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::CallForHelp)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::AIResource)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::AILock)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::AILockTicket)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Cast)
