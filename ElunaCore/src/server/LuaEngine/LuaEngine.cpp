/*
FOEREAPER TOMMY ENGINE, YEAH!
*/
#pragma warning (disable:4006)
#include "LuaEngine.h"
#include "GlobalMethods.h"
#include "UnitMethods.h"
#include "GroupMethods.h"
#include "GuildMethods.h"
#include "GameObjectMethods.h"
#include "QueryMethods.h"
#include "AuraMethods.h"
#include "ChannelMethods.h"
#include "LuaFunctions.h"
#include "LuaCreatureAI.h"
#include "LuaGameObjectAI.h"

Eluna* Eluna::LuaEngine = NULL; // give it a value
ElunaScript* Eluna::Script = NULL;

void Eluna::Init()
{
    if (LuaEngine)
        return;

    LuaEngine = new Eluna;
    Script = new ElunaScript("Eluna");
    get()->StartEluna();
}

template<typename T> const char* GetTName() { return "UNK"; }
template<> const char* GetTName<Unit>() { return "Unit"; }
template<> const char* GetTName<GameObject>() { return "GameObject"; }
template<> const char* GetTName<Group>() { return "Group"; }
template<> const char* GetTName<Guild>() { return "Guild"; }
template<> const char* GetTName<Log>() { return "Log"; }
template<> const char* GetTName<QueryResult>() { return "QueryResult"; }
template<> const char* GetTName<Aura>() { return "Aura"; }
template<> const char* GetTName<Channel>() { return "Channel"; }

void Eluna::StartEluna()
{
    _luaState = luaL_newstate();
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Eluna Nova Lua Engine loaded.");

    InitTables();

    LoadedScripts _loadedScripts;
    LoadDirectory("scripts", &_loadedScripts);
    luaL_openlibs(_luaState);
    //Register Globals Here
    RegisterGlobals(_luaState);
    //Register Templates Here
    ElunaTemplate<Unit>::Register(_luaState);
    ElunaTemplate<GameObject>::Register(_luaState);
    ElunaTemplate<Group>::Register(_luaState);
    ElunaTemplate<Guild>::Register(_luaState);
    ElunaTemplate<QueryResult>::Register(_luaState);
    ElunaTemplate<Aura>::Register(_luaState);
    ElunaTemplate<Channel>::Register(_luaState);

    uint32 cnt_uncomp = 0;
    char filename[200];
    for(std::set<std::string>::iterator itr = _loadedScripts.luaFiles.begin(); itr !=  _loadedScripts.luaFiles.end(); itr++)
    {
        strcpy(filename, itr->c_str());
        if(luaL_loadfile(_luaState, filename) != 0)
        {
            sLog->outError(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Error loading `%s`.", itr->c_str());
            report(_luaState);
        }
        else
        {
            int err = lua_pcall(_luaState, 0, 0, 0);
            if(err != 0 && err == LUA_ERRRUN)
            {
                sLog->outError(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Error loading `%s`.", itr->c_str());
                report(_luaState);
            }
        }
        cnt_uncomp++;
    }
    sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Loaded %u Lua scripts", cnt_uncomp);
}

/* Register Other Hooks (Events) */
static int RegisterServerHook(lua_State* L);
static int RegisterGossipEvent(lua_State* L);
static int RegisterCreatureEvent(lua_State* L);
static int RegisterGameObjectEvent(lua_State* L);
static int RegisterGameObjectGossipEvent(lua_State* L);

void Eluna::RegisterGlobals(lua_State* L)
{
    lua_register(L, "RegisterServerHook", RegisterServerHook);
    lua_register(L, "RegisterGossipEvent", RegisterGossipEvent);
    lua_register(L, "RegisterCreatureEvent", RegisterCreatureEvent);
    lua_register(L, "RegisterGameObjectEvent", RegisterGameObjectEvent);
    lua_register(L, "RegisterGameObjectGossipEvent", RegisterGameObjectGossipEvent);

    lua_register(L, "GetLuaEngine", &LuaGlobalFunctions::GetLuaEngine);
    lua_register(L, "GetLUAEngine", &LuaGlobalFunctions::GetLuaEngine);
    lua_register(L, "GetCoreVersion", &LuaGlobalFunctions::GetCoreVersion);
    lua_register(L, "ReloadEluna", &LuaGlobalFunctions::ReloadEluna);
    lua_register(L, "GetPlayerByGUID", &LuaGlobalFunctions::GetPlayerByGUID);
    lua_register(L, "GetPlayerByName", &LuaGlobalFunctions::GetPlayerByName);
    lua_register(L, "GetGameTime", &LuaGlobalFunctions::GetGameTime);
    lua_register(L, "SendWorldMessage", &LuaGlobalFunctions::SendWorldMessage);
    lua_register(L, "GetPlayersInWorld", &LuaGlobalFunctions::GetPlayersInWorld);
    lua_register(L, "GetPlayersInMap", &LuaGlobalFunctions::GetPlayersInMap);
    lua_register(L, "WorldDBQuery", &LuaGlobalFunctions::WorldDBQuery);
    lua_register(L, "GetGuildByName", &LuaGlobalFunctions::GetGuildByName);
    lua_register(L, "GetGuildByLeaderGUID", &LuaGlobalFunctions::GetGuildByLeaderGUID);
    lua_register(L, "GetPlayerCount", &LuaGlobalFunctions::GetPlayerCount);
    lua_register(L, "CreateLuaEvent", &LuaGlobalFunctions::CreateLuaEvent);
    lua_register(L, "PerformIngameSpawn", &LuaGlobalFunctions::PerformIngameSpawn);             // Not Documented
}

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
    if(!hFile)
    {
        sLog->outError(LOG_FILTER_SERVER_LOADING, "Eluna Nova::No `scripts` directory found!");
        return;
    }

    FindNextFile(hFile, &FindData);
    while( FindNextFile(hFile, &FindData) )
    {
        if(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            strcpy(SearchName,Dirname);
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
            while(len > 0)
            {
                ext[i++] = fname[--len];
                if(fname[len] == '.')
                    break;
            }
            ext[i++] = '\0';
            if(!_stricmp(ext,"aul."))
                lscr->luaFiles.insert(fname);
        }
    }
    FindClose(hFile);
#endif
}

void Eluna::report(lua_State* L)
{
    const char* msg = lua_tostring(L, -1);
    while(msg)
    {
        lua_pop(L, -1);
        printf("\t%s\n",msg);
        msg = lua_tostring(L, -1);
    }
}

/* Pushes */
void Eluna::PushGUID(lua_State* L, uint64 g)
{
    if(!L) L = _luaState;
    lua_pushunsigned(L, GUID_LOPART(g));
}

//void Eluna::PushLong(lua_State* L, uint64 l)
//{
//    if(!L) L = _luaState;
//    lua_pushinteger(L, l);
//}

void Eluna::PushInteger(lua_State* L, int i)
{
    if(!L) L = _luaState;
    lua_pushinteger(L, i);
}

void Eluna::PushUnsigned(lua_State* L, uint32 u)
{
    if(!L) L = _luaState;
    lua_pushunsigned(L, u);
}

void Eluna::PushFloat(lua_State* L, float f)
{
    if(!L) L = _luaState;
    lua_pushnumber(L, f);
}

void Eluna::PushDouble(lua_State* L, double d)
{
    if(!L) L = _luaState;
    lua_pushnumber(L, d);
}

void Eluna::PushBoolean(lua_State* L, bool b)
{
    if(!L) L = _luaState;
    if(b)
        lua_pushboolean(L, 1);
    else
        lua_pushboolean(L, 0);
}

void Eluna::PushString(lua_State* L, const char* str)
{
    if(!L) L = _luaState;
    lua_pushstring(L, str);
}

void Eluna::PushGroup(lua_State* L, Group* group)
{
    if(!L) L = _luaState;
    if(group)
        ElunaTemplate<Group>::push(L, group);
    else
        lua_pushnil(L);
}

void Eluna::PushGuild(lua_State* L, Guild* pGuild)
{
    if(!L) L = _luaState;
    if(pGuild)
        ElunaTemplate<Guild>::push(L, pGuild);
    else
        lua_pushnil(L);
}

void Eluna::PushUnit(lua_State* L, Unit* unit)
{
    if(!L) L = _luaState;
    if(unit)
        ElunaTemplate<Unit>::push(L, unit);
    else
        lua_pushnil(L);
}

void Eluna::PushQueryResult(lua_State* L, QueryResult* result)
{
    if(!L) L = _luaState;
    if(result)
        ElunaTemplate<QueryResult>::push(L, result);
    else
        lua_pushnil(L);
}

void Eluna::PushGO(lua_State* L, GameObject* _go)
{
    if (!L) L = _luaState;
    if (_go)
        ElunaTemplate<GameObject>::push(L, _go);
    else
        lua_pushnil(L);
}

void Eluna::PushAura(lua_State* L, Aura* aura)
{
    if (!L) L = _luaState;
    if (aura)
        ElunaTemplate<Aura>::push(L, aura);
    else
        lua_pushnil(L);
}

void Eluna::PushChannel(lua_State* L, Channel* channel)
{
    if(!L) L = _luaState;
    if(channel)
        ElunaTemplate<Channel>::push(L, channel);
    else
        lua_pushnil(L);
}

CreatureAI* Eluna::GetLuaCreatureAI(Creature* creature)
{
    if (sLuaCreatureScript->GetCreatureBindingForId(creature->GetEntry()))
        return sLuaCreatureScript->GetAI(creature);
    return NULL;
}

GameObjectAI* Eluna::GetLuaGameObjectAI(GameObject* gameObject)
{
    if (sLuaGameObjectScript->GetGameObjectAIBindingForId(gameObject->GetEntry()))
        return sLuaGameObjectScript->GetAI(gameObject);
    return NULL;
}

// RegisterServerHook(ev, func)
static int RegisterServerHook(lua_State* L)
{
    uint16 functionRef = 0;
    lua_settop(L, 2);
    uint32 ev = luaL_checkint(L, 1);
    const char* typeName = luaL_typename(L, 2);

    if (ev == 0 || !typeName)
        return 0;

    if(!strcmp(typeName, "function"))
        functionRef = (uint16)lua_ref(L, true);

    if(functionRef > 0)
        Eluna::get()->Register(REGTYPE_SERVER, 0, ev, functionRef);
    return 0;
}

//RegisterGossipEvent(ev, func)
static int RegisterGossipEvent(lua_State* L)
{
    uint16 functionRef = 0;
    lua_settop(L, 3);
    uint32 entry = luaL_checkint(L, 1);
    uint32 ev = luaL_checkint(L, 2);
    const char* typeName = luaL_typename(L, 3);

    if (ev == 0 || !typeName)
        return 0;

    if(!strcmp(typeName, "function"))
        functionRef = (uint16)lua_ref(L, true);

    if(functionRef > 0)
        Eluna::get()->Register(REGTYPE_GOSSIP, entry, ev, functionRef);
    return 0;
}

// RegisterGameObjectGossipEvent(entry, event, function)
static int RegisterGameObjectGossipEvent(lua_State* L)
{
    uint16 functionRef = 0;
    lua_settop(L, 3);
    uint32 entry = luaL_checkint(L, 1);
    uint32 ev = luaL_checkint(L, 2);
    const char* typeName = luaL_typename(L, 3);

    if (ev == 0 || !typeName)
        return 0;

    if(!strcmp(typeName, "function"))
        functionRef = (uint16)lua_ref(L, true);

    if(functionRef > 0)
        Eluna::get()->Register(REGTYPE_GAMEOBJECT_GOSSIP, entry, ev, functionRef);
    return 0;
}

// RegisterCreatureEvent(entry, ev, func)
static int RegisterCreatureEvent(lua_State* L)
{
    uint16 functionRef = 0;
    lua_settop(L, 3);
    uint32 entry = luaL_checkint(L, 1);
    uint32 evt = luaL_checkint(L, 2);
    const char* typeName = luaL_typename(L, 3);
    if(evt == 0 || !typeName)
        return 0;

    if (!strcmp(typeName, "function"))
        functionRef = (uint16)lua_ref(L, true);

    if (functionRef > 0)
        Eluna::get()->Register(REGTYPE_CREATURE, entry, evt, functionRef);
    return 0;
}

// RegisterGameObjectEvent(entry, event, func)
static int RegisterGameObjectEvent(lua_State* L)
{
    uint16 functionRef = 0;
    lua_settop(L, 3);
    uint32 entry = luaL_checkint(L, 1);
    uint32 evt = luaL_checkint(L, 2);
    const char* typeName = luaL_typename(L, 3);
    if(evt == 0 || !typeName)
        return 0;

    if (!strcmp(typeName, "function"))
        functionRef = (uint16)lua_ref(L, true);

    if (functionRef > 0)
        Eluna::get()->Register(REGTYPE_GAMEOBJECT, entry, evt, functionRef);
    return 0;
}

void Eluna::Register(uint8 regtype, uint32 id, uint32 evt, uint16 functionRef)
{
    switch(regtype)
    {
    case REGTYPE_SERVER:
        if(evt < SERVER_EVENT_COUNT)
            _serverEventBindings.at(evt).push_back(functionRef);
        break;

    case REGTYPE_GOSSIP:
        if(evt < GOSSIP_EVENT_COUNT)
            sLuaCreatureScript->RegisterGossipScript(id, evt, functionRef);
        break;

    case REGTYPE_CREATURE:
        if (evt < CREATURE_EVENT_COUNT)
            sLuaCreatureScript->RegisterCreatureScript(id, evt, functionRef);
        break;

    case REGTYPE_GAMEOBJECT:
        if (evt < GAMEOBJECT_EVENT_COUNT)
            sLuaGameObjectScript->RegisterGameObjectScript(id, evt, functionRef);
        break;

    case REGTYPE_GAMEOBJECT_GOSSIP:
        if (evt < GOSSIP_EVENT_COUNT)
            sLuaGameObjectScript->RegisterGameObjectGossipScript(id, evt, functionRef);
        break;
    }
}

void Eluna::Restart()
{
    sLog->outInfo(LOG_FILTER_GENERAL, "Eluna Nova::Restarting Engine");
    for (ElunaBindingMap::iterator itr = get()->_serverEventBindings.begin(); itr != get()->_serverEventBindings.end(); ++itr)
    {
        for (vector<uint16>::iterator _itr = itr->second.begin(); _itr != itr->second.end(); ++_itr)
            luaL_unref(get()->_luaState, LUA_REGISTRYINDEX, (*_itr));
        itr->second.clear();
    }

    for (vector<CreatureBind*>::iterator itr = get()->_gossipEventBindings.begin(); itr != get()->_gossipEventBindings.end(); ++itr)
    {
        for (int i = 0; i < GOSSIP_EVENT_COUNT; i++)
            luaL_unref(get()->_luaState, LUA_REGISTRYINDEX, (*itr)->_gossipReferences[i]);
        delete (*itr);
    }
    get()->_gossipEventBindings.clear();

    for (vector<CreatureBind*>::iterator itr = get()->_creatureEventBindings.begin(); itr != get()->_creatureEventBindings.end(); ++itr)
    {
        for (int i = 0; i < CREATURE_EVENT_COUNT; i++)
            luaL_unref(get()->_luaState, LUA_REGISTRYINDEX, (*itr)->_functionReferences[i]);
        delete (*itr);
    }
    get()->_creatureEventBindings.clear();

	for (vector<GameObjectBind*>::iterator itr = get()->_gameObjectAIEventBindings.begin(); itr != get()->_gameObjectAIEventBindings.end(); ++itr)
    {
		for (int i = 0; i < GAMEOBJECT_EVENT_COUNT; i++)
			luaL_unref(get()->_luaState, LUA_REGISTRYINDEX, (*itr)->_functionReferences[i]);
        delete (*itr);
    }
    get()->_gameObjectAIEventBindings.clear();

	for (vector<GameObjectBind*>::iterator itr = get()->_gameObjectGossipBindings.begin(); itr != get()->_gameObjectGossipBindings.end(); ++itr)
    {
		for (int i = 0; i < GOSSIP_EVENT_COUNT; i++)
			luaL_unref(get()->_luaState, LUA_REGISTRYINDEX, (*itr)->_gossipReferences[i]);
        delete (*itr);
    }
    get()->_gameObjectGossipBindings.clear();

    lua_close(get()->_luaState); // Closing

    get()->StartEluna(); // Restarting
}
