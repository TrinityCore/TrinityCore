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

#ifndef GarrisonMap_h__
#define GarrisonMap_h__

#include "Map.h"

class Garrison;
class Player;

class TC_GAME_API GarrisonMap : public Map
{
public:
    GarrisonMap(uint32 id, time_t, uint32 instanceId, Map* parent, ObjectGuid const& owner);

    void LoadGridObjects(NGridType* grid, Cell const& cell) override;
    Garrison* GetGarrison();

    void InitVisibilityDistance() override;

    bool AddPlayerToMap(Player* player, bool initPlayer = true) override;

private:
    ObjectGuid _owner;
    Player* _loadingPlayer; ///< @workaround Player is not registered in ObjectAccessor during login
};

#endif // GarrisonMap_h__
