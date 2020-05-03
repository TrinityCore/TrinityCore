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

#include "ObjectGuid.h"
#include "ByteBuffer.h"
#include "Containers.h"
#include "Errors.h"
#include "Hash.h"
#include "Log.h"
#include "Realm.h"
#include "Util.h"
#include "World.h"

static_assert(sizeof(ObjectGuid) == sizeof(uint64) * 2, "ObjectGuid must be exactly 16 bytes");

namespace
{
    struct ObjectGuidInfo
    {
        char const* Names[AsUnderlyingType(HighGuid::Count)];
        std::string(ObjectGuidInfo::*ClientFormatFunction[AsUnderlyingType(HighGuid::Count)])(char const*, ObjectGuid guid);

        std::string Format(ObjectGuid guid)
        {
            if (guid.GetHigh() >= HighGuid::Count)
                return "Uniq-WOWGUID_TO_STRING_FAILED";

            int32 type = AsUnderlyingType(guid.GetHigh());
            if (!ClientFormatFunction[type])
                return "Uniq-WOWGUID_TO_STRING_FAILED";

            return (this->*ClientFormatFunction[type])(Names[type], guid);
        }

        std::string FormatNull(char const*, ObjectGuid)
        {
            return "0000000000000000";
        }

        std::string FormatUniq(char const* typeName, ObjectGuid guid)
        {
            constexpr char const* uniqNames[] =
            {
                nullptr,
                "WOWGUID_UNIQUE_PROBED_DELETE",
                "WOWGUID_UNIQUE_JAM_TEMP",
                "WOWGUID_TO_STRING_FAILED",
                "WOWGUID_FROM_STRING_FAILED",
                "WOWGUID_UNIQUE_SERVER_SELF",
                "WOWGUID_UNIQUE_MAGIC_SELF",
                "WOWGUID_UNIQUE_MAGIC_PET",
                "WOWGUID_UNIQUE_INVALID_TRANSPORT",
                "WOWGUID_UNIQUE_AMMO_ID",
                "WOWGUID_SPELL_TARGET_TRADE_ITEM",
                "WOWGUID_SCRIPT_TARGET_INVALID",
                "WOWGUID_SCRIPT_TARGET_NONE",
                nullptr,
                "WOWGUID_FAKE_MODERATOR",
                nullptr,
                nullptr,
                "WOWGUID_UNIQUE_ACCOUNT_OBJ_INITIALIZATION"
            };

            ObjectGuid::LowType id = guid.GetCounter();
            if (id >= Trinity::Containers::Size(uniqNames))
                id = 3;

            return Trinity::StringFormat("%s-%s", typeName, uniqNames[id]);
        }

        std::string FormatPlayer(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%08llX", typeName, guid.GetRealmId(), guid.GetRawValue(0));
        }

        std::string FormatItem(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%016llX", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 18) & 0xFFFFFF, guid.GetRawValue(0));
        }

        std::string FormatWorldObject(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u-%u-%u-%010llX", typeName, guid.GetSubType(), guid.GetRealmId(), guid.GetMapId(),
                uint32(guid.GetRawValue(0) >> 40) & 0xFFFFFF, guid.GetEntry(), guid.GetCounter());
        }

        std::string FormatTransport(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%016llX", typeName, uint32(guid.GetRawValue(1) >> 38) & 0xFFFFF, guid.GetRawValue(0));
        }

        std::string FormatClientActor(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 26) & 0xFFFFFF, uint32(guid.GetRawValue(0)));
        }

        std::string FormatChatChannel(char const* typeName, ObjectGuid guid)
        {
            uint32 builtIn = (guid.GetRawValue(1) >> 25) & 0x1;
            uint32 trade = (guid.GetRawValue(1) >> 24) & 0x1;
            uint32 zoneId = (guid.GetRawValue(1) >> 10) & 0x3FFF;
            uint32 factionGroupMask = (guid.GetRawValue(1) >> 4) & 0x3F;
            return Trinity::StringFormat("%s-%u-%u-%u-%u-%u-%08llX", typeName, guid.GetRealmId(), builtIn, trade, zoneId, factionGroupMask, guid.GetRawValue(0));
        }

        std::string FormatGlobal(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%llu-%012llX", typeName, guid.GetRawValue(1) & 0x3FFFFFFFFFFFFFF, guid.GetRawValue(0));
        }

        std::string FormatGuild(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%012llX", typeName, guid.GetRealmId(), guid.GetRawValue(0));
        }

        std::string FormatMobileSession(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%08llX", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 33) & 0x1FF, guid.GetRawValue(0));
        }

        std::string FormatWebObj(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u-%012llX", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 37) & 0x1F,
                uint32(guid.GetRawValue(1) >> 35) & 0x3, guid.GetRawValue(0));
        }

        std::string FormatLFGObject(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u-%u-%u-%u-%06llX", typeName, uint32(guid.GetRawValue(1) >> 54) & 0xF, uint32(guid.GetRawValue(1) >> 50) & 0xF,
                uint32(guid.GetRawValue(1) >> 46) & 0xF, uint32(guid.GetRawValue(1) >> 38) & 0xFF, uint32(guid.GetRawValue(1) >> 37) & 0x1,
                uint32(guid.GetRawValue(1) >> 35) & 0x3, guid.GetRawValue(0));
        }

        std::string FormatLFGList(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%06llX", typeName, uint32(guid.GetRawValue(1) >> 54) & 0xF, guid.GetRawValue(0));
        }

        std::string FormatClient(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%012llX", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 10) & 0xFFFFFFFF, guid.GetRawValue(0));
        }

        std::string FormatClubFinder(char const* typeName, ObjectGuid guid)
        {
            uint32 type = uint32(guid.GetRawValue(1) >> 33) & 0xFF;
            uint32 clubFinderId = uint32(guid.GetRawValue(1)) & 0xFFFFFFFF;
            if (type == 1) // guild
                return Trinity::StringFormat("%s-%u-%u-%u-%llu", typeName, type, clubFinderId, guid.GetRealmId(), guid.GetRawValue(0) /*guildId*/);

            return Trinity::StringFormat("%s-%u-%u-%016llX", typeName, type, clubFinderId, guid.GetRawValue(0) /*clubId*/);
        }

        ObjectGuidInfo();
    } Info;

    ObjectGuidInfo::ObjectGuidInfo()
    {
#define SET_GUID_INFO(type, format) Names[AsUnderlyingType(HighGuid::type)] = #type; ClientFormatFunction[AsUnderlyingType(HighGuid::type)] = &ObjectGuidInfo::format;

        SET_GUID_INFO(Null, FormatNull);
        SET_GUID_INFO(Uniq, FormatUniq);
        SET_GUID_INFO(Player, FormatPlayer);
        SET_GUID_INFO(Item, FormatItem);
        SET_GUID_INFO(WorldTransaction, FormatWorldObject);
        SET_GUID_INFO(StaticDoor, FormatTransport);
        SET_GUID_INFO(Transport, FormatTransport);
        SET_GUID_INFO(Conversation, FormatWorldObject);
        SET_GUID_INFO(Creature, FormatWorldObject);
        SET_GUID_INFO(Vehicle, FormatWorldObject);
        SET_GUID_INFO(Pet, FormatWorldObject);
        SET_GUID_INFO(GameObject, FormatWorldObject);
        SET_GUID_INFO(DynamicObject, FormatWorldObject);
        SET_GUID_INFO(AreaTrigger, FormatWorldObject);
        SET_GUID_INFO(Corpse, FormatWorldObject);
        SET_GUID_INFO(LootObject, FormatWorldObject);
        SET_GUID_INFO(SceneObject, FormatWorldObject);
        SET_GUID_INFO(Scenario, FormatWorldObject);
        SET_GUID_INFO(AIGroup, FormatWorldObject);
        SET_GUID_INFO(DynamicDoor, FormatWorldObject);
        SET_GUID_INFO(ClientActor, FormatClientActor);
        SET_GUID_INFO(Vignette, FormatWorldObject);
        SET_GUID_INFO(CallForHelp, FormatWorldObject);
        SET_GUID_INFO(AIResource, FormatWorldObject);
        SET_GUID_INFO(AILock, FormatWorldObject);
        SET_GUID_INFO(AILockTicket, FormatWorldObject);
        SET_GUID_INFO(ChatChannel, FormatChatChannel);
        SET_GUID_INFO(Party, FormatGlobal);
        SET_GUID_INFO(Guild, FormatGuild);
        SET_GUID_INFO(WowAccount, FormatGlobal);
        SET_GUID_INFO(BNetAccount, FormatGlobal);
        SET_GUID_INFO(GMTask, FormatGlobal);
        SET_GUID_INFO(MobileSession, FormatMobileSession);
        SET_GUID_INFO(RaidGroup, FormatGlobal);
        SET_GUID_INFO(Spell, FormatGlobal);
        SET_GUID_INFO(Mail, FormatGlobal);
        SET_GUID_INFO(WebObj, FormatWebObj);
        SET_GUID_INFO(LFGObject, FormatLFGObject);
        SET_GUID_INFO(LFGList, FormatLFGList);
        SET_GUID_INFO(UserRouter, FormatGlobal);
        SET_GUID_INFO(PVPQueueGroup, FormatGlobal);
        SET_GUID_INFO(UserClient, FormatGlobal);
        SET_GUID_INFO(PetBattle, FormatClient);
        SET_GUID_INFO(UniqUserClient, FormatClient);
        SET_GUID_INFO(BattlePet, FormatGlobal);
        SET_GUID_INFO(CommerceObj, FormatGlobal);
        SET_GUID_INFO(ClientSession, FormatClient);
        SET_GUID_INFO(Cast, FormatWorldObject);
        SET_GUID_INFO(ClientConnection, FormatClient);
        SET_GUID_INFO(ClubFinder, FormatClubFinder);

#undef SET_GUID_INFO
    }
}

char const* ObjectGuid::GetTypeName(HighGuid high)
{
    if (high >= HighGuid::Count)
        return "<unknown>";

    return Info.Names[uint32(high)];
}

std::string ObjectGuid::ToString() const
{
    return Info.Format(*this);
}

std::string ObjectGuid::ToHexString() const
{
    return Trinity::StringFormat("0x%016llX%016llX", _data[1], _data[0]);
}

std::size_t ObjectGuid::GetHash() const
{
    std::size_t hashVal = 0;
    Trinity::hash_combine(hashVal, _data[0]);
    Trinity::hash_combine(hashVal, _data[1]);
    return hashVal;
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

ObjectGuid ObjectGuidFactory::CreateNull()
{
    return ObjectGuid();
}

ObjectGuid ObjectGuidFactory::CreateUniq(ObjectGuid::LowType id)
{
    return ObjectGuid(uint64(uint64(HighGuid::Uniq) << 58),
        id);
}

ObjectGuid ObjectGuidFactory::CreatePlayer(ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(HighGuid::Player) << 58)
        | (uint64(realm.Id.Realm) << 42)),
        dbId);
}

ObjectGuid ObjectGuidFactory::CreateItem(ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(HighGuid::Item) << 58)
        | (uint64(realm.Id.Realm) << 42)),
        dbId);
}

ObjectGuid ObjectGuidFactory::CreateWorldObject(HighGuid type, uint8 subType, uint16 mapId, uint32 serverId, uint32 entry, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(type) << 58)
        | (uint64(realm.Id.Realm & 0x1FFF) << 42)
        | (uint64(mapId & 0x1FFF) << 29)
        | (uint64(entry & 0x7FFFFF) << 6)
        | (uint64(subType) & 0x3F)),
        uint64((uint64(serverId & 0xFFFFFF) << 40)
        | (counter & UI64LIT(0xFFFFFFFFFF))));
}

ObjectGuid ObjectGuidFactory::CreateTransport(HighGuid type, uint32 counter)
{
    return ObjectGuid(uint64((uint64(type) << 58)
        | (uint64(counter) << 38)),
        UI64LIT(0));
}

ObjectGuid ObjectGuidFactory::CreateClientActor(uint16 ownerType, uint16 ownerId, uint32 counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::ClientActor) << 58)
        | (uint64(ownerType & 0x1FFF) << 42)
        | (uint64(ownerId & 0xFFFFFF) << 26)),
        uint64(counter));
}

ObjectGuid ObjectGuidFactory::CreateChatChannel(bool builtIn, bool trade, uint16 zoneId, uint8 factionGroupMask, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::ChatChannel) << 58)
        | (uint64(realm.Id.Realm & 0x1FFF) << 42)
        | (uint64(builtIn) << 25)
        | (uint64(trade) << 24)
        | (uint64(zoneId & 0x3FFF) << 10)
        | (uint64(factionGroupMask & 0x3F) << 4)),
        counter);
}

ObjectGuid ObjectGuidFactory::CreateGlobal(HighGuid type, ObjectGuid::LowType dbIdHigh, ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(type) << 58)
        | (uint64(dbIdHigh & UI64LIT(0x3FFFFFFFFFFFFFF)))),
        dbId);
}

ObjectGuid ObjectGuidFactory::CreateGuild(ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(HighGuid::Guild) << 58)
        | (uint64(realm.Id.Realm) << 42)),
        dbId);
}

ObjectGuid ObjectGuidFactory::CreateMobileSession(uint16 arg1, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::MobileSession) << 58)
        | (uint64(realm.Id.Realm) << 42)
        | (uint64(arg1 & 0x1FF) << 33)),
        counter);
}

ObjectGuid ObjectGuidFactory::CreateWebObj(uint8 arg1, uint8 arg2, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::WebObj) << 58)
        | (uint64(realm.Id.Realm & 0x1FFF) << 42)
        | (uint64(arg1 & 0x1F) << 37)
        | (uint64(arg2 & 0x3) << 35)),
        counter);
}

ObjectGuid ObjectGuidFactory::CreateLFGObject(uint8 arg1, uint8 arg2, uint8 arg3, uint8 arg4, bool arg5, uint8 arg6, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::LFGObject) << 58)
        | (uint64(arg1 & 0xF) << 54)
        | (uint64(arg2 & 0xF) << 50)
        | (uint64(arg3 & 0xF) << 46)
        | (uint64(arg4 & 0xFF) << 38)
        | (uint64(arg5 ? 1 : 0) << 37)
        | (uint64(arg6 & 0x3) << 35)),
        counter);
}

ObjectGuid ObjectGuidFactory::CreateLFGList(uint8 arg1, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::LFGObject) << 58)
        | (uint64(arg1 & 0xF) << 54)),
        counter);
}

ObjectGuid ObjectGuidFactory::CreateClient(HighGuid type, uint32 arg1, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(type) << 58)
        | (uint64(realm.Id.Realm & 0x1FFF) << 42)
        | (uint64(arg1 & 0xFFFFFFFF) << 10)),
        counter);
}

ObjectGuid ObjectGuidFactory::CreateClubFinder(uint8 type, uint32 clubFinderId, ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(HighGuid::ClubFinder) << 58)
        | (type == 1 ? (uint64(realm.Id.Realm & 0x1FFF) << 42) : UI64LIT(0))
        | (uint64(type & 0xFF) << 33)
        | (uint64(clubFinderId & 0xFFFFFFFF))),
        dbId);
}

ObjectGuid const ObjectGuid::Empty = ObjectGuid();
ObjectGuid const ObjectGuid::TradeItem = ObjectGuid::Create<HighGuid::Uniq>(UI64LIT(10));

ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid)
{
    uint8 lowMask = 0;
    uint8 highMask = 0;
    buf.FlushBits();    // flush any unwritten bits to make wpos return a meaningful value
    std::size_t pos = buf.wpos();
    buf << uint8(lowMask);
    buf << uint8(highMask);

    uint8 packed[8];
    if (size_t packedSize = ByteBuffer::PackUInt64(guid._data[0], &lowMask, packed))
        buf.append(packed, packedSize);
    if (size_t packedSize = ByteBuffer::PackUInt64(guid._data[1], &highMask, packed))
        buf.append(packed, packedSize);

    buf.put(pos, lowMask);
    buf.put(pos + 1, highMask);

    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid& guid)
{
    uint8 lowMask, highMask;
    buf >> lowMask >> highMask;
    buf.ReadPackedUInt64(lowMask, guid._data[0]);
    buf.ReadPackedUInt64(highMask, guid._data[1]);
    return buf;
}

void ObjectGuidGeneratorBase::HandleCounterOverflow(HighGuid high)
{
    TC_LOG_ERROR("misc", "%s guid overflow!! Can't continue, shutting down server. ", ObjectGuid::GetTypeName(high));
    World::StopNow(ERROR_EXIT_CODE);
}

template class TC_GAME_API ObjectGuidGenerator<HighGuid::Null>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Uniq>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Player>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Item>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::WorldTransaction>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::StaticDoor>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Transport>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Conversation>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Creature>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Vehicle>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Pet>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::GameObject>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::DynamicObject>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::AreaTrigger>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Corpse>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::LootObject>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::SceneObject>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Scenario>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::AIGroup>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::DynamicDoor>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::ClientActor>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Vignette>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::CallForHelp>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::AIResource>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::AILock>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::AILockTicket>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::ChatChannel>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Party>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Guild>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::WowAccount>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::BNetAccount>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::GMTask>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::MobileSession>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::RaidGroup>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Spell>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Mail>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::WebObj>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::LFGObject>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::LFGList>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::UserRouter>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::PVPQueueGroup>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::UserClient>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::PetBattle>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::UniqUserClient>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::BattlePet>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::CommerceObj>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::ClientSession>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::Cast>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::ClientConnection>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::ClubFinder>;
