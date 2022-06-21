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

#include "Map.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "CharacterPackets.h"
#include "Conversation.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "DynamicTree.h"
#include "GameObjectModel.h"
#include "GameTime.h"
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
#include "Metric.h"
#include "MiscPackets.h"
#include "MMapFactory.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectGridLoader.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PhasingHandler.h"
#include "PoolMgr.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Transport.h"
#include "Vehicle.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "Weather.h"
#include "WeatherMgr.h"
#include "World.h"
#include "WorldSession.h"
#include <sstream>

#include "Hacks/boost_1_74_fibonacci_heap.h"
BOOST_1_74_FIBONACCI_HEAP_MSVC_COMPILE_FIX(RespawnListContainer::value_type)

#define DEFAULT_GRID_EXPIRY     300
#define MAX_GRID_LOAD_TIME      50
#define MAX_CREATURE_ATTACK_RADIUS  (45.0f * sWorld->getRate(RATE_CREATURE_AGGRO))

GridState* si_GridStates[MAX_GRID_STATE];

ZoneDynamicInfo::ZoneDynamicInfo() : MusicId(0), DefaultWeather(nullptr), WeatherId(WEATHER_STATE_FINE),
    Intensity(0.0f) { }

Map::~Map()
{
    // UnloadAll must be called before deleting the map

    sScriptMgr->OnDestroyMap(this);

    // Delete all waiting spawns, else there will be a memory leak
    // This doesn't delete from database.
    UnloadAllRespawnInfos();

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

    if (m_parentMap == this)
        delete m_childTerrainMaps;

    MMAP::MMapFactory::createOrGetMMapManager()->unloadMapInstance(GetId(), i_InstanceId);
}

void Map::DiscoverGridMapFiles()
{
    std::string tileListName = Trinity::StringFormat("%smaps/%04u.tilelist", sWorld->GetDataPath().c_str(), GetId());
    // tile list is optional
    if (FILE* tileList = fopen(tileListName.c_str(), "rb"))
    {
        u_map_magic mapMagic = { };
        uint32 versionMagic = { };
        uint32 build;
        char tilesData[MAX_NUMBER_OF_GRIDS * MAX_NUMBER_OF_GRIDS] = { };
        if (fread(mapMagic.data(), mapMagic.size(), 1, tileList) == 1
            && mapMagic == MapMagic
            && fread(&versionMagic, sizeof(versionMagic), 1, tileList) == 1
            && versionMagic == MapVersionMagic
            && fread(&build, sizeof(build), 1, tileList) == 1
            && fread(&tilesData[0], MAX_NUMBER_OF_GRIDS * MAX_NUMBER_OF_GRIDS, 1, tileList) == 1)
        {
            i_gridFileExists = std::bitset<MAX_NUMBER_OF_GRIDS * MAX_NUMBER_OF_GRIDS>(tilesData, std::size(tilesData));
            fclose(tileList);
            return;
        }

        fclose(tileList);
    }

    for (uint32 gx = 0; gx < MAX_NUMBER_OF_GRIDS; ++gx)
        for (uint32 gy = 0; gy < MAX_NUMBER_OF_GRIDS; ++gy)
            i_gridFileExists[gx * MAX_NUMBER_OF_GRIDS + gy] = ExistMap(GetId(), gx, gy, false);
}

Map* Map::GetRootParentTerrainMap()
{
    Map* map = this;
    while (map != map->m_parentTerrainMap)
        map = map->m_parentTerrainMap;

    return map;
}

bool Map::ExistMap(uint32 mapid, int gx, int gy, bool log /*= true*/)
{
    std::string fileName = Trinity::StringFormat("%smaps/%04u_%02u_%02u.map", sWorld->GetDataPath().c_str(), mapid, gx, gy);

    bool ret = false;
    FILE* file = fopen(fileName.c_str(), "rb");
    if (!file)
    {
        if (log)
        {
            TC_LOG_ERROR("maps", "Map file '%s' does not exist!", fileName.c_str());
            TC_LOG_ERROR("maps", "Please place MAP-files (*.map) in the appropriate directory (%s), or correct the DataDir setting in your worldserver.conf file.", (sWorld->GetDataPath() + "maps/").c_str());
        }
    }
    else
    {
        map_fileheader header;
        if (fread(&header, sizeof(header), 1, file) == 1)
        {
            if (header.mapMagic != MapMagic || header.versionMagic != MapVersionMagic)
            {
                if (log)
                    TC_LOG_ERROR("maps", "Map file '%s' is from an incompatible map version (%.*s v%u), %.*s v%u is expected. Please pull your source, recompile tools and recreate maps using the updated mapextractor, then replace your old map files with new files. If you still have problems search on forum for error TCE00018.",
                        fileName.c_str(), 4, header.mapMagic.data(), header.versionMagic, 4, MapMagic.data(), MapVersionMagic);
            }
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
            VMAP::LoadResult result = vmgr->existsMap((sWorld->GetDataPath() + "vmaps").c_str(), mapid, gx, gy);
            std::string name = vmgr->getDirFileName(mapid, gx, gy);
            switch (result)
            {
                case VMAP::LoadResult::Success:
                    break;
                case VMAP::LoadResult::FileNotFound:
                    TC_LOG_ERROR("maps", "VMap file '%s' does not exist", (sWorld->GetDataPath() + "vmaps/" + name).c_str());
                    TC_LOG_ERROR("maps", "Please place VMAP files (*.vmtree and *.vmtile) in the vmap directory (%s), or correct the DataDir setting in your worldserver.conf file.", (sWorld->GetDataPath() + "vmaps/").c_str());
                    return false;
                case VMAP::LoadResult::VersionMismatch:
                    TC_LOG_ERROR("maps", "VMap file '%s' couldn't be loaded", (sWorld->GetDataPath() + "vmaps/" + name).c_str());
                    TC_LOG_ERROR("maps", "This is because the version of the VMap file and the version of this module are different, please re-extract the maps with the tools compiled with this module.");
                    return false;
                case VMAP::LoadResult::ReadFromFileFailed:
                    TC_LOG_ERROR("maps", "VMap file '%s' couldn't be loaded", (sWorld->GetDataPath() + "vmaps/" + name).c_str());
                    TC_LOG_ERROR("maps", "This is because VMAP files are corrupted, please re-extract the maps with the tools compiled with this module.");
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

    bool mmapLoadResult = MMAP::MMapFactory::createOrGetMMapManager()->loadMap(sWorld->GetDataPath(), GetId(), gx, gy);

    if (mmapLoadResult)
        TC_LOG_DEBUG("mmaps.tiles", "MMAP loaded name:%s, id:%d, x:%d, y:%d (mmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx, gy, gx, gy);
    else
        TC_LOG_WARN("mmaps.tiles", "Could not load MMAP name:%s, id:%d, x:%d, y:%d (mmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx, gy, gx, gy);
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

void Map::LoadMap(int gx, int gy)
{
    LoadMapImpl(this, gx, gy);

    for (Map* childBaseMap : *m_childTerrainMaps)
        childBaseMap->LoadMap(gx, gy);
}

void Map::LoadMapImpl(Map* map, int gx, int gy)
{
    if (map->GridMaps[gx][gy])
        return;

    // map file name
    std::string fileName = Trinity::StringFormat("%smaps/%04u_%02u_%02u.map", sWorld->GetDataPath().c_str(), map->GetId(), gx, gy);
    TC_LOG_DEBUG("maps", "Loading map %s", fileName.c_str());
    // loading data
    std::shared_ptr<GridMap> gridMap = std::make_shared<GridMap>();
    GridMap::LoadResult gridMapLoadResult = gridMap->loadData(fileName.c_str());
    if (gridMapLoadResult == GridMap::LoadResult::Ok)
        map->GridMaps[gx][gy] = std::move(gridMap);
    else
    {
        map->i_gridFileExists[gx * MAX_NUMBER_OF_GRIDS + gy] = false;
        Map* parentTerrain = map;
        while (parentTerrain != parentTerrain->m_parentTerrainMap)
        {
            map->GridMaps[gx][gy] = parentTerrain->m_parentTerrainMap->GridMaps[gx][gy];
            if (map->GridMaps[gx][gy])
                break;

            parentTerrain = parentTerrain->m_parentTerrainMap;
        }
    }

    if (map->GridMaps[gx][gy])
        sScriptMgr->OnLoadGridMap(map, map->GridMaps[gx][gy].get(), gx, gy);
    else if (gridMapLoadResult == GridMap::LoadResult::InvalidFile)
        TC_LOG_ERROR("maps", "Error loading map file: %s", fileName.c_str());
}

void Map::UnloadMap(int gx, int gy)
{
    for (Map* childBaseMap : *m_childTerrainMaps)
        childBaseMap->UnloadMap(gx, gy);

    UnloadMapImpl(this, gx, gy);
}

void Map::UnloadMapImpl(Map* map, int gx, int gy)
{
    map->GridMaps[gx][gy] = nullptr;
}

void Map::LoadMapAndVMap(int gx, int gy)
{
    LoadMap(gx, gy);
    // Only load the data for the base map
    if (this == m_parentMap)
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
    si_GridStates[GRID_STATE_INVALID] = new InvalidState();
    si_GridStates[GRID_STATE_ACTIVE] = new ActiveState();
    si_GridStates[GRID_STATE_IDLE] = new IdleState();
    si_GridStates[GRID_STATE_REMOVAL] = new RemovalState();
}

void Map::DeleteStateMachine()
{
    delete si_GridStates[GRID_STATE_INVALID];
    delete si_GridStates[GRID_STATE_ACTIVE];
    delete si_GridStates[GRID_STATE_IDLE];
    delete si_GridStates[GRID_STATE_REMOVAL];
}

Map::Map(uint32 id, time_t expiry, uint32 InstanceId, Difficulty SpawnMode, Map* _parent):
_creatureToMoveLock(false), _gameObjectsToMoveLock(false), _dynamicObjectsToMoveLock(false), _areaTriggersToMoveLock(false),
i_mapEntry(sMapStore.LookupEntry(id)), i_spawnMode(SpawnMode), i_InstanceId(InstanceId),
m_unloadTimer(0), m_VisibleDistance(DEFAULT_VISIBILITY_DISTANCE),
m_VisibilityNotifyPeriod(DEFAULT_VISIBILITY_NOTIFY_PERIOD),
m_activeNonPlayersIter(m_activeNonPlayers.end()), _transportsUpdateIter(_transports.end()),
i_gridExpiry(expiry),
i_scriptLock(false), _respawnCheckTimer(0)
{
    if (_parent)
    {
        m_parentMap = _parent;
        m_parentTerrainMap = m_parentMap->m_parentTerrainMap;
        m_childTerrainMaps = m_parentMap->m_childTerrainMaps;
    }
    else
    {
        m_parentMap = this;
        m_parentTerrainMap = this;
        m_childTerrainMaps = new std::vector<Map*>();
    }

    for (uint32 x = 0; x < MAX_NUMBER_OF_GRIDS; ++x)
    {
        for (uint32 y = 0; y < MAX_NUMBER_OF_GRIDS; ++y)
        {
            //z code
            GridMaps[x][y] = nullptr;
            GridMapReference[x][y] = 0;
            setNGrid(nullptr, x, y);
        }
    }

    _zonePlayerCountMap.clear();

    //lets initialize visibility distance for map
    Map::InitVisibilityDistance();

    _weatherUpdateTimer.SetInterval(time_t(1 * IN_MILLISECONDS));

    GetGuidSequenceGenerator<HighGuid::Transport>().Set(sObjectMgr->GetGenerator<HighGuid::Transport>().GetNextAfterMaxUsed());

    _poolData = sPoolMgr->InitPoolsForMap(this);

    sTransportMgr->CreateTransportsForMap(this);

    MMAP::MMapFactory::createOrGetMMapManager()->loadMapInstance(sWorld->GetDataPath(), GetId(), i_InstanceId);

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
    if (obj->IsWorldObject())
        grid->GetGridType(cell.CellX(), cell.CellY()).AddWorldObject(obj);
    else
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
    ASSERT(ngrid != nullptr);

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

void Map::EnsureGridCreated(GridCoord const& p)
{
    std::lock_guard<std::mutex> lock(_gridLock);
    EnsureGridCreated_i(p);
}

//Create NGrid so the object can be added to it
//But object data is not loaded here
void Map::EnsureGridCreated_i(GridCoord const& p)
{
    if (!getNGrid(p.x_coord, p.y_coord))
    {
        TC_LOG_DEBUG("maps", "Creating grid[%u, %u] for map %u instance %u", p.x_coord, p.y_coord, GetId(), i_InstanceId);

        NGridType* ngrid = new NGridType(p.x_coord * MAX_NUMBER_OF_GRIDS + p.y_coord, p.x_coord, p.y_coord, i_gridExpiry, sWorld->getBoolConfig(CONFIG_GRID_UNLOAD));
        setNGrid(ngrid, p.x_coord, p.y_coord);

        // build a linkage between this map and NGridType
        buildNGridLinkage(ngrid);

        ngrid->SetGridState(GRID_STATE_IDLE);

        //z coord
        int gx = (MAX_NUMBER_OF_GRIDS - 1) - p.x_coord;
        int gy = (MAX_NUMBER_OF_GRIDS - 1) - p.y_coord;

        if (!GridMaps[gx][gy])
        {
            Map* rootParentTerrainMap = m_parentMap->GetRootParentTerrainMap();
            // because LoadMapAndVMap is always entered using rootParentTerrainMap, we can only lock that once and not have to do it for every child map
            std::unique_lock<std::mutex> lock(rootParentTerrainMap->_gridLock, std::defer_lock);
            if (this != rootParentTerrainMap)
                lock.lock();

            if (!m_parentMap->GridMaps[gx][gy])
                rootParentTerrainMap->LoadMapAndVMap(gx, gy);

            if (m_parentMap->GridMaps[gx][gy])
            {
                GridMaps[gx][gy] = m_parentMap->GridMaps[gx][gy];
                ++rootParentTerrainMap->GridMapReference[gx][gy];
            }
        }
    }
}

//Load NGrid and make it active
void Map::EnsureGridLoadedForActiveObject(Cell const& cell, WorldObject const* object)
{
    EnsureGridLoaded(cell);
    NGridType *grid = getNGrid(cell.GridX(), cell.GridY());
    ASSERT(grid != nullptr);

    if (object->IsPlayer())
        GetMultiPersonalPhaseTracker().LoadGrid(object->GetPhaseShift(), *grid, this, cell);

    // refresh grid state & timer
    if (grid->GetGridState() != GRID_STATE_ACTIVE)
    {
        TC_LOG_DEBUG("maps", "Active object %s triggers loading of grid [%u, %u] on map %u", object->GetGUID().ToString().c_str(), cell.GridX(), cell.GridY(), GetId());
        ResetGridExpiry(*grid, 0.1f);
        grid->SetGridState(GRID_STATE_ACTIVE);
    }
}

//Create NGrid and load the object data in it
bool Map::EnsureGridLoaded(Cell const& cell)
{
    EnsureGridCreated(GridCoord(cell.GridX(), cell.GridY()));
    NGridType *grid = getNGrid(cell.GridX(), cell.GridY());

    ASSERT(grid != nullptr);
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

void Map::GridMarkNoUnload(uint32 x, uint32 y)
{
    // First make sure this grid is loaded
    float gX = ((float(x) - 0.5f - CENTER_GRID_ID) * SIZE_OF_GRIDS) + (CENTER_GRID_OFFSET * 2);
    float gY = ((float(y) - 0.5f - CENTER_GRID_ID) * SIZE_OF_GRIDS) + (CENTER_GRID_OFFSET * 2);
    Cell cell = Cell(gX, gY);
    EnsureGridLoaded(cell);

    // Mark as don't unload
    NGridType* grid = getNGrid(x, y);
    grid->setUnloadExplicitLock(true);
}

void Map::GridUnmarkNoUnload(uint32 x, uint32 y)
{
    // If grid is loaded, clear unload lock
    if (IsGridLoaded(GridCoord(x, y)))
    {
        NGridType* grid = getNGrid(x, y);
        grid->setUnloadExplicitLock(false);
    }
}

void Map::LoadGrid(float x, float y)
{
    EnsureGridLoaded(Cell(x, y));
}

void Map::LoadGridForActiveObject(float x, float y, WorldObject const* object)
{
    EnsureGridLoadedForActiveObject(Cell(x, y), object);
}

bool Map::AddPlayerToMap(Player* player, bool initPlayer /*= true*/)
{
    CellCoord cellCoord = Trinity::ComputeCellCoord(player->GetPositionX(), player->GetPositionY());
    if (!cellCoord.IsCoordValid())
    {
        TC_LOG_ERROR("maps", "Map::Add: Player %s has invalid coordinates X:%f Y:%f grid cell [%u:%u]", player->GetGUID().ToString().c_str(), player->GetPositionX(), player->GetPositionY(), cellCoord.x_coord, cellCoord.y_coord);
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
    PhasingHandler::SendToPlayer(player);

    if (player->IsAlive())
        ConvertCorpseToBones(player->GetGUID());

    sScriptMgr->OnPlayerEnterMap(this, player);
    return true;
}

void Map::UpdatePersonalPhasesForPlayer(Player const* player)
{
    Cell cell(player->GetPositionX(), player->GetPositionY());
    GetMultiPersonalPhaseTracker().OnOwnerPhaseChanged(player, getNGrid(cell.GridX(), cell.GridY()), this, cell);
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

    //something, such as vehicle, needs to be update immediately
    //also, trigger needs to cast spell, if not update, cannot see visual
    obj->SetIsNewObject(true);
    obj->UpdateObjectVisibilityOnCreate();
    obj->SetIsNewObject(false);
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

    _transports.insert(obj);

    if (obj->GetExpectedMapId() == GetId())
    {
        obj->AddToWorld();

        // Broadcast creation to players
        for (Map::PlayerList::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        {
            if (itr->GetSource()->GetTransport() != obj && itr->GetSource()->IsInPhase(obj))
            {
                UpdateData data(GetId());
                obj->BuildCreateUpdateBlockForPlayer(&data, itr->GetSource());
                itr->GetSource()->m_visibleTransports.insert(obj->GetGUID());
                WorldPacket packet;
                data.BuildPacket(&packet);
                itr->GetSource()->SendDirectMessage(&packet);
            }
        }
    }

    return true;
}

bool Map::IsGridLoaded(GridCoord const& p) const
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

void Map::UpdatePlayerZoneStats(uint32 oldZone, uint32 newZone)
{
    // Nothing to do if no change
    if (oldZone == newZone)
        return;

    if (oldZone != MAP_INVALID_ZONE)
    {
        uint32& oldZoneCount = _zonePlayerCountMap[oldZone];
        ASSERT(oldZoneCount, "A player left zone %u (went to %u) - but there were no players in the zone!", oldZone, newZone);
        --oldZoneCount;
    }
    ++_zonePlayerCountMap[newZone];
}

void Map::Update(uint32 t_diff)
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

    /// process any due respawns
    if (_respawnCheckTimer <= t_diff)
    {
        ProcessRespawns();
        _respawnCheckTimer = sWorld->getIntConfig(CONFIG_RESPAWN_MINCHECKINTERVALMS);
    }
    else
        _respawnCheckTimer -= t_diff;

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

        // If player is using far sight or mind vision, visit that object too
        if (WorldObject* viewPoint = player->GetViewpoint())
            VisitNearbyCellsOf(viewPoint, grid_object_update, world_object_update);

        // Handle updates for creatures in combat with player and are more than 60 yards away
        if (player->IsInCombat())
        {
            std::vector<Unit*> toVisit;
            for (auto const& pair : player->GetCombatManager().GetPvECombatRefs())
                if (Creature* unit = pair.second->GetOther(player)->ToCreature())
                    if (unit->GetMapId() == player->GetMapId() && !unit->IsWithinDistInMap(player, GetVisibilityRange(), false))
                        toVisit.push_back(unit);
            for (Unit* unit : toVisit)
                VisitNearbyCellsOf(unit, grid_object_update, world_object_update);
        }

        { // Update any creatures that own auras the player has applications of
            std::unordered_set<Unit*> toVisit;
            for (std::pair<uint32, AuraApplication*> pair : player->GetAppliedAuras())
            {
                if (Unit* caster = pair.second->GetBase()->GetCaster())
                    if (caster->GetTypeId() != TYPEID_PLAYER && !caster->IsWithinDistInMap(player, GetVisibilityRange(), false))
                        toVisit.insert(caster);
            }
            for (Unit* unit : toVisit)
                VisitNearbyCellsOf(unit, grid_object_update, world_object_update);
        }

        { // Update player's summons
            std::vector<Unit*> toVisit;

            // Totems
            for (ObjectGuid const& summonGuid : player->m_SummonSlot)
                if (!summonGuid.IsEmpty())
                    if (Creature* unit = GetCreature(summonGuid))
                        if (unit->GetMapId() == player->GetMapId() && !unit->IsWithinDistInMap(player, GetVisibilityRange(), false))
                            toVisit.push_back(unit);

            for (Unit* unit : toVisit)
                VisitNearbyCellsOf(unit, grid_object_update, world_object_update);
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

    _weatherUpdateTimer.Update(t_diff);
    if (_weatherUpdateTimer.Passed())
    {
        for (auto&& zoneInfo : _zoneDynamicInfo)
            if (zoneInfo.second.DefaultWeather && !zoneInfo.second.DefaultWeather->Update(_weatherUpdateTimer.GetInterval()))
                zoneInfo.second.DefaultWeather.reset();

        _weatherUpdateTimer.Reset();
    }

    // update phase shift objects
    GetMultiPersonalPhaseTracker().Update(this, t_diff);

    MoveAllCreaturesInMoveList();
    MoveAllGameObjectsInMoveList();
    MoveAllAreaTriggersInMoveList();

    if (!m_mapRefManager.isEmpty() || !m_activeNonPlayers.empty())
        ProcessRelocationNotifies(t_diff);

    sScriptMgr->OnMapUpdate(this, t_diff);

    TC_METRIC_VALUE("map_creatures", uint64(GetObjectsStore().Size<Creature>()),
        TC_METRIC_TAG("map_id", std::to_string(GetId())),
        TC_METRIC_TAG("map_instanceid", std::to_string(GetInstanceId())));

    TC_METRIC_VALUE("map_gameobjects", uint64(GetObjectsStore().Size<GameObject>()),
        TC_METRIC_TAG("map_id", std::to_string(GetId())),
        TC_METRIC_TAG("map_instanceid", std::to_string(GetInstanceId())));
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
    // Before leaving map, update zone/area for stats
    player->UpdateZone(MAP_INVALID_ZONE, 0);
    sScriptMgr->OnPlayerLeaveMap(this, player);

    GetMultiPersonalPhaseTracker().MarkAllPhasesForDeletion(player->GetGUID());

    player->CombatStop();

    bool const inWorld = player->IsInWorld();
    player->RemoveFromWorld();
    SendRemoveTransports(player);

    if (!inWorld) // if was in world, RemoveFromWorld() called DestroyForNearbyPlayers()
        player->UpdateObjectVisibilityOnDestroy();

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
    bool const inWorld = obj->IsInWorld() && obj->GetTypeId() >= TYPEID_UNIT && obj->GetTypeId() <= TYPEID_GAMEOBJECT;
    obj->RemoveFromWorld();
    if (obj->isActiveObject())
        RemoveFromActive(obj);

    GetMultiPersonalPhaseTracker().UnregisterTrackedObject(obj);

    if (!inWorld) // if was in world, RemoveFromWorld() called DestroyForNearbyPlayers()
        obj->UpdateObjectVisibilityOnDestroy();

    obj->RemoveFromGrid();

    obj->ResetMap();

    if (remove)
        DeleteFromWorld(obj);
}

template<>
void Map::RemoveFromMap(Transport* obj, bool remove)
{
    if (obj->IsInWorld())
    {
        obj->RemoveFromWorld();

        UpdateData data(GetId());
        if (obj->IsDestroyedObject())
            obj->BuildDestroyUpdateBlock(&data);
        else
            obj->BuildOutOfRangeUpdateBlock(&data);

        WorldPacket packet;
        data.BuildPacket(&packet);
        for (Map::PlayerList::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        {
            if (itr->GetSource()->GetTransport() != obj && itr->GetSource()->m_visibleTransports.count(obj->GetGUID()))
            {
                itr->GetSource()->SendDirectMessage(&packet);
                itr->GetSource()->m_visibleTransports.erase(obj->GetGUID());
            }
        }
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
        DeleteFromWorld(obj);
}

template <typename T>
/*static*/ bool Map::CheckGridIntegrity(T* object, bool moved, char const* objType)
{
    Cell const& cur_cell = object->GetCurrentCell();
    Cell xy_cell(object->GetPositionX(), object->GetPositionY());
    if (xy_cell != cur_cell)
    {
        TC_LOG_DEBUG("maps", "%s %s X: %f Y: %f (%s) is in grid[%u, %u]cell[%u, %u] instead of grid[%u, %u]cell[%u, %u]",
            objType, object->GetGUID().ToString().c_str(),
            object->GetPositionX(), object->GetPositionY(), (moved ? "final" : "original"),
            cur_cell.GridX(), cur_cell.GridY(), cur_cell.CellX(), cur_cell.CellY(),
            xy_cell.GridX(), xy_cell.GridY(), xy_cell.CellX(), xy_cell.CellY());
        return true;                                        // not crash at error, just output error in debug mode
    }

    return true;
}

void Map::PlayerRelocation(Player* player, float x, float y, float z, float orientation)
{
    ASSERT(player);

    Cell old_cell(player->GetPositionX(), player->GetPositionY());
    Cell new_cell(x, y);

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

    player->UpdatePositionData();
    player->UpdateObjectVisibility(false);
}

void Map::CreatureRelocation(Creature* creature, float x, float y, float z, float ang, bool respawnRelocationOnFail)
{
    ASSERT(CheckGridIntegrity(creature, false, "Creature"));

    Cell new_cell(x, y);

    if (!respawnRelocationOnFail && !getNGrid(new_cell.GridX(), new_cell.GridY()))
        return;

    Cell old_cell = creature->GetCurrentCell();
    // delay creature move for grid/cell to grid/cell moves
    if (old_cell.DiffCell(new_cell) || old_cell.DiffGrid(new_cell))
    {
#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "Creature %s added to moving list from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", creature->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
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
        creature->UpdatePositionData();
        RemoveCreatureFromMoveList(creature);
    }

    ASSERT(CheckGridIntegrity(creature, true, "Creature"));
}

void Map::GameObjectRelocation(GameObject* go, float x, float y, float z, float orientation, bool respawnRelocationOnFail)
{
    ASSERT(CheckGridIntegrity(go, false, "GameObject"));
    Cell new_cell(x, y);

    if (!respawnRelocationOnFail && !getNGrid(new_cell.GridX(), new_cell.GridY()))
        return;

    Cell old_cell = go->GetCurrentCell();

    // delay creature move for grid/cell to grid/cell moves
    if (old_cell.DiffCell(new_cell) || old_cell.DiffGrid(new_cell))
    {
#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "GameObject %s added to moving list from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif
        AddGameObjectToMoveList(go, x, y, z, orientation);
        // in diffcell/diffgrid case notifiers called at finishing move go in Map::MoveAllGameObjectsInMoveList
    }
    else
    {
        go->Relocate(x, y, z, orientation);
        go->AfterRelocation();
        RemoveGameObjectFromMoveList(go);
    }

    ASSERT(CheckGridIntegrity(go, true, "GameObject"));
}

void Map::DynamicObjectRelocation(DynamicObject* dynObj, float x, float y, float z, float orientation)
{
    ASSERT(CheckGridIntegrity(dynObj, false, "DynamicObject"));
    Cell new_cell(x, y);

    if (!getNGrid(new_cell.GridX(), new_cell.GridY()))
        return;

    Cell old_cell = dynObj->GetCurrentCell();

    // delay creature move for grid/cell to grid/cell moves
    if (old_cell.DiffCell(new_cell) || old_cell.DiffGrid(new_cell))
    {
#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "GameObject %s added to moving list from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", dynObj->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif
        AddDynamicObjectToMoveList(dynObj, x, y, z, orientation);
        // in diffcell/diffgrid case notifiers called at finishing move dynObj in Map::MoveAllGameObjectsInMoveList
    }
    else
    {
        dynObj->Relocate(x, y, z, orientation);
        dynObj->UpdatePositionData();
        dynObj->UpdateObjectVisibility(false);
        RemoveDynamicObjectFromMoveList(dynObj);
    }

    ASSERT(CheckGridIntegrity(dynObj, true, "DynamicObject"));
}

void Map::AreaTriggerRelocation(AreaTrigger* at, float x, float y, float z, float orientation)
{
    ASSERT(CheckGridIntegrity(at, false, "AreaTrigger"));
    Cell new_cell(x, y);

    if (!getNGrid(new_cell.GridX(), new_cell.GridY()))
        return;

    Cell old_cell = at->GetCurrentCell();

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

    ASSERT(CheckGridIntegrity(at, true, "AreaTrigger"));
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
            c->UpdatePositionData();
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
                TC_LOG_DEBUG("maps", "Creature %s cannot be move to unloaded respawn grid.", c->GetGUID().ToString().c_str());
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
            go->AfterRelocation();
        }
        else
        {
            // if GameObject can't be move in new cell/grid (not loaded) move it to repawn cell/grid
            // GameObject coordinates will be updated and notifiers send
            if (!GameObjectRespawnRelocation(go, false))
            {
                // ... or unload (if respawn grid also not loaded)
#ifdef TRINITY_DEBUG
                TC_LOG_DEBUG("maps", "GameObject %s cannot be move to unloaded respawn grid.", go->GetGUID().ToString().c_str());
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
            dynObj->UpdatePositionData();
            dynObj->UpdateObjectVisibility(false);
        }
        else
        {
#ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "DynamicObject %s cannot be moved to unloaded grid.", dynObj->GetGUID().ToString().c_str());
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
            at->UpdateShape();
            at->UpdateObjectVisibility(false);
        }
        else
        {
#ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "AreaTrigger %s cannot be moved to unloaded grid.", at->GetGUID().ToString().c_str());
#endif
        }
    }

    _areaTriggersToMove.clear();
    _areaTriggersToMoveLock = false;
}

template <typename T>
bool Map::MapObjectCellRelocation(T* object, Cell new_cell, [[maybe_unused]] char const* objType)
{
    Cell const& old_cell = object->GetCurrentCell();
    if (!old_cell.DiffGrid(new_cell))                       // in same grid
    {
        // if in same cell then none do
        if (old_cell.DiffCell(new_cell))
        {
#ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "%s %s moved in grid[%u, %u] from cell[%u, %u] to cell[%u, %u].", objType, object->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.CellX(), new_cell.CellY());
#endif

            object->RemoveFromGrid();
            AddToGrid(object, new_cell);
        }
        else
        {
#ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "%s %s moved in same grid[%u, %u]cell[%u, %u].", objType, object->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY());
#endif
        }

        return true;
    }

    // in diff. grids but active creature
    if (object->isActiveObject())
    {
        EnsureGridLoadedForActiveObject(new_cell, object);

#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "Active %s %s moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", objType, object->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif

        object->RemoveFromGrid();
        AddToGrid(object, new_cell);

        return true;
    }

    if (Creature* c = object->ToCreature())
        if (c->GetCharmerOrOwnerGUID().IsPlayer())
            EnsureGridLoaded(new_cell);

    // in diff. loaded grid normal object
    if (IsGridLoaded(GridCoord(new_cell.GridX(), new_cell.GridY())))
    {
#ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("maps", "%s %s moved from grid[%u, %u]cell[%u, %u] to grid[%u, %u]cell[%u, %u].", objType, object->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif

        object->RemoveFromGrid();
        EnsureGridCreated(GridCoord(new_cell.GridX(), new_cell.GridY()));
        AddToGrid(object, new_cell);

        return true;
    }

    // fail to move: normal object attempt move to unloaded grid
#ifdef TRINITY_DEBUG
    TC_LOG_DEBUG("maps", "%s %s attempted to move from grid[%u, %u]cell[%u, %u] to unloaded grid[%u, %u]cell[%u, %u].", objType, object->GetGUID().ToString().c_str(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
#endif
    return false;
}

bool Map::CreatureCellRelocation(Creature* c, Cell new_cell)
{
    return MapObjectCellRelocation(c, new_cell, "Creature");
}

bool Map::GameObjectCellRelocation(GameObject* go, Cell new_cell)
{
    return MapObjectCellRelocation(go, new_cell, "GameObject");
}

bool Map::DynamicObjectCellRelocation(DynamicObject* go, Cell new_cell)
{
    return MapObjectCellRelocation(go, new_cell, "DynamicObject");
}

bool Map::AreaTriggerCellRelocation(AreaTrigger* at, Cell new_cell)
{
    return MapObjectCellRelocation(at, new_cell, "AreaTrigger");
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
    TC_LOG_DEBUG("maps", "Creature %s moved from grid[%u, %u]cell[%u, %u] to respawn grid[%u, %u]cell[%u, %u].", c->GetGUID().ToString().c_str(), c->GetCurrentCell().GridX(), c->GetCurrentCell().GridY(), c->GetCurrentCell().CellX(), c->GetCurrentCell().CellY(), resp_cell.GridX(), resp_cell.GridY(), resp_cell.CellX(), resp_cell.CellY());
#endif

    // teleport it to respawn point (like normal respawn if player see)
    if (CreatureCellRelocation(c, resp_cell))
    {
        c->Relocate(resp_x, resp_y, resp_z, resp_o);
        c->GetMotionMaster()->Initialize(); // prevent possible problems with default move generators
        //CreatureRelocationNotify(c, resp_cell, resp_cell.GetCellCoord());
        c->UpdatePositionData();
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
    TC_LOG_DEBUG("maps", "GameObject %s moved from grid[%u, %u]cell[%u, %u] to respawn grid[%u, %u]cell[%u, %u].", go->GetGUID().ToString().c_str(), go->GetCurrentCell().GridX(), go->GetCurrentCell().GridY(), go->GetCurrentCell().CellX(), go->GetCurrentCell().CellY(), resp_cell.GridX(), resp_cell.GridY(), resp_cell.CellX(), resp_cell.CellY());
#endif

    // teleport it to respawn point (like normal respawn if player see)
    if (GameObjectCellRelocation(go, resp_cell))
    {
        go->Relocate(resp_x, resp_y, resp_z, resp_o);
        go->UpdatePositionData();
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

        // After removing all objects from the map, purge empty tracked phases
        GetMultiPersonalPhaseTracker().UnloadGrid(ngrid);

        {
            ObjectGridUnloader worker;
            TypeContainerVisitor<ObjectGridUnloader, GridTypeMapContainer> visitor(worker);
            ngrid.VisitAllGrids(visitor);
        }

        ASSERT(i_objectsToRemove.empty());

        delete &ngrid;
        setNGrid(nullptr, x, y);
    }
    int gx = (MAX_NUMBER_OF_GRIDS - 1) - x;
    int gy = (MAX_NUMBER_OF_GRIDS - 1) - y;

    // delete grid map, but don't delete if it is from parent map (and thus only reference)
    if (GridMaps[gx][gy])
    {
        Map* terrainRoot = m_parentMap->GetRootParentTerrainMap();
        if (!--terrainRoot->GridMapReference[gx][gy])
        {
            m_parentMap->GetRootParentTerrainMap()->UnloadMap(gx, gy);
            VMAP::VMapFactory::createOrGetVMapManager()->unloadMap(terrainRoot->GetId(), gx, gy);
            MMAP::MMapFactory::createOrGetMMapManager()->unloadMap(terrainRoot->GetId(), gx, gy);
        }
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
                player->TeleportTo(player->m_homebind);
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
    _minHeightPlanes = nullptr;
    // Liquid data
    _liquidGlobalEntry = 0;
    _liquidGlobalFlags = map_liquidHeaderTypeFlags::NoWater;
    _liquidOffX   = 0;
    _liquidOffY   = 0;
    _liquidWidth  = 0;
    _liquidHeight = 0;
    _liquidLevel = INVALID_HEIGHT;
    _liquidEntry = nullptr;
    _liquidFlags = nullptr;
    _liquidMap  = nullptr;
    _holes = nullptr;
}

GridMap::~GridMap()
{
    unloadData();
}

GridMap::LoadResult GridMap::loadData(char const* filename)
{
    // Unload old data if exist
    unloadData();

    map_fileheader header;
    // Not return error if file not found
    FILE* in = fopen(filename, "rb");
    if (!in)
        return LoadResult::FileDoesNotExist;

    if (fread(&header, sizeof(header), 1, in) != 1)
    {
        fclose(in);
        return LoadResult::InvalidFile;
    }

    if (header.mapMagic == MapMagic && header.versionMagic == MapVersionMagic)
    {
        // load up area data
        if (header.areaMapOffset && !loadAreaData(in, header.areaMapOffset, header.areaMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map area data\n");
            fclose(in);
            return LoadResult::InvalidFile;
        }
        // load up height data
        if (header.heightMapOffset && !loadHeightData(in, header.heightMapOffset, header.heightMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map height data\n");
            fclose(in);
            return LoadResult::InvalidFile;
        }
        // load up liquid data
        if (header.liquidMapOffset && !loadLiquidData(in, header.liquidMapOffset, header.liquidMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map liquids data\n");
            fclose(in);
            return LoadResult::InvalidFile;
        }
        // loadup holes data (if any. check header.holesOffset)
        if (header.holesSize && !loadHolesData(in, header.holesOffset, header.holesSize))
        {
            TC_LOG_ERROR("maps", "Error loading map holes data\n");
            fclose(in);
            return LoadResult::InvalidFile;
        }
        fclose(in);
        return LoadResult::Ok;
    }

    TC_LOG_ERROR("maps", "Map file '%s' is from an incompatible map version (%.*s v%u), %.*s v%u is expected. Please pull your source, recompile tools and recreate maps using the updated mapextractor, then replace your old map files with new files. If you still have problems search on forum for error TCE00018.",
        filename, 4, header.mapMagic.data(), header.versionMagic, 4, MapMagic.data(), MapVersionMagic);
    fclose(in);
    return LoadResult::InvalidFile;
}

void GridMap::unloadData()
{
    delete[] _areaMap;
    delete[] m_V9;
    delete[] m_V8;
    delete[] _minHeightPlanes;
    delete[] _liquidEntry;
    delete[] _liquidFlags;
    delete[] _liquidMap;
    delete[] _holes;
    _areaMap = nullptr;
    m_V9 = nullptr;
    m_V8 = nullptr;
    _minHeightPlanes = nullptr;
    _liquidEntry = nullptr;
    _liquidFlags = nullptr;
    _liquidMap  = nullptr;
    _holes = nullptr;
    _gridGetHeight = &GridMap::getHeightFromFlat;
}

bool GridMap::loadAreaData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_areaHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.areaMagic != MapAreaMagic)
        return false;

    _gridArea = header.gridArea;
    if (!header.flags.HasFlag(map_areaHeaderFlags::NoArea))
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

    if (fread(&header, sizeof(header), 1, in) != 1 || header.heightMagic != MapHeightMagic)
        return false;

    _gridHeight = header.gridHeight;
    if (!header.flags.HasFlag(map_heightHeaderFlags::NoHeight))
    {
        if (header.flags.HasFlag(map_heightHeaderFlags::HeightAsInt16))
        {
            m_uint16_V9 = new uint16 [129*129];
            m_uint16_V8 = new uint16 [128*128];
            if (fread(m_uint16_V9, sizeof(uint16), 129*129, in) != 129*129 ||
                fread(m_uint16_V8, sizeof(uint16), 128*128, in) != 128*128)
                return false;
            _gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 65535;
            _gridGetHeight = &GridMap::getHeightFromUint16;
        }
        else if (header.flags.HasFlag(map_heightHeaderFlags::HeightAsInt8))
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

    if (header.flags.HasFlag(map_heightHeaderFlags::HasFlightBounds))
    {
        std::array<int16, 9> maxHeights;
        std::array<int16, 9> minHeights;
        if (fread(maxHeights.data(), sizeof(int16), maxHeights.size(), in) != maxHeights.size() ||
            fread(minHeights.data(), sizeof(int16), minHeights.size(), in) != minHeights.size())
            return false;

        static uint32 constexpr indices[8][3] =
        {
            { 3, 0, 4 },
            { 0, 1, 4 },
            { 1, 2, 4 },
            { 2, 5, 4 },
            { 5, 8, 4 },
            { 8, 7, 4 },
            { 7, 6, 4 },
            { 6, 3, 4 }
        };

        static float constexpr boundGridCoords[9][2] =
        {
            { 0.0f, 0.0f },
            { 0.0f, -266.66666f },
            { 0.0f, -533.33331f },
            { -266.66666f, 0.0f },
            { -266.66666f, -266.66666f },
            { -266.66666f, -533.33331f },
            { -533.33331f, 0.0f },
            { -533.33331f, -266.66666f },
            { -533.33331f, -533.33331f }
        };

        _minHeightPlanes = new G3D::Plane[8];
        for (uint32 quarterIndex = 0; quarterIndex < 8; ++quarterIndex)
            _minHeightPlanes[quarterIndex] = G3D::Plane(
                G3D::Vector3(boundGridCoords[indices[quarterIndex][0]][0], boundGridCoords[indices[quarterIndex][0]][1], minHeights[indices[quarterIndex][0]]),
                G3D::Vector3(boundGridCoords[indices[quarterIndex][1]][0], boundGridCoords[indices[quarterIndex][1]][1], minHeights[indices[quarterIndex][1]]),
                G3D::Vector3(boundGridCoords[indices[quarterIndex][2]][0], boundGridCoords[indices[quarterIndex][2]][1], minHeights[indices[quarterIndex][2]])
            );
    }

    return true;
}

bool GridMap::loadLiquidData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_liquidHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.liquidMagic != MapLiquidMagic)
        return false;

    _liquidGlobalEntry = header.liquidType;
    _liquidGlobalFlags = header.liquidFlags;
    _liquidOffX  = header.offsetX;
    _liquidOffY  = header.offsetY;
    _liquidWidth = header.width;
    _liquidHeight = header.height;
    _liquidLevel  = header.liquidLevel;

    if (!header.flags.HasFlag(map_liquidHeaderFlags::NoType))
    {
        _liquidEntry = new uint16[16*16];
        if (fread(_liquidEntry, sizeof(uint16), 16*16, in) != 16*16)
            return false;

        _liquidFlags = new map_liquidHeaderTypeFlags[16*16];
        if (fread(_liquidFlags, sizeof(map_liquidHeaderTypeFlags), 16*16, in) != 16*16)
            return false;
    }
    if (!header.flags.HasFlag(map_liquidHeaderFlags::NoHeight))
    {
        _liquidMap = new float[uint32(_liquidWidth) * uint32(_liquidHeight)];
        if (fread(_liquidMap, sizeof(float), _liquidWidth*_liquidHeight, in) != (uint32(_liquidWidth) * uint32(_liquidHeight)))
            return false;
    }
    return true;
}

bool GridMap::loadHolesData(FILE* in, uint32 offset, uint32 /*size*/)
{
    if (fseek(in, offset, SEEK_SET) != 0)
        return false;

    _holes = new uint8[16 * 16 * 8];
    if (fread(_holes, sizeof(uint8), 16 * 16 * 8, in) != 16 * 16 * 8)
        return false;

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

    if (isHole(x_int, y_int))
        return INVALID_HEIGHT;

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

    if (isHole(x_int, y_int))
        return INVALID_HEIGHT;

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

    if (isHole(x_int, y_int))
        return INVALID_HEIGHT;

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

bool GridMap::isHole(int row, int col) const
{
    if (!_holes)
        return false;

    int cellRow = row / 8;     // 8 squares per cell
    int cellCol = col / 8;
    int holeRow = row % 8;
    int holeCol = col % 8;

    return (_holes[cellRow * 16 * 8 + cellCol * 8 + holeRow] & (1 << holeCol)) != 0;
}

float GridMap::getMinHeight(float x, float y) const
{
    if (!_minHeightPlanes)
        return -500.0f;

    GridCoord gridCoord = Trinity::ComputeGridCoordSimple(x, y);

    int32 doubleGridX = int32(std::floor(-(x - MAP_HALFSIZE) / CENTER_GRID_OFFSET));
    int32 doubleGridY = int32(std::floor(-(y - MAP_HALFSIZE) / CENTER_GRID_OFFSET));

    float gx = x - (int32(gridCoord.x_coord) - CENTER_GRID_ID + 1) * SIZE_OF_GRIDS;
    float gy = y - (int32(gridCoord.y_coord) - CENTER_GRID_ID + 1) * SIZE_OF_GRIDS;

    uint32 quarterIndex = 0;
    if (doubleGridY & 1)
    {
        if (doubleGridX & 1)
            quarterIndex = 4 + (gx <= gy);
        else
            quarterIndex = 2 + ((-SIZE_OF_GRIDS - gx) > gy);
    }
    else if (doubleGridX & 1)
        quarterIndex = 6 + ((-SIZE_OF_GRIDS - gx) <= gy);
    else
        quarterIndex = gx > gy;

    G3D::Ray ray = G3D::Ray::fromOriginAndDirection(G3D::Vector3(gx, gy, 0.0f), G3D::Vector3::unitZ());
    return ray.intersection(_minHeightPlanes[quarterIndex]).z;
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

// Get water state on map
inline ZLiquidStatus GridMap::GetLiquidStatus(float x, float y, float z, Optional<map_liquidHeaderTypeFlags> ReqLiquidType, LiquidData* data, float collisionHeight)
{
    // Check water type (if no water return)
    if (_liquidGlobalFlags == map_liquidHeaderTypeFlags::NoWater && !_liquidFlags)
        return LIQUID_MAP_NO_WATER;

    // Get cell
    float cx = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    float cy = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int x_int = (int)cx & (MAP_RESOLUTION-1);
    int y_int = (int)cy & (MAP_RESOLUTION-1);

    // Check water type in cell
    int idx=(x_int>>3)*16 + (y_int>>3);
    map_liquidHeaderTypeFlags type = _liquidFlags ? _liquidFlags[idx] : _liquidGlobalFlags;
    uint32 entry = _liquidEntry ? _liquidEntry[idx] : _liquidGlobalEntry;
    if (LiquidTypeEntry const* liquidEntry = sLiquidTypeStore.LookupEntry(entry))
    {
        type &= map_liquidHeaderTypeFlags::DarkWater;
        uint32 liqTypeIdx = liquidEntry->SoundBank;
        if (entry < 21)
        {
            if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(getArea(x, y)))
            {
                uint32 overrideLiquid = area->LiquidTypeID[liquidEntry->SoundBank];
                if (!overrideLiquid && area->ParentAreaID)
                {
                    area = sAreaTableStore.LookupEntry(area->ParentAreaID);
                    if (area)
                        overrideLiquid = area->LiquidTypeID[liquidEntry->SoundBank];
                }

                if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(overrideLiquid))
                {
                    entry = overrideLiquid;
                    liqTypeIdx = liq->SoundBank;
                }
            }
        }

        type |= map_liquidHeaderTypeFlags(1 << liqTypeIdx);
    }

    if (type == map_liquidHeaderTypeFlags::NoWater)
        return LIQUID_MAP_NO_WATER;

    // Check req liquid type mask
    if (ReqLiquidType && (*ReqLiquidType & type) == map_liquidHeaderTypeFlags::NoWater)
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
    if (liquid_level < ground_level || z < ground_level)
        return LIQUID_MAP_NO_WATER;

    // All ok in water -> store data
    if (data)
    {
        data->entry = entry;
        data->type_flags = type;
        data->level = liquid_level;
        data->depth_level = ground_level;
    }

    // For speed check as int values
    float delta = liquid_level - z;

    if (delta > collisionHeight)                   // Under water
        return LIQUID_MAP_UNDER_WATER;
    if (delta > 0.0f)                   // In water
        return LIQUID_MAP_IN_WATER;
    if (delta > -0.1f)                   // Walk on water
        return LIQUID_MAP_WATER_WALK;
                                      // Above water
    return LIQUID_MAP_ABOVE_WATER;
}

GridMap* Map::GetGrid(uint32 mapId, float x, float y)
{
    // half opt method
    int gx = (int)(CENTER_GRID_ID - x / SIZE_OF_GRIDS);                   //grid x
    int gy = (int)(CENTER_GRID_ID - y / SIZE_OF_GRIDS);                   //grid y

    // ensure GridMap is loaded
    EnsureGridCreated(GridCoord((MAX_NUMBER_OF_GRIDS - 1) - gx, (MAX_NUMBER_OF_GRIDS - 1) - gy));

    GridMap* grid = GridMaps[gx][gy].get();
    auto childMapItr = std::find_if(m_childTerrainMaps->begin(), m_childTerrainMaps->end(), [mapId](Map* childTerrainMap) { return childTerrainMap->GetId() == mapId; });
    if (childMapItr != m_childTerrainMaps->end() && (*childMapItr)->GridMaps[gx][gy])
        grid = (*childMapItr)->GridMaps[gx][gy].get();

    return grid;
}

bool Map::HasChildMapGridFile(uint32 mapId, int32 gx, int32 gy) const
{
    auto childMapItr = std::find_if(m_childTerrainMaps->begin(), m_childTerrainMaps->end(), [mapId](Map* childTerrainMap) { return childTerrainMap->GetId() == mapId; });
    return childMapItr != m_childTerrainMaps->end() && (*childMapItr)->i_gridFileExists[gx * MAX_NUMBER_OF_GRIDS + gy];
}

float Map::GetWaterOrGroundLevel(PhaseShift const& phaseShift, float x, float y, float z, float* ground /*= nullptr*/, bool /*swim = false*/, float collisionHeight /*= DEFAULT_COLLISION_HEIGHT*/)
{
    if (GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, this, x, y), x, y))
    {
        // we need ground level (including grid height version) for proper return water level in point
        float ground_z = GetHeight(phaseShift, x, y, z + Z_OFFSET_FIND_HEIGHT, true, 50.0f);
        if (ground)
            *ground = ground_z;

        LiquidData liquid_status;

        ZLiquidStatus res = GetLiquidStatus(phaseShift, x, y, ground_z, map_liquidHeaderTypeFlags::AllLiquids, &liquid_status, collisionHeight);
        switch (res)
        {
            case LIQUID_MAP_ABOVE_WATER:
                return std::max<float>(liquid_status.level, ground_z);
            case LIQUID_MAP_NO_WATER:
                return ground_z;
            default:
                return liquid_status.level;
        }
    }

    return VMAP_INVALID_HEIGHT_VALUE;
}

float Map::GetStaticHeight(PhaseShift const& phaseShift, float x, float y, float z, bool checkVMap /*= true*/, float maxSearchDist /*= DEFAULT_HEIGHT_SEARCH*/)
{
    // find raw .map surface under Z coordinates
    float mapHeight = VMAP_INVALID_HEIGHT_VALUE;
    uint32 terrainMapId = PhasingHandler::GetTerrainMapId(phaseShift, this, x, y);
    float gridHeight = GetGridHeight(phaseShift, x, y);
    if (G3D::fuzzyGe(z, gridHeight - GROUND_HEIGHT_TOLERANCE))
        mapHeight = gridHeight;

    float vmapHeight = VMAP_INVALID_HEIGHT_VALUE;
    if (checkVMap)
    {
        VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
        if (vmgr->isHeightCalcEnabled())
            vmapHeight = vmgr->getHeight(terrainMapId, x, y, z, maxSearchDist);
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

            return mapHeight;                           // better use .map surface height
        }

        return vmapHeight;                              // we have only vmapHeight (if have)
    }

    return mapHeight;                               // explicitly use map data
}

float Map::GetGridHeight(PhaseShift const& phaseShift, float x, float y)
{
    if (GridMap* gmap = GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, this, x, y), x, y))
        return gmap->getHeight(x, y);

    return VMAP_INVALID_HEIGHT_VALUE;
}

float Map::GetMinHeight(PhaseShift const& phaseShift, float x, float y)
{
    if (GridMap const* grid = GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, this, x, y), x, y))
        return grid->getMinHeight(x, y);

    return -500.0f;
}

static inline bool IsInWMOInterior(uint32 mogpFlags)
{
    return (mogpFlags & 0x2000) != 0;
}

bool Map::GetAreaInfo(PhaseShift const& phaseShift, float x, float y, float z, uint32& mogpflags, int32& adtId, int32& rootId, int32& groupId)
{
    float vmap_z = z;
    float dynamic_z = z;
    float check_z = z;
    uint32 terrainMapId = PhasingHandler::GetTerrainMapId(phaseShift, this, x, y);
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    uint32 vflags;
    int32 vadtId;
    int32 vrootId;
    int32 vgroupId;
    uint32 dflags;
    int32 dadtId;
    int32 drootId;
    int32 dgroupId;

    bool hasVmapAreaInfo = vmgr->getAreaInfo(terrainMapId, x, y, vmap_z, vflags, vadtId, vrootId, vgroupId);
    bool hasDynamicAreaInfo = _dynamicTree.getAreaInfo(x, y, dynamic_z, phaseShift, dflags, dadtId, drootId, dgroupId);
    auto useVmap = [&]() { check_z = vmap_z; mogpflags = vflags; adtId = vadtId; rootId = vrootId; groupId = vgroupId; };
    auto useDyn = [&]() { check_z = dynamic_z; mogpflags = dflags; adtId = dadtId; rootId = drootId; groupId = dgroupId; };

    if (hasVmapAreaInfo)
    {
        if (hasDynamicAreaInfo && dynamic_z > vmap_z)
            useDyn();
        else
            useVmap();
    }
    else if (hasDynamicAreaInfo)
    {
        useDyn();
    }

    if (hasVmapAreaInfo || hasDynamicAreaInfo)
    {
        // check if there's terrain between player height and object height
        if (GridMap* gmap = GetGrid(terrainMapId, x, y))
        {
            float mapHeight = gmap->getHeight(x, y);
            // z + 2.0f condition taken from GetHeight(), not sure if it's such a great choice...
            if (z + 2.0f > mapHeight && mapHeight > check_z)
                return false;
        }
        return true;
    }
    return false;
}

uint32 Map::GetAreaId(PhaseShift const& phaseShift, float x, float y, float z)
{
    uint32 mogpFlags;
    int32 adtId, rootId, groupId;
    float vmapZ = z;
    bool hasVmapArea = GetAreaInfo(phaseShift, x, y, vmapZ, mogpFlags, adtId, rootId, groupId);

    uint32 gridAreaId = 0;
    float gridMapHeight = INVALID_HEIGHT;
    if (GridMap* gmap = GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, this, x, y), x, y))
    {
        gridAreaId = gmap->getArea(x, y);
        gridMapHeight = gmap->getHeight(x, y);
    }

    uint32 areaId = 0;

    // floor is the height we are closer to (but only if above)
    if (hasVmapArea && G3D::fuzzyGe(z, vmapZ - GROUND_HEIGHT_TOLERANCE) && (G3D::fuzzyLt(z, gridMapHeight - GROUND_HEIGHT_TOLERANCE) || vmapZ > gridMapHeight))
    {
        // wmo found
        if (WMOAreaTableEntry const* wmoEntry = sDB2Manager.GetWMOAreaTable(rootId, adtId, groupId))
            areaId = wmoEntry->AreaTableID;

        if (!areaId)
            areaId = gridAreaId;
    }
    else
        areaId = gridAreaId;

    if (!areaId)
        areaId = i_mapEntry->AreaTableID;

    return areaId;
}

uint32 Map::GetZoneId(PhaseShift const& phaseShift, float x, float y, float z)
{
    uint32 areaId = GetAreaId(phaseShift, x, y, z);
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
        if (area->ParentAreaID)
            return area->ParentAreaID;

    return areaId;
}

void Map::GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, float x, float y, float z)
{
    areaid = zoneid = GetAreaId(phaseShift, x, y, z);
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaid))
        if (area->ParentAreaID)
            zoneid = area->ParentAreaID;
}

ZLiquidStatus Map::GetLiquidStatus(PhaseShift const& phaseShift, float x, float y, float z, map_liquidHeaderTypeFlags ReqLiquidType, LiquidData* data, float collisionHeight)
{
    ZLiquidStatus result = LIQUID_MAP_NO_WATER;
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    float liquid_level = INVALID_HEIGHT;
    float ground_level = INVALID_HEIGHT;
    uint32 liquid_type = 0;
    uint32 mogpFlags = 0;
    bool useGridLiquid = true;
    uint32 terrainMapId = PhasingHandler::GetTerrainMapId(phaseShift, this, x, y);
    if (vmgr->GetLiquidLevel(terrainMapId, x, y, z, AsUnderlyingType(ReqLiquidType), liquid_level, ground_level, liquid_type, mogpFlags))
    {
        useGridLiquid = !IsInWMOInterior(mogpFlags);
        TC_LOG_DEBUG("maps", "GetLiquidStatus(): vmap liquid level: %f ground: %f type: %u", liquid_level, ground_level, liquid_type);
        // Check water level and ground level
        if (liquid_level > ground_level && G3D::fuzzyGe(z, ground_level - GROUND_HEIGHT_TOLERANCE))
        {
            // All ok in water -> store data
            if (data)
            {
                // hardcoded in client like this
                if (GetId() == 530 && liquid_type == 2)
                    liquid_type = 15;

                uint32 liquidFlagType = 0;
                if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquid_type))
                    liquidFlagType = liq->SoundBank;

                if (liquid_type && liquid_type < 21)
                {
                    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(GetAreaId(phaseShift, x, y, z)))
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
                            liquidFlagType = liq->SoundBank;
                        }
                    }
                }

                data->level = liquid_level;
                data->depth_level = ground_level;

                data->entry = liquid_type;
                data->type_flags = map_liquidHeaderTypeFlags(1 << liquidFlagType);
            }

            float delta = liquid_level - z;

            // Get position delta
            if (delta > collisionHeight)                   // Under water
                return LIQUID_MAP_UNDER_WATER;
            if (delta > 0.0f)                   // In water
                return LIQUID_MAP_IN_WATER;
            if (delta > -0.1f)                   // Walk on water
                return LIQUID_MAP_WATER_WALK;
            result = LIQUID_MAP_ABOVE_WATER;
        }
    }

    if (useGridLiquid)
    {
        if (GridMap* gmap = GetGrid(terrainMapId, x, y))
        {
            LiquidData map_data;
            ZLiquidStatus map_result = gmap->GetLiquidStatus(x, y, z, ReqLiquidType, &map_data, collisionHeight);
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
    }
    return result;
}

void Map::GetFullTerrainStatusForPosition(PhaseShift const& phaseShift, float x, float y, float z, PositionFullTerrainStatus& data, map_liquidHeaderTypeFlags reqLiquidType, float collisionHeight)
{
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    VMAP::AreaAndLiquidData vmapData;
    VMAP::AreaAndLiquidData dynData;
    VMAP::AreaAndLiquidData* wmoData = nullptr;
    uint32 terrainMapId = PhasingHandler::GetTerrainMapId(phaseShift, this, x, y);
    GridMap* gmap = GetGrid(terrainMapId, x, y);
    vmgr->getAreaAndLiquidData(terrainMapId, x, y, z, AsUnderlyingType(reqLiquidType), vmapData);
    _dynamicTree.getAreaAndLiquidData(x, y, z, phaseShift, AsUnderlyingType(reqLiquidType), dynData);

    uint32 gridAreaId = 0;
    float gridMapHeight = INVALID_HEIGHT;
    if (gmap)
    {
        gridAreaId = gmap->getArea(x, y);
        gridMapHeight = gmap->getHeight(x, y);
    }

    bool useGridLiquid = true;

    // floor is the height we are closer to (but only if above)
    data.floorZ = VMAP_INVALID_HEIGHT;
    if (gridMapHeight > INVALID_HEIGHT && G3D::fuzzyGe(z, gridMapHeight - GROUND_HEIGHT_TOLERANCE))
        data.floorZ = gridMapHeight;
    if (vmapData.floorZ > VMAP_INVALID_HEIGHT &&
        G3D::fuzzyGe(z, vmapData.floorZ - GROUND_HEIGHT_TOLERANCE) &&
        (G3D::fuzzyLt(z, gridMapHeight - GROUND_HEIGHT_TOLERANCE) || vmapData.floorZ > gridMapHeight))
    {
        data.floorZ = vmapData.floorZ;
        wmoData = &vmapData;
    }
    // NOTE: Objects will not detect a case when a wmo providing area/liquid despawns from under them
    // but this is fine as these kind of objects are not meant to be spawned and despawned a lot
    // example: Lich King platform
    if (dynData.floorZ > VMAP_INVALID_HEIGHT &&
        G3D::fuzzyGe(z, dynData.floorZ - GROUND_HEIGHT_TOLERANCE) &&
        (G3D::fuzzyLt(z, gridMapHeight - GROUND_HEIGHT_TOLERANCE) || dynData.floorZ > gridMapHeight) &&
        (G3D::fuzzyLt(z, vmapData.floorZ - GROUND_HEIGHT_TOLERANCE) || dynData.floorZ > vmapData.floorZ))
    {
        data.floorZ = dynData.floorZ;
        wmoData = &dynData;
    }

    if (wmoData)
    {
        if (wmoData->areaInfo)
        {
            data.areaInfo.emplace(wmoData->areaInfo->adtId, wmoData->areaInfo->rootId, wmoData->areaInfo->groupId, wmoData->areaInfo->mogpFlags);
            // wmo found
            WMOAreaTableEntry const* wmoEntry = sDB2Manager.GetWMOAreaTable(wmoData->areaInfo->rootId, wmoData->areaInfo->adtId, wmoData->areaInfo->groupId);
            data.outdoors = (wmoData->areaInfo->mogpFlags & 0x8) != 0;
            if (wmoEntry)
            {
                data.areaId = wmoEntry->AreaTableID;
                if (wmoEntry->Flags & 4)
                    data.outdoors = true;
                else if (wmoEntry->Flags & 2)
                    data.outdoors = false;
            }

            if (!data.areaId)
                data.areaId = gridAreaId;

            useGridLiquid = !IsInWMOInterior(wmoData->areaInfo->mogpFlags);
        }
    }
    else
    {
        data.outdoors = true;
        data.areaId = gridAreaId;
        if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(data.areaId))
            data.outdoors = (areaEntry->Flags[0] & (AREA_FLAG_INSIDE | AREA_FLAG_OUTSIDE)) != AREA_FLAG_INSIDE;
    }

    if (!data.areaId)
        data.areaId = i_mapEntry->AreaTableID;

    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(data.areaId);

    // liquid processing
    data.liquidStatus = LIQUID_MAP_NO_WATER;
    if (wmoData && wmoData->liquidInfo && wmoData->liquidInfo->level > wmoData->floorZ)
    {
        uint32 liquidType = wmoData->liquidInfo->type;
        if (GetId() == 530 && liquidType == 2) // gotta love blizzard hacks
            liquidType = 15;

        uint32 liquidFlagType = 0;
        if (LiquidTypeEntry const* liquidData = sLiquidTypeStore.LookupEntry(liquidType))
            liquidFlagType = liquidData->SoundBank;

        if (liquidType && liquidType < 21 && areaEntry)
        {
            uint32 overrideLiquid = areaEntry->LiquidTypeID[liquidFlagType];
            if (!overrideLiquid && areaEntry->ParentAreaID)
            {
                AreaTableEntry const* zoneEntry = sAreaTableStore.LookupEntry(areaEntry->ParentAreaID);
                if (zoneEntry)
                    overrideLiquid = zoneEntry->LiquidTypeID[liquidFlagType];
            }

            if (LiquidTypeEntry const* overrideData = sLiquidTypeStore.LookupEntry(overrideLiquid))
            {
                liquidType = overrideLiquid;
                liquidFlagType = overrideData->SoundBank;
            }
        }

        data.liquidInfo.emplace();
        data.liquidInfo->level = wmoData->liquidInfo->level;
        data.liquidInfo->depth_level = wmoData->floorZ;
        data.liquidInfo->entry = liquidType;
        data.liquidInfo->type_flags = map_liquidHeaderTypeFlags(1 << liquidFlagType);

        float delta = wmoData->liquidInfo->level - z;
        if (delta > collisionHeight)
            data.liquidStatus = LIQUID_MAP_UNDER_WATER;
        else if (delta > 0.0f)
            data.liquidStatus = LIQUID_MAP_IN_WATER;
        else if (delta > -0.1f)
            data.liquidStatus = LIQUID_MAP_WATER_WALK;
        else
            data.liquidStatus = LIQUID_MAP_ABOVE_WATER;
    }
    // look up liquid data from grid map
    if (gmap && useGridLiquid)
    {
        LiquidData gridMapLiquid;
        ZLiquidStatus gridMapStatus = gmap->GetLiquidStatus(x, y, z, reqLiquidType, &gridMapLiquid, collisionHeight);
        if (gridMapStatus != LIQUID_MAP_NO_WATER && (!wmoData || gridMapLiquid.level > wmoData->floorZ))
        {
            if (GetId() == 530 && gridMapLiquid.entry == 2)
                gridMapLiquid.entry = 15;
            data.liquidInfo = gridMapLiquid;
            data.liquidStatus = gridMapStatus;
        }
    }
}

float Map::GetWaterLevel(PhaseShift const& phaseShift, float x, float y)
{
    if (GridMap* gmap = GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, this, x, y), x, y))
        return gmap->getLiquidLevel(x, y);
    else
        return 0;
}

bool Map::isInLineOfSight(PhaseShift const& phaseShift, float x1, float y1, float z1, float x2, float y2, float z2, LineOfSightChecks checks, VMAP::ModelIgnoreFlags ignoreFlags) const
{
    if ((checks & LINEOFSIGHT_CHECK_VMAP)
      && !VMAP::VMapFactory::createOrGetVMapManager()->isInLineOfSight(PhasingHandler::GetTerrainMapId(phaseShift, this, x1, y1), x1, y1, z1, x2, y2, z2, ignoreFlags))
        return false;
    if (sWorld->getBoolConfig(CONFIG_CHECK_GOBJECT_LOS) && (checks & LINEOFSIGHT_CHECK_GOBJECT)
      && !_dynamicTree.isInLineOfSight({ x1, y1, z1 }, { x2, y2, z2 }, phaseShift))
        return false;
    return true;
}

bool Map::getObjectHitPos(PhaseShift const& phaseShift, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float& ry, float& rz, float modifyDist)
{
    G3D::Vector3 startPos(x1, y1, z1);
    G3D::Vector3 dstPos(x2, y2, z2);

    G3D::Vector3 resultPos;
    bool result = _dynamicTree.getObjectHitPos(startPos, dstPos, resultPos, modifyDist, phaseShift);

    rx = resultPos.x;
    ry = resultPos.y;
    rz = resultPos.z;
    return result;
}

bool Map::IsInWater(PhaseShift const& phaseShift, float x, float y, float pZ, LiquidData* data)
{
    LiquidData liquid_status;
    LiquidData* liquid_ptr = data ? data : &liquid_status;
    return (GetLiquidStatus(phaseShift, x, y, pZ, map_liquidHeaderTypeFlags::AllLiquids, liquid_ptr) & (LIQUID_MAP_IN_WATER | LIQUID_MAP_UNDER_WATER)) != 0;
}

bool Map::IsUnderWater(PhaseShift const& phaseShift, float x, float y, float z)
{
    return (GetLiquidStatus(phaseShift, x, y, z, map_liquidHeaderTypeFlags::Water | map_liquidHeaderTypeFlags::Ocean) & LIQUID_MAP_UNDER_WATER) != 0;
}

char const* Map::GetMapName() const
{
    return i_mapEntry ? i_mapEntry->MapName[sWorld->GetDefaultDbcLocale()] : "UNNAMEDMAP\x0";
}

void Map::SendInitSelf(Player* player)
{
    TC_LOG_DEBUG("maps", "Creating player data for himself %s", player->GetGUID().ToString().c_str());

    UpdateData data(player->GetMapId());

    // attach to player data current transport data
    if (Transport* transport = dynamic_cast<Transport*>(player->GetTransport()))
    {
        transport->BuildCreateUpdateBlockForPlayer(&data, player);
        player->m_visibleTransports.insert(transport->GetGUID());
    }

    // build data for self presence in world at own client (one time for map)
    player->BuildCreateUpdateBlockForPlayer(&data, player);

    // build other passengers at transport also (they always visible and marked as visible and will not send at visibility update at add to map
    if (Transport* transport = dynamic_cast<Transport*>(player->GetTransport()))
        for (WorldObject* passenger : transport->GetPassengers())
            if (player != passenger && player->HaveAtClient(passenger))
                passenger->BuildCreateUpdateBlockForPlayer(&data, player);

    WorldPacket packet;
    data.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void Map::SendInitTransports(Player* player)
{
    // Hack to send out transports
    UpdateData transData(GetId());
    for (Transport* transport : _transports)
    {
        if (transport->IsInWorld() && transport != player->GetTransport() && player->IsInPhase(transport))
        {
            transport->BuildCreateUpdateBlockForPlayer(&transData, player);
            player->m_visibleTransports.insert(transport->GetGUID());
        }
    }

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void Map::SendRemoveTransports(Player* player)
{
    // Hack to send out transports
    UpdateData transData(player->GetMapId());
    for (Transport* transport : _transports)
    {
        if (player->m_visibleTransports.count(transport->GetGUID()) && transport != player->GetTransport())
        {
            transport->BuildOutOfRangeUpdateBlock(&transData);
            player->m_visibleTransports.erase(transport->GetGUID());
        }
    }

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void Map::SendUpdateTransportVisibility(Player* player)
{
    // Hack to send out transports
    UpdateData transData(player->GetMapId());
    for (Transport* transport : _transports)
    {
        if (!transport->IsInWorld())
            continue;

        auto transportItr = player->m_visibleTransports.find(transport->GetGUID());
        if (player->IsInPhase(transport))
        {
            if (transportItr == player->m_visibleTransports.end())
            {
                transport->BuildCreateUpdateBlockForPlayer(&transData, player);
                player->m_visibleTransports.insert(transport->GetGUID());
            }
        }
        else if (transportItr != player->m_visibleTransports.end())
        {
            transport->BuildOutOfRangeUpdateBlock(&transData);
            player->m_visibleTransports.erase(transportItr);
        }
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
        iter->first->SendDirectMessage(&packet);
        packet.clear();                                     // clean the string
    }
}

// CheckRespawn MUST do one of the following:
//  -) return true
//  -) set info->respawnTime to zero, which indicates the respawn time should be deleted (and will never be processed again without outside intervention)
//  -) set info->respawnTime to a new respawn time, which must be strictly GREATER than the current time (GameTime::GetGameTime())
bool Map::CheckRespawn(RespawnInfo* info)
{
    SpawnData const* data = sObjectMgr->GetSpawnData(info->type, info->spawnId);
    ASSERT(data, "Invalid respawn info with type %u, spawnID " UI64FMTD " in respawn queue.", info->type, info->spawnId);

    // First, check if this creature's spawn group is inactive
    if (!IsSpawnGroupActive(data->spawnGroupData->groupId))
    {
        info->respawnTime = 0;
        return false;
    }

    // Next, check if there's already an instance of this object that would block the respawn
    bool alreadyExists = false;
    switch (info->type)
    {
        case SPAWN_TYPE_CREATURE:
        {
            // escort check for creatures only (if the world config boolean is set)
            bool const isEscort = (sWorld->getBoolConfig(CONFIG_RESPAWN_DYNAMIC_ESCORTNPC) && data->spawnGroupData->flags & SPAWNGROUP_FLAG_ESCORTQUESTNPC);

            auto range = _creatureBySpawnIdStore.equal_range(info->spawnId);
            for (auto it = range.first; it != range.second; ++it)
            {
                Creature* creature = it->second;
                if (!creature->IsAlive())
                    continue;
                // escort NPCs are allowed to respawn as long as all other instances are already escorting
                if (isEscort && creature->IsEscorted())
                    continue;
                alreadyExists = true;
                break;
            }
            break;
        }
        case SPAWN_TYPE_GAMEOBJECT:
            // gameobject check is simpler - they cannot be dead or escorting
            if (_gameobjectBySpawnIdStore.find(info->spawnId) != _gameobjectBySpawnIdStore.end())
                alreadyExists = true;
            break;
        default:
            ABORT_MSG("Invalid spawn type %u with spawnId " UI64FMTD " on map %u", uint32(info->type), info->spawnId, GetId());
            return true;
    }
    if (alreadyExists)
    {
        info->respawnTime = 0;
        return false;
    }

    // next, check linked respawn time
    ObjectGuid thisGUID = info->type == SPAWN_TYPE_GAMEOBJECT
        ? ObjectGuid::Create<HighGuid::GameObject>(GetId(), info->entry, info->spawnId)
        : ObjectGuid::Create<HighGuid::Creature>(GetId(), info->entry, info->spawnId);
    if (time_t linkedTime = GetLinkedRespawnTime(thisGUID))
    {
        time_t now = GameTime::GetGameTime();
        time_t respawnTime;
        if (linkedTime == std::numeric_limits<time_t>::max())
            respawnTime = linkedTime;
        else if (sObjectMgr->GetLinkedRespawnGuid(thisGUID) == thisGUID) // never respawn, save "something" in DB
            respawnTime = now + WEEK;
        else // set us to check again shortly after linked unit
            respawnTime = std::max<time_t>(now, linkedTime) + urand(5, 15);
        info->respawnTime = respawnTime;
        return false;
    }
    // everything ok, let's spawn
    return true;
}

void Map::Respawn(RespawnInfo* info, CharacterDatabaseTransaction dbTrans)
{
    if (info->respawnTime <= GameTime::GetGameTime())
        return;
    info->respawnTime = GameTime::GetGameTime();
    _respawnTimes.increase(info->handle);
    SaveRespawnInfoDB(*info, dbTrans);
}

size_t Map::DespawnAll(SpawnObjectType type, ObjectGuid::LowType spawnId)
{
    std::vector<WorldObject*> toUnload;
    switch (type)
    {
        case SPAWN_TYPE_CREATURE:
            for (auto const& pair : Trinity::Containers::MapEqualRange(GetCreatureBySpawnIdStore(), spawnId))
                toUnload.push_back(pair.second);
            break;
        case SPAWN_TYPE_GAMEOBJECT:
            for (auto const& pair : Trinity::Containers::MapEqualRange(GetGameObjectBySpawnIdStore(), spawnId))
                toUnload.push_back(pair.second);
            break;
        default:
            break;
    }

    for (WorldObject* o : toUnload)
        AddObjectToRemoveList(o);

    return toUnload.size();
}

bool Map::AddRespawnInfo(RespawnInfo const& info)
{
    if (!info.spawnId)
    {
        TC_LOG_ERROR("maps", "Attempt to insert respawn info for zero spawn id (type %u)", uint32(info.type));
        return false;
    }

    RespawnInfoMap* bySpawnIdMap = GetRespawnMapForType(info.type);
    if (!bySpawnIdMap)
        return false;

    // check if we already have the maximum possible number of respawns scheduled
    if (SpawnData::TypeHasData(info.type))
    {
        auto it = bySpawnIdMap->find(info.spawnId);
        if (it != bySpawnIdMap->end()) // spawnid already has a respawn scheduled
        {
            RespawnInfo* const existing = it->second;
            if (info.respawnTime <= existing->respawnTime) // delete existing in this case
                DeleteRespawnInfo(existing);
            else
                return false;
        }
        ASSERT(bySpawnIdMap->find(info.spawnId) == bySpawnIdMap->end(), "Insertion of respawn info with id (%u," UI64FMTD ") into spawn id map failed - state desync.", uint32(info.type), info.spawnId);
    }
    else
        ABORT_MSG("Invalid respawn info for spawn id (%u," UI64FMTD ") being inserted", uint32(info.type), info.spawnId);

    RespawnInfo * ri = new RespawnInfo(info);
    ri->handle = _respawnTimes.push(ri);
    bySpawnIdMap->emplace(ri->spawnId, ri);
    return true;
}

static void PushRespawnInfoFrom(std::vector<RespawnInfo const*>& data, RespawnInfoMap const& map)
{
    data.reserve(data.size() + map.size());
    for (auto const& pair : map)
        data.push_back(pair.second);
}

void Map::GetRespawnInfo(std::vector<RespawnInfo const*>& respawnData, SpawnObjectTypeMask types) const
{
    if (types & SPAWN_TYPEMASK_CREATURE)
        PushRespawnInfoFrom(respawnData, _creatureRespawnTimesBySpawnId);
    if (types & SPAWN_TYPEMASK_GAMEOBJECT)
        PushRespawnInfoFrom(respawnData, _gameObjectRespawnTimesBySpawnId);
}

RespawnInfo* Map::GetRespawnInfo(SpawnObjectType type, ObjectGuid::LowType spawnId) const
{
    RespawnInfoMap const* map = GetRespawnMapForType(type);
    if (!map)
        return nullptr;
    auto it = map->find(spawnId);
    if (it == map->end())
        return nullptr;
    return it->second;
}

void Map::UnloadAllRespawnInfos() // delete everything from memory
{
    for (RespawnInfo* info : _respawnTimes)
        delete info;
    _respawnTimes.clear();
    _creatureRespawnTimesBySpawnId.clear();
    _gameObjectRespawnTimesBySpawnId.clear();
}

void Map::DeleteRespawnInfo(RespawnInfo* info, CharacterDatabaseTransaction dbTrans)
{
    // Delete from all relevant containers to ensure consistency
    ASSERT(info);

    // spawnid store
    auto spawnMap = GetRespawnMapForType(info->type);
    if (!spawnMap)
        return;

    auto range = spawnMap->equal_range(info->spawnId);
    auto it = std::find_if(range.first, range.second, [info](RespawnInfoMap::value_type const& pair) { return (pair.second == info); });
    ASSERT(it != range.second, "Respawn stores inconsistent for map %u, spawnid " UI64FMTD " (type %u)", GetId(), info->spawnId, uint32(info->type));
    spawnMap->erase(it);

    // respawn heap
    _respawnTimes.erase(info->handle);

    // database
    DeleteRespawnInfoFromDB(info->type, info->spawnId, dbTrans);

    // then cleanup the object
    delete info;
}

void Map::DeleteRespawnInfoFromDB(SpawnObjectType type, ObjectGuid::LowType spawnId, CharacterDatabaseTransaction dbTrans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_RESPAWN);
    stmt->setUInt16(0, type);
    stmt->setUInt64(1, spawnId);
    stmt->setUInt16(2, GetId());
    stmt->setUInt32(3, GetInstanceId());
    CharacterDatabase.ExecuteOrAppend(dbTrans, stmt);
}

void Map::DoRespawn(SpawnObjectType type, ObjectGuid::LowType spawnId, uint32 gridId)
{
    if (!IsGridLoaded(gridId)) // if grid isn't loaded, this will be processed in grid load handler
        return;

    switch (type)
    {
        case SPAWN_TYPE_CREATURE:
        {
            Creature* obj = new Creature();
            if (!obj->LoadFromDB(spawnId, this, true, true))
                delete obj;
            break;
        }
        case SPAWN_TYPE_GAMEOBJECT:
        {
            GameObject* obj = new GameObject();
            if (!obj->LoadFromDB(spawnId, this, true))
                delete obj;
            break;
        }
        default:
            ABORT_MSG("Invalid spawn type %u (spawnid " UI64FMTD ") on map %u", uint32(type), spawnId, GetId());
    }
}

void Map::ProcessRespawns()
{
    time_t now = GameTime::GetGameTime();
    while (!_respawnTimes.empty())
    {
        RespawnInfo* next = _respawnTimes.top();
        if (now < next->respawnTime) // done for this tick
            break;

        if (uint32 poolId = sPoolMgr->IsPartOfAPool(next->type, next->spawnId)) // is this part of a pool?
        { // if yes, respawn will be handled by (external) pooling logic, just delete the respawn time
            // step 1: remove entry from maps to avoid it being reachable by outside logic
            _respawnTimes.pop();
            ASSERT_NOTNULL(GetRespawnMapForType(next->type))->erase(next->spawnId);

            // step 2: tell pooling logic to do its thing
            sPoolMgr->UpdatePool(GetPoolData(), poolId, next->type, next->spawnId);

            // step 3: get rid of the actual entry
            RemoveRespawnTime(next->type, next->spawnId, nullptr, true);
            delete next;
        }
        else if (CheckRespawn(next)) // see if we're allowed to respawn
        { // ok, respawn
            // step 1: remove entry from maps to avoid it being reachable by outside logic
            _respawnTimes.pop();
            ASSERT_NOTNULL(GetRespawnMapForType(next->type))->erase(next->spawnId);

            // step 2: do the respawn, which involves external logic
            DoRespawn(next->type, next->spawnId, next->gridId);

            // step 3: get rid of the actual entry
            RemoveRespawnTime(next->type, next->spawnId, nullptr, true);
            delete next;
        }
        else if (!next->respawnTime)
        { // just remove this respawn entry without rescheduling
            _respawnTimes.pop();
            ASSERT_NOTNULL(GetRespawnMapForType(next->type))->erase(next->spawnId);
            RemoveRespawnTime(next->type, next->spawnId, nullptr, true);
            delete next;
        }
        else
        { // new respawn time, update heap position
            ASSERT(now < next->respawnTime); // infinite loop guard
            _respawnTimes.decrease(next->handle);
            SaveRespawnInfoDB(*next);
        }
    }
}

void Map::ApplyDynamicModeRespawnScaling(WorldObject const* obj, ObjectGuid::LowType spawnId, uint32& respawnDelay, uint32 mode) const
{
    ASSERT(mode == 1);
    ASSERT(obj->GetMap() == this);

    if (IsBattlegroundOrArena())
        return;

    SpawnObjectType type;
    switch (obj->GetTypeId())
    {
        case TYPEID_UNIT:
            type = SPAWN_TYPE_CREATURE;
            break;
        case TYPEID_GAMEOBJECT:
            type = SPAWN_TYPE_GAMEOBJECT;
            break;
        default:
            return;
    }

    SpawnMetadata const* data = sObjectMgr->GetSpawnMetadata(type, spawnId);
    if (!data)
        return;

    if (!(data->spawnGroupData->flags & SPAWNGROUP_FLAG_DYNAMIC_SPAWN_RATE))
        return;

    auto it = _zonePlayerCountMap.find(obj->GetZoneId());
    if (it == _zonePlayerCountMap.end())
        return;
    uint32 const playerCount = it->second;
    if (!playerCount)
        return;
    double const adjustFactor = sWorld->getFloatConfig(type == SPAWN_TYPE_GAMEOBJECT ? CONFIG_RESPAWN_DYNAMICRATE_GAMEOBJECT : CONFIG_RESPAWN_DYNAMICRATE_CREATURE) / playerCount;
    if (adjustFactor >= 1.0) // nothing to do here
        return;
    uint32 const timeMinimum = sWorld->getIntConfig(type == SPAWN_TYPE_GAMEOBJECT ? CONFIG_RESPAWN_DYNAMICMINIMUM_GAMEOBJECT : CONFIG_RESPAWN_DYNAMICMINIMUM_CREATURE);
    if (respawnDelay <= timeMinimum)
        return;

    respawnDelay = std::max<uint32>(ceil(respawnDelay * adjustFactor), timeMinimum);
}

bool Map::ShouldBeSpawnedOnGridLoad(SpawnObjectType type, ObjectGuid::LowType spawnId) const
{
    ASSERT(SpawnData::TypeHasData(type));
    // check if the object is on its respawn timer
    if (GetRespawnTime(type, spawnId))
        return false;

    SpawnMetadata const* spawnData = ASSERT_NOTNULL(sObjectMgr->GetSpawnMetadata(type, spawnId));
    // check if the object is part of a spawn group
    SpawnGroupTemplateData const* spawnGroup = ASSERT_NOTNULL(spawnData->spawnGroupData);
    if (!(spawnGroup->flags & SPAWNGROUP_FLAG_SYSTEM))
        if (!IsSpawnGroupActive(spawnGroup->groupId))
            return false;

    if (spawnData->ToSpawnData()->poolId)
        if (!GetPoolData().IsSpawnedObject(type, spawnId))
            return false;

    return true;
}

SpawnGroupTemplateData const* Map::GetSpawnGroupData(uint32 groupId) const
{
    SpawnGroupTemplateData const* data = sObjectMgr->GetSpawnGroupData(groupId);
    if (data && (data->flags & SPAWNGROUP_FLAG_SYSTEM || data->mapId == GetId()))
        return data;
    return nullptr;
}

bool Map::SpawnGroupSpawn(uint32 groupId, bool ignoreRespawn, bool force, std::vector<WorldObject*>* spawnedObjects)
{
    SpawnGroupTemplateData const* groupData = GetSpawnGroupData(groupId);
    if (!groupData || groupData->flags & SPAWNGROUP_FLAG_SYSTEM)
    {
        TC_LOG_ERROR("maps", "Tried to spawn non-existing (or system) spawn group %u on map %u. Blocked.", groupId, GetId());
        return false;
    }

    SetSpawnGroupActive(groupId, true); // start processing respawns for the group

    std::vector<SpawnData const*> toSpawn;
    for (auto& pair : sObjectMgr->GetSpawnMetadataForGroup(groupId))
    {
        SpawnMetadata const* data = pair.second;
        ASSERT(groupData->mapId == data->mapId);

        auto respawnMap = GetRespawnMapForType(data->type);
        if (!respawnMap)
            continue;

        if (force || ignoreRespawn)
            RemoveRespawnTime(data->type, data->spawnId);

        uint32 nRespawnTimers = respawnMap->count(data->spawnId);
        if (SpawnData::TypeHasData(data->type))
        {
            // has a respawn timer
            if (nRespawnTimers)
                continue;

            // has a spawn already active
            if (!force)
                if (WorldObject* obj = GetWorldObjectBySpawnId(data->type, data->spawnId))
                    if ((data->type != SPAWN_TYPE_CREATURE) || obj->ToCreature()->IsAlive())
                        continue;

            toSpawn.push_back(ASSERT_NOTNULL(data->ToSpawnData()));
        }
    }

    for (SpawnData const* data : toSpawn)
    {
        // don't spawn if the current map difficulty is not used by the spawn
        if (std::find(data->spawnDifficulties.begin(), data->spawnDifficulties.end(), GetDifficultyID()) == data->spawnDifficulties.end())
            continue;

        // don't spawn if the grid isn't loaded (will be handled in grid loader)
        if (!IsGridLoaded(data->spawnPoint))
            continue;

        // now do the actual (re)spawn
        switch (data->type)
        {
            case SPAWN_TYPE_CREATURE:
            {
                Creature* creature = new Creature();
                if (!creature->LoadFromDB(data->spawnId, this, true, force))
                    delete creature;
                else if (spawnedObjects)
                    spawnedObjects->push_back(creature);
                break;
            }
            case SPAWN_TYPE_GAMEOBJECT:
            {
                GameObject* gameobject = new GameObject();
                if (!gameobject->LoadFromDB(data->spawnId, this, true))
                    delete gameobject;
                else if (spawnedObjects)
                    spawnedObjects->push_back(gameobject);
                break;
            }
            case SPAWN_TYPE_AREATRIGGER:
            {
                AreaTrigger* areaTrigger = new AreaTrigger();
                if (!areaTrigger->LoadFromDB(data->spawnId, this, true, false))
                    delete areaTrigger;
                else if (spawnedObjects)
                    spawnedObjects->push_back(areaTrigger);
                break;
            }
            default:
                ABORT_MSG("Invalid spawn type %u with spawnId " UI64FMTD, uint32(data->type), data->spawnId);
                return false;
        }
    }
    return true;
}

bool Map::SpawnGroupDespawn(uint32 groupId, bool deleteRespawnTimes, size_t* count)
{
    SpawnGroupTemplateData const* groupData = GetSpawnGroupData(groupId);
    if (!groupData || groupData->flags & SPAWNGROUP_FLAG_SYSTEM)
    {
        TC_LOG_ERROR("maps", "Tried to despawn non-existing (or system) spawn group %u on map %u. Blocked.", groupId, GetId());
        return false;
    }

    for (auto const& pair : sObjectMgr->GetSpawnMetadataForGroup(groupId))
    {
        SpawnMetadata const* data = pair.second;
        ASSERT(groupData->mapId == data->mapId);
        if (deleteRespawnTimes)
            RemoveRespawnTime(data->type, data->spawnId);
        size_t c = DespawnAll(data->type, data->spawnId);
        if (count)
            *count += c;
    }
    SetSpawnGroupActive(groupId, false); // stop processing respawns for the group, too
    return true;
}

void Map::SetSpawnGroupActive(uint32 groupId, bool state)
{
    SpawnGroupTemplateData const* const data = GetSpawnGroupData(groupId);
    if (!data || data->flags & SPAWNGROUP_FLAG_SYSTEM)
    {
        TC_LOG_ERROR("maps", "Tried to set non-existing (or system) spawn group %u to %s on map %u. Blocked.", groupId, state ? "active" : "inactive", GetId());
        return;
    }
    if (state != !(data->flags & SPAWNGROUP_FLAG_MANUAL_SPAWN)) // toggled
        _toggledSpawnGroupIds.insert(groupId);
    else
        _toggledSpawnGroupIds.erase(groupId);
}

bool Map::IsSpawnGroupActive(uint32 groupId) const
{
    SpawnGroupTemplateData const* const data = GetSpawnGroupData(groupId);
    if (!data)
    {
        TC_LOG_ERROR("maps", "Tried to query state of non-existing spawn group %u on map %u.", groupId, GetId());
        return false;
    }
    if (data->flags & SPAWNGROUP_FLAG_SYSTEM)
        return true;
    // either manual spawn group and toggled, or not manual spawn group and not toggled...
    return (_toggledSpawnGroupIds.find(groupId) != _toggledSpawnGroupIds.end()) != !(data->flags & SPAWNGROUP_FLAG_MANUAL_SPAWN);
}

void Map::AddFarSpellCallback(FarSpellCallback&& callback)
{
    _farSpellCallbacks.Enqueue(new FarSpellCallback(std::move(callback)));
}

void Map::DelayedUpdate(uint32 t_diff)
{
    {
        FarSpellCallback* callback;
        while (_farSpellCallbacks.Dequeue(callback))
        {
            (*callback)(this);
            delete callback;
        }
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

    obj->SetDestroyedObject(true);
    obj->CleanupsBeforeDelete(false);                            // remove or simplify at least cross referenced links

    i_objectsToRemove.insert(obj);
}

void Map::AddObjectToSwitchList(WorldObject* obj, bool on)
{
    ASSERT(obj->GetMapId() == GetId() && obj->GetInstanceId() == GetInstanceId());
    // i_objectsToSwitch is iterated only in Map::RemoveAllObjectsInRemoveList() and it uses
    // the contained objects only if GetTypeId() == TYPEID_UNIT , so we can return in all other cases
    if (obj->GetTypeId() != TYPEID_UNIT)
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
        itr->GetSource()->SendDirectMessage(data);
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

void Map::AddToActive(WorldObject* obj)
{
    AddToActiveHelper(obj);

    Optional<Position> respawnLocation;
    switch (obj->GetTypeId())
    {
        case TYPEID_UNIT:
            if (Creature* creature = obj->ToCreature(); !creature->IsPet() && creature->GetSpawnId())
            {
                respawnLocation.emplace();
                creature->GetRespawnPosition(respawnLocation->m_positionX, respawnLocation->m_positionY, respawnLocation->m_positionZ);
            }
            break;
        case TYPEID_GAMEOBJECT:
            if (GameObject* gameObject = obj->ToGameObject(); gameObject->GetSpawnId())
            {
                respawnLocation.emplace();
                gameObject->GetRespawnPosition(respawnLocation->m_positionX, respawnLocation->m_positionY, respawnLocation->m_positionZ);
            }
            break;
        default:
            break;
    }

    if (respawnLocation)
    {
        GridCoord p = Trinity::ComputeGridCoord(respawnLocation->GetPositionX(), respawnLocation->GetPositionY());
        if (getNGrid(p.x_coord, p.y_coord))
            getNGrid(p.x_coord, p.y_coord)->incUnloadActiveLock();
        else
        {
            GridCoord p2 = Trinity::ComputeGridCoord(obj->GetPositionX(), obj->GetPositionY());
            TC_LOG_ERROR("maps", "Active object %s added to grid[%u, %u] but spawn grid[%u, %u] was not loaded.",
                obj->GetGUID().ToString().c_str(), p.x_coord, p.y_coord, p2.x_coord, p2.y_coord);
        }
    }
}

void Map::RemoveFromActive(WorldObject* obj)
{
    RemoveFromActiveHelper(obj);

    Optional<Position> respawnLocation;
    switch (obj->GetTypeId())
    {
        case TYPEID_UNIT:
            if (Creature* creature = obj->ToCreature(); !creature->IsPet() && creature->GetSpawnId())
            {
                respawnLocation.emplace();
                creature->GetRespawnPosition(respawnLocation->m_positionX, respawnLocation->m_positionY, respawnLocation->m_positionZ);
            }
            break;
        case TYPEID_GAMEOBJECT:
            if (GameObject* gameObject = obj->ToGameObject(); gameObject->GetSpawnId())
            {
                respawnLocation.emplace();
                gameObject->GetRespawnPosition(respawnLocation->m_positionX, respawnLocation->m_positionY, respawnLocation->m_positionZ);
            }
            break;
        default:
            break;
    }

    if (respawnLocation)
    {
        GridCoord p = Trinity::ComputeGridCoord(respawnLocation->GetPositionX(), respawnLocation->GetPositionY());
        if (getNGrid(p.x_coord, p.y_coord))
            getNGrid(p.x_coord, p.y_coord)->decUnloadActiveLock();
        else
        {
            GridCoord p2 = Trinity::ComputeGridCoord(obj->GetPositionX(), obj->GetPositionY());
            TC_LOG_ERROR("maps", "Active object %s removed from to grid[%u, %u] but spawn grid[%u, %u] was not loaded.",
                obj->GetGUID().ToString().c_str(), p.x_coord, p.y_coord, p2.x_coord, p2.y_coord);
        }
    }
}

template TC_GAME_API bool Map::AddToMap(Corpse*);
template TC_GAME_API bool Map::AddToMap(Creature*);
template TC_GAME_API bool Map::AddToMap(GameObject*);
template TC_GAME_API bool Map::AddToMap(DynamicObject*);
template TC_GAME_API bool Map::AddToMap(AreaTrigger*);
template TC_GAME_API bool Map::AddToMap(SceneObject*);
template TC_GAME_API bool Map::AddToMap(Conversation*);

template TC_GAME_API void Map::RemoveFromMap(Corpse*, bool);
template TC_GAME_API void Map::RemoveFromMap(Creature*, bool);
template TC_GAME_API void Map::RemoveFromMap(GameObject*, bool);
template TC_GAME_API void Map::RemoveFromMap(DynamicObject*, bool);
template TC_GAME_API void Map::RemoveFromMap(AreaTrigger*, bool);
template TC_GAME_API void Map::RemoveFromMap(SceneObject*, bool);
template TC_GAME_API void Map::RemoveFromMap(Conversation*, bool);

/* ******* Dungeon Instance Maps ******* */

InstanceMap::InstanceMap(uint32 id, time_t expiry, uint32 InstanceId, Difficulty SpawnMode, Map* _parent, TeamId InstanceTeam)
  : Map(id, expiry, InstanceId, SpawnMode, _parent),
    m_resetAfterUnload(false), m_unloadWhenEmpty(false),
    i_data(nullptr), i_script_id(0), i_script_team(InstanceTeam), i_scenario(nullptr)
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
        TC_LOG_ERROR("maps", "InstanceMap::CannotEnter - player %s %s already in map %d, %d, %d!", player->GetName().c_str(), player->GetGUID().ToString().c_str(), GetId(), GetInstanceId(), GetDifficultyID());
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
                player->AddInstanceEnterTime(GetInstanceId(), GameTime::GetGameTime());

            // get or create an instance save for the map
            InstanceSave* mapSave = sInstanceSaveMgr->GetInstanceSave(GetInstanceId());
            if (!mapSave)
            {
                TC_LOG_DEBUG("maps", "InstanceMap::Add: creating instance save for map %d spawnmode %d with instance id %d", GetId(), GetDifficultyID(), GetInstanceId());
                mapSave = sInstanceSaveMgr->AddInstanceSave(GetId(), GetInstanceId(), GetDifficultyID(), 0, 0, true);
            }

            ASSERT(mapSave);

            // check for existing instance binds
            InstancePlayerBind* playerBind = player->GetBoundInstance(GetId(), GetDifficultyID());
            if (playerBind && playerBind->perm)
            {
                // cannot enter other instances if bound permanently
                if (playerBind->save != mapSave)
                {
                    TC_LOG_ERROR("maps", "InstanceMap::Add: player %s %s is permanently bound to instance %s %d, %d, %d, %d, %d, %d but he is being put into instance %s %d, %d, %d, %d, %d, %d", player->GetName().c_str(), player->GetGUID().ToString().c_str(), GetMapName(), playerBind->save->GetMapId(), playerBind->save->GetInstanceId(), static_cast<uint32>(playerBind->save->GetDifficultyID()), playerBind->save->GetPlayerCount(), playerBind->save->GetGroupCount(), playerBind->save->CanReset(), GetMapName(), mapSave->GetMapId(), mapSave->GetInstanceId(), static_cast<uint32>(mapSave->GetDifficultyID()), mapSave->GetPlayerCount(), mapSave->GetGroupCount(), mapSave->CanReset());
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
                        TC_LOG_ERROR("maps", "InstanceMap::Add: player %s %s is being put into instance %s %d, %d, %d, %d, %d, %d but he is in group %s and is bound to instance %d, %d, %d, %d, %d, %d!", player->GetName().c_str(), player->GetGUID().ToString().c_str(), GetMapName(), mapSave->GetMapId(), mapSave->GetInstanceId(), static_cast<uint32>(mapSave->GetDifficultyID()), mapSave->GetPlayerCount(), mapSave->GetGroupCount(), mapSave->CanReset(), group->GetLeaderGUID().ToString().c_str(), playerBind->save->GetMapId(), playerBind->save->GetInstanceId(), static_cast<uint32>(playerBind->save->GetDifficultyID()), playerBind->save->GetPlayerCount(), playerBind->save->GetGroupCount(), playerBind->save->CanReset());
                        if (groupBind)
                            TC_LOG_ERROR("maps", "InstanceMap::Add: the group is bound to the instance %s %d, %d, %d, %d, %d, %d", GetMapName(), groupBind->save->GetMapId(), groupBind->save->GetInstanceId(), static_cast<uint32>(groupBind->save->GetDifficultyID()), groupBind->save->GetPlayerCount(), groupBind->save->GetGroupCount(), groupBind->save->CanReset());
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
                            TC_LOG_ERROR("maps", "InstanceMap::Add: player %s %s is being put into instance %d, %d, %d but he is in group %s which is bound to instance %d, %d, %d!", player->GetName().c_str(), player->GetGUID().ToString().c_str(), mapSave->GetMapId(), mapSave->GetInstanceId(), static_cast<uint32>(mapSave->GetDifficultyID()), group->GetLeaderGUID().ToString().c_str(), groupBind->save->GetMapId(), groupBind->save->GetInstanceId(), static_cast<uint32>(groupBind->save->GetDifficultyID()));
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
                            player->SendDirectMessage(pendingRaidLock.Write());
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

void InstanceMap::Update(uint32 t_diff)
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

    if (i_data)
        i_data->OnPlayerLeave(player);

    // if last player set unload timer
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
    if (i_data != nullptr)
        return;

    InstanceTemplate const* mInstance = sObjectMgr->GetInstanceTemplate(GetId());
    if (mInstance)
    {
        i_script_id = mInstance->ScriptId;
        i_data = sScriptMgr->CreateInstanceData(this);
    }

    if (!i_data)
        return;

    if (load)
    {
        /// @todo make a global storage for this
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_INSTANCE);
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
    else
        i_data->Create();
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
        TC_LOG_ERROR("maps", "Cannot bind players to instance map (Name: %s, Entry: %u, Difficulty: %u, ID: %u) because no instance save is available!", GetMapName(), GetId(), static_cast<uint32>(GetDifficultyID()), GetInstanceId());
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
                TC_LOG_ERROR("maps", "Player (%s, Name: %s) is in instance map (Name: %s, Entry: %u, Difficulty: %u, ID: %u) that is being bound, but already has a save for the map on ID %u!", player->GetGUID().ToString().c_str(), player->GetName().c_str(), GetMapName(), save->GetMapId(), static_cast<uint32>(save->GetDifficultyID()), save->GetInstanceId(), bind->save->GetInstanceId());
            }
            else if (!bind->save)
            {
                TC_LOG_ERROR("maps", "Player (%s, Name: %s) is in instance map (Name: %s, Entry: %u, Difficulty: %u, ID: %u) that is being bound, but already has a bind (without associated save) for the map!", player->GetGUID().ToString().c_str(), player->GetName().c_str(), GetMapName(), save->GetMapId(), static_cast<uint32>(save->GetDifficultyID()), save->GetInstanceId());
            }
        }
        else
        {
            player->BindToInstance(save, true);
            WorldPackets::Instance::InstanceSaveCreated data;
            data.Gm = player->IsGameMaster();
            player->SendDirectMessage(data.Write());
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
            sInstanceSaveMgr->ScheduleReset(on, save->GetResetTime(), InstanceSaveManager::InstResetEvent(0, GetId(), GetDifficultyID(), GetInstanceId()));
        else
            TC_LOG_ERROR("maps", "InstanceMap::SetResetSchedule: cannot turn schedule %s, there is no save information for instance (map [id: %u, name: %s], instance id: %u, difficulty: %u)",
                on ? "on" : "off", GetId(), GetMapName(), GetInstanceId(), static_cast<uint32>(GetDifficultyID()));
    }
}

MapDifficultyEntry const* Map::GetMapDifficulty() const
{
    return sDB2Manager.GetMapDifficultyData(GetId(), GetDifficultyID());
}

ItemContext Map::GetDifficultyLootItemContext() const
{
    if (MapDifficultyEntry const* mapDifficulty = GetMapDifficulty())
        if (mapDifficulty->ItemContext)
            return ItemContext(mapDifficulty->ItemContext);

    if (DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(GetDifficultyID()))
        return ItemContext(difficulty->ItemContext);

    return ItemContext::NONE;
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

bool Map::IsScenario() const
{
    return i_mapEntry && i_mapEntry->IsScenario();
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
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PERM_BIND_BY_INSTANCE);
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

BattlegroundMap::BattlegroundMap(uint32 id, time_t expiry, uint32 InstanceId, Map* _parent, Difficulty spawnMode)
  : Map(id, expiry, InstanceId, spawnMode, _parent), m_bg(nullptr)
{
    //lets initialize visibility distance for BG/Arenas
    BattlegroundMap::InitVisibilityDistance();
}

BattlegroundMap::~BattlegroundMap()
{
    if (m_bg)
    {
        //unlink to prevent crash, always unlink all pointer reference before destruction
        m_bg->SetBgMap(nullptr);
        m_bg = nullptr;
    }
}

void BattlegroundMap::InitVisibilityDistance()
{
    //init visibility distance for BG/Arenas
    m_VisibleDistance        = IsBattleArena() ? World::GetMaxVisibleDistanceInArenas() : World::GetMaxVisibleDistanceInBG();
    m_VisibilityNotifyPeriod = IsBattleArena() ? World::GetVisibilityNotifyPeriodInArenas() : World::GetVisibilityNotifyPeriodInBG();
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

SceneObject* Map::GetSceneObject(ObjectGuid const& guid)
{
    return _objectsStore.Find<SceneObject>(guid);
}

Conversation* Map::GetConversation(ObjectGuid const& guid)
{
    return _objectsStore.Find<Conversation>(guid);
}

Player* Map::GetPlayer(ObjectGuid const& guid)
{
    return ObjectAccessor::GetPlayer(this, guid);
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
        return nullptr;

    GameObject* go = GetGameObject(guid);
    return go ? go->ToTransport() : nullptr;
}

Creature* Map::GetCreatureBySpawnId(ObjectGuid::LowType spawnId) const
{
    auto const bounds = GetCreatureBySpawnIdStore().equal_range(spawnId);
    if (bounds.first == bounds.second)
        return nullptr;

    std::unordered_multimap<ObjectGuid::LowType, Creature*>::const_iterator creatureItr = std::find_if(bounds.first, bounds.second, [](Map::CreatureBySpawnIdContainer::value_type const& pair)
    {
        return pair.second->IsAlive();
    });

    return creatureItr != bounds.second ? creatureItr->second : bounds.first->second;
}

GameObject* Map::GetGameObjectBySpawnId(ObjectGuid::LowType spawnId) const
{
    auto const bounds = GetGameObjectBySpawnIdStore().equal_range(spawnId);
    if (bounds.first == bounds.second)
        return nullptr;

    std::unordered_multimap<ObjectGuid::LowType, GameObject*>::const_iterator creatureItr = std::find_if(bounds.first, bounds.second, [](Map::GameObjectBySpawnIdContainer::value_type const& pair)
    {
        return pair.second->isSpawned();
    });

    return creatureItr != bounds.second ? creatureItr->second : bounds.first->second;
}

AreaTrigger* Map::GetAreaTriggerBySpawnId(ObjectGuid::LowType spawnId) const
{
    auto const bounds = GetAreaTriggerBySpawnIdStore().equal_range(spawnId);
    if (bounds.first == bounds.second)
        return nullptr;

    return bounds.first->second;
}

void Map::UpdateIteratorBack(Player* player)
{
    if (m_mapRefIter == player->GetMapRef())
        m_mapRefIter = m_mapRefIter->nocheck_prev();
}

void Map::SaveRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId, uint32 entry, time_t respawnTime, uint32 gridId, CharacterDatabaseTransaction dbTrans, bool startup)
{
    SpawnMetadata const* data = sObjectMgr->GetSpawnMetadata(type, spawnId);
    if (!data)
    {
        TC_LOG_ERROR("maps", "Map %u attempt to save respawn time for nonexistant spawnid (%u," UI64FMTD ").", GetId(), type, spawnId);
        return;
    }

    if (!respawnTime)
    {
        // Delete only
        RemoveRespawnTime(data->type, data->spawnId, dbTrans);
        return;
    }

    RespawnInfo ri;
    ri.type = data->type;
    ri.spawnId = data->spawnId;
    ri.entry = entry;
    ri.respawnTime = respawnTime;
    ri.gridId = gridId;
    bool success = AddRespawnInfo(ri);

    if (startup)
    {
        if (!success)
            TC_LOG_ERROR("maps", "Attempt to load saved respawn %" PRIu64 " for (%u," UI64FMTD ") failed - duplicate respawn? Skipped.", respawnTime, uint32(type), spawnId);
    }
    else if (success)
        SaveRespawnInfoDB(ri, dbTrans);
}

void Map::SaveRespawnInfoDB(RespawnInfo const& info, CharacterDatabaseTransaction dbTrans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_RESPAWN);
    stmt->setUInt16(0, info.type);
    stmt->setUInt64(1, info.spawnId);
    stmt->setInt64(2, info.respawnTime);
    stmt->setUInt16(3, GetId());
    stmt->setUInt32(4, GetInstanceId());
    CharacterDatabase.ExecuteOrAppend(dbTrans, stmt);
}

void Map::LoadRespawnTimes()
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_RESPAWNS);
    stmt->setUInt16(0, GetId());
    stmt->setUInt32(1, GetInstanceId());
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
    {
        do
        {
            Field* fields = result->Fetch();
            SpawnObjectType type = SpawnObjectType(fields[0].GetUInt16());
            ObjectGuid::LowType spawnId = fields[1].GetUInt64();
            time_t respawnTime = fields[2].GetInt64();

            if (SpawnData::TypeHasData(type))
            {
                if (SpawnData const* data = sObjectMgr->GetSpawnData(type, spawnId))
                    SaveRespawnTime(type, spawnId, data->id, time_t(respawnTime), Trinity::ComputeGridCoord(data->spawnPoint.GetPositionX(), data->spawnPoint.GetPositionY()).GetId(), nullptr, true);
                else
                    TC_LOG_ERROR("maps", "Loading saved respawn time of %" PRIu64 " for spawnid (%u," UI64FMTD ") - spawn does not exist, ignoring", respawnTime, uint32(type), spawnId);
            }
            else
            {
                TC_LOG_ERROR("maps", "Loading saved respawn time of %" PRIu64 " for spawnid (%u," UI64FMTD ") - invalid spawn type, ignoring", respawnTime, uint32(type), spawnId);
            }

        } while (result->NextRow());
    }
}

/*static*/ void Map::DeleteRespawnTimesInDB(uint16 mapId, uint32 instanceId)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_RESPAWNS);
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
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CORPSES);
    stmt->setUInt32(0, GetId());
    stmt->setUInt32(1, GetInstanceId());

    //        0     1     2     3            4      5          6          7     8      9       10     11        12    13          14          15
    // SELECT posX, posY, posZ, orientation, mapId, displayId, itemCache, race, class, gender, flags, dynFlags, time, corpseType, instanceId, guid FROM corpse WHERE mapId = ? AND instanceId = ?
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return;

    std::unordered_map<ObjectGuid::LowType, std::unordered_set<uint32>> phases;
    std::unordered_map<ObjectGuid::LowType, std::vector<UF::ChrCustomizationChoice>> customizations;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CORPSE_PHASES);
    stmt->setUInt32(0, GetId());
    stmt->setUInt32(1, GetInstanceId());

    //        0          1
    // SELECT OwnerGuid, PhaseId FROM corpse_phases cp LEFT JOIN corpse c ON cp.OwnerGuid = c.guid WHERE c.mapId = ? AND c.instanceId = ?
    if (PreparedQueryResult phaseResult = CharacterDatabase.Query(stmt))
    {
        do
        {
            Field* fields = phaseResult->Fetch();
            ObjectGuid::LowType guid = fields[0].GetUInt64();
            uint32 phaseId = fields[1].GetUInt32();

            phases[guid].insert(phaseId);

        } while (phaseResult->NextRow());
    }

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CORPSE_CUSTOMIZATIONS);
    stmt->setUInt32(0, GetId());
    stmt->setUInt32(1, GetInstanceId());

    //        0             1                            2
    // SELECT cc.ownerGuid, cc.chrCustomizationOptionID, cc.chrCustomizationChoiceID FROM corpse_customizations cc LEFT JOIN corpse c ON cc.ownerGuid = c.guid WHERE c.mapId = ? AND c.instanceId = ?
    if (PreparedQueryResult customizationResult = CharacterDatabase.Query(stmt))
    {
        do
        {
            Field* fields = customizationResult->Fetch();
            ObjectGuid::LowType guid = fields[0].GetUInt64();
            std::vector<UF::ChrCustomizationChoice>& customizationsForCorpse = customizations[guid];

            customizationsForCorpse.emplace_back();
            UF::ChrCustomizationChoice& choice = customizationsForCorpse.back();
            choice.ChrCustomizationOptionID = fields[1].GetUInt32();
            choice.ChrCustomizationChoiceID = fields[2].GetUInt32();

        } while (customizationResult->NextRow());
    }

    do
    {
        Field* fields = result->Fetch();
        CorpseType type = CorpseType(fields[13].GetUInt8());
        ObjectGuid::LowType guid = fields[15].GetUInt64();
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

        for (uint32 phaseId : phases[guid])
            PhasingHandler::AddPhase(corpse, phaseId, false);

        corpse->SetCustomizations(Trinity::Containers::MakeIteratorPair(customizations[guid].begin(), customizations[guid].end()));

        AddCorpse(corpse);

    } while (result->NextRow());
}

void Map::DeleteCorpseData()
{
    // DELETE cp, c FROM corpse_phases cp INNER JOIN corpse c ON cp.OwnerGuid = c.guid WHERE c.mapId = ? AND c.instanceId = ?
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CORPSES_FROM_MAP);
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

    corpse->UpdateObjectVisibilityOnDestroy();
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
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    corpse->DeleteFromDB(trans);
    CharacterDatabase.CommitTransaction(trans);

    Corpse* bones = nullptr;

    // create the bones only if the map and the grid is loaded at the corpse's location
    // ignore bones creating option in case insignia
    if ((insignia ||
        (IsBattlegroundOrArena() ? sWorld->getBoolConfig(CONFIG_DEATH_BONES_BG_OR_ARENA) : sWorld->getBoolConfig(CONFIG_DEATH_BONES_WORLD))) &&
        !IsRemovalGrid(corpse->GetPositionX(), corpse->GetPositionY()))
    {
        // Create bones, don't change Corpse
        bones = new Corpse();
        bones->Create(corpse->GetGUID().GetCounter(), this);

        bones->ReplaceAllCorpseDynamicFlags(corpse->GetCorpseDynamicFlags());
        bones->SetOwnerGUID(corpse->m_corpseData->Owner);
        bones->SetPartyGUID(corpse->m_corpseData->PartyGUID);
        bones->SetGuildGUID(corpse->m_corpseData->GuildGUID);
        bones->SetDisplayId(corpse->m_corpseData->DisplayID);
        bones->SetRace(corpse->m_corpseData->RaceID);
        bones->SetSex(corpse->m_corpseData->Sex);
        bones->SetClass(corpse->m_corpseData->Class);
        bones->SetCustomizations(Trinity::Containers::MakeIteratorPair(corpse->m_corpseData->Customizations.begin(), corpse->m_corpseData->Customizations.end()));
        bones->ReplaceAllFlags(corpse->m_corpseData->Flags | CORPSE_FLAG_BONES);
        bones->SetFactionTemplate(corpse->m_corpseData->FactionTemplate);

        bones->SetCellCoord(corpse->GetCellCoord());
        bones->Relocate(corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ(), corpse->GetOrientation());

        PhasingHandler::InheritPhaseShift(bones, corpse);

        AddCorpse(bones);

        bones->UpdatePositionData();
        bones->SetZoneScript();

        // add bones in grid store if grid loaded where corpse placed
        AddToMap(bones);
    }

    // all references to the corpse should be removed at this point
    delete corpse;

    return bones;
}

void Map::RemoveOldCorpses()
{
    time_t now = GameTime::GetGameTime();

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

    for (ZoneDynamicInfo::LightOverride const& lightOverride : itr->second.LightOverrides)
    {
        WorldPackets::Misc::OverrideLight overrideLight;
        overrideLight.AreaLightID = lightOverride.AreaLightId;
        overrideLight.OverrideLightID = lightOverride.OverrideLightId;
        overrideLight.TransitionMilliseconds = lightOverride.TransitionMilliseconds;
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
        WorldPackets::Misc::Weather weather(weatherId, zoneDynamicInfo.Intensity);
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
        info.DefaultWeather = std::make_unique<Weather>(zoneId, weatherData);
        info.DefaultWeather->ReGenerate();
        info.DefaultWeather->UpdateWeather();
    }

    return info.DefaultWeather.get();
}

WeatherState Map::GetZoneWeather(uint32 zoneId) const
{
    ZoneDynamicInfo const* zoneDynamicInfo = Trinity::Containers::MapGetValuePtr(_zoneDynamicInfo, zoneId);
    if (zoneDynamicInfo)
    {
        if (WeatherState weatherId = zoneDynamicInfo->WeatherId)
            return weatherId;

        if (zoneDynamicInfo->DefaultWeather)
            return zoneDynamicInfo->DefaultWeather->GetWeatherState();
    }

    return WEATHER_STATE_FINE;
}

void Map::SetZoneWeather(uint32 zoneId, WeatherState weatherId, float intensity)
{
    ZoneDynamicInfo& info = _zoneDynamicInfo[zoneId];
    info.WeatherId = weatherId;
    info.Intensity = intensity;

    Map::PlayerList const& players = GetPlayers();
    if (!players.isEmpty())
    {
        WorldPackets::Misc::Weather weather(weatherId, intensity);
        weather.Write();

        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            if (Player* player = itr->GetSource())
                if (player->GetZoneId() == zoneId)
                    player->SendDirectMessage(weather.GetRawPacket());
    }
}

void Map::SetZoneOverrideLight(uint32 zoneId, uint32 areaLightId, uint32 overrideLightId, Milliseconds transitionTime)
{
    ZoneDynamicInfo& info = _zoneDynamicInfo[zoneId];
    // client can support only one override for each light (zone independent)
    info.LightOverrides.erase(std::remove_if(info.LightOverrides.begin(), info.LightOverrides.end(), [areaLightId](ZoneDynamicInfo::LightOverride const& lightOverride)
    {
        return lightOverride.AreaLightId == areaLightId;
    }), info.LightOverrides.end());

    // set new override (if any)
    if (overrideLightId)
    {
        ZoneDynamicInfo::LightOverride& lightOverride = info.LightOverrides.emplace_back();
        lightOverride.AreaLightId = areaLightId;
        lightOverride.OverrideLightId = overrideLightId;
        lightOverride.TransitionMilliseconds = static_cast<uint32>(transitionTime.count());
    }

    Map::PlayerList const& players = GetPlayers();
    if (!players.isEmpty())
    {
        WorldPackets::Misc::OverrideLight overrideLight;
        overrideLight.AreaLightID = areaLightId;
        overrideLight.OverrideLightID = overrideLightId;
        overrideLight.TransitionMilliseconds = static_cast<uint32>(transitionTime.count());
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
    {
        if (Player* player = itr->GetSource())
        {
            if (player->IsInWorld())
            {
                player->UpdateAreaDependentAuras(player->GetAreaId());
                player->UpdateZoneDependentAuras(player->GetZoneId());
            }
        }
    }
}

std::string Map::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << std::boolalpha
        << "Id: " << GetId() << " InstanceId: " << GetInstanceId() << " Difficulty: " << std::to_string(GetDifficultyID())
        << " HasPlayers: " << HavePlayers();
    return sstr.str();
}

std::string InstanceMap::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << Map::GetDebugInfo() << "\n"
        << std::boolalpha
        << "ScriptId: " << GetScriptId() << " ScriptName: " << GetScriptName();
    return sstr.str();
}
