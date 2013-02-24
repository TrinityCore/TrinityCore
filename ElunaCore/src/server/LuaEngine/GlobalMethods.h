#include "ScriptPCH.h"
#ifndef __GLOBAL_METHODS_ELUNA
#define __GLOBAL_METHODS_ELUNA

#include "SystemConfig.h"
#include "World.h"
#include "MapManager.h"
#include "GuildMgr.h"
#include "ObjectAccessor.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

namespace LuaGlobalFunctions
{
    // GetLuaEngine() - Gets lua engine name
    static int GetLuaEngine(lua_State* L)
    {
        Eluna::get()->PushString(L, "Eluna Nova 0.1"); // remove version?
        return 1;
    }
    
    // ReloadEluna() - Gets core version as string
    static int GetCoreVersion(lua_State* L)
    {
        Eluna::get()->PushString(L, _FULLVERSION);
        return 1;
    }
    
    // ReloadEluna() - Reloads eluna
    static int ReloadEluna(lua_State* L)
    {
        Eluna::get()->Restart();
        return 0;
    }
    
    // GetPlayerByGUID(guid) - Gets Player object by its guid
    static int GetPlayerByGUID(lua_State* L)
    {
        uint32 guidLow = luaL_checkunsigned(L, 1);
        Eluna::get()->PushUnit(L, sObjectAccessor->FindPlayer(MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER)));
        return 1;
    }
    
    // GetPlayerByName("name") - Gets player object by name
    static int GetPlayerByName(lua_State* L)
    {
        const char* message = luaL_checkstring(L, 1);
        Eluna::get()->PushUnit(L, sObjectAccessor->FindPlayerByName(message));
        return 1;
    }
    
    // GetGameTime() - Gets ingame time as seconds (server time?)
    static int GetGameTime(lua_State* L)
    {
        Eluna::get()->PushUnsigned(L, sWorld->GetGameTime());
        return 1;
    }
    
    // SendWorldMessage("msg") - Sends a broadcast message to everyone
    static int SendWorldMessage(lua_State* L)
    {
        const char* message = luaL_checkstring(L, 1);
        sWorld->SendServerMessage(SERVER_MSG_STRING, message);
        return 0;
    }
    
    // GetPlayersInWorld([team, onlyGM]) - Gets a table with players in world. Team can be 0 for ally, 1 for horde and 2 for both.
    static int GetPlayersInWorld(lua_State* L)
    {
        uint32 team = luaL_optunsigned(L, 1, TEAM_NEUTRAL);
        bool onlyGM = luaL_optbool(L, 2, false);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        SessionMap const& sessions = sWorld->GetAllSessions();
        for (SessionMap::const_iterator it = sessions.begin(); it != sessions.end(); ++it)
        {
            if (Player* player = it->second->GetPlayer())
            {
                if (player->GetSession() && ((team >= TEAM_NEUTRAL || player->GetTeamId() == team) && (!onlyGM || player->isGameMaster())))
                {
                    ++i;
                    Eluna::get()->PushUnsigned(L, i);
                    Eluna::get()->PushUnit(L, player);
                    lua_settable(L, tbl);
                }
            }
        }

        lua_settop(L, tbl); // push table to top of stack
        return 1;
    }
    
    // GetPlayersInMap(mapid[, instanceid, team]) - Gets a table with players in the map. Instanceid optional (0 for normal map). Team can be 0 for ally, 1 for horde and 2 for both
    static int GetPlayersInMap(lua_State* L)
    {
        uint32 mapID = luaL_checkunsigned(L, 1);
        uint32 instanceID = luaL_optunsigned(L, 2, 0);
        uint32 team = luaL_optunsigned(L, 3, TEAM_NEUTRAL);

        Map* map = sMapMgr->FindMap(mapID, instanceID);
        if(!map)
            return 0;

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        Map::PlayerList const& players = map->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player* player = itr->getSource();
            if(!player)
                continue;
            if (player->GetSession() && (team >= TEAM_NEUTRAL || player->GetTeamId() == team))
            {
                ++i;
                Eluna::get()->PushUnsigned(L, i);
                Eluna::get()->PushUnit(L, player);
                lua_settable(L, tbl);
            }
        }

        lua_settop(L, tbl);
        return 1;
    }
    
    // WorldDBQuery("sql") - Executes SQL to world database and returns the query result or nil (instant)
    static int WorldDBQuery(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if(!query)
            return 0;

        QueryResult result = WorldDatabase.Query(query);
        if(!result)
            return 0;

        Eluna::get()->PushQueryResult(L, new QueryResult(result));
        return 1;
    }

    // WorldDBExecute("sql") - Executes SQL to world database (not instant)
    static int WorldDBExecute(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if(!query)
            return 0;

        WorldDatabase.Execute(query);
        return 0;
    }
    
    // CharDBQuery("sql") - Executes SQL to characters database and returns the query result or nil (instant)
    static int CharDBQuery(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if(!query)
            return 0;

        QueryResult result = CharacterDatabase.Query(query);
        if(!result)
            return 0;

        Eluna::get()->PushQueryResult(L, new QueryResult(result));
        return 1;
    }

    // CharDBExecute("sql") - Executes SQL to characters database (not instant)
    static int CharDBExecute(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if(!query)
            return 0;

        CharacterDatabase.Execute(query);
        return 0;
    }
    
    // AuthDBQuery("sql") - Executes SQL to auth database and returns the query result or nil (instant)
    static int AuthDBQuery(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if(!query)
            return 0;

        QueryResult result = LoginDatabase.Query(query);
        if(!result)
            return 0;

        Eluna::get()->PushQueryResult(L, new QueryResult(result));
        return 1;
    }

    // AuthDBExecute("sql") - Executes SQL to auth database (not instant)
    static int AuthDBExecute(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if(!query)
            return 0;

        LoginDatabase.Execute(query);
        return 0;
    }
    
    // GetGuildByName("name") - Gets guild object
    static int GetGuildByName(lua_State* L)
    {
        const char* name = luaL_checkstring(L, 1);
        Eluna::get()->PushGuild(L, sGuildMgr->GetGuildByName(name));
        return 1;
    }
    
    // GetGuildByLeaderGUID(leaderGUID) - Gets guild object
    static int GetGuildByLeaderGUID(lua_State* L)
    {
        uint32 guidLow = luaL_checkunsigned(L, 1);
        Eluna::get()->PushGuild(L, sGuildMgr->GetGuildByLeader(MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER)));
        return 1;
    }
    
    // GetPlayerCount() - Gets server player count
    static int GetPlayerCount(lua_State* L)
    {
        Eluna::get()->PushUnsigned(L, sWorld->GetPlayerCount());
        return 1;
    }
    
    // CreateLuaEvent(function, delay, calls) - Creates a timed event. Calls set to 0 will call inf
    static int CreateLuaEvent(lua_State* L)
    {
        const char* typeName = luaL_typename(L, 1);
        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);
        if(!typeName)
            return 0;
        if(!strcmp(luaL_typename(L, 1), "function") || delay > 0)
        {
            int functionRef = lua_ref(L, true);
            Eluna::get()->_luaEventMgr->CreateLuaEvent(functionRef, delay, repeats);
            Eluna::get()->PushInteger(L, functionRef);
        }
        else
            return 0;
        return 1;
    }

    // PerformIngameSpawn(spawntype, entry, mapid, x, y, z, o[, save, DurOrResptime, phase])
    // spawntype: 1 Creature, 2 Object. DurOrResptime is respawntime for gameobjects and despawntime for creatures if creature is not saved
    static int PerformIngameSpawn(lua_State* L)
    {
        int spawntype = luaL_checkinteger(L, 1);
        uint32 entry = luaL_checkunsigned(L, 2);
        uint32 mapID = luaL_checkunsigned(L, 3);
        float x = luaL_checknumber(L, 4);
        float y = luaL_checknumber(L, 5);
        float z = luaL_checknumber(L, 6);
        float o = luaL_checknumber(L, 7);
        bool save = luaL_optbool(L, 8, false);
        uint32 durorresptime = luaL_optunsigned(L, 9, 0);
        uint32 phase = luaL_optunsigned(L, 10, PHASEMASK_NORMAL);

        if(!phase)
            return 0;

        Map* map = sMapMgr->FindMap(mapID, 0);
        if(!map)
            return 0;

        Position pos = {x,y,z,o};

        if(spawntype == 1) // spawn creature
        {
            if(save)
            {
                Creature* creature = new Creature();
                if (!creature->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), map, phase, entry, 0, 0, x, y, z, o))
                {
                    delete creature;
                    return 0;
                }

                creature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), phase);

                uint32 db_guid = creature->GetDBTableGUIDLow();

                if (!creature->LoadCreatureFromDB(db_guid, map))
                {
                    delete creature;
                    return 0;
                }

                sObjectMgr->AddCreatureToGrid(db_guid, sObjectMgr->GetCreatureData(db_guid));
                Eluna::get()->PushUnit(L, creature);
            }
            else
            {
                TempSummon* creature = map->SummonCreature(entry, pos, NULL, durorresptime);
                if(!creature)
                    return 0;

                if(durorresptime)
                    creature->SetTempSummonType(TEMPSUMMON_TIMED_OR_DEAD_DESPAWN);
                else
                    creature->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                
                Eluna::get()->PushUnit(L, creature);
            }

            return 1;
        }
        
        if(spawntype == 2) // Spawn object
        {

            const GameObjectTemplate* objectInfo = sObjectMgr->GetGameObjectTemplate(entry);
            if (!objectInfo)
                return 0;

            if (objectInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(objectInfo->displayId))
                return 0;

            GameObject* object = new GameObject;
            uint32 guidLow = sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT);

            if (!object->Create(guidLow, objectInfo->entry, map, phase, x, y, z, o, 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
            {
                delete object;
                return 0;
            }

            if (durorresptime)
                object->SetRespawnTime(durorresptime);

            if(save)
            {
                // fill the gameobject data and save to the db
                object->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), phase);

                // this will generate a new guid if the object is in an instance
                if (!object->LoadGameObjectFromDB(guidLow, map))
                {
                    delete object;
                    return false;
                }

                sObjectMgr->AddGameobjectToGrid(guidLow, sObjectMgr->GetGOData(guidLow));
            }
            else
                map->AddToMap(object);
            Eluna::get()->PushGO(L, object);
            return 1;
        }

        return 0;
    }
}
#endif