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

#include "LFG.h"
#include "LFGGroupData.h"

namespace lfg
{

LfgGroupData::LfgGroupData(): m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE),
    m_Leader(), m_Dungeon(0), m_KicksLeft(LFG_GROUP_MAX_KICKS), m_VoteKickActive(false)
{ }

LfgGroupData::~LfgGroupData()
{ }

bool LfgGroupData::IsLfgGroup()
{
    return m_OldState != LFG_STATE_NONE;
}

void LfgGroupData::SetState(LfgState state)
{
    switch (state)
    {
        case LFG_STATE_NONE:
            m_Dungeon = 0;
            m_KicksLeft = LFG_GROUP_MAX_KICKS;
        case LFG_STATE_FINISHED_DUNGEON:
        case LFG_STATE_DUNGEON:
            m_OldState = state;
            // No break on purpose
        default:
            m_State = state;
    }
}

void LfgGroupData::RestoreState()
{
    m_State = m_OldState;
}

void LfgGroupData::AddPlayer(ObjectGuid guid)
{
    m_Players.insert(guid);
}

uint8 LfgGroupData::RemovePlayer(ObjectGuid guid)
{
    GuidSet::iterator it = m_Players.find(guid);
    if (it != m_Players.end())
        m_Players.erase(it);
    return uint8(m_Players.size());
}

void LfgGroupData::RemoveAllPlayers()
{
    m_Players.clear();
}

void LfgGroupData::SetLeader(ObjectGuid guid)
{
    m_Leader = guid;
}

void LfgGroupData::SetDungeon(uint32 dungeon)
{
    m_Dungeon = dungeon;
}

void LfgGroupData::DecreaseKicksLeft()
{
    if (m_KicksLeft)
      --m_KicksLeft;
}

LfgState LfgGroupData::GetState() const
{
    return m_State;
}

LfgState LfgGroupData::GetOldState() const
{
    return m_OldState;
}

GuidSet const& LfgGroupData::GetPlayers() const
{
    return m_Players;
}

uint8 LfgGroupData::GetPlayerCount() const
{
    return m_Players.size();
}

ObjectGuid LfgGroupData::GetLeader() const
{
    return m_Leader;
}

uint32 LfgGroupData::GetDungeon(bool asId /* = true */) const
{
    if (asId)
        return (m_Dungeon & 0x00FFFFFF);
    else
        return m_Dungeon;
}

uint8 LfgGroupData::GetKicksLeft() const
{
    return m_KicksLeft;
}

void LfgGroupData::SetVoteKick(bool active)
{
    m_VoteKickActive = active;
}

bool LfgGroupData::IsVoteKickActive() const
{
    return m_VoteKickActive;
}

} // namespace lfg
