/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _LFGQUEUE_H
#define _LFGQUEUE_H

#include "LFG.h"

enum LfgCompatibility
{
    LFG_COMPATIBILITY_PENDING,
    LFG_INCOMPATIBLES_WRONG_GROUP_SIZE,
    LFG_INCOMPATIBLES_TOO_MUCH_PLAYERS,
    LFG_INCOMPATIBLES_MULTIPLE_LFG_GROUPS,
    LFG_INCOMPATIBLES_HAS_IGNORES,
    LFG_INCOMPATIBLES_NO_ROLES,
    LFG_INCOMPATIBLES_NO_DUNGEONS,
    LFG_COMPATIBLES_WITH_LESS_PLAYERS,                     // Values under this = not compatible (do not modify order)
    LFG_COMPATIBLES_BAD_STATES,
    LFG_COMPATIBLES_MATCH                                  // Must be the last one
};

/// Stores player or group queue info
struct LfgQueueData
{
    LfgQueueData(): joinTime(time_t(time(NULL))), tanks(LFG_TANKS_NEEDED),
        healers(LFG_HEALERS_NEEDED), dps(LFG_DPS_NEEDED)
        { }

    LfgQueueData(time_t _joinTime, const LfgDungeonSet &_dungeons, const LfgRolesMap &_roles)
    {
        joinTime = _joinTime;
        dungeons = _dungeons;
        roles = _roles;
        tanks = LFG_TANKS_NEEDED;
        healers = LFG_HEALERS_NEEDED;
        dps = LFG_DPS_NEEDED;

        for (LfgRolesMap::const_iterator it = roles.begin(); it != roles.end(); ++it)
        {
            uint8 role = it->second;
            if (role & PLAYER_ROLE_TANK)
                --tanks;
            else if (role & PLAYER_ROLE_HEALER)
                --healers;
            else
                --dps;
        }
    }

    time_t joinTime;                                       ///< Player queue join time (to calculate wait times)
    uint8 tanks;                                           ///< Tanks needed
    uint8 healers;                                         ///< Healers needed
    uint8 dps;                                             ///< Dps needed
    LfgDungeonSet dungeons;                                ///< Selected Player/Group Dungeon/s
    LfgRolesMap roles;                                     ///< Selected Player Role/s
};

struct LfgWaitTime
{
    LfgWaitTime(): time(-1), number(0) {}
    int32 time;                                            ///< Wait time
    uint32 number;                                         ///< Number of people used to get that wait time
};

typedef std::map<uint32, LfgWaitTime> LfgWaitTimesMap;
typedef std::map<std::string, LfgCompatibility> LfgCompatibleMap;
typedef std::map<uint64, LfgQueueData> LfgQueueDataMap;

/**
    Stores all data related to queue
*/
class LfgQueue
{
    public:

        // Add/Remove from queue
        void AddToQueue(uint64 guid);
        void RemoveFromQueue(uint64 guid);
        void AddQueueData(uint64 guid, time_t joinTime, const LfgDungeonSet &dungeons, const LfgRolesMap &rolesMap);
        void RemoveQueueData(uint64 guid);

        // Update Timers (when proposal success)
        void UpdateWaitTimeAvg(int32 waitTime, uint32 dungeonId);
        void UpdateWaitTimeTank(int32 waitTime, uint32 dungeonId);
        void UpdateWaitTimeHealer(int32 waitTime, uint32 dungeonId);
        void UpdateWaitTimeDps(int32 waitTime, uint32 dungeonId);

        // Update Queue timers
        void UpdateQueueTimers(time_t currTime);
        time_t GetJoinTime(uint64 guid);

        // Find new group
        uint8 FindGroups();

        // Just for debugging purposes
        LfgCompatibleMap const& GetCompatibleMap();
        std::string DumpQueueInfo() const;
        std::string DumpCompatibleInfo() const;
    private:
        void AddToNewQueue(uint64 guid);
        void AddToCurrentQueue(uint64 guid);
        void RemoveFromNewQueue(uint64 guid);
        void RemoveFromCurrentQueue(uint64 guid);

        void SetCompatibles(std::string const& key, LfgCompatibility compatibles);
        LfgCompatibility GetCompatibles(std::string const& key);
        void RemoveFromCompatibles(uint64 guid);

        LfgCompatibility FindNewGroups(LfgGuidList& check, LfgGuidList& all);
        LfgCompatibility CheckCompatibility(LfgGuidList check);

        // Queue
        LfgQueueDataMap m_QueueDataMap;                    ///< Queued groups
        LfgCompatibleMap m_CompatibleMap;                  ///< Compatible dungeons

        LfgWaitTimesMap m_waitTimesAvg;                    ///< Average wait time to find a group queuing as multiple roles
        LfgWaitTimesMap m_waitTimesTank;                   ///< Average wait time to find a group queuing as tank
        LfgWaitTimesMap m_waitTimesHealer;                 ///< Average wait time to find a group queuing as healer
        LfgWaitTimesMap m_waitTimesDps;                    ///< Average wait time to find a group queuing as dps
        LfgGuidList m_currentQueue;                        ///< Ordered list. Used to find groups
        LfgGuidList m_newToQueue;                          ///< New groups to add to queue
};

#endif
