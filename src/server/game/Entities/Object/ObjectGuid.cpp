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
#include <charconv>

static_assert(sizeof(ObjectGuid) == sizeof(uint64) * 2, "ObjectGuid must be exactly 16 bytes");

namespace
{
    struct ObjectGuidInfo
    {
        std::string Names[AsUnderlyingType(HighGuid::Count)];
        fmt::appender(*ClientFormatFunction[AsUnderlyingType(HighGuid::Count)])(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid);
        ObjectGuid(*ClientParseFunction[AsUnderlyingType(HighGuid::Count)])(HighGuid type, std::string_view guidString);

        static std::string Format(ObjectGuid const& guid)
        {
            return Trinity::StringFormat("{}", guid);
        }

        ObjectGuid Parse(std::string_view guidString) const
        {
            std::size_t typeEnd = guidString.find('-');
            if (typeEnd == std::string::npos)
            {
                if (guidString == "0000000000000000")
                    return ObjectGuid::Empty;
                return ObjectGuid::FromStringFailed;
            }

            std::string_view typeStr = guidString.substr(0, typeEnd);
            guidString.remove_prefix(typeEnd + 1);

            // find correct parser for type name
            for (int32 type = 0; type < AsUnderlyingType(HighGuid::Count); ++type)
                if (typeStr == Names[type])
                    return ClientParseFunction[type](HighGuid(type), guidString);

            return ObjectGuid::FromStringFailed;
        }

        struct FormatPadding { std::ptrdiff_t Value; constexpr operator std::ptrdiff_t() const { return Value; } };

        template <std::ptrdiff_t Width>
        static constexpr inline FormatPadding padding{ .Value = Width };
        static constexpr inline FormatPadding no_padding{ .Value = 0 };

        struct FormatBase { int32 Value; constexpr operator int32() const { return Value; } };

        static constexpr inline FormatBase dec{ 10 };
        static constexpr inline FormatBase hex{ 16 };

        static fmt::appender AppendTypeName(fmt::format_context& ctx, std::string const& type)
        {
            return std::copy(type.begin(), type.end(), ctx.out());
        }

        template <FormatPadding Width, FormatBase Base>
        static fmt::appender AppendComponent(fmt::format_context& ctx, uint64 component)
        {
            *ctx.out() = '-';

            std::array<char, 20> buf;
            auto [end, err] = std::to_chars(buf.data(), buf.data() + buf.size(), component, Base);

            ASSERT_NODEBUGINFO(err == std::errc(), "Failed to convert guid part to string");

            if constexpr (Width != 0)
            {
                if (std::distance(buf.data(), end) < Width)
                    std::fill_n(ctx.out(), Width - std::distance(buf.data(), end), '0');
            }

            return std::transform(buf.data(), end, ctx.out(), charToUpper);
        }

        static fmt::appender AppendComponent(fmt::format_context& ctx, std::string_view component)
        {
            *ctx.out() = '-';
            return std::copy(component.begin(), component.end(), ctx.out());
        }

        template <FormatBase Base, typename T>
        static bool ParseComponent(std::string_view& input, T* component)
        {
            auto [end, err] = std::from_chars(input.data(), input.data() + input.length(), *component, Base);
            if (err != std::errc())
                return false;

            input.remove_prefix(end - input.data());
            if (!input.empty())
            {
                if (input[0] != '-')
                    return false;

                input.remove_prefix(1);
            }

            return true;
        }

        static bool ParseDone(std::string_view const& sv) { return sv.empty(); }

        static fmt::appender FormatNull(fmt::format_context& ctx, std::string const& /*typeName*/, ObjectGuid const& /*guid*/)
        {
            return std::fill_n(ctx.out(), 16, '0');
        }

        static ObjectGuid ParseNull(HighGuid, std::string_view)
        {
            return ObjectGuid::Empty;
        }

        static fmt::appender FormatUniq(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
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
                "WOWGUID_UNIQUE_ACCOUNT_OBJ_INITIALIZATION",
                nullptr,
                "WOWGUID_PENDING_PERMANENT_CHARACTER_ASSIGNMENT"
            };

            ObjectGuid::LowType id = guid.GetCounter();
            if (id >= std::size(uniqNames) || !uniqNames[id])
                id = 3;

            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent(ctx, uniqNames[id]));
            return ctx.out();
        }

        static ObjectGuid ParseUniq(HighGuid /*type*/, std::string_view guidString)
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
                "WOWGUID_UNIQUE_ACCOUNT_OBJ_INITIALIZATION",
                nullptr,
                "WOWGUID_PENDING_PERMANENT_CHARACTER_ASSIGNMENT"
            };

            for (std::size_t id = 0; id < std::size(uniqNames); ++id)
            {
                if (!uniqNames[id])
                    continue;

                if (guidString == uniqNames[id])
                    return ObjectGuidFactory::CreateUniq(id);
            }

            return ObjectGuid::FromStringFailed;
        }

        static fmt::appender FormatPlayer(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<padding<8>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParsePlayer(HighGuid /*type*/, std::string_view guidString)
        {
            uint32 realmId = 0;
            uint64 dbId = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<hex>(guidString, &dbId)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreatePlayer(realmId, dbId);
        }

        static fmt::appender FormatItem(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 18 & 0xFFFFFF));
            ctx.advance_to(AppendComponent<padding<16>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseItem(HighGuid /*type*/, std::string_view guidString)
        {
            uint32 realmId = 0;
            uint32 arg1 = 0;
            uint64 dbId = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<dec>(guidString, &arg1)
                || !ParseComponent<hex>(guidString, &dbId)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateItem(realmId, dbId);
        }

        static fmt::appender FormatWorldObject(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetSubType()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetMapId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(0) >> 40 & 0xFFFFFF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetEntry()));
            ctx.advance_to(AppendComponent<padding<10>, hex>(ctx, guid.GetCounter()));
            return ctx.out();
        }

        static ObjectGuid ParseWorldObject(HighGuid type, std::string_view guidString)
        {
            uint8 subType = 0;
            uint32 realmId = 0;
            uint16 mapId = 0;
            uint32 serverId = 0;
            uint32 id = 0;
            uint64 counter = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &subType)
                || !ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<dec>(guidString, &mapId)
                || !ParseComponent<dec>(guidString, &serverId)
                || !ParseComponent<dec>(guidString, &id)
                || !ParseComponent<hex>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateWorldObject(type, subType, realmId, mapId, serverId, id, counter);
        }

        static fmt::appender FormatTransport(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetEntry()));
            ctx.advance_to(AppendComponent<padding<16>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseTransport(HighGuid type, std::string_view guidString)
        {
            uint32 id = 0;
            uint32 counter = 0;

            if (!ParseComponent<dec>(guidString, &id)
                || !ParseComponent<hex>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateTransport(type, counter);
        }

        static fmt::appender FormatClientActor(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 26 & 0xFFFFFF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(0) & 0xFFFFFFFF));
            return ctx.out();
        }

        static ObjectGuid ParseClientActor(HighGuid /*type*/, std::string_view guidString)
        {
            uint16 ownerType = 0;
            uint16 ownerId = 0;
            uint32 counter = 0;

            if (!ParseComponent<dec>(guidString, &ownerType)
                || !ParseComponent<dec>(guidString, &ownerId)
                || !ParseComponent<dec>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateClientActor(ownerType, ownerId, counter);
        }

        static fmt::appender FormatChatChannel(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            uint32 builtIn = (guid.GetRawValue(1) >> 25) & 0x1;
            uint32 trade = (guid.GetRawValue(1) >> 24) & 0x1;
            uint32 zoneId = (guid.GetRawValue(1) >> 10) & 0x3FFF;
            uint32 factionGroupMask = (guid.GetRawValue(1) >> 4) & 0x3F;

            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, builtIn));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, trade));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, zoneId));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, factionGroupMask));
            ctx.advance_to(AppendComponent<padding<8>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseChatChannel(HighGuid /*type*/, std::string_view guidString)
        {
            uint32 realmId = 0;
            uint32 builtIn = 0;
            uint32 trade = 0;
            uint16 zoneId = 0;
            uint8 factionGroupMask = 0;
            uint64 id = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<dec>(guidString, &builtIn)
                || !ParseComponent<dec>(guidString, &trade)
                || !ParseComponent<dec>(guidString, &zoneId)
                || !ParseComponent<dec>(guidString, &factionGroupMask)
                || !ParseComponent<hex>(guidString, &id)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateChatChannel(realmId, builtIn != 0, trade != 0, zoneId, factionGroupMask, id);
        }

        static fmt::appender FormatGlobal(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) & 0x3FFFFFFFFFFFFFF));
            ctx.advance_to(AppendComponent<padding<12>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseGlobal(HighGuid type, std::string_view guidString)
        {
            uint64 dbIdHigh = UI64LIT(0);
            uint64 dbIdLow = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &dbIdHigh)
                || !ParseComponent<hex>(guidString, &dbIdLow)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateGlobal(type, dbIdHigh, dbIdLow);
        }

        static fmt::appender FormatGuild(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<padding<12>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseGuild(HighGuid type, std::string_view guidString)
        {
            uint32 realmId = 0;
            uint64 dbId = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<hex>(guidString, &dbId)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateGuild(type, realmId, dbId);
        }

        static fmt::appender FormatMobileSession(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 33 & 0x1FF));
            ctx.advance_to(AppendComponent<padding<8>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseMobileSession(HighGuid /*type*/, std::string_view guidString)
        {
            uint32 realmId = 0;
            uint16 arg1 = 0;
            uint64 counter = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<dec>(guidString, &arg1)
                || !ParseComponent<hex>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateMobileSession(realmId, arg1, counter);
        }

        static fmt::appender FormatWebObj(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 37 & 0x1F));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 35 & 0x3));
            ctx.advance_to(AppendComponent<padding<12>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseWebObj(HighGuid /*type*/, std::string_view guidString)
        {
            uint32 realmId = 0;
            uint8 arg1 = 0;
            uint8 arg2 = 0;
            uint64 counter = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<dec>(guidString, &arg1)
                || !ParseComponent<dec>(guidString, &arg2)
                || !ParseComponent<hex>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateWebObj(realmId, arg1, arg2, counter);
        }

        static fmt::appender FormatLFGObject(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 54 & 0xF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 50 & 0xF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 46 & 0xF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 38 & 0xFF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 37 & 0x1));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 35 & 0x3));
            ctx.advance_to(AppendComponent<padding<6>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseLFGObject(HighGuid /*type*/, std::string_view guidString)
        {
            uint8 arg1 = 0;
            uint8 arg2 = 0;
            uint8 arg3 = 0;
            uint8 arg4 = 0;
            uint8 arg5 = 0;
            uint8 arg6 = 0;
            uint64 counter = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &arg1)
                || !ParseComponent<dec>(guidString, &arg2)
                || !ParseComponent<dec>(guidString, &arg3)
                || !ParseComponent<dec>(guidString, &arg4)
                || !ParseComponent<dec>(guidString, &arg5)
                || !ParseComponent<dec>(guidString, &arg6)
                || !ParseComponent<hex>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateLFGObject(arg1, arg2, arg3, arg4, arg5 != 0, arg6, counter);
        }

        static fmt::appender FormatLFGList(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 54 & 0xF));
            ctx.advance_to(AppendComponent<padding<6>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseLFGList(HighGuid /*type*/, std::string_view guidString)
        {
            uint8 arg1 = 0;
            uint64 counter = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &arg1)
                || !ParseComponent<hex>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateLFGList(arg1, counter);
        }

        static fmt::appender FormatClient(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) >> 10 & 0xFFFFFFFF));
            ctx.advance_to(AppendComponent<padding<12>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseClient(HighGuid type, std::string_view guidString)
        {
            uint32 realmId = 0;
            uint32 arg1 = 0;
            uint64 counter = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<dec>(guidString, &arg1)
                || !ParseComponent<hex>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateClient(type, realmId, arg1, counter);
        }

        static fmt::appender FormatClubFinder(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            uint32 type = uint32(guid.GetRawValue(1) >> 33) & 0xFF;
            uint32 clubFinderId = uint32(guid.GetRawValue(1)) & 0xFFFFFFFF;

            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, type));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, clubFinderId));
            switch (type)
            {
                case 0: // club
                    ctx.advance_to(AppendComponent<padding<16>, hex>(ctx, guid.GetRawValue(0))); // clubId
                    break;
                case 1: // guild
                    ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
                    ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(0))); // guildId
                    break;
                default:
                    break;
            }

            return ctx.out();
        }

        static ObjectGuid ParseClubFinder(HighGuid /*type*/, std::string_view guidString)
        {
            uint8 type = 0;
            uint32 clubFinderId = 0;
            uint32 realmId = 0;
            uint64 dbId = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &type)
                || !ParseComponent<dec>(guidString, &clubFinderId))
                return ObjectGuid::FromStringFailed;

            switch (type)
            {
                case 0: // club
                    if (!ParseComponent<hex>(guidString, &dbId))
                        return ObjectGuid::FromStringFailed;
                    break;
                case 1: // guild
                    if (!ParseComponent<dec>(guidString, &realmId)
                        || !ParseComponent<dec>(guidString, &dbId))
                        return ObjectGuid::FromStringFailed;
                    break;
                default:
                    return ObjectGuid::FromStringFailed;
            }

            if (!ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateClubFinder(realmId, type, clubFinderId, dbId);
        }

        static fmt::appender FormatToolsClient(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetMapId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(0) >> 40 & 0xFFFFFF));
            ctx.advance_to(AppendComponent<padding<10>, hex>(ctx, guid.GetCounter()));
            return ctx.out();
        }

        static ObjectGuid ParseToolsClient(HighGuid /*type*/, std::string_view guidString)
        {
            uint16 mapId = 0;
            uint32 serverId = 0;
            uint64 counter = UI64LIT(0);

            if (!ParseComponent<dec>(guidString, &mapId)
                || !ParseComponent<dec>(guidString, &serverId)
                || !ParseComponent<hex>(guidString, &counter)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateToolsClient(mapId, serverId, counter);
        }

        static fmt::appender FormatWorldLayer(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<padding<0>, hex>(ctx, guid.GetRawValue(1) >> 10 & 0xFFFFFFFF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(1) & 0x1FF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(0) >> 24 & 0xFF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRawValue(0) & 0x7FFFFF));
            return ctx.out();
        }

        static ObjectGuid ParseWorldLayer(HighGuid /*type*/, std::string_view guidString)
        {
            uint32 arg1 = 0;
            uint16 arg2 = 0;
            uint8 arg3 = 0;
            uint32 arg4 = 0;

            if (!ParseComponent<hex>(guidString, &arg1)
                || !ParseComponent<dec>(guidString, &arg2)
                || !ParseComponent<dec>(guidString, &arg3)
                || !ParseComponent<dec>(guidString, &arg4)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateWorldLayer(arg1, arg2, arg3, arg4);
        }

        static fmt::appender FormatLMMLobby(fmt::format_context& ctx, std::string const& typeName, ObjectGuid const& guid)
        {
            ctx.advance_to(AppendTypeName(ctx, typeName));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, guid.GetRealmId()));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, uint32(guid.GetRawValue(1) >> 26) & 0xFFFFFF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, uint32(guid.GetRawValue(1) >> 18) & 0xFF));
            ctx.advance_to(AppendComponent<no_padding, dec>(ctx, uint32(guid.GetRawValue(1) >> 10) & 0xFF));
            ctx.advance_to(AppendComponent<padding<0>, hex>(ctx, guid.GetRawValue(0)));
            return ctx.out();
        }

        static ObjectGuid ParseLMMLobby(HighGuid /*type*/, std::string_view guidString)
        {
            uint32 realmId = 0;
            uint32 arg2 = 0;
            uint8 arg3 = 0;
            uint8 arg4 = 0;
            uint64 arg5 = 0;

            if (!ParseComponent<dec>(guidString, &realmId)
                || !ParseComponent<dec>(guidString, &arg2)
                || !ParseComponent<dec>(guidString, &arg3)
                || !ParseComponent<dec>(guidString, &arg4)
                || !ParseComponent<hex>(guidString, &arg5)
                || !ParseDone(guidString))
                return ObjectGuid::FromStringFailed;

            return ObjectGuidFactory::CreateLMMLobby(realmId, arg2, arg3, arg4, arg5);
        }

        ObjectGuidInfo();
    } Info;

    ObjectGuidInfo::ObjectGuidInfo()
    {
#define SET_GUID_INFO(type, format, parse) \
            Names[AsUnderlyingType(HighGuid::type)] = #type;\
            ClientFormatFunction[AsUnderlyingType(HighGuid::type)] = &ObjectGuidInfo::format;\
            ClientParseFunction[AsUnderlyingType(HighGuid::type)] = &ObjectGuidInfo::parse

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
        SET_GUID_INFO(LMMParty, FormatClient, ParseClient);
        SET_GUID_INFO(LMMLobby, FormatLMMLobby, ParseLMMLobby);

#undef SET_GUID_INFO
    }
}

template <typename FormatContext>
inline auto fmt::formatter<ObjectGuid>::format(ObjectGuid const& guid, FormatContext& ctx) const -> decltype(ctx.out())
{
    if (guid.GetHigh() >= HighGuid::Count)
        return format(ObjectGuid::ToStringFailed, ctx);

    int32 type = AsUnderlyingType(guid.GetHigh());
    if (!Info.ClientFormatFunction[type])
        return format(ObjectGuid::ToStringFailed, ctx);

    return Info.ClientFormatFunction[type](ctx, Info.Names[type].c_str(), guid);
}

template TC_GAME_API fmt::appender fmt::formatter<ObjectGuid>::format<fmt::format_context>(ObjectGuid const&, format_context&) const;

std::string_view ObjectGuid::GetTypeName(HighGuid high)
{
    if (high >= HighGuid::Count)
        return "<unknown>";

    return Info.Names[uint32(high)];
}

std::string ObjectGuid::ToString() const
{
    return ObjectGuidInfo::Format(*this);
}

std::string ObjectGuid::ToHexString() const
{
    return Trinity::StringFormat("0x{:016X}{:016X}", _data[1], _data[0]);
}

ObjectGuid ObjectGuid::FromString(std::string_view guidString)
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

ObjectGuid ObjectGuidFactory::CreateLMMLobby(uint32 realmId, uint32 arg2, uint8 arg3, uint8 arg4, ObjectGuid::LowType counter)
{
    return ObjectGuid(uint64((uint64(HighGuid::LMMLobby) << 58)
        | (uint64(GetRealmIdForObjectGuid(realmId)) << 42)
        | (uint64(arg2 & 0xFFFFFFFF) << 26)
        | (uint64(arg3 & 0xFF) << 18)
        | (uint64(arg4 & 0xFF) << 10)),
        counter);
}

ObjectGuid const ObjectGuid::Empty = ObjectGuid();
ObjectGuid const ObjectGuid::ToStringFailed = ObjectGuid::Create<HighGuid::Uniq>(UI64LIT(3));
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

ObjectGuid::LowType ObjectGuidGenerator::Generate()
{
    if (_nextGuid >= ObjectGuid::GetMaxCounter(_high) - 1)
        HandleCounterOverflow();

    if (_high == HighGuid::Creature || _high == HighGuid::Vehicle || _high == HighGuid::GameObject || _high == HighGuid::Transport)
        CheckGuidTrigger();

    return _nextGuid++;
}

void ObjectGuidGenerator::HandleCounterOverflow()
{
    TC_LOG_ERROR("misc", "{} guid overflow!! Can't continue, shutting down server. ", ObjectGuid::GetTypeName(_high));
    World::StopNow(ERROR_EXIT_CODE);
}

void ObjectGuidGenerator::CheckGuidTrigger()
{
    if (!sWorld->IsGuidAlert() && _nextGuid > sWorld->getIntConfig(CONFIG_RESPAWN_GUIDALERTLEVEL))
        sWorld->TriggerGuidAlert();
    else if (!sWorld->IsGuidWarning() && _nextGuid > sWorld->getIntConfig(CONFIG_RESPAWN_GUIDWARNLEVEL))
        sWorld->TriggerGuidWarning();
}
