/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

enum LfgGroupEnum
{
    LFG_GROUP_MAX_KICKS                           = 3,
    LFG_GROUP_KICK_VOTES_NEEDED                   = 3
};

/**
    Stores all lfg data needed about a group.
*/
class LfgGroupData
{
    public:
        LfgGroupData();
        ~LfgGroupData();

        // General
        void SetState(LfgState state);
        void RestoreState();
        // Dungeon
        void SetDungeon(uint32 dungeon);
        // VoteKick
        void SetVotesNeeded(uint8 votes);
        void DecreaseKicksLeft();

        // General
        LfgState GetState() const;
        // Dungeon
        uint32 GetDungeon(bool asId = true) const;
        // VoteKick
        uint8 GetVotesNeeded() const;
        uint8 GetKicksLeft() const;

    private:
        // General
        LfgState m_State;                                  ///< State if group in LFG
        LfgState m_OldState;                               ///< Old State
        // Dungeon
        uint32 m_Dungeon;                                  ///< Dungeon entry
        // Vote Kick
        uint8 m_VotesNeeded;                               ///< Votes need to kick success
        uint8 m_KicksLeft;                                 ///< Number of kicks left
};

#endif
