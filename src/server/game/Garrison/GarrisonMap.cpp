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

#include "GarrisonMap.h"
#include "DBCEnums.h"
#include "GameObject.h"
#include "Garrison.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectGridLoader.h"
#include "Player.h"
#include "World.h"

class GarrisonGridLoader
{
public:
    GarrisonGridLoader(NGridType* grid, GarrisonMap* map)
        : i_grid(grid), i_map(map), i_garrison(map->GetGarrison()), i_gameObjects(0), i_creatures(0)
    { }

    void LoadN();

private:
    NGridType* i_grid;
    GarrisonMap* i_map;
    Garrison* i_garrison;
    uint32 i_gameObjects;
    uint32 i_creatures;
};

void GarrisonGridLoader::LoadN()
{
    if (i_garrison)
    {
        for (Garrison::Plot* plot : i_garrison->GetPlots())
        {
            GameObject* go = plot->CreateGameObject(i_map, i_garrison->GetFaction());
            if (!go)
                continue;

            ObjectGridLoaderBase::AddToMap(go, i_map, i_gameObjects);
        }
    }

    TC_LOG_DEBUG("maps", "{} GameObjects and {} Creatures loaded for grid {} on map {}", i_gameObjects, i_creatures, i_grid->GetGridId(), i_map->GetId());
}

GarrisonMap::GarrisonMap(uint32 id, time_t expiry, uint32 instanceId, ObjectGuid const& owner)
    : Map(id, expiry, instanceId, DIFFICULTY_NORMAL), _owner(owner), _loadingPlayer(nullptr)
{
    GarrisonMap::InitVisibilityDistance();
}

void GarrisonMap::LoadGridObjects(NGridType* grid)
{
    Map::LoadGridObjects(grid);

    GarrisonGridLoader loader(grid, this);
    loader.LoadN();
}

Garrison* GarrisonMap::GetGarrison()
{
    if (_loadingPlayer)
        return _loadingPlayer->GetGarrison();

    if (Player* owner = ObjectAccessor::FindConnectedPlayer(_owner))
        return owner->GetGarrison();

    return nullptr;
}

void GarrisonMap::InitVisibilityDistance()
{
    //init visibility distance for instances
    m_VisibleDistance = sWorld->getFloatConfig(CONFIG_MAX_VISIBILITY_DISTANCE_INSTANCE);
    m_VisibilityNotifyPeriod = sWorld->getIntConfig(CONFIG_VISIBILITY_NOTIFY_PERIOD_INSTANCE);
}

bool GarrisonMap::AddPlayerToMap(Player* player, bool initPlayer /*= true*/)
{
    if (player->GetGUID() == _owner)
        _loadingPlayer = player;

    bool result = Map::AddPlayerToMap(player, initPlayer);

    if (player->GetGUID() == _owner)
        _loadingPlayer = nullptr;

    return result;
}
