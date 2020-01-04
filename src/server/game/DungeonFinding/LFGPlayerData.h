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

#ifndef _LFGPLAYERDATA_H
#define _LFGPLAYERDATA_H

#include "LFG.h"
#include "LFGPacketsCommon.h"

namespace lfg
{

/**
    Stores all lfg data needed about the player.
*/
class TC_GAME_API LfgPlayerData
{
    public:
        LfgPlayerData();
        ~LfgPlayerData();

        // General
        void SetTicket(WorldPackets::LFG::RideTicket const& ticket);
        void SetState(LfgState state);
        void RestoreState();
        void SetTeam(uint8 team);
        void SetGroup(ObjectGuid group);

        // Queue
        void SetRoles(uint8 roles);
        void SetComment(std::string const& comment);
        void SetSelectedDungeons(const LfgDungeonSet& dungeons);

        // General
        WorldPackets::LFG::RideTicket const& GetTicket() const;
        LfgState GetState() const;
        LfgState GetOldState() const;
        uint8 GetTeam() const;
        ObjectGuid GetGroup() const;

        // Queue
        uint8 GetRoles() const;
        std::string const& GetComment() const;
        LfgDungeonSet const& GetSelectedDungeons() const;

        // Shortage
        void SetEnligibleForShortageRewards(bool apply);
        bool IsEnligibleForShortageRewards() const;

    private:
        // General
        WorldPackets::LFG::RideTicket m_Ticket;            ///< Join ticket
        LfgState m_State;                                  ///< State if group in LFG
        LfgState m_OldState;                               ///< Old State - Used to restore state after failed Rolecheck/Proposal
        // Player
        uint8 m_Team;                                      ///< Player team - determines the queue to join
        ObjectGuid m_Group;                                ///< Original group of player when joined LFG

        // Queue
        uint8 m_Roles;                                     ///< Roles the player selected when joined LFG
        std::string m_Comment;                             ///< Player comment used when joined LFG
        LfgDungeonSet m_SelectedDungeons;                  ///< Selected Dungeons when joined LFG

        // Shortage
        bool m_EnligibleForShortageRewards;                ///< Bonus reward state for shortage rewards
};

} // namespace lfg

#endif
