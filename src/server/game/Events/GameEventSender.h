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

#ifndef GameEventSender_h__
#define GameEventSender_h__

#include "Define.h"

class Map;
class Player;
class WorldObject;

namespace GameEvents
{
    TC_GAME_API void Trigger(uint32 gameEventId, WorldObject* source, WorldObject* target);
    TC_GAME_API void TriggerForPlayer(uint32 gameEventId, Player* source);
    TC_GAME_API void TriggerForMap(uint32 gameEventId, Map* map, WorldObject* source = nullptr, WorldObject* target = nullptr);
}

#endif // GameEventSender_h__
