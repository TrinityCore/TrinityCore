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

#ifndef __BATTLEGROUNDQUEUE_H
#define __BATTLEGROUNDQUEUE_H

#include "Common.h"
#include "DBCEnums.h"
#include "BattlegroundMap.h"
#include "EventProcessor.h"

//namespace Battleground
//{
#include <deque>


#define MAX_PVPDIFFICULTY_ENTRY 108

/**********************************************************************************************//**
 * \struct  BattlegroundQueueElement
 *
 * \brief   Battleground queue element. Represents a (collection of) player(s) and relevant
 * 			battleground information. 
 *
 * \author  Machiavelli
 * \date    7/10/2011
 **************************************************************************************************/

struct BattlegroundQueueElement
{
    BattlegroundQueueElement() : InviteScheduled(false){};
    GroupQueueInfo* GroupInfo;                             // pointer to the associated groupqueueinfo

    ///< The (collection of) player(s) per LowGUID
    std::vector<uint32> Players;

    ///< Union of data specific to arena's or battlegrounds
    union
    {
    std::map<uint64, PlayerQueueInfo*> Players;             // player queue info map
        Team Faction;

        ///< The arena matchmaker rating (if applicable)
        uint32 ArenaMMR;
    } Data;

    ///< Determines if this element was already scheduled for a delayed invite.
    //< If set to true, the element can still be scheduled for a MMR-selected match 
    //< and will be ignored for delayed invites.
    bool InviteScheduled;   
};

struct BattlegroundQueueIndex
{
    public:
        BattlegroundQueueIndex(uint8 rated, uint8 arenaType, uint8 pvpDifficultyId) : _raw((rated << 16) | (arenaType << 8) | pvpDifficultyId) {}

        operator uint32() { return _raw; }

        bool IsRated() { return bool(_raw >> 16); }
        ArenaType GetArenaType() { return ArenaType(_raw >> 8); }
        uint8 GetPvPDifficultyId() { return (_raw & 255); }

    private:
        uint32 _raw;
};

class BattlegroundQueue;

class BattlegroundQueueMgr
{
    friend class ACE_Singleton<BattlegroundQueueMgr, ACE_Null_Mutex>;

    protected:
        BattlegroundQueueMgr() { Initialize(); }
        virtual ~BattlegroundQueueMgr() {}

        void Initialize();
        void Update(uint32 const& diff);
        void Insert(BattlegroundQueueElement* element, uint8 rated, ArenaType arenaType, uint8 difficultyEntryId);
        void RemovePlayer(const uint64& guid, bool decreaseInvitedCount);
        bool IsPlayerInvited(const uint64& pl_guid, const uint32 bgInstanceGuid, const uint32 removeTime);
        bool GetPlayerGroupInfoData(const uint64& guid, GroupQueueInfo* ginfo);

        typedef std::map<ObjectGuid, PlayerQueueInfo> QueuedPlayersMap;
        ///< bracketId: Id in PVPDifficultiy.dbc, has access to mapId and level restrictions
        ///< arenaType: See enum
        ///< rated: rated match or not
        typedef std::map<uint32 /*queueId*/, BattlegroundQueue*> QueueMap;

        //we need constant add to begin and constant remove / add from the end, therefore deque suits our problem well
        // Queue will never be altered
        QueueMap Queues;
};

class BattlegroundQueue : public std::set<BattlegroundQueueElement*>
{
    friend class BattlegroundQueueMgr;

    typedef std::set<BattlegroundQueueElement*> Base;

    class ArenaInviteEvent : public BasicEvent
    {
        public:
            SelectionPool(): PlayerCount(0) { };

            bool AddGroup(GroupQueueInfo *ginfo, uint32 desiredCount);

        private:
            BattlegroundQueueElement* _team1;
            BattlegroundQueueElement* _team2;
    };

    protected:
        BattlegroundQueue(BattlegroundQueueIndex hash, PvPDifficultyEntry const* entry);

        ~BattlegroundQueue();

        void Insert(BattlegroundQueueElement* element);
        void Erase(BattlegroundQueueElement* element);
        void Update(uint32 const& diff);
    private:

        bool InviteGroupToBG(GroupQueueInfo* ginfo, Battleground* bg, uint32 side);

        ///< Counter variables dependant on type (BG/Arena)
        union
                uint8 AllianceCount;
                uint8 HordeCount;
            } _ahCount;

        } _variables;

        ///< Hash index BattlegroundQueueMgr uses to access pointer to this object.
        BattlegroundQueueIndex _hash;

        ///< Entry from PvPDifficultyEntry.dbc
        PvPDifficultyEntry const* _pvpDifficultyEntry;

        ///< Entry from BattleMasterListEntry.dbc
        BattlemasterListEntry const* _battleMasterListEntry;

        ///< The battleground_template
        BattlegroundTemplate const* _bgTemplate;

        ///< Asynchronous events
        EventProcessor _events;
};

/*
    This class is used to invite player to BG again, when minute lasts from his first invitation
    it is capable to solve all possibilities
*/
class BGQueueInviteEvent : public BasicEvent
{
    public:
        BGQueueInviteEvent(ObjectGuid pl_guid, uint32 BgInstanceGUID, BattlegroundTypeId BgTypeId, uint8 arenaType, uint32 removeTime) :
          _playerGUID(pl_guid), _bgInstanceGUID(BgInstanceGUID), _bgTypeId(BgTypeId), _arenaType(arenaType), _removeTime(removeTime)
          { }
        virtual ~BGQueueInviteEvent() { }

        virtual bool Execute(uint64 e_time, uint32 p_time) override;
        virtual void Abort(uint64 e_time) override;
    private:
        uint64 m_PlayerGuid;
        uint32 _bgInstanceGUID;
        BattlegroundTypeId _bgTypeId;
        uint8  _arenaType;
        uint32 _removeTime;
};

/*
    This class is used to remove player from BG queue after 1 minute 20 seconds from first invitation
    We must store removeInvite time in case player left queue and joined and is invited again
    We must store bgQueueTypeId, because battleground can be deleted already, when player entered it
*/
class BGQueueRemoveEvent : public BasicEvent
{
    public:
        BGQueueRemoveEvent(ObjectGuid pl_guid, uint32 bgInstanceGUID, BattlegroundTypeId BgTypeId, uint8 arenaType, BattlegroundQueueTypeId bgQueueTypeId, uint32 removeTime)
            : _playerGUID(pl_guid), _bgInstanceGUID(bgInstanceGUID), _removeTime(removeTime), _bgTypeId(BgTypeId), _bgQueueTypeId(bgQueueTypeId)
        { }

        virtual ~BGQueueRemoveEvent() { }

        virtual bool Execute(uint64 e_time, uint32 p_time) override;
        virtual void Abort(uint64 e_time) override;
    private:
        uint64 m_PlayerGuid;
        uint32 _bgInstanceGUID;
        uint32 _removeTime;
        BattlegroundTypeId _bgTypeId;
        BattlegroundQueueTypeId _bgQueueTypeId;
};

//} // namespace Battleground

#endif
