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

#ifndef ObjectGuid_h__
#define ObjectGuid_h__

#include "Define.h"
#include <array>
#include <functional>
#include <list>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <vector>

enum TypeID
{
    TYPEID_OBJECT        = 0,
    TYPEID_ITEM          = 1,
    TYPEID_CONTAINER     = 2,
    TYPEID_UNIT          = 3,
    TYPEID_PLAYER        = 4,
    TYPEID_GAMEOBJECT    = 5,
    TYPEID_DYNAMICOBJECT = 6,
    TYPEID_CORPSE        = 7
};

#define NUM_CLIENT_OBJECT_TYPES             8

enum TypeMask
{
    TYPEMASK_OBJECT         = 0x0001,
    TYPEMASK_ITEM           = 0x0002,
    TYPEMASK_CONTAINER      = 0x0004,                       // TYPEMASK_ITEM | 0x0004
    TYPEMASK_UNIT           = 0x0008,                       // creature
    TYPEMASK_PLAYER         = 0x0010,
    TYPEMASK_GAMEOBJECT     = 0x0020,
    TYPEMASK_DYNAMICOBJECT  = 0x0040,
    TYPEMASK_CORPSE         = 0x0080,

    TYPEMASK_SEER           = TYPEMASK_UNIT | TYPEMASK_DYNAMICOBJECT,
    TYPEMASK_WORLDOBJECT    = TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT | TYPEMASK_DYNAMICOBJECT | TYPEMASK_CORPSE
};

enum class HighGuid
{
    Item           = 0x4000,                      // blizz 4000
    Container      = 0x4000,                      // blizz 4000
    Player         = 0x0000,                      // blizz 0000
    GameObject     = 0xF110,                      // blizz F110
    Transport      = 0xF120,                      // blizz F120 (for GAMEOBJECT_TYPE_TRANSPORT)
    Unit           = 0xF130,                      // blizz F130
    Pet            = 0xF140,                      // blizz F140
    Vehicle        = 0xF150,                      // blizz F550
    DynamicObject  = 0xF100,                      // blizz F100
    Corpse         = 0xF101,                      // blizz F100
    Mo_Transport   = 0x1FC0,                      // blizz 1FC0 (for GAMEOBJECT_TYPE_MO_TRANSPORT)
    Instance       = 0x1F40,                      // blizz 1F40
    Group          = 0x1F50,
};

template<HighGuid high>
struct ObjectGuidTraits
{
    static bool const Global = false;
    static bool const MapSpecific = false;
};

#define GUID_TRAIT_GLOBAL(highguid) \
    template<> struct ObjectGuidTraits<highguid> \
    { \
        static bool const Global = true; \
        static bool const MapSpecific = false; \
    };

#define GUID_TRAIT_MAP_SPECIFIC(highguid) \
    template<> struct ObjectGuidTraits<highguid> \
    { \
        static bool const Global = false; \
        static bool const MapSpecific = true; \
    };

GUID_TRAIT_GLOBAL(HighGuid::Player)
GUID_TRAIT_GLOBAL(HighGuid::Item)
GUID_TRAIT_GLOBAL(HighGuid::Mo_Transport)
GUID_TRAIT_GLOBAL(HighGuid::Group)
GUID_TRAIT_GLOBAL(HighGuid::Instance)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Transport)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Unit)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Vehicle)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Pet)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::GameObject)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::DynamicObject)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Corpse)

class ByteBuffer;
class ObjectGuid;
class PackedGuid;

struct PackedGuidReader
{
    explicit PackedGuidReader(ObjectGuid& guid) : Guid(guid) { }
    ObjectGuid& Guid;
};

struct PackedGuidWriter
{
    explicit PackedGuidWriter(ObjectGuid const& guid) : Guid(guid) { }
    ObjectGuid const& Guid;
};

class TC_GAME_API ObjectGuid
{
    public:
        static ObjectGuid const Empty;

        typedef uint32 LowType;

        template<HighGuid type>
        static typename std::enable_if<ObjectGuidTraits<type>::Global, ObjectGuid>::type Create(LowType counter) { return Global(type, counter); }

        template<HighGuid type>
        static typename std::enable_if<ObjectGuidTraits<type>::MapSpecific, ObjectGuid>::type Create(uint32 entry, LowType counter) { return MapSpecific(type, entry, counter); }

        ObjectGuid() : _guid(0) { }
        explicit ObjectGuid(uint64 guid) : _guid(guid) { }
        ObjectGuid(HighGuid hi, uint32 entry, LowType counter) : _guid(counter ? uint64(counter) | (uint64(entry) << 24) | (uint64(hi) << 48) : 0) { }
        ObjectGuid(HighGuid hi, LowType counter) : _guid(counter ? uint64(counter) | (uint64(hi) << 48) : 0) { }

        operator uint64() const { return _guid; }
        PackedGuidReader ReadAsPacked() { return PackedGuidReader(*this); }

        void Set(uint64 guid) { _guid = guid; }
        void Clear() { _guid = 0; }

        PackedGuidWriter WriteAsPacked() const { return PackedGuidWriter(*this); }

        uint64   GetRawValue() const { return _guid; }
        HighGuid GetHigh() const { return HighGuid((_guid >> 48) & 0x0000FFFF); }
        uint32   GetEntry() const { return HasEntry() ? uint32((_guid >> 24) & UI64LIT(0x0000000000FFFFFF)) : 0; }
        LowType  GetCounter()  const
        {
            return HasEntry()
                   ? LowType(_guid & UI64LIT(0x0000000000FFFFFF))
                   : LowType(_guid & UI64LIT(0x00000000FFFFFFFF));
        }

        static LowType GetMaxCounter(HighGuid high)
        {
            return HasEntry(high)
                   ? LowType(0x00FFFFFF)
                   : LowType(0xFFFFFFFF);
        }

        ObjectGuid::LowType GetMaxCounter() const { return GetMaxCounter(GetHigh()); }

        bool IsEmpty()             const { return _guid == 0; }
        bool IsCreature()          const { return GetHigh() == HighGuid::Unit; }
        bool IsPet()               const { return GetHigh() == HighGuid::Pet; }
        bool IsVehicle()           const { return GetHigh() == HighGuid::Vehicle; }
        bool IsCreatureOrPet()     const { return IsCreature() || IsPet(); }
        bool IsCreatureOrVehicle() const { return IsCreature() || IsVehicle(); }
        bool IsAnyTypeCreature()   const { return IsCreature() || IsPet() || IsVehicle(); }
        bool IsPlayer()            const { return !IsEmpty() && GetHigh() == HighGuid::Player; }
        bool IsUnit()              const { return IsAnyTypeCreature() || IsPlayer(); }
        bool IsItem()              const { return GetHigh() == HighGuid::Item; }
        bool IsGameObject()        const { return GetHigh() == HighGuid::GameObject; }
        bool IsDynamicObject()     const { return GetHigh() == HighGuid::DynamicObject; }
        bool IsCorpse()            const { return GetHigh() == HighGuid::Corpse; }
        bool IsTransport()         const { return GetHigh() == HighGuid::Transport; }
        bool IsMOTransport()       const { return GetHigh() == HighGuid::Mo_Transport; }
        bool IsAnyTypeGameObject() const { return IsGameObject() || IsTransport() || IsMOTransport(); }
        bool IsInstance()          const { return GetHigh() == HighGuid::Instance; }
        bool IsGroup()             const { return GetHigh() == HighGuid::Group; }

        static TypeID GetTypeId(HighGuid high)
        {
            switch (high)
            {
                case HighGuid::Item:         return TYPEID_ITEM;
                //case HighGuid::Container:    return TYPEID_CONTAINER; HighGuid::Container == HighGuid::Item currently
                case HighGuid::Unit:         return TYPEID_UNIT;
                case HighGuid::Pet:          return TYPEID_UNIT;
                case HighGuid::Player:       return TYPEID_PLAYER;
                case HighGuid::GameObject:   return TYPEID_GAMEOBJECT;
                case HighGuid::DynamicObject: return TYPEID_DYNAMICOBJECT;
                case HighGuid::Corpse:       return TYPEID_CORPSE;
                case HighGuid::Mo_Transport: return TYPEID_GAMEOBJECT;
                case HighGuid::Vehicle:      return TYPEID_UNIT;
                // unknown
                case HighGuid::Instance:
                case HighGuid::Group:
                default:                    return TYPEID_OBJECT;
            }
        }

        TypeID GetTypeId() const { return GetTypeId(GetHigh()); }

        bool operator!() const { return IsEmpty(); }
        bool operator==(ObjectGuid const& right) const = default;
        std::strong_ordering operator<=>(ObjectGuid const& right) const = default;

        static std::string_view GetTypeName(HighGuid high);
        std::string_view GetTypeName() const { return !IsEmpty() ? GetTypeName(GetHigh()) : "None"; }
        std::string ToString() const;
        std::string ToHexString() const;

    private:
        static bool HasEntry(HighGuid high)
        {
            switch (high)
            {
                case HighGuid::Item:
                case HighGuid::Player:
                case HighGuid::DynamicObject:
                case HighGuid::Corpse:
                case HighGuid::Mo_Transport:
                case HighGuid::Instance:
                case HighGuid::Group:
                    return false;
                case HighGuid::GameObject:
                case HighGuid::Transport:
                case HighGuid::Unit:
                case HighGuid::Pet:
                case HighGuid::Vehicle:
                default:
                    return true;
            }
        }

        bool HasEntry() const { return HasEntry(GetHigh()); }

        static ObjectGuid Global(HighGuid type, LowType counter);
        static ObjectGuid MapSpecific(HighGuid type, uint32 entry, LowType counter);

        explicit ObjectGuid(uint32 const&) = delete;                 // no implementation, used to catch wrong type assignment
        ObjectGuid(HighGuid, uint32, uint64 counter) = delete;       // no implementation, used to catch wrong type assignment
        ObjectGuid(HighGuid, uint64 counter) = delete;               // no implementation, used to catch wrong type assignment

        uint64 _guid;
};

// Some Shared defines
using GuidSet = std::set<ObjectGuid>;
using GuidList = std::list<ObjectGuid>;
using GuidVector = std::vector<ObjectGuid>;
using GuidUnorderedSet = std::unordered_set<ObjectGuid>;

// minimum buffer size for packed guid is 9 bytes
#define PACKED_GUID_MIN_BUFFER_SIZE 9

class TC_GAME_API PackedGuid
{
    friend TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);

    public:
        explicit PackedGuid() : _packedSize(1), _packedGuid() { }
        explicit PackedGuid(ObjectGuid guid) { Set(guid); }

        void Set(ObjectGuid guid);

        std::size_t size() const { return _packedSize; }

    private:
        uint8 _packedSize;
        std::array<uint8, PACKED_GUID_MIN_BUFFER_SIZE> _packedGuid;
};

class TC_GAME_API ObjectGuidGenerator
{
public:
    explicit ObjectGuidGenerator(HighGuid high, ObjectGuid::LowType start = 1) : _high(high), _nextGuid(start) { }
    ~ObjectGuidGenerator() = default;

    void Set(ObjectGuid::LowType val) { _nextGuid = val; }
    ObjectGuid::LowType Generate();
    ObjectGuid::LowType GetNextAfterMaxUsed() const { return _nextGuid; }

protected:
    void HandleCounterOverflow();
    void CheckGuidTrigger();
    HighGuid _high;
    ObjectGuid::LowType _nextGuid;
};

TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid);
TC_GAME_API ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid&       guid);

TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);
TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, PackedGuidWriter const& guid);
TC_GAME_API ByteBuffer& operator>>(ByteBuffer& buf, PackedGuidReader const& guid);

namespace std
{
    template<>
    struct hash<ObjectGuid>
    {
        public:
            size_t operator()(ObjectGuid const& key) const
            {
                return std::hash<uint64>()(key.GetRawValue());
            }
    };
}

namespace fmt
{
inline namespace v9
{
template <typename T, typename Char, typename Enable>
struct formatter;

template <>
struct formatter<ObjectGuid, char, void>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx) -> decltype(ctx.begin())
    {
        auto begin = ctx.begin(), end = ctx.end();
        if (begin == end)
            return begin;

        if (*begin != '}')
            throw std::invalid_argument("invalid type specifier");

        return begin;
    }

    template <typename FormatContext>
    auto format(ObjectGuid const& guid, FormatContext& ctx) const -> decltype(ctx.out());
};
}
}
#endif // ObjectGuid_h__
