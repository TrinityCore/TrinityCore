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

#ifndef ObjectGuid_h__
#define ObjectGuid_h__

#include "Common.h"
#include "ByteBuffer.h"
#include <boost/functional/hash.hpp>

#include <functional>

enum TypeID
{
    TYPEID_OBJECT        = 0,
    TYPEID_ITEM          = 1,
    TYPEID_CONTAINER     = 2,
    TYPEID_UNIT          = 3,
    TYPEID_PLAYER        = 4,
    TYPEID_GAMEOBJECT    = 5,
    TYPEID_DYNAMICOBJECT = 6,
    TYPEID_CORPSE        = 7,
    TYPEID_AREATRIGGER   = 8
};

#define NUM_CLIENT_OBJECT_TYPES             9

enum TypeMask
{
    TYPEMASK_OBJECT         = 0x0001,
    TYPEMASK_ITEM           = 0x0002,
    TYPEMASK_CONTAINER      = 0x0006,                       // TYPEMASK_ITEM | 0x0004
    TYPEMASK_UNIT           = 0x0008,                       // creature
    TYPEMASK_PLAYER         = 0x0010,
    TYPEMASK_GAMEOBJECT     = 0x0020,
    TYPEMASK_DYNAMICOBJECT  = 0x0040,
    TYPEMASK_CORPSE         = 0x0080,
    TYPEMASK_AREATRIGGER    = 0x0100,
    TYPEMASK_SEER           = TYPEMASK_PLAYER | TYPEMASK_UNIT | TYPEMASK_DYNAMICOBJECT
};

enum HighGuid
{
    HIGHGUID_ITEM           = 0x400,                       // blizz 4000
    HIGHGUID_CONTAINER      = 0x400,                       // blizz 4000
    HIGHGUID_PLAYER         = 0x000,                       // blizz 0000
    HIGHGUID_GAMEOBJECT     = 0xF11,                       // blizz F110
    HIGHGUID_TRANSPORT      = 0xF12,                       // blizz F120 (for GAMEOBJECT_TYPE_TRANSPORT)
    HIGHGUID_UNIT           = 0xF13,                       // blizz F130
    HIGHGUID_PET            = 0xF14,                       // blizz F140
    HIGHGUID_VEHICLE        = 0xF15,                       // blizz F550
    HIGHGUID_DYNAMICOBJECT  = 0xF10,                       // blizz F100
    HIGHGUID_CORPSE         = 0xF101,                      // blizz F100
    HIGHGUID_AREATRIGGER    = 0xF102,
    HIGHGUID_BATTLEGROUND   = 0x1F1,
    HIGHGUID_MO_TRANSPORT   = 0x1FC,                       // blizz 1FC0 (for GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT)
    HIGHGUID_INSTANCE       = 0x1F4,                       // blizz 1F40
    HIGHGUID_GROUP          = 0x1F5,
    HIGHGUID_GUILD          = 0x1FF
};

class ObjectGuid;
class PackedGuid;

struct PackedGuidReader
{
    explicit PackedGuidReader(ObjectGuid& guid) : GuidPtr(&guid) { }
    ObjectGuid* GuidPtr;
};

#pragma pack(push, 1)

class ObjectGuid
{
    friend std::ostream& operator<<(std::ostream& stream, ObjectGuid const& guid);
    friend ByteBuffer& operator>>(ByteBuffer& buf, PackedGuidReader const& guid);
    friend class PackedGuid;

    public:
        static ObjectGuid const Empty;

        typedef uint64 LowType;

        ObjectGuid() : _low(0), _high(0) { }
        ObjectGuid(HighGuid hi, uint32 entry, LowType counter) : _low(counter ? uint64(counter) | (uint64(entry) << 32) | (uint64(hi) << ((hi == HIGHGUID_CORPSE || hi == HIGHGUID_AREATRIGGER) ? 48 : 52)) : 0), _high(0) { }
        ObjectGuid(HighGuid hi, LowType counter) : _low(counter ? uint64(counter) | (uint64(hi) << ((hi == HIGHGUID_CORPSE || hi == HIGHGUID_AREATRIGGER) ? 48 : 52)) : 0), _high(0) { }
        ObjectGuid(ObjectGuid const&) = default;

        PackedGuidReader ReadAsPacked() { return PackedGuidReader(*this); }

        std::vector<uint8> GetRawValue() const;
        void SetRawValue(std::vector<uint8> const& guid);
        void SetRawValue(uint64 high, uint64 low) { _high = high; _low = low; }
        void Clear() { _low = 0; }

        PackedGuid WriteAsPacked() const;

        HighGuid GetHigh() const
        {
            uint32 temp = ((uint64(_low) >> 48) & 0x0000FFFF);
            return HighGuid((temp == HIGHGUID_CORPSE || temp == HIGHGUID_AREATRIGGER) ? temp : ((temp >> 4) & 0x00000FFF));
        }
        uint32 GetEntry() const { return HasEntry() ? uint32((_low >> 32) & UI64LIT(0x00000000000FFFFF)) : 0; }
        LowType GetCounter()  const
        {
            return _low & UI64LIT(0x00000000FFFFFFFF);
        }

        static LowType GetMaxCounter(HighGuid /*high*/)
        {
            return UI64LIT(0xFFFFFFFF);
        }

        uint32 GetMaxCounter() const { return GetMaxCounter(GetHigh()); }

        uint8& operator[](uint32 index)
        {
            ASSERT(index < sizeof(uint64) * 2);
            return ((uint8*)&_low)[index];
        }

        uint8 const& operator[](uint32 index) const
        {
            ASSERT(index < sizeof(uint64) * 2);
            return ((uint8 const*)&_low)[index];
        }

        bool IsEmpty()             const { return _low == 0 && _high == 0; }
        bool IsCreature()          const { return GetHigh() == HIGHGUID_UNIT; }
        bool IsPet()               const { return GetHigh() == HIGHGUID_PET; }
        bool IsVehicle()           const { return GetHigh() == HIGHGUID_VEHICLE; }
        bool IsCreatureOrPet()     const { return IsCreature() || IsPet(); }
        bool IsCreatureOrVehicle() const { return IsCreature() || IsVehicle(); }
        bool IsAnyTypeCreature()   const { return IsCreature() || IsPet() || IsVehicle(); }
        bool IsPlayer()            const { return !IsEmpty() && GetHigh() == HIGHGUID_PLAYER; }
        bool IsUnit()              const { return IsAnyTypeCreature() || IsPlayer(); }
        bool IsItem()              const { return GetHigh() == HIGHGUID_ITEM; }
        bool IsGameObject()        const { return GetHigh() == HIGHGUID_GAMEOBJECT; }
        bool IsDynamicObject()     const { return GetHigh() == HIGHGUID_DYNAMICOBJECT; }
        bool IsCorpse()            const { return GetHigh() == HIGHGUID_CORPSE; }
        bool IsAreaTrigger()       const { return GetHigh() == HIGHGUID_AREATRIGGER; }
        bool IsBattleground()      const { return GetHigh() == HIGHGUID_BATTLEGROUND; }
        bool IsTransport()         const { return GetHigh() == HIGHGUID_TRANSPORT; }
        bool IsMOTransport()       const { return GetHigh() == HIGHGUID_MO_TRANSPORT; }
        bool IsAnyTypeGameObject() const { return IsGameObject() || IsTransport() || IsMOTransport(); }
        bool IsInstance()          const { return GetHigh() == HIGHGUID_INSTANCE; }
        bool IsGroup()             const { return GetHigh() == HIGHGUID_GROUP; }
        bool IsGuild()             const { return GetHigh() == HIGHGUID_GUILD; }

        static TypeID GetTypeId(HighGuid high)
        {
            switch (high)
            {
                case HIGHGUID_ITEM:         return TYPEID_ITEM;
                //case HIGHGUID_CONTAINER:    return TYPEID_CONTAINER; HIGHGUID_CONTAINER==HIGHGUID_ITEM currently
                case HIGHGUID_UNIT:         return TYPEID_UNIT;
                case HIGHGUID_PET:          return TYPEID_UNIT;
                case HIGHGUID_PLAYER:       return TYPEID_PLAYER;
                case HIGHGUID_GAMEOBJECT:   return TYPEID_GAMEOBJECT;
                case HIGHGUID_DYNAMICOBJECT: return TYPEID_DYNAMICOBJECT;
                case HIGHGUID_CORPSE:       return TYPEID_CORPSE;
                case HIGHGUID_AREATRIGGER:  return TYPEID_AREATRIGGER;
                case HIGHGUID_MO_TRANSPORT: return TYPEID_GAMEOBJECT;
                case HIGHGUID_VEHICLE:      return TYPEID_UNIT;
                // unknown
                case HIGHGUID_INSTANCE:
                case HIGHGUID_BATTLEGROUND:
                case HIGHGUID_GROUP:
                case HIGHGUID_GUILD:
                default:                    return TYPEID_OBJECT;
            }
        }

        TypeID GetTypeId() const { return GetTypeId(GetHigh()); }

        bool operator!() const { return IsEmpty(); }
        bool operator== (ObjectGuid const& guid) const { return _low == guid._low && _high == guid._high; }
        bool operator!= (ObjectGuid const& guid) const { return !(*this == guid); }
        bool operator< (ObjectGuid const& guid) const
        {
            if (_high < guid._high)
                return true;
            else if (_high > guid._high)
                return false;

            return _low < guid._low;
        }

        static char const* GetTypeName(HighGuid high);
        char const* GetTypeName() const { return !IsEmpty() ? GetTypeName(GetHigh()) : "None"; }
        std::string ToString() const;

    private:
        static bool HasEntry(HighGuid high)
        {
            switch (high)
            {
                case HIGHGUID_ITEM:
                case HIGHGUID_PLAYER:
                case HIGHGUID_DYNAMICOBJECT:
                case HIGHGUID_CORPSE:
                case HIGHGUID_MO_TRANSPORT:
                case HIGHGUID_INSTANCE:
                case HIGHGUID_GROUP:
                    return false;
                case HIGHGUID_GAMEOBJECT:
                case HIGHGUID_TRANSPORT:
                case HIGHGUID_UNIT:
                case HIGHGUID_PET:
                case HIGHGUID_VEHICLE:
                default:
                    return true;
            }
        }

        bool HasEntry() const { return HasEntry(GetHigh()); }

        explicit ObjectGuid(uint32 const&) = delete;                 // no implementation, used to catch wrong type assignment

        uint64 _low;
        uint64 _high;
};

#pragma pack(pop)

// Some Shared defines
typedef std::set<ObjectGuid> GuidSet;
typedef std::list<ObjectGuid> GuidList;
typedef std::deque<ObjectGuid> GuidDeque;
typedef std::vector<ObjectGuid> GuidVector;

// maximum buffer size for packed guid is 18 bytes
#define PACKED_GUID_MIN_BUFFER_SIZE 18

class PackedGuid
{
        friend ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);

    public:
        explicit PackedGuid() : _packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { _packedGuid << uint16(0); }
        explicit PackedGuid(ObjectGuid guid) : _packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { Set(guid); }

        void Set(ObjectGuid guid);

        size_t size() const { return _packedGuid.size(); }

    private:
        ByteBuffer _packedGuid;
};

template<HighGuid high>
class ObjectGuidGenerator
{
    public:
        explicit ObjectGuidGenerator(ObjectGuid::LowType start = UI64LIT(1)) : _nextGuid(start) { }

        void Set(uint64 val) { _nextGuid = val; }
        ObjectGuid::LowType Generate();
        ObjectGuid::LowType GetNextAfterMaxUsed() const { return _nextGuid; }

    private:
        uint64 _nextGuid;
};

ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid);
ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid&       guid);

ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);
ByteBuffer& operator>>(ByteBuffer& buf, PackedGuidReader const& guid);

std::ostream& operator<<(std::ostream& stream, ObjectGuid const& guid);

inline PackedGuid ObjectGuid::WriteAsPacked() const { return PackedGuid(*this); }

namespace std
{
    template<>
    struct hash<ObjectGuid>
    {
    public:
        size_t operator()(ObjectGuid const& key) const
        {
            return boost::hash_range(reinterpret_cast<uint64 const*>(&key), reinterpret_cast<uint64 const*>(&key) + 2);
        }
    };
}

#endif // ObjectGuid_h__
