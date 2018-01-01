/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITYCORE_GROUP_H
#define TRINITYCORE_GROUP_H

#include "DBCEnums.h"
#include "DatabaseEnvFwd.h"
#include "GroupRefManager.h"
#include "Loot.h"
#include "Object.h"
#include "SharedDefines.h"
#include <map>

class Battlefield;
class Battleground;
class Creature;
class InstanceSave;
class Map;
class Player;
class Unit;
class WorldObject;
class WorldPacket;
class WorldSession;

struct MapEntry;

namespace WorldPackets
{
    namespace Loot
    {
        struct LootItemData;
    }
}

#define MAX_GROUP_SIZE      5
#define MAX_RAID_SIZE       40
#define MAX_RAID_SUBGROUPS  MAX_RAID_SIZE / MAX_GROUP_SIZE

#define TARGET_ICONS_COUNT  8
#define RAID_MARKERS_COUNT  8

#define READYCHECK_DURATION 35000

enum RollVote
{
    PASS              = 0,
    NEED              = 1,
    GREED             = 2,
    DISENCHANT        = 3,
    NOT_EMITED_YET    = 4,
    NOT_VALID         = 5
};

enum GroupMemberOnlineStatus
{
    MEMBER_STATUS_OFFLINE   = 0x0000,
    MEMBER_STATUS_ONLINE    = 0x0001,                       // Lua_UnitIsConnected
    MEMBER_STATUS_PVP       = 0x0002,                       // Lua_UnitIsPVP
    MEMBER_STATUS_DEAD      = 0x0004,                       // Lua_UnitIsDead
    MEMBER_STATUS_GHOST     = 0x0008,                       // Lua_UnitIsGhost
    MEMBER_STATUS_PVP_FFA   = 0x0010,                       // Lua_UnitIsPVPFreeForAll
    MEMBER_STATUS_UNK3      = 0x0020,                       // used in calls from Lua_GetPlayerMapPosition/Lua_GetBattlefieldFlagPosition
    MEMBER_STATUS_AFK       = 0x0040,                       // Lua_UnitIsAFK
    MEMBER_STATUS_DND       = 0x0080,                       // Lua_UnitIsDND
    MEMBER_STATUS_RAF       = 0x0100,
    MEMBER_STATUS_VEHICLE   = 0x0200,                       // Lua_UnitInVehicle
};

enum GroupMemberFlags
{
    MEMBER_FLAG_ASSISTANT   = 0x01,
    MEMBER_FLAG_MAINTANK    = 0x02,
    MEMBER_FLAG_MAINASSIST  = 0x04
};

enum GroupMemberAssignment
{
    GROUP_ASSIGN_MAINTANK   = 0,
    GROUP_ASSIGN_MAINASSIST = 1
};

enum GroupType
{
    GROUP_TYPE_NONE         = 0,
    GROUP_TYPE_NORMAL       = 1,
    GROUP_TYPE_WORLD_PVP    = 4
};

enum GroupFlags
{
    GROUP_FLAG_NONE                 = 0x000,
    GROUP_FLAG_FAKE_RAID            = 0x001,
    GROUP_FLAG_RAID                 = 0x002,
    GROUP_FLAG_LFG_RESTRICTED       = 0x004, // Script_HasLFGRestrictions()
    GROUP_FLAG_LFG                  = 0x008,
    GROUP_FLAG_DESTROYED            = 0x010,
    GROUP_FLAG_ONE_PERSON_PARTY     = 0x020, // Script_IsOnePersonParty()
    GROUP_FLAG_EVERYONE_ASSISTANT   = 0x040, // Script_IsEveryoneAssistant()
    GROUP_FLAG_GUILD_GROUP          = 0x100,

    GROUP_MASK_BGRAID                = GROUP_FLAG_FAKE_RAID | GROUP_FLAG_RAID,
};

enum GroupCategory : uint8
{
    GROUP_CATEGORY_HOME     = 0,
    GROUP_CATEGORY_INSTANCE = 1,

    MAX_GROUP_CATEGORY
};

enum GroupUpdateFlags
{
    GROUP_UPDATE_FLAG_NONE              = 0x00000000,       // nothing
    GROUP_UPDATE_FLAG_UNK704            = 0x00000001,       // uint8[2] (unk)
    GROUP_UPDATE_FLAG_STATUS            = 0x00000002,       // uint16 (GroupMemberStatusFlag)
    GROUP_UPDATE_FLAG_POWER_TYPE        = 0x00000004,       // uint8 (PowerType)
    GROUP_UPDATE_FLAG_UNK322            = 0x00000008,       // uint16 (unk)
    GROUP_UPDATE_FLAG_CUR_HP            = 0x00000010,       // uint32 (HP)
    GROUP_UPDATE_FLAG_MAX_HP            = 0x00000020,       // uint32 (max HP)
    GROUP_UPDATE_FLAG_CUR_POWER         = 0x00000040,       // int16 (power value)
    GROUP_UPDATE_FLAG_MAX_POWER         = 0x00000080,       // int16 (max power value)
    GROUP_UPDATE_FLAG_LEVEL             = 0x00000100,       // uint16 (level value)
    GROUP_UPDATE_FLAG_UNK200000         = 0x00000200,       // int16 (unk)
    GROUP_UPDATE_FLAG_ZONE              = 0x00000400,       // uint16 (zone id)
    GROUP_UPDATE_FLAG_UNK2000000        = 0x00000800,       // int16 (unk)
    GROUP_UPDATE_FLAG_UNK4000000        = 0x00001000,       // int32 (unk)
    GROUP_UPDATE_FLAG_POSITION          = 0x00002000,       // uint16 (x), uint16 (y), uint16 (z)
    GROUP_UPDATE_FLAG_VEHICLE_SEAT      = 0x00104000,       // int32 (vehicle seat id)
    GROUP_UPDATE_FLAG_AURAS             = 0x00008000,       // uint8 (unk), uint64 (mask), uint32 (count), for each bit set: uint32 (spell id) + uint16 (AuraFlags)  (if has flags Scalable -> 3x int32 (bps))
    GROUP_UPDATE_FLAG_PET               = 0x00010000,       // complex (pet)
    GROUP_UPDATE_FLAG_PHASE             = 0x00020000,       // int32 (unk), uint32 (phase count), for (count) uint16(phaseId)

    GROUP_UPDATE_FULL =  GROUP_UPDATE_FLAG_UNK704 | GROUP_UPDATE_FLAG_STATUS | GROUP_UPDATE_FLAG_POWER_TYPE |
                        GROUP_UPDATE_FLAG_UNK322 | GROUP_UPDATE_FLAG_CUR_HP | GROUP_UPDATE_FLAG_MAX_HP |
                        GROUP_UPDATE_FLAG_CUR_POWER | GROUP_UPDATE_FLAG_MAX_POWER | GROUP_UPDATE_FLAG_LEVEL |
                        GROUP_UPDATE_FLAG_UNK200000 | GROUP_UPDATE_FLAG_ZONE | GROUP_UPDATE_FLAG_UNK2000000 |
                        GROUP_UPDATE_FLAG_UNK4000000 | GROUP_UPDATE_FLAG_POSITION | GROUP_UPDATE_FLAG_VEHICLE_SEAT |
                        GROUP_UPDATE_FLAG_AURAS | GROUP_UPDATE_FLAG_PET | GROUP_UPDATE_FLAG_PHASE // all known flags
};

enum GroupUpdatePetFlags
{
    GROUP_UPDATE_FLAG_PET_NONE      = 0x00000000,       // nothing
    GROUP_UPDATE_FLAG_PET_GUID      = 0x00000001,       // ObjectGuid (pet guid)
    GROUP_UPDATE_FLAG_PET_NAME      = 0x00000002,       // cstring (name, NULL terminated string)
    GROUP_UPDATE_FLAG_PET_MODEL_ID  = 0x00000004,       // uint16 (model id)
    GROUP_UPDATE_FLAG_PET_CUR_HP    = 0x00000008,       // uint32 (HP)
    GROUP_UPDATE_FLAG_PET_MAX_HP    = 0x00000010,       // uint32 (max HP)
    GROUP_UPDATE_FLAG_PET_AURAS     = 0x00000020,       // [see GROUP_UPDATE_FLAG_AURAS]

    GROUP_UPDATE_PET_FULL = GROUP_UPDATE_FLAG_PET_GUID | GROUP_UPDATE_FLAG_PET_NAME | GROUP_UPDATE_FLAG_PET_MODEL_ID |
                            GROUP_UPDATE_FLAG_PET_CUR_HP | GROUP_UPDATE_FLAG_PET_MAX_HP | GROUP_UPDATE_FLAG_PET_AURAS // all pet flags
};

class Roll : public LootValidatorRef
{
    public:
        explicit Roll(LootItem const& li);
        ~Roll();
        void setLoot(Loot* pLoot);
        Loot* getLoot();
        void targetObjectBuildLink() override;
        void FillPacket(WorldPackets::Loot::LootItemData& lootItem) const;

        uint32 itemid;
        ItemRandomEnchantmentId itemRandomPropId;
        uint32 itemRandomSuffix;
        uint8 itemCount;
        typedef std::map<ObjectGuid, RollVote> PlayerVote;
        PlayerVote playerVote;                              //vote position correspond with player position (in group)
        uint8 totalPlayersRolling;
        uint8 totalNeed;
        uint8 totalGreed;
        uint8 totalPass;
        uint8 itemSlot;
        uint8 rollVoteMask;
};

struct InstanceGroupBind
{
    InstanceSave* save;
    bool perm;
    /* permanent InstanceGroupBinds exist if the leader has a permanent
       PlayerInstanceBind for the same instance. */
    InstanceGroupBind() : save(NULL), perm(false) { }
};

struct RaidMarker
{
    WorldLocation Location;
    ObjectGuid TransportGUID;

    RaidMarker(uint32 mapId, float positionX, float positionY, float positionZ, ObjectGuid transportGuid = ObjectGuid::Empty)
    {
        Location.WorldRelocate(mapId, positionX, positionY, positionZ);
        TransportGUID = transportGuid;
    }
};

/** request member stats checken **/
/// @todo uninvite people that not accepted invite
class TC_GAME_API Group
{
    public:
        struct MemberSlot
        {
            ObjectGuid  guid;
            std::string name;
            uint8       _class;
            uint8       group;
            uint8       flags;
            uint8       roles;
            bool        readyChecked;
        };
        typedef std::list<MemberSlot> MemberSlotList;
        typedef MemberSlotList::const_iterator member_citerator;

        typedef std::unordered_map< uint32 /*mapId*/, InstanceGroupBind> BoundInstancesMap;
    protected:
        typedef MemberSlotList::iterator member_witerator;
        typedef std::set<Player*> InvitesList;

        typedef std::vector<Roll*> Rolls;

    public:
        Group();
        ~Group();

        // group manipulation methods
        bool   Create(Player* leader);
        void   LoadGroupFromDB(Field* field);
        void LoadMemberFromDB(ObjectGuid::LowType guidLow, uint8 memberFlags, uint8 subgroup, uint8 roles);
        bool   AddInvite(Player* player);
        void   RemoveInvite(Player* player);
        void   RemoveAllInvites();
        bool   AddLeaderInvite(Player* player);
        bool   AddMember(Player* player);
        bool   RemoveMember(ObjectGuid guid, const RemoveMethod &method = GROUP_REMOVEMETHOD_DEFAULT, ObjectGuid kicker = ObjectGuid::Empty, const char* reason = NULL);
        void   ChangeLeader(ObjectGuid guid, int8 partyIndex = 0);
 static void   ConvertLeaderInstancesToGroup(Player* player, Group* group, bool switchLeader);
        void   SetLootMethod(LootMethod method);
        void   SetLooterGuid(ObjectGuid guid);
        void   SetMasterLooterGuid(ObjectGuid guid);
        void   UpdateLooterGuid(WorldObject* pLootedObject, bool ifneed = false);
        void   SetLootThreshold(ItemQualities threshold);
        void   Disband(bool hideDestroy = false);
        void   SetLfgRoles(ObjectGuid guid, uint8 roles);
        uint8  GetLfgRoles(ObjectGuid guid);
        void   SetEveryoneIsAssistant(bool apply);

        // Update
        void   Update(uint32 diff);
        void   UpdateReadyCheck(uint32 diff);

        // Ready check
        void StartReadyCheck(ObjectGuid starterGuid, int8 partyIndex, uint32 duration = READYCHECK_DURATION);
        void EndReadyCheck();

        bool IsReadyCheckStarted(void) const { return m_readyCheckStarted; }
        bool IsReadyCheckCompleted(void) const;

        void SetOfflineMembersReadyChecked(void);
        void SetMemberReadyCheck(ObjectGuid guid, bool ready);
        void SetMemberReadyCheck(MemberSlot* slot, bool ready);

        void SetMemberReadyChecked(MemberSlot* slot);
        void ResetMemberReadyChecked(void);

        // Raid Markers
        void AddRaidMarker(uint8 markerId, uint32 mapId, float positionX, float positionY, float positionZ, ObjectGuid transportGuid = ObjectGuid::Empty);
        void DeleteRaidMarker(uint8 markerId);
        void SendRaidMarkersChanged(WorldSession* session = nullptr, int8 partyIndex = 0);

        // properties accessories
        bool IsFull() const;
        bool isLFGGroup()  const;
        bool isRaidGroup() const;
        bool isBGGroup()   const;
        bool isBFGroup()   const;
        bool IsCreated()   const;
        GroupCategory GetGroupCategory() const { return m_groupCategory; }
        ObjectGuid GetLeaderGUID() const;
        ObjectGuid GetGUID() const;
        const char * GetLeaderName() const;
        LootMethod GetLootMethod() const;
        ObjectGuid GetLooterGuid() const;
        ObjectGuid GetMasterLooterGuid() const;
        ItemQualities GetLootThreshold() const;

        uint32 GetDbStoreId() const { return m_dbStoreId; }

        // member manipulation methods
        bool IsMember(ObjectGuid guid) const;
        bool IsLeader(ObjectGuid guid) const;
        ObjectGuid GetMemberGUID(const std::string& name);
        bool IsAssistant(ObjectGuid guid) const;

        Player* GetInvited(ObjectGuid guid) const;
        Player* GetInvited(const std::string& name) const;

        bool SameSubGroup(ObjectGuid guid1, ObjectGuid guid2) const;
        bool SameSubGroup(ObjectGuid guid1, MemberSlot const* slot2) const;
        bool SameSubGroup(Player const* member1, Player const* member2) const;
        bool HasFreeSlotSubGroup(uint8 subgroup) const;

        MemberSlotList const& GetMemberSlots() const { return m_memberSlots; }
        GroupReference* GetFirstMember() { return m_memberMgr.getFirst(); }
        GroupReference const* GetFirstMember() const { return m_memberMgr.getFirst(); }
        uint32 GetMembersCount() const { return uint32(m_memberSlots.size()); }
        GroupFlags GetGroupFlags() const { return m_groupFlags; }

        uint8 GetMemberGroup(ObjectGuid guid) const;

        void ConvertToLFG();
        void ConvertToRaid();
        void ConvertToGroup();

        void SetBattlegroundGroup(Battleground* bg);
        void SetBattlefieldGroup(Battlefield* bf);
        GroupJoinBattlegroundResult CanJoinBattlegroundQueue(Battleground const* bgOrTemplate, BattlegroundQueueTypeId bgQueueTypeId, uint32 MinPlayerCount, uint32 MaxPlayerCount, bool isRated, uint32 arenaSlot, ObjectGuid& errorGuid);

        void ChangeMembersGroup(ObjectGuid guid, uint8 group);
        void SwapMembersGroups(ObjectGuid firstGuid, ObjectGuid secondGuid);
        void SetTargetIcon(uint8 symbol, ObjectGuid target, ObjectGuid changedBy, uint8 partyIndex);
        void SetGroupMemberFlag(ObjectGuid guid, bool apply, GroupMemberFlags flag);
        void RemoveUniqueGroupMemberFlag(GroupMemberFlags flag);

        void SetDungeonDifficultyID(Difficulty difficulty);
        void SetRaidDifficultyID(Difficulty difficulty);
        void SetLegacyRaidDifficultyID(Difficulty difficulty);
        Difficulty GetDifficultyID(MapEntry const* mapEntry) const;
        Difficulty GetDungeonDifficultyID() const { return m_dungeonDifficulty; }
        Difficulty GetRaidDifficultyID() const { return m_raidDifficulty; }
        Difficulty GetLegacyRaidDifficultyID() const { return m_legacyRaidDifficulty; }
        void ResetInstances(uint8 method, bool isRaid, bool isLegacy, Player* SendMsgTo);

        // -no description-
        //void SendInit(WorldSession* session);
        void SendTargetIconList(WorldSession* session, int8 partyIndex = 0);
        void SendUpdate();
        void SendUpdateToPlayer(ObjectGuid playerGUID, MemberSlot* slot = NULL);
        void SendUpdateDestroyGroupToPlayer(Player* player) const;
        void UpdatePlayerOutOfRange(Player* player);

        template<class Worker>
        void BroadcastWorker(Worker& worker)
        {
            for (GroupReference* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
                worker(itr->GetSource());
        }

        template<class Worker>
        void BroadcastWorker(Worker const& worker) const
        {
            for (GroupReference const* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
                worker(itr->GetSource());
        }

        void BroadcastPacket(WorldPacket const* packet, bool ignorePlayersInBGRaid, int group = -1, ObjectGuid ignoredPlayer = ObjectGuid::Empty);
        void BroadcastAddonMessagePacket(WorldPacket const* packet, const std::string& prefix, bool ignorePlayersInBGRaid, int group = -1, ObjectGuid ignore = ObjectGuid::Empty);

        /*********************************************************/
        /***                   LOOT SYSTEM                     ***/
        /*********************************************************/

        bool isRollLootActive() const { return !RollId.empty(); }
        void SendLootStartRollToPlayer(uint32 countDown, uint32 mapId, Player* p, bool canNeed, Roll const& r) const;
        void SendLootRoll(ObjectGuid playerGuid, int32 rollNumber, uint8 rollType, Roll const& roll) const;
        void SendLootRollWon(ObjectGuid winnerGuid, int32 rollNumber, uint8 rollType, Roll const& roll) const;
        void SendLootAllPassed(Roll const& roll) const;
        void SendLootRollsComplete(Roll const& roll) const;
        void SendLooter(Creature* creature, Player* pLooter);
        void GroupLoot(Loot* loot, WorldObject* pLootedObject);
        void MasterLoot(Loot* loot, WorldObject* pLootedObject);
        Rolls::iterator GetRoll(ObjectGuid lootObjectGuid, uint8 lootListId);
        void CountTheRoll(Rolls::iterator roll);
        void CountRollVote(ObjectGuid playerGuid, ObjectGuid lootObjectGuid, uint8 lootListId, uint8 choice);
        void EndRoll(Loot* loot);

        // related to disenchant rolls
        void ResetMaxEnchantingLevel();

        void LinkMember(GroupReference* pRef);
        void DelinkMember(ObjectGuid guid);

        InstanceGroupBind* BindToInstance(InstanceSave* save, bool permanent, bool load = false);
        void UnbindInstance(uint32 mapid, uint8 difficulty, bool unload = false);
        InstanceGroupBind* GetBoundInstance(Player* player);
        InstanceGroupBind* GetBoundInstance(Map* aMap);
        InstanceGroupBind* GetBoundInstance(MapEntry const* mapEntry);
        InstanceGroupBind* GetBoundInstance(Difficulty difficulty, uint32 mapId);
        BoundInstancesMap& GetBoundInstances(Difficulty difficulty);

        // FG: evil hacks
        void BroadcastGroupUpdate(void);

    protected:
        bool _setMembersGroup(ObjectGuid guid, uint8 group);
        void _homebindIfInstance(Player* player);

        void _initRaidSubGroupsCounter();
        member_citerator _getMemberCSlot(ObjectGuid Guid) const;
        member_witerator _getMemberWSlot(ObjectGuid Guid);
        void SubGroupCounterIncrease(uint8 subgroup);
        void SubGroupCounterDecrease(uint8 subgroup);
        void ToggleGroupMemberFlag(member_witerator slot, uint8 flag, bool apply);

        MemberSlotList      m_memberSlots;
        GroupRefManager     m_memberMgr;
        InvitesList         m_invitees;
        ObjectGuid          m_leaderGuid;
        std::string         m_leaderName;
        GroupFlags          m_groupFlags;
        GroupCategory       m_groupCategory;
        Difficulty          m_dungeonDifficulty;
        Difficulty          m_raidDifficulty;
        Difficulty          m_legacyRaidDifficulty;
        Battleground*       m_bgGroup;
        Battlefield*        m_bfGroup;
        ObjectGuid          m_targetIcons[TARGET_ICONS_COUNT];
        LootMethod          m_lootMethod;
        ItemQualities       m_lootThreshold;
        ObjectGuid          m_looterGuid;
        ObjectGuid          m_masterLooterGuid;
        Rolls               RollId;
        BoundInstancesMap   m_boundInstances[MAX_DIFFICULTY];
        uint8*              m_subGroupsCounts;
        ObjectGuid          m_guid;
        uint32              m_maxEnchantingLevel;
        uint32              m_dbStoreId;                    // Represents the ID used in database (Can be reused by other groups if group was disbanded)

        // Ready Check
        bool                m_readyCheckStarted;
        int32               m_readyCheckTimer;

        // Raid markers
        std::array<std::unique_ptr<RaidMarker>, RAID_MARKERS_COUNT> m_markers;
        uint32              m_activeMarkers;
};
#endif
