/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include <type_traits>
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
    TYPEID_AREATRIGGER   = 8,
    TYPEID_SCENEOBJECT   = 9,
    TYPEID_CONVERSATION  = 10
};

#define NUM_CLIENT_OBJECT_TYPES             11

enum TypeMask
{
    TYPEMASK_OBJECT         = 0x0001,
    TYPEMASK_ITEM           = 0x0002,
    TYPEMASK_CONTAINER      = 0x0004,
    TYPEMASK_UNIT           = 0x0008,
    TYPEMASK_PLAYER         = 0x0010,
    TYPEMASK_GAMEOBJECT     = 0x0020,
    TYPEMASK_DYNAMICOBJECT  = 0x0040,
    TYPEMASK_CORPSE         = 0x0080,
    TYPEMASK_AREATRIGGER    = 0x0100,
    TYPEMASK_SCENEOBJECT    = 0x0200,
    TYPEMASK_CONVERSATION   = 0x0400,
    TYPEMASK_SEER           = TYPEMASK_PLAYER | TYPEMASK_UNIT | TYPEMASK_DYNAMICOBJECT
};

enum class HighGuid
{
    Null             = 0,
    Uniq             = 1,
    Player           = 2,
    Item             = 3,
    StaticDoor       = 4,   //NYI
    Transport        = 5,
    Conversation     = 6,
    Creature         = 7,
    Vehicle          = 8,
    Pet              = 9,
    GameObject       = 10,
    DynamicObject    = 11,
    AreaTrigger      = 12,
    Corpse           = 13,
    LootObject       = 14,
    SceneObject      = 15,
    Scenario         = 16,
    AIGroup          = 17,
    DynamicDoor      = 18,
    ClientActor      = 19,  //NYI
    Vignette         = 20,
    CallForHelp      = 21,
    AIResource       = 22,
    AILock           = 23,
    AILockTicket     = 24,
    ChatChannel      = 25,
    Party            = 26,
    Guild            = 27,
    WowAccount       = 28,
    BNetAccount      = 29,
    GMTask           = 30,
    MobileSession    = 31,  //NYI
    RaidGroup        = 32,
    Spell            = 33,
    Mail             = 34,
    WebObj           = 35,  //NYI
    LFGObject        = 36,  //NYI
    LFGList          = 37,  //NYI
    UserRouter       = 38,
    PVPQueueGroup    = 39,
    UserClient       = 40,
    PetBattle        = 41,  //NYI
    UniqueUserClient = 42,
    BattlePet        = 43,

    Count,
};

template<HighGuid high>
struct ObjectGuidTraits
{
    static bool const Global = false;
    static bool const RealmSpecific = false;
    static bool const MapSpecific = false;
};

#define GUID_TRAIT_GLOBAL(highguid) \
    template<> struct ObjectGuidTraits<highguid> \
    { \
        static bool const Global = true; \
        static bool const RealmSpecific = false; \
        static bool const MapSpecific = false; \
    };

#define GUID_TRAIT_REALM_SPECIFIC(highguid) \
    template<> struct ObjectGuidTraits<highguid> \
    { \
        static bool const Global = false; \
        static bool const RealmSpecific = true; \
        static bool const MapSpecific = false; \
    };

#define GUID_TRAIT_MAP_SPECIFIC(highguid) \
    template<> struct ObjectGuidTraits<highguid> \
    { \
        static bool const Global = false; \
        static bool const RealmSpecific = false; \
        static bool const MapSpecific = true; \
    };

GUID_TRAIT_GLOBAL(HighGuid::Uniq)
GUID_TRAIT_GLOBAL(HighGuid::Party)
GUID_TRAIT_GLOBAL(HighGuid::WowAccount)
GUID_TRAIT_GLOBAL(HighGuid::BNetAccount)
GUID_TRAIT_GLOBAL(HighGuid::GMTask)
GUID_TRAIT_GLOBAL(HighGuid::RaidGroup)
GUID_TRAIT_GLOBAL(HighGuid::Spell)
GUID_TRAIT_GLOBAL(HighGuid::Mail)
GUID_TRAIT_GLOBAL(HighGuid::UserRouter)
GUID_TRAIT_GLOBAL(HighGuid::PVPQueueGroup)
GUID_TRAIT_GLOBAL(HighGuid::UserClient)
GUID_TRAIT_GLOBAL(HighGuid::UniqueUserClient)
GUID_TRAIT_GLOBAL(HighGuid::BattlePet)
GUID_TRAIT_REALM_SPECIFIC(HighGuid::Player)
GUID_TRAIT_REALM_SPECIFIC(HighGuid::Item)       // This is not exactly correct, there are 2 more unknown parts in highguid: (high >> 10 & 0xFF), (high >> 18 & 0xFFFFFF)
GUID_TRAIT_REALM_SPECIFIC(HighGuid::Transport)
GUID_TRAIT_REALM_SPECIFIC(HighGuid::Guild)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Conversation)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Creature)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Vehicle)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Pet)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::GameObject)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::DynamicObject)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::AreaTrigger)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Corpse)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::LootObject)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::SceneObject)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Scenario)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::AIGroup)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::DynamicDoor)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::Vignette)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::CallForHelp)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::AIResource)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::AILock)
GUID_TRAIT_MAP_SPECIFIC(HighGuid::AILockTicket)

class ObjectGuid;
class PackedGuid;

#pragma pack(push, 1)

class TC_GAME_API ObjectGuid
{
    friend TC_GAME_API std::ostream& operator<<(std::ostream& stream, ObjectGuid const& guid);
    friend TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid);
    friend TC_GAME_API ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid& guid);

    public:
        static ObjectGuid const Empty;
        static ObjectGuid const TradeItem;

        typedef uint64 LowType;

        template<HighGuid type>
        static typename std::enable_if<ObjectGuidTraits<type>::Global, ObjectGuid>::type Create(LowType counter) { return Global(type, counter); }

        template<HighGuid type>
        static typename std::enable_if<ObjectGuidTraits<type>::RealmSpecific, ObjectGuid>::type Create(LowType counter) { return RealmSpecific(type, counter); }

        template<HighGuid type>
        static typename std::enable_if<ObjectGuidTraits<type>::MapSpecific, ObjectGuid>::type Create(uint16 mapId, uint32 entry, LowType counter) { return MapSpecific(type, 0, mapId, 0, entry, counter); }

        ObjectGuid() : _low(0), _high(0) { }

        std::vector<uint8> GetRawValue() const;
        void SetRawValue(std::vector<uint8> const& guid);
        void SetRawValue(uint64 high, uint64 low) { _high = high; _low = low; }
        void Clear() { _high = 0; _low = 0; }

        HighGuid GetHigh() const { return HighGuid((_high >> 58) & 0x3F); }
        uint32 GetRealmId() const { return uint32((_high >> 42) & 0x1FFF); }
        uint32 GetMapId() const { return uint32((_high >> 29) & 0x1FFF); }
        uint32 GetEntry() const { return uint32((_high >> 6) & 0x7FFFFF); }
        LowType GetCounter() const { return _low & UI64LIT(0x000000FFFFFFFFFF); }

        static LowType GetMaxCounter(HighGuid /*high*/)
        {
            return UI64LIT(0xFFFFFFFFFF);
        }

        LowType GetMaxCounter() const { return GetMaxCounter(GetHigh()); }

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
        bool IsCreature()          const { return GetHigh() == HighGuid::Creature; }
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
        bool IsAreaTrigger()       const { return GetHigh() == HighGuid::AreaTrigger; }
        bool IsMOTransport()       const { return GetHigh() == HighGuid::Transport; }
        bool IsAnyTypeGameObject() const { return IsGameObject() || IsMOTransport(); }
        bool IsParty()             const { return GetHigh() == HighGuid::Party; }
        bool IsGuild()             const { return GetHigh() == HighGuid::Guild; }
        bool IsSceneObject()       const { return GetHigh() == HighGuid::SceneObject; }
        bool IsConversation()      const { return GetHigh() == HighGuid::Conversation; }

        static TypeID GetTypeId(HighGuid high)
        {
            switch (high)
            {
                case HighGuid::Item:            return TYPEID_ITEM;
                case HighGuid::Creature:
                case HighGuid::Pet:
                case HighGuid::Vehicle:         return TYPEID_UNIT;
                case HighGuid::Player:          return TYPEID_PLAYER;
                case HighGuid::GameObject:
                case HighGuid::Transport:       return TYPEID_GAMEOBJECT;
                case HighGuid::DynamicObject:   return TYPEID_DYNAMICOBJECT;
                case HighGuid::Corpse:          return TYPEID_CORPSE;
                case HighGuid::AreaTrigger:     return TYPEID_AREATRIGGER;
                case HighGuid::SceneObject:     return TYPEID_SCENEOBJECT;
                case HighGuid::Conversation:    return TYPEID_CONVERSATION;
                default:                        return TYPEID_OBJECT;
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
                case HighGuid::GameObject:
                case HighGuid::Creature:
                case HighGuid::Pet:
                case HighGuid::Vehicle:
                default:
                    return true;
            }
        }

        bool HasEntry() const { return HasEntry(GetHigh()); }

        static ObjectGuid Global(HighGuid type, LowType counter);
        static ObjectGuid RealmSpecific(HighGuid type, LowType counter);
        static ObjectGuid MapSpecific(HighGuid type, uint8 subType, uint16 mapId, uint32 serverId, uint32 entry, LowType counter);

        ObjectGuid(uint64 high, uint64 low) : _low(low), _high(high) { }
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
typedef std::unordered_set<ObjectGuid> GuidUnorderedSet;

// maximum buffer size for packed guid is 18 bytes
#define PACKED_GUID_MIN_BUFFER_SIZE 18

class TC_GAME_API PackedGuid
{
        friend TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);

    public:
        explicit PackedGuid() : _packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { _packedGuid << uint16(0); }
        explicit PackedGuid(ObjectGuid const& guid) : _packedGuid(PACKED_GUID_MIN_BUFFER_SIZE) { Set(guid); }

        void Set(ObjectGuid const& guid);

        size_t size() const { return _packedGuid.size(); }

    private:
        ByteBuffer _packedGuid;
};

class TC_GAME_API ObjectGuidGeneratorBase
{
public:
    ObjectGuidGeneratorBase(ObjectGuid::LowType start = UI64LIT(1)) : _nextGuid(start) { }

    virtual void Set(uint64 val) { _nextGuid = val; }
    virtual ObjectGuid::LowType Generate() = 0;
    ObjectGuid::LowType GetNextAfterMaxUsed() const { return _nextGuid; }

protected:
    static void HandleCounterOverflow(HighGuid high);
    uint64 _nextGuid;
};

template<HighGuid high>
class TC_GAME_API ObjectGuidGenerator : public ObjectGuidGeneratorBase
{
public:
    explicit ObjectGuidGenerator(ObjectGuid::LowType start = UI64LIT(1)) : ObjectGuidGeneratorBase(start) { }

    ObjectGuid::LowType Generate() override
    {
        if (_nextGuid >= ObjectGuid::GetMaxCounter(high) - 1)
            HandleCounterOverflow(high);
        return _nextGuid++;
    }
};

TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid);
TC_GAME_API ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid&       guid);

TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid);

TC_GAME_API std::ostream& operator<<(std::ostream& stream, ObjectGuid const& guid);

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
