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
#include "HighGuid.h"

#include <functional>

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


class ObjectGuid;
class PackedGuid;

struct PackedGuidReader
{
    explicit PackedGuidReader(ObjectGuid& guid) : GuidPtr(&guid) { }
    ObjectGuid* GuidPtr;
};

class ObjectGuid
{
    public:
        static ObjectGuid const Empty;

        ObjectGuid() { Set(0); }
        explicit ObjectGuid(uint64 guid) { Set(guid); }
        ObjectGuid(HighGuid hi, uint32 entry, uint32 counter)
        {
            Set(counter ? uint64(counter) | (uint64(entry) << 24) | (uint64(hi) << 48) : 0);
        }
        ObjectGuid(HighGuid hi, uint32 counter)
        { 
            Set(counter ? uint64(counter) | (uint64(hi) << 48) : 0); 
        }

        operator uint64() const { return _guid; }
        PackedGuidReader ReadAsPacked() { return PackedGuidReader(*this); }

        void Set(uint64 guid) 
        { 
            _guid = guid; 
            _highGuid.reset(HighGuidFactory::Create(guid));
        }
        void Clear() { Set(0); }

        PackedGuid WriteAsPacked() const;

        uint64   GetRawValue() const { return _guid; }
        HighGuid GetHigh() const { return _highGuid->Guid(); }
        uint32   GetEntry() const { return _highGuid->HasEntry() ? uint32((_guid >> 24) & UI64LIT(0x0000000000FFFFFF)) : 0; }
        uint32   GetCounter()  const
        {
            return _highGuid->HasEntry()
                   ? uint32(_guid & UI64LIT(0x0000000000FFFFFF))
                   : uint32(_guid & UI64LIT(0x00000000FFFFFFFF));
        }

        bool IsEmpty()             const { return _guid == 0; }
        bool IsCreature()          const { return _highGuid->Guid() == HIGHGUID_UNIT; }
        bool IsPet()               const { return _highGuid->Guid() == HIGHGUID_PET; }
        bool IsVehicle()           const { return _highGuid->Guid() == HIGHGUID_VEHICLE; }
        bool IsCreatureOrPet()     const { return IsCreature() || IsPet(); }
        bool IsCreatureOrVehicle() const { return IsCreature() || IsVehicle(); }
        bool IsAnyTypeCreature()   const { return IsCreature() || IsPet() || IsVehicle(); }
        bool IsPlayer()            const { return !IsEmpty() && _highGuid->Guid() == HIGHGUID_PLAYER; }
        bool IsUnit()              const { return IsAnyTypeCreature() || IsPlayer(); }
        bool IsItem()              const { return _highGuid->Guid() == HIGHGUID_ITEM; }
        bool IsGameObject()        const { return _highGuid->Guid() == HIGHGUID_GAMEOBJECT; }
        bool IsDynamicObject()     const { return _highGuid->Guid() == HIGHGUID_DYNAMICOBJECT; }
        bool IsCorpse()            const { return _highGuid->Guid() == HIGHGUID_CORPSE; }
        bool IsTransport()         const { return _highGuid->Guid() == HIGHGUID_TRANSPORT; }
        bool IsMOTransport()       const { return _highGuid->Guid() == HIGHGUID_MO_TRANSPORT; }
        bool IsAnyTypeGameObject() const { return IsGameObject() || IsTransport() || IsMOTransport(); }
        bool IsInstance()          const { return _highGuid->Guid() == HIGHGUID_INSTANCE; }
        bool IsGroup()             const { return _highGuid->Guid() == HIGHGUID_GROUP; }

        TypeID GetTypeId() const { return _highGuid->TypeId(); }

        bool operator!() const { return IsEmpty(); }
        bool operator== (ObjectGuid const& guid) const { return GetRawValue() == guid.GetRawValue(); }
        bool operator!= (ObjectGuid const& guid) const { return GetRawValue() != guid.GetRawValue(); }
        bool operator< (ObjectGuid const& guid) const { return GetRawValue() < guid.GetRawValue(); }

        std::string const GetTypeName() const { return _highGuid->TypeName(); }
        std::string const ToString() const;
    private:
        std::shared_ptr<HighGuidBase> _highGuid;

        bool HasEntry() const { return _highGuid->HasEntry(); }

        explicit ObjectGuid(uint32 const&) = delete;                 // no implementation, used to catch wrong type assignment
        ObjectGuid(HighGuid, uint32, uint64 counter) = delete;       // no implementation, used to catch wrong type assignment
        ObjectGuid(HighGuid, uint64 counter) = delete;               // no implementation, used to catch wrong type assignment

        uint64 _guid;
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

    public:
        explicit PackedGuid() : _packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { _packedGuid.appendPackGUID(0); }
        explicit PackedGuid(uint64 guid) : _packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { _packedGuid.appendPackGUID(guid); }
        explicit PackedGuid(ObjectGuid guid) : _packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { _packedGuid.appendPackGUID(guid.GetRawValue()); }

        void Set(uint64 guid) { _packedGuid.wpos(0); _packedGuid.appendPackGUID(guid); }
        void Set(ObjectGuid guid) { _packedGuid.wpos(0); _packedGuid.appendPackGUID(guid.GetRawValue()); }

        size_t size() const { return _packedGuid.size(); }

    private:
        ByteBuffer _packedGuid;
};

template<HighGuid high>
class ObjectGuidGenerator
{
    public:
        explicit ObjectGuidGenerator(uint32 start = 1) : _nextGuid(start), _type(HighGuidFactory::Create(high)) { }

        void Set(uint32 val) { _nextGuid = val; }
        uint32 Generate();
        uint32 GetNextAfterMaxUsed() const { return _nextGuid; }

    private:
        uint32 _nextGuid;
        std::unique_ptr<HighGuidBase> _type;
};

ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid);
ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid&       guid);

ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);
ByteBuffer& operator>>(ByteBuffer& buf, PackedGuidReader const& guid);

inline PackedGuid ObjectGuid::WriteAsPacked() const { return PackedGuid(*this); }

namespace std
{
    template<>
    struct hash<ObjectGuid>
    {
        public:
            size_t operator()(ObjectGuid const& key) const
            {
                return hash<uint64>()(key.GetRawValue());
            }
    };
}




#endif // ObjectGuid_h__
