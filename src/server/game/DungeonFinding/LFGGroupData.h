/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _LFGGROUPDATA_H
#define _LFGGROUPDATA_H

#include "LFG.h"

namespace lfg
{

enum LfgGroupEnum
{
    LFG_GROUP_MAX_KICKS                           = 3,
};

/**
    Stores all lfg data needed about a group.
*/
class LfgGroupData
{
    public:
        LfgGroupData();
        ~LfgGroupData();

        bool IsLfgGroup();

        // General
        void SetState(LfgState state);
        void RestoreState();
        void AddPlayer(ObjectGuid guid);
        uint8 RemovePlayer(ObjectGuid guid);
        void RemoveAllPlayers();
        void SetLeader(ObjectGuid guid);

        // Dungeon
        void SetDungeon(uint32 dungeon);

        // VoteKick
        void DecreaseKicksLeft();

        // General
        LfgState GetState() const;
        LfgState GetOldState() const;
        GuidSet const& GetPlayers() const;
        uint8 GetPlayerCount() const;
        ObjectGuid GetLeader() const;

        // Dungeon
        uint32 GetDungeon(bool asId = true) const;

        // VoteKick
        uint8 GetKicksLeft() const;

        void SetVoteKick(bool active);
        bool IsVoteKickActive() const;

    private:
        // General
        LfgState m_State;                                  ///< State if group in LFG
        LfgState m_OldState;                               ///< Old State
        ObjectGuid m_Leader;                               ///< Leader GUID
        GuidSet m_Players;                                 ///< Players in group
        // Dungeon
        uint32 m_Dungeon;                                  ///< Dungeon entry
        // Vote Kick
        uint8 m_KicksLeft;                                 ///< Number of kicks left
        bool m_VoteKickActive;
};

} // namespace lfg

#endif
