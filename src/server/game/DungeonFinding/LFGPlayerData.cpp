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

#include "LFGPlayerData.h"

namespace lfg
{

LfgPlayerData::LfgPlayerData(): m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE),
    m_Team(0), m_Group(), m_Roles(0)
{ }

LfgPlayerData::~LfgPlayerData() { }

void LfgPlayerData::SetTicket(WorldPackets::LFG::RideTicket const& ticket)
{
    m_Ticket = ticket;
}

void LfgPlayerData::SetState(LfgState state)
{
    switch (state)
    {
        case LFG_STATE_NONE:
        case LFG_STATE_FINISHED_DUNGEON:
            m_Roles = 0;
            m_SelectedDungeons.clear();
            /* fallthrough */
        case LFG_STATE_DUNGEON:
            m_OldState = state;
            /* fallthrough */
        default:
            m_State = state;
    }
}

void LfgPlayerData::RestoreState()
{
    if (m_OldState == LFG_STATE_NONE)
    {
        m_SelectedDungeons.clear();
        m_Roles = 0;
    }
    m_State = m_OldState;
}

void LfgPlayerData::SetTeam(uint8 team)
{
    m_Team = team;
}

void LfgPlayerData::SetGroup(ObjectGuid group)
{
    m_Group = group;
}

void LfgPlayerData::SetRoles(uint8 roles)
{
    m_Roles = roles;
}

void LfgPlayerData::SetSelectedDungeons(LfgDungeonSet const& dungeons)
{
    m_SelectedDungeons = dungeons;
}

WorldPackets::LFG::RideTicket const& LfgPlayerData::GetTicket() const
{
    return m_Ticket;
}

LfgState LfgPlayerData::GetState() const
{
    return m_State;
}

LfgState LfgPlayerData::GetOldState() const
{
    return m_OldState;
}

uint8 LfgPlayerData::GetTeam() const
{
    return m_Team;
}

ObjectGuid LfgPlayerData::GetGroup() const
{
    return m_Group;
}

uint8 LfgPlayerData::GetRoles() const
{
    return m_Roles;
}

LfgDungeonSet const& LfgPlayerData::GetSelectedDungeons() const
{
    return m_SelectedDungeons;
}

} // namespace lfg
