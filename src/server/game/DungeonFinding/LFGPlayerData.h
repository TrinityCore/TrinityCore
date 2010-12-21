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

#ifndef _LFGPLAYERDATA_H
#define _LFGPLAYERDATA_H

#include "Common.h"
#include "LFG.h"

/**
    Stores all lfg data needed about the player.
*/
class LfgPlayerData
{
    public:
        LfgPlayerData();
        ~LfgPlayerData();

        // General
        void SetState(LfgState state);
        void ClearState();
        void SetLockedDungeons(const LfgLockMap& lock);
        // Queue
        void SetRoles(uint8 roles);
        void SetComment(const std::string& comment);
        void SetSelectedDungeons(const LfgDungeonSet& dungeons);
        void ClearSelectedDungeons();

        // General
        LfgState GetState() const;
        const LfgLockMap& GetLockedDungeons() const;
        // Queue
        uint8 GetRoles() const;
        const std::string& GetComment() const;
        const LfgDungeonSet& GetSelectedDungeons() const;
        
    private:
        // General
        LfgState m_State;                                  ///< State if group in LFG
        LfgState m_OldState;                               ///< Old State
        // Player
        LfgLockMap m_LockedDungeons;                       ///< Dungeons player can't do and reason
        // Queue
        uint8 m_Roles;                                     ///< Roles the player selected when joined LFG
        std::string m_Comment;                             ///< Player comment used when joined LFG
        LfgDungeonSet m_SelectedDungeons;                  ///< Selected Dungeons when joined LFG
};

#endif
