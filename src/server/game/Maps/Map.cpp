/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "MapManager.h"
#include "Player.h"
#include "Vehicle.h"
#include "GridNotifiers.h"
#include "Log.h"
#include "GridStates.h"
#include "CellImpl.h"
#include "InstanceData.h"
#include "Map.h"
#include "GridNotifiersImpl.h"
#include "Config.h"
#include "Transport.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "World.h"
#include "Group.h"
#include "MapRefManager.h"
#include "Vehicle.h"
#include "WaypointManager.h"
#include "DBCEnums.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GossipDef.h"

#include "MapInstanced.h"
#include "InstanceSaveMgr.h"
#include "VMapFactory.h"

#define DEFAULT_GRID_EXPIRY     300
#define MAX_GRID_LOAD_TIME      50
#define MAX_CREATURE_ATTACK_RADIUS  (45.0f * sWorld.getRate(RATE_CREATURE_AGGRO))

GridState* si_GridStates[MAX_GRID_STATE];

struct ScriptAction
{
    uint64 sourceGUID;
    uint64 targetGUID;
    uint64 ownerGUID;                                       // owner of source if source is item
    ScriptInfo const* script;                               // pointer to static script data
};

Map::~Map()
{
    UnloadAll();

    while (!i_worldObjects.empty())
    {
        WorldObject *obj = *i_worldObjects.begin();
        ASSERT(obj->m_isWorldObject);
        //ASSERT(obj->GetTypeId() == TYPEID_CORPSE);
        obj->RemoveFromWorld();
        obj->ResetMap();
    }

    if (!m_scriptSchedule.empty())
        sWorld.DecreaseScheduledScriptCount(m_scriptSchedule.size());
}

bool Map::ExistMap(uint32 mapid,int gx,int gy)
{
    int len = sWorld.GetDataPath().length()+strlen("maps/%03u%02u%02u.map")+1;
    char* tmp = new char[len];
    snprintf(tmp, len, (char *)(sWorld.GetDataPath()+"maps/%03u%02u%02u.map").c_str(),mapid,gx,gy);

    FILE *pf=fopen(tmp,"rb");

    if (!pf)
    {
        sLog.outError("Map file '%s': does not exist!",tmp);
        delete[] tmp;
        return false;
    }

    map_fileheader header;
    fread(&header, sizeof(header), 1, pf);
    if (header.mapMagic != uint32(MAP_MAGIC) || header.versionMagic != uint32(MAP_VERSION_MAGIC))
    {
        sLog.outError("Map file '%s' is from an incompatible clientversion. Please recreate using the mapextractor.",tmp);
        delete [] tmp;
        fclose(pf);                                         //close file before return
        return false;
    }

    delete [] tmp;
    fclose(pf);
    return true;
}

bool Map::ExistVMap(uint32 mapid,int gx,int gy)
{
    if (VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager())
    {
        if (vmgr->isMapLoadingEnabled())
        {
            bool exists = vmgr->existsMap((sWorld.GetDataPath()+ "vmaps").c_str(),  mapid, gx,gy);
            if (!exists)
            {
                std::string name = vmgr->getDirFileName(mapid,gx,gy);
                sLog.outError("VMap file '%s' is missing or points to wrong version of vmap file. Redo vmaps with latest version of vmap_assembler.exe.", (sWorld.GetDataPath()+"vmaps/"+name).c_str());
                return false;
            }
        }
    }

    return true;
}

void Map::LoadVMap(int gx,int gy)
{
                                                            // x and y are swapped !!
    int vmapLoadResult = VMAP::VMapFactory::createOrGetVMapManager()->loadMap((sWorld.GetDataPath()+ "vmaps").c_str(),  GetId(), gx,gy);
    switch(vmapLoadResult)
    {
        case VMAP::VMAP_LOAD_RESULT_OK:
            sLog.outDetail("VMAP loaded name:%s, id:%d, x:%d, y:%d (vmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx,gy,gx,gy);
            break;
        case VMAP::VMAP_LOAD_RESULT_ERROR:
            sLog.outDetail("Could not load VMAP name:%s, id:%d, x:%d, y:%d (vmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx,gy,gx,gy);
            break;
        case VMAP::VMAP_LOAD_RESULT_IGNORED:
            DEBUG_LOG("Ignored VMAP name:%s, id:%d, x:%d, y:%d (vmap rep.: x:%d, y:%d)", GetMapName(), GetId(), gx,gy,gx,gy);
            break;
    }
}

void Map::LoadMap(int gx,int gy, bool reload)
{
    if (i_InstanceId != 0)
    {
        if (GridMaps[gx][gy])
            return;

        // load grid map for base map
        if (!m_parentMap->GridMaps[gx][gy])
            m_parentMap->EnsureGridCreated(GridPair(63-gx,63-gy));

        ((MapInstanced*)(m_parentMap))->AddGridMapReference(GridPair(gx,gy));
        GridMaps[gx][gy] = m_parentMap->GridMaps[gx][gy];
        return;
    }

    if (GridMaps[gx][gy] && !reload)
        return;

    //map already load, delete it before reloading (Is it necessary? Do we really need the ability the reload maps during runtime?)
    if (GridMaps[gx][gy])
    {
        sLog.outDetail("Unloading previously loaded map %u before reloading.",GetId());
        delete (GridMaps[gx][gy]);
        GridMaps[gx][gy]=NULL;
    }

    // map file name
    char *tmp=NULL;
    int len = sWorld.GetDataPath().length()+strlen("maps/%03u%02u%02u.map")+1;
    tmp = new char[len];
    snprintf(tmp, len, (char *)(sWorld.GetDataPath()+"maps/%03u%02u%02u.map").c_str(),GetId(),gx,gy);
    sLog.outDetail("Loading map %s",tmp);
    // loading data
    GridMaps[gx][gy] = new GridMap();
    if (!GridMaps[gx][gy]->loadData(tmp))
    {
        sLog.outError("Error loading map file: \n %s\n", tmp);
    }
    delete [] tmp;
}

void Map::LoadMapAndVMap(int gx,int gy)
{
    LoadMap(gx,gy);
    if (i_InstanceId == 0)
        LoadVMap(gx, gy);                                   // Only load the data for the base map
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

Map::Map(uint32 id, time_t expiry, uint32 InstanceId, uint8 SpawnMode, Map* _parent)
  : i_mapEntry (sMapStore.LookupEntry(id)), i_spawnMode(SpawnMode), i_InstanceId(InstanceId), m_unloadTimer(0),
  m_activeNonPlayersIter(m_activeNonPlayers.end()),
  i_gridExpiry(expiry), m_parentMap(_parent ? _parent : this),
  m_VisibleDistance(DEFAULT_VISIBILITY_DISTANCE),
  m_VisibilityNotifyPeriod(DEFAULT_VISIBILITY_NOTIFY_PERIOD),
  i_scriptLock(false)
{
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
}

void Map::InitVisibilityDistance()
{
    //init visibility for continents
    m_VisibleDistance = World::GetMaxVisibleDistanceOnContinents();
    m_VisibilityNotifyPeriod = World::GetVisibilityNotifyPeriodOnContinents();
}

// Template specialization of utility methods
template<class T>
void Map::AddToGrid(T* obj, NGridType *grid, Cell const& cell)
{
    if (obj->m_isWorldObject)
        (*grid)(cell.CellX(), cell.CellY()).template AddWorldObject<T>(obj);
    else
        (*grid)(cell.CellX(), cell.CellY()).template AddGridObject<T>(obj);
}

template<>
void Map::AddToGrid(Creature* obj, NGridType *grid, Cell const& cell)
{
    if (obj->m_isWorldObject)
        (*grid)(cell.CellX(), cell.CellY()).AddWorldObject(obj);
    else
        (*grid)(cell.CellX(), cell.CellY()).AddGridObject(obj);

    obj->SetCurrentCell(cell);
}

template<class T>
void Map::RemoveFromGrid(T* obj, NGridType *grid, Cell const& cell)
{
    if (obj->m_isWorldObject)
        (*grid)(cell.CellX(), cell.CellY()).template RemoveWorldObject<T>(obj);
    else
        (*grid)(cell.CellX(), cell.CellY()).template RemoveGridObject<T>(obj);
}

template<class T>
void Map::SwitchGridContainers(T* obj, bool on)
{
    CellPair p = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
    {
        sLog.outError("Map::SwitchGridContainers: Object " I64FMT " has invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUID(), obj->GetPositionX(), obj->GetPositionY(), p.x_coord, p.y_coord);
        return;
    }

    Cell cell(p);
    if (!loaded(GridPair(cell.data.Part.grid_x, cell.data.Part.grid_y)))
        return;

    DEBUG_LOG("Switch object " I64FMT " from grid[%u,%u] %u", obj->GetGUID(), cell.data.Part.grid_x, cell.data.Part.grid_y, on);
    NGridType *ngrid = getNGrid(cell.GridX(), cell.GridY());
    ASSERT(ngrid != NULL);

    GridType &grid = (*ngrid)(cell.CellX(), cell.CellY());

    if (on)
    {
        grid.RemoveGridObject<T>(obj);
        grid.AddWorldObject<T>(obj);
        /*if (!grid.RemoveGridObject<T>(obj, obj->GetGUID())
            || !grid.AddWorldObject<T>(obj, obj->GetGUID()))
        {
            ASSERT(false);
        }*/
    }
    else
    {
        grid.RemoveWorldObject<T>(obj);
        grid.AddGridObject<T>(obj);
        /*if (!grid.RemoveWorldObject<T>(obj, obj->GetGUID())
            || !grid.AddGridObject<T>(obj, obj->GetGUID()))
        {
            ASSERT(false);
        }*/
    }
    obj->m_isWorldObject = on;
}

template void Map::SwitchGridContainers(Creature *, bool);
//template void Map::SwitchGridContainers(DynamicObject *, bool);

template<class T>
void Map::DeleteFromWorld(T* obj)
{
    // Note: In case resurrectable corpse and pet its removed from global lists in own destructor
    delete obj;
}

template<>
void Map::DeleteFromWorld(Player* pl)
{
    sObjectAccessor.RemoveObject(pl);
    delete pl;
}

void
Map::EnsureGridCreated(const GridPair &p)
{
    if (!getNGrid(p.x_coord, p.y_coord))
    {
        ACE_GUARD(ACE_Thread_Mutex, Guard, Lock);
        if (!getNGrid(p.x_coord, p.y_coord))
        {
            sLog.outDebug("Creating grid[%u,%u] for map %u instance %u", p.x_coord, p.y_coord, GetId(), i_InstanceId);

            setNGrid(new NGridType(p.x_coord*MAX_NUMBER_OF_GRIDS + p.y_coord, p.x_coord, p.y_coord, i_gridExpiry, sWorld.getConfig(CONFIG_GRID_UNLOAD)),
                p.x_coord, p.y_coord);

            // build a linkage between this map and NGridType
            buildNGridLinkage(getNGrid(p.x_coord, p.y_coord));

            getNGrid(p.x_coord, p.y_coord)->SetGridState(GRID_STATE_IDLE);

            //z coord
            int gx = (MAX_NUMBER_OF_GRIDS - 1) - p.x_coord;
            int gy = (MAX_NUMBER_OF_GRIDS - 1) - p.y_coord;

            if (!GridMaps[gx][gy])
                LoadMapAndVMap(gx,gy);
        }
    }
}

void
Map::EnsureGridLoadedAtEnter(const Cell &cell, Player *player)
{
    EnsureGridLoaded(cell);
    NGridType *grid = getNGrid(cell.GridX(), cell.GridY());
    ASSERT(grid != NULL);

    if (player)
    {
        DEBUG_LOG("Player %s enter cell[%u,%u] triggers loading of grid[%u,%u] on map %u", player->GetName(), cell.CellX(), cell.CellY(), cell.GridX(), cell.GridY(), GetId());
    }
    else
    {
        DEBUG_LOG("Active object nearby triggers loading of grid [%u,%u] on map %u", cell.GridX(), cell.GridY(), GetId());
    }

    // refresh grid state & timer
    if (grid->GetGridState() != GRID_STATE_ACTIVE)
    {
        ResetGridExpiry(*grid, 0.1f);
        grid->SetGridState(GRID_STATE_ACTIVE);
    }
}

bool Map::EnsureGridLoaded(const Cell &cell)
{
    EnsureGridCreated(GridPair(cell.GridX(), cell.GridY()));
    NGridType *grid = getNGrid(cell.GridX(), cell.GridY());

    ASSERT(grid != NULL);
    if (!isGridObjectDataLoaded(cell.GridX(), cell.GridY()))
    {
        sLog.outDebug("Loading grid[%u,%u] for map %u instance %u", cell.GridX(), cell.GridY(), GetId(), i_InstanceId);

        ObjectGridLoader loader(*grid, this, cell);
        loader.LoadN();

        // Add resurrectable corpses to world object list in grid
        sObjectAccessor.AddCorpsesToGrid(GridPair(cell.GridX(),cell.GridY()),(*grid)(cell.CellX(), cell.CellY()), this);

        setGridObjectDataLoaded(true,cell.GridX(), cell.GridY());
        return true;
    }

    return false;
}

void Map::LoadGrid(float x, float y)
{
    CellPair pair = Trinity::ComputeCellPair(x, y);
    Cell cell(pair);
    EnsureGridLoaded(cell);
}

bool Map::Add(Player *player)
{
    // Check if we are adding to correct map
    ASSERT (player->GetMap() == this);
    CellPair p = Trinity::ComputeCellPair(player->GetPositionX(), player->GetPositionY());
    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
    {
        sLog.outError("Map::Add: Player (GUID: %u) has invalid coordinates X:%f Y:%f grid cell [%u:%u]", player->GetGUIDLow(), player->GetPositionX(), player->GetPositionY(), p.x_coord, p.y_coord);
        return false;
    }

    player->SetMap(this);

    Cell cell(p);
    EnsureGridLoadedAtEnter(cell, player);
    NGridType *grid = getNGrid(cell.GridX(), cell.GridY());
    ASSERT(grid != NULL);
    AddToGrid(player, grid, cell);

    player->AddToWorld();

    SendInitSelf(player);
    SendInitTransports(player);

    player->m_clientGUIDs.clear();
    player->UpdateObjectVisibility(true);

    return true;
}

template<class T>
void
Map::Add(T *obj)
{
    CellPair p = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
    {
        sLog.outError("Map::Add: Object " UI64FMTD " has invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUID(), obj->GetPositionX(), obj->GetPositionY(), p.x_coord, p.y_coord);
        return;
    }

    Cell cell(p);
    if (obj->IsInWorld()) // need some clean up later
    {
        obj->UpdateObjectVisibility(true);
        return;
    }

    if (obj->isActiveObject())
        EnsureGridLoadedAtEnter(cell);
    else
        EnsureGridCreated(GridPair(cell.GridX(), cell.GridY()));

    NGridType *grid = getNGrid(cell.GridX(), cell.GridY());
    ASSERT(grid != NULL);

    AddToGrid(obj,grid,cell);
    //obj->SetMap(this);
    obj->AddToWorld();

    if (obj->isActiveObject())
        AddToActive(obj);

    DEBUG_LOG("Object %u enters grid[%u,%u]", GUID_LOPART(obj->GetGUID()), cell.GridX(), cell.GridY());

    //something, such as vehicle, needs to be update immediately
    //also, trigger needs to cast spell, if not update, cannot see visual
    obj->UpdateObjectVisibility(true);
}

/*
void Map::MessageBroadcast(Player *player, WorldPacket *msg, bool to_self)
{
    CellPair p = Trinity::ComputeCellPair(player->GetPositionX(), player->GetPositionY());

    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
    {
        sLog.outError("Map::MessageBroadcast: Player (GUID: %u) have invalid coordinates X:%f Y:%f grid cell [%u:%u]", player->GetGUIDLow(), player->GetPositionX(), player->GetPositionY(), p.x_coord, p.y_coord);
        return;
    }

    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    if (!loaded(GridPair(cell.data.Part.grid_x, cell.data.Part.grid_y)))
        return;

    Trinity::MessageDeliverer post_man(*player, msg, to_self);
    TypeContainerVisitor<Trinity::MessageDeliverer, WorldTypeMapContainer > message(post_man);
    CellLock<ReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, message, *this, *player, GetVisibilityDistance());
}

void Map::MessageBroadcast(WorldObject *obj, WorldPacket *msg)
{
    CellPair p = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());

    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
    {
        sLog.outError("Map::MessageBroadcast: Object (GUID: %u TypeId: %u) have invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUIDLow(), obj->GetTypeId(), obj->GetPositionX(), obj->GetPositionY(), p.x_coord, p.y_coord);
        return;
    }

    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    if (!loaded(GridPair(cell.data.Part.grid_x, cell.data.Part.grid_y)))
        return;

    //TODO: currently on continents when Visibility.Distance.InFlight > Visibility.Distance.Continents
    //we have alot of blinking mobs because monster move packet send is broken...
    Trinity::ObjectMessageDeliverer post_man(*obj,msg);
    TypeContainerVisitor<Trinity::ObjectMessageDeliverer, WorldTypeMapContainer > message(post_man);
    CellLock<ReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, message, *this, *obj, GetVisibilityDistance());
}

void Map::MessageDistBroadcast(Player *player, WorldPacket *msg, float dist, bool to_self, bool own_team_only)
{
    CellPair p = Trinity::ComputeCellPair(player->GetPositionX(), player->GetPositionY());

    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
    {
        sLog.outError("Map::MessageBroadcast: Player (GUID: %u) have invalid coordinates X:%f Y:%f grid cell [%u:%u]", player->GetGUIDLow(), player->GetPositionX(), player->GetPositionY(), p.x_coord, p.y_coord);
        return;
    }

    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    if (!loaded(GridPair(cell.data.Part.grid_x, cell.data.Part.grid_y)))
        return;

    Trinity::MessageDistDeliverer post_man(*player, msg, dist, to_self, own_team_only);
    TypeContainerVisitor<Trinity::MessageDistDeliverer , WorldTypeMapContainer > message(post_man);
    CellLock<ReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, message, *this, *player, dist);
}

void Map::MessageDistBroadcast(WorldObject *obj, WorldPacket *msg, float dist)
{
    CellPair p = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());

    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
    {
        sLog.outError("Map::MessageBroadcast: Object (GUID: %u TypeId: %u) have invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUIDLow(), obj->GetTypeId(), obj->GetPositionX(), obj->GetPositionY(), p.x_coord, p.y_coord);
        return;
    }

    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    if (!loaded(GridPair(cell.data.Part.grid_x, cell.data.Part.grid_y)))
        return;

    Trinity::ObjectMessageDistDeliverer post_man(*obj, msg, dist);
    TypeContainerVisitor<Trinity::ObjectMessageDistDeliverer, WorldTypeMapContainer > message(post_man);
    CellLock<ReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, message, *this, *obj, dist);
}
*/

bool Map::loaded(const GridPair &p) const
{
    return (getNGrid(p.x_coord, p.y_coord) && isGridObjectDataLoaded(p.x_coord, p.y_coord));
}

void Map::Update(const uint32 &t_diff)
{
    /// update players at tick
    for (m_mapRefIter = m_mapRefManager.begin(); m_mapRefIter != m_mapRefManager.end(); ++m_mapRefIter)
    {
        Player* plr = m_mapRefIter->getSource();
        if (plr && plr->IsInWorld())
            plr->Update(t_diff);
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
        Player* plr = m_mapRefIter->getSource();

        if (!plr->IsInWorld())
            continue;

        CellPair standing_cell(Trinity::ComputeCellPair(plr->GetPositionX(), plr->GetPositionY()));

        // Check for correctness of standing_cell, it also avoids problems with update_cell
        if (standing_cell.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || standing_cell.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
            continue;

        // the overloaded operators handle range checking
        // so ther's no need for range checking inside the loop
        CellPair begin_cell(standing_cell), end_cell(standing_cell);
        //lets update mobs/objects in ALL visible cells around player!
        CellArea area = Cell::CalculateCellArea(*plr, GetVisibilityDistance());
        area.ResizeBorders(begin_cell, end_cell);

        for (uint32 x = begin_cell.x_coord; x <= end_cell.x_coord; ++x)
        {
            for (uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; ++y)
            {
                // marked cells are those that have been visited
                // don't visit the same cell twice
                uint32 cell_id = (y * TOTAL_NUMBER_OF_CELLS_PER_MAP) + x;
                if (!isCellMarked(cell_id))
                {
                    markCell(cell_id);
                    CellPair pair(x,y);
                    Cell cell(pair);
                    cell.data.Part.reserved = CENTER_DISTRICT;
                    //cell.SetNoCreate();
                    cell.Visit(pair, grid_object_update,  *this);
                    cell.Visit(pair, world_object_update, *this);
                }
            }
        }
    }

    // non-player active objects
    if (!m_activeNonPlayers.empty())
    {
        for (m_activeNonPlayersIter = m_activeNonPlayers.begin(); m_activeNonPlayersIter != m_activeNonPlayers.end();)
        {
            // skip not in world
            WorldObject* obj = *m_activeNonPlayersIter;

            // step before processing, in this case if Map::Remove remove next object we correctly
            // step to next-next, and if we step to end() then newly added objects can wait next update.
            ++m_activeNonPlayersIter;

            if (!obj->IsInWorld())
                continue;

            CellPair standing_cell(Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY()));

            // Check for correctness of standing_cell, it also avoids problems with update_cell
            if (standing_cell.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || standing_cell.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
                continue;

            // the overloaded operators handle range checking
            // so ther's no need for range checking inside the loop
            CellPair begin_cell(standing_cell), end_cell(standing_cell);
            begin_cell << 1; begin_cell -= 1;               // upper left
            end_cell >> 1; end_cell += 1;                   // lower right

            for (uint32 x = begin_cell.x_coord; x <= end_cell.x_coord; ++x)
            {
                for (uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; ++y)
                {
                    // marked cells are those that have been visited
                    // don't visit the same cell twice
                    uint32 cell_id = (y * TOTAL_NUMBER_OF_CELLS_PER_MAP) + x;
                    if (!isCellMarked(cell_id))
                    {
                        markCell(cell_id);
                        CellPair pair(x,y);
                        Cell cell(pair);
                        cell.data.Part.reserved = CENTER_DISTRICT;
                        //cell.SetNoCreate();
                        cell.Visit(pair, grid_object_update,  *this);
                        cell.Visit(pair, world_object_update, *this);
                    }
                }
            }
        }
    }

    ///- Process necessary scripts
    if (!m_scriptSchedule.empty())
    {
        i_scriptLock = true;
        ScriptsProcess();
        i_scriptLock = false;
    }

    MoveAllCreaturesInMoveList();

    if (!m_mapRefManager.isEmpty() || !m_activeNonPlayers.empty())
        ProcessRelocationNotifies(t_diff);
}

struct ResetNotifier
{
    template<class T>inline void resetNotify(GridRefManager<T> &m)
    {
        for (typename GridRefManager<T>::iterator iter=m.begin(); iter != m.end(); ++iter)
            iter->getSource()->ResetAllNotifies();
    }
    template<class T> void Visit(GridRefManager<T> &) {}
    void Visit(CreatureMapType &m) { resetNotify<Creature>(m);}
    void Visit(PlayerMapType &m) { resetNotify<Player>(m);}
};

void Map::ProcessRelocationNotifies(const uint32 & diff)
{
    for (GridRefManager<NGridType>::iterator i = GridRefManager<NGridType>::begin(); i != GridRefManager<NGridType>::end(); ++i)
    {
        NGridType *grid = i->getSource();

        if (grid->GetGridState() != GRID_STATE_ACTIVE)
            continue;

        grid->getGridInfoRef()->getRelocationTimer().TUpdate(diff);
        if (!grid->getGridInfoRef()->getRelocationTimer().TPassed())
            continue;

        uint32 gx = grid->getX(), gy = grid->getY();

        CellPair cell_min(gx*MAX_NUMBER_OF_CELLS, gy*MAX_NUMBER_OF_CELLS);
        CellPair cell_max(cell_min.x_coord + MAX_NUMBER_OF_CELLS, cell_min.y_coord+MAX_NUMBER_OF_CELLS);

        for (uint32 x = cell_min.x_coord; x < cell_max.x_coord; ++x)
        {
            for (uint32 y = cell_min.y_coord; y < cell_max.y_coord; ++y)
            {
                uint32 cell_id = (y * TOTAL_NUMBER_OF_CELLS_PER_MAP) + x;
                if (!isCellMarked(cell_id))
                    continue;

                CellPair pair(x,y);
                Cell cell(pair);
                cell.SetNoCreate();

                Trinity::DelayedUnitRelocation cell_relocation(cell, pair, *this, GetVisibilityDistance());
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
        NGridType *grid = i->getSource();

        if (grid->GetGridState() != GRID_STATE_ACTIVE)
            continue;

        if (!grid->getGridInfoRef()->getRelocationTimer().TPassed())
            continue;

        grid->getGridInfoRef()->getRelocationTimer().TReset(diff, m_VisibilityNotifyPeriod);

        uint32 gx = grid->getX(), gy = grid->getY();

        CellPair cell_min(gx*MAX_NUMBER_OF_CELLS, gy*MAX_NUMBER_OF_CELLS);
        CellPair cell_max(cell_min.x_coord + MAX_NUMBER_OF_CELLS, cell_min.y_coord+MAX_NUMBER_OF_CELLS);

        for (uint32 x = cell_min.x_coord; x < cell_max.x_coord; ++x)
        {
            for (uint32 y = cell_min.y_coord; y < cell_max.y_coord; ++y)
            {
                uint32 cell_id = (y * TOTAL_NUMBER_OF_CELLS_PER_MAP) + x;
                if (!isCellMarked(cell_id))
                    continue;

                CellPair pair(x,y);
                Cell cell(pair);
                cell.SetNoCreate();
                Visit(cell, grid_notifier);
                Visit(cell, world_notifier);
            }
        }
    }
}

void Map::Remove(Player *player, bool remove)
{
    player->RemoveFromWorld();
    SendRemoveTransports(player);

    CellPair p = Trinity::ComputeCellPair(player->GetPositionX(), player->GetPositionY());
    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
        sLog.outCrash("Map::Remove: Player is in invalid cell!");
    else
    {
        Cell cell(p);
        if (!getNGrid(cell.data.Part.grid_x, cell.data.Part.grid_y))
            sLog.outError("Map::Remove() i_grids was NULL x:%d, y:%d",cell.data.Part.grid_x,cell.data.Part.grid_y);
        else
        {
            DEBUG_LOG("Remove player %s from grid[%u,%u]", player->GetName(), cell.GridX(), cell.GridY());
            NGridType *grid = getNGrid(cell.GridX(), cell.GridY());
            ASSERT(grid != NULL);

            player->UpdateObjectVisibility(true);
            RemoveFromGrid(player,grid,cell);
        }
    }

    if (remove)
        DeleteFromWorld(player);
}

bool Map::RemoveBones(uint64 guid, float x, float y)
{
    if (IsRemovalGrid(x, y))
    {
        Corpse * corpse = sObjectAccessor.GetObjectInWorld(GetId(), x, y, guid, (Corpse*)NULL);
        if (corpse && corpse->GetTypeId() == TYPEID_CORPSE && corpse->GetType() == CORPSE_BONES)
            corpse->DeleteBonesFromWorld();
        else
            return false;
    }
    return true;
}

template<class T>
void
Map::Remove(T *obj, bool remove)
{
    obj->RemoveFromWorld();
    if (obj->isActiveObject())
        RemoveFromActive(obj);

    CellPair p = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
    if (p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
        sLog.outError("Map::Remove: Object " I64FMT " has invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUID(), obj->GetPositionX(), obj->GetPositionY(), p.x_coord, p.y_coord);
    else
    {
        Cell cell(p);
        if (loaded(GridPair(cell.data.Part.grid_x, cell.data.Part.grid_y)))
        {
            DEBUG_LOG("Remove object " I64FMT " from grid[%u,%u]", obj->GetGUID(), cell.data.Part.grid_x, cell.data.Part.grid_y);
            NGridType *grid = getNGrid(cell.GridX(), cell.GridY());
            ASSERT(grid != NULL);

            obj->UpdateObjectVisibility(true);
            RemoveFromGrid(obj,grid,cell);
        }
    }

    obj->ResetMap();

    if (remove)
    {
        // if option set then object already saved at this moment
        if (!sWorld.getConfig(CONFIG_SAVE_RESPAWN_TIME_IMMEDIATELY))
            obj->SaveRespawnTime();
        DeleteFromWorld(obj);
    }
}

void
Map::PlayerRelocation(Player *player, float x, float y, float z, float orientation)
{
    ASSERT(player);

    CellPair old_val = Trinity::ComputeCellPair(player->GetPositionX(), player->GetPositionY());
    CellPair new_val = Trinity::ComputeCellPair(x, y);

    Cell old_cell(old_val);
    Cell new_cell(new_val);

    player->Relocate(x, y, z, orientation);

    if (old_cell.DiffGrid(new_cell) || old_cell.DiffCell(new_cell))
    {
        DEBUG_LOG("Player %s relocation grid[%u,%u]cell[%u,%u]->grid[%u,%u]cell[%u,%u]", player->GetName(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());

        NGridType* oldGrid = getNGrid(old_cell.GridX(), old_cell.GridY());
        RemoveFromGrid(player, oldGrid,old_cell);

        if (old_cell.DiffGrid(new_cell))
            EnsureGridLoadedAtEnter(new_cell, player);

        NGridType* newGrid = getNGrid(new_cell.GridX(), new_cell.GridY());
        AddToGrid(player, newGrid,new_cell);
    }

    player->UpdateObjectVisibility(false);
}

void
Map::CreatureRelocation(Creature *creature, float x, float y, float z, float ang)
{
    ASSERT(CheckGridIntegrity(creature,false));

    Cell old_cell = creature->GetCurrentCell();

    CellPair new_val = Trinity::ComputeCellPair(x, y);
    Cell new_cell(new_val);

    // delay creature move for grid/cell to grid/cell moves
    if (old_cell.DiffCell(new_cell) || old_cell.DiffGrid(new_cell))
    {
        #ifdef TRINITY_DEBUG
        if ((sLog.getLogFilter() & LOG_FILTER_CREATURE_MOVES) == 0)
            sLog.outDebug("Creature (GUID: %u Entry: %u) added to moving list from grid[%u,%u]cell[%u,%u] to grid[%u,%u]cell[%u,%u].", creature->GetGUIDLow(), creature->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif
        AddCreatureToMoveList(creature, x, y, z, ang);
        // in diffcell/diffgrid case notifiers called at finishing move creature in Map::MoveAllCreaturesInMoveList
    }
    else
    {
        creature->Relocate(x, y, z, ang);
        creature->UpdateObjectVisibility(false);
    }

    ASSERT(CheckGridIntegrity(creature,true));
}

void Map::AddCreatureToMoveList(Creature *c, float x, float y, float z, float ang)
{
    if (!c)
        return;

    i_creaturesToMove[c] = CreatureMover(x, y, z, ang);
}

void Map::MoveAllCreaturesInMoveList()
{
    while (!i_creaturesToMove.empty())
    {
        // get data and remove element;
        CreatureMoveList::iterator iter = i_creaturesToMove.begin();
        Creature* c = iter->first;
        CreatureMover cm = iter->second;
        i_creaturesToMove.erase(iter);

        // calculate cells
        CellPair new_val = Trinity::ComputeCellPair(cm.x, cm.y);
        Cell new_cell(new_val);

        // do move or do move to respawn or remove creature if previous all fail
        if (CreatureCellRelocation(c,new_cell))
        {
            // update pos
            c->Relocate(cm.x, cm.y, cm.z, cm.ang);
            //CreatureRelocationNotify(c,new_cell,new_cell.cellPair());
            c->UpdateObjectVisibility(false);
        }
        else
        {
            // if creature can't be move in new cell/grid (not loaded) move it to repawn cell/grid
            // creature coordinates will be updated and notifiers send
            if (!CreatureRespawnRelocation(c))
            {
                // ... or unload (if respawn grid also not loaded)
                #ifdef TRINITY_DEBUG
                if ((sLog.getLogFilter() & LOG_FILTER_CREATURE_MOVES) == 0)
                    sLog.outDebug("Creature (GUID: %u Entry: %u) cannot be move to unloaded respawn grid.",c->GetGUIDLow(),c->GetEntry());
                #endif
                AddObjectToRemoveList(c);
            }
        }
    }
}

bool Map::CreatureCellRelocation(Creature *c, Cell new_cell)
{
    Cell const& old_cell = c->GetCurrentCell();
    if (!old_cell.DiffGrid(new_cell))                       // in same grid
    {
        // if in same cell then none do
        if (old_cell.DiffCell(new_cell))
        {
            #ifdef TRINITY_DEBUG
            if ((sLog.getLogFilter() & LOG_FILTER_CREATURE_MOVES) == 0)
                sLog.outDebug("Creature (GUID: %u Entry: %u) moved in grid[%u,%u] from cell[%u,%u] to cell[%u,%u].", c->GetGUIDLow(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.CellX(), new_cell.CellY());
            #endif

            RemoveFromGrid(c,getNGrid(old_cell.GridX(), old_cell.GridY()),old_cell);
            AddToGrid(c,getNGrid(new_cell.GridX(), new_cell.GridY()),new_cell);
        }
        else
        {
            #ifdef TRINITY_DEBUG
            if ((sLog.getLogFilter() & LOG_FILTER_CREATURE_MOVES) == 0)
                sLog.outDebug("Creature (GUID: %u Entry: %u) moved in same grid[%u,%u]cell[%u,%u].", c->GetGUIDLow(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY());
            #endif
        }

        return true;
    }

    // in diff. grids but active creature
    if (c->isActiveObject())
    {
        EnsureGridLoadedAtEnter(new_cell);

        #ifdef TRINITY_DEBUG
        if ((sLog.getLogFilter() & LOG_FILTER_CREATURE_MOVES) == 0)
            sLog.outDebug("Active creature (GUID: %u Entry: %u) moved from grid[%u,%u]cell[%u,%u] to grid[%u,%u]cell[%u,%u].", c->GetGUIDLow(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif

        RemoveFromGrid(c,getNGrid(old_cell.GridX(), old_cell.GridY()),old_cell);
        AddToGrid(c,getNGrid(new_cell.GridX(), new_cell.GridY()),new_cell);

        return true;
    }

    // in diff. loaded grid normal creature
    if (loaded(GridPair(new_cell.GridX(), new_cell.GridY())))
    {
        #ifdef TRINITY_DEBUG
        if ((sLog.getLogFilter() & LOG_FILTER_CREATURE_MOVES) == 0)
            sLog.outDebug("Creature (GUID: %u Entry: %u) moved from grid[%u,%u]cell[%u,%u] to grid[%u,%u]cell[%u,%u].", c->GetGUIDLow(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
        #endif

        RemoveFromGrid(c,getNGrid(old_cell.GridX(), old_cell.GridY()),old_cell);
        EnsureGridCreated(GridPair(new_cell.GridX(), new_cell.GridY()));
        AddToGrid(c,getNGrid(new_cell.GridX(), new_cell.GridY()),new_cell);

        return true;
    }

    // fail to move: normal creature attempt move to unloaded grid
    #ifdef TRINITY_DEBUG
    if ((sLog.getLogFilter() & LOG_FILTER_CREATURE_MOVES) == 0)
        sLog.outDebug("Creature (GUID: %u Entry: %u) attempted to move from grid[%u,%u]cell[%u,%u] to unloaded grid[%u,%u]cell[%u,%u].", c->GetGUIDLow(), c->GetEntry(), old_cell.GridX(), old_cell.GridY(), old_cell.CellX(), old_cell.CellY(), new_cell.GridX(), new_cell.GridY(), new_cell.CellX(), new_cell.CellY());
    #endif
    return false;
}

bool Map::CreatureRespawnRelocation(Creature *c)
{
    float resp_x, resp_y, resp_z, resp_o;
    c->GetRespawnCoord(resp_x, resp_y, resp_z, &resp_o);

    CellPair resp_val = Trinity::ComputeCellPair(resp_x, resp_y);
    Cell resp_cell(resp_val);

    c->CombatStop();
    c->GetMotionMaster()->Clear();

    #ifdef TRINITY_DEBUG
    if ((sLog.getLogFilter() & LOG_FILTER_CREATURE_MOVES) == 0)
        sLog.outDebug("Creature (GUID: %u Entry: %u) moved from grid[%u,%u]cell[%u,%u] to respawn grid[%u,%u]cell[%u,%u].", c->GetGUIDLow(), c->GetEntry(), c->GetCurrentCell().GridX(), c->GetCurrentCell().GridY(), c->GetCurrentCell().CellX(), c->GetCurrentCell().CellY(), resp_cell.GridX(), resp_cell.GridY(), resp_cell.CellX(), resp_cell.CellY());
    #endif

    // teleport it to respawn point (like normal respawn if player see)
    if (CreatureCellRelocation(c,resp_cell))
    {
        c->Relocate(resp_x, resp_y, resp_z, resp_o);
        c->GetMotionMaster()->Initialize();                 // prevent possible problems with default move generators
        //CreatureRelocationNotify(c,resp_cell,resp_cell.cellPair());
        c->UpdateObjectVisibility(false);
        return true;
    }
    else
        return false;
}

bool Map::UnloadGrid(const uint32 &x, const uint32 &y, bool unloadAll)
{
    NGridType *grid = getNGrid(x, y);
    ASSERT(grid != NULL);

    {
        if (!unloadAll && ActiveObjectsNearGrid(x, y))
             return false;

        sLog.outDebug("Unloading grid[%u,%u] for map %u", x,y, GetId());

        ObjectGridUnloader unloader(*grid);

        if (!unloadAll)
        {
            // Finish creature moves, remove and delete all creatures with delayed remove before moving to respawn grids
            // Must know real mob position before move
            MoveAllCreaturesInMoveList();

            // move creatures to respawn grids if this is diff.grid or to remove list
            unloader.MoveToRespawnN();

            // Finish creature moves, remove and delete all creatures with delayed remove before unload
            MoveAllCreaturesInMoveList();
        }

        ObjectGridCleaner cleaner(*grid);
        cleaner.CleanN();

        RemoveAllObjectsInRemoveList();

        unloader.UnloadN();

        ASSERT(i_objectsToRemove.empty());

        delete grid;
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
            // x and y are swapped
            VMAP::VMapFactory::createOrGetVMapManager()->unloadMap(GetId(), gx, gy);
        }
        else
            ((MapInstanced*)m_parentMap)->RemoveGridMapReference(GridPair(gx, gy));

        GridMaps[gx][gy] = NULL;
    }
    DEBUG_LOG("Unloading grid[%u,%u] for map %u finished", x,y, GetId());
    return true;
}

void Map::RemoveAllPlayers()
{
    if (HavePlayers())
    {
        for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        {
            Player* plr = itr->getSource();
            if (!plr->IsBeingTeleportedFar())
            {
                // this is happening for bg
                sLog.outError("Map::UnloadAll: player %s is still in map %u during unload, this should not happen!", plr->GetName(), GetId());
                plr->TeleportTo(plr->m_homebindMapId, plr->m_homebindX, plr->m_homebindY, plr->m_homebindZ, plr->GetOrientation());
            }
        }
    }
}

void Map::UnloadAll()
{
    // clear all delayed moves, useless anyway do this moves before map unload.
    i_creaturesToMove.clear();

    for (GridRefManager<NGridType>::iterator i = GridRefManager<NGridType>::begin(); i != GridRefManager<NGridType>::end();)
    {
        NGridType &grid(*i->getSource());
        ++i;
        UnloadGrid(grid.getX(), grid.getY(), true);       // deletes the grid and removes it from the GridRefManager
    }
}

//*****************************
// Grid function
//*****************************
GridMap::GridMap()
{
    m_flags = 0;
    // Area data
    m_gridArea = 0;
    m_area_map = NULL;
    // Height level data
    m_gridHeight = INVALID_HEIGHT;
    m_gridGetHeight = &GridMap::getHeightFromFlat;
    m_V9 = NULL;
    m_V8 = NULL;
    // Liquid data
    m_liquidType    = 0;
    m_liquid_offX   = 0;
    m_liquid_offY   = 0;
    m_liquid_width  = 0;
    m_liquid_height = 0;
    m_liquidLevel = INVALID_HEIGHT;
    m_liquid_type = NULL;
    m_liquid_map  = NULL;
}

GridMap::~GridMap()
{
    unloadData();
}

bool GridMap::loadData(char *filename)
{
    // Unload old data if exist
    unloadData();

    map_fileheader header;
    // Not return error if file not found
    FILE *in = fopen(filename, "rb");
    if (!in)
        return true;
    fread(&header, sizeof(header),1,in);
    if (header.mapMagic == uint32(MAP_MAGIC) && header.versionMagic == uint32(MAP_VERSION_MAGIC))
    {
        // loadup area data
        if (header.areaMapOffset && !loadAreaData(in, header.areaMapOffset, header.areaMapSize))
        {
            sLog.outError("Error loading map area data\n");
            fclose(in);
            return false;
        }
        // loadup height data
        if (header.heightMapOffset && !loadHeihgtData(in, header.heightMapOffset, header.heightMapSize))
        {
            sLog.outError("Error loading map height data\n");
            fclose(in);
            return false;
        }
        // loadup liquid data
        if (header.liquidMapOffset && !loadLiquidData(in, header.liquidMapOffset, header.liquidMapSize))
        {
            sLog.outError("Error loading map liquids data\n");
            fclose(in);
            return false;
        }
        fclose(in);
        return true;
    }
    sLog.outError("Map file '%s' is from an incompatible clientversion. Please recreate using the mapextractor.", filename);
    fclose(in);
    return false;
}

void GridMap::unloadData()
{
    delete[] m_area_map;
    delete[] m_V9;
    delete[] m_V8;
    delete[] m_liquid_type;
    delete[] m_liquid_map;
    m_area_map = NULL;
    m_V9 = NULL;
    m_V8 = NULL;
    m_liquid_type = NULL;
    m_liquid_map  = NULL;
    m_gridGetHeight = &GridMap::getHeightFromFlat;
}

bool GridMap::loadAreaData(FILE *in, uint32 offset, uint32 /*size*/)
{
    map_areaHeader header;
    fseek(in, offset, SEEK_SET);
    fread(&header, sizeof(header), 1, in);
    if (header.fourcc != uint32(MAP_AREA_MAGIC))
        return false;

    m_gridArea = header.gridArea;
    if (!(header.flags & MAP_AREA_NO_AREA))
    {
        m_area_map = new uint16 [16*16];
        fread(m_area_map, sizeof(uint16), 16*16, in);
    }
    return true;
}

bool  GridMap::loadHeihgtData(FILE *in, uint32 offset, uint32 /*size*/)
{
    map_heightHeader header;
    fseek(in, offset, SEEK_SET);
    fread(&header, sizeof(header), 1, in);
    if (header.fourcc != uint32(MAP_HEIGHT_MAGIC))
        return false;

    m_gridHeight = header.gridHeight;
    if (!(header.flags & MAP_HEIGHT_NO_HEIGHT))
    {
        if ((header.flags & MAP_HEIGHT_AS_INT16))
        {
            m_uint16_V9 = new uint16 [129*129];
            m_uint16_V8 = new uint16 [128*128];
            fread(m_uint16_V9, sizeof(uint16), 129*129, in);
            fread(m_uint16_V8, sizeof(uint16), 128*128, in);
            m_gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 65535;
            m_gridGetHeight = &GridMap::getHeightFromUint16;
        }
        else if ((header.flags & MAP_HEIGHT_AS_INT8))
        {
            m_uint8_V9 = new uint8 [129*129];
            m_uint8_V8 = new uint8 [128*128];
            fread(m_uint8_V9, sizeof(uint8), 129*129, in);
            fread(m_uint8_V8, sizeof(uint8), 128*128, in);
            m_gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 255;
            m_gridGetHeight = &GridMap::getHeightFromUint8;
        }
        else
        {
            m_V9 = new float [129*129];
            m_V8 = new float [128*128];
            fread(m_V9, sizeof(float), 129*129, in);
            fread(m_V8, sizeof(float), 128*128, in);
            m_gridGetHeight = &GridMap::getHeightFromFloat;
        }
    }
    else
        m_gridGetHeight = &GridMap::getHeightFromFlat;
    return true;
}

bool  GridMap::loadLiquidData(FILE *in, uint32 offset, uint32 /*size*/)
{
    map_liquidHeader header;
    fseek(in, offset, SEEK_SET);
    fread(&header, sizeof(header), 1, in);
    if (header.fourcc != uint32(MAP_LIQUID_MAGIC))
        return false;

    m_liquidType   = header.liquidType;
    m_liquid_offX  = header.offsetX;
    m_liquid_offY  = header.offsetY;
    m_liquid_width = header.width;
    m_liquid_height= header.height;
    m_liquidLevel  = header.liquidLevel;

    if (!(header.flags & MAP_LIQUID_NO_TYPE))
    {
        m_liquid_type = new uint8 [16*16];
        fread(m_liquid_type, sizeof(uint8), 16*16, in);
    }
    if (!(header.flags & MAP_LIQUID_NO_HEIGHT))
    {
        m_liquid_map = new float [m_liquid_width*m_liquid_height];
        fread(m_liquid_map, sizeof(float), m_liquid_width*m_liquid_height, in);
    }
    return true;
}

uint16 GridMap::getArea(float x, float y)
{
    if (!m_area_map)
        return m_gridArea;

    x = 16 * (32 - x/SIZE_OF_GRIDS);
    y = 16 * (32 - y/SIZE_OF_GRIDS);
    int lx = (int)x & 15;
    int ly = (int)y & 15;
    return m_area_map[lx*16 + ly];
}

float  GridMap::getHeightFromFlat(float /*x*/, float /*y*/) const
{
    return m_gridHeight;
}

float  GridMap::getHeightFromFloat(float x, float y) const
{
    if (!m_V8 || !m_V9)
        return m_gridHeight;

    x = MAP_RESOLUTION * (32 - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (32 - y/SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);

    // Height stored as: h5 - its v8 grid, h1-h4 - its v9 grid
    // +--------------> X
    // | h1-------h2     Coordinates is:
    // | | \  1  / |     h1 0,0
    // | |  \   /  |     h2 0,1
    // | | 2  h5 3 |     h3 1,0
    // | |  /   \  |     h4 1,1
    // | | /  4  \ |     h5 1/2,1/2
    // | h3-------h4
    // V Y
    // For find height need
    // 1 - detect triangle
    // 2 - solve linear equation from triangle points
    // Calculate coefficients for solve h = a*x + b*y + c

    float a,b,c;
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

float  GridMap::getHeightFromUint8(float x, float y) const
{
    if (!m_uint8_V8 || !m_uint8_V9)
        return m_gridHeight;

    x = MAP_RESOLUTION * (32 - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (32 - y/SIZE_OF_GRIDS);

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
    return (float)((a * x) + (b * y) + c)*m_gridIntHeightMultiplier + m_gridHeight;
}

float  GridMap::getHeightFromUint16(float x, float y) const
{
    if (!m_uint16_V8 || !m_uint16_V9)
        return m_gridHeight;

    x = MAP_RESOLUTION * (32 - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (32 - y/SIZE_OF_GRIDS);

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
    return (float)((a * x) + (b * y) + c)*m_gridIntHeightMultiplier + m_gridHeight;
}

float  GridMap::getLiquidLevel(float x, float y)
{
    if (!m_liquid_map)
        return m_liquidLevel;

    x = MAP_RESOLUTION * (32 - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (32 - y/SIZE_OF_GRIDS);

    int cx_int = ((int)x & (MAP_RESOLUTION-1)) - m_liquid_offY;
    int cy_int = ((int)y & (MAP_RESOLUTION-1)) - m_liquid_offX;

    if (cx_int < 0 || cx_int >=m_liquid_height)
        return INVALID_HEIGHT;
    if (cy_int < 0 || cy_int >=m_liquid_width)
        return INVALID_HEIGHT;

    return m_liquid_map[cx_int*m_liquid_width + cy_int];
}

uint8  GridMap::getTerrainType(float x, float y)
{
    if (!m_liquid_type)
        return m_liquidType;

    x = 16 * (32 - x/SIZE_OF_GRIDS);
    y = 16 * (32 - y/SIZE_OF_GRIDS);
    int lx = (int)x & 15;
    int ly = (int)y & 15;
    return m_liquid_type[lx*16 + ly];
}

// Get water state on map
inline ZLiquidStatus GridMap::getLiquidStatus(float x, float y, float z, uint8 ReqLiquidType, LiquidData *data)
{
    // Check water type (if no water return)
    if (!m_liquid_type && !m_liquidType)
        return LIQUID_MAP_NO_WATER;

    // Get cell
    float cx = MAP_RESOLUTION * (32 - x/SIZE_OF_GRIDS);
    float cy = MAP_RESOLUTION * (32 - y/SIZE_OF_GRIDS);

    int x_int = (int)cx & (MAP_RESOLUTION-1);
    int y_int = (int)cy & (MAP_RESOLUTION-1);

    // Check water type in cell
    uint8 type = m_liquid_type ? m_liquid_type[(x_int>>3)*16 + (y_int>>3)] : m_liquidType;
    if (type == 0)
        return LIQUID_MAP_NO_WATER;

    // Check req liquid type mask
    if (ReqLiquidType && !(ReqLiquidType&type))
        return LIQUID_MAP_NO_WATER;

    // Check water level:
    // Check water height map
    int lx_int = x_int - m_liquid_offY;
    int ly_int = y_int - m_liquid_offX;
    if (lx_int < 0 || lx_int >=m_liquid_height)
        return LIQUID_MAP_NO_WATER;
    if (ly_int < 0 || ly_int >=m_liquid_width)
        return LIQUID_MAP_NO_WATER;

    // Get water level
    float liquid_level = m_liquid_map ? m_liquid_map[lx_int*m_liquid_width + ly_int] : m_liquidLevel;
    // Get ground level (sub 0.2 for fix some errors)
    float ground_level = getHeight(x, y);

    // Check water level and ground level
    if (liquid_level < ground_level || z < ground_level - 2)
        return LIQUID_MAP_NO_WATER;

    // All ok in water -> store data
    if (data)
    {
        data->type  = type;
        data->level = liquid_level;
        data->depth_level = ground_level;
    }

    // For speed check as int values
    int delta = int((liquid_level - z) * 10);

    // Get position delta
    if (delta > 20)                   // Under water
        return LIQUID_MAP_UNDER_WATER;
    if (delta > 0)                   // In water
        return LIQUID_MAP_IN_WATER;
    if (delta > -1)                   // Walk on water
        return LIQUID_MAP_WATER_WALK;
                                      // Above water
    return LIQUID_MAP_ABOVE_WATER;
}

inline GridMap *Map::GetGrid(float x, float y)
{
    // half opt method
    int gx=(int)(32-x/SIZE_OF_GRIDS);                       //grid x
    int gy=(int)(32-y/SIZE_OF_GRIDS);                       //grid y

    // ensure GridMap is loaded
    EnsureGridCreated(GridPair(63-gx,63-gy));

    return GridMaps[gx][gy];
}

float Map::GetHeight(float x, float y, float z, bool pUseVmaps, float maxSearchDist) const
{
    // find raw .map surface under Z coordinates
    float mapHeight;
    if (GridMap *gmap = const_cast<Map*>(this)->GetGrid(x, y))
    {
        float _mapheight = gmap->getHeight(x,y);

        // look from a bit higher pos to find the floor, ignore under surface case
        if (z + 2.0f > _mapheight)
            mapHeight = _mapheight;
        else
            mapHeight = VMAP_INVALID_HEIGHT_VALUE;
    }
    else
        mapHeight = VMAP_INVALID_HEIGHT_VALUE;

    float vmapHeight;
    if (pUseVmaps)
    {
        VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
        if (vmgr->isHeightCalcEnabled())
        {
            // look from a bit higher pos to find the floor
            vmapHeight = vmgr->getHeight(GetId(), x, y, z + 2.0f, maxSearchDist);
        }
        else
            vmapHeight = VMAP_INVALID_HEIGHT_VALUE;
    }
    else
        vmapHeight = VMAP_INVALID_HEIGHT_VALUE;

    // mapHeight set for any above raw ground Z or <= INVALID_HEIGHT
    // vmapheight set for any under Z value or <= INVALID_HEIGHT

    if (vmapHeight > INVALID_HEIGHT)
    {
        if (mapHeight > INVALID_HEIGHT)
        {
            // we have mapheight and vmapheight and must select more appropriate

            // we are already under the surface or vmap height above map heigt
            // or if the distance of the vmap height is less the land height distance
            if (z < mapHeight || vmapHeight > mapHeight || fabs(mapHeight-z) > fabs(vmapHeight-z))
                return vmapHeight;
            else
                return mapHeight;                           // better use .map surface height

        }
        else
            return vmapHeight;                              // we have only vmapHeight (if have)
    }
    else
    {
        if (!pUseVmaps)
            return mapHeight;                               // explicitly use map data (if have)
        else if (mapHeight > INVALID_HEIGHT && (z < mapHeight + 2 || z == MAX_HEIGHT))
            return mapHeight;                               // explicitly use map data if original z < mapHeight but map found (z+2 > mapHeight)
        else
            return VMAP_INVALID_HEIGHT_VALUE;               // we not have any height
    }
}

inline bool IsOutdoorWMO(uint32 mogpFlags, int32 adtId, int32 rootId, int32 groupId, WMOAreaTableEntry const* wmoEntry, AreaTableEntry const* atEntry)
{
    bool outdoor = true;

    if(wmoEntry && atEntry)
    {
        if(atEntry->flags & AREA_FLAG_OUTSIDE)
            return true;
        if(atEntry->flags & AREA_FLAG_INSIDE)
            return false;
    }

    outdoor = mogpFlags&0x8;

    if(wmoEntry)
    {
        if(wmoEntry->Flags & 4)
            return true;
        if((wmoEntry->Flags & 2)!=0)
            outdoor = false;
    }
    return outdoor;
}

bool Map::IsOutdoors(float x, float y, float z) const
{
    uint32 mogpFlags;
    int32 adtId, rootId, groupId;

    // no wmo found? -> outside by default
    if(!GetAreaInfo(x, y, z, mogpFlags, adtId, rootId, groupId))
        return true;

    AreaTableEntry const* atEntry = 0;
    WMOAreaTableEntry const* wmoEntry= GetWMOAreaTableEntryByTripple(rootId, adtId, groupId);
    if(wmoEntry)
    {
        DEBUG_LOG("Got WMOAreaTableEntry! flag %u, areaid %u", wmoEntry->Flags, wmoEntry->areaId);
        atEntry = GetAreaEntryByAreaID(wmoEntry->areaId);
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
        if(GridMap *gmap = const_cast<Map*>(this)->GetGrid(x, y))
        {
            float _mapheight = gmap->getHeight(x,y);
            // z + 2.0f condition taken from GetHeight(), not sure if it's such a great choice...
            if(z + 2.0f > _mapheight &&  _mapheight > vmap_z)
                return false;
        }
        return true;
    }
    return false;
}

uint16 Map::GetAreaFlag(float x, float y, float z, bool *isOutdoors) const
{
    uint32 mogpFlags;
    int32 adtId, rootId, groupId;
    WMOAreaTableEntry const* wmoEntry = 0;
    AreaTableEntry const* atEntry = 0;
    bool haveAreaInfo = false;

    if (GetAreaInfo(x, y, z, mogpFlags, adtId, rootId, groupId))
    {
        haveAreaInfo = true;
        if (wmoEntry = GetWMOAreaTableEntryByTripple(rootId, adtId, groupId))
            atEntry = GetAreaEntryByAreaID(wmoEntry->areaId);
    }

    uint16 areaflag;

    if (atEntry)
        areaflag = atEntry->exploreFlag;
    else
    {
        if (GridMap *gmap = const_cast<Map*>(this)->GetGrid(x, y))
            areaflag = gmap->getArea(x, y);
        // this used while not all *.map files generated (instances)
        else
            areaflag = GetAreaFlagByMapId(i_mapEntry->MapID);
    }

    if (isOutdoors)
    {
        if (haveAreaInfo)
            *isOutdoors = IsOutdoorWMO(mogpFlags, adtId, rootId, groupId, wmoEntry, atEntry);
        else
            *isOutdoors = true;
    }
    return areaflag;
 }

uint8 Map::GetTerrainType(float x, float y) const
{
    if (GridMap *gmap = const_cast<Map*>(this)->GetGrid(x, y))
        return gmap->getTerrainType(x, y);
    else
        return 0;
}

ZLiquidStatus Map::getLiquidStatus(float x, float y, float z, uint8 ReqLiquidType, LiquidData *data) const
{
    ZLiquidStatus result = LIQUID_MAP_NO_WATER;
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    float liquid_level, ground_level = INVALID_HEIGHT;
    uint32 liquid_type;
    if (vmgr->GetLiquidLevel(GetId(), x, y, z, ReqLiquidType, liquid_level, ground_level, liquid_type))
    {
        sLog.outDebug("getLiquidStatus(): vmap liquid level: %f ground: %f type: %u", liquid_level, ground_level, liquid_type);
        // Check water level and ground level
        if (liquid_level > ground_level && z > ground_level - 2)
        {
            // All ok in water -> store data
            if (data)
            {
                data->type  = liquid_type;
                data->level = liquid_level;
                data->depth_level = ground_level;
            }

            // For speed check as int values
            int delta = int((liquid_level - z) * 10);

            // Get position delta
            if (delta > 20)                   // Under water
                return LIQUID_MAP_UNDER_WATER;
            if (delta > 0 )                   // In water
                return LIQUID_MAP_IN_WATER;
            if (delta > -1)                   // Walk on water
                return LIQUID_MAP_WATER_WALK;
            result = LIQUID_MAP_ABOVE_WATER;
        }
    }

    if(GridMap* gmap = const_cast<Map*>(this)->GetGrid(x, y))
    {
        LiquidData map_data;
        ZLiquidStatus map_result = gmap->getLiquidStatus(x, y, z, ReqLiquidType, &map_data);
        // Not override LIQUID_MAP_ABOVE_WATER with LIQUID_MAP_NO_WATER:
        if (map_result != LIQUID_MAP_NO_WATER && (map_data.level > ground_level))
        {
            if (data)
                *data = map_data;
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

uint32 Map::GetAreaIdByAreaFlag(uint16 areaflag,uint32 map_id)
{
    AreaTableEntry const *entry = GetAreaEntryByAreaFlagAndMap(areaflag,map_id);

    if (entry)
        return entry->ID;
    else
        return 0;
}

uint32 Map::GetZoneIdByAreaFlag(uint16 areaflag,uint32 map_id)
{
    AreaTableEntry const *entry = GetAreaEntryByAreaFlagAndMap(areaflag,map_id);

    if (entry)
        return (entry->zone != 0) ? entry->zone : entry->ID;
    else
        return 0;
}

void Map::GetZoneAndAreaIdByAreaFlag(uint32& zoneid, uint32& areaid, uint16 areaflag,uint32 map_id)
{
    AreaTableEntry const *entry = GetAreaEntryByAreaFlagAndMap(areaflag,map_id);

    areaid = entry ? entry->ID : 0;
    zoneid = entry ? ((entry->zone != 0) ? entry->zone : entry->ID) : 0;
}

bool Map::IsInWater(float x, float y, float pZ, LiquidData *data) const
{
    // Check surface in x, y point for liquid
    if (const_cast<Map*>(this)->GetGrid(x, y))
    {
        LiquidData liquid_status;
        LiquidData *liquid_ptr = data ? data : &liquid_status;
        if (getLiquidStatus(x, y, pZ, MAP_ALL_LIQUIDS, liquid_ptr))
                return true;
    }
    return false;
}

bool Map::IsUnderWater(float x, float y, float z) const
{
    if (const_cast<Map*>(this)->GetGrid(x, y))
    {
        if (getLiquidStatus(x, y, z, MAP_LIQUID_TYPE_WATER|MAP_LIQUID_TYPE_OCEAN)&LIQUID_MAP_UNDER_WATER)
            return true;
    }
    return false;
}

bool Map::CheckGridIntegrity(Creature* c, bool moved) const
{
    Cell const& cur_cell = c->GetCurrentCell();

    CellPair xy_val = Trinity::ComputeCellPair(c->GetPositionX(), c->GetPositionY());
    Cell xy_cell(xy_val);
    if (xy_cell != cur_cell)
    {
        sLog.outDebug("Creature (GUID: %u) X: %f Y: %f (%s) is in grid[%u,%u]cell[%u,%u] instead of grid[%u,%u]cell[%u,%u]",
            c->GetGUIDLow(),
            c->GetPositionX(),c->GetPositionY(),(moved ? "final" : "original"),
            cur_cell.GridX(), cur_cell.GridY(), cur_cell.CellX(), cur_cell.CellY(),
            xy_cell.GridX(),  xy_cell.GridY(),  xy_cell.CellX(),  xy_cell.CellY());
        return true;                                        // not crash at error, just output error in debug mode
    }

    return true;
}

const char* Map::GetMapName() const
{
    return i_mapEntry ? i_mapEntry->name[sWorld.GetDefaultDbcLocale()] : "UNNAMEDMAP\x0";
}

void Map::UpdateObjectVisibility(WorldObject* obj, Cell cell, CellPair cellpair)
{
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();
    Trinity::VisibleChangesNotifier notifier(*obj);
    TypeContainerVisitor<Trinity::VisibleChangesNotifier, WorldTypeMapContainer > player_notifier(notifier);
    cell.Visit(cellpair, player_notifier, *this, *obj, GetVisibilityDistance());
}

void Map::UpdateObjectsVisibilityFor(Player* player, Cell cell, CellPair cellpair)
{
    Trinity::VisibleNotifier notifier(*player);

    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();
    TypeContainerVisitor<Trinity::VisibleNotifier, WorldTypeMapContainer > world_notifier(notifier);
    TypeContainerVisitor<Trinity::VisibleNotifier, GridTypeMapContainer  > grid_notifier(notifier);
    cell.Visit(cellpair, world_notifier, *this, *player, GetVisibilityDistance());
    cell.Visit(cellpair, grid_notifier,  *this, *player, GetVisibilityDistance());

    // send data
    notifier.SendToSelf();
}
/*
void Map::PlayerRelocationNotify(Player* player, Cell cell, CellPair cellpair)
{
    Trinity::PlayerRelocationNotifier relocationNotifier(*player);
    cell.data.Part.reserved = ALL_DISTRICT;

    TypeContainerVisitor<Trinity::PlayerRelocationNotifier, GridTypeMapContainer >  p2grid_relocation(relocationNotifier);
    TypeContainerVisitor<Trinity::PlayerRelocationNotifier, WorldTypeMapContainer > p2world_relocation(relocationNotifier);

    cell.Visit(cellpair, p2grid_relocation, *this, *player, MAX_CREATURE_ATTACK_RADIUS);
    cell.Visit(cellpair, p2world_relocation, *this, *player, MAX_CREATURE_ATTACK_RADIUS);
}

void Map::CreatureRelocationNotify(Creature *creature, Cell cell, CellPair cellpair)
{
    Trinity::CreatureRelocationNotifier relocationNotifier(*creature);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();                                     // not trigger load unloaded grids at notifier call

    TypeContainerVisitor<Trinity::CreatureRelocationNotifier, WorldTypeMapContainer > c2world_relocation(relocationNotifier);
    TypeContainerVisitor<Trinity::CreatureRelocationNotifier, GridTypeMapContainer >  c2grid_relocation(relocationNotifier);

    cell.Visit(cellpair, c2world_relocation, *this, *creature, MAX_CREATURE_ATTACK_RADIUS);
    cell.Visit(cellpair, c2grid_relocation, *this, *creature, MAX_CREATURE_ATTACK_RADIUS);
}
*/

void Map::SendInitSelf(Player * player)
{
    sLog.outDetail("Creating player data for himself %u", player->GetGUIDLow());

    UpdateData data;

    // attach to player data current transport data
    if (Transport* transport = player->GetTransport())
    {
        transport->BuildCreateUpdateBlockForPlayer(&data, player);
    }

    // build data for self presence in world at own client (one time for map)
    player->BuildCreateUpdateBlockForPlayer(&data, player);

    // build other passengers at transport also (they always visible and marked as visible and will not send at visibility update at add to map
    if (Transport* transport = player->GetTransport())
    {
        for (Transport::PlayerSet::const_iterator itr = transport->GetPassengers().begin(); itr != transport->GetPassengers().end(); ++itr)
        {
            if (player != (*itr) && player->HaveAtClient(*itr))
            {
                (*itr)->BuildCreateUpdateBlockForPlayer(&data, player);
            }
        }
    }

    WorldPacket packet;
    data.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

void Map::SendInitTransports(Player * player)
{
    // Hack to send out transports
    MapManager::TransportMap& tmap = sMapMgr.m_TransportsByMap;

    // no transports at map
    if (tmap.find(player->GetMapId()) == tmap.end())
        return;

    UpdateData transData;

    MapManager::TransportSet& tset = tmap[player->GetMapId()];

    for (MapManager::TransportSet::const_iterator i = tset.begin(); i != tset.end(); ++i)
    {
        // send data for current transport in other place
        if ((*i) != player->GetTransport() && (*i)->GetMapId() == GetId())
        {
            (*i)->BuildCreateUpdateBlockForPlayer(&transData, player);
        }
    }

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

void Map::SendRemoveTransports(Player * player)
{
    // Hack to send out transports
    MapManager::TransportMap& tmap = sMapMgr.m_TransportsByMap;

    // no transports at map
    if (tmap.find(player->GetMapId()) == tmap.end())
        return;

    UpdateData transData;

    MapManager::TransportSet& tset = tmap[player->GetMapId()];

    // except used transport
    for (MapManager::TransportSet::const_iterator i = tset.begin(); i != tset.end(); ++i)
        if ((*i) != player->GetTransport() && (*i)->GetMapId() != GetId())
            (*i)->BuildOutOfRangeUpdateBlock(&transData);

    WorldPacket packet;
    transData.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

inline void Map::setNGrid(NGridType *grid, uint32 x, uint32 y)
{
    if (x >= MAX_NUMBER_OF_GRIDS || y >= MAX_NUMBER_OF_GRIDS)
    {
        sLog.outError("map::setNGrid() Invalid grid coordinates found: %d, %d!",x,y);
        ASSERT(false);
    }
    i_grids[x][y] = grid;
}

void Map::DelayedUpdate(const uint32 t_diff)
{
    RemoveAllObjectsInRemoveList();

    // Don't unload grids if it's battleground, since we may have manually added GOs,creatures, those doesn't load from DB at grid re-load !
    // This isn't really bother us, since as soon as we have instanced BG-s, the whole map unloads as the BG gets ended
    if (!IsBattleGroundOrArena())
    {
        for (GridRefManager<NGridType>::iterator i = GridRefManager<NGridType>::begin(); i != GridRefManager<NGridType>::end();)
        {
            NGridType *grid = i->getSource();
            GridInfo *info = i->getSource()->getGridInfoRef();
            ++i;                                                // The update might delete the map and we need the next map before the iterator gets invalid
            ASSERT(grid->GetGridState() >= 0 && grid->GetGridState() < MAX_GRID_STATE);
            si_GridStates[grid->GetGridState()]->Update(*this, *grid, *info, grid->getX(), grid->getY(), t_diff);
        }
    }
}

void Map::AddObjectToRemoveList(WorldObject *obj)
{
    ASSERT(obj->GetMapId() == GetId() && obj->GetInstanceId() == GetInstanceId());

    obj->CleanupsBeforeDelete(false);                            // remove or simplify at least cross referenced links

    i_objectsToRemove.insert(obj);
    //sLog.outDebug("Object (GUID: %u TypeId: %u) added to removing list.",obj->GetGUIDLow(),obj->GetTypeId());
}

void Map::AddObjectToSwitchList(WorldObject *obj, bool on)
{
    ASSERT(obj->GetMapId() == GetId() && obj->GetInstanceId() == GetInstanceId());

    std::map<WorldObject*, bool>::iterator itr = i_objectsToSwitch.find(obj);
    if (itr == i_objectsToSwitch.end())
        i_objectsToSwitch.insert(itr, std::make_pair(obj, on));
    else if (itr->second != on)
        i_objectsToSwitch.erase(itr);
    else
        ASSERT(false);
}

void Map::RemoveAllObjectsInRemoveList()
{
    while (!i_objectsToSwitch.empty())
    {
        std::map<WorldObject*, bool>::iterator itr = i_objectsToSwitch.begin();
        WorldObject *obj = itr->first;
        bool on = itr->second;
        i_objectsToSwitch.erase(itr);

        switch(obj->GetTypeId())
        {
        case TYPEID_UNIT:
            if (!obj->ToCreature()->isPet())
                SwitchGridContainers(obj->ToCreature(), on);
            break;
        }
    }

    //sLog.outDebug("Object remover 1 check.");
    while (!i_objectsToRemove.empty())
    {
        std::set<WorldObject*>::iterator itr = i_objectsToRemove.begin();
        WorldObject* obj = *itr;

        switch(obj->GetTypeId())
        {
            case TYPEID_CORPSE:
            {
                Corpse* corpse = sObjectAccessor.GetCorpse(*obj, obj->GetGUID());
                if (!corpse)
                    sLog.outError("Tried to delete corpse/bones %u that is not in map.", obj->GetGUIDLow());
                else
                    Remove(corpse,true);
                break;
            }
        case TYPEID_DYNAMICOBJECT:
            Remove((DynamicObject*)obj,true);
            break;
        case TYPEID_GAMEOBJECT:
            Remove((GameObject*)obj,true);
            break;
        case TYPEID_UNIT:
            // in case triggered sequence some spell can continue casting after prev CleanupsBeforeDelete call
            // make sure that like sources auras/etc removed before destructor start
            obj->ToCreature()->CleanupsBeforeDelete();
            Remove(obj->ToCreature(),true);
            break;
        default:
            sLog.outError("Non-grid object (TypeId: %u) is in grid object remove list, ignored.",obj->GetTypeId());
            break;
        }

        i_objectsToRemove.erase(itr);
    }

    //sLog.outDebug("Object remover 2 check.");
}

uint32 Map::GetPlayersCountExceptGMs() const
{
    uint32 count = 0;
    for (MapRefManager::const_iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (!itr->getSource()->isGameMaster())
            ++count;
    return count;
}

void Map::SendToPlayers(WorldPacket const* data) const
{
    for (MapRefManager::const_iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        itr->getSource()->GetSession()->SendPacket(data);
}

bool Map::ActiveObjectsNearGrid(uint32 x, uint32 y) const
{
    ASSERT(x < MAX_NUMBER_OF_GRIDS);
    ASSERT(y < MAX_NUMBER_OF_GRIDS);

    CellPair cell_min(x*MAX_NUMBER_OF_CELLS, y*MAX_NUMBER_OF_CELLS);
    CellPair cell_max(cell_min.x_coord + MAX_NUMBER_OF_CELLS, cell_min.y_coord+MAX_NUMBER_OF_CELLS);

    //we must find visible range in cells so we unload only non-visible cells...
    float viewDist = GetVisibilityDistance();
    int cell_range = (int)ceilf(viewDist / SIZE_OF_GRID_CELL) + 1;

    cell_min << cell_range;
    cell_min -= cell_range;
    cell_max >> cell_range;
    cell_max += cell_range;

    for (MapRefManager::const_iterator iter = m_mapRefManager.begin(); iter != m_mapRefManager.end(); ++iter)
    {
        Player* plr = iter->getSource();

        CellPair p = Trinity::ComputeCellPair(plr->GetPositionX(), plr->GetPositionY());
        if ((cell_min.x_coord <= p.x_coord && p.x_coord <= cell_max.x_coord) &&
            (cell_min.y_coord <= p.y_coord && p.y_coord <= cell_max.y_coord))
            return true;
    }

    for (ActiveNonPlayers::const_iterator iter = m_activeNonPlayers.begin(); iter != m_activeNonPlayers.end(); ++iter)
    {
        WorldObject* obj = *iter;

        CellPair p = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
        if ((cell_min.x_coord <= p.x_coord && p.x_coord <= cell_max.x_coord) &&
            (cell_min.y_coord <= p.y_coord && p.y_coord <= cell_max.y_coord))
            return true;
    }

    return false;
}

void Map::AddToActive(Creature* c)
{
    AddToActiveHelper(c);

    // also not allow unloading spawn grid to prevent creating creature clone at load
    if (!c->isPet() && c->GetDBTableGUIDLow())
    {
        float x,y,z;
        c->GetRespawnCoord(x,y,z);
        GridPair p = Trinity::ComputeGridPair(x, y);
        if (getNGrid(p.x_coord, p.y_coord))
            getNGrid(p.x_coord, p.y_coord)->incUnloadActiveLock();
        else
        {
            GridPair p2 = Trinity::ComputeGridPair(c->GetPositionX(), c->GetPositionY());
            sLog.outError("Active creature (GUID: %u Entry: %u) added to grid[%u,%u] but spawn grid[%u,%u] was not loaded.",
                c->GetGUIDLow(), c->GetEntry(), p.x_coord, p.y_coord, p2.x_coord, p2.y_coord);
        }
    }
}

void Map::RemoveFromActive(Creature* c)
{
    RemoveFromActiveHelper(c);

    // also allow unloading spawn grid
    if (!c->isPet() && c->GetDBTableGUIDLow())
    {
        float x,y,z;
        c->GetRespawnCoord(x,y,z);
        GridPair p = Trinity::ComputeGridPair(x, y);
        if (getNGrid(p.x_coord, p.y_coord))
            getNGrid(p.x_coord, p.y_coord)->decUnloadActiveLock();
        else
        {
            GridPair p2 = Trinity::ComputeGridPair(c->GetPositionX(), c->GetPositionY());
            sLog.outError("Active creature (GUID: %u Entry: %u) removed from grid[%u,%u] but spawn grid[%u,%u] was not loaded.",
                c->GetGUIDLow(), c->GetEntry(), p.x_coord, p.y_coord, p2.x_coord, p2.y_coord);
        }
    }
}

template void Map::Add(Corpse *);
template void Map::Add(Creature *);
template void Map::Add(GameObject *);
template void Map::Add(DynamicObject *);

template void Map::Remove(Corpse *,bool);
template void Map::Remove(Creature *,bool);
template void Map::Remove(GameObject *, bool);
template void Map::Remove(DynamicObject *, bool);

/* ******* Dungeon Instance Maps ******* */

InstanceMap::InstanceMap(uint32 id, time_t expiry, uint32 InstanceId, uint8 SpawnMode, Map* _parent)
  : Map(id, expiry, InstanceId, SpawnMode, _parent),
    m_resetAfterUnload(false), m_unloadWhenEmpty(false),
    i_data(NULL), i_script_id(0)
{
    //lets initialize visibility distance for dungeons
    InstanceMap::InitVisibilityDistance();

    // the timer is started by default, and stopped when the first player joins
    // this make sure it gets unloaded if for some reason no player joins
    m_unloadTimer = std::max(sWorld.getConfig(CONFIG_INSTANCE_UNLOAD_DELAY), (uint32)MIN_UNLOAD_DELAY);
}

InstanceMap::~InstanceMap()
{
    delete i_data;
    i_data = NULL;
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
bool InstanceMap::CanEnter(Player *player)
{
    if (player->GetMapRef().getTarget() == this)
    {
        sLog.outError("InstanceMap::CanEnter - player %s(%u) already in map %d,%d,%d!", player->GetName(), player->GetGUIDLow(), GetId(), GetInstanceId(), GetSpawnMode());
        ASSERT(false);
        return false;
    }

    // allow GM's to enter
    if (player->isGameMaster())
        return Map::CanEnter(player);

    // cannot enter if the instance is full (player cap), GMs don't count
    uint32 maxPlayers = GetMaxPlayers();
    if (GetPlayersCountExceptGMs() >= maxPlayers)
    {
        sLog.outDetail("MAP: Instance '%u' of map '%s' cannot have more than '%u' players. Player '%s' rejected", GetInstanceId(), GetMapName(), maxPlayers, player->GetName());
        player->SendTransferAborted(GetId(), TRANSFER_ABORT_MAX_PLAYERS);
        return false;
    }

    // cannot enter while an encounter is in progress on raids
    /*Group *pGroup = player->GetGroup();
    if (!player->isGameMaster() && pGroup && pGroup->InCombatToInstance(GetInstanceId()) && player->GetMapId() != GetId())*/
    if (IsRaid() && GetInstanceData() && GetInstanceData()->IsEncounterInProgress())
    {
        player->SendTransferAborted(GetId(), TRANSFER_ABORT_ZONE_IN_COMBAT);
        return false;
    }

    // cannot enter if instance is in use by another party/soloer that have a
    // permanent save in the same instance id

    PlayerList const &playerList = GetPlayers();
    Player *firstInsidePlayer = NULL;

    if (!playerList.isEmpty())
        for (PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
            if (Player *iPlayer = i->getSource())
            {
                if (iPlayer->isGameMaster()) // bypass GMs
                    continue;
                if (!player->GetGroup()) // player has not group and there is someone inside, deny entry
                {
                    player->SendTransferAborted(GetId(), TRANSFER_ABORT_MAX_PLAYERS);
                    return false;
                }
                // player inside instance has no group or his groups is different to entering player's one, deny entry
                if (!iPlayer->GetGroup() || iPlayer->GetGroup() != player->GetGroup() )
                {
                    player->SendTransferAborted(GetId(), TRANSFER_ABORT_MAX_PLAYERS);
                    return false;
                }
                break;
            }

    return Map::CanEnter(player);
}

/*
    Do map specific checks and add the player to the map if successful.
*/
bool InstanceMap::Add(Player *player)
{
    // TODO: Not sure about checking player level: already done in HandleAreaTriggerOpcode
    // GMs still can teleport player in instance.
    // Is it needed?

    {
        ACE_GUARD_RETURN(ACE_Thread_Mutex, guard, Lock, false);
        // Check moved to void WorldSession::HandleMoveWorldportAckOpcode()
        //if (!CanEnter(player))
            //return false;

        // Dungeon only code
        if (IsDungeon())
        {
            // get or create an instance save for the map
            InstanceSave *mapSave = sInstanceSaveManager.GetInstanceSave(GetInstanceId());
            if (!mapSave)
            {
                sLog.outDetail("InstanceMap::Add: creating instance save for map %d spawnmode %d with instance id %d", GetId(), GetSpawnMode(), GetInstanceId());
                mapSave = sInstanceSaveManager.AddInstanceSave(GetId(), GetInstanceId(), Difficulty(GetSpawnMode()), 0, true);
            }

            // check for existing instance binds
            InstancePlayerBind *playerBind = player->GetBoundInstance(GetId(), Difficulty(GetSpawnMode()));
            if (playerBind && playerBind->perm)
            {
                // cannot enter other instances if bound permanently
                if (playerBind->save != mapSave)
                {
                    sLog.outError("InstanceMap::Add: player %s(%d) is permanently bound to instance %d,%d,%d,%d,%d,%d but he is being put into instance %d,%d,%d,%d,%d,%d", player->GetName(), player->GetGUIDLow(), playerBind->save->GetMapId(), playerBind->save->GetInstanceId(), playerBind->save->GetDifficulty(), playerBind->save->GetPlayerCount(), playerBind->save->GetGroupCount(), playerBind->save->CanReset(), mapSave->GetMapId(), mapSave->GetInstanceId(), mapSave->GetDifficulty(), mapSave->GetPlayerCount(), mapSave->GetGroupCount(), mapSave->CanReset());
                    return false;
                }
            }
            else
            {
                Group *pGroup = player->GetGroup();
                if (pGroup)
                {
                    // solo saves should be reset when entering a group
                    InstanceGroupBind *groupBind = pGroup->GetBoundInstance(this);
                    if (playerBind)
                    {
                        sLog.outError("InstanceMap::Add: player %s(%d) is being put into instance %d,%d,%d,%d,%d,%d but he is in group %d and is bound to instance %d,%d,%d,%d,%d,%d!", player->GetName(), player->GetGUIDLow(), mapSave->GetMapId(), mapSave->GetInstanceId(), mapSave->GetDifficulty(), mapSave->GetPlayerCount(), mapSave->GetGroupCount(), mapSave->CanReset(), GUID_LOPART(pGroup->GetLeaderGUID()), playerBind->save->GetMapId(), playerBind->save->GetInstanceId(), playerBind->save->GetDifficulty(), playerBind->save->GetPlayerCount(), playerBind->save->GetGroupCount(), playerBind->save->CanReset());
                        if (groupBind) sLog.outError("InstanceMap::Add: the group is bound to the instance %d,%d,%d,%d,%d,%d", groupBind->save->GetMapId(), groupBind->save->GetInstanceId(), groupBind->save->GetDifficulty(), groupBind->save->GetPlayerCount(), groupBind->save->GetGroupCount(), groupBind->save->CanReset());
                        //ASSERT(false);
                        return false;
                    }
                    // bind to the group or keep using the group save
                    if (!groupBind)
                        pGroup->BindToInstance(mapSave, false);
                    else
                    {
                        // cannot jump to a different instance without resetting it
                        if (groupBind->save != mapSave)
                        {
                            sLog.outError("InstanceMap::Add: player %s(%d) is being put into instance %d,%d,%d but he is in group %d which is bound to instance %d,%d,%d!", player->GetName(), player->GetGUIDLow(), mapSave->GetMapId(), mapSave->GetInstanceId(), mapSave->GetDifficulty(), GUID_LOPART(pGroup->GetLeaderGUID()), groupBind->save->GetMapId(), groupBind->save->GetInstanceId(), groupBind->save->GetDifficulty());
                            if (mapSave)
                                sLog.outError("MapSave players: %d, group count: %d", mapSave->GetPlayerCount(), mapSave->GetGroupCount());
                            else
                                sLog.outError("MapSave NULL");
                            if (groupBind->save)
                                sLog.outError("GroupBind save players: %d, group count: %d", groupBind->save->GetPlayerCount(), groupBind->save->GetGroupCount());
                            else
                                sLog.outError("GroupBind save NULL");
                            return false;
                        }
                        // if the group/leader is permanently bound to the instance
                        // players also become permanently bound when they enter
                        if (groupBind->perm)
                        {
                            WorldPacket data(SMSG_INSTANCE_SAVE_CREATED, 4);
                            data << uint32(0);
                            player->GetSession()->SendPacket(&data);
                            player->BindToInstance(mapSave, true);
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

        sLog.outDetail("MAP: Player '%s' entered instance '%u' of map '%s'", player->GetName(), GetInstanceId(), GetMapName());
        // initialize unload state
        m_unloadTimer = 0;
        m_resetAfterUnload = false;
        m_unloadWhenEmpty = false;
    }

    // this will acquire the same mutex so it cannot be in the previous block
    Map::Add(player);

    if (i_data)
        i_data->OnPlayerEnter(player);

    return true;
}

void InstanceMap::Update(const uint32& t_diff)
{
    Map::Update(t_diff);

    if (i_data)
        i_data->Update(t_diff);
}

void InstanceMap::Remove(Player *player, bool remove)
{
    sLog.outDetail("MAP: Removing player '%s' from instance '%u' of map '%s' before relocating to another map", player->GetName(), GetInstanceId(), GetMapName());
    //if last player set unload timer
    if (!m_unloadTimer && m_mapRefManager.getSize() == 1)
        m_unloadTimer = m_unloadWhenEmpty ? MIN_UNLOAD_DELAY : std::max(sWorld.getConfig(CONFIG_INSTANCE_UNLOAD_DELAY), (uint32)MIN_UNLOAD_DELAY);
    Map::Remove(player, remove);
    // for normal instances schedule the reset after all players have left
    SetResetSchedule(true);
}

void InstanceMap::CreateInstanceData(bool load)
{
    if (i_data != NULL)
        return;

    InstanceTemplate const* mInstance = objmgr.GetInstanceTemplate(GetId());
    if (mInstance)
    {
        i_script_id = mInstance->script_id;
        i_data = sScriptMgr.CreateInstanceData(this);
    }

    if (!i_data)
        return;

    i_data->Initialize();

    if (load)
    {
        // TODO: make a global storage for this
        QueryResult_AutoPtr result = CharacterDatabase.PQuery("SELECT data FROM instance WHERE map = '%u' AND id = '%u'", GetId(), i_InstanceId);
        if (result)
        {
            Field* fields = result->Fetch();
            std::string data = fields[0].GetString();
            if (data != "")
            {
                sLog.outDebug("Loading instance data for `%s` with id %u", objmgr.GetScriptName(i_script_id), i_InstanceId);
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
        if (method == INSTANCE_RESET_ALL)
        {
            // notify the players to leave the instance so it can be reset
            for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
                itr->getSource()->SendResetFailedNotify(GetId());
        }
        else
        {
            if (method == INSTANCE_RESET_GLOBAL)
                // set the homebind timer for players inside (1 minute)
                for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
                    itr->getSource()->m_InstanceValid = false;

            // the unload timer is not started
            // instead the map will unload immediately after the players have left
            m_unloadWhenEmpty = true;
            m_resetAfterUnload = true;
        }
    }
    else
    {
        // unloaded at next update
        m_unloadTimer = MIN_UNLOAD_DELAY;
        m_resetAfterUnload = true;
    }

    return m_mapRefManager.isEmpty();
}

void InstanceMap::PermBindAllPlayers(Player *player)
{
    if (!IsDungeon())
        return;

    InstanceSave *save = sInstanceSaveManager.GetInstanceSave(GetInstanceId());
    if (!save)
    {
        sLog.outError("Cannot bind players, no instance save available for map!");
        return;
    }

    Group *group = player->GetGroup();
    // group members outside the instance group don't get bound
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
    {
        Player* plr = itr->getSource();
        // players inside an instance cannot be bound to other instances
        // some players may already be permanently bound, in this case nothing happens
        InstancePlayerBind *bind = plr->GetBoundInstance(save->GetMapId(), save->GetDifficulty());
        if (!bind || !bind->perm)
        {
            plr->BindToInstance(save, true);
            WorldPacket data(SMSG_INSTANCE_SAVE_CREATED, 4);
            data << uint32(0);
            plr->GetSession()->SendPacket(&data);
        }

        // if the leader is not in the instance the group will not get a perm bind
        if (group && group->GetLeaderGUID() == plr->GetGUID())
            group->BindToInstance(save, true);
    }
}

void InstanceMap::UnloadAll()
{
    ASSERT(!HavePlayers());

    if (m_resetAfterUnload == true)
        objmgr.DeleteRespawnTimeForInstance(GetInstanceId());

    Map::UnloadAll();
}

void InstanceMap::SendResetWarnings(uint32 timeLeft) const
{
    for (MapRefManager::const_iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        itr->getSource()->SendInstanceResetWarning(GetId(), itr->getSource()->GetDifficulty(IsRaid()), timeLeft);
}

void InstanceMap::SetResetSchedule(bool on)
{
    // only for normal instances
    // the reset time is only scheduled when there are no payers inside
    // it is assumed that the reset time will rarely (if ever) change while the reset is scheduled
    if (IsDungeon() && !HavePlayers() && !IsRaidOrHeroicDungeon())
    {
        InstanceSave *save = sInstanceSaveManager.GetInstanceSave(GetInstanceId());
        if (!save) sLog.outError("InstanceMap::SetResetSchedule: cannot turn schedule %s, no save available for instance %d of %d", on ? "on" : "off", GetInstanceId(), GetId());
        else sInstanceSaveManager.ScheduleReset(on, save->GetResetTime(), InstanceSaveManager::InstResetEvent(0, GetId(), Difficulty(GetSpawnMode()), GetInstanceId()));
    }
}

MapDifficulty const* Map::GetMapDifficulty() const
{
    return GetMapDifficultyData(GetId(),GetDifficulty());
}

uint32 InstanceMap::GetMaxPlayers() const
{
    if (MapDifficulty const* mapDiff = GetMapDifficulty())
    {
        if (mapDiff->maxPlayers || IsRegularDifficulty())    // Normal case (expect that regular difficulty always have correct maxplayers)
            return mapDiff->maxPlayers;
        else                                                // DBC have 0 maxplayers for heroic instances with expansion < 2
        {                                                   // The heroic entry exists, so we don't have to check anything, simply return normal max players
            MapDifficulty const* normalDiff = GetMapDifficultyData(GetId(), REGULAR_DIFFICULTY);
            return normalDiff ? normalDiff->maxPlayers : 0;
        }
    }
    else                                                    // I'd rather ASSERT(false);
        return 0;
}

uint32 InstanceMap::GetMaxResetDelay() const
{
    MapDifficulty const* mapDiff = GetMapDifficulty();
    return mapDiff ? mapDiff->resetTime : 0;
}

/* ******* Battleground Instance Maps ******* */

BattleGroundMap::BattleGroundMap(uint32 id, time_t expiry, uint32 InstanceId, Map* _parent, uint8 spawnMode)
  : Map(id, expiry, InstanceId, spawnMode, _parent)
{
    //lets initialize visibility distance for BG/Arenas
    BattleGroundMap::InitVisibilityDistance();
}

BattleGroundMap::~BattleGroundMap()
{
}

void BattleGroundMap::InitVisibilityDistance()
{
    //init visibility distance for BG/Arenas
    m_VisibleDistance = World::GetMaxVisibleDistanceInBGArenas();
    m_VisibilityNotifyPeriod = World::GetVisibilityNotifyPeriodInBGArenas();
}

bool BattleGroundMap::CanEnter(Player * player)
{
    if (player->GetMapRef().getTarget() == this)
    {
        sLog.outError("BGMap::CanEnter - player %u is already in map!", player->GetGUIDLow());
        ASSERT(false);
        return false;
    }

    if (player->GetBattleGroundId() != GetInstanceId())
        return false;

    // player number limit is checked in bgmgr, no need to do it here

    return Map::CanEnter(player);
}

bool BattleGroundMap::Add(Player * player)
{
    {
        ACE_GUARD_RETURN(ACE_Thread_Mutex, guard, Lock, false);
        //Check moved to void WorldSession::HandleMoveWorldportAckOpcode()
        //if (!CanEnter(player))
            //return false;
        // reset instance validity, battleground maps do not homebind
        player->m_InstanceValid = true;
    }
    return Map::Add(player);
}

void BattleGroundMap::Remove(Player *player, bool remove)
{
    sLog.outDetail("MAP: Removing player '%s' from bg '%u' of map '%s' before relocating to another map", player->GetName(), GetInstanceId(), GetMapName());
    Map::Remove(player, remove);
}

void BattleGroundMap::SetUnload()
{
    m_unloadTimer = MIN_UNLOAD_DELAY;
}

void BattleGroundMap::RemoveAllPlayers()
{
    if (HavePlayers())
        for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
            if (Player* plr = itr->getSource())
                if (!plr->IsBeingTeleportedFar())
                    plr->TeleportTo(plr->GetBattleGroundEntryPoint());

}

/// Put scripts in the execution queue
void Map::ScriptsStart(ScriptMapMap const& scripts, uint32 id, Object* source, Object* target)
{
    ///- Find the script map
    ScriptMapMap::const_iterator s = scripts.find(id);
    if (s == scripts.end())
        return;

    // prepare static data
    uint64 sourceGUID = source ? source->GetGUID() : (uint64)0; //some script commands doesn't have source
    uint64 targetGUID = target ? target->GetGUID() : (uint64)0;
    uint64 ownerGUID  = (source->GetTypeId() == TYPEID_ITEM) ? ((Item*)source)->GetOwnerGUID() : (uint64)0;

    ///- Schedule script execution for all scripts in the script map
    ScriptMap const *s2 = &(s->second);
    bool immedScript = false;
    for (ScriptMap::const_iterator iter = s2->begin(); iter != s2->end(); ++iter)
    {
        ScriptAction sa;
        sa.sourceGUID = sourceGUID;
        sa.targetGUID = targetGUID;
        sa.ownerGUID  = ownerGUID;

        sa.script = &iter->second;
        m_scriptSchedule.insert(std::pair<time_t, ScriptAction>(time_t(sWorld.GetGameTime() + iter->first), sa));
        if (iter->first == 0)
            immedScript = true;

        sWorld.IncreaseScheduledScriptsCount();
    }
    ///- If one of the effects should be immediate, launch the script execution
    if (/*start &&*/ immedScript && !i_scriptLock)
    {
        i_scriptLock = true;
        ScriptsProcess();
        i_scriptLock = false;
    }
}

void Map::ScriptCommandStart(ScriptInfo const& script, uint32 delay, Object* source, Object* target)
{
    // NOTE: script record _must_ exist until command executed

    // prepare static data
    uint64 sourceGUID = source ? source->GetGUID() : (uint64)0;
    uint64 targetGUID = target ? target->GetGUID() : (uint64)0;
    uint64 ownerGUID  = (source->GetTypeId() == TYPEID_ITEM) ? ((Item*)source)->GetOwnerGUID() : (uint64)0;

    ScriptAction sa;
    sa.sourceGUID = sourceGUID;
    sa.targetGUID = targetGUID;
    sa.ownerGUID  = ownerGUID;

    sa.script = &script;
    m_scriptSchedule.insert(std::pair<time_t, ScriptAction>(time_t(sWorld.GetGameTime() + delay), sa));

    sWorld.IncreaseScheduledScriptsCount();

    ///- If effects should be immediate, launch the script execution
    if (delay == 0 && !i_scriptLock)
    {
        i_scriptLock = true;
        ScriptsProcess();
        i_scriptLock = false;
    }
}

// Helpers for ScriptProcess method.
inline Player* Map::_GetScriptPlayerSourceOrTarget(Object* source, Object* target, uint32 unScriptID, const char *sCommandName) const
{
    Player *pPlayer = NULL;
    if (!source && !target)
        sLog.outError("%s (script id: %u) source and target objects are NULL.", sCommandName, unScriptID);
    else
    {
        // Check target first, then source.
        if (target)
            pPlayer = target->ToPlayer();
        if (!pPlayer && source)
            pPlayer = source->ToPlayer();

        if (!pPlayer)
            sLog.outError("%s (script id: %u) neither source nor target object is player (source: TypeId: %u, Entry: %u, GUID: %u; target: TypeId: %u, Entry: %u, GUID: %u), skipping.", 
                sCommandName, unScriptID,
                source ? source->GetTypeId() : 0, source ? source->GetEntry() : 0, source ? source->GetGUIDLow() : 0, 
                target ? target->GetTypeId() : 0, target ? target->GetEntry() : 0, target ? target->GetGUIDLow() : 0);
    }
    return pPlayer;
}

inline Creature* Map::_GetScriptCreatureSourceOrTarget(Object* source, Object* target, uint32 unScriptID, const char *sCommandName, bool bReverse) const
{
    Creature *pCreature = NULL;
    if (!source && !target)
        sLog.outError("%s (script id: %u) source and target objects are NULL.", sCommandName, unScriptID);
    else
    {
        if (bReverse)
        {
            // Check target first, then source.
            if (target)
                pCreature = target->ToCreature();
            if (!pCreature && source)
                pCreature = source->ToCreature();
        }
        else
        {
            // Check source first, then target.
            if (source)
                pCreature = source->ToCreature();
            if (!pCreature && target)
                pCreature = target->ToCreature();
        }

        if (!pCreature)
            sLog.outError("%s (script id: %u) neither source nor target are creatures (source: TypeId: %u, Entry: %u, GUID: %u; target: TypeId: %u, Entry: %u, GUID: %u), skipping.", 
                sCommandName, unScriptID,
                source ? source->GetTypeId() : 0, source ? source->GetEntry() : 0, source ? source->GetGUIDLow() : 0, 
                target ? target->GetTypeId() : 0, target ? target->GetEntry() : 0, target ? target->GetGUIDLow() : 0);
    }
    return pCreature;
}

inline Unit* Map::_GetScriptUnit(Object* obj, bool isSource, uint32 unScriptID, const char *sCommandName) const
{
    Unit* pUnit = NULL;
    if (!obj)
        sLog.outError("%s (script id: %u) %s object is NULL.", sCommandName, unScriptID, isSource ? "source" : "target");
    else if (!obj->isType(TYPEMASK_UNIT))
        sLog.outError("%s (script id: %u) %s object is not unit (TypeId: %u, Entry: %u, GUID: %u), skipping.",
            sCommandName, unScriptID, isSource ? "source" : "target", obj->GetTypeId(), obj->GetEntry(), obj->GetGUIDLow());
    else
    {
        pUnit = dynamic_cast<Unit*>(obj);
        if (!pUnit)
            sLog.outError("%s (script id: %u) %s object could not be casted to unit.", sCommandName, unScriptID, isSource ? "source" : "target");
    }
    return pUnit;
}

inline Player* Map::_GetScriptPlayer(Object* obj, bool isSource, uint32 unScriptID, const char *sCommandName) const
{
    Player* pPlayer = NULL;
    if (!obj)
        sLog.outError("%s (script id: %u) %s object is NULL.", sCommandName, unScriptID, isSource ? "source" : "target");
    else
    {
        pPlayer = obj->ToPlayer();
        if (!pPlayer)
            sLog.outError("%s (script id: %u) %s object is not a player (TypeId: %u, Entry: %u, GUID: %u).",
                sCommandName, unScriptID, isSource ? "source" : "target", obj->GetTypeId(), obj->GetEntry(), obj->GetGUIDLow());
    }
    return pPlayer;
}

inline Creature* Map::_GetScriptCreature(Object* obj, bool isSource, uint32 unScriptID, const char *sCommandName) const
{
    Creature* pCreature = NULL;
    if (!obj)
        sLog.outError("%s (script id: %u) %s object is NULL.", sCommandName, unScriptID, isSource ? "source" : "target");
    else
    {
        pCreature = obj->ToCreature();
        if (!pCreature)
            sLog.outError("%s (script id: %u) %s object is not a creature (TypeId: %u, Entry: %u, GUID: %u).",
                sCommandName, unScriptID, isSource ? "source" : "target", obj->GetTypeId(), obj->GetEntry(), obj->GetGUIDLow());
    }
    return pCreature;
}

inline WorldObject* Map::_GetScriptWorldObject(Object* obj, bool isSource, uint32 unScriptID, const char *sCommandName) const
{
    WorldObject* pWorldObject = NULL;
    if (!obj)
        sLog.outError("%s (script id: %u) %s object is NULL.", sCommandName, unScriptID, isSource ? "source" : "target");
    else
    {
        pWorldObject = dynamic_cast<WorldObject*>(obj);
        if (!pWorldObject)
            sLog.outError("%s (script id: %u) %s object is not a world object (TypeId: %u, Entry: %u, GUID: %u).",
                sCommandName, unScriptID, isSource ? "source" : "target", obj->GetTypeId(), obj->GetEntry(), obj->GetGUIDLow());
    }
    return pWorldObject;
}

inline void Map::_ScriptProcessDoor(Object* source, Object* target, bool bOpen, uint32 guid, int32 nTimeToToggle, uint32 unScriptID) const
{
    const char* sCommandName = bOpen ? "SCRIPT_COMMAND_OPEN_DOOR" : "SCRIPT_COMMAND_CLOSE_DOOR";
    if (!guid)
        sLog.outError("%s (script id: %u) door guid is not specified.", sCommandName, unScriptID);
    else if (!source)
        sLog.outError("%s (script id: %u) source object is NULL.", sCommandName, unScriptID);
    else if (!source->isType(TYPEMASK_UNIT))
        sLog.outError("%s (script id: %u) source object is not unit (TypeId: %u, Entry: %u, GUID: %u), skipping.",
            sCommandName, unScriptID, source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
    else
    {
        WorldObject* wSource = dynamic_cast <WorldObject*> (source);
        if (!wSource)
            sLog.outError("%s (script id: %u) source object could not be casted to world object (TypeId: %u, Entry: %u, GUID: %u), skipping.",
                sCommandName, unScriptID, source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
        else 
        {
            GameObject *pDoor = _FindGameObject(wSource, guid);
            if (!pDoor)
                sLog.outError("%s (script id: %u) gameobject was not found (guid: %u).", sCommandName, unScriptID, guid);
            else if (pDoor->GetGoType() != GAMEOBJECT_TYPE_DOOR)
                sLog.outError("%s (script id: %u) gameobject is not a door (GoType: %u, Entry: %u, GUID: %u).", 
                    sCommandName, unScriptID, pDoor->GetGoType(), pDoor->GetEntry(), pDoor->GetGUIDLow());
            else if (bOpen == (pDoor->GetGoState() == GO_STATE_READY))
            {
                if (nTimeToToggle < 15)
                    nTimeToToggle = 15;

                pDoor->UseDoorOrButton(nTimeToToggle);

                if (target && target->isType(TYPEMASK_GAMEOBJECT))
                {
                    GameObject* goTarget = dynamic_cast<GameObject*>(target);
                    if (goTarget && goTarget->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
                        goTarget->UseDoorOrButton(nTimeToToggle);
                }
            }
        }
    }
}

inline GameObject* Map::_FindGameObject(WorldObject* pSearchObject, uint32 guid) const
{
    GameObject *pGameObject = NULL;

    CellPair p(Trinity::ComputeCellPair(pSearchObject->GetPositionX(), pSearchObject->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;

    Trinity::GameObjectWithDbGUIDCheck goCheck(*pSearchObject, guid);
    Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck> checker(pSearchObject, pGameObject, goCheck);

    TypeContainerVisitor<Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck>, GridTypeMapContainer > objectChecker(checker);
    cell.Visit(p, objectChecker, *pSearchObject->GetMap());

    return pGameObject;
}

/// Process queued scripts
void Map::ScriptsProcess()
{
    if (m_scriptSchedule.empty())
        return;

    ///- Process overdue queued scripts
    std::multimap<time_t, ScriptAction>::iterator iter = m_scriptSchedule.begin();
    // ok as multimap is a *sorted* associative container
    while (!m_scriptSchedule.empty() && (iter->first <= sWorld.GetGameTime()))
    {
        ScriptAction const& step = iter->second;

        Object* source = NULL;

        if (step.sourceGUID)
        {
            switch (GUID_HIPART(step.sourceGUID))
            {
                case HIGHGUID_ITEM:
                // case HIGHGUID_CONTAINER: == HIGHGUID_ITEM
                {
                    Player* player = HashMapHolder<Player>::Find(step.ownerGUID);
                    if (player)
                        source = player->GetItemByGuid(step.sourceGUID);
                    break;
                }
                case HIGHGUID_UNIT:
                    source = HashMapHolder<Creature>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_PET:
                    source = HashMapHolder<Pet>::Find(step.sourceGUID);
                    break;
                //case HIGHGUID_VEHICLE:
                //    source = HashMapHolder<Vehicle>::Find(step.sourceGUID);
                //    break;
                case HIGHGUID_PLAYER:
                    source = HashMapHolder<Player>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_GAMEOBJECT:
                    source = HashMapHolder<GameObject>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_CORPSE:
                    source = HashMapHolder<Corpse>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_MO_TRANSPORT:
                    for (MapManager::TransportSet::iterator iter = sMapMgr.m_Transports.begin(); iter != sMapMgr.m_Transports.end(); ++iter)
                    {
                        if ((*iter)->GetGUID() == step.sourceGUID)
                        {
                            source = reinterpret_cast<Object*>(*iter);
                            break;
                        }
                    }
                    break;
                default:
                    sLog.outError("*_script source with unsupported high guid value %u",GUID_HIPART(step.sourceGUID));
                    break;
            }
        }

        //if (source && !source->IsInWorld()) source = NULL;

        Object* target = NULL;

        if (step.targetGUID)
        {
            switch (GUID_HIPART(step.targetGUID))
            {
                case HIGHGUID_UNIT:
                    target = HashMapHolder<Creature>::Find(step.targetGUID);
                    break;
                case HIGHGUID_PET:
                    target = HashMapHolder<Pet>::Find(step.targetGUID);
                    break;
                //case HIGHGUID_VEHICLE:
                //    target = HashMapHolder<Vehicle>::Find(step.targetGUID);
                //    break;
                case HIGHGUID_PLAYER:                       // empty GUID case also
                    target = HashMapHolder<Player>::Find(step.targetGUID);
                    break;
                case HIGHGUID_GAMEOBJECT:
                    target = HashMapHolder<GameObject>::Find(step.targetGUID);
                    break;
                case HIGHGUID_CORPSE:
                    target = HashMapHolder<Corpse>::Find(step.targetGUID);
                    break;
                default:
                    sLog.outError("*_script source with unsupported high guid value %u",GUID_HIPART(step.targetGUID));
                    break;
            }
        }

        //if (target && !target->IsInWorld()) target = NULL;

        switch (step.script->command)
        {
            case SCRIPT_COMMAND_TALK:
                // Source or target must be Creature.
                if (Creature *cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_TALK"))
                {
                    if (step.script->datalong > CHAT_TYPE_WHISPER)
                    {
                        sLog.outError("SCRIPT_COMMAND_TALK (script id: %u) invalid chat type (%u) specified, skipping.", step.script->id, step.script->datalong);
                        break;
                    }

                    uint64 targetGUID = target ? target->GetGUID() : 0;
                    switch (step.script->datalong)
                    {
                        case CHAT_TYPE_SAY:
                            cSource->Say(step.script->dataint, LANG_UNIVERSAL, targetGUID);
                            break;
                        case CHAT_TYPE_YELL:
                            cSource->Yell(step.script->dataint, LANG_UNIVERSAL, targetGUID);
                            break;
                        case CHAT_TYPE_TEXT_EMOTE:
                            cSource->TextEmote(step.script->dataint, targetGUID);
                            break;
                        case CHAT_TYPE_BOSS_EMOTE:
                            cSource->MonsterTextEmote(step.script->dataint, targetGUID, true);
                            break;
                        case CHAT_TYPE_WHISPER:
                            if (!targetGUID || !IS_PLAYER_GUID(targetGUID))
                            {
                                sLog.outError("SCRIPT_COMMAND_TALK (script id: %u) attempt to whisper to non-player unit, skipping.", step.script->id);
                                break;
                            }
                            cSource->Whisper(step.script->dataint, targetGUID);
                            break;
                        default:
                            break;                              // must be already checked at load
                    }
                }
                break;

            case SCRIPT_COMMAND_EMOTE:
                // Source or target must be Creature.
                if (Creature *cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_EMOTE"))
                {
                    if (step.script->datalong2)
                        cSource->SetUInt32Value(UNIT_NPC_EMOTESTATE, step.script->datalong);
                    else
                        cSource->HandleEmoteCommand(step.script->datalong);
                }
                break;

            case SCRIPT_COMMAND_FIELD_SET:
                // Source or target must be Creature.
                if (Creature *cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_FIELD_SET"))
                {
                    // Validate field number.
                    if (step.script->datalong <= OBJECT_FIELD_ENTRY || step.script->datalong >= cSource->GetValuesCount())
                        sLog.outError("SCRIPT_COMMAND_FIELD_SET (script id: %u) wrong field %u (max count: %u) in object (TypeId: %u, Entry: %u, GUID: %u) specified, skipping.",
                            step.script->id, step.script->datalong, cSource->GetValuesCount(), cSource->GetTypeId(), cSource->GetEntry(), cSource->GetGUIDLow());
                    else
                        cSource->SetUInt32Value(step.script->datalong, step.script->datalong2);
                }
                break;

            case SCRIPT_COMMAND_MOVE_TO:
                // Source or target must be Creature.
                if (Creature *cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_MOVE_TO"))
                {
                    cSource->SendMonsterMoveWithSpeed(step.script->x, step.script->y, step.script->z, step.script->datalong2);
                    cSource->GetMap()->CreatureRelocation(cSource, step.script->x, step.script->y, step.script->z, 0);
                }
                break;

            case SCRIPT_COMMAND_FLAG_SET:
                // Source or target must be Creature.
                if (Creature *cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_FLAG_SET"))
                {
                    // Validate field number.
                    if (step.script->datalong <= OBJECT_FIELD_ENTRY || step.script->datalong >= cSource->GetValuesCount())
                        sLog.outError("SCRIPT_COMMAND_FLAG_SET (script id: %u) wrong field %u (max count: %u) in object (TypeId: %u, Entry: %u, GUID: %u) specified, skipping.",
                            step.script->id, step.script->datalong, source->GetValuesCount(), source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
                    else
                        cSource->SetFlag(step.script->datalong, step.script->datalong2);
                }
                break;

            case SCRIPT_COMMAND_FLAG_REMOVE:
                // Source or target must be Creature.
                if (Creature *cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_FLAG_REMOVE"))
                {
                    // Validate field number.
                    if (step.script->datalong <= OBJECT_FIELD_ENTRY || step.script->datalong >= cSource->GetValuesCount())
                        sLog.outError("SCRIPT_COMMAND_FLAG_REMOVE (script id: %u) wrong field %u (max count: %u) in object (TypeId: %u, Entry: %u, GUID: %u) specified, skipping.",
                            step.script->id, step.script->datalong, source->GetValuesCount(), source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
                    else
                        cSource->RemoveFlag(step.script->datalong, step.script->datalong2);
                }
                break;

            case SCRIPT_COMMAND_TELEPORT_TO:
                switch (step.script->datalong2)
                {
                    case 0:
                        // Source or target must be Player.
                        if (Player *pSource = _GetScriptPlayerSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_TELEPORT_TO"))
                            pSource->TeleportTo(step.script->datalong, step.script->x, step.script->y, step.script->z, step.script->o);
                        break;
                    case 1:
                        // Source or target must be Creature.
                        if (Creature *cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_TELEPORT_TO", true))
                            cSource->NearTeleportTo(step.script->x, step.script->y, step.script->z, step.script->o);
                        break;
                    default:
                        sLog.outError("SCRIPT_COMMAND_TELEPORT_TO (script id: %u) unknown datalong2 flag (%u), skipping.", 
                            step.script->id, step.script->datalong2);
                }
                break;

            case SCRIPT_COMMAND_KILL_CREDIT:
                // Source or target must be Player.
                if (Player *pSource = _GetScriptPlayerSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_KILL_CREDIT"))
                {
                    if (step.script->datalong2)
                        pSource->RewardPlayerAndGroupAtEvent(step.script->datalong, pSource);
                    else
                        pSource->KilledMonsterCredit(step.script->datalong, 0);
                }
                break;

            case SCRIPT_COMMAND_TEMP_SUMMON_CREATURE:
            {
                // Source must be WorldObject.
                if (WorldObject* pSummoner = _GetScriptWorldObject(source, true, step.script->id, "SCRIPT_COMMAND_TEMP_SUMMON_CREATURE"))
                {
                    if (!step.script->datalong)
                        sLog.outError("SCRIPT_COMMAND_TEMP_SUMMON_CREATURE (script id: %u) creature entry (datalong) is not specified.", 
                            step.script->id);
                    else
                    {
                        float x = step.script->x;
                        float y = step.script->y;
                        float z = step.script->z;
                        float o = step.script->o;

                        if (pSummoner->SummonCreature(step.script->datalong, x, y, z, o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, step.script->datalong2))
                            sLog.outError("SCRIPT_COMMAND_TEMP_SUMMON (script id: %u) creature was not spawned (entry: %u).", 
                                step.script->id, step.script->datalong);
                    }
                }
                break;
            }

            case SCRIPT_COMMAND_RESPAWN_GAMEOBJECT:
                if (!step.script->datalong)
                {
                    sLog.outError("SCRIPT_COMMAND_RESPAWN_GAMEOBJECT (script id: %u) gameobject entry (datalong) is not specified.", step.script->id);
                    break;
                }

                // Source or target must be WorldObject.
                if (WorldObject* pSummoner = _GetScriptWorldObject(source, true, step.script->id, "SCRIPT_COMMAND_RESPAWN_GAMEOBJECT"))
                {
                    GameObject *pGO = _FindGameObject(pSummoner, step.script->datalong);
                    if (!pGO)
                    {
                        sLog.outError("SCRIPT_COMMAND_RESPAWN_GAMEOBJECT (script id: %u) gameobject was not found (guid: %u).", 
                            step.script->id, step.script->datalong);
                        break;
                    }

                    if (pGO->GetGoType() == GAMEOBJECT_TYPE_FISHINGNODE ||
                        pGO->GetGoType() == GAMEOBJECT_TYPE_DOOR        ||
                        pGO->GetGoType() == GAMEOBJECT_TYPE_BUTTON      ||
                        pGO->GetGoType() == GAMEOBJECT_TYPE_TRAP)
                    {
                        sLog.outError("SCRIPT_COMMAND_RESPAWN_GAMEOBJECT (script id: %u) can not be used with gameobject of type %u (guid: %u).", 
                            step.script->id, uint32(pGO->GetGoType()), step.script->datalong);
                        break;
                    }

                    // Check that GO is not spawned
                    if (!pGO->isSpawned())
                    {
                        int32 nTimeToDespawn = step.script->datalong2 < 5 ? 5 : (int32) step.script->datalong2;
                        pGO->SetLootState(GO_READY);
                        pGO->SetRespawnTime(nTimeToDespawn);

                        pGO->GetMap()->Add(pGO);
                    }
                }
                break;

            case SCRIPT_COMMAND_OPEN_DOOR:
                _ScriptProcessDoor(source, target, true, step.script->datalong, (int32) step.script->datalong2, step.script->id);
                break;

            case SCRIPT_COMMAND_CLOSE_DOOR:
                _ScriptProcessDoor(source, target, false, step.script->datalong, (int32) step.script->datalong2, step.script->id);
                break;

            case SCRIPT_COMMAND_QUEST_EXPLORED:
            {
                if (!source)
                {
                    sLog.outError("SCRIPT_COMMAND_QUEST_EXPLORED (script id %u) source object is NULL.", step.script->id);
                    break;
                }
                if (!target)
                {
                    sLog.outError("SCRIPT_COMMAND_QUEST_EXPLORED (script id %u) target object is NULL.", step.script->id);
                    break;
                }

                // when script called for item spell casting then target == (unit or GO) and source is player
                WorldObject* worldObject;
                Player* pTarget = NULL;
                if (pTarget = target->ToPlayer())
                {
                    if (source->GetTypeId() != TYPEID_UNIT && source->GetTypeId() != TYPEID_GAMEOBJECT && source->GetTypeId() != TYPEID_PLAYER)
                    {
                        sLog.outError("SCRIPT_COMMAND_QUEST_EXPLORED (script id %u) source is not unit, gameobject or player (TypeId: %u, Entry: %u, GUID: %u), skipping.",
                            step.script->id, source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
                        break;
                    }
                    worldObject = dynamic_cast<WorldObject*>(source);
                }
                else if (pTarget = source->ToPlayer())
                {
                    if (target->GetTypeId() != TYPEID_UNIT && target->GetTypeId() != TYPEID_GAMEOBJECT && target->GetTypeId() != TYPEID_PLAYER)
                    {
                        sLog.outError("SCRIPT_COMMAND_QUEST_EXPLORED (script id %u) target is not unit, gameobject or player (TypeId: %u, Entry: %u, GUID: %u), skipping.",
                            step.script->id, target->GetTypeId(), target->GetEntry(), target->GetGUIDLow());
                        break;
                    }
                    worldObject =  dynamic_cast<WorldObject*>(target);
                }
                else
                {
                    sLog.outError("SCRIPT_COMMAND_QUEST_EXPLORED (script id %u) neither source nor target is player (source: TypeId: %u, Entry: %u, GUID: %u; target: TypeId: %u, Entry: %u, GUID: %u), skipping.", 
                        step.script->id,
                        source ? source->GetTypeId() : 0, source ? source->GetEntry() : 0, source ? source->GetGUIDLow() : 0, 
                        target ? target->GetTypeId() : 0, target ? target->GetEntry() : 0, target ? target->GetGUIDLow() : 0);
                    break;
                }

                // quest id and flags checked at script loading
                if ((worldObject->GetTypeId() != TYPEID_UNIT || ((Unit*)worldObject)->isAlive()) && 
                    (step.script->datalong2 == 0 || worldObject->IsWithinDistInMap(pTarget, float(step.script->datalong2))))
                    pTarget->AreaExploredOrEventHappens(step.script->datalong);
                else
                    pTarget->FailQuest(step.script->datalong);

                break;
            }

            case SCRIPT_COMMAND_ACTIVATE_OBJECT:
                // Source must be Unit.
                if (Unit *pSource = _GetScriptUnit(source, true, step.script->id, "SCRIPT_COMMAND_ACTIVATE_OBJECT"))
                {
                    // Target must be GameObject.
                    if (!target)
                    {
                        sLog.outError("SCRIPT_COMMAND_ACTIVATE_OBJECT (script id: %u) target object is NULL.", step.script->id);
                        break;
                    }

                    if (target->GetTypeId() != TYPEID_GAMEOBJECT)
                    {
                        sLog.outError("SCRIPT_COMMAND_ACTIVATE_OBJECT (script id: %u) target object is not gameobject (TypeId: %u, Entry: %u, GUID: %u), skipping.",
                            step.script->id, target->GetTypeId(),target->GetEntry(),target->GetGUIDLow());
                        break;
                    }

                    if (GameObject *pGO = dynamic_cast<GameObject*>(target))
                        pGO->Use(pSource);
                }
                break;

            case SCRIPT_COMMAND_REMOVE_AURA:
                // Source (datalong2 != 0) or target (datalong2 == 0) must be Unit.
                if (Unit *pTarget = _GetScriptUnit(step.script->datalong2 ? source : target, step.script->datalong2, step.script->id, "SCRIPT_COMMAND_REMOVE_AURA"))
                    pTarget->RemoveAurasDueToSpell(step.script->datalong);
                break;

            case SCRIPT_COMMAND_CAST_SPELL:
            {
                // TODO: Allow gameobjects to be targets and casters
                if (!source && !target)
                {
                    sLog.outError("SCRIPT_COMMAND_CAST_SPELL (script id: %u) source and target objects are NULL.", step.script->id);
                    break;
                }

                Unit* uSource = NULL;
                Unit* uTarget = NULL;
                // source/target cast spell at target/source (script->datalong2: 0: s->t 1: s->s 2: t->t 3: t->s
                switch (step.script->datalong2)
                {
                    case 0: // source -> target
                        uSource = dynamic_cast<Unit*>(source);
                        uTarget = dynamic_cast<Unit*>(target);
                        break;
                    case 1: // source -> source
                        uSource = dynamic_cast<Unit*>(source);
                        uTarget = uSource;
                        break;
                    case 2: // target -> target
                        uSource = dynamic_cast<Unit*>(target);
                        uTarget = uSource;
                        break;
                    case 3: // target -> source
                        uSource = dynamic_cast<Unit*>(target);
                        uTarget = dynamic_cast<Unit*>(source);
                        break;
                    case 4: // source -> creature with entry
                        uSource = dynamic_cast<Unit*>(source);
                        uTarget = GetClosestCreatureWithEntry(uSource, abs(step.script->dataint), step.script->x);
                        break;
                }

                if (!uSource || !uSource->isType(TYPEMASK_UNIT))
                {
                    sLog.outError("SCRIPT_COMMAND_CAST_SPELL (script id: %u) no source unit found for spell %u", step.script->id, step.script->datalong);
                    break;
                }

                if (!uTarget || !uTarget->isType(TYPEMASK_UNIT))
                {
                    sLog.outError("SCRIPT_COMMAND_CAST_SPELL (script id: %u) no target unit found for spell %u", step.script->id, step.script->datalong);
                    break;
                }

                bool triggered = (step.script->datalong2 != 4) ? step.script->dataint & 0x1 : step.script->dataint < 0;
                uSource->CastSpell(uTarget, step.script->datalong, triggered);
                break;
            }

            case SCRIPT_COMMAND_PLAY_SOUND:
                // Source must be WorldObject.
                if (WorldObject* pSource = _GetScriptWorldObject(source, true, step.script->id, "SCRIPT_COMMAND_PLAY_SOUND"))
                {
                    // datalong2 bitmask: 0/1=anyone/target
                    Player* pTarget = NULL;
                    if (step.script->datalong2 & 1)
                    {
                        // Target must be Player.
                        pTarget = _GetScriptPlayer(target, false, step.script->id, "SCRIPT_COMMAND_PLAY_SOUND");
                        if (!pTarget)
                            break;
                    }

                    // datalong2 bitmask: 0/2=without/with distance dependent
                    if (step.script->datalong2 & 2)
                        pSource->PlayDistanceSound(step.script->datalong, pTarget);
                    else
                        pSource->PlayDirectSound(step.script->datalong, pTarget);
                }
                break;

            case SCRIPT_COMMAND_CREATE_ITEM:
                // Target or source must be Player.
                if (Player* pReceiver = _GetScriptPlayerSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_CREATE_ITEM"))
                {
                    ItemPosCountVec dest;
                    uint8 msg = pReceiver->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, step.script->datalong, step.script->datalong2);
                    if (msg == EQUIP_ERR_OK)
                    {
                        if (Item* item = pReceiver->StoreNewItem(dest, step.script->datalong, true))
                            pReceiver->SendNewItem(item, step.script->datalong2, false, true);
                    }
                    else
                        pReceiver->SendEquipError(msg, NULL, NULL, step.script->datalong);
                }
                break;

            case SCRIPT_COMMAND_DESPAWN_SELF:
                // Target or source must be Creature.
                if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_DESPAWN_SELF", true))
                    cSource->ForcedDespawn(step.script->datalong);
                break;

            case SCRIPT_COMMAND_LOAD_PATH:
                // Source must be Unit.
                if (Unit* pSource = _GetScriptUnit(source, true, step.script->id, "SCRIPT_COMMAND_START_MOVE"))
                {
                    if (!sWaypointMgr->GetPath(step.script->datalong))
                        sLog.outError("SCRIPT_COMMAND_START_MOVE (script id: %u) source object has an invalid path (%u), skipping.", step.script->id, step.script->datalong);
                    else
                        pSource->GetMotionMaster()->MovePath(step.script->datalong, step.script->datalong2);
                }
                break;

            case SCRIPT_COMMAND_CALLSCRIPT_TO_UNIT:
            {
                if (!step.script->datalong)
                {
                    sLog.outError("SCRIPT_COMMAND_CALLSCRIPT (script id: %u) creature entry is not specified, skipping.", step.script->id);
                    break;
                }
                if (!step.script->datalong2)
                {
                    sLog.outError("SCRIPT_COMMAND_CALLSCRIPT (script id: %u) script id is not specified, skipping.", step.script->id);
                    break;
                }

                Creature* cTarget;
                if (source) //using grid searcher
                {
                    WorldObject* wSource = dynamic_cast <WorldObject*> (source);

                    CellPair p(Trinity::ComputeCellPair(wSource->GetPositionX(), wSource->GetPositionY()));
                    Cell cell(p);
                    cell.data.Part.reserved = ALL_DISTRICT;

                    Trinity::CreatureWithDbGUIDCheck target_check(wSource, step.script->datalong);
                    Trinity::CreatureSearcher<Trinity::CreatureWithDbGUIDCheck> checker(wSource, cTarget, target_check);

                    TypeContainerVisitor<Trinity::CreatureSearcher <Trinity::CreatureWithDbGUIDCheck>, GridTypeMapContainer > unit_checker(checker);
                    cell.Visit(p, unit_checker, *wSource->GetMap());
                }
                else //check hashmap holders
                {
                    if (CreatureData const* data = objmgr.GetCreatureData(step.script->datalong))
                        cTarget = ObjectAccessor::GetObjectInWorld<Creature>(data->mapid, data->posX, data->posY, MAKE_NEW_GUID(step.script->datalong, data->id, HIGHGUID_UNIT), cTarget);
                }

                if (!cTarget)
                {
                    sLog.outError("SCRIPT_COMMAND_CALLSCRIPT (script id: %u) target was not found (entry: %u)", step.script->id, step.script->datalong);
                    break;
                }

                //Lets choose our ScriptMap map
                ScriptMapMap *datamap = NULL;
                switch (step.script->dataint)
                {
                    case 1: //QUEST END SCRIPTMAP
                        datamap = &sQuestEndScripts;
                        break;
                    case 2: //QUEST START SCRIPTMAP
                        datamap = &sQuestStartScripts;
                        break;
                    case 3: //SPELLS SCRIPTMAP
                        datamap = &sSpellScripts;
                        break;
                    case 4: //GAMEOBJECTS SCRIPTMAP
                        datamap = &sGameObjectScripts;
                        break;
                    case 5: //EVENTS SCRIPTMAP
                        datamap = &sEventScripts;
                        break;
                    case 6: //WAYPOINTS SCRIPTMAP
                        datamap = &sWaypointScripts;
                        break;
                    default:
                        sLog.outError("SCRIPT_COMMAND_CALLSCRIPT (script id: %u) unknown scriptmap (%u) specified, skipping.", step.script->id, step.script->dataint);
                        break;
                }
                //if no scriptmap present...
                if (!datamap)
                    break;

                // Insert script into schedule but do not start it
                ScriptsStart(*datamap, step.script->datalong2, cTarget, NULL);
                break;
            }

            case SCRIPT_COMMAND_KILL:
                // Source or target must be Creature.
                if (Creature *cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script->id, "SCRIPT_COMMAND_KILL"))
                {
                    if (cSource->isDead())
                        sLog.outError("SCRIPT_COMMAND_KILL (script id: %u) creature is already dead (Entry: %u, GUID: %u)", 
                            step.script->id, cSource->GetEntry(), cSource->GetGUIDLow());
                    else
                    {
                        cSource->setDeathState(JUST_DIED);
                        if (step.script->dataint == 1)
                            cSource->RemoveCorpse();
                    }
                }
                break;

            case SCRIPT_COMMAND_ORIENTATION:
                // Source must be Unit.
                if (Unit *pSource = _GetScriptUnit(source, true, step.script->id, "SCRIPT_COMMAND_ORIENTATION"))
                {
                    if (!step.script->datalong)
                        pSource->SetOrientation(step.script->o);
                    else
                    {
                        // Target must be Unit.
                        Unit* pTarget = _GetScriptUnit(target, false, step.script->id, "SCRIPT_COMMAND_ORIENTATION");
                        if (!pTarget)
                            break;

                        pSource->SetInFront(pTarget);
                    }

                    pSource->SendMovementFlagUpdate();
                }
                break;

            case SCRIPT_COMMAND_EQUIP:
                // Source must be Creature.
                if (Creature *cSource = _GetScriptCreature(source, true, step.script->id, "SCRIPT_COMMAND_EQUIP"))
                    cSource->LoadEquipment(step.script->datalong);
                break;

            case SCRIPT_COMMAND_MODEL:
                // Source must be Creature.
                if (Creature *cSource = _GetScriptCreature(source, true, step.script->id, "SCRIPT_COMMAND_MODEL"))
                    cSource->SetDisplayId(step.script->datalong);
                break;

            case SCRIPT_COMMAND_CLOSE_GOSSIP:
                // Source must be Player.
                if (Player *pSource = _GetScriptPlayer(source, true, step.script->id, "SCRIPT_COMMAND_CLOSE_GOSSIP"))
                    pSource->PlayerTalkClass->CloseGossip();
                break;

            case SCRIPT_COMMAND_PLAYMOVIE:
                // Source must be Player.
                if (Player *pSource = _GetScriptPlayer(source, true, step.script->id, "SCRIPT_COMMAND_PLAYMOVIE"))
                    pSource->SendMovieStart(step.script->datalong);
                break;

            default:
                sLog.outError("Unknown script command %u called.", step.script->command);
                break;
        }

        m_scriptSchedule.erase(iter);
        sWorld.DecreaseScheduledScriptCount();

        iter = m_scriptSchedule.begin();
    }
}

Creature*
Map::GetCreature(uint64 guid)
{
    return ObjectAccessor::GetObjectInMap(guid, this, (Creature*)NULL);
}

GameObject*
Map::GetGameObject(uint64 guid)
{
    return ObjectAccessor::GetObjectInMap(guid, this, (GameObject*)NULL);
}

DynamicObject*
Map::GetDynamicObject(uint64 guid)
{
    return ObjectAccessor::GetObjectInMap(guid, this, (DynamicObject*)NULL);
}

void Map::UpdateIteratorBack(Player *player)
{
    if (m_mapRefIter == player->GetMapRef())
        m_mapRefIter = m_mapRefIter->nocheck_prev();
}
