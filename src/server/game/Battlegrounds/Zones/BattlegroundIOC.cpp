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

#include "BattlegroundIOC.h"

BattlegroundIOC::BattlegroundIOC(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
{
    //BgObjects.resize(BG_WS_OBJECT_MAX);
    //BgCreatures.resize(BG_CREATURES_MAX_WS);

    //StartMessageIds[BG_STARTING_EVENT_SECOND] = BG_WS_TEXT_START_ONE_MINUTE;
    //StartMessageIds[BG_STARTING_EVENT_THIRD] = BG_WS_TEXT_START_HALF_MINUTE;
    //StartMessageIds[BG_STARTING_EVENT_FOURTH] = BG_WS_TEXT_BATTLE_HAS_BEGUN;

    //_flagSpellForceTimer = 0;
    //_bothFlagsKept = false;
    //_flagDebuffState = 0;
    //m_FlagKeepers[TEAM_ALLIANCE].Clear();
    //m_FlagKeepers[TEAM_HORDE].Clear();
    //m_DroppedFlagGUID[TEAM_ALLIANCE].Clear();
    //m_DroppedFlagGUID[TEAM_HORDE].Clear();
    //_flagState[TEAM_ALLIANCE] = BG_WS_FLAG_STATE_ON_BASE;
    //_flagState[TEAM_HORDE] = BG_WS_FLAG_STATE_ON_BASE;
    //_flagsTimer[TEAM_ALLIANCE] = 0;
    //_flagsTimer[TEAM_HORDE] = 0;
    //_flagsDropTimer[TEAM_ALLIANCE] = 0;
    //_flagsDropTimer[TEAM_HORDE] = 0;
    //_lastFlagCaptureTeam = 0;
    //m_ReputationCapture = 0;
    //m_HonorWinKills = 0;
    //m_HonorEndKills = 0;
    //_minutesElapsed = 0;
}

BattlegroundIOC::~BattlegroundIOC() { }
