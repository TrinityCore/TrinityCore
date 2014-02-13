/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#include "LuaEngine.h"
// #include "HookMgr.h"

#if PLATFORM == PLATFORM_UNIX
#include <dirent.h>
#endif

extern void RegisterFunctions(lua_State* L);
extern void AddElunaScripts();

bool StartEluna()
{
#ifndef ELUNA
    {
        TC_LOG_ERROR("server.loading", "[Eluna]: LuaEngine is Disabled. (If you want to use it please enable in cmake)");
        return false;
    }
#endif
    
    ELUNA_GUARD();
    if (sEluna.L)
    {
        sHookMgr.OnEngineRestart();
        TC_LOG_INFO("misc", "[Eluna]: Restarting Lua Engine");

        // Unregisters and stops all timed events
        sEluna.m_EventMgr.RemoveEvents();

        // Remove bindings
        sEluna.PacketEventBindings.Clear();
        sEluna.ServerEventBindings.Clear();
        sEluna.PlayerEventBindings.Clear();
        sEluna.GuildEventBindings.Clear();
        sEluna.GroupEventBindings.Clear();
        sEluna.VehicleEventBindings.Clear();

        sEluna.CreatureEventBindings.Clear();
        sEluna.CreatureGossipBindings.Clear();
        sEluna.GameObjectEventBindings.Clear();
        sEluna.GameObjectGossipBindings.Clear();
        sEluna.ItemEventBindings.Clear();
        sEluna.ItemGossipBindings.Clear();
        sEluna.playerGossipBindings.Clear();

        lua_close(sEluna.L);
    }
    else
        AddElunaScripts();

    sEluna.L = luaL_newstate();
    TC_LOG_INFO("misc", "[Eluna]: Lua Engine loaded.");

    LoadedScripts loadedScripts;
    sEluna.LoadDirectory("lua_scripts", &loadedScripts);
    luaL_openlibs(sEluna.L);
    // Register functions here
    RegisterFunctions(sEluna.L);

    // Randomize math.random()
    luaL_dostring(sEluna.L, "math.randomseed( tonumber(tostring(os.time()):reverse():sub(1,6)) )");

    uint32 count = 0;
    char filename[200];
    for (std::set<std::string>::const_iterator itr = loadedScripts.begin(); itr !=  loadedScripts.end(); ++itr)
    {
        strcpy(filename, itr->c_str());
        if (luaL_loadfile(sEluna.L, filename) != 0)
        {
            TC_LOG_ERROR("server.loading", "[Eluna]: Error loading file `%s`.", itr->c_str());
            sEluna.report(sEluna.L);
        }
        else
        {
            int err = lua_pcall(sEluna.L, 0, 0, 0);
            if (err != 0 && err == LUA_ERRRUN)
            {
                TC_LOG_ERROR("server.loading", "[Eluna]: Error loading file `%s`.", itr->c_str());
                sEluna.report(sEluna.L);
            }
        }
        ++count;
    }

    /*
    if (restart)
    {
        //! Iterate over every supported source type (creature and gameobject)
        //! Not entirely sure how this will affect units in non-loaded grids.
        {
            HashMapHolder<Creature>::ReadGuard g(HashMapHolder<Creature>::GetLock());
            HashMapHolder<Creature>::MapType& m = HashMapHolder<Creature>::GetContainer();
            for (HashMapHolder<Creature>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
            {
                if (itr->second->IsInWorld()) // must check?
                    // if(sEluna.CreatureEventBindings->GetBindMap(iter->second->GetEntry())) // update all AI or just Eluna?
                        itr->second->AIM_Initialize();
            }
        }

        {
            HashMapHolder<GameObject>::ReadGuard g(HashMapHolder<GameObject>::GetLock());
            HashMapHolder<GameObject>::MapType& m = HashMapHolder<GameObject>::GetContainer();
            for (HashMapHolder<GameObject>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
            {
                if (itr->second->IsInWorld()) // must check?
                    // if(sEluna.GameObjectEventBindings->GetBindMap(iter->second->GetEntry())) // update all AI or just Eluna?
                        itr->second->AIM_Initialize();
            }
        }
    }
    */

    TC_LOG_INFO("misc", "[Eluna]: Loaded %u Lua scripts..", count);
    return true;
}

// Loads lua scripts from given directory
void Eluna::LoadDirectory(const char* Dirname, LoadedScripts* lscr)
{
#ifdef WIN32
    HANDLE hFile;
    WIN32_FIND_DATA FindData;
    memset(&FindData, 0, sizeof(FindData));
    char SearchName[MAX_PATH];

    strcpy(SearchName, Dirname);
    strcat(SearchName, "\\*.*");

    hFile = FindFirstFile(SearchName, &FindData);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        TC_LOG_ERROR("server.loading", "[Eluna]: Error No `lua_scripts` directory found! Creating a 'lua_scripts' directory.");
        CreateDirectory("lua_scripts", NULL);
        return;
    }

    FindNextFile(hFile, &FindData);
    while (FindNextFile(hFile, &FindData))
    {
        if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            strcpy(SearchName, Dirname);
            strcat(SearchName, "\\");
            strcat(SearchName, FindData.cFileName);
            LoadDirectory(SearchName, lscr);
        }
        else
        {
            std::string fname = Dirname;
            fname += "\\";
            fname += FindData.cFileName;
            size_t len = strlen(fname.c_str());
            int i = 0;
            char ext[MAX_PATH];
            while (len > 0)
            {
                ext[i++] = fname[--len];
                if (fname[len] == '.')
                    break;
            }
            ext[i++] = '\0';
            if (!_stricmp(ext, "aul."))
            {
                TC_LOG_DEBUG("server.loading", "[Eluna]: Load File: %s", fname.c_str());
                lscr->insert(fname);
            }
        }
    }
    FindClose(hFile);
#else
    const char* dir = strrchr(Dirname, '/');
    if (strcmp(Dirname, "..") == 0 || strcmp(Dirname, ".") == 0)
        return;

    if (dir && (strcmp(dir, "/..") == 0 || strcmp(dir, "/.") == 0 || strcmp(dir, "/.svn") == 0))
        return;

    struct dirent** list;
    int fileCount = scandir(Dirname, &list, 0, 0);

    if (fileCount <= 0 || !list)
        return;

    struct stat attributes;
    bool error;
    while (fileCount--)
    {
        char _path[200];
        sprintf(_path, "%s/%s", Dirname, list[fileCount]->d_name);
        if (stat(_path, &attributes) == -1)
        {
            error = true;
            TC_LOG_ERROR("server.loading", "[Eluna]: Error opening `%s`", _path);
        }
        else
            error = false;

        if (!error && S_ISDIR(attributes.st_mode))
            LoadDirectory(_path, lscr);
        else
        {
            char* ext = strrchr(list[fileCount]->d_name, '.');
            if (ext && !strcmp(ext, ".lua"))
                lscr->insert(_path);
        }
        free(list[fileCount]);
    }
    free(list);
#endif
}

void Eluna::report(lua_State* L)
{
    const char* msg = lua_tostring(L, -1);
    while (msg)
    {
        lua_pop(L, -1);
        printf("\t%s\n",msg);
        msg = lua_tostring(L, -1);
    }
}

void Eluna::BeginCall(int fReference)
{
    lua_settop(L, 0); // stack should be empty
    lua_rawgeti(L, LUA_REGISTRYINDEX, (fReference));
}

bool Eluna::ExecuteCall(int params, int res)
{
    bool ret = true;
    int top = lua_gettop(L);

    if (lua_type(L, top - params) == LUA_TFUNCTION) // is function
    {
        if (lua_pcall(L, params, res, 0))
        {
            report(L);
            ret = false;
        }
    }
    else
    {
        ret = false;
        if (params > 0)
        {
            for (int i = top; i >= (top - params); i--)
            {
                if (!lua_isnone(L, i))
                    lua_remove(L, i);
            }
        }
    }
    return ret;
}

void Eluna::EndCall(int res)
{
    for (int i = res; i > 0; i--)
    {
        if (!lua_isnone(L, res))
            lua_remove(L, res);
    }
}

/* Pushes */
void Eluna::Push(lua_State* L)
{
    lua_pushnil(L);
}

void Eluna::Push(lua_State* L, const uint64 l)
{
    std::ostringstream ss;
    ss << l;
    sEluna.Push(L, ss.str());
}

void Eluna::Push(lua_State* L, const int64 l)
{
    std::ostringstream ss;
    ss << l;
    sEluna.Push(L, ss.str());
}

void Eluna::Push(lua_State* L, const uint32 u)
{
    lua_pushunsigned(L, u);
}

void Eluna::Push(lua_State* L, const int32 i)
{
    lua_pushinteger(L, i);
}

void Eluna::Push(lua_State* L, const double d)
{
    lua_pushnumber(L, d);
}

void Eluna::Push(lua_State* L, const float f)
{
    lua_pushnumber(L, f);
}

void Eluna::Push(lua_State* L, const bool b)
{
    lua_pushboolean(L, b);
}

void Eluna::Push(lua_State* L, const std::string str)
{
    lua_pushstring(L, str.c_str());
}

void Eluna::Push(lua_State* L, const char* str)
{
    lua_pushstring(L, str);
}

Object* Eluna::CHECK_OBJECT(lua_State* L, int narg)
{
    return ElunaTemplate<Object>::check(L, narg);
}

WorldObject* Eluna::CHECK_WORLDOBJECT(lua_State* L, int narg)
{
    return ElunaTemplate<WorldObject>::check(L, narg);
}

Unit* Eluna::CHECK_UNIT(lua_State* L, int narg)
{
    WorldObject* obj = CHECK_WORLDOBJECT(L, narg);
    if (!obj)
        return NULL;
    return obj->ToUnit();
}

Player* Eluna::CHECK_PLAYER(lua_State* L, int narg)
{
    WorldObject* obj = CHECK_WORLDOBJECT(L, narg);
    if (!obj)
        return NULL;
    return obj->ToPlayer();
}

Creature* Eluna::CHECK_CREATURE(lua_State* L, int narg)
{
    WorldObject* obj = CHECK_WORLDOBJECT(L, narg);
    if (!obj)
        return NULL;
    return obj->ToCreature();
}

GameObject* Eluna::CHECK_GAMEOBJECT(lua_State* L, int narg)
{
    WorldObject* obj = CHECK_WORLDOBJECT(L, narg);
    if (!obj)
        return NULL;
    return obj->ToGameObject();
}

Corpse* Eluna::CHECK_CORPSE(lua_State* L, int narg)
{
    WorldObject* obj = CHECK_WORLDOBJECT(L, narg);
    if (!obj)
        return NULL;
    return obj->ToCorpse();
}

Vehicle* Eluna::CHECK_VEHICLE(lua_State* L, int narg)
{
    return ElunaTemplate<Vehicle>::check(L, narg);
}

WorldPacket* Eluna::CHECK_PACKET(lua_State* L, int narg)
{
    return ElunaTemplate<WorldPacket>::check(L, narg);
}

Quest* Eluna::CHECK_QUEST(lua_State* L, int narg)
{
    return ElunaTemplate<Quest>::check(L, narg);
}

Spell* Eluna::CHECK_SPELL(lua_State* L, int narg)
{
    return ElunaTemplate<Spell>::check(L, narg);
}

uint64 Eluna::CHECK_ULONG(lua_State* L, int narg)
{
    uint64 l = 0;
    const char* c_str = luaL_optstring(L, narg, "0");
    sscanf(c_str, UI64FMTD, &l);
    return l;
}

int64 Eluna::CHECK_LONG(lua_State* L, int narg)
{
    int64 l = 0;
    const char* c_str = luaL_optstring(L, narg, "0");
    sscanf(c_str, SI64FMTD, &l);
    return l;
}

Item* Eluna::CHECK_ITEM(lua_State* L, int narg)
{
    return ElunaTemplate<Item>::check(L, narg);
}

// Saves the function reference ID given to the register type's store for given entry under the given event
void Eluna::Register(uint8 regtype, uint32 id, uint32 evt, int functionRef)
{
    switch (regtype)
    {
        case REGTYPE_PACKET:
            if (evt < NUM_MSG_TYPES)
            {
                PacketEventBindings.Insert(evt, functionRef);
                return;
            }
            break;

        case REGTYPE_SERVER:
            if (evt < SERVER_EVENT_COUNT)
            {
                ServerEventBindings.Insert(evt, functionRef);
                return;
            }
            break;

        case REGTYPE_PLAYER:
            if (evt < PLAYER_EVENT_COUNT)
            {
                PlayerEventBindings.Insert(evt, functionRef);
                return;
            }
            break;

        case REGTYPE_VEHICLE:
            if (evt < VEHICLE_EVENT_COUNT)
            {
                VehicleEventBindings.Insert(evt, functionRef);
                return;
            }
            break;

        case REGTYPE_GUILD:
            if (evt < GUILD_EVENT_COUNT)
            {
                GuildEventBindings.Insert(evt, functionRef);
                return;
            }
            break;

        case REGTYPE_GROUP:
            if (evt < GROUP_EVENT_COUNT)
            {
                GroupEventBindings.Insert(evt, functionRef);
                return;
            }
            break;

        case REGTYPE_CREATURE:
            if (evt < CREATURE_EVENT_COUNT)
            {
                if (!sObjectMgr->GetCreatureTemplate(id))
                {
                    luaL_error(L, "Couldn't find a creature with (ID: %d)!", id);
                    return;
                }

                sEluna.CreatureEventBindings.Insert(id, evt, functionRef);
                return;
            }
            break;

        case REGTYPE_CREATURE_GOSSIP:
            if (evt < GOSSIP_EVENT_COUNT)
            {
                if (!sObjectMgr->GetCreatureTemplate(id))
                {
                    luaL_error(L, "Couldn't find a creature with (ID: %d)!", id);
                    return;
                }

                sEluna.CreatureGossipBindings.Insert(id, evt, functionRef);
                return;
            }
            break;

        case REGTYPE_GAMEOBJECT:
            if (evt < GAMEOBJECT_EVENT_COUNT)
            {
                if (!sObjectMgr->GetGameObjectTemplate(id))
                {
                    luaL_error(L, "Couldn't find a gameobject with (ID: %d)!", id);
                    return;
                }

                sEluna.GameObjectEventBindings.Insert(id, evt, functionRef);
                return;
            }
            break;

        case REGTYPE_GAMEOBJECT_GOSSIP:
            if (evt < GOSSIP_EVENT_COUNT)
            {
                if (!sObjectMgr->GetGameObjectTemplate(id))
                {
                    luaL_error(L, "Couldn't find a gameobject with (ID: %d)!", id);
                    return;
                }

                sEluna.GameObjectGossipBindings.Insert(id, evt, functionRef);
                return;
            }
            break;

        case REGTYPE_ITEM:
            if (evt < ITEM_EVENT_COUNT)
            {
                if (!sObjectMgr->GetItemTemplate(id))
                {
                    luaL_error(L, "Couldn't find a item with (ID: %d)!", id);
                    return;
                }

                sEluna.ItemEventBindings.Insert(id, evt, functionRef);
                return;
            }
            break;

        case REGTYPE_ITEM_GOSSIP:
            if (evt < GOSSIP_EVENT_COUNT)
            {
                if (!sObjectMgr->GetItemTemplate(id))
                {
                    luaL_error(L, "Couldn't find a item with (ID: %d)!", id);
                    return;
                }

                sEluna.ItemGossipBindings.Insert(id, evt, functionRef);
                return;
            }
            break;

        case REGTYPE_PLAYER_GOSSIP:
            if (evt < GOSSIP_EVENT_COUNT)
            {
                sEluna.playerGossipBindings.Insert(id, evt, functionRef);
                return;
            }
            break;

        default:
            luaL_error(L, "Unknown register type (regtype %d, id %d, event %d)", regtype, id, evt);
            return;
    }
    luaL_error(L, "Unknown event type (regtype %d, id %d, event %d)", regtype, id, evt);
}


void Eluna::EventBind::Clear()
{
    for (ElunaEntryMap::iterator itr = Bindings.begin(); itr != Bindings.end(); ++itr)
    {
        for (ElunaBindingMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            luaL_unref(sEluna.L, LUA_REGISTRYINDEX, (*it));
        itr->second.clear();
    }
    Bindings.clear();
}

void Eluna::EventBind::Insert(int eventId, int funcRef)
{
    Bindings[eventId].push_back(funcRef);
}

bool Eluna::EventBind::BeginCall(int eventId) const
{
    if (Bindings.empty())
        return false;
    if (Bindings.find(eventId) == Bindings.end())
        return false;
    lua_settop(sEluna.L, 0); // stack should be empty
    sEluna.Push(sEluna.L, eventId);
    return true;
}

void Eluna::EventBind::ExecuteCall()
{
    int eventId = luaL_checkinteger(sEluna.L, 1);
    int params = lua_gettop(sEluna.L);
    for (ElunaBindingMap::const_iterator it = Bindings[eventId].begin(); it != Bindings[eventId].end(); ++it)
    {
        lua_rawgeti(sEluna.L, LUA_REGISTRYINDEX, (*it)); // Fetch function
        for (int i = 1; i <= params; ++i) // Copy original pushed params
            lua_pushvalue(sEluna.L, i);
        sEluna.ExecuteCall(params, LUA_MULTRET); // Do call and leave results to stack
    }
    for (int i = params; i > 0; --i) // Remove original pushed params
        if (!lua_isnone(sEluna.L, i))
            lua_remove(sEluna.L, i);
    // Results in stack, otherwise stack clean
}

void Eluna::EventBind::EndCall() const
{
    lua_settop(sEluna.L, 0); // stack should be empty
};

void Eluna::EntryBind::Clear()
{
    for (ElunaEntryMap::iterator itr = Bindings.begin(); itr != Bindings.end(); ++itr)
    {
        for (ElunaBindingMap::const_iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            luaL_unref(sEluna.L, LUA_REGISTRYINDEX, it->second);
        itr->second.clear();
    }
    Bindings.clear();
}

void Eluna::EntryBind::Insert(uint32 entryId, int eventId, int funcRef)
{
    if (Bindings[entryId][eventId])
    {
        luaL_unref(sEluna.L, LUA_REGISTRYINDEX, funcRef); // free the unused ref
        luaL_error(sEluna.L, "A function is already registered for entry (%d) event (%d)", entryId, eventId);
    }
    else
        Bindings[entryId][eventId] = funcRef;
}

EventMgr::LuaEvent::LuaEvent(EventProcessor* _events, int _funcRef, uint32 _delay, uint32 _calls, Object* _obj) :
    events(_events), funcRef(_funcRef), delay(_delay), calls(_calls), obj(_obj)
{
    if (_events)
        sEluna.m_EventMgr.LuaEvents[_events].insert(this); // Able to access the event if we have the processor
}

EventMgr::LuaEvent::~LuaEvent()
{
    if (events)
    {
        // Attempt to remove the pointer from LuaEvents
        EventMgr::EventMap::const_iterator it = sEluna.m_EventMgr.LuaEvents.find(events); // Get event set
        if (it != sEluna.m_EventMgr.LuaEvents.end())
            sEluna.m_EventMgr.LuaEvents[events].erase(this); // Remove pointer
    }
    luaL_unref(sEluna.L, LUA_REGISTRYINDEX, funcRef); // Free lua function ref
}

bool EventMgr::LuaEvent::Execute(uint64 time, uint32 diff)
{
    ELUNA_GUARD();
    bool remove = (calls == 1);
    if (!remove)
        events->AddEvent(this, events->CalculateTime(delay)); // Reschedule before calling incase RemoveEvents used
    sEluna.BeginCall(funcRef);
    sEluna.Push(sEluna.L, funcRef);
    sEluna.Push(sEluna.L, delay);
    sEluna.Push(sEluna.L, calls);
    if (!remove && calls)
        --calls;
    sEluna.Push(sEluna.L, obj);
    sEluna.ExecuteCall(4, 0);
    return remove; // Destory (true) event if not run
}

// Lua taxi helper functions
uint32 LuaTaxiMgr::nodeId = 500;
void LuaTaxiMgr::StartTaxi(Player* player, uint32 pathid)
{
    if (pathid >= sTaxiPathNodesByPath.size())
        return;

    TaxiPathNodeList const& path = sTaxiPathNodesByPath[pathid];
    if (path.size() < 2)
        return;

    std::vector<uint32> nodes;
    nodes.resize(2);
    nodes[0] = path[0].index;
    nodes[1] = path[path.size() - 1].index;

    player->ActivateTaxiPathTo(nodes);
}

uint32 LuaTaxiMgr::AddPath(std::list<TaxiPathNodeEntry> nodes, uint32 mountA, uint32 mountH, uint32 price, uint32 pathId)
{
    if (nodes.size() < 2)
        return 0;
    if (!pathId)
        pathId = sTaxiPathNodesByPath.size();
    if (sTaxiPathNodesByPath.size() <= pathId)
        sTaxiPathNodesByPath.resize(pathId + 1);
    sTaxiPathNodesByPath[pathId].clear();
    sTaxiPathNodesByPath[pathId].resize(nodes.size());
    uint32 startNode = nodeId;
    uint32 index = 0;
    for (std::list<TaxiPathNodeEntry>::const_iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        TaxiPathNodeEntry entry = *it;
        entry.path = pathId;
        TaxiNodesEntry* nodeEntry = new TaxiNodesEntry();
        nodeEntry->ID = index;
        nodeEntry->map_id = entry.mapid;
        nodeEntry->MountCreatureID[0] = mountH;
        nodeEntry->MountCreatureID[1] = mountA;
        nodeEntry->x = entry.x;
        nodeEntry->y = entry.y;
        nodeEntry->z = entry.z;
        sTaxiNodesStore.SetEntry(nodeId, nodeEntry);
        entry.index = nodeId++;
        sTaxiPathNodesByPath[pathId].set(index++, TaxiPathNodePtr(new TaxiPathNodeEntry(entry)));
    }
    if (startNode >= nodeId)
        return 0;
    sTaxiPathSetBySource[startNode][nodeId - 1] = TaxiPathBySourceAndDestination(pathId, price);
    return pathId;
}