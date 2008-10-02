/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __BATTLEGROUNDMGR_H
#define __BATTLEGROUNDMGR_H

#include "BattleGround.h"
#include "Policies/Singleton.h"

class BattleGround;

//TODO it is not possible to have this structure, because we should have BattlegroundSet for each queue
//so i propose to change this type to array 1..MAX_BATTLEGROUND_TYPES of sets or maps..
typedef std::map<uint32, BattleGround*> BattleGroundSet;
//typedef std::map<uint32, BattleGroundQueue*> BattleGroundQueueSet;
typedef std::deque<BattleGround*> BGFreeSlotQueueType;

#define MAX_BATTLEGROUND_QUEUES 7                           // for level ranges 10-19, 20-29, 30-39, 40-49, 50-59, 60-69, 70+

#define MAX_BATTLEGROUND_TYPES 9                            // each BG type will be in array

struct PlayerQueueInfo
{
    uint32  InviteTime;                                     // first invite time
    uint32  LastInviteTime;                                 // last invite time
    uint32  IsInvitedToBGInstanceGUID;                      // was invited to certain BG
    uint32  LastOnlineTime;                                 // for tracking and removing offline players from queue after 5 minutes
    uint32  Team;                                           // Player team (ALLIANCE/HORDE)
    bool IsRated;
    bool AsGroup;                                           // uint32 GroupId;
    uint8 ArenaType;
};

struct PlayersCount
{
    uint32 Alliance;
    uint32 Horde;
};

template<class _Kty, class _Ty> class bgqueue: public std::map<_Kty, _Ty>
{
    public:
        uint32 Alliance;
        uint32 Horde;
        //bool   Ready; // not used now
        //uint32 AverageTime; //not already implemented (it should be average time in queue for last 10 players)
};

class BattleGroundQueue
{
    public:
        BattleGroundQueue();
        ~BattleGroundQueue();
/*
        uint32 GetType();
        void SetType(uint32 type);*/

        void Update(uint32 bgTypeId, uint32 queue_id);

        void AddPlayer(Player *plr, uint32 bgTypeId);
        void RemovePlayer(uint64 guid, bool decreaseInvitedCount);

        typedef bgqueue<uint64, PlayerQueueInfo> QueuedPlayersMap;
        QueuedPlayersMap m_QueuedPlayers[MAX_BATTLEGROUND_QUEUES];
        typedef std::list<uint64> PlayerGuidsSortedByTimeQueue;
        PlayerGuidsSortedByTimeQueue m_PlayersSortedByWaitTime[MAX_BATTLEGROUND_QUEUES];
};

/*
    This class is used to invite player to BG again, when minute lasts from his first invitation
    it is capable to solve all possibilities
*/
class BGQueueInviteEvent : public BasicEvent
{
    public:
        BGQueueInviteEvent(uint64 pl_guid, uint32 BgInstanceGUID) : m_PlayerGuid(pl_guid), m_BgInstanceGUID(BgInstanceGUID) {};
        virtual ~BGQueueInviteEvent() {};

        virtual bool Execute(uint64 e_time, uint32 p_time);
        virtual void Abort(uint64 e_time);
    private:
        uint64 m_PlayerGuid;
        uint32 m_BgInstanceGUID;

};

/*
    This class is used to remove player from BG queue after 2 minutes from first invitation
*/
class BGQueueRemoveEvent : public BasicEvent
{
    public:
        BGQueueRemoveEvent(uint64 pl_guid, uint32 bgInstanceGUID, uint32 playersTeam) : m_PlayerGuid(pl_guid), m_BgInstanceGUID(bgInstanceGUID), m_PlayersTeam(playersTeam) {};
        virtual ~BGQueueRemoveEvent() {};

        virtual bool Execute(uint64 e_time, uint32 p_time);
        virtual void Abort(uint64 e_time);
    private:
        uint64 m_PlayerGuid;
        uint32 m_BgInstanceGUID;
        uint32 m_PlayersTeam;
};


class BattleGroundMgr
{
    public:
        /* Construction */
        BattleGroundMgr();
        ~BattleGroundMgr();
        void Update(time_t diff);

        /* Packet Building */
        void BuildPlayerJoinedBattleGroundPacket(WorldPacket *data, Player *plr);
        void BuildPlayerLeftBattleGroundPacket(WorldPacket *data, Player *plr);
        void BuildBattleGroundListPacket(WorldPacket *data, uint64 guid, Player *plr, uint32 bgTypeId);
        void BuildGroupJoinedBattlegroundPacket(WorldPacket *data, uint32 bgTypeId);
        void BuildUpdateWorldStatePacket(WorldPacket *data, uint32 field, uint32 value);
        void BuildPvpLogDataPacket(WorldPacket *data, BattleGround *bg);
        void BuildBattleGroundStatusPacket(WorldPacket *data, BattleGround *bg, uint32 team, uint8 QueueSlot, uint8 StatusID, uint32 Time1, uint32 Time2);
        void BuildPlaySoundPacket(WorldPacket *data, uint32 soundid);

        /* Player invitation */
        // called from Queue update, or from Addplayer to queue
        void InvitePlayer(Player* plr, uint32 bgInstanceGUID);

        /* Battlegrounds */
        BattleGroundSet::iterator GetBattleGroundsBegin() { return m_BattleGrounds.begin(); };
        BattleGroundSet::iterator GetBattleGroundsEnd() { return m_BattleGrounds.end(); };

        BattleGround* GetBattleGround(uint8 ID)
        {
            BattleGroundSet::iterator i = m_BattleGrounds.find(ID);
            if(i != m_BattleGrounds.end())
                return i->second;
            else
                return NULL;
        };

        uint32 CreateBattleGround(uint32 bgTypeId, uint32 MinPlayersPerTeam, uint32 MaxPlayersPerTeam, uint32 LevelMin, uint32 LevelMax, char* BattleGroundName, uint32 MapID, float Team1StartLocX, float Team1StartLocY, float Team1StartLocZ, float Team1StartLocO, float Team2StartLocX, float Team2StartLocY, float Team2StartLocZ, float Team2StartLocO);

        inline void AddBattleGround(uint32 ID, BattleGround* BG) { m_BattleGrounds[ID] = BG; };

        void CreateInitialBattleGrounds();

        void SendToBattleGround(Player *pl, uint32 bgTypeId);

        /* Battleground queues */
        //these queues are instantiated when creating BattlegroundMrg
        BattleGroundQueue m_BattleGroundQueues[MAX_BATTLEGROUND_TYPES]; // public, because we need to access them in BG handler code

        BGFreeSlotQueueType BGFreeSlotQueue[MAX_BATTLEGROUND_TYPES];

        void SendAreaSpiritHealerQueryOpcode(Player *pl, BattleGround *bg, uint64 guid);

    private:

        /* Battlegrounds */
        BattleGroundSet m_BattleGrounds;
};

#define sBattleGroundMgr MaNGOS::Singleton<BattleGroundMgr>::Instance()
#endif
