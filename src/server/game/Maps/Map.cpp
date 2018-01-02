/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Map.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "Conversation.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "DynamicTree.h"
#include "GameObjectModel.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "GridStates.h"
#include "Group.h"
#include "InstancePackets.h"
#include "InstanceScenario.h"
#include "InstanceScript.h"
#include "Log.h"
#include "MapInstanced.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "MMapFactory.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectGridLoader.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "ScriptMgr.h"
#include "Transport.h"
#include "Vehicle.h"
#include "VMapFactory.h"
#include "Weather.h"
#include "WeatherMgr.h"
#include "World.h"
#include "WorldSession.h"

u_map_magic MapMagic        = { {'M','A','P','S'} };
u_map_magic MapVersionMagic = { {'v','1','.','8'} };
u_map_magic MapAreaMagic    = { {'A','R','E','A'} };
u_map_magic MapHeightMagic  = { {'M','H','G','T'} };
u_map_magic MapLiquidMagic  = { {'M','L','I','Q'} };

#define DEFAULT_GRID_EXPIRY     300
#define MAX_GRID_LOAD_TIME      50
#define MAX_CREATURE_ATTACK_RADIUS  (45.0f * sWorld->getRate(RATE_CREATURE_AGGRO))

GridState* si_GridStates[MAX_GRID_STATE];


ZoneDynamicInfo::ZoneDynamicInfo() : MusicId(0), DefaultWeather(nullptr), WeatherId(WEATHER_STATE_FINE),
    WeatherGrade(0.0f), OverrideLightId(0), LightFadeInTime(0) { }

Map::~Map()
{
    // UnloadAll must be called before deleting the map

    sScriptMgr->OnDestroyMap(this);

    while (!i_worldObjects.empty())
    {
        WorldObject* obj = *i_worldObjects.begin();
        ASSERT(obj->IsWorldObject());
        //ASSERT(obj->GetTypeId() == TYPEID_CORPSE);
        obj->RemoveFromWorld();
        obj->ResetMap();
    }

    if (!m_scriptSchedule.empty())
        sMapMgr->DecreaseScheduledScriptCount(m_scriptSchedule.size());

    MMAP::MMapFactory::createOrGetMMapManager()->unloadMapInstance(GetId(), i_InstanceId);
}

bool Map::ExistMap(uint32 mapid, int gx, int gy)
{
    std::string fileName = Trinity::StringFormat("%smaps/%04u_%02u_%02u.map", sWorld->GetDataPath().c_str(), mapid, gx, gy);

    bool ret = false;
    FILE* file = fopen(fileName.c_str(), "rb");
    if (!file)
    {
        TC_LOG_ERROR("maps", "Map file '%s' does not exist!", fileName.c_str());
        TC_LOG_ERROR("maps", "Please place MAP-files (*.map) in the appropriate directory (%s), or correct the DataDir setting in your worldserver.conf file.", (sWorld->GetDataPath()+"maps/").c_str());
    }
    else
    {
        map_fileheader header;
        if (fread(&header, sizeof(header), 1, file) == 1)
        {
            if (header.mapMagic.asUInt != MapMagic.asUInt || header.versionMagic.asUInt != MapVersionMagic.asUInt)
                TC_LOG_ERROR("maps", "Map file '%s' is from an incompatible map version (%.*s %.*s), %.*s %.*s is expected. Please pull your source, recompile tools and recreate maps using the updated mapextractor, then replace your old map files with new files. If you still have problems search on forum for error TCE00018.",
                    fileName.c_str(), 4, header.mapMagic.asChar, 4, header.versionMagic.asChar, 4, MapMagic.asChar, 4, MapVersionMagic.asChar);
            else
                ret = true;
        }
        fclose(file);
    }

    return ret;
}

bool Map::ExistVMap(uint32 mapid, int gx, int gy)
{
    if (VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager())
    {
        if (vmgr->isMapLoadingEnabled())
        {
            bool exists = vmgr->existsMap((sWorld->GetDataPath()+ "vmaps").c_str(),  mapid, gx, gy);
            if (!exists)
            {
                std::string name = vmgr->getDirFileName(mapid, gx, gy);
                TC_LOG_ERROR("maps", "VMap file '%s' does not exist", (sWorld->GetDataPath()+"vmaps/"+name).c_str());
                TC_LOG_ERROR("maps", "Please place VMAP-files (*.vmtree and *.vmtile) in the vmap-directory (%s), or correct the DataDir setting in your worldserver.conf file.", (sWorld->GetDataPath()+"vmaps/").c_str());
                return false;
            }
        }
    }

    return true;
}

void Map::LoadMMap(int gx, int gy)
{
    if (!DisableMgr::IsPathfindingEnabled(GetId()))
        return;

    bool mmapLoadResult = MMAP::MMapFactory::createOrGetMMapManager()->loadMap((sWorld->GetDataPath() + "mmaps").c_str(), GetId(), gx, gy);

    if (mmapLoadResult)
        TC_LOG_DEBUG("mmaps", "MMAP loaded name:%s, id:%d, x:%d, y:%d (mmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx, gy, gx, gy);
    else
        TC_LOG_ERROR("mmaps", "Could not load MMAP name:%s, id:%d, x:%d, y:%d (mmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx, gy, gx, gy);
}

void Map::LoadVMap(int gx, int gy)
{
    if (!VMAP::VMapFactory::createOrGetVMapManager()->isMapLoadingEnabled())
        return;
                                                            // x and y are swapped !!
    int vmapLoadResult = VMAP::VMapFactory::createOrGetVMapManager()->loadMap((sWorld->GetDataPath()+ "vmaps").c_str(),  GetId(), gx, gy);
    switch (vmapLoadResult)
    {
        case VMAP::VMAP_LOAD_RESULT_OK:
            TC_LOG_DEBUG("maps", "VMAP loaded name:%s, id:%d, x:%d, y:%d (vmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx, gy, gx, gy);
            break;
        case VMAP::VMAP_LOAD_RESULT_ERROR:
            TC_LOG_ERROR("maps", "Could not load VMAP name:%s, id:%d, x:%d, y:%d (vmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx, gy, gx, gy);
            break;
        case VMAP::VMAP_LOAD_RESULT_IGNORED:
            TC_LOG_DEBUG("maps", "Ignored VMAP name:%s, id:%d, x:%d, y:%d (vmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx, gy, gx, gy);
            break;
    }
}

void Map::LoadMap(int gx, int gy, bool reload)
{
    if (i_InstanceId != 0)
    {
        if (GridMaps[gx][gy])
            return;

        // load grid map for base map
        if (!m_parentMap->GridMaps[gx][gy])
            m_parentMap->EnsureGridCreated(GridCoord((MAX_NUMBER_OF_GRIDS - 1) - gx, (MAX_NUMBER_OF_GRIDS - 1) - gy));

        ((MapInstanced*)(m_parentMap))->AddGridMapReference(GridCoord(gx, gy));
        GridMaps[gx][gy] = m_parentMap->GridMaps[gx][gy];
        return;
    }

    if (GridMaps[gx][gy] && !reload)
        return;

    //map already load, delete it before reloading (Is it necessary? Do we really need the ability the reload maps during runtime?)
    if (GridMaps[gx][gy])
    {
        TC_LOG_DEBUG("maps", "Unloading previously loaded map %u before reloading.", GetId());
        sScriptMgr->OnUnloadGridMap(this, GridMaps[gx][gy], gx, gy);

        delete (GridMaps[gx][gy]);
        GridMaps[gx][gy]=NULL;
    }

    // map file name
    std::string fileName = Trinity::StringFormat("%smaps/%04u_%02u_%02u.map", sWorld->GetDataPath().c_str(), GetId(), gx, gy);
    TC_LOG_DEBUG("maps", "Loading map %s", fileName.c_str());
    // loading data
    GridMaps[gx][gy] = new GridMap();
    if (!GridMaps[gx][gy]->loadData(fileName.c_str()))
        TC_LOG_ERROR("maps", "Error loading map file: %s", fileName.c_str());

    sScriptMgr->OnLoadGridMap(this, GridMaps[gx][gy], gx, gy);
}

void Map::LoadMapAndVMap(int gx, int gy)
{
    LoadMap(gx, gy);
   // Only load the data for the base map
    if (i_InstanceId == 0)
    {
        LoadVMap(gx, gy);
        LoadMMap(gx, gy);
    }
}

void Map::LoadAllCells()
{
    for (uint32 cellX = 0; cellX < TOTAL_NUMBER_OF_CELLS_PER_MAP; cellX++)
        for (uint32 cellY = 0; cellY < TOTAL_NUMBER_OF_CELLS_PER_MAP; cellY++)
            LoadGrid((cellX + 0.5f - CENTER_GRID_CELL_ID) * SIZE_OF_GRID_CELL, (cellY + 0.5f - CENTER_GRID_CELL_ID) * SIZE_OF_GRID_CELL);
}

void Map::InitStateMachine()
{
    si_GridStates[GRID_STATE_INVALID] = new InvalidState;
    si_GridStates[GRID_STATE_ACTIVE] = new ActiveState;
    si_GridStates[GRID_STATE_IDLE] = new IdleState;
    si_GridStates[GRID_STATE_REMOVAL] = new RemovalState;
}

void Map::DeleteStateMachine()
{
    delete si_GridStates[GRID_STATE_INVALID];
    delete si_GridStates[GRID_STATE_ACTIVE];
    delete si_GridStates[GRID_STATE_IDLE];
    delete si_GridStates[GRID_STATE_REMOVAL];
}

Map::Map(uint32 id, time_t expiry, uint32 InstanceId, uint8 SpawnMode, Map* _parent):
_creatureToMoveLock(false), _gameObjectsToMoveLock(false), _dynamicObjectsToMoveLock(false), _areaTriggersToMoveLock(false),
i_mapEntry(sMapStore.LookupEntry(id)), i_spawnMode(SpawnMode), i_InstanceId(InstanceId),
m_unloadTimer(0), m_VisibleDistance(DEFAULT_VISIBILITY_DISTANCE),
m_VisibilityNotifyPeriod(DEFAULT_VISIBILITY_NOTIFY_PERIOD),
m_activeNonPlayersIter(m_activeNonPlayers.end()), _transportsUpdateIter(_transports.end()),
i_gridExpiry(expiry),
i_scriptLock(false), _defaultLight(DB2Manager::GetDefaultMapLight(id))
{
    m_parentMap = (_parent ? _parent : this);
    for (unsigned int idx=0; idx < MAX_NUMBER_OF_GRIDS; ++idx)
    {
        for (unsigned int j=0; j < MAX_NUMBER_OF_GRIDS; ++j)
        {
            //z code
            GridMaps[idx][j] =NULL;
            setNGrid(NULL, idx, j);
        }
    }

    //lets initialize visibility distance for map
    Map::InitVisibilityDistance();

    _weatherUpdateTimer.SetInterval(time_t(1 * IN_MILLISECONDS));

    GetGuidSequenceGenerator<HighGuid::Transport>().Set(sObjectMgr->GetGenerator<HighGuid::Transport>().GetNextAfterMaxUsed());

    sScriptMgr->OnCreateMap(this);
}

void Map::InitVisibilityDistance()
{
    //init visibility for continents
    m_VisibleDistance = World::GetMaxVisibleDistanceOnContinents();
    m_VisibilityNotifyPeriod = World::GetVisibilityNotifyPeriodOnContinents();
}

// Template specialization of utility methods
template<class T>
void Map::AddToGrid(T* obj, Cell const& cell)
{
    NGridType* grid = getNGrid(cell.GridX(), cell.GridY());
    if (obj->IsWorldObject())
        grid->GetGridType(cell.CellX(), cell.CellY()).template AddWorldObject<T>(obj);
    else
        grid->GetGridType(cell.CellX(), cell.CellY()).template AddGridObject<T>(obj);
}

template<>
void Map::AddToGrid(Creature* obj, Cell const& cell)
{
    NGridType* grid = getNGrid(cell.GridX(), cell.GridY());
    if (obj->IsWorldObject())
        grid->GetGridType(cell.CellX(), cell.CellY()).AddWorldObject(obj);
    else
        grid->GetGridType(cell.CellX(), cell.CellY()).AddGridObject(obj);

    obj->SetCurrentCell(cell);
}

template<>
void Map::AddToGrid(GameObject* obj, Cell const& cell)
{
    NGridType* grid = getNGrid(cell.GridX(), cell.GridY());
    grid->GetGridType(cell.CellX(), cell.CellY()).AddGridObject(obj);

    obj->SetCurrentCell(cell);
}

template<>
void Map::AddToGrid(DynamicObject* obj, Cell const& cell)
{
    NGridType* grid = getNGrid(cell.GridX(), cell.GridY());
    grid->GetGridType(cell.CellX(), cell.CellY()).AddGridObject(obj);

    obj->SetCurrentCell(cell);
}

template<>
void Map::AddToGrid(AreaTrigger* obj, Cell const& cell)
{
    NGridType* grid = getNGrid(cell.GridX(), cell.GridY());
    grid->GetGridType(cell.CellX(), cell.CellY()).AddGridObject(obj);

    obj->SetCurrentCell(cell);
}

template<>
void Map::AddToGrid(Corpse* obj, Cell const& cell)
{
    NGridType* grid = getNGrid(cell.GridX(), cell.GridY());
    // Corpses are a special object type - they can be added to grid via a call to AddToMap
    // or loaded through ObjectGridLoader.
    // Both corpses loaded from database and these freshly generated by Player::CreateCoprse are added to _corpsesByCell
    // ObjectGridLoader loads all corpses from _corpsesByCell even if they were already added to grid before it was loaded
    // so we need to explicitly check it here (Map::AddToGrid is only called from Player::BuildPlayerRepop, not from ObjectGridLoader)
    // to avoid failing an assertion in GridObject::AddToGrid
    if (grid->isGridObjectDataLoaded())
    {
        if (obj->IsWorldObject())
            grid->GetGridType(cell.CellX(), cell.CellY()).AddWorldObject(obj);
        else
            grid->GetGridType(cell.CellX(), cell.CellY()).AddGridObject(obj);
    }
}

template<class T>
void Map::SwitchGridContainers(T* /*obj*/, bool /*on*/) { }

template<>
void Map::SwitchGridContainers(Creature* obj, bool on)
{
    ASSERT(!obj->IsPermanentWorldObject());
    CellCoord p = Trinity::ComputeCellCoord(obj->GetPositionX(), obj->GetPositionY());
    if (!p.IsCoordValid())
    {
        TC_LOG_ERROR("maps", "Map::SwitchGridContainers: Object %s has invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUID().ToString().c_str(), obj->GetPositionX(), obj->GetPositionY(), p.x_coord, p.y_coord);
        return;
    }

    Cell cell(p);
    if (!IsGridLoaded(GridCoord(cell.data.Part.grid_x, cell.data.Part.grid_y)))
        return;

    if (sLog->ShouldLog("maps", LOG_LEVEL_DEBUG))
    {
        // Extract bitfield values
        uint32 const grid_x = cell.data.Part.grid_x;
        uint32 const grid_y = cell.data.Part.grid_y;

        TC_LOG_DEBUG("maps", "Switch object %s from grid[%u, %u] %u", obj->GetGUID().ToString().c_str(), grid_x, grid_y, on);
    }

    NGridType *ngrid = getNGrid(cell.GridX(), cell.GridY());
    ASSERT(ngrid != NULL);

    GridType &grid = ngrid->GetGridType(cell.CellX(), cell.CellY());

    obj->RemoveFromGrid(); //This step is not really necessary but we want to do ASSERT in remove/add

    if (on)
    {
        grid.AddWorldObject(obj);
        AddWorldObject(obj);
    }
    else
    {
        grid.AddGridObject(obj);
        RemoveWorldObject(obj);
    }

    obj->m_isTempWorldObject = on;
}

template<>
void Map::SwitchGridContainers(GameObject* obj, bool on)
{
    ASSERT(!obj->IsPermanentWorldObject());
    CellCoord p = Trinity::ComputeCellCoord(obj->GetPositionX(), obj->GetPositionY());
    if (!p.IsCoordValid())
    {
        TC_LOG_ERROR("maps", "Map::SwitchGridContainers: Object %s has invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUID().ToString().c_str(), obj->GetPositionX(), obj->GetPositionY(), p.x_coord, p.y_coord);
        return;
    }

    Cell cell(p);
    if (!IsGridLoaded(GridCoord(cell.data.Part.grid_x, cell.data.Part.grid_y)))
        return;

    if (sLog->ShouldLog("maps", LOG_LEVEL_DEBUG))
    {
        // Extract bitfield values
        uint32 const grid_x = cell.data.Part.grid_x;
        uint32 const grid_y = cell.data.Part.grid_y;

        TC_LOG_DEBUG("maps", "Switch object %s from grid[%u, %u] %u", obj->GetGUID().ToString().c_str(), grid_x, grid_y, on);
    }

    NGridType *ngrid = getNGrid(cell.GridX(), cell.GridY());
    ASSERT(ngrid != NULL);

    GridType &grid = ngrid->GetGridType(cell.CellX(), cell.CellY());

    obj->RemoveFromGrid(); //This step is not really necessary but we want to do ASSERT in remove/add

    if (on)
    {
        grid.AddWorldObject(obj);
        AddWorldObject(obj);
    }
    else
    {
        grid.AddGridObject(obj);
        RemoveWorldObject(obj);
    }
}

template<class T>
void Map::DeleteFromWorld(T* obj)
{
    // Note: In case resurrectable corpse and pet its removed from global lists in own destructor
    delete obj;
}

template<>
void Map::DeleteFromWorld(Player* player)
{
    ObjectAccessor::RemoveObject(player);
    RemoveUpdateObject(player); /// @todo I do not know why we need this, it should be removed in ~Object anyway
    delete player;
}

template<>
void Map::DeleteFromWorld(Transport* transport)
{
    ObjectAccessor::RemoveObject(transport);
    delete transport;
}

void Map::EnsureGridCreated(const GridCoord &p)
{
    std::lock_guard<std::mutex> lock(_gridLock);
    EnsureGridCreated_i(p);
}

//Create NGrid so the object can be added to it
//But object data is not loaded here
void Map::EnsureGridCreated_i(const GridCoord &p)
{
    if (!getNGrid(p.x_coord, p.y_coord))
    {
        TC_LOG_DEBUG("maps", "Creating grid[%u, %u] for map %u instance %u", p.x_coord, p.y_coord, GetId(), i_InstanceId);

        setNGrid(new NGridType(p.x_coord*MAX_NUMBER_OF_GRIDS + p.y_coord, p.x_coord, p.y_coord, i_gridExpiry, sWorld->getBoolConfig(CONFIG_GRID_UNLOAD)),
            p.x_coord, p.y_coord);

        // build a linkage between this map and NGridType
        buildNGridLinkage(getNGrid(p.x_coord, p.y_coord));

        getNGrid(p.x_coord, p.y_coord)->SetGridState(GRID_STATE_IDLE);

        //z coord
        int gx = (MAX_NUMBER_OF_GRIDS - 1) - p.x_coord;
        int gy = (MAX_NUMBER_OF_GRIDS - 1) - p.y_coord;

        if (!GridMaps[gx][gy])
            LoadMapAndVMap(gx, gy);
    }
}

//Load NGrid and make it active
void Map::EnsureGridLoadedForActiveObject(const Cell &cell, WorldObject* object)
{
    EnsureGridLoaded(cell);
    NGridType *grid = getNGrid(cell.GridX(), cell.GridY());
    ASSERT(grid != NULL);

    // refresh grid state & timer
    if (grid->GetGridState() != GRID_STATE_ACTIVE)
    {
        TC_LOG_DEBUG("maps", "Active object %s triggers loading of grid [%u, %u] on map %u", object->GetGUID().ToString().c_str(), cell.GridX(), cell.GridY(), GetId());
        ResetGridExpiry(*grid, 0.1f);
        grid->SetGridState(GRID_STATE_ACTIVE);
    }
}

//Create NGrid and load the object data in it
bool Map::EnsureGridLoaded(const Cell &cell)
{
    EnsureGridCreated(GridCoord(cell.GridX(), cell.GridY()));
    NGridType *grid = getNGrid(cell.GridX(), cell.GridY());

    ASSERT(grid != NULL);
    if (!isGridObjectDataLoaded(cell.GridX(), cell.GridY()))
    {
        TC_LOG_DEBUG("maps", "Loading grid[%u, %u] for map %u instance %u", cell.GridX(), cell.GridY(), GetId(), i_InstanceId);

        setGridObjectDataLoaded(true, cell.GridX(), cell.GridY());

        LoadGridObjects(grid, cell);

        Balance();
        return true;
    }

    return false;
}

void Map::LoadGridObjects(NGridType* grid, Cell const& cell)
{
    ObjectGridLoader loader(*grid, this, cell);
    loader.LoadN();
}

void Map::LoadGrid(float x, float y)
{
    EnsureGridLoaded(Cell(x, y));
}

bool Map::AddPlayerToMap(Player* player, bool initPlayer /*= true*/)
{
    CellCoord cellCoord = Trinity::ComputeCellCoord(player->GetPositionX(), player->GetPositionY());
    if (!cellCoord.IsCoordValid())
    {
        TC_LOG_ERROR("maps", "Map::Add: Player (%s) has invalid coordinates X:%f Y:%f grid cell [%u:%u]", player->GetGUID().ToString().c_str(), player->GetPositionX(), player->GetPositionY(), cellCoord.x_coord, cellCoord.y_coord);
        return false;
    }

    Cell cell(cellCoord);
    EnsureGridLoadedForActiveObject(cell, player);
    AddToGrid(player, cell);

    // Check if we are adding to correct map
    ASSERT (player->GetMap() == this);
    player->SetMap(this);
    player->AddToWorld();

    if (initPlayer)
        SendInitSelf(player);

    SendInitTransports(player);

    if (initPlayer)
        player->m_clientGUIDs.clear();

    player->UpdateObjectVisibility(false);
    player->SendUpdatePhasing();

    if (player->IsAlive())
        ConvertCorpseToBones(player->GetGUID());

    sScriptMgr->OnPlayerEnterMap(this, player);
    return true;
}

template<class T>
void Map::InitializeObject(T* /*obj*/) { }

template<>
void Map::InitializeObject(Creature* obj)
{
    obj->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
}

template<>
void Map::InitializeObject(GameObject* obj)
{
    obj->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
}

template<class T>
bool Map::AddToMap(T* obj)
{
    /// @todo Needs clean up. An object should not be added to map twice.
    if (obj->IsInWorld())
    {
        ASSERT(obj->IsInGrid());
        obj->UpdateObjectVisibility(true);
        return true;
    }

    CellCoord cellCoord = Trinity::ComputeCellCoord(obj->GetPositionX(), obj->GetPositionY());
    //It will create many problems (including crashes) if an object is not added to grid after creation
    //The correct way to fix it is to make AddToMap return false and delete the object if it is not added to grid
    //But now AddToMap is used in too many places, I will just see how many ASSERT failures it will cause
    ASSERT(cellCoord.IsCoordValid());
    if (!cellCoord.IsCoordValid())
    {
        TC_LOG_ERROR("maps", "Map::Add: Object %s has invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUID().ToString().c_str(), obj->GetPositionX(), obj->GetPositionY(), cellCoord.x_coord, cellCoord.y_coord);
        return false; //Should delete object
    }

    Cell cell(cellCoord);
    if (obj->isActiveObject())
        EnsureGridLoadedForActiveObject(cell, obj);
    else
        EnsureGridCreated(GridCoord(cell.GridX(), cell.GridY()));
    AddToGrid(obj, cell);
    TC_LOG_DEBUG("maps", "Object %s enters grid[%u, %u]", obj->GetGUID().ToString().c_str(), cell.GridX(), cell.GridY());

    //Must already be set before AddToMap. Usually during obj->Create.
    //obj->SetMap(this);
    obj->AddToWorld();

    InitializeObject(obj);

    if (obj->isActiveObject())
        AddToActive(obj);

    obj->RebuildTerrainSwaps();

    //something, such as vehicle, needs to be update immediately
    //also, trigger needs to cast spell, if not update, cannot see visual
    obj->UpdateObjectVisibilityOnCreate();
    return true;
}

template<>
bool Map::AddToMap(Transport* obj)
{
    //TODO: Needs clean up. An object should not be added to map twice.
    if (obj->IsInWorld())
        return true;

    CellCoord cellCoord = Trinity::ComputeCellCoord(obj->GetPositionX(), obj->GetPositionY());
    if (!cellCoord.IsCoordValid())
    {
        TC_LOG_ERROR("maps", "Map::Add: Object %s has invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUID().ToString().c_str(), obj->GetPositionX(), obj->GetPositionY(), cellCoord.x_coord, cellCoord.y_coord);
        return false; //Should delete object
    }

    obj->AddToWorld();
    _transports.insert(obj);

    // Broadcast creation to players
    if (!GetPlayers().isEmpty())
    {
        for (Map::PlayerList::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        {
            if (itr->GetSource()->GetTransport() != obj)
            {
                UpdateData data(GetId());
                obj->BuildCreateUpdateBlockForPlayer(&data, itr->GetSource());
                WorldPacket packet;
                data.BuildPacket(&packet);
                itr->GetSource()->SendDirectMessage(&packet);
            }
        }
    }

    return true;
}

bool Map::IsGridLoaded(const GridCoord &p) const
{
    return (getNGrid(p.x_coord, p.y_coord) && isGridObjectDataLoaded(p.x_coord, p.y_coord));
}

void Map::VisitNearbyCellsOf(WorldObject* obj, TypeContainerVisitor<Trinity::ObjectUpdater, GridTypeMapContainer> &gridVisitor, TypeContainerVisitor<Trinity::ObjectUpdater, WorldTypeMapContainer> &worldVisitor)
{
    // Check for valid position
    if (!obj->IsPositionValid())
        return;

    // Update mobs/objects in ALL visible cells around object!
    CellArea area = Cell::CalculateCellArea(obj->GetPositionX(), obj->GetPositionY(), obj->GetGridActivationRange());

    for (uint32 x = area.low_bound.x_coord; x <= area.high_bound.x_coord; ++x)
    {
        for (uint32 y = area.low_bound.y_coord; y <= area.high_bound.y_coord; ++y)
        {
            // marked cells are those that have been visited
            // don't visit the same cell twice
            uint32 cell_id = (y * TOTAL_NUMBER_OF_CELLS_PER_MAP) + x;
            if (isCellMarked(cell_id))
                continue;

            markCell(cell_id);
            CellCoord pair(x, y);
            Cell cell(pair);
            cell.SetNoCreate();
            Visit(cell, gridVisitor);
            Visit(cell, worldVisitor);
        }
    }
}

void Map::Update(const uint32 t_diff)
{
    _dynamicTree.update(t_diff);
    /// update worldsessions for existing players
    for (m_mapRefIter = m_mapRefManager.begin(); m_mapRefIter != m_mapRefManager.end(); ++m_mapRefIter)
    {
        Player* player = m_mapRefIter->GetSource();
        if (player && player->IsInWorld())
        {
            //player->Update(t_diff);
            WorldSession* session = player->GetSession();
            MapSessionFilter updater(session);
            session->Update(t_diff, updater);
        }
    }
    /// update active cells around players and active objects
    resetMarkedCells();

    Trinity::ObjectUpdater updater(t_diff);
    // for creature
    TypeContainerVisitor<Trinity::ObjectUpdater, GridTypeMapContainer  > grid_object_update(updater);
    // for pets
    TypeContainerVisitor<Trinity::ObjectUpdater, WorldTypeMapContainer > world_object_update(updater);

    // the player iterator is stored in the map object
    // to make sure calls to Map::Remove don't invalidate it
    for (m_mapRefIter = m_mapRefManager.begin(); m_mapRefIter != m_mapRefManager.end(); ++m_mapRefIter)
    {
        Player* player = m_mapRefIter->GetSource();

        if (!player || !player->IsInWorld())
            continue;

        // update players at tick
        player->Update(t_diff);

        VisitNearbyCellsOf(player, grid_object_update, world_object_update);

        // If player is using far sight, visit that object too
        if (WorldObject* viewPoint = player->GetViewpoint())
        {
            if (Creature* viewCreature = viewPoint->ToCreature())
                VisitNearbyCellsOf(viewCreature, grid_object_update, world_object_update);
            else if (DynamicObject* viewObject = viewPoint->ToDynObject())
                VisitNearbyCellsOf(viewObject, grid_object_update, world_object_update);
        }

        // Handle updates for creatures in combat with player and are more than 60 yards away
        if (player->IsInCombat())
        {
            std::vector<Creature*> updateList;
            HostileReference* ref = player->getHostileRefManager().getFirst();

            while (ref)
            {
                if (Unit* unit = ref->GetSource()->GetOwner())
                    if (unit->ToCreature() && unit->GetMapId() == player->GetMapId() && !unit->IsWithinDistInMap(player, GetVisibilityRange(), false))
                        updateList.push_back(unit->ToCreature());

                ref = ref->next();
            }

            // Process deferred update list for player
            for (Creature* c : updateList)
                VisitNearbyCellsOf(c, grid_object_update, world_object_update);
        }
    }

    // non-player active objects, increasing iterator in the loop in case of object removal
    for (m_activeNonPlayersIter = m_activeNonPlayers.begin(); m_activeNonPlayersIter != m_activeNonPlayers.end();)
    {
        WorldObject* obj = *m_activeNonPlayersIter;
        ++m_activeNonPlayersIter;

        if (!obj || !obj->IsInWorld())
            continue;

        VisitNearbyCellsOf(obj, grid_object_update, world_object_update);
    }

    for (_transportsUpdateIter = _transports.begin(); _transportsUpdateIter != _transports.end();)
    {
        WorldObject* obj = *_transportsUpdateIter;
        ++_transportsUpdateIter;

        if (!obj->IsInWorld())
            continue;

        obj->Update(t_diff);
    }

    SendObjectUpdates();

    ///- Process necessary scripts
    if (!m_scriptSchedule.empty())
    {
        i_scriptLock = true;
        ScriptsProcess();
        i_scriptLock = false;
    }

    if (_weatherUpdateTimer.Passed())
    {
        for (auto&& zoneInfo : _zoneDynamicInfo)
            if (zoneInfo.second.DefaultWeather && !zoneInfo.second.DefaultWeather->Update(_weatherUpdateTimer.GetInterval()))
                zoneInfo.second.DefaultWeather.reset();

        _weatherUpdateTimer.Reset();
    }

    MoveAllCreaturesInMoveList();
    MoveAllGameObjectsInMoveList();
    MoveAllAreaTriggersInMoveList();

    if (!m_mapRefManager.isEmpty() || !m_activeNonPlayers.empty())
        ProcessRelocationNotifies(t_diff);

    sScriptMgr->OnMapUpdate(this, t_diff);
}

struct ResetNotifier
{
    template<class T>inline void resetNotify(GridRefManager<T> &m)
    {
        for (typename GridRefManager<T>::iterator iter=m.begin(); iter != m.end(); ++iter)
            iter->GetSource()->ResetAllNotifies();
    }
    template<class T> void Visit(GridRefManager<T> &) { }
    void Visit(CreatureMapType &m) { resetNotify<Creature>(m);}
    void Visit(PlayerMapType &m) { resetNotify<Player>(m);}
};

void Map::ProcessRelocationNotifies(const uint32 diff)
{
    for (GridRefManager<NGridType>::iterator i = GridRefManager<NGridType>::begin(); i != GridRefManager<NGridType>::end(); ++i)
    {
        NGridType *grid = i->GetSource();

        if (grid->GetGridState() != GRID_STATE_ACTIVE)
            continue;

        grid->getGridInfoRef()->getRelocationTimer().TUpdate(diff);
        if (!grid->getGridInfoRef()->getRelocationTimer().TPassed())
            continue;

        uint32 gx = grid->getX(), gy = grid->getY();

        CellCoord cell_min(gx*MAX_NUMBER_OF_CELLS, gy*MAX_NUMBER_OF_CELLS);
        CellCoord cell_max(cell_min.x_coord + MAX_NUMBER_OF_CELLS, cell_min.y_coord+MAX_NUMBER_OF_CELLS);

        for (uint32 x = cell_min.x_coord; x < cell_max.x_coord; ++x)
        {
            for (uint32 y = cell_min.y_coord; y < cell_max.y_coord; ++y)
            {
                uint32 cell_id = (y * TOTAL_NUMBER_OF_CELLS_PER_MAP) + x;
                if (!isCellMarked(cell_id))
                    continue;

                CellCoord pair(x, y);
                Cell cell(pair);
                cell.SetNoCreate();

                Trinity::DelayedUnitRelocation cell_relocation(cell, pair, *this, MAX_VISIBILITY_DISTANCE);
                TypeContainerVisitor<Trinity::DelayedUnitRelocation, GridTypeMapContainer  > grid_object_relocation(cell_relocation);
                TypeContainerVisitor<Trinity::DelayedUnitRelocation, WorldTypeMapContainer > world_object_relocation(cell_relocation);
                Visit(cell, grid_object_relocation);
                Visit(cell, world_object_relocation);
            }
        }
    }

    ResetNotifier reset;
    TypeContainerVisitor<ResetNotifier, GridTypeMapContainer >  grid_notifier(reset);
    TypeContainerVisitor<ResetNotifier, WorldTypeMapContainer > world_notifier(reset);
    for (GridRefManager<NGridType>::iterator i = GridRefManager<NGridType>::begin(); i != GridRefManager<NGridType>::end(); ++i)
    {
        NGridType *grid = i->GetSource();

        if (grid->GetGridState() != GRID_STATE_ACTIVE)
            continue;

        if (!grid->getGridInfoRef()->getRelocationTimer().TPassed())
            continue;

        grid->getGridInfoRef()->getRelocationTimer().TReset(diff, m_VisibilityNotifyPeriod);

        uint32 gx = grid->getX(), gy = grid->getY();

        CellCoord cell_min(gx*MAX_NUMBER_OF_CELLS, gy*MAX_NUMBER_OF_CELLS);
        CellCoord cell_max(cell_min.x_coord + MAX_NUMBER_OF_CELLS, cell_min.y_coord+MAX_NUMBER_OF_CELLS);

        for (uint32 x = cell_min.x_coord; x < cell_max.x_coord; ++x)
        {
            for (uint32 y = cell_min.y_coord; y < cell_max.y_coord; ++y)
            {
                uint32 cell_id = (y * TOTAL_NUMBER_OF_CELLS_PER_MAP) + x;
                if (!isCellMarked(cell_id))
                    continue;

                CellCoord pair(x, y);
                Cell cell(pair);
                cell.SetNoCreate();
                Visit(cell, grid_notifier);
                Visit(cell, world_notifier);
            }
        }
    }
}

void Map::RemovePlayerFromMap(Player* player, bool remove)
{
    sScriptMgr->OnPlayerLeaveMap(this, player);

    player->RemoveFromWorld();
    SendRemoveTransports(player);

    player->UpdateObjectVisibility(true);
    if (player->IsInGrid())
        player->RemoveFromGrid();
    else
        ASSERT(remove); //maybe deleted in logoutplayer when player is not in a map

    if (remove)
        DeleteFromWorld(player);
}

template<class T>
void Map::RemoveFromMap(T *obj, bool remove)
{
    obj->RemoveFromWorld();
    if (obj->isActiveObject())
        RemoveFromActive(obj);

    obj->UpdateObjectVisibility(true);
    obj->RemoveFromGrid();

    obj->ResetMap();

    if (remove)
    {
        // if option set then object already saved at this moment
        if (!sWorld->getBoolConfig(CONFIG_SAVE_RESPAWN_TIME_IMMEDIATELY))
            obj->SaveRespawnTime();
        DeleteFromWorld(obj);
    }
}

template<>
void Map::RemoveFromMap(Transport* obj, bool remove)
{
    obj->RemoveFromWorld();

    Map::PlayerList const& players = GetPlayers();
    if (!players.isEmpty())
    {
        UpdateData data(GetId());
        obj->BuildOutOfRangeUpdateBlock(&data);
        WorldPacket packet;
        data.BuildPacket(&packet);
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            if (itr->GetSource()->GetTransport() != obj)
                itr->GetSource()->SendDirectMessage(&packet);
    }

    if (_transportsUpdateIter != _transports.end())
    {
        TransportsContainer::iterator itr = _transports.find(obj);
        if (itr == _transports.end())
            return;
        if (itr == _transportsUpdateIter)
            ++_transportsUpdateIter;
        _transports.erase(itr);
    }
    else
        _transports.erase(obj);

    obj->ResetMap();

    if (remove)
    {
        // if option set then object already saved at this moment
        if (!sWorld->getBoolConfig(CONFIG_SAVE_RESPAWN_TIME_IMMEDIATELY))
            obj->SaveRespawnTime();
        DeleteFromWorld(obj);
    }
}

void Map::PlayerRelocation(Player* player, float x, float y, float z, float orientation)
{
    ASSERT(player);

    Cell old_cell(player->GetPositionX(), player->GetPositionY());
    Cell new_cell(x, y);

    //! If hovering, always increase our server-side Z position
    //! Client automatically projects correct position based on Z coord sent in monster move
    //! and UNIT_FIELD_HOVERHEIGHT sent in object updates
    if (player->HasUnitMovementFlag(MOVEMENTFLAG_HOVER))
        z += player->GetFloatValue(UNIT_FIELD_HOVERHEIGHT);

    player->Relocate(x, y, z, orientation);
    if (player->IsVehicle())
        player->GetVehicleKit()->RelocatePassengers();

    if (old_cell.DiffGrid(new_cell) || old_cell.DiffCell(new_cell))
    {
        TC_LOG_DEBUG("maps", "Player %s relocation grid[%u, %u]cell[%u, %u]->grid[%u, %u]cell[%u, %u]", player->GetName().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());

        player->RemoveFromGrid();

        if (old_cell.DiffGrid(new_cell))
            EnsureGridLoadedForActiveObject(new_cell, player);

        AddToGrid(player, new_cell);
    }

    player->UpdateObjectVisibility(false);
}

void Map::CreatureRelocation(Creature* creature, float x, float y, float z, float ang, bool respawnRelocationOnFail)
{
    ASSERT(CheckGridIntegrity(creature, false));

    Cell old_cell = creature->GetCurrentCell();
    Cell new_cell(x, y);

    if (!respawnRelocationOnFail && !getNGrid(new_cell.GridX(), new_cell.GridY()))
        return;

    //! If hovering, always increase our server-side Z position
    //! Client automatically projects correct position based on Z coord sent in monster move
    //! and UNIT_FIELD_HOVERHEIGHT sent in object updates
    if (creature->HasUnitMovementFlag(MOVEMENTFLAG_HOVER))
        z += creature->GetFloatValue(UNIT_FIELD_HOVERHEIGHT);

    // delay creature move for grid/cell to grid/cell moves
    if (old_cell.DiffCell(new_cell) || old_cell.DiffGrid(new_cell))
    {
        #ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "Creature (%s Entry: %u) added to moving list from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", creature->GetGUID().ToString().c_str(), creature->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif
        AddCreatureToMoveList(creature, x, y, z, ang);
        // in diffcell/diffgrid case notifiers called at finishing move creature in Map::MoveAllCreaturesInMoveList
    }
    else
    {
        creature->Relocate(x, y, z, ang);
        if (creature->IsVehicle())
            creature->GetVehicleKit()->RelocatePassengers();
        creature->UpdateObjectVisibility(false);
        RemoveCreatureFromMoveList(creature);
    }

    ASSERT(CheckGridIntegrity(creature, true));
}

void Map::GameObjectRelocation(GameObject* go, float x, float y, float z, float orientation, bool respawnRelocationOnFail)
{
    Cell integrity_check(go->GetPositionX(), go->GetPositionY());
    Cell old_cell = go->GetCurrentCell();

    ASSERT(integrity_check == old_cell);
    Cell new_cell(x, y);

    if (!respawnRelocationOnFail && !getNGrid(new_cell.GridX(), new_cell.GridY()))
        return;

    // delay creature move for grid/cell to grid/cell moves
    if (old_cell.DiffCell(new_cell) || old_cell.DiffGrid(new_cell))
    {
#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "GameObject (%s Entry: %u) added to moving list from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), go->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif
        AddGameObjectToMoveList(go, x, y, z, orientation);
        // in diffcell/diffgrid case notifiers called at finishing move go in Map::MoveAllGameObjectsInMoveList
    }
    else
    {
        go->Relocate(x, y, z, orientation);
        go->UpdateModelPosition();
        go->UpdateObjectVisibility(false);
        RemoveGameObjectFromMoveList(go);
    }

    old_cell = go->GetCurrentCell();
    integrity_check = Cell(go->GetPositionX(), go->GetPositionY());
    ASSERT(integrity_check == old_cell);
}

void Map::DynamicObjectRelocation(DynamicObject* dynObj, float x, float y, float z, float orientation)
{
    Cell integrity_check(dynObj->GetPositionX(), dynObj->GetPositionY());
    Cell old_cell = dynObj->GetCurrentCell();

    ASSERT(integrity_check == old_cell);
    Cell new_cell(x, y);

    if (!getNGrid(new_cell.GridX(), new_cell.GridY()))
        return;

    // delay creature move for grid/cell to grid/cell moves
    if (old_cell.DiffCell(new_cell) || old_cell.DiffGrid(new_cell))
    {
#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "GameObject (%s) added to moving list from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", dynObj->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif
        AddDynamicObjectToMoveList(dynObj, x, y, z, orientation);
        // in diffcell/diffgrid case notifiers called at finishing move dynObj in Map::MoveAllGameObjectsInMoveList
    }
    else
    {
        dynObj->Relocate(x, y, z, orientation);
        dynObj->UpdateObjectVisibility(false);
        RemoveDynamicObjectFromMoveList(dynObj);
    }

    old_cell = dynObj->GetCurrentCell();
    integrity_check = Cell(dynObj->GetPositionX(), dynObj->GetPositionY());
    ASSERT(integrity_check == old_cell);
}

void Map::AreaTriggerRelocation(AreaTrigger* at, float x, float y, float z, float orientation)
{
    Cell integrity_check(at->GetPositionX(), at->GetPositionY());
    Cell old_cell = at->GetCurrentCell();

    ASSERT(integrity_check == old_cell);
    Cell new_cell(x, y);

    if (!getNGrid(new_cell.GridX(), new_cell.GridY()))
        return;

    // delay areatrigger move for grid/cell to grid/cell moves
    if (old_cell.DiffCell(new_cell) || old_cell.DiffGrid(new_cell))
    {
#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "AreaTrigger (%s) added to moving list from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", at->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif
        AddAreaTriggerToMoveList(at, x, y, z, orientation);
        // in diffcell/diffgrid case notifiers called at finishing move at in Map::MoveAllAreaTriggersInMoveList
    }
    else
    {
        at->Relocate(x, y, z, orientation);
        at->UpdateShape();
        at->UpdateObjectVisibility(false);
        RemoveAreaTriggerFromMoveList(at);
    }

    old_cell = at->GetCurrentCell();
    integrity_check = Cell(at->GetPositionX(), at->GetPositionY());
    ASSERT(integrity_check == old_cell);
}

void Map::AddCreatureToMoveList(Creature* c, float x, float y, float z, float ang)
{
    if (_creatureToMoveLock) //can this happen?
        return;

    if (c->_moveState == MAP_OBJECT_CELL_MOVE_NONE)
        _creaturesToMove.push_back(c);
    c->SetNewCellPosition(x, y, z, ang);
}

void Map::RemoveCreatureFromMoveList(Creature* c)
{
    if (_creatureToMoveLock) //can this happen?
        return;

    if (c->_moveState == MAP_OBJECT_CELL_MOVE_ACTIVE)
        c->_moveState = MAP_OBJECT_CELL_MOVE_INACTIVE;
}

void Map::AddGameObjectToMoveList(GameObject* go, float x, float y, float z, float ang)
{
    if (_gameObjectsToMoveLock) //can this happen?
        return;

    if (go->_moveState == MAP_OBJECT_CELL_MOVE_NONE)
        _gameObjectsToMove.push_back(go);
    go->SetNewCellPosition(x, y, z, ang);
}

void Map::RemoveGameObjectFromMoveList(GameObject* go)
{
    if (_gameObjectsToMoveLock) //can this happen?
        return;

    if (go->_moveState == MAP_OBJECT_CELL_MOVE_ACTIVE)
        go->_moveState = MAP_OBJECT_CELL_MOVE_INACTIVE;
}

void Map::AddDynamicObjectToMoveList(DynamicObject* dynObj, float x, float y, float z, float ang)
{
    if (_dynamicObjectsToMoveLock) //can this happen?
        return;

    if (dynObj->_moveState == MAP_OBJECT_CELL_MOVE_NONE)
        _dynamicObjectsToMove.push_back(dynObj);
    dynObj->SetNewCellPosition(x, y, z, ang);
}

void Map::RemoveDynamicObjectFromMoveList(DynamicObject* dynObj)
{
    if (_dynamicObjectsToMoveLock) //can this happen?
        return;

    if (dynObj->_moveState == MAP_OBJECT_CELL_MOVE_ACTIVE)
        dynObj->_moveState = MAP_OBJECT_CELL_MOVE_INACTIVE;
}

void Map::AddAreaTriggerToMoveList(AreaTrigger* at, float x, float y, float z, float ang)
{
    if (_areaTriggersToMoveLock) //can this happen?
        return;

    if (at->_moveState == MAP_OBJECT_CELL_MOVE_NONE)
        _areaTriggersToMove.push_back(at);
    at->SetNewCellPosition(x, y, z, ang);
}

void Map::RemoveAreaTriggerFromMoveList(AreaTrigger* at)
{
    if (_areaTriggersToMoveLock) //can this happen?
        return;

    if (at->_moveState == MAP_OBJECT_CELL_MOVE_ACTIVE)
        at->_moveState = MAP_OBJECT_CELL_MOVE_INACTIVE;
}

void Map::MoveAllCreaturesInMoveList()
{
    _creatureToMoveLock = true;
    for (std::vector<Creature*>::iterator itr = _creaturesToMove.begin(); itr != _creaturesToMove.end(); ++itr)
    {
        Creature* c = *itr;
        if (c->FindMap() != this) //pet is teleported to another map
            continue;

        if (c->_moveState != MAP_OBJECT_CELL_MOVE_ACTIVE)
        {
            c->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
            continue;
        }

        c->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
        if (!c->IsInWorld())
            continue;

        // do move or do move to respawn or remove creature if previous all fail
        if (CreatureCellRelocation(c, Cell(c->_newPosition.m_positionX, c->_newPosition.m_positionY)))
        {
            // update pos
            c->Relocate(c->_newPosition);
            if (c->IsVehicle())
                c->GetVehicleKit()->RelocatePassengers();
            //CreatureRelocationNotify(c, new_cell, new_cell.cellCoord());
            c->UpdateObjectVisibility(false);
        }
        else
        {
            // if creature can't be move in new cell/grid (not loaded) move it to repawn cell/grid
            // creature coordinates will be updated and notifiers send
            if (!CreatureRespawnRelocation(c, false))
            {
                // ... or unload (if respawn grid also not loaded)
                #ifdef TRINITY_DEBUG
                TC_LOG_DEBUG("maps", "Creature (%s Entry: %u) cannot be move to unloaded respawn grid.", c->GetGUID().ToString().c_str(), c->GetEntry());
                #endif
                //AddObjectToRemoveList(Pet*) should only be called in Pet::Remove
                //This may happen when a player just logs in and a pet moves to a nearby unloaded cell
                //To avoid this, we can load nearby cells when player log in
                //But this check is always needed to ensure safety
                /// @todo pets will disappear if this is outside CreatureRespawnRelocation
                //need to check why pet is frequently relocated to an unloaded cell
                if (c->IsPet())
                    ((Pet*)c)->Remove(PET_SAVE_NOT_IN_SLOT, true);
                else
                    AddObjectToRemoveList(c);
            }
        }
    }
    _creaturesToMove.clear();
    _creatureToMoveLock = false;
}

void Map::MoveAllGameObjectsInMoveList()
{
    _gameObjectsToMoveLock = true;
    for (std::vector<GameObject*>::iterator itr = _gameObjectsToMove.begin(); itr != _gameObjectsToMove.end(); ++itr)
    {
        GameObject* go = *itr;
        if (go->FindMap() != this) //transport is teleported to another map
            continue;

        if (go->_moveState != MAP_OBJECT_CELL_MOVE_ACTIVE)
        {
            go->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
            continue;
        }

        go->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
        if (!go->IsInWorld())
            continue;

        // do move or do move to respawn or remove creature if previous all fail
        if (GameObjectCellRelocation(go, Cell(go->_newPosition.m_positionX, go->_newPosition.m_positionY)))
        {
            // update pos
            go->Relocate(go->_newPosition);
            go->UpdateModelPosition();
            go->UpdateObjectVisibility(false);
        }
        else
        {
            // if GameObject can't be move in new cell/grid (not loaded) move it to repawn cell/grid
            // GameObject coordinates will be updated and notifiers send
            if (!GameObjectRespawnRelocation(go, false))
            {
                // ... or unload (if respawn grid also not loaded)
#ifdef TRINITY_DEBUG
                TC_LOG_DEBUG("maps", "GameObject (%s Entry: %u) cannot be move to unloaded respawn grid.", go->GetGUID().ToString().c_str(), go->GetEntry());
#endif
                AddObjectToRemoveList(go);
            }
        }
    }
    _gameObjectsToMove.clear();
    _gameObjectsToMoveLock = false;
}

void Map::MoveAllDynamicObjectsInMoveList()
{
    _dynamicObjectsToMoveLock = true;
    for (std::vector<DynamicObject*>::iterator itr = _dynamicObjectsToMove.begin(); itr != _dynamicObjectsToMove.end(); ++itr)
    {
        DynamicObject* dynObj = *itr;
        if (dynObj->FindMap() != this) //transport is teleported to another map
            continue;

        if (dynObj->_moveState != MAP_OBJECT_CELL_MOVE_ACTIVE)
        {
            dynObj->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
            continue;
        }

        dynObj->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
        if (!dynObj->IsInWorld())
            continue;

        // do move or do move to respawn or remove creature if previous all fail
        if (DynamicObjectCellRelocation(dynObj, Cell(dynObj->_newPosition.m_positionX, dynObj->_newPosition.m_positionY)))
        {
            // update pos
            dynObj->Relocate(dynObj->_newPosition);
            dynObj->UpdateObjectVisibility(false);
        }
        else
        {
#ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "DynamicObject (%s) cannot be moved to unloaded grid.", dynObj->GetGUID().ToString().c_str());
#endif
        }
    }

    _dynamicObjectsToMove.clear();
    _dynamicObjectsToMoveLock = false;
}

void Map::MoveAllAreaTriggersInMoveList()
{
    _areaTriggersToMoveLock = true;
    for (std::vector<AreaTrigger*>::iterator itr = _areaTriggersToMove.begin(); itr != _areaTriggersToMove.end(); ++itr)
    {
        AreaTrigger* at = *itr;
        if (at->FindMap() != this) //transport is teleported to another map
            continue;

        if (at->_moveState != MAP_OBJECT_CELL_MOVE_ACTIVE)
        {
            at->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
            continue;
        }

        at->_moveState = MAP_OBJECT_CELL_MOVE_NONE;
        if (!at->IsInWorld())
            continue;

        // do move or do move to respawn or remove creature if previous all fail
        if (AreaTriggerCellRelocation(at, Cell(at->_newPosition.m_positionX, at->_newPosition.m_positionY)))
        {
            // update pos
            at->Relocate(at->_newPosition);
            at->UpdateObjectVisibility(false);
        }
        else
        {
#ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "AreaTrigger (%s) cannot be moved to unloaded grid.", at->GetGUID().ToString().c_str());
#endif
        }
    }

    _areaTriggersToMove.clear();
    _areaTriggersToMoveLock = false;
}

bool Map::CreatureCellRelocation(Creature* c, Cell new_cell)
{
    Cell const& old_cell = c->GetCurrentCell();
    if (!old_cell.DiffGrid(new_cell))                       // in same grid
    {
        // if in same cell then none do
        if (old_cell.DiffCell(new_cell))
        {
            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "Creature (%s Entry: %u) moved in grid[%u, %u] from cell[%u, %u] to cell[%u, %u].", c->GetGUID().ToString().c_str(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.CellX(), new_cell.CellY());
            #endif

            c->RemoveFromGrid();
            AddToGrid(c, new_cell);
        }
        else
        {
            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "Creature (%s Entry: %u) moved in same grid[%u, %u]cell[%u, %u].", c->GetGUID().ToString().c_str(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY());
            #endif
        }

        return true;
    }

    // in diff. grids but active creature
    if (c->isActiveObject())
    {
        EnsureGridLoadedForActiveObject(new_cell, c);

        #ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "Active creature (%s Entry: %u) moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", c->GetGUID().ToString().c_str(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif

        c->RemoveFromGrid();
        AddToGrid(c, new_cell);

        return true;
    }

    // in diff. loaded grid normal creature
    if (IsGridLoaded(GridCoord(new_cell.GridX(), new_cell.GridY())))
    {
        #ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "Creature (%s Entry: %u) moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", c->GetGUID().ToString().c_str(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif

        c->RemoveFromGrid();
        EnsureGridCreated(GridCoord(new_cell.GridX(), new_cell.GridY()));
        AddToGrid(c, new_cell);

        return true;
    }

    // fail to move: normal creature attempt move to unloaded grid
    #ifdef TRINITY_DEBUG
    TC_LOG_DEBUG("maps", "Creature (%s Entry: %u) attempted to move from grid[%u, %u]cell[%u, %u] to unloaded grid[%u, %u]cell[%u, %u].", c->GetGUID().ToString().c_str(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
    #endif
    return false;
}

bool Map::GameObjectCellRelocation(GameObject* go, Cell new_cell)
{
    Cell const& old_cell = go->GetCurrentCell();
    if (!old_cell.DiffGrid(new_cell))                       // in same grid
    {
        // if in same cell then none do
        if (old_cell.DiffCell(new_cell))
        {
            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "GameObject (%s Entry: %u) moved in grid[%u, %u] from cell[%u, %u] to cell[%u, %u].", go->GetGUID().ToString().c_str(), go->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.CellX(), new_cell.CellY());
            #endif

            go->RemoveFromGrid();
            AddToGrid(go, new_cell);
        }
        else
        {
            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "GameObject (%s Entry: %u) moved in same grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), go->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY());
            #endif
        }

        return true;
    }

    // in diff. grids but active GameObject
    if (go->isActiveObject())
    {
        EnsureGridLoadedForActiveObject(new_cell, go);

        #ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "Active GameObject (%s Entry: %u) moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), go->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif

        go->RemoveFromGrid();
        AddToGrid(go, new_cell);

        return true;
    }

    // in diff. loaded grid normal GameObject
    if (IsGridLoaded(GridCoord(new_cell.GridX(), new_cell.GridY())))
    {
        #ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "GameObject (%s Entry: %u) moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), go->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif

        go->RemoveFromGrid();
        EnsureGridCreated(GridCoord(new_cell.GridX(), new_cell.GridY()));
        AddToGrid(go, new_cell);

        return true;
    }

    // fail to move: normal GameObject attempt move to unloaded grid
    #ifdef TRINITY_DEBUG
    TC_LOG_DEBUG("maps", "GameObject (%s Entry: %u) attempted to move from grid[%u, %u]cell[%u, %u] to unloaded grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), go->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
    #endif
    return false;
}

bool Map::DynamicObjectCellRelocation(DynamicObject* go, Cell new_cell)
{
    Cell const& old_cell = go->GetCurrentCell();
    if (!old_cell.DiffGrid(new_cell))                       // in same grid
    {
        // if in same cell then none do
        if (old_cell.DiffCell(new_cell))
        {
            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "DynamicObject (%s) moved in grid[%u, %u] from cell[%u, %u] to cell[%u, %u].", go->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.CellX(), new_cell.CellY());
            #endif

            go->RemoveFromGrid();
            AddToGrid(go, new_cell);
        }
        else
        {
            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "DynamicObject (%s) moved in same grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY());
            #endif
        }

        return true;
    }

    // in diff. grids but active GameObject
    if (go->isActiveObject())
    {
        EnsureGridLoadedForActiveObject(new_cell, go);

        #ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "Active DynamicObject (%s) moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif

        go->RemoveFromGrid();
        AddToGrid(go, new_cell);

        return true;
    }

    // in diff. loaded grid normal GameObject
    if (IsGridLoaded(GridCoord(new_cell.GridX(), new_cell.GridY())))
    {
        #ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "DynamicObject (%s) moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif

        go->RemoveFromGrid();
        EnsureGridCreated(GridCoord(new_cell.GridX(), new_cell.GridY()));
        AddToGrid(go, new_cell);

        return true;
    }

    // fail to move: normal GameObject attempt move to unloaded grid
    #ifdef TRINITY_DEBUG
    TC_LOG_DEBUG("maps", "DynamicObject (%s) attempted to move from grid[%u, %u]cell[%u, %u] to unloaded grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
    #endif
    return false;
}

bool Map::AreaTriggerCellRelocation(AreaTrigger* at, Cell new_cell)
{
    Cell const& old_cell = at->GetCurrentCell();
    if (!old_cell.DiffGrid(new_cell))                       // in same grid
    {
        // if in same cell then none do
        if (old_cell.DiffCell(new_cell))
        {
#ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "AreaTrigger (%s) moved in grid[%u, %u] from cell[%u, %u] to cell[%u, %u].", at->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.CellX(), new_cell.CellY());
#endif

            at->RemoveFromGrid();
            AddToGrid(at, new_cell);
        }
        else
        {
#ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "AreaTrigger (%s) moved in same grid[%u, %u]cell[%u, %u].", at->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY());
#endif
        }

        return true;
    }

    // in diff. grids but active AreaTrigger
    if (at->isActiveObject())
    {
        EnsureGridLoadedForActiveObject(new_cell, at);

#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "Active AreaTrigger (%s) moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", at->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif

        at->RemoveFromGrid();
        AddToGrid(at, new_cell);

        return true;
    }

    // in diff. loaded grid normal AreaTrigger
    if (IsGridLoaded(GridCoord(new_cell.GridX(), new_cell.GridY())))
    {
#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "AreaTrigger (%s) moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", at->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif

        at->RemoveFromGrid();
        EnsureGridCreated(GridCoord(new_cell.GridX(), new_cell.GridY()));
        AddToGrid(at, new_cell);

        return true;
    }

    // fail to move: normal AreaTrigger attempt move to unloaded grid
#ifdef TRINITY_DEBUG
    TC_LOG_DEBUG("maps", "AreaTrigger (%s) attempted to move from grid[%u, %u]cell[%u, %u] to unloaded grid[%u, %u]cell[%u, %u].", at->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif
    return false;
}

bool Map::CreatureRespawnRelocation(Creature* c, bool diffGridOnly)
{
    float resp_x, resp_y, resp_z, resp_o;
    c->GetRespawnPosition(resp_x, resp_y, resp_z, &resp_o);
    Cell resp_cell(resp_x, resp_y);

    //creature will be unloaded with grid
    if (diffGridOnly && !c->GetCurrentCell().DiffGrid(resp_cell))
        return true;

    c->CombatStop();
    c->GetMotionMaster()->Clear();

    #ifdef TRINITY_DEBUG
    TC_LOG_DEBUG("maps", "Creature (%s Entry: %u) moved from grid[%u, %u]cell[%u, %u] to respawn grid[%u, %u]cell[%u, %u].", c->GetGUID().ToString().c_str(), c->GetEntry(), c->GetCurrentCell().GridX(), c->GetCurrentCell().GridY(), c->GetCurrentCell().CellX(), c->GetCurrentCell().CellY(), resp_cell.GridX(), resp_cell.GridY(), resp_cell.CellX(), resp_cell.CellY());
    #endif

    // teleport it to respawn point (like normal respawn if player see)
    if (CreatureCellRelocation(c, resp_cell))
    {
        c->Relocate(resp_x, resp_y, resp_z, resp_o);
        c->GetMotionMaster()->Initialize();                 // prevent possible problems with default move generators
        //CreatureRelocationNotify(c, resp_cell, resp_cell.GetCellCoord());
        c->UpdateObjectVisibility(false);
        return true;
    }

    return false;
}

bool Map::GameObjectRespawnRelocation(GameObject* go, bool diffGridOnly)
{
    float resp_x, resp_y, resp_z, resp_o;
    go->GetRespawnPosition(resp_x, resp_y, resp_z, &resp_o);
    Cell resp_cell(resp_x, resp_y);

    //GameObject will be unloaded with grid
    if (diffGridOnly && !go->GetCurrentCell().DiffGrid(resp_cell))
        return true;

    #ifdef TRINITY_DEBUG
    TC_LOG_DEBUG("maps", "GameObject (%s Entry: %u) moved from grid[%u, %u]cell[%u, %u] to respawn grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), go->GetEntry(), go->GetCurrentCell().GridX(), go->GetCurrentCell().GridY(), go->GetCurrentCell().CellX(), go->GetCurrentCell().CellY(), resp_cell.GridX(), resp_cell.GridY(), resp_cell.CellX(), resp_cell.CellY());
    #endif

    // teleport it to respawn point (like normal respawn if player see)
    if (GameObjectCellRelocation(go, resp_cell))
    {
        go->Relocate(resp_x, resp_y, resp_z, resp_o);
        go->UpdateObjectVisibility(false);
        return true;
    }

    return false;
}

bool Map::UnloadGrid(NGridType& ngrid, bool unloadAll)
{
    const uint32 x = ngrid.getX();
    const uint32 y = ngrid.getY();

    {
        if (!unloadAll)
        {
            //pets, possessed creatures (must be active), transport passengers
            if (ngrid.GetWorldObjectCountInNGrid<Creature>())
                return false;

            if (ActiveObjectsNearGrid(ngrid))
                return false;
        }

        TC_LOG_DEBUG("maps", "Unloading grid[%u, %u] for map %u", x, y, GetId());

        if (!unloadAll)
        {
            // Finish creature moves, remove and delete all creatures with delayed remove before moving to respawn grids
            // Must know real mob position before move
            MoveAllCreaturesInMoveList();
            MoveAllGameObjectsInMoveList();
            MoveAllAreaTriggersInMoveList();

            // move creatures to respawn grids if this is diff.grid or to remove list
            ObjectGridEvacuator worker;
            TypeContainerVisitor<ObjectGridEvacuator, GridTypeMapContainer> visitor(worker);
            ngrid.VisitAllGrids(visitor);

            // Finish creature moves, remove and delete all creatures with delayed remove before unload
            MoveAllCreaturesInMoveList();
            MoveAllGameObjectsInMoveList();
            MoveAllAreaTriggersInMoveList();
        }

        {
            ObjectGridCleaner worker;
            TypeContainerVisitor<ObjectGridCleaner, GridTypeMapContainer> visitor(worker);
            ngrid.VisitAllGrids(visitor);
        }

        RemoveAllObjectsInRemoveList();

        {
            ObjectGridUnloader worker;
            TypeContainerVisitor<ObjectGridUnloader, GridTypeMapContainer> visitor(worker);
            ngrid.VisitAllGrids(visitor);
        }

        ASSERT(i_objectsToRemove.empty());

        delete &ngrid;
        setNGrid(NULL, x, y);
    }
    int gx = (MAX_NUMBER_OF_GRIDS - 1) - x;
    int gy = (MAX_NUMBER_OF_GRIDS - 1) - y;

    // delete grid map, but don't delete if it is from parent map (and thus only reference)
    //+++if (GridMaps[gx][gy]) don't check for GridMaps[gx][gy], we might have to unload vmaps
    {
        if (i_InstanceId == 0)
        {
            if (GridMaps[gx][gy])
            {
                GridMaps[gx][gy]->unloadData();
                delete GridMaps[gx][gy];
            }
            VMAP::VMapFactory::createOrGetVMapManager()->unloadMap(GetId(), gx, gy);
            MMAP::MMapFactory::createOrGetMMapManager()->unloadMap(GetId(), gx, gy);
        }
        else
            ((MapInstanced*)m_parentMap)->RemoveGridMapReference(GridCoord(gx, gy));

        GridMaps[gx][gy] = NULL;
    }
    TC_LOG_DEBUG("maps", "Unloading grid[%u, %u] for map %u finished", x, y, GetId());
    return true;
}

void Map::RemoveAllPlayers()
{
    if (HavePlayers())
    {
        for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        {
            Player* player = itr->GetSource();
            if (!player->IsBeingTeleportedFar())
            {
                // this is happening for bg
                TC_LOG_ERROR("maps", "Map::UnloadAll: player %s is still in map %u during unload, this should not happen!", player->GetName().c_str(), GetId());
                player->TeleportTo(player->m_homebindMapId, player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation());
            }
        }
    }
}

void Map::UnloadAll()
{
    // clear all delayed moves, useless anyway do this moves before map unload.
    _creaturesToMove.clear();
    _gameObjectsToMove.clear();

    for (GridRefManager<NGridType>::iterator i = GridRefManager<NGridType>::begin(); i != GridRefManager<NGridType>::end();)
    {
        NGridType &grid(*i->GetSource());
        ++i;
        UnloadGrid(grid, true);       // deletes the grid and removes it from the GridRefManager
    }

    for (TransportsContainer::iterator itr = _transports.begin(); itr != _transports.end();)
    {
        Transport* transport = *itr;
        ++itr;

        RemoveFromMap<Transport>(transport, true);
    }

    for (auto& cellCorpsePair : _corpsesByCell)
    {
        for (Corpse* corpse : cellCorpsePair.second)
        {
            corpse->RemoveFromWorld();
            corpse->ResetMap();
            delete corpse;
        }
    }

    _corpsesByCell.clear();
    _corpsesByPlayer.clear();
    _corpseBones.clear();
}

// *****************************
// Grid function
// *****************************
GridMap::GridMap()
{
    _flags = 0;
    // Area data
    _gridArea = 0;
    _areaMap = nullptr;
    // Height level data
    _gridHeight = INVALID_HEIGHT;
    _gridGetHeight = &GridMap::getHeightFromFlat;
    _gridIntHeightMultiplier = 0;
    m_V9 = nullptr;
    m_V8 = nullptr;
    _maxHeight = nullptr;
    _minHeight = nullptr;
    // Liquid data
    _liquidType    = 0;
    _liquidOffX   = 0;
    _liquidOffY   = 0;
    _liquidWidth  = 0;
    _liquidHeight = 0;
    _liquidLevel = INVALID_HEIGHT;
    _liquidEntry = nullptr;
    _liquidFlags = nullptr;
    _liquidMap  = nullptr;
}

GridMap::~GridMap()
{
    unloadData();
}

bool GridMap::loadData(const char* filename)
{
    // Unload old data if exist
    unloadData();

    map_fileheader header;
    // Not return error if file not found
    FILE* in = fopen(filename, "rb");
    if (!in)
        return true;

    if (fread(&header, sizeof(header), 1, in) != 1)
    {
        fclose(in);
        return false;
    }

    if (header.mapMagic.asUInt == MapMagic.asUInt && header.versionMagic.asUInt == MapVersionMagic.asUInt)
    {
        // load up area data
        if (header.areaMapOffset && !loadAreaData(in, header.areaMapOffset, header.areaMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map area data\n");
            fclose(in);
            return false;
        }
        // load up height data
        if (header.heightMapOffset && !loadHeightData(in, header.heightMapOffset, header.heightMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map height data\n");
            fclose(in);
            return false;
        }
        // load up liquid data
        if (header.liquidMapOffset && !loadLiquidData(in, header.liquidMapOffset, header.liquidMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map liquids data\n");
            fclose(in);
            return false;
        }
        fclose(in);
        return true;
    }

    TC_LOG_ERROR("maps", "Map file '%s' is from an incompatible map version (%.*s %.*s), %.*s %.*s is expected. Please pull your source, recompile tools and recreate maps using the updated mapextractor, then replace your old map files with new files. If you still have problems search on forum for error TCE00018.",
        filename, 4, header.mapMagic.asChar, 4, header.versionMagic.asChar, 4, MapMagic.asChar, 4, MapVersionMagic.asChar);
    fclose(in);
    return false;
}

void GridMap::unloadData()
{
    delete[] _areaMap;
    delete[] m_V9;
    delete[] m_V8;
    delete[] _maxHeight;
    delete[] _minHeight;
    delete[] _liquidEntry;
    delete[] _liquidFlags;
    delete[] _liquidMap;
    _areaMap = nullptr;
    m_V9 = nullptr;
    m_V8 = nullptr;
    _maxHeight = nullptr;
    _minHeight = nullptr;
    _liquidEntry = nullptr;
    _liquidFlags = nullptr;
    _liquidMap  = nullptr;
    _gridGetHeight = &GridMap::getHeightFromFlat;
}

bool GridMap::loadAreaData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_areaHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.fourcc != MapAreaMagic.asUInt)
        return false;

    _gridArea = header.gridArea;
    if (!(header.flags & MAP_AREA_NO_AREA))
    {
        _areaMap = new uint16[16 * 16];
        if (fread(_areaMap, sizeof(uint16), 16*16, in) != 16*16)
            return false;
    }
    return true;
}

bool GridMap::loadHeightData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_heightHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.fourcc != MapHeightMagic.asUInt)
        return false;

    _gridHeight = header.gridHeight;
    if (!(header.flags & MAP_HEIGHT_NO_HEIGHT))
    {
        if ((header.flags & MAP_HEIGHT_AS_INT16))
        {
            m_uint16_V9 = new uint16 [129*129];
            m_uint16_V8 = new uint16 [128*128];
            if (fread(m_uint16_V9, sizeof(uint16), 129*129, in) != 129*129 ||
                fread(m_uint16_V8, sizeof(uint16), 128*128, in) != 128*128)
                return false;
            _gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 65535;
            _gridGetHeight = &GridMap::getHeightFromUint16;
        }
        else if ((header.flags & MAP_HEIGHT_AS_INT8))
        {
            m_uint8_V9 = new uint8 [129*129];
            m_uint8_V8 = new uint8 [128*128];
            if (fread(m_uint8_V9, sizeof(uint8), 129*129, in) != 129*129 ||
                fread(m_uint8_V8, sizeof(uint8), 128*128, in) != 128*128)
                return false;
            _gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 255;
            _gridGetHeight = &GridMap::getHeightFromUint8;
        }
        else
        {
            m_V9 = new float [129*129];
            m_V8 = new float [128*128];
            if (fread(m_V9, sizeof(float), 129*129, in) != 129*129 ||
                fread(m_V8, sizeof(float), 128*128, in) != 128*128)
                return false;
            _gridGetHeight = &GridMap::getHeightFromFloat;
        }
    }
    else
        _gridGetHeight = &GridMap::getHeightFromFlat;

    if (header.flags & MAP_HEIGHT_HAS_FLIGHT_BOUNDS)
    {
        _maxHeight = new int16[3 * 3];
        _minHeight = new int16[3 * 3];
        if (fread(_maxHeight, sizeof(int16), 3 * 3, in) != 3 * 3 ||
            fread(_minHeight, sizeof(int16), 3 * 3, in) != 3 * 3)
            return false;
    }

    return true;
}

bool GridMap::loadLiquidData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_liquidHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.fourcc != MapLiquidMagic.asUInt)
        return false;

    _liquidType   = header.liquidType;
    _liquidOffX  = header.offsetX;
    _liquidOffY  = header.offsetY;
    _liquidWidth = header.width;
    _liquidHeight = header.height;
    _liquidLevel  = header.liquidLevel;

    if (!(header.flags & MAP_LIQUID_NO_TYPE))
    {
        _liquidEntry = new uint16[16*16];
        if (fread(_liquidEntry, sizeof(uint16), 16*16, in) != 16*16)
            return false;

        _liquidFlags = new uint8[16*16];
        if (fread(_liquidFlags, sizeof(uint8), 16*16, in) != 16*16)
            return false;
    }
    if (!(header.flags & MAP_LIQUID_NO_HEIGHT))
    {
        _liquidMap = new float[uint32(_liquidWidth) * uint32(_liquidHeight)];
        if (fread(_liquidMap, sizeof(float), _liquidWidth*_liquidHeight, in) != (uint32(_liquidWidth) * uint32(_liquidHeight)))
            return false;
    }
    return true;
}

uint16 GridMap::getArea(float x, float y) const
{
    if (!_areaMap)
        return _gridArea;

    x = 16 * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = 16 * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);
    int lx = (int)x & 15;
    int ly = (int)y & 15;
    return _areaMap[lx*16 + ly];
}

float GridMap::getHeightFromFlat(float /*x*/, float /*y*/) const
{
    return _gridHeight;
}

float GridMap::getHeightFromFloat(float x, float y) const
{
    if (!m_V8 || !m_V9)
        return _gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);

    // Height stored as: h5 - its v8 grid, h1-h4 - its v9 grid
    // +--------------> X
    // | h1-------h2     Coordinates is:
    // | | \  1  / |     h1 0, 0
    // | |  \   /  |     h2 0, 1
    // | | 2  h5 3 |     h3 1, 0
    // | |  /   \  |     h4 1, 1
    // | | /  4  \ |     h5 1/2, 1/2
    // | h3-------h4
    // V Y
    // For find height need
    // 1 - detect triangle
    // 2 - solve linear equation from triangle points
    // Calculate coefficients for solve h = a*x + b*y + c

    float a, b, c;
    // Select triangle:
    if (x+y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            float h1 = m_V9[(x_int)*129 + y_int];
            float h2 = m_V9[(x_int+1)*129 + y_int];
            float h5 = 2 * m_V8[x_int*128 + y_int];
            a = h2-h1;
            b = h5-h1-h2;
            c = h1;
        }
        else
        {
            // 2 triangle (h1, h3, h5 points)
            float h1 = m_V9[x_int*129 + y_int  ];
            float h3 = m_V9[x_int*129 + y_int+1];
            float h5 = 2 * m_V8[x_int*128 + y_int];
            a = h5 - h1 - h3;
            b = h3 - h1;
            c = h1;
        }
    }
    else
    {
        if (x > y)
        {
            // 3 triangle (h2, h4, h5 points)
            float h2 = m_V9[(x_int+1)*129 + y_int  ];
            float h4 = m_V9[(x_int+1)*129 + y_int+1];
            float h5 = 2 * m_V8[x_int*128 + y_int];
            a = h2 + h4 - h5;
            b = h4 - h2;
            c = h5 - h4;
        }
        else
        {
            // 4 triangle (h3, h4, h5 points)
            float h3 = m_V9[(x_int)*129 + y_int+1];
            float h4 = m_V9[(x_int+1)*129 + y_int+1];
            float h5 = 2 * m_V8[x_int*128 + y_int];
            a = h4 - h3;
            b = h3 + h4 - h5;
            c = h5 - h4;
        }
    }
    // Calculate height
    return a * x + b * y + c;
}

float GridMap::getHeightFromUint8(float x, float y) const
{
    if (!m_uint8_V8 || !m_uint8_V9)
        return _gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);

    int32 a, b, c;
    uint8 *V9_h1_ptr = &m_uint8_V9[x_int*128 + x_int + y_int];
    if (x+y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            int32 h1 = V9_h1_ptr[  0];
            int32 h2 = V9_h1_ptr[129];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h2-h1;
            b = h5-h1-h2;
            c = h1;
        }
        else
        {
            // 2 triangle (h1, h3, h5 points)
            int32 h1 = V9_h1_ptr[0];
            int32 h3 = V9_h1_ptr[1];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h5 - h1 - h3;
            b = h3 - h1;
            c = h1;
        }
    }
    else
    {
        if (x > y)
        {
            // 3 triangle (h2, h4, h5 points)
            int32 h2 = V9_h1_ptr[129];
            int32 h4 = V9_h1_ptr[130];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h2 + h4 - h5;
            b = h4 - h2;
            c = h5 - h4;
        }
        else
        {
            // 4 triangle (h3, h4, h5 points)
            int32 h3 = V9_h1_ptr[  1];
            int32 h4 = V9_h1_ptr[130];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h4 - h3;
            b = h3 + h4 - h5;
            c = h5 - h4;
        }
    }
    // Calculate height
    return (float)((a * x) + (b * y) + c)*_gridIntHeightMultiplier + _gridHeight;
}

float GridMap::getHeightFromUint16(float x, float y) const
{
    if (!m_uint16_V8 || !m_uint16_V9)
        return _gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);

    int32 a, b, c;
    uint16 *V9_h1_ptr = &m_uint16_V9[x_int*128 + x_int + y_int];
    if (x+y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            int32 h1 = V9_h1_ptr[  0];
            int32 h2 = V9_h1_ptr[129];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h2-h1;
            b = h5-h1-h2;
            c = h1;
        }
        else
        {
            // 2 triangle (h1, h3, h5 points)
            int32 h1 = V9_h1_ptr[0];
            int32 h3 = V9_h1_ptr[1];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h5 - h1 - h3;
            b = h3 - h1;
            c = h1;
        }
    }
    else
    {
        if (x > y)
        {
            // 3 triangle (h2, h4, h5 points)
            int32 h2 = V9_h1_ptr[129];
            int32 h4 = V9_h1_ptr[130];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h2 + h4 - h5;
            b = h4 - h2;
            c = h5 - h4;
        }
        else
        {
            // 4 triangle (h3, h4, h5 points)
            int32 h3 = V9_h1_ptr[  1];
            int32 h4 = V9_h1_ptr[130];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h4 - h3;
            b = h3 + h4 - h5;
            c = h5 - h4;
        }
    }
    // Calculate height
    return (float)((a * x) + (b * y) + c)*_gridIntHeightMultiplier + _gridHeight;
}

float GridMap::getMinHeight(float x, float y) const
{
    if (!_minHeight)
        return -500.0f;

    static uint32 const indices[] =
    {
        3, 0, 4,
        0, 1, 4,
        1, 2, 4,
        2, 5, 4,
        5, 8, 4,
        8, 7, 4,
        7, 6, 4,
        6, 3, 4
    };

    static float const boundGridCoords[] =
    {
        0.0f, 0.0f,
        0.0f, -266.66666f,
        0.0f, -533.33331f,
        -266.66666f, 0.0f,
        -266.66666f, -266.66666f,
        -266.66666f, -533.33331f,
        -533.33331f, 0.0f,
        -533.33331f, -266.66666f,
        -533.33331f, -533.33331f
    };

    Cell cell(x, y);
    float gx = x - (int32(cell.GridX()) - CENTER_GRID_ID + 1) * SIZE_OF_GRIDS;
    float gy = y - (int32(cell.GridY()) - CENTER_GRID_ID + 1) * SIZE_OF_GRIDS;

    uint32 quarterIndex = 0;
    if (cell.CellY() < MAX_NUMBER_OF_CELLS / 2)
    {
        if (cell.CellX() < MAX_NUMBER_OF_CELLS / 2)
        {
            quarterIndex = 4 + (gy > gx);
        }
        else
            quarterIndex = 2 + ((-SIZE_OF_GRIDS - gx) > gy);
    }
    else if (cell.CellX() < MAX_NUMBER_OF_CELLS / 2)
    {
        quarterIndex = 6 + ((-SIZE_OF_GRIDS - gx) <= gy);
    }
    else
        quarterIndex = gx > gy;

    quarterIndex *= 3;

    return G3D::Plane(
        G3D::Vector3(boundGridCoords[indices[quarterIndex + 0] * 2 + 0], boundGridCoords[indices[quarterIndex + 0] * 2 + 1], _minHeight[indices[quarterIndex + 0]]),
        G3D::Vector3(boundGridCoords[indices[quarterIndex + 1] * 2 + 0], boundGridCoords[indices[quarterIndex + 1] * 2 + 1], _minHeight[indices[quarterIndex + 1]]),
        G3D::Vector3(boundGridCoords[indices[quarterIndex + 2] * 2 + 0], boundGridCoords[indices[quarterIndex + 2] * 2 + 1], _minHeight[indices[quarterIndex + 2]])
    ).distance(G3D::Vector3(gx, gy, 0.0f));
}

float GridMap::getLiquidLevel(float x, float y) const
{
    if (!_liquidMap)
        return _liquidLevel;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int cx_int = ((int)x & (MAP_RESOLUTION-1)) - _liquidOffY;
    int cy_int = ((int)y & (MAP_RESOLUTION-1)) - _liquidOffX;

    if (cx_int < 0 || cx_int >=_liquidHeight)
        return INVALID_HEIGHT;
    if (cy_int < 0 || cy_int >=_liquidWidth)
        return INVALID_HEIGHT;

    return _liquidMap[cx_int*_liquidWidth + cy_int];
}

// Why does this return LIQUID data?
uint8 GridMap::getTerrainType(float x, float y) const
{
    if (!_liquidFlags)
        return 0;

    x = 16 * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = 16 * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);
    int lx = (int)x & 15;
    int ly = (int)y & 15;
    return _liquidFlags[lx*16 + ly];
}

// Get water state on map
inline ZLiquidStatus GridMap::getLiquidStatus(float x, float y, float z, uint8 ReqLiquidType, LiquidData* data)
{
    // Check water type (if no water return)
    if (!_liquidType && !_liquidFlags)
        return LIQUID_MAP_NO_WATER;

    // Get cell
    float cx = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    float cy = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int x_int = (int)cx & (MAP_RESOLUTION-1);
    int y_int = (int)cy & (MAP_RESOLUTION-1);

    // Check water type in cell
    int idx=(x_int>>3)*16 + (y_int>>3);
    uint8 type = _liquidFlags ? _liquidFlags[idx] : _liquidType;
    uint32 entry = 0;
    if (_liquidEntry)
    {
        if (LiquidTypeEntry const* liquidEntry = sLiquidTypeStore.LookupEntry(_liquidEntry[idx]))
        {
            entry = liquidEntry->ID;
            type &= MAP_LIQUID_TYPE_DARK_WATER;
            uint32 liqTypeIdx = liquidEntry->Type;
            if (entry < 21)
            {
                if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(getArea(x, y)))
                {
                    uint32 overrideLiquid = area->LiquidTypeID[liquidEntry->Type];
                    if (!overrideLiquid && area->ParentAreaID)
                    {
                        area = sAreaTableStore.LookupEntry(area->ParentAreaID);
                        if (area)
                            overrideLiquid = area->LiquidTypeID[liquidEntry->Type];
                    }

                    if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(overrideLiquid))
                    {
                        entry = overrideLiquid;
                        liqTypeIdx = liq->Type;
                    }
                }
            }

            type |= 1 << liqTypeIdx;
        }
    }

    if (type == 0)
        return LIQUID_MAP_NO_WATER;

    // Check req liquid type mask
    if (ReqLiquidType && !(ReqLiquidType&type))
        return LIQUID_MAP_NO_WATER;

    // Check water level:
    // Check water height map
    int lx_int = x_int - _liquidOffY;
    int ly_int = y_int - _liquidOffX;
    if (lx_int < 0 || lx_int >=_liquidHeight)
        return LIQUID_MAP_NO_WATER;
    if (ly_int < 0 || ly_int >=_liquidWidth)
        return LIQUID_MAP_NO_WATER;

    // Get water level
    float liquid_level = _liquidMap ? _liquidMap[lx_int*_liquidWidth + ly_int] : _liquidLevel;
    // Get ground level (sub 0.2 for fix some errors)
    float ground_level = getHeight(x, y);

    // Check water level and ground level
    if (liquid_level < ground_level || z < ground_level - 2)
        return LIQUID_MAP_NO_WATER;

    // All ok in water -> store data
    if (data)
    {
        data->entry = entry;
        data->type_flags  = type;
        data->level = liquid_level;
        data->depth_level = ground_level;
    }

    // For speed check as int values
    float delta = liquid_level - z;

    if (delta > 2.0f)                   // Under water
        return LIQUID_MAP_UNDER_WATER;
    if (delta > 0.0f)                   // In water
        return LIQUID_MAP_IN_WATER;
    if (delta > -0.1f)                   // Walk on water
        return LIQUID_MAP_WATER_WALK;
                                      // Above water
    return LIQUID_MAP_ABOVE_WATER;
}

inline GridMap* Map::GetGrid(float x, float y)
{
    // half opt method
    int gx=(int)(CENTER_GRID_ID - x/SIZE_OF_GRIDS);                       //grid x
    int gy=(int)(CENTER_GRID_ID - y/SIZE_OF_GRIDS);                       //grid y

    // ensure GridMap is loaded
    EnsureGridCreated(GridCoord((MAX_NUMBER_OF_GRIDS - 1) - gx, (MAX_NUMBER_OF_GRIDS - 1) - gy));

    return GridMaps[gx][gy];
}

float Map::GetWaterOrGroundLevel(std::set<uint32> const& phases, float x, float y, float z, float* ground /*= nullptr*/, bool /*swim = false*/) const
{
    if (const_cast<Map*>(this)->GetGrid(x, y))
    {
        // we need ground level (including grid height version) for proper return water level in point
        float ground_z = GetHeight(phases, x, y, z, true, 50.0f);
        if (ground)
            *ground = ground_z;

        LiquidData liquid_status;

        ZLiquidStatus res = getLiquidStatus(x, y, ground_z, MAP_ALL_LIQUIDS, &liquid_status);
        return res ? liquid_status.level : ground_z;
    }

    return VMAP_INVALID_HEIGHT_VALUE;
}

float Map::GetHeight(float x, float y, float z, bool checkVMap /*= true*/, float maxSearchDist /*= DEFAULT_HEIGHT_SEARCH*/) const
{
    // find raw .map surface under Z coordinates
    float mapHeight = VMAP_INVALID_HEIGHT_VALUE;
    if (GridMap* gmap = const_cast<Map*>(this)->GetGrid(x, y))
    {
        float gridHeight = gmap->getHeight(x, y);
        // look from a bit higher pos to find the floor, ignore under surface case
        if (z + 2.0f > gridHeight)
            mapHeight = gridHeight;
    }

    float vmapHeight = VMAP_INVALID_HEIGHT_VALUE;
    if (checkVMap)
    {
        VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
        if (vmgr->isHeightCalcEnabled())
            vmapHeight = vmgr->getHeight(GetId(), x, y, z + 2.0f, maxSearchDist);   // look from a bit higher pos to find the floor
    }

    // mapHeight set for any above raw ground Z or <= INVALID_HEIGHT
    // vmapheight set for any under Z value or <= INVALID_HEIGHT
    if (vmapHeight > INVALID_HEIGHT)
    {
        if (mapHeight > INVALID_HEIGHT)
        {
            // we have mapheight and vmapheight and must select more appropriate

            // vmap height above map height
            // or if the distance of the vmap height is less the land height distance
            if (vmapHeight > mapHeight || std::fabs(mapHeight - z) > std::fabs(vmapHeight - z))
                return vmapHeight;
            else
                return mapHeight;                           // better use .map surface height
        }
        else
            return vmapHeight;                              // we have only vmapHeight (if have)
    }

    return mapHeight;                               // explicitly use map data
}

float Map::GetMinHeight(float x, float y) const
{
    if (GridMap const* grid = const_cast<Map*>(this)->GetGrid(x, y))
        return grid->getMinHeight(x, y);

    return -500.0f;
}

inline bool IsOutdoorWMO(uint32 mogpFlags, int32 /*adtId*/, int32 /*rootId*/, int32 /*groupId*/, WMOAreaTableEntry const* wmoEntry, AreaTableEntry const* atEntry)
{
    bool outdoor = true;

    if (wmoEntry && atEntry)
    {
        if (atEntry->Flags[0] & AREA_FLAG_OUTSIDE)
            return true;
        if (atEntry->Flags[0] & AREA_FLAG_INSIDE)
            return false;
    }

    outdoor = (mogpFlags & 0x8) != 0;

    if (wmoEntry)
    {
        if (wmoEntry->Flags & 4)
            return true;
        if (wmoEntry->Flags & 2)
            outdoor = false;
    }
    return outdoor;
}

bool Map::IsOutdoors(float x, float y, float z) const
{
    uint32 mogpFlags;
    int32 adtId, rootId, groupId;

    // no wmo found? -> outside by default
    if (!GetAreaInfo(x, y, z, mogpFlags, adtId, rootId, groupId))
        return true;

    AreaTableEntry const* atEntry = nullptr;
    WMOAreaTableEntry const* wmoEntry= sDB2Manager.GetWMOAreaTable(rootId, adtId, groupId);
    if (wmoEntry)
    {
        TC_LOG_DEBUG("maps", "Got WMOAreaTableEntry! flag %u, areaid %u", wmoEntry->Flags, wmoEntry->AreaTableID);
        atEntry = sAreaTableStore.LookupEntry(wmoEntry->AreaTableID);
    }
    return IsOutdoorWMO(mogpFlags, adtId, rootId, groupId, wmoEntry, atEntry);
}

bool Map::GetAreaInfo(float x, float y, float z, uint32 &flags, int32 &adtId, int32 &rootId, int32 &groupId) const
{
    float vmap_z = z;
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    if (vmgr->getAreaInfo(GetId(), x, y, vmap_z, flags, adtId, rootId, groupId))
    {
        // check if there's terrain between player height and object height
        if (GridMap* gmap = const_cast<Map*>(this)->GetGrid(x, y))
        {
            float _mapheight = gmap->getHeight(x, y);
            // z + 2.0f condition taken from GetHeight(), not sure if it's such a great choice...
            if (z + 2.0f > _mapheight &&  _mapheight > vmap_z)
                return false;
        }
        return true;
    }
    return false;
}

uint32 Map::GetAreaId(float x, float y, float z, bool *isOutdoors) const
{
    uint32 mogpFlags;
    int32 adtId, rootId, groupId;
    WMOAreaTableEntry const* wmoEntry = nullptr;
    AreaTableEntry const* atEntry = nullptr;
    bool haveAreaInfo = false;
    uint32 areaId = 0;

    if (GetAreaInfo(x, y, z, mogpFlags, adtId, rootId, groupId))
    {
        haveAreaInfo = true;
        wmoEntry = sDB2Manager.GetWMOAreaTable(rootId, adtId, groupId);
        if (wmoEntry)
        {
            areaId = wmoEntry->AreaTableID;
            atEntry = sAreaTableStore.LookupEntry(wmoEntry->AreaTableID);
        }
    }

    if (!areaId)
    {
        if (GridMap* gmap = const_cast<Map*>(this)->GetGrid(x, y))
            areaId = gmap->getArea(x, y);

        // this used while not all *.map files generated (instances)
        if (!areaId)
            areaId = i_mapEntry->AreaTableID;
    }

    if (isOutdoors)
    {
        if (haveAreaInfo)
            *isOutdoors = IsOutdoorWMO(mogpFlags, adtId, rootId, groupId, wmoEntry, atEntry);
        else
            *isOutdoors = true;
    }
    return areaId;
}

uint32 Map::GetAreaId(float x, float y, float z) const
{
    return GetAreaId(x, y, z, nullptr);
}

uint32 Map::GetZoneId(float x, float y, float z) const
{
    uint32 areaId = GetAreaId(x, y, z);
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
        if (area->ParentAreaID)
            return area->ParentAreaID;

    return areaId;
}

void Map::GetZoneAndAreaId(uint32& zoneid, uint32& areaid, float x, float y, float z) const
{
    areaid = zoneid = GetAreaId(x, y, z);
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaid))
        if (area->ParentAreaID)
            zoneid = area->ParentAreaID;
}

uint8 Map::GetTerrainType(float x, float y) const
{
    if (GridMap* gmap = const_cast<Map*>(this)->GetGrid(x, y))
        return gmap->getTerrainType(x, y);
    else
        return 0;
}

ZLiquidStatus Map::getLiquidStatus(float x, float y, float z, uint8 ReqLiquidType, LiquidData* data) const
{
    ZLiquidStatus result = LIQUID_MAP_NO_WATER;
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    float liquid_level = INVALID_HEIGHT;
    float ground_level = INVALID_HEIGHT;
    uint32 liquid_type = 0;
    if (vmgr->GetLiquidLevel(GetId(), x, y, z, ReqLiquidType, liquid_level, ground_level, liquid_type))
    {
        TC_LOG_DEBUG("maps", "getLiquidStatus(): vmap liquid level: %f ground: %f type: %u", liquid_level, ground_level, liquid_type);
        // Check water level and ground level
        if (liquid_level > ground_level && z > ground_level - 2)
        {
            // All ok in water -> store data
            if (data)
            {
                // hardcoded in client like this
                if (GetId() == 530 && liquid_type == 2)
                    liquid_type = 15;

                uint32 liquidFlagType = 0;
                if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquid_type))
                    liquidFlagType = liq->Type;

                if (liquid_type && liquid_type < 21)
                {
                    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(GetAreaId(x, y, z)))
                    {
                        uint32 overrideLiquid = area->LiquidTypeID[liquidFlagType];
                        if (!overrideLiquid && area->ParentAreaID)
                        {
                            area = sAreaTableStore.LookupEntry(area->ParentAreaID);
                            if (area)
                                overrideLiquid = area->LiquidTypeID[liquidFlagType];
                        }

                        if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(overrideLiquid))
                        {
                            liquid_type = overrideLiquid;
                            liquidFlagType = liq->Type;
                        }
                    }
                }

                data->level = liquid_level;
                data->depth_level = ground_level;

                data->entry = liquid_type;
                data->type_flags = 1 << liquidFlagType;
            }

            float delta = liquid_level - z;

            // Get position delta
            if (delta > 2.0f)                   // Under water
                return LIQUID_MAP_UNDER_WATER;
            if (delta > 0.0f)                   // In water
                return LIQUID_MAP_IN_WATER;
            if (delta > -0.1f)                   // Walk on water
                return LIQUID_MAP_WATER_WALK;
            result = LIQUID_MAP_ABOVE_WATER;
        }
    }

    if (GridMap* gmap = const_cast<Map*>(this)->GetGrid(x, y))
    {
        LiquidData map_data;
        ZLiquidStatus map_result = gmap->getLiquidStatus(x, y, z, ReqLiquidType, &map_data);
        // Not override LIQUID_MAP_ABOVE_WATER with LIQUID_MAP_NO_WATER:
        if (map_result != LIQUID_MAP_NO_WATER && (map_data.level > ground_level))
        {
            if (data)
            {
                // hardcoded in client like this
                if (GetId() == 530 && map_data.entry == 2)
                    map_data.entry = 15;

                *data = map_data;
            }
            return map_result;
        }
    }
    return result;
}

float Map::GetWaterLevel(float x, float y) const
{
    if (GridMap* gmap = const_cast<Map*>(this)->GetGrid(x, y))
        return gmap->getLiquidLevel(x, y);
    else
        return 0;
}

bool Map::isInLineOfSight(float x1, float y1, float z1, float x2, float y2, float z2, std::set<uint32> const& phases) const
{
    return VMAP::VMapFactory::createOrGetVMapManager()->isInLineOfSight(GetId(), x1, y1, z1, x2, y2, z2)
        && _dynamicTree.isInLineOfSight({ x1, y1, z1 }, { x2, y2, z2 }, phases);
}

bool Map::getObjectHitPos(std::set<uint32> const& phases, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float& ry, float& rz, float modifyDist)
{
    G3D::Vector3 startPos(x1, y1, z1);
    G3D::Vector3 dstPos(x2, y2, z2);

    G3D::Vector3 resultPos;
    bool result = _dynamicTree.getObjectHitPos(phases, startPos, dstPos, resultPos, modifyDist);

    rx = resultPos.x;
    ry = resultPos.y;
    rz = resultPos.z;
    return result;
}

float Map::GetHeight(std::set<uint32> const& phases, float x, float y, float z, bool vmap /*= true*/, float maxSearchDist /*= DEFAULT_HEIGHT_SEARCH*/) const
{
    return std::max<float>(GetHeight(x, y, z, vmap, maxSearchDist), _dynamicTree.getHeight(x, y, z, maxSearchDist, phases));
}

bool Map::IsInWater(float x, float y, float pZ, LiquidData* data) const
{
    LiquidData liquid_status;
    LiquidData* liquid_ptr = data ? data : &liquid_status;
    return (getLiquidStatus(x, y, pZ, MAP_ALL_LIQUIDS, liquid_ptr) & (LIQUID_MAP_IN_WATER | LIQUID_MAP_UNDER_WATER)) != 0;
}

bool Map::IsUnderWater(float x, float y, float z) const
{
    return (getLiquidStatus(x, y, z, MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN) & LIQUID_MAP_UNDER_WATER) != 0;
}

bool Map::CheckGridIntegrity(Creature* c, bool moved) const
{
    Cell const& cur_cell = c->GetCurrentCell();
    Cell xy_cell(c->GetPositionX(), c->GetPositionY());
    if (xy_cell != cur_cell)
    {
        TC_LOG_DEBUG("maps", "Creature (%s) X: %f Y: %f (%s) is in grid[%u, %u]cell[%u, %u] instead of grid[%u, %u]cell[%u, %u]",
            c->GetGUID().ToString().c_str(),
            c->GetPositionX(), c->GetPositionY(), (moved ? "final" : "original"),
            cur_cell.GridX(), cur_cell.GridY(), cur_cell.CellX(), cur_cell.CellY(),
            xy_cell.GridX(),  xy_cell.GridY(),  xy_cell.CellX(),  xy_cell.CellY());
        return true;                                        // not crash at error, just output error in debug mode
    }

    return true;
}

char const* Map::GetMapName() const
{
    return i_mapEntry ? i_mapEntry->MapName->Str[sWorld->GetDefaultDbcLocale()] : "UNNAMEDMAP\x0";
}

void Map::SendInitSelf(Player* player)
{
    TC_LOG_DEBUG("maps", "Creating player data for himself %s", player->GetGUID().ToString().c_str());

    UpdateData data(player->GetMapId());

    // attach to player data current transport data
    if (Transport* transport = player->GetTransport())
    {
        transport->BuildCreateUpdateBlockForPlayer(&data, player);
    }

    // build data for self presence in world at own client (one time for map)
    player->BuildCreateUpdateBlockForPlayer(&data, player);

    // build other passengers at transport also (they always visible and marked as visible and will not send at visibility update at add to map
    if (Transport* transport = player->GetTransport())
        for (Transport::PassengerSet::const_iterator itr = transport->GetPassengers().begin(); itr != transport->GetPassengers().end(); ++itr)
            if (player != (*itr) && player->HaveAtClient(*itr))
                (*itr)->BuildCreateUpdateBlockForPlayer(&data, player);

    WorldPacket packet;
    data.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

void Map::SendInitTransports(Player* player)
{
    // Hack to send out transports
    UpdateData transData(player->GetMapId());
    for (TransportsContainer::const_iterator i = _transports.begin(); i != _transports.end(); ++i)
        if (*i != player->GetTransport() && player->IsInPhase(*i))
            (*i)->BuildCreateUpdateBlockForPlayer(&transData, player);

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

void Map::SendRemoveTransports(Player* player)
{
    // Hack to send out transports
    UpdateData transData(player->GetMapId());
    for (TransportsContainer::const_iterator i = _transports.begin(); i != _transports.end(); ++i)
        if (*i != player->GetTransport())
            (*i)->BuildOutOfRangeUpdateBlock(&transData);

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

void Map::SendUpdateTransportVisibility(Player* player, std::set<uint32> const& previousPhases)
{
    // Hack to send out transports
    UpdateData transData(player->GetMapId());
    for (TransportsContainer::const_iterator i = _transports.begin(); i != _transports.end(); ++i)
    {
        if (*i == player->GetTransport())
            continue;

        if (player->IsInPhase(*i) && !Trinity::Containers::Intersects(previousPhases.begin(), previousPhases.end(), (*i)->GetPhases().begin(), (*i)->GetPhases().end()))
            (*i)->BuildCreateUpdateBlockForPlayer(&transData, player);
        else if (!player->IsInPhase(*i))
            (*i)->BuildOutOfRangeUpdateBlock(&transData);
    }

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

inline void Map::setNGrid(NGridType *grid, uint32 x, uint32 y)
{
    if (x >= MAX_NUMBER_OF_GRIDS || y >= MAX_NUMBER_OF_GRIDS)
    {
        TC_LOG_ERROR("maps", "map::setNGrid() Invalid grid coordinates found: %d, %d!", x, y);
        ABORT();
    }
    i_grids[x][y] = grid;
}

void Map::SendObjectUpdates()
{
    UpdateDataMapType update_players;

    while (!_updateObjects.empty())
    {
        Object* obj = *_updateObjects.begin();
        ASSERT(obj->IsInWorld());
        _updateObjects.erase(_updateObjects.begin());
        obj->BuildUpdate(update_players);
    }

    WorldPacket packet;                                     // here we allocate a std::vector with a size of 0x10000
    for (UpdateDataMapType::iterator iter = update_players.begin(); iter != update_players.end(); ++iter)
    {
        iter->second.BuildPacket(&packet);
        iter->first->GetSession()->SendPacket(&packet);
        packet.clear();                                     // clean the string
    }
}

void Map::DelayedUpdate(const uint32 t_diff)
{
    for (_transportsUpdateIter = _transports.begin(); _transportsUpdateIter != _transports.end();)
    {
        Transport* transport = *_transportsUpdateIter;
        ++_transportsUpdateIter;

        if (!transport->IsInWorld())
            continue;

        transport->DelayedUpdate(t_diff);
    }

    RemoveAllObjectsInRemoveList();

    // Don't unload grids if it's battleground, since we may have manually added GOs, creatures, those doesn't load from DB at grid re-load !
    // This isn't really bother us, since as soon as we have instanced BG-s, the whole map unloads as the BG gets ended
    if (!IsBattlegroundOrArena())
    {
        for (GridRefManager<NGridType>::iterator i = GridRefManager<NGridType>::begin(); i != GridRefManager<NGridType>::end();)
        {
            NGridType *grid = i->GetSource();
            GridInfo* info = i->GetSource()->getGridInfoRef();
            ++i;                                                // The update might delete the map and we need the next map before the iterator gets invalid
            ASSERT(grid->GetGridState() >= 0 && grid->GetGridState() < MAX_GRID_STATE);
            si_GridStates[grid->GetGridState()]->Update(*this, *grid, *info, t_diff);
        }
    }
}

void Map::AddObjectToRemoveList(WorldObject* obj)
{
    ASSERT(obj->GetMapId() == GetId() && obj->GetInstanceId() == GetInstanceId());

    obj->CleanupsBeforeDelete(false);                            // remove or simplify at least cross referenced links

    i_objectsToRemove.insert(obj);
    //TC_LOG_DEBUG("maps", "Object (GUID: %u TypeId: %u) added to removing list.", obj->GetGUIDLow(), obj->GetTypeId());
}

void Map::AddObjectToSwitchList(WorldObject* obj, bool on)
{
    ASSERT(obj->GetMapId() == GetId() && obj->GetInstanceId() == GetInstanceId());
    // i_objectsToSwitch is iterated only in Map::RemoveAllObjectsInRemoveList() and it uses
    // the contained objects only if GetTypeId() == TYPEID_UNIT , so we can return in all other cases
    if (obj->GetTypeId() != TYPEID_UNIT && obj->GetTypeId() != TYPEID_GAMEOBJECT)
        return;

    std::map<WorldObject*, bool>::iterator itr = i_objectsToSwitch.find(obj);
    if (itr == i_objectsToSwitch.end())
        i_objectsToSwitch.insert(itr, std::make_pair(obj, on));
    else if (itr->second != on)
        i_objectsToSwitch.erase(itr);
    else
        ABORT();
}

void Map::RemoveAllObjectsInRemoveList()
{
    while (!i_objectsToSwitch.empty())
    {
        std::map<WorldObject*, bool>::iterator itr = i_objectsToSwitch.begin();
        WorldObject* obj = itr->first;
        bool on = itr->second;
        i_objectsToSwitch.erase(itr);

        if (!obj->IsPermanentWorldObject())
        {
            switch (obj->GetTypeId())
            {
                case TYPEID_UNIT:
                    SwitchGridContainers<Creature>(obj->ToCreature(), on);
                    break;
                case TYPEID_GAMEOBJECT:
                    SwitchGridContainers<GameObject>(obj->ToGameObject(), on);
                    break;
                default:
                    break;
            }
        }
    }

    //TC_LOG_DEBUG("maps", "Object remover 1 check.");
    while (!i_objectsToRemove.empty())
    {
        std::set<WorldObject*>::iterator itr = i_objectsToRemove.begin();
        WorldObject* obj = *itr;

        switch (obj->GetTypeId())
        {
            case TYPEID_CORPSE:
            {
                Corpse* corpse = ObjectAccessor::GetCorpse(*obj, obj->GetGUID());
                if (!corpse)
                    TC_LOG_ERROR("maps", "Tried to delete corpse/bones %s that is not in map.", obj->GetGUID().ToString().c_str());
                else
                    RemoveFromMap(corpse, true);
                break;
            }
            case TYPEID_DYNAMICOBJECT:
                RemoveFromMap(obj->ToDynObject(), true);
                break;
            case TYPEID_AREATRIGGER:
                RemoveFromMap((AreaTrigger*)obj, true);
                break;
            case TYPEID_CONVERSATION:
                RemoveFromMap((Conversation*)obj, true);
                break;
            case TYPEID_GAMEOBJECT:
            {
                GameObject* go = obj->ToGameObject();
                if (Transport* transport = go->ToTransport())
                    RemoveFromMap(transport, true);
                else
                    RemoveFromMap(go, true);
                break;
            }
            case TYPEID_UNIT:
                // in case triggered sequence some spell can continue casting after prev CleanupsBeforeDelete call
                // make sure that like sources auras/etc removed before destructor start
                obj->ToCreature()->CleanupsBeforeDelete();
                RemoveFromMap(obj->ToCreature(), true);
                break;
            default:
                TC_LOG_ERROR("maps", "Non-grid object (TypeId: %u) is in grid object remove list, ignored.", obj->GetTypeId());
                break;
        }

        i_objectsToRemove.erase(itr);
    }

    //TC_LOG_DEBUG("maps", "Object remover 2 check.");
}

uint32 Map::GetPlayersCountExceptGMs() const
{
    uint32 count = 0;
    for (MapRefManager::const_iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (!itr->GetSource()->IsGameMaster())
            ++count;
    return count;
}

void Map::SendToPlayers(WorldPacket const* data) const
{
    for (MapRefManager::const_iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        itr->GetSource()->GetSession()->SendPacket(data);
}

bool Map::ActiveObjectsNearGrid(NGridType const& ngrid) const
{
    CellCoord cell_min(ngrid.getX() * MAX_NUMBER_OF_CELLS, ngrid.getY() * MAX_NUMBER_OF_CELLS);
    CellCoord cell_max(cell_min.x_coord + MAX_NUMBER_OF_CELLS, cell_min.y_coord+MAX_NUMBER_OF_CELLS);

    //we must find visible range in cells so we unload only non-visible cells...
    float viewDist = GetVisibilityRange();
    int cell_range = (int)ceilf(viewDist / SIZE_OF_GRID_CELL) + 1;

    cell_min.dec_x(cell_range);
    cell_min.dec_y(cell_range);
    cell_max.inc_x(cell_range);
    cell_max.inc_y(cell_range);

    for (MapRefManager::const_iterator iter = m_mapRefManager.begin(); iter != m_mapRefManager.end(); ++iter)
    {
        Player* player = iter->GetSource();

        CellCoord p = Trinity::ComputeCellCoord(player->GetPositionX(), player->GetPositionY());
        if ((cell_min.x_coord <= p.x_coord && p.x_coord <= cell_max.x_coord) &&
            (cell_min.y_coord <= p.y_coord && p.y_coord <= cell_max.y_coord))
            return true;
    }

    for (ActiveNonPlayers::const_iterator iter = m_activeNonPlayers.begin(); iter != m_activeNonPlayers.end(); ++iter)
    {
        WorldObject* obj = *iter;

        CellCoord p = Trinity::ComputeCellCoord(obj->GetPositionX(), obj->GetPositionY());
        if ((cell_min.x_coord <= p.x_coord && p.x_coord <= cell_max.x_coord) &&
            (cell_min.y_coord <= p.y_coord && p.y_coord <= cell_max.y_coord))
            return true;
    }

    return false;
}

template<class T>
void Map::AddToActive(T* obj)
{
    AddToActiveHelper(obj);
}

template <>
void Map::AddToActive(Creature* c)
{
    AddToActiveHelper(c);

    // also not allow unloading spawn grid to prevent creating creature clone at load
    if (!c->IsPet() && c->GetSpawnId())
    {
        float x, y, z;
        c->GetRespawnPosition(x, y, z);
        GridCoord p = Trinity::ComputeGridCoord(x, y);
        if (getNGrid(p.x_coord, p.y_coord))
            getNGrid(p.x_coord, p.y_coord)->incUnloadActiveLock();
        else
        {
            GridCoord p2 = Trinity::ComputeGridCoord(c->GetPositionX(), c->GetPositionY());
            TC_LOG_ERROR("maps", "Active creature (%s Entry: %u) added to grid[%u, %u] but spawn grid[%u, %u] was not loaded.",
                c->GetGUID().ToString().c_str(), c->GetEntry(), p.x_coord, p.y_coord, p2.x_coord, p2.y_coord);
        }
    }
}

template<>
void Map::AddToActive(DynamicObject* d)
{
    AddToActiveHelper(d);
}

template<class T>
void Map::RemoveFromActive(T* /*obj*/) { }

template <>
void Map::RemoveFromActive(Creature* c)
{
    RemoveFromActiveHelper(c);

    // also allow unloading spawn grid
    if (!c->IsPet() && c->GetSpawnId())
    {
        float x, y, z;
        c->GetRespawnPosition(x, y, z);
        GridCoord p = Trinity::ComputeGridCoord(x, y);
        if (getNGrid(p.x_coord, p.y_coord))
            getNGrid(p.x_coord, p.y_coord)->decUnloadActiveLock();
        else
        {
            GridCoord p2 = Trinity::ComputeGridCoord(c->GetPositionX(), c->GetPositionY());
            TC_LOG_ERROR("maps", "Active creature (%s Entry: %u) removed from grid[%u, %u] but spawn grid[%u, %u] was not loaded.",
                c->GetGUID().ToString().c_str(), c->GetEntry(), p.x_coord, p.y_coord, p2.x_coord, p2.y_coord);
        }
    }
}

template<>
void Map::RemoveFromActive(DynamicObject* obj)
{
    RemoveFromActiveHelper(obj);
}

template TC_GAME_API bool Map::AddToMap(Corpse*);
template TC_GAME_API bool Map::AddToMap(Creature*);
template TC_GAME_API bool Map::AddToMap(GameObject*);
template TC_GAME_API bool Map::AddToMap(DynamicObject*);
template TC_GAME_API bool Map::AddToMap(AreaTrigger*);
template TC_GAME_API bool Map::AddToMap(Conversation*);

template TC_GAME_API void Map::RemoveFromMap(Corpse*, bool);
template TC_GAME_API void Map::RemoveFromMap(Creature*, bool);
template TC_GAME_API void Map::RemoveFromMap(GameObject*, bool);
template TC_GAME_API void Map::RemoveFromMap(DynamicObject*, bool);
template TC_GAME_API void Map::RemoveFromMap(AreaTrigger*, bool);
template TC_GAME_API void Map::RemoveFromMap(Conversation*, bool);

/* ******* Dungeon Instance Maps ******* */

InstanceMap::InstanceMap(uint32 id, time_t expiry, uint32 InstanceId, uint8 SpawnMode, Map* _parent)
  : Map(id, expiry, InstanceId, SpawnMode, _parent),
    m_resetAfterUnload(false), m_unloadWhenEmpty(false),
    i_data(NULL), i_script_id(0), i_scenario(nullptr)
{
    //lets initialize visibility distance for dungeons
    InstanceMap::InitVisibilityDistance();

    // the timer is started by default, and stopped when the first player joins
    // this make sure it gets unloaded if for some reason no player joins
    m_unloadTimer = std::max(sWorld->getIntConfig(CONFIG_INSTANCE_UNLOAD_DELAY), (uint32)MIN_UNLOAD_DELAY);
}

InstanceMap::~InstanceMap()
{
    delete i_data;
    delete i_scenario;
}

void InstanceMap::InitVisibilityDistance()
{
    //init visibility distance for instances
    m_VisibleDistance = World::GetMaxVisibleDistanceInInstances();
    m_VisibilityNotifyPeriod = World::GetVisibilityNotifyPeriodInInstances();
}

/*
    Do map specific checks to see if the player can enter
*/
Map::EnterState InstanceMap::CannotEnter(Player* player)
{
    if (player->GetMapRef().getTarget() == this)
    {
        TC_LOG_ERROR("maps", "InstanceMap::CannotEnter - player %s(%s) already in map %d, %d, %d!", player->GetName().c_str(), player->GetGUID().ToString().c_str(), GetId(), GetInstanceId(), GetSpawnMode());
        ABORT();
        return CANNOT_ENTER_ALREADY_IN_MAP;
    }

    // allow GM's to enter
    if (player->IsGameMaster())
        return Map::CannotEnter(player);

    // cannot enter if the instance is full (player cap), GMs don't count
    uint32 maxPlayers = GetMaxPlayers();
    if (GetPlayersCountExceptGMs() >= maxPlayers)
    {
        TC_LOG_WARN("maps", "MAP: Instance '%u' of map '%s' cannot have more than '%u' players. Player '%s' rejected", GetInstanceId(), GetMapName(), maxPlayers, player->GetName().c_str());
        return CANNOT_ENTER_MAX_PLAYERS;
    }

    // cannot enter while an encounter is in progress (unless this is a relog, in which case it is permitted)
    if (!player->IsLoading() && IsRaid() && GetInstanceScript() && GetInstanceScript()->IsEncounterInProgress())
        return CANNOT_ENTER_ZONE_IN_COMBAT;

    // cannot enter if player is permanent saved to a different instance id
    if (InstancePlayerBind* playerBind = player->GetBoundInstance(GetId(), GetDifficultyID()))
        if (playerBind->perm && playerBind->save)
            if (playerBind->save->GetInstanceId() != GetInstanceId())
                return CANNOT_ENTER_INSTANCE_BIND_MISMATCH;

    return Map::CannotEnter(player);
}

/*
    Do map specific checks and add the player to the map if successful.
*/
bool InstanceMap::AddPlayerToMap(Player* player, bool initPlayer /*= true*/)
{
    /// @todo Not sure about checking player level: already done in HandleAreaTriggerOpcode
    // GMs still can teleport player in instance.
    // Is it needed?

    {
        std::lock_guard<std::mutex> lock(_mapLock);
        // Check moved to void WorldSession::HandleMoveWorldportAckOpcode()
        //if (!CanEnter(player))
            //return false;

        // Dungeon only code
        if (IsDungeon())
        {
            Group* group = player->GetGroup();

            // increase current instances (hourly limit)
            if (!group || !group->isLFGGroup())
                player->AddInstanceEnterTime(GetInstanceId(), time(NULL));

            // get or create an instance save for the map
            InstanceSave* mapSave = sInstanceSaveMgr->GetInstanceSave(GetInstanceId());
            if (!mapSave)
            {
                TC_LOG_DEBUG("maps", "InstanceMap::Add: creating instance save for map %d spawnmode %d with instance id %d", GetId(), GetSpawnMode(), GetInstanceId());
                mapSave = sInstanceSaveMgr->AddInstanceSave(GetId(), GetInstanceId(), Difficulty(GetSpawnMode()), 0, 0, true);
            }

            ASSERT(mapSave);

            // check for existing instance binds
            InstancePlayerBind* playerBind = player->GetBoundInstance(GetId(), Difficulty(GetSpawnMode()));
            if (playerBind && playerBind->perm)
            {
                // cannot enter other instances if bound permanently
                if (playerBind->save != mapSave)
                {
                    TC_LOG_ERROR("maps", "InstanceMap::Add: player %s(%s) is permanently bound to instance %s %d, %d, %d, %d, %d, %d but he is being put into instance %s %d, %d, %d, %d, %d, %d", player->GetName().c_str(), player->GetGUID().ToString().c_str(), GetMapName(), playerBind->save->GetMapId(), playerBind->save->GetInstanceId(), playerBind->save->GetDifficultyID(), playerBind->save->GetPlayerCount(), playerBind->save->GetGroupCount(), playerBind->save->CanReset(), GetMapName(), mapSave->GetMapId(), mapSave->GetInstanceId(), mapSave->GetDifficultyID(), mapSave->GetPlayerCount(), mapSave->GetGroupCount(), mapSave->CanReset());
                    return false;
                }
            }
            else
            {
                if (group)
                {
                    // solo saves should have been reset when the map was loaded
                    InstanceGroupBind* groupBind = group->GetBoundInstance(this);
                    if (playerBind && playerBind->save != mapSave)
                    {
                        TC_LOG_ERROR("maps", "InstanceMap::Add: player %s(%s) is being put into instance %s %d, %d, %d, %d, %d, %d but he is in group %s and is bound to instance %d, %d, %d, %d, %d, %d!", player->GetName().c_str(), player->GetGUID().ToString().c_str(), GetMapName(), mapSave->GetMapId(), mapSave->GetInstanceId(), mapSave->GetDifficultyID(), mapSave->GetPlayerCount(), mapSave->GetGroupCount(), mapSave->CanReset(), group->GetLeaderGUID().ToString().c_str(), playerBind->save->GetMapId(), playerBind->save->GetInstanceId(), playerBind->save->GetDifficultyID(), playerBind->save->GetPlayerCount(), playerBind->save->GetGroupCount(), playerBind->save->CanReset());
                        if (groupBind)
                            TC_LOG_ERROR("maps", "InstanceMap::Add: the group is bound to the instance %s %d, %d, %d, %d, %d, %d", GetMapName(), groupBind->save->GetMapId(), groupBind->save->GetInstanceId(), groupBind->save->GetDifficultyID(), groupBind->save->GetPlayerCount(), groupBind->save->GetGroupCount(), groupBind->save->CanReset());
                        //ABORT();
                        return false;
                    }
                    // bind to the group or keep using the group save
                    if (!groupBind)
                        group->BindToInstance(mapSave, false);
                    else
                    {
                        // cannot jump to a different instance without resetting it
                        if (groupBind->save != mapSave)
                        {
                            TC_LOG_ERROR("maps", "InstanceMap::Add: player %s(%s) is being put into instance %d, %d, %d but he is in group %s which is bound to instance %d, %d, %d!", player->GetName().c_str(), player->GetGUID().ToString().c_str(), mapSave->GetMapId(), mapSave->GetInstanceId(), mapSave->GetDifficultyID(), group->GetLeaderGUID().ToString().c_str(), groupBind->save->GetMapId(), groupBind->save->GetInstanceId(), groupBind->save->GetDifficultyID());
                            TC_LOG_ERROR("maps", "MapSave players: %d, group count: %d", mapSave->GetPlayerCount(), mapSave->GetGroupCount());
                            if (groupBind->save)
                                TC_LOG_ERROR("maps", "GroupBind save players: %d, group count: %d", groupBind->save->GetPlayerCount(), groupBind->save->GetGroupCount());
                            else
                                TC_LOG_ERROR("maps", "GroupBind save NULL");
                            return false;
                        }
                        // if the group/leader is permanently bound to the instance
                        // players also become permanently bound when they enter
                        if (groupBind->perm)
                        {
                            WorldPackets::Instance::PendingRaidLock pendingRaidLock;
                            pendingRaidLock.TimeUntilLock = 60000;
                            pendingRaidLock.CompletedMask = i_data ? i_data->GetCompletedEncounterMask() : 0;
                            pendingRaidLock.Extending = false;
                            pendingRaidLock.WarningOnly = false; // events it throws:  1 : INSTANCE_LOCK_WARNING   0 : INSTANCE_LOCK_STOP / INSTANCE_LOCK_START
                            player->GetSession()->SendPacket(pendingRaidLock.Write());
                            player->SetPendingBind(mapSave->GetInstanceId(), 60000);
                        }
                    }
                }
                else
                {
                    // set up a solo bind or continue using it
                    if (!playerBind)
                        player->BindToInstance(mapSave, false);
                    else
                        // cannot jump to a different instance without resetting it
                        ASSERT(playerBind->save == mapSave);
                }
            }
        }

        // for normal instances cancel the reset schedule when the
        // first player enters (no players yet)
        SetResetSchedule(false);

        TC_LOG_DEBUG("maps", "MAP: Player '%s' entered instance '%u' of map '%s'", player->GetName().c_str(), GetInstanceId(), GetMapName());
        // initialize unload state
        m_unloadTimer = 0;
        m_resetAfterUnload = false;
        m_unloadWhenEmpty = false;
    }

    // this will acquire the same mutex so it cannot be in the previous block
    Map::AddPlayerToMap(player, initPlayer);

    if (i_data)
        i_data->OnPlayerEnter(player);

    if (i_scenario)
        i_scenario->OnPlayerEnter(player);

    return true;
}

void InstanceMap::Update(const uint32 t_diff)
{
    Map::Update(t_diff);

    if (i_data)
    {
        i_data->Update(t_diff);
        i_data->UpdateCombatResurrection(t_diff);
    }

    if (i_scenario)
        i_scenario->Update(t_diff);
}

void InstanceMap::RemovePlayerFromMap(Player* player, bool remove)
{
    TC_LOG_DEBUG("maps", "MAP: Removing player '%s' from instance '%u' of map '%s' before relocating to another map", player->GetName().c_str(), GetInstanceId(), GetMapName());
    //if last player set unload timer
    if (!m_unloadTimer && m_mapRefManager.getSize() == 1)
        m_unloadTimer = m_unloadWhenEmpty ? MIN_UNLOAD_DELAY : std::max(sWorld->getIntConfig(CONFIG_INSTANCE_UNLOAD_DELAY), (uint32)MIN_UNLOAD_DELAY);
    if (i_scenario)
        i_scenario->OnPlayerExit(player);
    Map::RemovePlayerFromMap(player, remove);
    // for normal instances schedule the reset after all players have left
    SetResetSchedule(true);
    sInstanceSaveMgr->UnloadInstanceSave(GetInstanceId());
}

void InstanceMap::CreateInstanceData(bool load)
{
    if (i_data != NULL)
        return;

    InstanceTemplate const* mInstance = sObjectMgr->GetInstanceTemplate(GetId());
    if (mInstance)
    {
        i_script_id = mInstance->ScriptId;
        i_data = sScriptMgr->CreateInstanceData(this);
    }

    if (!i_data)
        return;

    i_data->Initialize();

    if (load)
    {
        /// @todo make a global storage for this
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_INSTANCE);
        stmt->setUInt16(0, uint16(GetId()));
        stmt->setUInt32(1, i_InstanceId);
        PreparedQueryResult result = CharacterDatabase.Query(stmt);

        if (result)
        {
            Field* fields = result->Fetch();
            std::string data = fields[0].GetString();
            i_data->SetCompletedEncountersMask(fields[1].GetUInt32());
            i_data->SetEntranceLocation(fields[2].GetUInt32());
            if (!data.empty())
            {
                TC_LOG_DEBUG("maps", "Loading instance data for `%s` with id %u", sObjectMgr->GetScriptName(i_script_id).c_str(), i_InstanceId);
                i_data->Load(data.c_str());
            }
        }
    }
}

/*
    Returns true if there are no players in the instance
*/
bool InstanceMap::Reset(uint8 method)
{
    // note: since the map may not be loaded when the instance needs to be reset
    // the instance must be deleted from the DB by InstanceSaveManager

    if (HavePlayers())
    {
        if (method == INSTANCE_RESET_ALL || method == INSTANCE_RESET_CHANGE_DIFFICULTY)
        {
            // notify the players to leave the instance so it can be reset
            for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
                itr->GetSource()->SendResetFailedNotify(GetId());
        }
        else
        {
            bool doUnload = true;
            if (method == INSTANCE_RESET_GLOBAL)
            {
                // set the homebind timer for players inside (1 minute)
                for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
                {
                    InstancePlayerBind* bind = itr->GetSource()->GetBoundInstance(GetId(), GetDifficultyID());
                    if (bind && bind->extendState && bind->save->GetInstanceId() == GetInstanceId())
                        doUnload = false;
                    else
                        itr->GetSource()->m_InstanceValid = false;
                }

                if (doUnload && HasPermBoundPlayers()) // check if any unloaded players have a nonexpired save to this
                    doUnload = false;
            }

            if (doUnload)
            {
                // the unload timer is not started
                // instead the map will unload immediately after the players have left
                m_unloadWhenEmpty = true;
                m_resetAfterUnload = true;
            }
        }
    }
    else
    {
        // unloaded at next update
        m_unloadTimer = MIN_UNLOAD_DELAY;
        m_resetAfterUnload = !(method == INSTANCE_RESET_GLOBAL && HasPermBoundPlayers());
    }

    return m_mapRefManager.isEmpty();
}

std::string const& InstanceMap::GetScriptName() const
{
    return sObjectMgr->GetScriptName(i_script_id);
}

void InstanceMap::PermBindAllPlayers()
{
    if (!IsDungeon())
        return;

    InstanceSave* save = sInstanceSaveMgr->GetInstanceSave(GetInstanceId());
    if (!save)
    {
        TC_LOG_ERROR("maps", "Cannot bind players to instance map (Name: %s, Entry: %u, Difficulty: %u, ID: %u) because no instance save is available!", GetMapName(), GetId(), GetDifficultyID(), GetInstanceId());
        return;
    }

    // perm bind all players that are currently inside the instance
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
    {
        Player* player = itr->GetSource();
        // never instance bind GMs with GM mode enabled
        if (player->IsGameMaster())
            continue;

        InstancePlayerBind* bind = player->GetBoundInstance(save->GetMapId(), save->GetDifficultyID());
        if (bind && bind->perm)
        {
            if (bind->save && bind->save->GetInstanceId() != save->GetInstanceId())
            {
                TC_LOG_ERROR("maps", "Player (GUID: " UI64FMTD ", Name: %s) is in instance map (Name: %s, Entry: %u, Difficulty: %u, ID: %u) that is being bound, but already has a save for the map on ID %u!", player->GetGUID().GetCounter(), player->GetName().c_str(), GetMapName(), save->GetMapId(), save->GetDifficultyID(), save->GetInstanceId(), bind->save->GetInstanceId());
            }
            else if (!bind->save)
            {
                TC_LOG_ERROR("maps", "Player (GUID: " UI64FMTD ", Name: %s) is in instance map (Name: %s, Entry: %u, Difficulty: %u, ID: %u) that is being bound, but already has a bind (without associated save) for the map!", player->GetGUID().GetCounter(), player->GetName().c_str(), GetMapName(), save->GetMapId(), save->GetDifficultyID(), save->GetInstanceId());
            }
        }
        else
        {
            player->BindToInstance(save, true);
            WorldPackets::Instance::InstanceSaveCreated data;
            data.Gm = player->IsGameMaster();
            player->GetSession()->SendPacket(data.Write());
            player->GetSession()->SendCalendarRaidLockout(save, true);

            // if group leader is in instance, group also gets bound
            if (Group* group = player->GetGroup())
                if (group->GetLeaderGUID() == player->GetGUID())
                    group->BindToInstance(save, true);
        }
    }
}

void InstanceMap::UnloadAll()
{
    ASSERT(!HavePlayers());

    if (m_resetAfterUnload)
    {
        DeleteRespawnTimes();
        DeleteCorpseData();
    }

    Map::UnloadAll();
}

void InstanceMap::SendResetWarnings(uint32 timeLeft) const
{
    for (MapRefManager::const_iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        itr->GetSource()->SendInstanceResetWarning(GetId(), itr->GetSource()->GetDifficultyID(GetEntry()), timeLeft, true);
}

void InstanceMap::SetResetSchedule(bool on)
{
    // only for normal instances
    // the reset time is only scheduled when there are no payers inside
    // it is assumed that the reset time will rarely (if ever) change while the reset is scheduled
    if (IsDungeon() && !HavePlayers() && !IsRaidOrHeroicDungeon())
    {
        if (InstanceSave* save = sInstanceSaveMgr->GetInstanceSave(GetInstanceId()))
            sInstanceSaveMgr->ScheduleReset(on, save->GetResetTime(), InstanceSaveManager::InstResetEvent(0, GetId(), Difficulty(GetSpawnMode()), GetInstanceId()));
        else
            TC_LOG_ERROR("maps", "InstanceMap::SetResetSchedule: cannot turn schedule %s, there is no save information for instance (map [id: %u, name: %s], instance id: %u, difficulty: %u)",
                on ? "on" : "off", GetId(), GetMapName(), GetInstanceId(), Difficulty(GetSpawnMode()));
    }
}

MapDifficultyEntry const* Map::GetMapDifficulty() const
{
    return sDB2Manager.GetMapDifficultyData(GetId(), GetDifficultyID());
}

uint8 Map::GetDifficultyLootBonusTreeMod() const
{
    if (MapDifficultyEntry const* mapDifficulty = GetMapDifficulty())
        if (mapDifficulty->ItemBonusTreeModID)
            return mapDifficulty->ItemBonusTreeModID;

    if (DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(GetDifficultyID()))
        return difficulty->ItemBonusTreeModID;

    return 0;
}

uint32 Map::GetId() const
{
    return i_mapEntry->ID;
}

bool Map::Instanceable() const
{
    return i_mapEntry && i_mapEntry->Instanceable();
}

bool Map::IsDungeon() const
{
    return i_mapEntry && i_mapEntry->IsDungeon();
}

bool Map::IsNonRaidDungeon() const
{
    return i_mapEntry && i_mapEntry->IsNonRaidDungeon();
}

bool Map::IsRaid() const
{
    return i_mapEntry && i_mapEntry->IsRaid();
}

bool Map::IsRaidOrHeroicDungeon() const
{
    return IsRaid() || IsHeroic();
}

bool Map::IsHeroic() const
{
    if (DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(i_spawnMode))
        return difficulty->Flags & DIFFICULTY_FLAG_HEROIC;
    return false;
}

bool Map::Is25ManRaid() const
{
    return IsRaid() && (i_spawnMode == DIFFICULTY_25_N || i_spawnMode == DIFFICULTY_25_HC);
}

bool Map::IsBattleground() const
{
    return i_mapEntry && i_mapEntry->IsBattleground();
}

bool Map::IsBattleArena() const
{
    return i_mapEntry && i_mapEntry->IsBattleArena();
}

bool Map::IsBattlegroundOrArena() const
{
    return i_mapEntry && i_mapEntry->IsBattlegroundOrArena();
}

bool Map::IsGarrison() const
{
    return i_mapEntry && i_mapEntry->IsGarrison();
}

bool Map::GetEntrancePos(int32 &mapid, float &x, float &y)
{
    if (!i_mapEntry)
        return false;
    return i_mapEntry->GetEntrancePos(mapid, x, y);
}

bool InstanceMap::HasPermBoundPlayers() const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PERM_BIND_BY_INSTANCE);
    stmt->setUInt16(0,GetInstanceId());
    return !!CharacterDatabase.Query(stmt);
}

uint32 InstanceMap::GetMaxPlayers() const
{
    MapDifficultyEntry const* mapDiff = GetMapDifficulty();
    if (mapDiff && mapDiff->MaxPlayers)
        return mapDiff->MaxPlayers;

    return GetEntry()->MaxPlayers;
}

uint32 InstanceMap::GetMaxResetDelay() const
{
    MapDifficultyEntry const* mapDiff = GetMapDifficulty();
    return mapDiff ? mapDiff->GetRaidDuration() : 0;
}

/* ******* Battleground Instance Maps ******* */

BattlegroundMap::BattlegroundMap(uint32 id, time_t expiry, uint32 InstanceId, Map* _parent, uint8 spawnMode)
  : Map(id, expiry, InstanceId, spawnMode, _parent), m_bg(NULL)
{
    //lets initialize visibility distance for BG/Arenas
    BattlegroundMap::InitVisibilityDistance();
}

BattlegroundMap::~BattlegroundMap()
{
    if (m_bg)
    {
        //unlink to prevent crash, always unlink all pointer reference before destruction
        m_bg->SetBgMap(NULL);
        m_bg = NULL;
    }
}

void BattlegroundMap::InitVisibilityDistance()
{
    //init visibility distance for BG/Arenas
    m_VisibleDistance = World::GetMaxVisibleDistanceInBGArenas();
    m_VisibilityNotifyPeriod = World::GetVisibilityNotifyPeriodInBGArenas();
}

Map::EnterState BattlegroundMap::CannotEnter(Player* player)
{
    if (player->GetMapRef().getTarget() == this)
    {
        TC_LOG_ERROR("maps", "BGMap::CannotEnter - player %s is already in map!", player->GetGUID().ToString().c_str());
        ABORT();
        return CANNOT_ENTER_ALREADY_IN_MAP;
    }

    if (player->GetBattlegroundId() != GetInstanceId())
        return CANNOT_ENTER_INSTANCE_BIND_MISMATCH;

    // player number limit is checked in bgmgr, no need to do it here

    return Map::CannotEnter(player);
}

bool BattlegroundMap::AddPlayerToMap(Player* player, bool initPlayer /*= true*/)
{
    {
        std::lock_guard<std::mutex> lock(_mapLock);
        //Check moved to void WorldSession::HandleMoveWorldportAckOpcode()
        //if (!CanEnter(player))
            //return false;
        // reset instance validity, battleground maps do not homebind
        player->m_InstanceValid = true;
    }
    return Map::AddPlayerToMap(player, initPlayer);
}

void BattlegroundMap::RemovePlayerFromMap(Player* player, bool remove)
{
    TC_LOG_DEBUG("maps", "MAP: Removing player '%s' from bg '%u' of map '%s' before relocating to another map", player->GetName().c_str(), GetInstanceId(), GetMapName());
    Map::RemovePlayerFromMap(player, remove);
}

void BattlegroundMap::SetUnload()
{
    m_unloadTimer = MIN_UNLOAD_DELAY;
}

void BattlegroundMap::RemoveAllPlayers()
{
    if (HavePlayers())
        for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
            if (Player* player = itr->GetSource())
                if (!player->IsBeingTeleportedFar())
                    player->TeleportTo(player->GetBattlegroundEntryPoint());
}

AreaTrigger* Map::GetAreaTrigger(ObjectGuid const& guid)
{
    return _objectsStore.Find<AreaTrigger>(guid);
}

Conversation* Map::GetConversation(ObjectGuid const& guid)
{
    return _objectsStore.Find<Conversation>(guid);
}

Corpse* Map::GetCorpse(ObjectGuid const& guid)
{
    return _objectsStore.Find<Corpse>(guid);
}

Creature* Map::GetCreature(ObjectGuid const& guid)
{
    return _objectsStore.Find<Creature>(guid);
}

DynamicObject* Map::GetDynamicObject(ObjectGuid const& guid)
{
    return _objectsStore.Find<DynamicObject>(guid);
}

GameObject* Map::GetGameObject(ObjectGuid const& guid)
{
    return _objectsStore.Find<GameObject>(guid);
}

Pet* Map::GetPet(ObjectGuid const& guid)
{
    return _objectsStore.Find<Pet>(guid);
}

Transport* Map::GetTransport(ObjectGuid const& guid)
{
    if (!guid.IsMOTransport())
        return NULL;

    GameObject* go = GetGameObject(guid);
    return go ? go->ToTransport() : NULL;
}

void Map::UpdateIteratorBack(Player* player)
{
    if (m_mapRefIter == player->GetMapRef())
        m_mapRefIter = m_mapRefIter->nocheck_prev();
}

void Map::SaveCreatureRespawnTime(ObjectGuid::LowType dbGuid, time_t respawnTime)
{
    if (!respawnTime)
    {
        // Delete only
        RemoveCreatureRespawnTime(dbGuid);
        return;
    }

    _creatureRespawnTimes[dbGuid] = respawnTime;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CREATURE_RESPAWN);
    stmt->setUInt64(0, dbGuid);
    stmt->setUInt32(1, uint32(respawnTime));
    stmt->setUInt16(2, GetId());
    stmt->setUInt32(3, GetInstanceId());
    CharacterDatabase.Execute(stmt);
}

void Map::RemoveCreatureRespawnTime(ObjectGuid::LowType dbGuid)
{
    _creatureRespawnTimes.erase(dbGuid);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CREATURE_RESPAWN);
    stmt->setUInt64(0, dbGuid);
    stmt->setUInt16(1, GetId());
    stmt->setUInt32(2, GetInstanceId());
    CharacterDatabase.Execute(stmt);
}

void Map::SaveGORespawnTime(ObjectGuid::LowType dbGuid, time_t respawnTime)
{
    if (!respawnTime)
    {
        // Delete only
        RemoveGORespawnTime(dbGuid);
        return;
    }

    _goRespawnTimes[dbGuid] = respawnTime;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GO_RESPAWN);
    stmt->setUInt64(0, dbGuid);
    stmt->setUInt32(1, uint32(respawnTime));
    stmt->setUInt16(2, GetId());
    stmt->setUInt32(3, GetInstanceId());
    CharacterDatabase.Execute(stmt);
}

void Map::RemoveGORespawnTime(ObjectGuid::LowType dbGuid)
{
    _goRespawnTimes.erase(dbGuid);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GO_RESPAWN);
    stmt->setUInt64(0, dbGuid);
    stmt->setUInt16(1, GetId());
    stmt->setUInt32(2, GetInstanceId());
    CharacterDatabase.Execute(stmt);
}

void Map::LoadRespawnTimes()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CREATURE_RESPAWNS);
    stmt->setUInt16(0, GetId());
    stmt->setUInt32(1, GetInstanceId());
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
    {
        do
        {
            Field* fields = result->Fetch();
            ObjectGuid::LowType loguid = fields[0].GetUInt64();
            uint32 respawnTime = fields[1].GetUInt32();

            _creatureRespawnTimes[loguid] = time_t(respawnTime);
        } while (result->NextRow());
    }

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GO_RESPAWNS);
    stmt->setUInt16(0, GetId());
    stmt->setUInt32(1, GetInstanceId());
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
    {
        do
        {
            Field* fields = result->Fetch();
            ObjectGuid::LowType loguid = fields[0].GetUInt64();
            uint32 respawnTime = fields[1].GetUInt32();

            _goRespawnTimes[loguid] = time_t(respawnTime);
        } while (result->NextRow());
    }
}

void Map::DeleteRespawnTimes()
{
    _creatureRespawnTimes.clear();
    _goRespawnTimes.clear();

    DeleteRespawnTimesInDB(GetId(), GetInstanceId());
}

void Map::DeleteRespawnTimesInDB(uint16 mapId, uint32 instanceId)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CREATURE_RESPAWN_BY_INSTANCE);
    stmt->setUInt16(0, mapId);
    stmt->setUInt32(1, instanceId);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GO_RESPAWN_BY_INSTANCE);
    stmt->setUInt16(0, mapId);
    stmt->setUInt32(1, instanceId);
    CharacterDatabase.Execute(stmt);
}

time_t Map::GetLinkedRespawnTime(ObjectGuid guid) const
{
    ObjectGuid linkedGuid = sObjectMgr->GetLinkedRespawnGuid(guid);
    switch (linkedGuid.GetHigh())
    {
        case HighGuid::Creature:
            return GetCreatureRespawnTime(linkedGuid.GetCounter());
        case HighGuid::GameObject:
            return GetGORespawnTime(linkedGuid.GetCounter());
        default:
            break;
    }

    return time_t(0);
}

void Map::LoadCorpseData()
{
    std::unordered_map<ObjectGuid::LowType, std::unordered_set<uint32>> phases;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CORPSE_PHASES);
    stmt->setUInt32(0, GetId());
    stmt->setUInt32(1, GetInstanceId());

    //        0          1
    // SELECT OwnerGuid, PhaseId FROM corpse_phases cp LEFT JOIN corpse c ON cp.OwnerGuid = c.guid WHERE c.mapId = ? AND c.instanceId = ?
    PreparedQueryResult phaseResult = CharacterDatabase.Query(stmt);
    if (phaseResult)
    {
        do
        {
            Field* fields = phaseResult->Fetch();
            ObjectGuid::LowType guid = fields[0].GetUInt64();
            uint32 phaseId = fields[1].GetUInt32();

            phases[guid].insert(phaseId);

        } while (phaseResult->NextRow());
    }

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CORPSES);
    stmt->setUInt32(0, GetId());
    stmt->setUInt32(1, GetInstanceId());

    //        0     1     2     3            4      5          6          7       8       9      10        11    12          13          14
    // SELECT posX, posY, posZ, orientation, mapId, displayId, itemCache, bytes1, bytes2, flags, dynFlags, time, corpseType, instanceId, guid FROM corpse WHERE mapId = ? AND instanceId = ?
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        CorpseType type = CorpseType(fields[12].GetUInt8());
        ObjectGuid::LowType guid = fields[14].GetUInt64();
        if (type >= MAX_CORPSE_TYPE || type == CORPSE_BONES)
        {
            TC_LOG_ERROR("misc", "Corpse (guid: " UI64FMTD ") have wrong corpse type (%u), not loading.", guid, type);
            continue;
        }

        Corpse* corpse = new Corpse(type);
        if (!corpse->LoadCorpseFromDB(GenerateLowGuid<HighGuid::Corpse>(), fields))
        {
            delete corpse;
            continue;
        }

        for (auto phaseId : phases[guid])
            corpse->SetInPhase(phaseId, false, true);

        AddCorpse(corpse);

    } while (result->NextRow());
}

void Map::DeleteCorpseData()
{
    // DELETE cp, c FROM corpse_phases cp INNER JOIN corpse c ON cp.OwnerGuid = c.guid WHERE c.mapId = ? AND c.instanceId = ?
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CORPSES_FROM_MAP);
    stmt->setUInt32(0, GetId());
    stmt->setUInt32(1, GetInstanceId());
    CharacterDatabase.Execute(stmt);
}

void Map::AddCorpse(Corpse* corpse)
{
    corpse->SetMap(this);

    _corpsesByCell[corpse->GetCellCoord().GetId()].insert(corpse);
    if (corpse->GetType() != CORPSE_BONES)
        _corpsesByPlayer[corpse->GetOwnerGUID()] = corpse;
    else
        _corpseBones.insert(corpse);
}

void Map::RemoveCorpse(Corpse* corpse)
{
    ASSERT(corpse);

    corpse->DestroyForNearbyPlayers();
    if (corpse->IsInGrid())
        RemoveFromMap(corpse, false);
    else
    {
        corpse->RemoveFromWorld();
        corpse->ResetMap();
    }

    _corpsesByCell[corpse->GetCellCoord().GetId()].erase(corpse);
    if (corpse->GetType() != CORPSE_BONES)
        _corpsesByPlayer.erase(corpse->GetOwnerGUID());
    else
        _corpseBones.erase(corpse);
}

Corpse* Map::ConvertCorpseToBones(ObjectGuid const& ownerGuid, bool insignia /*= false*/)
{
    Corpse* corpse = GetCorpseByPlayer(ownerGuid);
    if (!corpse)
        return nullptr;

    RemoveCorpse(corpse);

    // remove corpse from DB
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    corpse->DeleteFromDB(trans);
    CharacterDatabase.CommitTransaction(trans);

    Corpse* bones = NULL;

    // create the bones only if the map and the grid is loaded at the corpse's location
    // ignore bones creating option in case insignia
    if ((insignia ||
        (IsBattlegroundOrArena() ? sWorld->getBoolConfig(CONFIG_DEATH_BONES_BG_OR_ARENA) : sWorld->getBoolConfig(CONFIG_DEATH_BONES_WORLD))) &&
        !IsRemovalGrid(corpse->GetPositionX(), corpse->GetPositionY()))
    {
        // Create bones, don't change Corpse
        bones = new Corpse();
        bones->Create(corpse->GetGUID().GetCounter(), this);

        for (uint8 i = OBJECT_FIELD_GUID + 4; i < CORPSE_END; ++i)                    // don't overwrite guid
            bones->SetUInt32Value(i, corpse->GetUInt32Value(i));

        bones->SetCellCoord(corpse->GetCellCoord());
        bones->Relocate(corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ(), corpse->GetOrientation());

        bones->SetUInt32Value(CORPSE_FIELD_FLAGS, corpse->GetUInt32Value(CORPSE_FIELD_FLAGS) | CORPSE_FLAG_BONES);

        bones->CopyPhaseFrom(corpse);

        AddCorpse(bones);

        // add bones in grid store if grid loaded where corpse placed
        AddToMap(bones);
    }

    // all references to the corpse should be removed at this point
    delete corpse;

    return bones;
}

void Map::RemoveOldCorpses()
{
    time_t now = time(nullptr);

    std::vector<ObjectGuid> corpses;
    corpses.reserve(_corpsesByPlayer.size());

    for (auto const& p : _corpsesByPlayer)
        if (p.second->IsExpired(now))
            corpses.push_back(p.first);

    for (ObjectGuid const& ownerGuid : corpses)
        ConvertCorpseToBones(ownerGuid);

    std::vector<Corpse*> expiredBones;
    for (Corpse* bones : _corpseBones)
        if (bones->IsExpired(now))
            expiredBones.push_back(bones);

    for (Corpse* bones : expiredBones)
    {
        RemoveCorpse(bones);
        delete bones;
    }
}

void Map::SendZoneDynamicInfo(uint32 zoneId, Player* player) const
{
    auto itr = _zoneDynamicInfo.find(zoneId);
    if (itr == _zoneDynamicInfo.end())
        return;

    if (uint32 music = itr->second.MusicId)
        player->SendDirectMessage(WorldPackets::Misc::PlayMusic(music).Write());

    SendZoneWeather(itr->second, player);

    if (uint32 overrideLightId = itr->second.OverrideLightId)
    {
        WorldPackets::Misc::OverrideLight overrideLight;
        overrideLight.AreaLightID = _defaultLight;
        overrideLight.OverrideLightID = overrideLightId;
        overrideLight.TransitionMilliseconds = itr->second.LightFadeInTime;
        player->SendDirectMessage(overrideLight.Write());
    }
}

void Map::SendZoneWeather(uint32 zoneId, Player* player) const
{
    if (!player->HasAuraType(SPELL_AURA_FORCE_WEATHER))
    {
        auto itr = _zoneDynamicInfo.find(zoneId);
        if (itr == _zoneDynamicInfo.end())
            return;

        SendZoneWeather(itr->second, player);
    }
}

void Map::SendZoneWeather(ZoneDynamicInfo const& zoneDynamicInfo, Player* player) const
{
    if (WeatherState weatherId = zoneDynamicInfo.WeatherId)
    {
        WorldPackets::Misc::Weather weather(weatherId, zoneDynamicInfo.WeatherGrade);
        player->SendDirectMessage(weather.Write());
    }
    else if (zoneDynamicInfo.DefaultWeather)
    {
        zoneDynamicInfo.DefaultWeather->SendWeatherUpdateToPlayer(player);
    }
    else
        Weather::SendFineWeatherUpdateToPlayer(player);
}

void Map::SetZoneMusic(uint32 zoneId, uint32 musicId)
{
    _zoneDynamicInfo[zoneId].MusicId = musicId;

    Map::PlayerList const& players = GetPlayers();
    if (!players.isEmpty())
    {
        WorldPackets::Misc::PlayMusic playMusic(musicId);
        playMusic.Write();

        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            if (Player* player = itr->GetSource())
                if (player->GetZoneId() == zoneId && !player->HasAuraType(SPELL_AURA_FORCE_WEATHER))
                    player->SendDirectMessage(playMusic.GetRawPacket());
    }
}

Weather* Map::GetOrGenerateZoneDefaultWeather(uint32 zoneId)
{
    WeatherData const* weatherData = WeatherMgr::GetWeatherData(zoneId);
    if (!weatherData)
        return nullptr;

    ZoneDynamicInfo& info = _zoneDynamicInfo[zoneId];
    if (!info.DefaultWeather)
    {
        info.DefaultWeather = Trinity::make_unique<Weather>(zoneId, weatherData);
        info.DefaultWeather->ReGenerate();
        info.DefaultWeather->UpdateWeather();
    }

    return info.DefaultWeather.get();
}

void Map::SetZoneWeather(uint32 zoneId, WeatherState weatherId, float weatherGrade)
{
    ZoneDynamicInfo& info = _zoneDynamicInfo[zoneId];
    info.WeatherId = weatherId;
    info.WeatherGrade = weatherGrade;

    Map::PlayerList const& players = GetPlayers();
    if (!players.isEmpty())
    {
        WorldPackets::Misc::Weather weather(weatherId, weatherGrade);
        weather.Write();

        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            if (Player* player = itr->GetSource())
                if (player->GetZoneId() == zoneId)
                    player->SendDirectMessage(weather.GetRawPacket());
    }
}

void Map::SetZoneOverrideLight(uint32 zoneId, uint32 lightId, uint32 fadeInTime)
{
    ZoneDynamicInfo& info = _zoneDynamicInfo[zoneId];
    info.OverrideLightId = lightId;
    info.LightFadeInTime = fadeInTime;

    Map::PlayerList const& players = GetPlayers();
    if (!players.isEmpty())
    {
        WorldPackets::Misc::OverrideLight overrideLight;
        overrideLight.AreaLightID = _defaultLight;
        overrideLight.OverrideLightID = lightId;
        overrideLight.TransitionMilliseconds = fadeInTime;
        overrideLight.Write();

        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            if (Player* player = itr->GetSource())
                if (player->GetZoneId() == zoneId)
                    player->SendDirectMessage(overrideLight.GetRawPacket());
    }
}

void Map::UpdateAreaDependentAuras()
{
    Map::PlayerList const& players = GetPlayers();
    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        if (Player* player = itr->GetSource())
            if (player->IsInWorld())
            {
                player->UpdateAreaDependentAuras(player->GetAreaId());
                player->UpdateZoneDependentAuras(player->GetZoneId());
            }
}
