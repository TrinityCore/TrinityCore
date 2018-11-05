/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "Battlefield.h"
#include "SharedDefines.h"

Battlefield::Battlefield(BattlefieldBattleId battleId, BattlefieldZoneId zoneId) : _battleId(battleId), _zoneId(zoneId), _enabled(false), _controllingTeam(PVP_TEAM_NEUTRAL)
{
}

PvPTeamId Battlefield::GetAttackerTeam() const
{
    return _controllingTeam == PVP_TEAM_NEUTRAL ? PVP_TEAM_NEUTRAL : PvPTeamId(1 - _controllingTeam);
}

bool Battlefield::Initialize(bool status)
{
    _enabled = status;
    return true;
}
