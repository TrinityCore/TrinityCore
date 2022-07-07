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
        std::string Names[AsUnderlyingType(HighGuid::Count)];
        std::string(ObjectGuidInfo::*ClientFormatFunction[AsUnderlyingType(HighGuid::Count)])(char const* typeName, ObjectGuid guid);
        ObjectGuid(ObjectGuidInfo::*ClientParseFunction[AsUnderlyingType(HighGuid::Count)])(HighGuid type, char const* guidString);

        std::string Format(ObjectGuid guid)
        {
            if (guid.GetHigh() >= HighGuid::Count)
                return "Uniq-WOWGUID_TO_STRING_FAILED";

            int32 type = AsUnderlyingType(guid.GetHigh());
            if (!ClientFormatFunction[type])
                return "Uniq-WOWGUID_TO_STRING_FAILED";

            return (this->*ClientFormatFunction[type])(Names[type].c_str(), guid);
        }

        ObjectGuid Parse(std::string const& guidString)
        {
            std::size_t typeEnd = guidString.find('-');
            if (typeEnd == std::string::npos)
                return ObjectGuid::FromStringFailed;

            int32 type = 0;
            for (; type < AsUnderlyingType(HighGuid::Count); ++type)
            {
                if (Names[type].length() < typeEnd)
                    continue;

                if (guidString.compare(0, typeEnd, Names[type]) == 0)
                    break;
            }

            if (type >= AsUnderlyingType(HighGuid::Count))
                return ObjectGuid::FromStringFailed;

            return (this->*ClientParseFunction[type])(HighGuid(type), &guidString[typeEnd + 1]);
        }

        std::string FormatNull(char const*, ObjectGuid)
        {
            return "0000000000000000";
        }

        ObjectGuid ParseNull(HighGuid, char const*)
        {
            return ObjectGuid::Empty;
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
            if (id >= std::size(uniqNames))
                id = 3;

            return Trinity::StringFormat("%s-%s", typeName, uniqNames[id]);
        }

        ObjectGuid ParseUniq(HighGuid /*type*/, char const* guidString)
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

            for (std::size_t id = 0; id < std::size(uniqNames); ++id)
            {
                if (!uniqNames[id])
                    continue;

                if (strcmp(guidString, uniqNames[id]) == 0)
                    return ObjectGuidFactory::CreateUniq(id);
            }

            return ObjectGuid::FromStringFailed;
        }

        std::string FormatPlayer(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%08llX", typeName, guid.GetRealmId(), guid.GetRawValue(0));
        }

        ObjectGuid ParsePlayer(HighGuid /*type*/, char const* guidString)
        {
            uint32 realmId = 0;
            uint64 dbId = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%08" SCNx64, &realmId, &dbId) != 2)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreatePlayer(realmId, dbId);
        }

        std::string FormatItem(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%016llX", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 18) & 0xFFFFFF, guid.GetRawValue(0));
        }

        ObjectGuid ParseItem(HighGuid /*type*/, char const* guidString)
        {
            uint32 realmId = 0;
            uint32 arg1 = 0;
            uint64 dbId = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%u-%016" SCNx64, &realmId, &arg1, &dbId) != 3)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateItem(realmId, dbId);
        }

        std::string FormatWorldObject(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u-%u-%u-%010llX", typeName, guid.GetSubType(), guid.GetRealmId(), guid.GetMapId(),
                uint32(guid.GetRawValue(0) >> 40) & 0xFFFFFF, guid.GetEntry(), guid.GetCounter());
        }

        ObjectGuid ParseWorldObject(HighGuid type, char const* guidString)
        {
            uint32 subType = 0;
            uint32 realmId = 0;
            uint32 mapId = 0;
            uint32 serverId = 0;
            uint32 id = 0;
            uint64 counter = UI64LIT(0);
            if (std::sscanf(guidString, "%u-%u-%u-%u-%u-%010" SCNx64, &subType, &realmId, &mapId, &serverId, &id, &counter) != 6)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateWorldObject(type, subType, realmId, mapId, serverId, id, counter);
        }

        std::string FormatTransport(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%016llX", typeName, uint32(guid.GetRawValue(1) >> 38) & 0xFFFFF, guid.GetRawValue(0));
        }

        ObjectGuid ParseTransport(HighGuid type, char const* guidString)
        {
            uint32 id = 0;
            uint64 counter = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%016" SCNx64, &id, &counter) != 2)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateTransport(type, counter);
        }

        std::string FormatClientActor(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 26) & 0xFFFFFF, uint32(guid.GetRawValue(0)));
        }

        ObjectGuid ParseClientActor(HighGuid /*type*/, char const* guidString)
        {
            uint32 ownerType = 0;
            uint32 ownerId = 0;
            uint32 counter = 0;

            if (std::sscanf(guidString, "%u-%u-%u", &ownerType, &ownerId, &counter) != 3)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateClientActor(ownerType, ownerId, counter);
        }

        std::string FormatChatChannel(char const* typeName, ObjectGuid guid)
        {
            uint32 builtIn = (guid.GetRawValue(1) >> 25) & 0x1;
            uint32 trade = (guid.GetRawValue(1) >> 24) & 0x1;
            uint32 zoneId = (guid.GetRawValue(1) >> 10) & 0x3FFF;
            uint32 factionGroupMask = (guid.GetRawValue(1) >> 4) & 0x3F;
            return Trinity::StringFormat("%s-%u-%u-%u-%u-%u-%08llX", typeName, guid.GetRealmId(), builtIn, trade, zoneId, factionGroupMask, guid.GetRawValue(0));
        }

        ObjectGuid ParseChatChannel(HighGuid /*type*/, char const* guidString)
        {
            uint32 realmId = 0;
            uint32 builtIn = 0;
            uint32 trade = 0;
            uint32 zoneId = 0;
            uint32 factionGroupMask = 0;
            uint64 id = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%u-%u-%u-%u-%08" SCNx64, &realmId, &builtIn, &trade, &zoneId, &factionGroupMask, &id) != 6)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateChatChannel(realmId, builtIn != 0, trade != 0, zoneId, factionGroupMask, id);
        }

        std::string FormatGlobal(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%llu-%012llX", typeName, guid.GetRawValue(1) & 0x3FFFFFFFFFFFFFF, guid.GetRawValue(0));
        }

        ObjectGuid ParseGlobal(HighGuid type, char const* guidString)
        {
            uint64 dbIdHigh = UI64LIT(0);
            uint64 dbIdLow = UI64LIT(0);

            if (std::sscanf(guidString, "%" SCNu64 "-%012" SCNx64, &dbIdHigh, &dbIdLow) != 2)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateGlobal(type, dbIdHigh, dbIdLow);
        }

        std::string FormatGuild(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%012llX", typeName, guid.GetRealmId(), guid.GetRawValue(0));
        }

        ObjectGuid ParseGuild(HighGuid type, char const* guidString)
        {
            uint32 realmId = 0;
            uint64 dbId = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%012" SCNx64, &realmId, &dbId) != 2)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateGuild(type, realmId, dbId);
        }

        std::string FormatMobileSession(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%08llX", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 33) & 0x1FF, guid.GetRawValue(0));
        }

        ObjectGuid ParseMobileSession(HighGuid /*type*/, char const* guidString)
        {
            uint32 realmId = 0;
            uint32 arg1 = 0;
            uint64 counter = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%u-%08" SCNx64, &realmId, &arg1, &counter) != 3)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateMobileSession(realmId, arg1, counter);
        }

        std::string FormatWebObj(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u-%012llX", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 37) & 0x1F,
                uint32(guid.GetRawValue(1) >> 35) & 0x3, guid.GetRawValue(0));
        }

        ObjectGuid ParseWebObj(HighGuid /*type*/, char const* guidString)
        {
            uint32 realmId = 0;
            uint32 arg1 = 0;
            uint32 arg2 = 0;
            uint64 counter = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%u-%u-%012" SCNx64, &realmId, &arg1, &arg2, &counter) != 4)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateWebObj(realmId, arg1, arg2, counter);
        }

        std::string FormatLFGObject(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u-%u-%u-%u-%06llX", typeName, uint32(guid.GetRawValue(1) >> 54) & 0xF, uint32(guid.GetRawValue(1) >> 50) & 0xF,
                uint32(guid.GetRawValue(1) >> 46) & 0xF, uint32(guid.GetRawValue(1) >> 38) & 0xFF, uint32(guid.GetRawValue(1) >> 37) & 0x1,
                uint32(guid.GetRawValue(1) >> 35) & 0x3, guid.GetRawValue(0));
        }

        ObjectGuid ParseLFGObject(HighGuid /*type*/, char const* guidString)
        {
            uint32 arg1 = 0;
            uint32 arg2 = 0;
            uint32 arg3 = 0;
            uint32 arg4 = 0;
            uint32 arg5 = 0;
            uint32 arg6 = 0;
            uint64 counter = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%u-%u-%u-%u-%u-%06" SCNx64, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &counter) != 7)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateLFGObject(arg1, arg2, arg3, arg4, arg5 != 0, arg6, counter);
        }

        std::string FormatLFGList(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%06llX", typeName, uint32(guid.GetRawValue(1) >> 54) & 0xF, guid.GetRawValue(0));
        }

        ObjectGuid ParseLFGList(HighGuid /*type*/, char const* guidString)
        {
            uint32 arg1 = 0;
            uint64 counter = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%06" SCNx64, &arg1, &counter) != 2)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateLFGList(arg1, counter);
        }

        std::string FormatClient(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%012llX", typeName, guid.GetRealmId(), uint32(guid.GetRawValue(1) >> 10) & 0xFFFFFFFF, guid.GetRawValue(0));
        }

        ObjectGuid ParseClient(HighGuid type, char const* guidString)
        {
            uint32 realmId = 0;
            uint32 arg1 = 0;
            uint64 counter = UI64LIT(0);

            if (std::sscanf(guidString, "%u-%u-%012" SCNx64, &realmId, &arg1, &counter) != 3)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateClient(type, realmId, arg1, counter);
        }

        std::string FormatClubFinder(char const* typeName, ObjectGuid guid)
        {
            uint32 type = uint32(guid.GetRawValue(1) >> 33) & 0xFF;
            uint32 clubFinderId = uint32(guid.GetRawValue(1)) & 0xFFFFFFFF;
            if (type == 1) // guild
                return Trinity::StringFormat("%s-%u-%u-%u-%llu", typeName, type, clubFinderId, guid.GetRealmId(), guid.GetRawValue(0) /*guildId*/);

            return Trinity::StringFormat("%s-%u-%u-%016llX", typeName, type, clubFinderId, guid.GetRawValue(0) /*clubId*/);
        }

        ObjectGuid ParseClubFinder(HighGuid /*type*/, char const* guidString)
        {
            uint32 type = 0;
            uint32 consumed = 0;

            if (std::sscanf(guidString, "%u-%n", &type, &consumed) != 1)
                return ObjectGuid::FromStringFailed;

            uint32 clubFinderId = 0;
            uint32 realmId = 0;
            uint64 dbId = UI64LIT(0);

            switch (type)
            {
                case 0: // club
                    if (std::sscanf(guidString + consumed, "%u-%016" SCNx64, &clubFinderId, &dbId) != 2)
                        return ObjectGuid::FromStringFailed;
                    break;
                case 1: // guild
                    if (std::sscanf(guidString + consumed, "%u-%u-%016" SCNx64, &clubFinderId, &realmId, &dbId) != 3)
                        return ObjectGuid::FromStringFailed;
                    break;
                default:
                    return ObjectGuid::FromStringFailed;
            }

            return ObjectGuidFactory::CreateClubFinder(realmId, type, clubFinderId, dbId);
        }

        std::string FormatToolsClient(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%u-%u-%u-%010llX", typeName, guid.GetMapId(), uint32(guid.GetRawValue(0) >> 40) & 0xFFFFFF, guid.GetCounter());
        }

        ObjectGuid ParseToolsClient(HighGuid /*type*/, char const* guidString)
        {
            uint32 mapId = 0;
            uint32 serverId = 0;
            uint64 counter = UI64LIT(0);
            if (std::sscanf(guidString, "%u-%u-%010" SCNx64, &mapId, &serverId, &counter) != 3)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateToolsClient(mapId, serverId, counter);
        }

        std::string FormatWorldLayer(char const* typeName, ObjectGuid guid)
        {
            return Trinity::StringFormat("%s-%X-%u-%u-%u", typeName, uint32((guid.GetRawValue(1) >> 10) & 0xFFFFFFFF), uint32(guid.GetRawValue(1) & 0x1FF),
                uint32((guid.GetRawValue(0) >> 24) & 0xFF), uint32(guid.GetRawValue(0) & 0x7FFFFF));
        }

        ObjectGuid ParseWorldLayer(HighGuid /*type*/, char const* guidString)
        {
            uint32 arg1 = 0;
            uint16 arg2 = 0;
            uint8 arg3 = 0;
            uint32 arg4 = 0;
            if (std::sscanf(guidString, "%x-%hu-%hhu-%u", &arg1, &arg2, &arg3, &arg4) != 4)
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateWorldLayer(arg1, arg2, arg3, arg4);
        }

        ObjectGuidInfo();
    } Info;

    ObjectGuidInfo::ObjectGuidInfo()
    {
#define SET_GUID_INFO(type, format, parse) \
            Names[AsUnderlyingType(HighGuid::type)] = #type;\
            ClientFormatFunction[AsUnderlyingType(HighGuid::type)] = &ObjectGuidInfo::format;\
            ClientParseFunction[AsUnderlyingType(HighGuid::type)] = &ObjectGuidInfo::parse;

        SET_GUID_INFO(Null, FormatNull, ParseNull);
        SET_GUID_INFO(Uniq, FormatUniq, ParseUniq);
        SET_GUID_INFO(Player, FormatPlayer, ParsePlayer);
        SET_GUID_INFO(Item, FormatItem, ParseItem);
        SET_GUID_INFO(WorldTransaction, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(StaticDoor, FormatTransport, ParseTransport);
        SET_GUID_INFO(Transport, FormatTransport, ParseTransport);
        SET_GUID_INFO(Conversation, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(Creature, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(Vehicle, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(Pet, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(GameObject, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(DynamicObject, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(AreaTrigger, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(Corpse, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(LootObject, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(SceneObject, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(Scenario, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(AIGroup, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(DynamicDoor, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(ClientActor, FormatClientActor, ParseClientActor);
        SET_GUID_INFO(Vignette, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(CallForHelp, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(AIResource, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(AILock, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(AILockTicket, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(ChatChannel, FormatChatChannel, ParseChatChannel);
        SET_GUID_INFO(Party, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(Guild, FormatGuild, ParseGuild);
        SET_GUID_INFO(WowAccount, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(BNetAccount, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(GMTask, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(MobileSession, FormatMobileSession, ParseMobileSession);
        SET_GUID_INFO(RaidGroup, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(Spell, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(Mail, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(WebObj, FormatWebObj, ParseWebObj);
        SET_GUID_INFO(LFGObject, FormatLFGObject, ParseLFGObject);
        SET_GUID_INFO(LFGList, FormatLFGList, ParseLFGList);
        SET_GUID_INFO(UserRouter, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(PVPQueueGroup, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(UserClient, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(PetBattle, FormatClient, ParseClient);
        SET_GUID_INFO(UniqUserClient, FormatClient, ParseClient);
        SET_GUID_INFO(BattlePet, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(CommerceObj, FormatGlobal, ParseGlobal);
        SET_GUID_INFO(ClientSession, FormatClient, ParseClient);
        SET_GUID_INFO(Cast, FormatWorldObject, ParseWorldObject);
        SET_GUID_INFO(ClientConnection, FormatClient, ParseClient);
        SET_GUID_INFO(ClubFinder, FormatClubFinder, ParseClubFinder);
        SET_GUID_INFO(ToolsClient, FormatToolsClient, ParseToolsClient);
        SET_GUID_INFO(WorldLayer, FormatWorldLayer, ParseWorldLayer);
        SET_GUID_INFO(ArenaTeam, FormatGuild, ParseGuild);

#undef SET_GUID_INFO
    }
}

char const* ObjectGuid::GetTypeName(HighGuid high)
{
    if (high >= HighGuid::Count)
        return "<unknown>";

    return Info.Names[uint32(high)].c_str();
}

std::string ObjectGuid::ToString() const
{
    return Info.Format(*this);
}

std::string ObjectGuid::ToHexString() const
{
    return Trinity::StringFormat("0x%016llX%016llX", _data[1], _data[0]);
}

ObjectGuid ObjectGuid::FromString(std::string const& guidString)
{
    return Info.Parse(guidString);
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

static inline uint32 GetRealmIdForObjectGuid(uint32 realmId)
{
    if (realmId)
        return realmId;

    return realm.Id.Realm;
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

ObjectGuid ObjectGuidFactory::CreatePlayer(uint32 realmId, ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(HighGuid::Player) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId)) << 42)),
        dbId);
}

ObjectGuid ObjectGuidFactory::CreateItem(uint32 realmId, ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(HighGuid::Item) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId)) << 42)),
        dbId);
}

ObjectGuid ObjectGuidFactory::CreateWorldObject(HighGuid type, uint8 subType, uint32 realmId, uint16 mapId, uint32 serverId, uint32 entry, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(type) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId) & 0x1FFF) << 42)
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

ObjectGuid ObjectGuidFactory::CreateChatChannel(uint32 realmId, bool builtIn, bool trade, uint16 zoneId, uint8 factionGroupMask, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::ChatChannel) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId) & 0x1FFF) << 42)
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

ObjectGuid ObjectGuidFactory::CreateGuild(HighGuid type, uint32 realmId, ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(type) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId)) << 42)),
        dbId);
}

ObjectGuid ObjectGuidFactory::CreateMobileSession(uint32 realmId, uint16 arg1, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::MobileSession) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId)) << 42)
        | (uint64(arg1 & 0x1FF) << 33)),
        counter);
}

ObjectGuid ObjectGuidFactory::CreateWebObj(uint32 realmId, uint8 arg1, uint8 arg2, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::WebObj) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId) & 0x1FFF) << 42)
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

ObjectGuid ObjectGuidFactory::CreateClient(HighGuid type, uint32 realmId, uint32 arg1, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(type) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId) & 0x1FFF) << 42)
        | (uint64(arg1 & 0xFFFFFFFF) << 10)),
        counter);
}

ObjectGuid ObjectGuidFactory::CreateClubFinder(uint32 realmId, uint8 type, uint32 clubFinderId, ObjectGuid::LowType dbId)
{
    return ObjectGuid(uint64((uint64(HighGuid::ClubFinder) << 58)
        | (type == 1 ? (uint64(GetRealmIdForObjectGuid(realmId) & 0x1FFF) << 42) : UI64LIT(0))
        | (uint64(type & 0xFF) << 33)
        | (uint64(clubFinderId & 0xFFFFFFFF))),
        dbId);
}

ObjectGuid ObjectGuidFactory::CreateToolsClient(uint16 mapId, uint32 serverId, uint64 counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::ToolsClient) << 58)
        | uint64(mapId)),
        uint64((uint64(serverId & 0xFFFFFF) << 40)
        | (counter & UI64LIT(0xFFFFFFFFFF))));
}

ObjectGuid ObjectGuidFactory::CreateWorldLayer(uint32 arg1, uint16 arg2, uint8 arg3, uint32 arg4)
{
    return ObjectGuid(uint64((uint64(HighGuid::WorldLayer) << 58)
        | (uint64(arg1 & 0xFFFFFFFF) << 10)
        | (uint64(arg2 & 0x1FF))),
        uint64((uint64(arg3 & 0xFF) << 24)
        | uint64(arg4 & 0x7FFFFF)));
}

ObjectGuid const ObjectGuid::Empty = ObjectGuid();
ObjectGuid const ObjectGuid::FromStringFailed = ObjectGuid::Create<HighGuid::Uniq>(UI64LIT(4));
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

void ObjectGuidGeneratorBase::CheckGuidTrigger(ObjectGuid::LowType guidlow)
{
    if (!sWorld->IsGuidAlert() && guidlow > sWorld->getIntConfig(CONFIG_RESPAWN_GUIDALERTLEVEL))
        sWorld->TriggerGuidAlert();
    else if (!sWorld->IsGuidWarning() && guidlow > sWorld->getIntConfig(CONFIG_RESPAWN_GUIDWARNLEVEL))
        sWorld->TriggerGuidWarning();
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
template class TC_GAME_API ObjectGuidGenerator<HighGuid::ToolsClient>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::WorldLayer>;
template class TC_GAME_API ObjectGuidGenerator<HighGuid::ArenaTeam>;
