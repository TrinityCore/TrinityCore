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
#include "EnumFlag.h"
#include <deque>
#include <functional>
#include <list>
#include <set>
#include <string>
#include <type_traits>
#include <vector>
#include <unordered_set>

enum TypeID
{
    TYPEID_OBJECT                 = 0,
    TYPEID_ITEM                   = 1,
    TYPEID_CONTAINER              = 2,
    TYPEID_AZERITE_EMPOWERED_ITEM = 3,
    TYPEID_AZERITE_ITEM           = 4,
    TYPEID_UNIT                   = 5,
    TYPEID_PLAYER                 = 6,
    TYPEID_ACTIVE_PLAYER          = 7,
    TYPEID_GAMEOBJECT             = 8,
    TYPEID_DYNAMICOBJECT          = 9,
    TYPEID_CORPSE                 = 10,
    TYPEID_AREATRIGGER            = 11,
    TYPEID_SCENEOBJECT            = 12,
    TYPEID_CONVERSATION           = 13
};

#define NUM_CLIENT_OBJECT_TYPES             14

enum TypeMask
{
    TYPEMASK_OBJECT                 = 0x0001,
    TYPEMASK_ITEM                   = 0x0002,
    TYPEMASK_CONTAINER              = 0x0004,
    TYPEMASK_AZERITE_EMPOWERED_ITEM = 0x0008,
    TYPEMASK_AZERITE_ITEM           = 0x0010,
    TYPEMASK_UNIT                   = 0x0020,
    TYPEMASK_PLAYER                 = 0x0040,
    TYPEMASK_ACTIVE_PLAYER          = 0x0080,
    TYPEMASK_GAMEOBJECT             = 0x0100,
    TYPEMASK_DYNAMICOBJECT          = 0x0200,
    TYPEMASK_CORPSE                 = 0x0400,
    TYPEMASK_AREATRIGGER            = 0x0800,
    TYPEMASK_SCENEOBJECT            = 0x1000,
    TYPEMASK_CONVERSATION           = 0x2000,
    TYPEMASK_SEER                   = TYPEMASK_PLAYER | TYPEMASK_UNIT | TYPEMASK_DYNAMICOBJECT
};

enum class HighGuid
{
    Null             = 0,
    Uniq             = 1,
    Player           = 2,
    Item             = 3,
    WorldTransaction = 4,
    StaticDoor       = 5,   //NYI
    Transport        = 6,
    Conversation     = 7,
    Creature         = 8,
    Vehicle          = 9,
    Pet              = 10,
    GameObject       = 11,
    DynamicObject    = 12,
    AreaTrigger      = 13,
    Corpse           = 14,
    LootObject       = 15,
    SceneObject      = 16,
    Scenario         = 17,
    AIGroup          = 18,
    DynamicDoor      = 19,
    ClientActor      = 20,  //NYI
    Vignette         = 21,
    CallForHelp      = 22,
    AIResource       = 23,
    AILock           = 24,
    AILockTicket     = 25,
    ChatChannel      = 26,
    Party            = 27,
    Guild            = 28,
    WowAccount       = 29,
    BNetAccount      = 30,
    GMTask           = 31,
    MobileSession    = 32,  //NYI
    RaidGroup        = 33,
    Spell            = 34,
    Mail             = 35,
    WebObj           = 36,  //NYI
    LFGObject        = 37,  //NYI
    LFGList          = 38,  //NYI
    UserRouter       = 39,
    PVPQueueGroup    = 40,
    UserClient       = 41,
    PetBattle        = 42,  //NYI
    UniqUserClient   = 43,
    BattlePet        = 44,
    CommerceObj      = 45,
    ClientSession    = 46,
    Cast             = 47,
    ClientConnection = 48,
    ClubFinder       = 49,

    Count,
};

enum class ObjectGuidSequenceSource
{
    None    = 0x0,
    Global  = 0x1,
    Realm   = 0x2,
    Map     = 0x4
};

DEFINE_ENUM_FLAG(ObjectGuidSequenceSource);

enum class ObjectGuidFormatType
{
    Null,
    Uniq,
    Player,
    Item,
    WorldObject,
    Transport,
    ClientActor,
    ChatChannel,
    Global,
    Guild,
    MobileSession,
    WebObj,
    LFGObject,
    LFGList,
    Client,
    ClubFinder,
};

template<HighGuid high>
struct ObjectGuidTraits
{
    static constexpr EnumFlag<ObjectGuidSequenceSource> SequenceSource = ObjectGuidSequenceSource::None;
    using Format = std::integral_constant<ObjectGuidFormatType, ObjectGuidFormatType::Null>;
};

#define MAKE_GUID_TRAIT(high, sequence, format) \
    template<> struct ObjectGuidTraits<high> \
    { \
        static constexpr EnumFlag<ObjectGuidSequenceSource> SequenceSource = sequence; \
        using Format = std::integral_constant<ObjectGuidFormatType, format>; \
    }

MAKE_GUID_TRAIT(HighGuid::Null, ObjectGuidSequenceSource::None, ObjectGuidFormatType::Null);
MAKE_GUID_TRAIT(HighGuid::Uniq, ObjectGuidSequenceSource::None, ObjectGuidFormatType::Uniq);
MAKE_GUID_TRAIT(HighGuid::Player, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::Player);
MAKE_GUID_TRAIT(HighGuid::Item, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::Item);
MAKE_GUID_TRAIT(HighGuid::WorldTransaction, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::StaticDoor, ObjectGuidSequenceSource::Global | ObjectGuidSequenceSource::Map, ObjectGuidFormatType::Transport);
MAKE_GUID_TRAIT(HighGuid::Transport, ObjectGuidSequenceSource::Global | ObjectGuidSequenceSource::Map, ObjectGuidFormatType::Transport);
MAKE_GUID_TRAIT(HighGuid::Conversation, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::Creature, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::Vehicle, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::Pet, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::GameObject, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::DynamicObject, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::AreaTrigger, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::Corpse, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::LootObject, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::SceneObject, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::Scenario, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::AIGroup, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::DynamicDoor, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::ClientActor, ObjectGuidSequenceSource::None, ObjectGuidFormatType::ClientActor);
MAKE_GUID_TRAIT(HighGuid::Vignette, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::CallForHelp, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::AIResource, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::AILock, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::AILockTicket, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::ChatChannel, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::ChatChannel);
MAKE_GUID_TRAIT(HighGuid::Party, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::Guild, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::Guild);
MAKE_GUID_TRAIT(HighGuid::WowAccount, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::BNetAccount, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::GMTask, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::MobileSession, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::MobileSession);
MAKE_GUID_TRAIT(HighGuid::RaidGroup, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::Spell, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::Mail, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::WebObj, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::WebObj);
MAKE_GUID_TRAIT(HighGuid::LFGObject, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::LFGObject);
MAKE_GUID_TRAIT(HighGuid::LFGList, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::LFGList);
MAKE_GUID_TRAIT(HighGuid::UserRouter, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::PVPQueueGroup, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::UserClient, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::PetBattle, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::Client);
MAKE_GUID_TRAIT(HighGuid::UniqUserClient, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::Client);
MAKE_GUID_TRAIT(HighGuid::BattlePet, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::CommerceObj, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::Global);
MAKE_GUID_TRAIT(HighGuid::ClientSession, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::Client);
MAKE_GUID_TRAIT(HighGuid::Cast, ObjectGuidSequenceSource::Map, ObjectGuidFormatType::WorldObject);
MAKE_GUID_TRAIT(HighGuid::ClientConnection, ObjectGuidSequenceSource::Realm, ObjectGuidFormatType::Client);
MAKE_GUID_TRAIT(HighGuid::ClubFinder, ObjectGuidSequenceSource::Global, ObjectGuidFormatType::ClubFinder);

class ByteBuffer;
class ObjectGuid;

class TC_GAME_API ObjectGuidFactory
{
public:
    static ObjectGuid CreateNull();
    static ObjectGuid CreateUniq(uint64 id);
    static ObjectGuid CreatePlayer(uint64 dbId);
    static ObjectGuid CreateItem(uint64 dbId);
    static ObjectGuid CreateWorldObject(HighGuid type, uint8 subType, uint16 mapId, uint32 serverId, uint32 entry, uint64 counter);
    static ObjectGuid CreateTransport(HighGuid type, uint32 counter);
    static ObjectGuid CreateClientActor(uint16 ownerType, uint16 ownerId, uint32 counter);
    static ObjectGuid CreateChatChannel(bool builtIn, bool trade, uint16 zoneId, uint8 factionGroupMask, uint64 counter);
    static ObjectGuid CreateGlobal(HighGuid type, uint64 dbIdHigh, uint64 dbId);
    static ObjectGuid CreateGuild(uint64 dbId);
    static ObjectGuid CreateMobileSession(uint16 arg1, uint64 counter);
    static ObjectGuid CreateWebObj(uint8 arg1, uint8 arg2, uint64 counter);
    static ObjectGuid CreateLFGObject(uint8 arg1, uint8 arg2, uint8 arg3, uint8 arg4, bool arg5, uint8 arg6, uint64 counter);
    static ObjectGuid CreateLFGList(uint8 arg1, uint64 counter);
    static ObjectGuid CreateClient(HighGuid type, uint32 arg1, uint64 counter);
    static ObjectGuid CreateClubFinder(uint8 type, uint32 clubFinderId, uint64 dbId);
};

#pragma pack(push, 1)

class TC_GAME_API ObjectGuid
{
    friend class ObjectGuidFactory;
    friend TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid);
    friend TC_GAME_API ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid& guid);

    public:
        static ObjectGuid const Empty;
        static ObjectGuid const TradeItem;

        using LowType = uint64;

        ObjectGuid() { Clear(); }

        uint64 GetRawValue(std::size_t i) const { return _data[i]; }
        std::vector<uint8> GetRawValue() const;
        void SetRawValue(std::vector<uint8> const& guid);
        void SetRawValue(uint64 high, uint64 low) { _data[0] = low; _data[1] = high; }
        void Clear() { std::fill(std::begin(_data), std::end(_data), UI64LIT(0)); }

        HighGuid GetHigh() const { return HighGuid((_data[1] >> 58) & 0x3F); }
        uint32 GetRealmId() const { return uint32((_data[1] >> 42) & 0xFFFF); }
        uint32 GetMapId() const { return uint32((_data[1] >> 29) & 0x1FFF); }
        uint32 GetEntry() const { return uint32((_data[1] >> 6) & 0x7FFFFF); }
        uint32 GetSubType() const { return uint32(_data[1] & 0x3F); }
        LowType GetCounter() const
        {
            switch (GetHigh())
            {
                case HighGuid::Transport:
                    return (_data[1] >> 38) & UI64LIT(0xFFFFF);
                default:
                    break;
            }
            return _data[0] & UI64LIT(0x000000FFFFFFFFFF);
        }

        static LowType GetMaxCounter(HighGuid high)
        {
            switch (high)
            {
                case HighGuid::Transport:
                    return UI64LIT(0xFFFFF);
                default:
                    break;
            }
            return UI64LIT(0xFFFFFFFFFF);
        }

        LowType GetMaxCounter() const { return GetMaxCounter(GetHigh()); }

        bool IsEmpty()             const { return _data[0] == 0 && _data[1] == 0; }
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
        bool IsCast()              const { return GetHigh() == HighGuid::Cast; }

        bool operator!() const { return IsEmpty(); }
        bool operator== (ObjectGuid const& guid) const { return _data[0] == guid._data[0] && _data[1] == guid._data[1]; }
        bool operator!= (ObjectGuid const& guid) const { return !(*this == guid); }
        bool operator< (ObjectGuid const& guid) const
        {
            if (_data[1] < guid._data[1])
                return true;
            else if (_data[1] > guid._data[1])
                return false;

            return _data[0] < guid._data[0];
        }

        static char const* GetTypeName(HighGuid high);
        char const* GetTypeName() const { return !IsEmpty() ? GetTypeName(GetHigh()) : "None"; }
        std::string ToString() const;
        std::string ToHexString() const;
        std::size_t GetHash() const;

        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::Null, ObjectGuid> Create() { return ObjectGuidFactory::CreateNull(); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::Uniq, ObjectGuid> Create(ObjectGuid::LowType id) { return ObjectGuidFactory::CreateUniq(id); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::Player, ObjectGuid> Create(ObjectGuid::LowType dbId) { return ObjectGuidFactory::CreatePlayer(dbId); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::Item, ObjectGuid> Create(ObjectGuid::LowType dbId) { return ObjectGuidFactory::CreateItem(dbId); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::WorldObject, ObjectGuid> Create(uint16 mapId, uint32 entry, ObjectGuid::LowType counter) { return ObjectGuidFactory::CreateWorldObject(type, 0, mapId, 0, entry, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::WorldObject, ObjectGuid> Create(uint8 subType, uint16 mapId, uint32 entry, ObjectGuid::LowType counter) { return ObjectGuidFactory::CreateWorldObject(type, subType, mapId, 0, entry, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::Transport, ObjectGuid> Create(uint32 counter) { return ObjectGuidFactory::CreateTransport(type, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::ClientActor, ObjectGuid> Create(uint16 ownerType, uint16 ownerId, uint32 counter) { return ObjectGuidFactory::CreateClientActor(ownerType, ownerId, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::ChatChannel, ObjectGuid> Create(bool builtIn, bool trade, uint16 zoneId, uint8 factionGroupMask, ObjectGuid::LowType counter) { return ObjectGuidFactory::CreateChatChannel(builtIn, trade, zoneId, factionGroupMask, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::Global, ObjectGuid> Create(ObjectGuid::LowType dbId) { return ObjectGuidFactory::CreateGlobal(type, UI64LIT(0), dbId); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::Guild, ObjectGuid> Create(ObjectGuid::LowType dbId) { return ObjectGuidFactory::CreateGuild(dbId); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::MobileSession, ObjectGuid> Create(uint16 arg1, ObjectGuid::LowType counter) { return ObjectGuidFactory::CreateMobileSession(arg1, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::WebObj, ObjectGuid> Create(uint8 arg1, uint8 arg2, ObjectGuid::LowType counter) { return ObjectGuidFactory::CreateWebObj(arg1, arg2, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::LFGObject, ObjectGuid> Create(uint8 arg1, uint8 arg2, uint8 arg3, uint8 arg4, bool arg5, uint8 arg6, ObjectGuid::LowType counter) { return ObjectGuidFactory::CreateLFGObject(arg1, arg2, arg3, arg4, arg5, arg6, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::LFGList, ObjectGuid> Create(uint8 arg1, ObjectGuid::LowType counter) { return ObjectGuidFactory::CreateLFGList(arg1, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::Client, ObjectGuid> Create(uint32 arg1, ObjectGuid::LowType counter) { return ObjectGuidFactory::CreateClient(type, arg1, counter); }
        template<HighGuid type> static std::enable_if_t<ObjectGuidTraits<type>::Format::value == ObjectGuidFormatType::ClubFinder, ObjectGuid> Create(uint8 clubType, uint32 clubFinderId, ObjectGuid::LowType dbId) { return ObjectGuidFactory::CreateClubFinder(clubType, clubFinderId, dbId); }

    protected:
        ObjectGuid(uint64 high, uint64 low)
        {
            _data[0] = low;
            _data[1] = high;
        }

        uint64 _data[2];
};

#pragma pack(pop)

// Some Shared defines
using GuidSet = std::set<ObjectGuid>;
using GuidList = std::list<ObjectGuid>;
using GuidDeque = std::deque<ObjectGuid>;
using GuidVector = std::vector<ObjectGuid>;
using GuidUnorderedSet = std::unordered_set<ObjectGuid>;

class TC_GAME_API ObjectGuidGeneratorBase
{
public:
    ObjectGuidGeneratorBase(ObjectGuid::LowType start = UI64LIT(1)) : _nextGuid(start) { }
    virtual ~ObjectGuidGeneratorBase() = default;

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

namespace std
{
    template<>
    struct hash<ObjectGuid>
    {
    public:
        size_t operator()(ObjectGuid const& key) const
        {
            return key.GetHash();
        }
    };
}

namespace Trinity
{
    namespace Legacy
    {
        enum class TypeID
        {
            Object          = 0,
            Item            = 1,
            Container       = 2,
            Unit            = 3,
            Player          = 4,
            GameObject      = 5,
            DynamicObject   = 6,
            Corpse          = 7,
            AreaTrigger     = 8,
            SceneObject     = 9,
            Conversation    = 10,
            Max
        };

        constexpr inline ::TypeID ConvertLegacyTypeID(TypeID legacyTypeID)
        {
            switch (legacyTypeID)
            {
                case TypeID::Object:
                    return TYPEID_OBJECT;
                case TypeID::Item:
                    return TYPEID_ITEM;
                case TypeID::Container:
                    return TYPEID_CONTAINER;
                case TypeID::Unit:
                    return TYPEID_UNIT;
                case TypeID::Player:
                    return TYPEID_PLAYER;
                case TypeID::GameObject:
                    return TYPEID_GAMEOBJECT;
                case TypeID::DynamicObject:
                    return TYPEID_DYNAMICOBJECT;
                case TypeID::Corpse:
                    return TYPEID_CORPSE;
                case TypeID::AreaTrigger:
                    return TYPEID_AREATRIGGER;
                case TypeID::SceneObject:
                    return TYPEID_SCENEOBJECT;
                case TypeID::Conversation:
                    return TYPEID_CONVERSATION;
                default:
                    return TYPEID_OBJECT;
            }
        }

        constexpr inline TypeMask ConvertLegacyTypeMask(uint32 legacyTypeMask)
        {
            uint32 typeMask = 0;
            for (TypeID i = TypeID::Object; i < TypeID::Max; i = TypeID(uint32(i) + 1))
                if (legacyTypeMask & (1 << uint32(i)))
                    typeMask |= 1u << ConvertLegacyTypeID(i);

            return TypeMask(typeMask);
        }
    }
}

#endif // ObjectGuid_h__
