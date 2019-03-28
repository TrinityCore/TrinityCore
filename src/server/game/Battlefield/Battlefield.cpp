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
#include "BattlefieldEntities.h"

Battlefield::Battlefield(BattlefieldBattleId battleId, BattlefieldZoneId zoneId) : _battleId(battleId), _zoneId(zoneId), _enabled(false), _active(false), _controllingTeam(PVP_TEAM_NEUTRAL), _timer(0)
{
}

Battlefield::~Battlefield()
{
}

bool Battlefield::Initialize(bool enabled)
{
    _enabled = enabled;
    return true;
}

void Battlefield::Update(uint32 /*diff*/)
{
}

void Battlefield::HandlePlayerEnterZone(Player* /*player*/)
{
}

void Battlefield::HandlePlayerLeaveZone(Player* /*player*/)
{
}

void Battlefield::HandleAreaSpiritHealerQueryOpcode(Player* /*player*/, ObjectGuid /*source*/)
{
}

void Battlefield::HandleAddPlayerToResurrectionQueue(Player* /*player*/, ObjectGuid /*source*/)
{
}

void Battlefield::HandleRemovePlayerFromResurrectionQueue(Player* /*player*/)
{
}

void Battlefield::EmplaceGraveyard(uint8 id, BattlefieldGraveyardPointer&& pointer)
{
    _graveyards.emplace(id, std::move(pointer));
}

Battlefield::BattlefieldGraveyardPointer& Battlefield::GetGraveyard(uint8 graveyardId)
{
    return _graveyards[graveyardId];
}

PvPTeamId Battlefield::GetAttackingTeam() const
{
    switch (GetControllingTeam())
    {
        case PVP_TEAM_HORDE:
            return PVP_TEAM_ALLIANCE;
        case PVP_TEAM_ALLIANCE:
            return PVP_TEAM_HORDE;
        case PVP_TEAM_NEUTRAL:
            return PVP_TEAM_NEUTRAL;
        default:
            break;
    }
    return PVP_TEAM_NEUTRAL;
}

TeamId Battlefield::GetControllingTeamId() const
{
    return TeamIdByPvPTeamId(GetControllingTeam());
}

TeamId Battlefield::GetAttackingTeamId() const
{
    return TeamIdByPvPTeamId(GetAttackingTeam());
}

WorldSafeLocsEntry const* Battlefield::GetClosestGraveyardLocation(Player* /*who*/) const
{
    return nullptr;
}
