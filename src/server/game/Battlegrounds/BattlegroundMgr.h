/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __BATTLEGROUNDMGR_H
#define __BATTLEGROUNDMGR_H

#include "Common.h"
#include "DBCEnums.h"
#include "BattlegroundMap.h"
#include "BattlegroundQueue.h"
#include "BattlegroundTemplate.h"

typedef std::map<uint32, Battleground*> BattlegroundContainer;
typedef std::set<uint32> BattlegroundClientIdsContainer;
typedef std::unordered_map<uint32, BattlegroundTypeId> BattleMastersMap;

#define WS_CURRENCY_RESET_TIME 20001                    // Custom worldstate

struct BattlegroundData
{
    BattlegroundContainer m_Battlegrounds;
    BattlegroundClientIdsContainer m_ClientBattlegroundIds[MAX_BATTLEGROUND_BRACKETS];
    BGFreeSlotQueueContainer BGFreeSlotQueue;
};

struct BattlegroundTemplate
{
    BattlegroundTypeId Id;
    uint16 MinPlayersPerTeam;
    uint16 MaxPlayersPerTeam;
    uint8 MinLevel;
    uint8 MaxLevel;
    Position StartLocation[BG_TEAMS_COUNT];
    float MaxStartDistSq;
    uint8 Weight;
    uint32 ScriptId;
    BattlemasterListEntry const* BattlemasterEntry;

    bool IsArena() const { return BattlemasterEntry->InstanceType == MAP_ARENA; }
};

class Battleground
{
    public:
        uint32 MapId;
};

class BattlegroundMgr
{
    private:

    friend class MapManager;
    friend class MapInstanced;

        BattlegroundMgr();
        ~BattlegroundMgr();

    public:
        static BattlegroundMgr* instance()
        {
            static BattlegroundMgr instance;
            return &instance;
        }

        void Update(uint32 diff);

        /* Packet Building */
        void BuildPlayerJoinedBattlegroundPacket(WorldPacket* data, ObjectGuid guid);
        void BuildPlayerLeftBattlegroundPacket(WorldPacket* data, ObjectGuid guid);
        void BuildBattlegroundListPacket(WorldPacket* data, ObjectGuid guid, Player* player, BattlegroundTypeId bgTypeId);
        void BuildStatusFailedPacket(WorldPacket* data, Battleground* bg, Player* pPlayer, uint8 QueueSlot, GroupJoinBattlegroundResult result);
        void BuildBattlegroundStatusPacket(WorldPacket* data, Battleground* bg, Player* player, uint8 queueSlot, uint8 statusId, uint32 time1, uint32 time2, uint8 arenaType);
        void BuildPvpLogDataPacket(WorldPacket *data, Battleground *bg);
        void SendAreaSpiritHealerQueryOpcode(Player* player, Battleground* bg, ObjectGuid guid);

        /* Battlegrounds */
        BattlegroundMap* GetBattlegroundThroughClientInstance(uint32 instanceId, BattlegroundTypeId bgTypeId);
        BattlegroundMap* GetBattleground(uint32 instanceId, BattlegroundTypeId bgTypeId); //there must be uint32 because MAX_BATTLEGROUND_TYPE_ID means unknown
        BattlegroundMap* GetBattleground(BattlegroundTypeId bgTypeId);
        BattlegroundMap* CreateNewBattleground(BattlegroundTypeId bgTypeId, PvPDifficultyEntry const* bracketEntry, uint8 arenaType, bool isRated);

        void AddBattleground(Battleground* bg);
        void RemoveBattleground(BattlegroundTypeId bgTypeId, uint32 instanceId);
        void AddBattleground(uint32 InstanceID, BattlegroundTypeId bgTypeId, Battleground* BG) { m_Battlegrounds[bgTypeId][InstanceID] = BG; };
        void RemoveBattleground(uint32 instanceID, BattlegroundTypeId bgTypeId) { m_Battlegrounds[bgTypeId].erase(instanceID); }
        BGFreeSlotQueueContainer& GetBGFreeSlotQueueStore(BattlegroundTypeId bgTypeId);

        void LoadBattlegroundTemplates();
        void DeleteAllBattlegrounds();

        void SendToBattleground(Player* player, uint32 InstanceID, BattlegroundTypeId bgTypeId);

        /* Battleground queues */
        BattlegroundQueue& GetBattlegroundQueue(BattlegroundQueueTypeId bgQueueTypeId) { return m_BattlegroundQueues[bgQueueTypeId]; }
        void ScheduleQueueUpdate(uint32 arenaMatchmakerRating, uint8 arenaType, BattlegroundQueueTypeId bgQueueTypeId, BattlegroundTypeId bgTypeId, BattlegroundBracketId bracket_id);
        uint32 GetPrematureFinishTime() const;

        void ToggleArenaTesting();
        void ToggleTesting();

        void SetHolidayWeekends(uint32 mask);

        bool isArenaTesting() const { return m_ArenaTesting; }
        bool isTesting() const { return m_Testing; }

        static BattlegroundQueueTypeId BGQueueTypeId(BattlegroundTypeId bgTypeId, uint8 arenaType);
        static BattlegroundTypeId BGTemplateId(BattlegroundQueueTypeId bgQueueTypeId);
        static uint8 BGArenaType(BattlegroundQueueTypeId bgQueueTypeId);

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

    private:
        bool CreateBattleground(BattlegroundTemplate const* bgTemplate);
        uint32 CreateClientVisibleInstanceId(BattlegroundTypeId bgTypeId, BattlegroundBracketId bracket_id);
        static bool IsArenaType(BattlegroundTypeId bgTypeId);
        BattlegroundTypeId GetRandomBG(BattlegroundTypeId id);

        typedef std::map<BattlegroundTypeId, BattlegroundData> BattlegroundDataContainer;
        BattlegroundDataContainer bgDataStore;

        BattlegroundQueue m_BattlegroundQueues[MAX_BATTLEGROUND_QUEUE_TYPES];

        BattlegroundSet m_Battlegrounds[MAX_BATTLEGROUND_TYPE_ID];

        std::vector<uint64> m_QueueUpdateScheduler;
        uint32 m_NextRatedArenaUpdate;
        bool   m_ArenaTesting;
        bool   m_Testing;
        BattleMastersMap mBattleMastersMap;

        BattlegroundTemplate const* GetBattlegroundTemplateByTypeId(BattlegroundTypeId id)
        {
            BattlegroundTemplateMap::const_iterator itr = _battlegroundTemplates.find(id);
            if (itr != _battlegroundTemplates.end())
                return &itr->second;
            return nullptr;
        }

        BattlegroundTemplate const* GetBattlegroundTemplateByMapId(uint32 mapId)
        {
            BattlegroundMapTemplateContainer::const_iterator itr = _battlegroundMapTemplates.find(mapId);
            if (itr != _battlegroundMapTemplates.end())
                return itr->second;
            return nullptr;
        }

        uint32 FillSelectionWeights(BattlegroundTemplate const* bgTemplate)
        {
            BattlegroundSelectionWeightMap &const selectionWeights = bgTemplate->Id== BATTLEGROUND_AA ? m_ArenaSelectionWeights : m_BGSelectionWeights;
            BattlegroundSelectionWeightMap::const_iterator itr;

            // Get sum of weights
        typedef std::map<BattlegroundTypeId, uint8 /*weight*/> BattlegroundSelectionWeightMap;

        typedef std::map<BattlegroundTypeId, BattlegroundTemplate> BattlegroundTemplateMap;
        typedef std::map<uint32 /*mapId*/, BattlegroundTemplate*> BattlegroundMapTemplateContainer;
        BattlegroundTemplateMap _battlegroundTemplates;
        BattlegroundMapTemplateContainer _battlegroundMapTemplates;
            uint32 sumWeight = 0;
            for (itr = selectionWeights.begin(); itr != selectionWeights.end(); ++itr)
                sumWeight += itr->second;

            // Reset iterator to begin
            itr = selectionWeights.begin();

            // Select a random weight
            uint32 selectedWeight = urand(0, sumWeight-1);

            // Get the right array accessor for it
            uint32 curWeight = 0;
            uint8 index = 0;    // Index used to access BattlegroundTemplate->BattleMasterListEntry->maps[8] 
            for (itr = selectionWeights.begin(); itr != selectionWeights.end(); ++itr)
            {
                curWeight += itr->second;
                ++index;
                if (selectedWeight < curWeight)
                    break;
            }

            return bgTemplate->BattlemasterEntry->mapid[index];
        }

        uint32 GetMapIdForBGType(BattlegroundTypeId type)
        {
            BattlegroundTemplate const* bgTemplate = GetBattlegroundTemplate(type);
            if (!bgTemplate)
            {
                sLog->outError("BattlegroundMgr::GetMapIdForBGType: No valid BattlegroundTemplate for Type=%u", type);
                return -1;
            }

            if (type != BATTLEGROUND_AA && type != BATTLEGROUND_RB)
                return bgTemplate->BattlemasterEntry->mapid[0];

            return FillSelectionWeights(bgTemplate);
        }

    private:
        BattlegroundTemplateMap _battlegroundTemplates;
        BattlegroundMaps _battlegrounds[MAX_BATTLEGROUND_TYPE_ID];
};

#define sBattlegroundMgr BattlegroundMgr::instance()

#endif // __BATTLEGROUNDMGR_H
