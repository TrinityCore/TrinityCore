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

#ifndef __BATTLEGROUNDMGR_H
#define __BATTLEGROUNDMGR_H

#include "Common.h"
#include "DBCEnums.h"
#include "Battleground.h"
#include "BattlegroundQueue.h"
#include "UniqueTrackablePtr.h"
#include <unordered_map>

class Battleground;
struct BattlemasterListEntry;

typedef std::map<uint32, Trinity::unique_trackable_ptr<Battleground>> BattlegroundContainer;
typedef std::set<uint32> BattlegroundClientIdsContainer;

typedef std::unordered_map<uint32, BattlegroundTypeId> BattleMastersMap;

enum BattlegroundMisc
{
    BATTLEGROUND_OBJECTIVE_UPDATE_INTERVAL      = 1000
};

struct BattlegroundData
{
    BattlegroundContainer m_Battlegrounds;
    BattlegroundClientIdsContainer m_ClientBattlegroundIds[MAX_BATTLEGROUND_BRACKETS];
};

struct BattlegroundTemplate
{
    BattlegroundTypeId Id;
    WorldSafeLocsEntry const* StartLocation[PVP_TEAMS_COUNT] = { };
    float MaxStartDistSq;
    uint8 Weight;
    uint32 ScriptId;
    BattlemasterListEntry const* BattlemasterEntry;

    bool IsArena() const;
    uint16 GetMinPlayersPerTeam() const;
    uint16 GetMaxPlayersPerTeam() const;
    uint8 GetMinLevel() const;
    uint8 GetMaxLevel() const;
};

namespace WorldPackets
{
    namespace Battleground
    {
        struct BattlefieldStatusHeader;
        class BattlefieldStatusNone;
        class BattlefieldStatusNeedConfirmation;
        class BattlefieldStatusActive;
        class BattlefieldStatusQueued;
        class BattlefieldStatusFailed;
    }
}

class TC_GAME_API BattlegroundMgr
{
    private:
        BattlegroundMgr();
        ~BattlegroundMgr();

    public:
        BattlegroundMgr(BattlegroundMgr const& right) = delete;
        BattlegroundMgr(BattlegroundMgr&& right) = delete;
        BattlegroundMgr& operator=(BattlegroundMgr const& right) = delete;
        BattlegroundMgr& operator=(BattlegroundMgr&& right) = delete;

        static BattlegroundMgr* instance();

        void Update(uint32 diff);

        /* Packet Building */
        void SendBattlegroundList(Player* player, ObjectGuid const& guid, BattlegroundTypeId bgTypeId);
        void BuildBattlegroundStatusHeader(WorldPackets::Battleground::BattlefieldStatusHeader* battlefieldStatus, Player* player, uint32 ticketId, uint32 joinTime, BattlegroundQueueTypeId queueId);
        void BuildBattlegroundStatusNone(WorldPackets::Battleground::BattlefieldStatusNone* battlefieldStatus, Player* player, uint32 ticketId, uint32 joinTime);
        void BuildBattlegroundStatusNeedConfirmation(WorldPackets::Battleground::BattlefieldStatusNeedConfirmation* battlefieldStatus, Battleground* bg, Player* player, uint32 ticketId, uint32 joinTime, uint32 timeout, BattlegroundQueueTypeId queueId);
        void BuildBattlegroundStatusActive(WorldPackets::Battleground::BattlefieldStatusActive* battlefieldStatus, Battleground* bg, Player* player, uint32 ticketId, uint32 joinTime, BattlegroundQueueTypeId queueId);
        void BuildBattlegroundStatusQueued(WorldPackets::Battleground::BattlefieldStatusQueued* battlefieldStatus, Player* player, uint32 ticketId, uint32 joinTime, BattlegroundQueueTypeId queueId, uint32 avgWaitTime, bool asGroup);
        void BuildBattlegroundStatusFailed(WorldPackets::Battleground::BattlefieldStatusFailed* battlefieldStatus, BattlegroundQueueTypeId queueId, Player* pPlayer, uint32 ticketId, GroupJoinBattlegroundResult result, ObjectGuid const* errorGuid = nullptr);

        /* Battlegrounds */
        Battleground* GetBattleground(uint32 InstanceID, BattlegroundTypeId bgTypeId);
        Battleground* CreateNewBattleground(BattlegroundQueueTypeId queueId, BattlegroundBracketId bracketId);

        void AddBattleground(Battleground* bg);
        void AddToBGFreeSlotQueue(Battleground* bg);
        void RemoveFromBGFreeSlotQueue(uint32 mapId, uint32 instanceId);
        BGFreeSlotQueueContainer& GetBGFreeSlotQueueStore(uint32 mapId);

        void LoadBattlegroundTemplates();
        void DeleteAllBattlegrounds();

        void SendToBattleground(Player* player, uint32 InstanceID, BattlegroundTypeId bgTypeId);

        /* Battleground queues */
        static bool IsValidQueueId(BattlegroundQueueTypeId bgQueueTypeId);
        BattlegroundQueue& GetBattlegroundQueue(BattlegroundQueueTypeId bgQueueTypeId) { return m_BattlegroundQueues.emplace(bgQueueTypeId, bgQueueTypeId).first->second; }
        void ScheduleQueueUpdate(uint32 arenaMatchmakerRating, BattlegroundQueueTypeId bgQueueTypeId, BattlegroundBracketId bracket_id);
        uint32 GetPrematureFinishTime() const;

        void ToggleArenaTesting();
        void ToggleTesting();

        bool isArenaTesting() const { return m_ArenaTesting; }
        bool isTesting() const { return m_Testing; }

        static bool IsRandomBattleground(uint32 battlemasterListId);
        static BattlegroundQueueTypeId BGQueueTypeId(uint16 battlemasterListId, BattlegroundQueueIdType type, bool rated, uint8 teamSize);

        static HolidayIds BGTypeToWeekendHolidayId(BattlegroundTypeId bgTypeId);
        static BattlegroundTypeId WeekendHolidayIdToBGType(HolidayIds holiday);
        static bool IsBGWeekend(BattlegroundTypeId bgTypeId);

        uint32 GetMaxRatingDifference() const;
        uint32 GetRatingDiscardTimer()  const;
        void LoadBattleMastersEntry();
        void CheckBattleMasters();
        BattlegroundTypeId GetBattleMasterBG(uint32 entry) const
        {
            BattleMastersMap::const_iterator itr = mBattleMastersMap.find(entry);
            if (itr != mBattleMastersMap.end())
                return itr->second;
            return BATTLEGROUND_TYPE_NONE;
        }

        BattlegroundTemplate const* GetBattlegroundTemplateByTypeId(BattlegroundTypeId id)
        {
            BattlegroundTemplateMap::const_iterator itr = _battlegroundTemplates.find(id);
            if (itr != _battlegroundTemplates.end())
                return &itr->second;
            return nullptr;
        }

    private:
        uint32 CreateClientVisibleInstanceId(BattlegroundTypeId bgTypeId, BattlegroundBracketId bracket_id);
        static bool IsArenaType(BattlegroundTypeId bgTypeId);
        BattlegroundTypeId GetRandomBG(BattlegroundTypeId id);

        typedef std::map<BattlegroundTypeId, BattlegroundData> BattlegroundDataContainer;
        BattlegroundDataContainer bgDataStore;

        std::map<BattlegroundQueueTypeId, BattlegroundQueue> m_BattlegroundQueues;
        std::map<uint32 /*mapId*/, BGFreeSlotQueueContainer> m_BGFreeSlotQueue;

        struct ScheduledQueueUpdate
        {
            uint32 ArenaMatchmakerRating;
            BattlegroundQueueTypeId QueueId;
            BattlegroundBracketId BracketId;

            bool operator==(ScheduledQueueUpdate const& right) const = default;
        };

        std::vector<ScheduledQueueUpdate> m_QueueUpdateScheduler;
        uint32 m_NextRatedArenaUpdate;
        uint32 m_UpdateTimer;
        bool   m_ArenaTesting;
        bool   m_Testing;
        BattleMastersMap mBattleMastersMap;

        BattlegroundTemplate const* GetBattlegroundTemplateByMapId(uint32 mapId)
        {
            BattlegroundMapTemplateContainer::const_iterator itr = _battlegroundMapTemplates.find(mapId);
            if (itr != _battlegroundMapTemplates.end())
                return itr->second;
            return nullptr;
        }

        typedef std::map<BattlegroundTypeId, BattlegroundTemplate> BattlegroundTemplateMap;
        typedef std::map<uint32 /*mapId*/, BattlegroundTemplate*> BattlegroundMapTemplateContainer;
        BattlegroundTemplateMap _battlegroundTemplates;
        BattlegroundMapTemplateContainer _battlegroundMapTemplates;
};

#define sBattlegroundMgr BattlegroundMgr::instance()

#endif // __BATTLEGROUNDMGR_H
