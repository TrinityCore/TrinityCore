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

#include "GameClient.h"
#include "WorldSession.h"
#include "Unit.h"
#include "Player.h"

GameClient::GameClient(WorldSession* sessionToServer)
{
    _sessionToServer = sessionToServer;
    _activelyMovedUnit = nullptr;
}

void GameClient::AddAllowedMover(Unit* unit)
{
    if (GameClient* previousController = unit->GetGameClientMovingMe())
        previousController->RemoveAllowedMover(unit);

    _allowedMovers.insert(unit->GetGUID());
    unit->SetGameClientMovingMe(this);
}

void GameClient::RemoveAllowedMover(Unit* unit)
{
    _allowedMovers.erase(unit->GetGUID());
    if (unit->GetGameClientMovingMe() == this)
    {
        unit->SetGameClientMovingMe(nullptr);
        SetActivelyMovedUnit(nullptr);
    }
}

bool GameClient::IsAllowedToMove(Unit* unit) const
{
    return _allowedMovers.count(unit->GetGUID());
}

bool GameClient::IsAllowedToMove(ObjectGuid guid) const
{
    return _allowedMovers.count(guid);
}

void GameClient::SetMovedUnit(Unit* target, bool allowMove)
{
    if (allowMove)
        AddAllowedMover(target);
    else
        RemoveAllowedMover(target);
}

void GameClient::SendDirectMessage(WorldPacket const* data) const
{
    GetBasePlayer()->SendDirectMessage(data);
}
