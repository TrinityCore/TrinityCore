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

#ifndef __GAMECLIENT_H
#define __GAMECLIENT_H

#include "WorldSession.h"

class Player;
class Unit;

class TC_GAME_API GameClient
{
    public:
        GameClient(WorldSession* sessionToServer);

        void AddAllowedMover(Unit* unit);
        void RemoveAllowedMover(Unit* unit);
        bool IsAllowedToMove(Unit* unit) const;
        bool IsAllowedToMove(ObjectGuid guid) const;
        void SetMovedUnit(Unit* target, bool allowMove);

        Unit* GetActivelyMovedUnit() const { return _activelyMovedUnit; }
        void SetActivelyMovedUnit(Unit* activelyMovedUnit) { _activelyMovedUnit = activelyMovedUnit; }

        Player* GetBasePlayer() const { return _sessionToServer->GetPlayer(); }
        WorldSession* GetWorldSession() const { return _sessionToServer; }

        void SendDirectMessage(WorldPacket const* data) const;

        std::string GetDebugInfo() const;
    private:
        // describe all units that this client has direct control over. Example, a player on a vehicle has client control over himself and the vehicle at the same time.
        GuidUnorderedSet _allowedMovers;

        // set/unset upon receiving CMSG_SET_ACTIVE_MOVER and CMSG_MOVE_NOT_ACTIVE_MOVER by the client
        // in other words, this field is set by the client (as long as the change is allowed by the server)
        Unit* _activelyMovedUnit;

        WorldSession* _sessionToServer;
};

#endif // __GAMECLIENT_H
