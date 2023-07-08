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

#include "Archaeology.h"
#include "DBCStore.h"
#include "Player.h"

Archaeology::Archaeology(Player* player): _player(player)
{
    _continentState[CONT_EASTERN] = STATE_NULL;
    _continentState[CONT_KALIMDOR] = STATE_NULL;
    _continentState[CONT_OUTLAND] = STATE_NULL;
    _continentState[CONT_NORTHREND] = STATE_NULL;
}

void Archaeology::Initialize()
{
    if (!_player || !_player->HasSkill(SKILL_ARCHAEOLOGY))
        return;

    LoadSitesFromDB();
    VerifySites();

    LoadCompletedProjectsFromDB();
    LoadCurrentProjectsFromDB();
    VerifyProjects();
}

void Archaeology::Learn()
{
    _continentState[CONT_EASTERN] = STATE_USE;
    _continentState[CONT_KALIMDOR] = STATE_USE;
    _continentState[CONT_OUTLAND] = STATE_NULL;
    _continentState[CONT_NORTHREND] = STATE_NULL;
    RegenerateAllSites();

    InitBranches();
    VerifyProjects();
}

void Archaeology::UnLearn()
{
    _continentState[CONT_EASTERN] = STATE_NULL;
    _continentState[CONT_KALIMDOR] = STATE_NULL;
    _continentState[CONT_OUTLAND] = STATE_NULL;
    _continentState[CONT_NORTHREND] = STATE_NULL;
    RegenerateAllSites();

    CleanProjects();
}

void Archaeology::Update()
{
    uint16 skillValue = _player->GetSkillValue(SKILL_ARCHAEOLOGY);

    if (SKILL_OUTLAND <= skillValue && _continentState[CONT_OUTLAND] == STATE_NULL)
    {
        _continentState[CONT_OUTLAND] = STATE_USE;
        RegenerateContinent(CONT_OUTLAND);
    }

    if(SKILL_NORTHREND <= skillValue && _continentState[CONT_NORTHREND] == STATE_NULL)
    {
        _continentState[CONT_NORTHREND] = STATE_USE;
        RegenerateContinent(CONT_NORTHREND);
    }

    if(SKILL_CATA <= skillValue)
    {
        _continentState[CONT_EASTERN] = STATE_EXT;
        _continentState[CONT_KALIMDOR] = STATE_EXT;
    }
}
