#include "LuaEngine.h"
#include "GlobalMethods.h"
#include "UnitMethods.h"
#include "GroupMethods.h"
#include "GuildMethods.h"
#include "GameObjectMethods.h"
#include "QueryMethods.h"
#include "AuraMethods.h"
#include "ItemMethods.h"
#include "WorldPacketMethods.h"
#include "SpellMethods.h"
#include "QuestMethods.h"
#include "LuaFunctions.h"

#if PLATFORM == PLATFORM_UNIX
#include <dirent.h>
#endif

lua_State* Eluna::LuaState = NULL;
map<uint64, Eluna::LuaEventMap*> Eluna::LuaEventMaps;

template<typename T> const char* GetTName() { return "UNK"; }
template<> const char* GetTName<Unit>() { return "Unit"; }
template<> const char* GetTName<GameObject>() { return "GameObject"; }
template<> const char* GetTName<Group>() { return "Group"; }
template<> const char* GetTName<Guild>() { return "Guild"; }
template<> const char* GetTName<Log>() { return "Log"; }
template<> const char* GetTName<QueryResult>() { return "QueryResult"; }
template<> const char* GetTName<Aura>() { return "Aura"; }
template<> const char* GetTName<WorldPacket>() { return "WorldPacket"; }
template<> const char* GetTName<Item>() { return "Item"; }
template<> const char* GetTName<Spell>() { return "Spell"; }
template<> const char* GetTName<Quest>() { return "Quest"; }

void Eluna::StartEluna(bool restart /*= false*/)
{
    if (restart)
    {
        OnElunaRestart(ELUNA_EVENT_ON_RESTART);
        sLog->outInfo(LOG_FILTER_GENERAL, "Eluna Nova::Restarting Engine");

        if (LuaState)
        {
            Eluna::LuaEventMap::LuaEventsResetAll(); // Unregisters and stops all timed events

            for (map<int, vector<int> >::iterator itr = sEluna->ServerEventBindings.begin(); itr != sEluna->ServerEventBindings.end(); ++itr)
            {
                for (vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                    luaL_unref(sEluna->LuaState, LUA_REGISTRYINDEX, (*it));
                itr->second.clear();
            }
            sEluna->CreatureEventBindings->Clear();
            sEluna->CreatureGossipBindings->Clear();
            sEluna->GameObjectEventBindings->Clear();
            sEluna->GameObjectGossipBindings->Clear();
            sEluna->ItemEventBindings->Clear();
            sEluna->ItemGossipBindings->Clear();
            sEluna->playerGossipBindings->Clear();

            lua_close(sEluna->LuaState);
        }
    }
    else
    {
        Eluna_AddScriptHooks();
        sEluna->CreatureAI = new LuaCreatureScript;
        sEluna->GameObjectAI = new LuaGameObjectScript;
        sEluna->WorldAI = new LuaWorldScript;
    }

    LuaState = luaL_newstate();
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Eluna Nova Lua Engine loaded.");

    LoadedScripts loadedScripts;
    LoadDirectory("scripts", &loadedScripts);
    luaL_openlibs(LuaState);
    //Register Globals Here
    RegisterGlobals(LuaState);
    //Register Templates Here
    ElunaTemplate<Unit>::Register(LuaState);
    ElunaTemplate<GameObject>::Register(LuaState);
    ElunaTemplate<Group>::Register(LuaState);
    ElunaTemplate<Guild>::Register(LuaState);
    ElunaTemplate<QueryResult>::Register(LuaState);
    ElunaTemplate<Aura>::Register(LuaState);
    ElunaTemplate<WorldPacket>::Register(LuaState);
    ElunaTemplate<Item>::Register(LuaState);
    ElunaTemplate<Spell>::Register(LuaState);
    ElunaTemplate<Quest>::Register(LuaState);

    uint32 count = 0;
    char filename[200];
    for (std::set<std::string>::iterator itr = loadedScripts.luaFiles.begin(); itr !=  loadedScripts.luaFiles.end(); ++itr)
    {
        strcpy(filename, itr->c_str());
        if (luaL_loadfile(LuaState, filename) != 0)
        {
            sLog->outError(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Error loading `%s`.", itr->c_str());
            report(LuaState);
        }
        else
        {
            int err = lua_pcall(LuaState, 0, 0, 0);
            if (err != 0 && err == LUA_ERRRUN)
            {
                sLog->outError(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Error loading `%s`.", itr->c_str());
                report(LuaState);
            }
        }
        ++count;
    }
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Loaded %u Lua scripts", count);
}

void Eluna::RegisterGlobals(lua_State* L)
{
    lua_register(L, "RegisterServerHook", &LuaGlobalFunctions::RegisterServerHook);
    lua_register(L, "RegisterCreatureEvent", &LuaGlobalFunctions::RegisterCreatureEvent);
    lua_register(L, "RegisterCreatureGossipEvent", &LuaGlobalFunctions::RegisterCreatureGossipEvent);
    lua_register(L, "RegisterGameObjectEvent", &LuaGlobalFunctions::RegisterGameObjectEvent);
    lua_register(L, "RegisterGameObjectGossipEvent", &LuaGlobalFunctions::RegisterGameObjectGossipEvent);
    lua_register(L, "RegisterItemEvent", &LuaGlobalFunctions::RegisterItemEvent);
    lua_register(L, "RegisterItemGossipEvent", &LuaGlobalFunctions::RegisterItemGossipEvent);
    lua_register(L, "RegisterPlayerGossipEvent", &LuaGlobalFunctions::RegisterPlayerGossipEvent);

    lua_register(L, "GetLuaEngine", &LuaGlobalFunctions::GetLuaEngine);
    lua_register(L, "GetLUAEngine", &LuaGlobalFunctions::GetLuaEngine);
    lua_register(L, "GetCoreVersion", &LuaGlobalFunctions::GetCoreVersion);
    lua_register(L, "GetQuest", &LuaGlobalFunctions::GetQuest);
    lua_register(L, "ReloadEluna", &LuaGlobalFunctions::ReloadEluna);
    lua_register(L, "GetPlayerByGUID", &LuaGlobalFunctions::GetPlayerByGUID);
    lua_register(L, "GetPlayerByName", &LuaGlobalFunctions::GetPlayerByName);
    lua_register(L, "GetGameTime", &LuaGlobalFunctions::GetGameTime);
    lua_register(L, "SendWorldMessage", &LuaGlobalFunctions::SendWorldMessage);
    lua_register(L, "GetPlayersInWorld", &LuaGlobalFunctions::GetPlayersInWorld);
    lua_register(L, "GetPlayersInMap", &LuaGlobalFunctions::GetPlayersInMap);
    lua_register(L, "WorldDBQuery", &LuaGlobalFunctions::WorldDBQuery); // Not Documented
    lua_register(L, "WorldDBExecute", &LuaGlobalFunctions::WorldDBExecute); // Not Documented
    lua_register(L, "CharDBQuery", &LuaGlobalFunctions::CharDBQuery); // Not Documented
    lua_register(L, "CharDBExecute", &LuaGlobalFunctions::CharDBExecute); // Not Documented
    lua_register(L, "AuthDBQuery", &LuaGlobalFunctions::AuthDBQuery); // Not Documented
    lua_register(L, "AuthDBExecute", &LuaGlobalFunctions::AuthDBExecute); // Not Documented
    lua_register(L, "GetGuildByName", &LuaGlobalFunctions::GetGuildByName);
    lua_register(L, "GetGuildByLeaderGUID", &LuaGlobalFunctions::GetGuildByLeaderGUID);
    lua_register(L, "GetPlayerCount", &LuaGlobalFunctions::GetPlayerCount);
    lua_register(L, "CreateLuaEvent", &LuaGlobalFunctions::CreateLuaEvent); // Not Documented
    lua_register(L, "RegisterTimedEvent", &LuaGlobalFunctions::CreateLuaEvent); // Arc compability Not Documented
    lua_register(L, "DestroyLuaEventByID", &LuaGlobalFunctions::DestroyLuaEventByID); // Not Documented
    lua_register(L, "DestroyLuaEvents", &LuaGlobalFunctions::DestroyLuaEvents); // Not Documented
    lua_register(L, "PerformIngameSpawn", &LuaGlobalFunctions::PerformIngameSpawn); // Not Documented
    lua_register(L, "CreatePacket", &LuaGlobalFunctions::CreatePacket); // Not Documented
	lua_register(L, "AddVendorItem", &LuaGlobalFunctions::AddVendorItem);
	lua_register(L, "VendorRemoveItem", &LuaGlobalFunctions::VendorRemoveItem);
	lua_register(L, "VendorRemoveAllItems", &LuaGlobalFunctions::VendorRemoveAllItems); // :VendorRemoveAllItems(creature, persist(bool)) -- Removes all items from a vendor. If persist is true, it will remove the rows in the npc_vendor table.
}

// Loads lua scripts from given directory
void Eluna::LoadDirectory(char* Dirname, LoadedScripts* lscr)
{
#ifdef WIN32
    HANDLE hFile;
    WIN32_FIND_DATA FindData;
    memset(&FindData, 0, sizeof(FindData));
    char SearchName[MAX_PATH];

    strcpy(SearchName, Dirname);
    strcat(SearchName, "\\*.*");

    hFile = FindFirstFile(SearchName, &FindData);

    // break if we don't find dir
    if (!hFile)
    {
        sLog->outError(LOG_FILTER_SERVER_LOADING, "Eluna Nova::No `scripts` directory found!");
        return;
    }

    FindNextFile(hFile, &FindData);
    while ( FindNextFile(hFile, &FindData) )
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
            if (!_stricmp(ext,"aul."))
                lscr->luaFiles.insert(fname);
        }
    }
    FindClose(hFile);
#else    
    char* dir = strrchr(Dirname, '/');
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
            sLog->outError(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Error opening `%s`", _path);
        }
        else
            error = false;

        if (!error && S_ISDIR(attributes.st_mode))
            LoadDirectory((char*)_path, lscr);
        else
        {
            char* ext = strrchr(list[fileCount]->d_name, '.');
            if (ext && !strcmp(ext, ".lua"))
                lscr->luaFiles.insert(_path);
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
    lua_settop(LuaState, 0); //stack should be empty
    lua_rawgeti(LuaState, LUA_REGISTRYINDEX, (fReference));
}

bool Eluna::ExecuteCall(uint8 params, uint8 res)
{
    bool ret = true;
    int top = lua_gettop(LuaState);
    if (strcmp(luaL_typename(LuaState,top-params), "function") )
    {
        ret = false;
        if (params > 0)
        {
            for (int i = top; i >= (top-params); i--)
            {
                if (!lua_isnone(LuaState, i) )
                    lua_remove(LuaState, i);
            }
        }
    }
    else
    {
        if (lua_pcall(LuaState,params,res,0) )
        {
            report(LuaState);
            ret = false;
        }
    }
    return ret;
}

void Eluna::EndCall(uint8 res)
{
    for (int i = res; i > 0; i--)
    {
        if (!lua_isnone(LuaState,res))
            lua_remove(LuaState,res);
    }
}

/* Pushes */
// Pushes a low part of a guid (low guid)
void Eluna::PushGUID(lua_State* L, uint64 g)
{
    if (!L) L = LuaState;
    lua_pushunsigned(L, GUID_LOPART(g));
}

void Eluna::PushInteger(lua_State* L, int i)
{
    if (!L) L = LuaState;
    lua_pushinteger(L, i);
}

void Eluna::PushUnsigned(lua_State* L, uint32 u)
{
    if (!L) L = LuaState;
    lua_pushunsigned(L, u);
}

void Eluna::PushFloat(lua_State* L, float f)
{
    if (!L) L = LuaState;
    lua_pushnumber(L, f);
}

void Eluna::PushDouble(lua_State* L, double d)
{
    if (!L) L = LuaState;
    lua_pushnumber(L, d);
}

void Eluna::PushBoolean(lua_State* L, bool b)
{
    if (!L) L = LuaState;
    if (b)
        lua_pushboolean(L, 1);
    else
        lua_pushboolean(L, 0);
}

void Eluna::PushString(lua_State* L, const char* str)
{
    if (!L) L = LuaState;
    lua_pushstring(L, str);
}

void Eluna::PushGroup(lua_State* L, Group* group)
{
    if (!L) L = LuaState;
    if (group)
        ElunaTemplate<Group>::push(L, group);
    else
        lua_pushnil(L);
}

void Eluna::PushGuild(lua_State* L, Guild* guild)
{
    if (!L) L = LuaState;
    if (guild)
        ElunaTemplate<Guild>::push(L, guild);
    else
        lua_pushnil(L);
}

void Eluna::PushUnit(lua_State* L, Unit* unit)
{
    if (!L) L = LuaState;
    if (unit)
        ElunaTemplate<Unit>::push(L, unit);
    else
        lua_pushnil(L);
}

void Eluna::PushQueryResult(lua_State* L, QueryResult* result)
{
    if (!L) L = LuaState;
    if (result)
        ElunaTemplate<QueryResult>::push(L, result);
    else
        lua_pushnil(L);
}

void Eluna::PushGO(lua_State* L, GameObject* _go)
{
    if (!L) L = LuaState;
    if (_go)
        ElunaTemplate<GameObject>::push(L, _go);
    else
        lua_pushnil(L);
}

void Eluna::PushAura(lua_State* L, Aura* aura)
{
    if (!L) L = LuaState;
    if (aura)
        ElunaTemplate<Aura>::push(L, aura);
    else
        lua_pushnil(L);
}

void Eluna::PushItem(lua_State* L, Item* item)
{
    if (!L) L = LuaState;
    if (item)
        ElunaTemplate<Item>::push(L, item);
    else
        lua_pushnil(L);
}

void Eluna::PushSpell(lua_State* L, Spell* spell)
{
	if (!L) L = LuaState;
	if (spell)
		ElunaTemplate<Spell>::push(L, spell);
	else
		lua_pushnil(L);
}

void Eluna::PushQuest(lua_State* L, Quest const* quest)
{
	if (!L) L = LuaState;
	if (quest)
		ElunaTemplate<Quest>::push(L, const_cast<Quest*>(quest));
	else
		lua_pushnil(L);
}

void Eluna::PushPacket(lua_State* L, WorldPacket* packet)
{
    if (!L) L = LuaState;
    if (packet)
        ElunaTemplate<WorldPacket>::push(L, packet);
    else
        lua_pushnil(L);
}

Player * Eluna::CHECK_PLAYER(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<Player>::check(LuaState, narg);
    else
        return ElunaTemplate<Player>::check(L, narg);
}

Unit * Eluna::CHECK_UNIT(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<Unit>::check(LuaState, narg);
    else
        return ElunaTemplate<Unit>::check(L, narg);
}

Creature * Eluna::CHECK_CREATURE(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<Creature>::check(LuaState, narg);
    else
        return ElunaTemplate<Creature>::check(L, narg);
}

GameObject* Eluna::CHECK_OBJECT(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<GameObject>::check(LuaState, narg);
    else
        return ElunaTemplate<GameObject>::check(L, narg);
}

WorldPacket* Eluna::CHECK_PACKET(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<WorldPacket>::check(LuaState, narg);
    else
        return ElunaTemplate<WorldPacket>::check(L, narg);
}

WorldObject* Eluna::CHECK_WORLDOBJECT(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<WorldObject>::check(LuaState, narg);
    else
        return ElunaTemplate<WorldObject>::check(L, narg);
}

// Unregisters and stops all timed events
void Eluna::LuaEventMap::LuaEventsResetAll()
{
    // GameObject && Creature events reset
    if (!sEluna->LuaEventMaps.empty())
        for (map<uint64, Eluna::LuaEventMap*>::iterator itr = sEluna->LuaEventMaps.begin(); itr != sEluna->LuaEventMaps.end(); ++itr)
            if (itr->second)
                itr->second->LuaEventsReset();
    // Global events reset
    sEluna->WorldAI->LuaEventsReset();
}

// Saves the function reference ID given to the register type's store for given entry under the given event
void Eluna::Register(uint8 regtype, uint32 id, uint32 evt, int functionRef)
{
    switch(regtype)
    {
    case REGTYPE_SERVER:
        if (evt < SERVER_EVENT_COUNT)
        {
            ServerEventBindings.at(evt).push_back(functionRef);
            return;
        }
        break;

    case REGTYPE_CREATURE:
        if (evt < CREATURE_EVENT_COUNT)
        {
            sEluna->CreatureAI->RegisterCreatureScript(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_CREATURE_GOSSIP:
        if (evt < GOSSIP_EVENT_COUNT)
        {
            sEluna->CreatureAI->RegisterCreatureGossipScript(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_GAMEOBJECT:
        if (evt < GAMEOBJECT_EVENT_COUNT)
        {
            sEluna->GameObjectAI->RegisterGameObjectScript(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_GAMEOBJECT_GOSSIP:
        if (evt < GOSSIP_EVENT_COUNT)
        {
            sEluna->GameObjectAI->RegisterGameObjectGossipScript(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_ITEM:
        if (evt < ITEM_EVENT_COUNT)
        {
            if (!sObjectMgr->GetItemTemplate(id))
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a item with (ID: %d)!", id);
                return;
            }

            sEluna->ItemEventBindings->Insert(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_ITEM_GOSSIP:
        if (evt < GOSSIP_EVENT_COUNT)
        {
            if (!sObjectMgr->GetItemTemplate(id))
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a item with (ID: %d)!", id);
                return;
            }

            sEluna->ItemGossipBindings->Insert(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_PLAYER_GOSSIP:
        if (evt < GOSSIP_EVENT_COUNT)
        {
            sEluna->playerGossipBindings->Insert(id, evt, functionRef);
            return;
        }
        break;

    default:
        sLog->outError(LOG_FILTER_GENERAL, "Unknown register type (regtype %u, id %u, event %u)", regtype, id, evt);
        return;
    }
    sLog->outError(LOG_FILTER_GENERAL, "Unknown event type (regtype %u, id %u, event %u)", regtype, id, evt);
}