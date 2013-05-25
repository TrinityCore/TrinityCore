#include "LuaEngine.h"
#include "HookMgr.h"
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

void Eluna::StartEluna(bool restart)
{
    if (restart)
    {
        sHookMgr->OnEngineRestart();
        TC_LOG_INFO(LOG_FILTER_GENERAL, "Eluna Nova::Restarting Engine");

        if (LuaState)
        {
            // Unregisters and stops all timed events
            LuaEventMap::ScriptEventsResetAll();
            LuaEventData::RemoveAll();

            // Remove bindings
            for (std::map<int, std::vector<int> >::iterator itr = ServerEventBindings.begin(); itr != ServerEventBindings.end(); ++itr)
            {
                for (std::vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                    luaL_unref(LuaState, LUA_REGISTRYINDEX, (*it));
                itr->second.clear();
            }
            CreatureEventBindings->Clear();
            CreatureGossipBindings->Clear();
            GameObjectEventBindings->Clear();
            GameObjectGossipBindings->Clear();
            ItemEventBindings->Clear();
            ItemGossipBindings->Clear();
            playerGossipBindings->Clear();

            lua_close(LuaState);
        }
    }
    else
        AddScriptHooks();

    LuaState = luaL_newstate();
    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "Eluna Nova Lua Engine loaded.");

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
            TC_LOG_ERROR(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Error loading `%s`.", itr->c_str());
            report(LuaState);
        }
        else
        {
            int err = lua_pcall(LuaState, 0, 0, 0);
            if (err != 0 && err == LUA_ERRRUN)
            {
                TC_LOG_ERROR(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Error loading `%s`.", itr->c_str());
                report(LuaState);
            }
        }
        ++count;
    }
    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Loaded %u Lua scripts", count);
}

void Eluna::RegisterGlobals(lua_State* L)
{
    // Hooks
    lua_register(L, "RegisterServerHook", &LuaGlobalFunctions::RegisterServerHook);                         // RegisterServerHook(event, function)
    lua_register(L, "RegisterCreatureEvent", &LuaGlobalFunctions::RegisterCreatureEvent);                   // RegisterCreatureEvent(entry, event, function)
    lua_register(L, "RegisterCreatureGossipEvent", &LuaGlobalFunctions::RegisterCreatureGossipEvent);       // RegisterCreatureGossipEvent(entry, event, function)
    lua_register(L, "RegisterGameObjectEvent", &LuaGlobalFunctions::RegisterGameObjectEvent);               // RegisterGameObjectEvent(entry, event, function)
    lua_register(L, "RegisterGameObjectGossipEvent", &LuaGlobalFunctions::RegisterGameObjectGossipEvent);   // RegisterGameObjectGossipEvent(entry, event, function)
    lua_register(L, "RegisterItemEvent", &LuaGlobalFunctions::RegisterItemEvent);                           // RegisterItemEvent(entry, event, function)
    lua_register(L, "RegisterItemGossipEvent", &LuaGlobalFunctions::RegisterItemGossipEvent);               // RegisterItemGossipEvent(entry, event, function)
    lua_register(L, "RegisterPlayerGossipEvent", &LuaGlobalFunctions::RegisterPlayerGossipEvent);           // RegisterPlayerGossipEvent(menu_id, event, function)

    // Getters
    lua_register(L, "GetLuaEngine", &LuaGlobalFunctions::GetLuaEngine);                     // GetLuaEngine() - Returns ElunaEngine
    lua_register(L, "GetLUAEngine", &LuaGlobalFunctions::GetLuaEngine);                     // GetLUAEngine() - Returns ElunaEngine
    lua_register(L, "GetCoreVersion", &LuaGlobalFunctions::GetCoreVersion);                 // GetCoreVersion() - Returns core version string
    lua_register(L, "GetQuest", &LuaGlobalFunctions::GetQuest);                             // GetQuest(questId) - Returns quest object
    lua_register(L, "GetPlayerByGUID", &LuaGlobalFunctions::GetPlayerByGUID);               // GetPlayerByGUID(guid) - Returns player object by GUID
    lua_register(L, "GetPlayerByName", &LuaGlobalFunctions::GetPlayerByName);               // GetPlayerByName(name) - Returns player object by player name
    lua_register(L, "GetGameTime", &LuaGlobalFunctions::GetGameTime);                       // GetGameTime() - Returns game time
    lua_register(L, "GetPlayersInWorld", &LuaGlobalFunctions::GetPlayersInWorld);           // GetPlayersInWorld([team, onlyGM]) - Returns a table with all player objects. Team can be 0 for ally, 1 for horde and 2 for neutral
    lua_register(L, "GetPlayersInMap", &LuaGlobalFunctions::GetPlayersInMap);               // GetPlayersInWorld(mapId[, instanceId, team]) - Returns a table with all player objects in map. Team can be 0 for ally, 1 for horde and 2 for neutral
    lua_register(L, "GetGuildByName", &LuaGlobalFunctions::GetGuildByName);                 // GetGuildByName(name) - Returns guild object by the guild name
    lua_register(L, "GetGuildByLeaderGUID", &LuaGlobalFunctions::GetGuildByLeaderGUID);     // GetGuildByLeaderGUID(guid) - Returns guild by it's leader's guid
    lua_register(L, "GetPlayerCount", &LuaGlobalFunctions::GetPlayerCount);                 // GetPlayerCount() - Returns the server's player count
    lua_register(L, "FindUnit", &LuaGlobalFunctions::FindUnit);                             // FindUnit(guid) - Returns unit by it's guid
    lua_register(L, "GetPlayerGUID", &LuaGlobalFunctions::GetPlayerGUID);                   // GetPlayerGUID(lowguid) - Generates GUID (uint64) string from player lowguid UNDOCUMENTED
    lua_register(L, "GetItemGUID", &LuaGlobalFunctions::GetItemGUID);                       // GetItemGUID(lowguid) - Generates GUID (uint64) string from item lowguid UNDOCUMENTED
    lua_register(L, "GetObjectGUID", &LuaGlobalFunctions::GetObjectGUID);                   // GetObjectGUID(lowguid, entry) - Generates GUID (uint64) string from gameobject lowguid and entry UNDOCUMENTED
    lua_register(L, "GetUnitGUID", &LuaGlobalFunctions::GetUnitGUID);                       // GetUnitGUID(lowguid, entry) - Generates GUID (uint64) string from unit (creature) lowguid and entry UNDOCUMENTED
    lua_register(L, "GetGUIDLow", &LuaGlobalFunctions::GetGUIDLow);                         // GetGUIDLow(guid) - Returns GUIDLow (uint32) from guid (uint64 as string) UNDOCUMENTED
    lua_register(L, "GetGUIDType", &LuaGlobalFunctions::GetGUIDType);                       // GetGUIDType(guid) - Returns Type (uint32) from guid (uint64 as string) UNDOCUMENTED
    lua_register(L, "GetGUIDEntry", &LuaGlobalFunctions::GetGUIDEntry);                     // GetGUIDLow(guid) - Returns Entry (uint32) from guid (uint64 as string), may be always 0 UNDOCUMENTED
    lua_register(L, "bit_not", &LuaGlobalFunctions::bit_not);                               // bit_not(a) - Returns ~a UNDOCUMENTED
    lua_register(L, "bit_xor", &LuaGlobalFunctions::bit_xor);                               // bit_xor(a, b) - Returns a ^ b UNDOCUMENTED
    lua_register(L, "bit_rshift", &LuaGlobalFunctions::bit_rshift);                         // bit_rshift(a, b) - Returns a >> b UNDOCUMENTED
    lua_register(L, "bit_lshift", &LuaGlobalFunctions::bit_lshift);                         // bit_lshift(a, b) - Returns a << b UNDOCUMENTED
    lua_register(L, "bit_or", &LuaGlobalFunctions::bit_or);                                 // bit_or(a, b) - Returns a | b UNDOCUMENTED
    lua_register(L, "bit_and", &LuaGlobalFunctions::bit_and);                               // bit_and(a, b) - Returns a & b UNDOCUMENTED
    lua_register(L, "GetItemLink", &LuaGlobalFunctions::GetItemLink);                       // GetItemLink(entry[, localeIndex]) - Returns the shift clickable link of the item. Item name translated if translate available for provided locale index UNDOCUMENTED

    // Other
    lua_register(L, "ReloadEluna", &LuaGlobalFunctions::ReloadEluna);                       // ReloadEluna() - Reload's Eluna engine
    lua_register(L, "SendWorldMessage", &LuaGlobalFunctions::SendWorldMessage);             // SendWorldMessage(msg) - Sends a broadcast message to everyone
    lua_register(L, "WorldDBQuery", &LuaGlobalFunctions::WorldDBQuery);                     // WorldDBQuery(sql) - Executes given SQL query to world database instantly and returns a QueryResult object
    lua_register(L, "WorldDBExecute", &LuaGlobalFunctions::WorldDBExecute);                 // WorldDBExecute(sql) - Executes given SQL query to world database (not instant)
    lua_register(L, "CharDBQuery", &LuaGlobalFunctions::CharDBQuery);                       // CharDBQuery(sql) - Executes given SQL query to character database instantly and returns a QueryResult object
    lua_register(L, "CharDBExecute", &LuaGlobalFunctions::CharDBExecute);                   // CharDBExecute(sql) - Executes given SQL query to character database (not instant)
    lua_register(L, "AuthDBQuery", &LuaGlobalFunctions::AuthDBQuery);                       // AuthDBQuery(sql) - Executes given SQL query to auth/logon database instantly and returns a QueryResult object
    lua_register(L, "AuthDBExecute", &LuaGlobalFunctions::AuthDBExecute);                   // AuthDBExecute(sql) - Executes given SQL query to auth/logon database (not instant)
    lua_register(L, "CreateLuaEvent", &LuaGlobalFunctions::CreateLuaEvent);                 // CreateLuaEvent(function, delay, calls) - Creates a timed event. Returns Event ID
    lua_register(L, "RegisterTimedEvent", &LuaGlobalFunctions::CreateLuaEvent);             // RegisterTimedEvent(function, delay, calls) - Creates a timed event. Returns Event ID
    lua_register(L, "DestroyEventByID", &LuaGlobalFunctions::DestroyEventByID);             // DestroyEventByID(eventId) - Removes a global timed event by it's ID
    lua_register(L, "DestroyEvents", &LuaGlobalFunctions::DestroyEvents);                   // DestroyEvents([allEvents]) - Removes all global timed events. Removes all timed events (creature and gameobject) if allEvents is true
    lua_register(L, "PerformIngameSpawn", &LuaGlobalFunctions::PerformIngameSpawn);         // PerformIngameSpawn(spawntype, entry, mapid, x, y, z, o[, save, DurOrResptime, phase]) - spawntype: 1 Creature, 2 Object. DurOrResptime is respawntime for gameobjects and despawntime for creatures if creature is not saved. Returns spawned creature/gameobject
    lua_register(L, "CreatePacket", &LuaGlobalFunctions::CreatePacket);                     // CreatePacket(opcode, size) - Creates a new packet object
    lua_register(L, "AddVendorItem", &LuaGlobalFunctions::AddVendorItem);                   // AddVendorItem(entry, itemId, maxcount, incrtime, extendedcost[, persist(bool)]) - Adds an item to vendor entry. If persist is false, wont be saved to database.
    lua_register(L, "VendorRemoveItem", &LuaGlobalFunctions::VendorRemoveItem);             // VendorRemoveItem(entry, item[, persist(bool)]) - Removes an item from vendor entry. If persist is false, wont be saved to database.
    lua_register(L, "VendorRemoveAllItems", &LuaGlobalFunctions::VendorRemoveAllItems);     // VendorRemoveAllItems(entry[, persist(bool)]) - Removes all items from vendor entry. If persist is false, wont be saved to database.
    lua_register(L, "Kick", &LuaGlobalFunctions::Kick);                                     // Kick(player) - Kicks given player
    lua_register(L, "Ban", &LuaGlobalFunctions::Ban);                                       // Ban(banMode(integer), nameOrIP(string), duration(string), reason(string), player(whoBanned)) - Banmode: 0 account, 1 character, 2 IP
    lua_register(L, "SaveAllPlayers", &LuaGlobalFunctions::SaveAllPlayers);                 // SaveAllPlayers() - Saves all players
    lua_register(L, "SendMail", &LuaGlobalFunctions::SendMail);                             // SendMail(subject, text, receiverLowGUID[, sender, stationary, delay, itemEntry, itemAmount, itemEntry2, itemAmount2...]) - Sends a mail to player with lowguid. use nil to use default values on optional arguments. Sender is an optional player object. UNDOCUMENTED
    lua_register(L, "AddTaxiPath", &LuaGlobalFunctions::AddTaxiPath);                       // AddTaxiPath(pathTable, mountA, mountH[, price, pathId]) - Adds a new taxi path. Returns the path's ID. Will replace an existing path if pathId provided and already used. path table structure: T = {{map, x, y, z[, actionFlag, delay, arrivalEvId, departEvId]}, {...}, ...} UDOCUMENTED
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
        TC_LOG_ERROR(LOG_FILTER_SERVER_LOADING, "Eluna Nova::No `scripts` directory found!");
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
            TC_LOG_ERROR(LOG_FILTER_SERVER_LOADING, "Eluna Nova::Error opening `%s`", _path);
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

    if (lua_type(LuaState, top-params) == LUA_TFUNCTION) // is function
    {
        if (lua_pcall(LuaState,params,res,0) )
        {
            report(LuaState);
            ret = false;
        }
    }
    else
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
void Eluna::PushULong(lua_State* L, uint64 l)
{
    if (!L) L = LuaState;
    std::ostringstream ss;
    ss << std::hex << l;
    sEluna->PushString(L, ss.str().c_str());
}

void Eluna::PushLong(lua_State* L, int64 l)
{
    if (!L) L = LuaState;
    std::ostringstream ss;
    ss << std::hex << l;
    sEluna->PushString(L, ss.str().c_str());
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

WorldObject* Eluna::CHECK_WORLDOBJECT(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<WorldObject>::check(LuaState, narg);
    else
        return ElunaTemplate<WorldObject>::check(L, narg);
}

Unit * Eluna::CHECK_UNIT(lua_State* L, int narg)
{
    return CHECK_WORLDOBJECT(L, narg)->ToUnit();
}

Player * Eluna::CHECK_PLAYER(lua_State* L, int narg)
{
    return CHECK_WORLDOBJECT(L, narg)->ToPlayer();
}

Creature * Eluna::CHECK_CREATURE(lua_State* L, int narg)
{
    return CHECK_WORLDOBJECT(L, narg)->ToCreature();
}

GameObject* Eluna::CHECK_OBJECT(lua_State* L, int narg)
{
    return CHECK_WORLDOBJECT(L, narg)->ToGameObject();
}

WorldPacket* Eluna::CHECK_PACKET(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<WorldPacket>::check(LuaState, narg);
    else
        return ElunaTemplate<WorldPacket>::check(L, narg);
}

Quest* Eluna::CHECK_QUEST(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<Quest>::check(LuaState, narg);
    else
        return ElunaTemplate<Quest>::check(L, narg);
}

Spell* Eluna::CHECK_SPELL(lua_State* L, int narg)
{
    if (!L)
        return ElunaTemplate<Spell>::check(LuaState, narg);
    else
        return ElunaTemplate<Spell>::check(L, narg);
}

uint64 Eluna::CHECK_ULONG(lua_State* L, int narg)
{
    const char* c_str;
    if (!L)
        c_str = luaL_optstring(LuaState, narg, "0");
    else
        c_str = luaL_optstring(L, narg, "0");
    return strtoul(c_str, NULL, 0);
}

int64 Eluna::CHECK_LONG(lua_State* L, int narg)
{
    const char* c_str;
    if (!L)
        c_str = luaL_optstring(LuaState, narg, "0");
    else
        c_str = luaL_optstring(L, narg, "0");
    return strtol(c_str, NULL, 0);
}

// Saves the function reference ID given to the register type's store for given entry under the given event
void Eluna::Register(uint8 regtype, uint32 id, uint32 evt, int functionRef)
{
    switch(regtype)
    {
    case REGTYPE_SERVER:
        if (evt < SERVER_EVENT_COUNT)
        {
            ServerEventBindings[evt].push_back(functionRef);
            return;
        }
        break;

    case REGTYPE_CREATURE:
        if (evt < CREATURE_EVENT_COUNT)
        {
            if (!sObjectMgr->GetCreatureTemplate(id))
            {
                luaL_error(LuaState, "Couldn't find a creature with (ID: %d)!", id);
                return;
            }

            sEluna->CreatureEventBindings->Insert(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_CREATURE_GOSSIP:
        if (evt < GOSSIP_EVENT_COUNT)
        {
            if (!sObjectMgr->GetCreatureTemplate(id))
            {
                luaL_error(LuaState, "Couldn't find a creature with (ID: %d)!", id);
                return;
            }

            sEluna->CreatureGossipBindings->Insert(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_GAMEOBJECT:
        if (evt < GAMEOBJECT_EVENT_COUNT)
        {
            if (!sObjectMgr->GetGameObjectTemplate(id))
            {
                luaL_error(LuaState, "Couldn't find a gameobject with (ID: %d)!", id);
                return;
            }

            sEluna->GameObjectEventBindings->Insert(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_GAMEOBJECT_GOSSIP:
        if (evt < GOSSIP_EVENT_COUNT)
        {
            if (!sObjectMgr->GetGameObjectTemplate(id))
            {
                luaL_error(LuaState, "Couldn't find a gameobject with (ID: %d)!", id);
                return;
            }

            sEluna->GameObjectGossipBindings->Insert(id, evt, functionRef);
            return;
        }
        break;

    case REGTYPE_ITEM:
        if (evt < ITEM_EVENT_COUNT)
        {
            if (!sObjectMgr->GetItemTemplate(id))
            {
                luaL_error(LuaState, "Couldn't find a item with (ID: %d)!", id);
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
                luaL_error(LuaState, "Couldn't find a item with (ID: %d)!", id);
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
        luaL_error(LuaState, "Unknown register type (regtype %d, id %d, event %d)", regtype, id, evt);
        return;
    }
    luaL_error(LuaState, "Unknown event type (regtype %d, id %d, event %d)", regtype, id, evt);
}
void Eluna::ElunaBind::Clear()
{
    for (ElunaEntryMap::iterator itr = Bindings.begin(); itr != Bindings.end(); ++itr)
    {
        for (ElunaBindingMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            luaL_unref(sEluna->LuaState, LUA_REGISTRYINDEX, it->second);
        itr->second.clear();
    }
    Bindings.clear();
}
void Eluna::ElunaBind::Insert(uint32 entryId, uint32 eventId, int funcRef)
{
    if (Bindings[entryId][eventId])
    {
        luaL_error(sEluna->LuaState, "A function is already registered for entry (%d) event (%d)", entryId, eventId);
        luaL_unref(sEluna->LuaState, LUA_REGISTRYINDEX, funcRef); // free the unused ref
    }
    else
        Bindings[entryId][eventId] = funcRef;
}

UNORDERED_MAP<uint64, Eluna::LuaEventMap*> Eluna::LuaEventMap::LuaEventMaps;
UNORDERED_MAP<int, Eluna::LuaEventData*> Eluna::LuaEventData::LuaEvents;
UNORDERED_MAP<uint64, std::set<int> > Eluna::LuaEventData::EventIDs;

void Eluna::LuaEventMap::ScriptEventsResetAll()
{
    // GameObject && Creature events reset
    if (!LuaEventMaps.empty())
        for (UNORDERED_MAP<uint64, LuaEventMap*>::iterator itr = LuaEventMaps.begin(); itr != LuaEventMaps.end(); ++itr)
            if (itr->second)
                itr->second->ScriptEventsReset();
    // Global events reset
    sEluna->LuaWorldAI->ScriptEventsReset();
}
void Eluna::LuaEventMap::ScriptEventsReset()
{
    _time = 0;
    if (ScriptEventsEmpty())
        return;
    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        luaL_unref(sEluna->LuaState, LUA_REGISTRYINDEX, itr->second.funcRef);
        ++itr;
    }
    _eventMap.clear();
}
void Eluna::LuaEventMap::ScriptEventCancel(int funcRef)
{
    if (ScriptEventsEmpty())
        return;

    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (funcRef == itr->second.funcRef)
        {
            luaL_unref(sEluna->LuaState, LUA_REGISTRYINDEX, itr->second.funcRef);
            _eventMap.erase(itr++);
        }
        else
            ++itr;
    }
}
void Eluna::LuaEventMap::ScriptEventsExecute()
{
    if (ScriptEventsEmpty())
        return;

    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (itr->first > _time)
        {
            ++itr;
            continue;
        }

        OnScriptEvent(itr->second.funcRef, itr->second.delay, itr->second.calls);

        if (itr->second.calls != 1)
        {
            if (itr->second.calls > 1)
                itr->second.calls = itr->second.calls-1;
            _eventMap.insert(EventStore::value_type(_time + itr->second.delay, itr->second));
        }
        else
            luaL_unref(sEluna->LuaState, LUA_REGISTRYINDEX, itr->second.funcRef);
        _eventMap.erase(itr++);
    }
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
    nodes[1] = path[path.size()-1].index;

    player->ActivateTaxiPathTo(nodes);
}
uint32 LuaTaxiMgr::AddPath(std::list<TaxiPathNodeEntry> nodes, uint32 mountA, uint32 mountH, uint32 price, uint32 pathId)
{
    if (nodes.size() < 2)
        return 0;
    if (!pathId)
        pathId = sTaxiPathNodesByPath.size();
    if (sTaxiPathNodesByPath.size() <= pathId)
        sTaxiPathNodesByPath.resize(pathId+1);
    sTaxiPathNodesByPath[pathId].clear();
    sTaxiPathNodesByPath[pathId].resize(nodes.size());
    uint32 startNode = nodeId;
    uint32 index = 0;
    for (std::list<TaxiPathNodeEntry>::iterator it = nodes.begin(); it != nodes.end(); ++it)
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
    sTaxiPathSetBySource[startNode][nodeId-1] = TaxiPathBySourceAndDestination(pathId, price);
    return pathId;
}