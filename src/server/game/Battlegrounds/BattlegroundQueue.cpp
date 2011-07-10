/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "BattlegroundQueue.h"
#include "BattlegroundMgr.h"
#include "DBCStores.h"
#include "Log.h"

/*
============================================================================================
Battleground Queue System
============================================================================================
*/

//namespace Battleground
//{
/**********************************************************************************************//**
 * \fn  void BattlegroundQueue::Insert( BattlegroundQueueElement* element )
 *
 * \brief   Inserts a new element into the queue.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param [in,out]  element The representation of a (collection of) Player(s).
 **************************************************************************************************/

void BattlegroundQueue::Insert( BattlegroundQueueElement* element )
{
    ASSERT(Base::insert(element).second == true && 
        "Element was already inserted to this BattlegroundQueue." && OutDebug());

    if (_hash.GetArenaType() >= ARENA_TYPE_2v2)
    {
        BattlegroundQueueElement* front = *begin();
        //!  If we're the only ones in queue, do not schedule anything
        if (front == element)
            return;

        //! (Author: Unknown)
        //! found out the minimum and maximum ratings the newly added team should battle against
        //! arenaRating is the rating of the latest joined team, or 0
        //! 0 is on (automatic update call) and we must set it to team's with longest wait time
        uint32 myRating = element->ArenaMMR ? element->ArenaMMR : front->ArenaMMR;

        uint32 minRating = (myRating <= sBattlegroundMgr->GetMaxRatingDifference()) ? 0 : myRating - sBattlegroundMgr->GetMaxRatingDifference();
        uint32 maxRating = myRating + sBattlegroundMgr->GetMaxRatingDifference();

        //! Find an immediate match based on matchmaker rating
        for (Base::iterator itr = begin(); itr != end(); ++itr)
        {   
            BattlegroundQueueElement* value = (*itr);
            //! Check rating boundaries
            if (value->ArenaMMR >= minRating && value->ArenaMMR <= maxRating)
            {
                //! TODO: Invite them both to the actual battleground
                // 
                // 
                //! Erase both elements from the queue since they both found their match.
                erase(value);
                erase(element);
                return;
            }
        }

        //! At this point no match is found based on matchmaker rating,
        //! so we schedule a delayed invite while both teams can still find their
        //! match trough MMR.
        //! Let's not re-schedule invites with teams that already have a match scheduled
        Base::const_iterator itr = begin();
        while ((*itr)->InviteScheduled)
            ++itr;        
         
        _events.AddEvent(new ArenaInviteEvent(element, *itr),
                        _events.CalculateTime(sBattlegroundMgr->GetRatingDiscardTimer()));

        //! Prevent these teams from being re-scheduled for a different match
        //! whenever a new team queues.
        element->InviteScheduled = true;
        (*itr)->InviteScheduled = true;

    }
    else //! Battleground
    {
        element->Data.Faction == ALLIANCE ? 
        _variables._ahCount.AllianceCount += element->Players.size() : 
        _variables._ahCount.HordeCount += element->Players.size();

        if (_variables._ahCount.AllianceCount >= _bgTemplate->MinPlayersPerTeam &&
            _variables._ahCount.HordeCount >= _bgTemplate->MaxPlayersPerTeam)
        {
            //! Invite every player to the battleground
        }
    }
}

void BattlegroundQueue::Erase( BattlegroundQueueElement* element )
{
    ASSERT(Base::erase(element) == size_t(1) &&
        "Element was already removed from this BattlegroundQueue." && OutDebug());
}

/**********************************************************************************************//**
 * \fn  char const* BattlegroundQueue::OutDebug()
 *
 * \brief   Gets diagnostic debug information for this object. Called in various ASSERT calls.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \return  A c-string (char*) with diagnostical information.
 **************************************************************************************************/

char const* BattlegroundQueue::OutDebug()
{
    std::stringstream ss;
    ss << std::endl;
    ss << "BattlegroundQueue Index: " << uint32(_hash) << std::endl;
    ss << "Rated? : " << _hash.IsRated() << std::endl;
    ss << "Arena Type: " << _hash.GetArenaType() << std::endl;
    ss << "PVP DifficultyEntry Id: " << _hash.GetPvPDifficultyId();
    return ss.str().c_str();
}

/**********************************************************************************************//**
 * \fn  void BattlegroundQueue::Update( uint32 const& diff )
 *
 * \brief   Updates the EventProcessor with given diff and executes scheduled events if necessary.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param   diff    Time difference in ms since last call to this function.
 **************************************************************************************************/

void BattlegroundQueue::Update( uint32 const& diff )
{
    _events.Update(diff);
}

BattlegroundQueue::~BattlegroundQueue()
{
    for (iterator itr = begin(); itr != end();)
    {
        delete (*itr);
        erase(itr++);
    }
}

BattlegroundQueue::BattlegroundQueue( BattlegroundQueueIndex hash, PvPDifficultyEntry const* entry ) 
: _hash(hash), _pvpDifficultyEntry(entry)
{
    //! Complicated relations between DBCs and SQL tables.
    for (uint32 i = 0; i < sBattlemasterListStore.GetNumRows(); ++i)
        if (BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(i)) 
            if (bl->mapid[0] == entry->mapId)
                _bgTemplate = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(bl->id));

    memset(&_variables, 0, sizeof(_variables));
}


/**********************************************************************************************//**
 * \fn  void BattlegroundQueueMgr::Initialize()
 *
 * \brief   Initializes this object. Allocate a BattlegroundQueue object for every possible queue.
 * 			There will be 2 * 3 * 108 = 648 seperate queues.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 **************************************************************************************************/

void BattlegroundQueueMgr::Initialize()
{
    for (uint8 rated = 0; rated <= 1; ++rated)
    {
        for (uint8 arenaType = ARENA_TYPE_2v2; arenaType <= ARENA_TYPE_5v5; ++arenaType)
        {
            if (arenaType == 4) // There's no such thing as ARENA_TYPE_4V4
                continue;

            for (uint8 pvpDifficultyEntry = 1; pvpDifficultyEntry <= MAX_PVPDIFFICULTY_ENTRY; ++pvpDifficultyEntry)
            {
                BattlegroundQueueIndex index(rated, arenaType, pvpDifficultyEntry);
                Queues[index] = new BattlegroundQueue(index, sPvPDifficultyStore.LookupEntry(pvpDifficultyEntry));
            }
        }
    }
}

/**********************************************************************************************//**
 * \fn  void BattlegroundQueueMgr::Update( uint32 const& diff )
 *
 * \brief   Updates the child queues. Called from World::Update thread.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param   diff    The time difference in ms since the last call to this function.
 **************************************************************************************************/

void BattlegroundQueueMgr::Update( uint32 const& diff )
{
    QueueMap::const_iterator itr;
    for (itr = Queues.begin(); itr != Queues.end(); ++itr)
        itr->second->Update(diff);
}

/**********************************************************************************************//**
 * \fn  inline void BattlegroundQueueMgr::Insert( BattlegroundQueueElement* element, uint8 rated,
 *      ArenaType arenaType, uint8 difficultyEntryId )
 *
 * \brief   Inserts a new element to the queue. Called from WorldSession handlers.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param [in,out]  element     If non-null, the element. Representation of a (collection of)
 * 					            Player(s)
 * \param   rated               Boolean that determines whether or not the arena match is rated.
 * 								Will always be 0 for non-arena's
 * \param   arenaType           Type of the arena. (See enum ArenaType)
 * \param   difficultyEntryId   Identifier for the difficulty entry in PvPDifficultyEntry.dbc.
 **************************************************************************************************/

inline
void BattlegroundQueueMgr::Insert( BattlegroundQueueElement* element, uint8 rated, ArenaType arenaType, uint8 difficultyEntryId )
{
    Queues[BattlegroundQueueIndex(rated, arenaType, difficultyEntryId)]->Insert(element);
}

/**********************************************************************************************//**
 * \fn  bool BattlegroundQueue::ArenaInviteEvent::Execute( uint64 , uint32 )
 *
 * \brief   Executing this event will start an arena match for the two respective teams.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param       Unused
 * \param       Unused
 *
 * \return  true if it succeeds, false if it fails.
 **************************************************************************************************/

bool BattlegroundQueue::ArenaInviteEvent::Execute( uint64 /*e_time*/, uint32 /*p_time*/ )
{
    //! TODO: Invite both arena teams to a match
}

//}  // Namespace Battleground