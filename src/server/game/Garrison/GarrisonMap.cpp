/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
    GarrisonGridLoader(NGridType* grid, GarrisonMap* map, Cell const& cell)
        : i_cell(cell), i_grid(grid), i_map(map), i_garrison(map->GetGarrison()), i_gameObjects(0), i_creatures(0)
    { }

    void Visit(GameObjectMapType& m);
    void Visit(CreatureMapType& m);

    void LoadN();

    template<class T> static void SetObjectCell(T* obj, CellCoord const& cellCoord);
    template<class T> void Visit(GridRefManager<T>& /*m*/) { }

private:
    Cell i_cell;
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
        i_cell.data.Part.cell_y = 0;
        for (uint32 x = 0; x < MAX_NUMBER_OF_CELLS; ++x)
        {
            i_cell.data.Part.cell_x = x;
            for (uint32 y = 0; y < MAX_NUMBER_OF_CELLS; ++y)
            {
                i_cell.data.Part.cell_y = y;

                //Load creatures and game objects
                TypeContainerVisitor<GarrisonGridLoader, GridTypeMapContainer> visitor(*this);
                i_grid->VisitGrid(x, y, visitor);
            }
        }
    }

    TC_LOG_DEBUG("maps", "%u GameObjects and %u Creatures loaded for grid %u on map %u", i_gameObjects, i_creatures, i_grid->GetGridId(), i_map->GetId());
}

void GarrisonGridLoader::Visit(GameObjectMapType& m)
{
    std::vector<Garrison::Plot*> plots = i_garrison->GetPlots();
    if (!plots.empty())
    {
        CellCoord cellCoord = i_cell.GetCellCoord();
        for (Garrison::Plot* plot : plots)
        {
            Position const& spawn = plot->PacketInfo.PlotPos.Pos;
            if (cellCoord != Trinity::ComputeCellCoord(spawn.GetPositionX(), spawn.GetPositionY()))
                continue;

            GameObject* go = plot->CreateGameObject(i_map, i_garrison->GetFaction());
            if (!go)
                continue;

            go->AddToGrid(m);
            ObjectGridLoader::SetObjectCell(go, cellCoord);
            go->AddToWorld();
            ++i_gameObjects;
        }
    }
}

void GarrisonGridLoader::Visit(CreatureMapType& /*m*/)
{

}

GarrisonMap::GarrisonMap(uint32 id, time_t expiry, uint32 instanceId, Map* parent, ObjectGuid const& owner)
    : Map(id, expiry, instanceId, DIFFICULTY_NORMAL, parent), _owner(owner), _loadingPlayer(nullptr)
{
    GarrisonMap::InitVisibilityDistance();
}

void GarrisonMap::LoadGridObjects(NGridType* grid, Cell const& cell)
{
    Map::LoadGridObjects(grid, cell);

    GarrisonGridLoader loader(grid, this, cell);
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
    m_VisibleDistance = World::GetMaxVisibleDistanceInBGArenas();
    m_VisibilityNotifyPeriod = World::GetVisibilityNotifyPeriodInBGArenas();
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
