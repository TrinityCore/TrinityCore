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
    m_Team(0), m_Group(), m_Roles(0), m_Comment(""), m_NumberOfPartyMembersAtJoin(0)
{ }

LfgPlayerData::~LfgPlayerData() { }

void LfgPlayerData::SetState(LfgState state)
{
    switch (state)
    {
        case LFG_STATE_NONE:
        case LFG_STATE_FINISHED_DUNGEON:
            m_Roles = 0;
            m_SelectedDungeons.clear();
            m_Comment.clear();
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

void LfgPlayerData::SetComment(std::string const& comment)
{
    m_Comment = comment;
}

void LfgPlayerData::SetSelectedDungeons(LfgDungeonSet const& dungeons)
{
    m_SelectedDungeons = dungeons;
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

std::string const& LfgPlayerData::GetComment() const
{
    return m_Comment;
}

LfgDungeonSet const& LfgPlayerData::GetSelectedDungeons() const
{
    return m_SelectedDungeons;
}

void LfgPlayerData::SetNumberOfPartyMembersAtJoin(uint8 count)
{
    m_NumberOfPartyMembersAtJoin = count;
}

uint8 LfgPlayerData::GetNumberOfPartyMembersAtJoin()
{
    return m_NumberOfPartyMembersAtJoin;
}

} // namespace lfg
