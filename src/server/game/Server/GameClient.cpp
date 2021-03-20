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

#include "GameClient.h"
#include "WorldSession.h"

GameClient::GameClient(WorldSession* sessionToServer) // : unitBeingMoved(nullptr)
{
    _sessionToServer = sessionToServer;
    _activeMover = nullptr;
}

//void GameClient::InitBasePlayer(Player * player)
//{
//    isBasePlayerSet = true;
//    this->currentlyControlledUnitServerPov = player;
//    AddAllowedMover(player->GetGUID());
//}
//
void GameClient::AddAllowedMover(Unit* unit)
{
    _allowedMovers.insert(unit->GetGUID());
    unit->SetGameClientMovingMe(this);
}

void GameClient::RemoveAllowedMover(Unit* unit)
{
    _allowedMovers.erase(unit->GetGUID());
    if (unit->GetGameClientMovingMe() == this)
        unit->SetGameClientMovingMe(nullptr);
    else
        TC_LOG_ERROR("entities.player", "this should not happen"); // @TODO: add proper handling here
}

bool GameClient::IsAllowedToMove(Unit* unit) const
{
    return _allowedMovers.count(unit->GetGUID());
}

bool GameClient::IsAllowedToMove(ObjectGuid guid) const
{
    return _allowedMovers.count(guid);
}

//void GameClient::SendDirectMessage(WorldPacket const * data) const
//{
//    _sessionToServer->SendPacket(data);
//}
//
//Player * GameClient::GetBasePlayer() const
//{
//    return isBasePlayerSet ? _sessionToServer->GetPlayer() : nullptr;
//}
