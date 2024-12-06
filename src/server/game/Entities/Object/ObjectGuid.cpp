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
#include "Log.h"
#include "Util.h"
#include "World.h"
#include <charconv>

ObjectGuid const ObjectGuid::Empty = ObjectGuid();

namespace
{
struct ObjectGuidInfo
{
    struct FormatPadding { std::ptrdiff_t Value; constexpr operator std::ptrdiff_t() const { return Value; } };

    template <std::ptrdiff_t Width>
    static constexpr inline FormatPadding padding{ .Value = Width };
    static constexpr inline FormatPadding no_padding{ .Value = 0 };

    struct FormatBase { int32 Value; constexpr operator int32() const { return Value; } };

    static constexpr inline FormatBase dec{ 10 };
    static constexpr inline FormatBase hex{ 16 };

    static fmt::appender AppendTypeName(fmt::format_context& ctx, std::string_view type)
    {
        return std::copy(type.begin(), type.end(), ctx.out());
    }

    template <FormatPadding Width, FormatBase Base>
    static fmt::appender AppendComponent(fmt::format_context& ctx, uint64 component)
    {
        std::array<char, 20> buf;
        auto [end, err] = std::to_chars(buf.data(), buf.data() + buf.size(), component, Base);

        ASSERT(err == std::errc(), "Failed to convert guid part to string");

        if constexpr (Width != 0)
        {
            if (std::distance(buf.data(), end) < Width)
                std::fill_n(ctx.out(), Width - std::distance(buf.data(), end), '0');
        }

        if constexpr (Base > 10)
            return std::transform(buf.data(), end, ctx.out(), charToUpper);
        else
            return std::copy(buf.data(), end, ctx.out());
    }
};
}

template <typename FormatContext>
auto fmt::formatter<ObjectGuid>::format(ObjectGuid const& guid, FormatContext& ctx) const -> decltype(ctx.out())
{
    ctx.advance_to(ObjectGuidInfo::AppendTypeName(ctx, "GUID Full: 0x"));
    ctx.advance_to(ObjectGuidInfo::AppendComponent<ObjectGuidInfo::padding<16>, ObjectGuidInfo::hex>(ctx, guid.GetRawValue()));
    ctx.advance_to(ObjectGuidInfo::AppendTypeName(ctx, " Type: "));
    ctx.advance_to(ObjectGuidInfo::AppendTypeName(ctx, guid.GetTypeName()));
    if (uint32 entry = guid.GetEntry())
    {
        ctx.advance_to(ObjectGuidInfo::AppendTypeName(ctx, guid.IsPet() ? " Pet number: " : " Entry: "));
        ctx.advance_to(ObjectGuidInfo::AppendComponent<ObjectGuidInfo::no_padding, ObjectGuidInfo::dec>(ctx, entry));
    }
    ctx.advance_to(ObjectGuidInfo::AppendTypeName(ctx, " Low: "));
    ctx.advance_to(ObjectGuidInfo::AppendComponent<ObjectGuidInfo::no_padding, ObjectGuidInfo::dec>(ctx, guid.GetCounter()));
    return ctx.out();
}

template TC_GAME_API fmt::appender fmt::formatter<ObjectGuid>::format<fmt::format_context>(ObjectGuid const&, format_context&) const;

std::string_view ObjectGuid::GetTypeName(HighGuid high)
{
    switch (high)
    {
        case HighGuid::Item:         return "Item";
        case HighGuid::Player:       return "Player";
        case HighGuid::GameObject:   return "Gameobject";
        case HighGuid::Transport:    return "Transport";
        case HighGuid::Unit:         return "Creature";
        case HighGuid::Pet:          return "Pet";
        case HighGuid::Vehicle:      return "Vehicle";
        case HighGuid::DynamicObject: return "DynObject";
        case HighGuid::Corpse:       return "Corpse";
        case HighGuid::Mo_Transport: return "MoTransport";
        case HighGuid::Instance:     return "InstanceID";
        case HighGuid::Group:        return "Group";
        default:
            return "<unknown>";
    }
}

std::string ObjectGuid::ToString() const
{
    return Trinity::StringFormat("{}", *this);
}

std::string ObjectGuid::ToHexString() const
{
    return Trinity::StringFormat("0x{:016X}", _guid);
}

ObjectGuid ObjectGuid::Global(HighGuid type, LowType counter)
{
    return ObjectGuid(type, counter);
}

ObjectGuid ObjectGuid::MapSpecific(HighGuid type, uint32 entry, LowType counter)
{
    return ObjectGuid(type, entry, counter);
}

void PackedGuid::Set(ObjectGuid guid)
{
    _packedSize = 1;
    uint64 raw = guid.GetRawValue();
    for (uint8 i = 0; i < 8; ++i)
    {
        uint8 byte = (raw >> (i * 8)) & 0xFF;
        _packedGuid[_packedSize] = byte;
        if (byte)
        {
            _packedGuid[0] |= uint8(1 << i);
            ++_packedSize;
        }
    }
}

ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid)
{
    buf << uint64(guid.GetRawValue());
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid& guid)
{
    guid.Set(buf.read<uint64>());
    return buf;
}

ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid)
{
    buf.append(guid._packedGuid.data(), guid._packedSize);
    return buf;
}

ByteBuffer& operator<<(ByteBuffer& buf, PackedGuidWriter const& guid)
{
    buf.appendPackGUID(guid.Guid.GetRawValue());
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, PackedGuidReader const& guid)
{
    buf.readPackGUID(reinterpret_cast<uint64&>(guid.Guid));
    return buf;
}

ObjectGuid::LowType ObjectGuidGenerator::Generate()
{
    if (_nextGuid >= ObjectGuid::GetMaxCounter(_high) - 1)
        HandleCounterOverflow();

    if (_high == HighGuid::Unit || _high == HighGuid::Vehicle || _high == HighGuid::GameObject || _high == HighGuid::Transport)
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
