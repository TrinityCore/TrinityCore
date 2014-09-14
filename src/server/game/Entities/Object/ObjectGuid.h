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
    TYPEID_CORPSE        = 7
};

#define NUM_CLIENT_OBJECT_TYPES             8

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
    TYPEMASK_SEER           = TYPEMASK_PLAYER | TYPEMASK_UNIT | TYPEMASK_DYNAMICOBJECT
};

enum HighGuid
{
    HIGHGUID_ITEM           = 0x4000,                      // blizz 4000
    HIGHGUID_CONTAINER      = 0x4000,                      // blizz 4000
    HIGHGUID_PLAYER         = 0x0000,                      // blizz 0000
    HIGHGUID_GAMEOBJECT     = 0xF110,                      // blizz F110
    HIGHGUID_TRANSPORT      = 0xF120,                      // blizz F120 (for GAMEOBJECT_TYPE_TRANSPORT)
    HIGHGUID_UNIT           = 0xF130,                      // blizz F130
    HIGHGUID_PET            = 0xF140,                      // blizz F140
    HIGHGUID_VEHICLE        = 0xF150,                      // blizz F550
    HIGHGUID_DYNAMICOBJECT  = 0xF100,                      // blizz F100
    HIGHGUID_CORPSE         = 0xF101,                      // blizz F100
    HIGHGUID_MO_TRANSPORT   = 0x1FC0,                      // blizz 1FC0 (for GAMEOBJECT_TYPE_MO_TRANSPORT)
    HIGHGUID_INSTANCE       = 0x1F40,                      // blizz 1F40
    HIGHGUID_GROUP          = 0x1F50
};

class ObjectGuid;
class PackedGuid;

struct PackedGuidReader
{
    explicit PackedGuidReader(ObjectGuid& guid) : m_guidPtr(&guid) {}
    ObjectGuid* m_guidPtr;
};

class ObjectGuid
{
    public:
        static ObjectGuid const Empty;

        ObjectGuid() : m_guid(0) {}
        explicit ObjectGuid(uint64 guid) : m_guid(guid) {}
        ObjectGuid(HighGuid hi, uint32 entry, uint32 counter) : m_guid(counter ? uint64(counter) | (uint64(entry) << 24) | (uint64(hi) << 48) : 0) {}
        ObjectGuid(HighGuid hi, uint32 counter) : m_guid(counter ? uint64(counter) | (uint64(hi) << 48) : 0) {}

        explicit operator uint64() const { return m_guid; }
        PackedGuidReader ReadAsPacked() { return PackedGuidReader(*this); }

        void Set(uint64 guid) { m_guid = guid; }
        void Clear() { m_guid = 0; }

        PackedGuid WriteAsPacked() const;

        uint64   GetRawValue() const { return m_guid; }
        HighGuid GetHigh() const { return HighGuid((m_guid >> 48) & 0x0000FFFF); }
        uint32   GetEntry() const { return HasEntry() ? uint32((m_guid >> 24) & UI64LIT(0x0000000000FFFFFF)) : 0; }
        uint32   GetCounter()  const
        {
            return HasEntry()
                   ? uint32(m_guid & UI64LIT(0x0000000000FFFFFF))
                   : uint32(m_guid & UI64LIT(0x00000000FFFFFFFF));
        }

        static uint32 GetMaxCounter(HighGuid high)
        {
            return HasEntry(high)
                   ? uint32(0x00FFFFFF)
                   : uint32(0xFFFFFFFF);
        }

        uint32 GetMaxCounter() const { return GetMaxCounter(GetHigh()); }

        bool IsEmpty()             const { return m_guid == 0; }
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
        bool IsTransport()         const { return GetHigh() == HIGHGUID_TRANSPORT; }
        bool IsMOTransport()       const { return GetHigh() == HIGHGUID_MO_TRANSPORT; }
        bool IsAnyTypeGameObject() const { return IsGameObject() || IsTransport() || IsMOTransport(); }
        bool IsInstance()          const { return GetHigh() == HIGHGUID_INSTANCE; }
        bool IsGroup()             const { return GetHigh() == HIGHGUID_GROUP; }

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
                case HIGHGUID_MO_TRANSPORT: return TYPEID_GAMEOBJECT;
                case HIGHGUID_VEHICLE:      return TYPEID_UNIT;
                // unknown
                case HIGHGUID_INSTANCE:
                case HIGHGUID_GROUP:
                default:                    return TYPEID_OBJECT;
            }
        }

        TypeID GetTypeId() const { return GetTypeId(GetHigh()); }

        //bool operator!() const { return IsEmpty(); }
        bool operator== (ObjectGuid const& guid) const { return GetRawValue() == guid.GetRawValue(); }
        bool operator!= (ObjectGuid const& guid) const { return GetRawValue() != guid.GetRawValue(); }
        bool operator< (ObjectGuid const& guid) const { return GetRawValue() < guid.GetRawValue(); }

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
        ObjectGuid(HighGuid, uint32, uint64 counter) = delete;       // no implementation, used to catch wrong type assignment
        ObjectGuid(HighGuid, uint64 counter) = delete;               // no implementation, used to catch wrong type assignment

        uint64 m_guid;
};

// Some Shared defines
typedef std::set<ObjectGuid> GuidSet;
typedef std::list<ObjectGuid> GuidList;
typedef std::deque<ObjectGuid> GuidDeque;
typedef std::vector<ObjectGuid> GuidVector;

// minimum buffer size for packed guid is 9 bytes
#define PACKED_GUID_MIN_BUFFER_SIZE 9

class PackedGuid
{
        friend ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);

    public:                                                 // constructors
        explicit PackedGuid() : m_packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { m_packedGuid.appendPackGUID(0); }
        explicit PackedGuid(uint64 guid) : m_packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { m_packedGuid.appendPackGUID(guid); }
        explicit PackedGuid(ObjectGuid guid) : m_packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { m_packedGuid.appendPackGUID(guid.GetRawValue()); }

        void Set(uint64 guid) { m_packedGuid.wpos(0); m_packedGuid.appendPackGUID(guid); }
        void Set(ObjectGuid guid) { m_packedGuid.wpos(0); m_packedGuid.appendPackGUID(guid.GetRawValue()); }

        size_t size() const { return m_packedGuid.size(); }

    private:                                                // fields
        ByteBuffer m_packedGuid;
};

template<HighGuid high>
class ObjectGuidGenerator
{
    public:                                                 // constructors
        explicit ObjectGuidGenerator(uint32 start = 1) : m_nextGuid(start) {}

        void Set(uint32 val) { m_nextGuid = val; }
        uint32 Generate();
        uint32 GetNextAfterMaxUsed() const { return m_nextGuid; }

    private:                                                // fields
        uint32 m_nextGuid;
};

ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid);
ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid&       guid);

ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);
ByteBuffer& operator>>(ByteBuffer& buf, PackedGuidReader const& guid);

inline PackedGuid ObjectGuid::WriteAsPacked() const { return PackedGuid(*this); }

namespace std
{
    template<>
    class hash<ObjectGuid>
    {
        public:
            size_t operator()(ObjectGuid const& key) const
            {
                return hash<uint64>()(key.GetRawValue());
            }
    };
}

#endif // ObjectGuid_h__
