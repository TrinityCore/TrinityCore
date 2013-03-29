#include "MapManager.h"
#include "SharedDefines.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "AccountMgr.h"

#ifndef __GLOBAL_METHODS_ELUNA
#define __GLOBAL_METHODS_ELUNA

namespace LuaGlobalFunctions
{
    // RegisterServerHook(ev, func)
    static int RegisterServerHook(lua_State* L)
    {
        int functionRef = 0;
        lua_settop(L, 2);
        uint32 ev = luaL_checkunsigned(L, 1);
        const char* typeName = luaL_typename(L, 2);

        if (ev == 0 || !typeName)
            return 0;

        if (!strcmp(typeName, "function"))
            functionRef = lua_ref(L, true);

        if (functionRef > 0)
            sEluna->Register(REGTYPE_SERVER, 0, ev, functionRef);
        return 0;
    }

    //RegisterCreatureGossipEvent(ev, func)
    static int RegisterCreatureGossipEvent(lua_State* L)
    {
        int functionRef = 0;
        lua_settop(L, 3);
        uint32 entry = luaL_checkint(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        const char* typeName = luaL_typename(L, 3);

        if (ev == 0 || !typeName)
            return 0;

        if (!strcmp(typeName, "function"))
            functionRef = lua_ref(L, true);

        if (functionRef > 0)
            sEluna->Register(REGTYPE_CREATURE_GOSSIP, entry, ev, functionRef);
        return 0;
    }

    // RegisterGameObjectGossipEvent(entry, event, function)
    static int RegisterGameObjectGossipEvent(lua_State* L)
    {
        int functionRef = 0;
        lua_settop(L, 3);
        uint32 entry = luaL_checkint(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        const char* typeName = luaL_typename(L, 3);

        if (ev == 0 || !typeName)
            return 0;

        if (!strcmp(typeName, "function"))
            functionRef = lua_ref(L, true);

        if (functionRef > 0)
            sEluna->Register(REGTYPE_GAMEOBJECT_GOSSIP, entry, ev, functionRef);
        return 0;
    }

    // RegisterItemEvent(entry, event, function)
    static int RegisterItemEvent(lua_State* L)
    {
        int functionRef = 0;
        lua_settop(L, 3);
        uint32 entry = luaL_checkint(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        const char* typeName = luaL_typename(L, 3);

        if (ev == 0 || !typeName)
            return 0;

        if (!strcmp(typeName, "function"))
            functionRef = lua_ref(L, true);

        if (functionRef > 0)
            sEluna->Register(REGTYPE_ITEM, entry, ev, functionRef);
        return 0;
    }

    // RegisterItemGossipEvent(entry, event, function)
    static int RegisterItemGossipEvent(lua_State* L)
    {
        int functionRef = 0;
        lua_settop(L, 3);
        uint32 entry = luaL_checkint(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        const char* typeName = luaL_typename(L, 3);

        if (ev == 0 || !typeName)
            return 0;

        if (!strcmp(typeName, "function"))
            functionRef = lua_ref(L, true);

        if (functionRef > 0)
            sEluna->Register(REGTYPE_ITEM_GOSSIP, entry, ev, functionRef);
        return 0;
    }

    // RegisterPlayerGossipEvent(menu_id, event, function)
    static int RegisterPlayerGossipEvent(lua_State* L)
    {
        int functionRef = 0;
        lua_settop(L, 3);
        uint32 menu_id = luaL_checkint(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        const char* typeName = luaL_typename(L, 3);

        if (ev == 0 || !typeName)
            return 0;

        if (!strcmp(typeName, "function"))
            functionRef = lua_ref(L, true);

        if (functionRef > 0)
            sEluna->Register(REGTYPE_PLAYER_GOSSIP, menu_id, ev, functionRef);
        return 0;
    }

    // RegisterCreatureEvent(entry, ev, func)
    static int RegisterCreatureEvent(lua_State* L)
    {
        int functionRef = 0;
        lua_settop(L, 3);
        uint32 entry = luaL_checkint(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        const char* typeName = luaL_typename(L, 3);
        if (ev == 0 || !typeName)
            return 0;

        if (!strcmp(typeName, "function"))
            functionRef = lua_ref(L, true);

        if (functionRef > 0)
            sEluna->Register(REGTYPE_CREATURE, entry, ev, functionRef);
        return 0;
    }

    // RegisterGameObjectEvent(entry, event, func)
    static int RegisterGameObjectEvent(lua_State* L)
    {
        int functionRef = 0;
        lua_settop(L, 3);
        uint32 entry = luaL_checkint(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        const char* typeName = luaL_typename(L, 3);
        if (ev == 0 || !typeName)
            return 0;

        if (!strcmp(typeName, "function"))
            functionRef = lua_ref(L, true);

        if (functionRef > 0)
            sEluna->Register(REGTYPE_GAMEOBJECT, entry, ev, functionRef);
        return 0;
    }

    // GetLuaEngine() - Gets lua engine name
    static int GetLuaEngine(lua_State* L)
    {
        sEluna->PushString(L, "Eluna Nova 0.1"); // remove version?
        return 1;
    }

    // ReloadEluna() - Gets core version as a string
    static int GetCoreVersion(lua_State* L)
    {
        sEluna->PushString(L, _FULLVERSION);
        return 1;
    }

    // GetQuest(questId)
    static int GetQuest(lua_State* L)
    {
        uint32 questId = luaL_checkunsigned(L, 1);
        if (!questId)
            return 0;

        sEluna->PushQuest(L, sObjectMgr->GetQuestTemplate(questId));
        return 1;
    }

    // ReloadEluna() - Reloads eluna
    static int ReloadEluna(lua_State* L)
    {
        sEluna->StartEluna(true);
        return 0;
    }

    // GetPlayerByGUID(guid) - Gets Player object by its guid
    static int GetPlayerByGUID(lua_State* L)
    {
        uint32 guidLow = luaL_checkunsigned(L, 1);
        sEluna->PushUnit(L, sObjectAccessor->FindPlayer(MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER)));
        return 1;
    }

    // GetPlayerByName("name") - Gets player object by name
    static int GetPlayerByName(lua_State* L)
    {
        const char* message = luaL_checkstring(L, 1);
        sEluna->PushUnit(L, sObjectAccessor->FindPlayerByName(message));
        return 1;
    }

    // GetGameTime() - Gets ingame time as seconds (server time?)
    static int GetGameTime(lua_State* L)
    {
        sEluna->PushUnsigned(L, sWorld->GetGameTime());
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
                    sEluna->PushUnsigned(L, i);
                    sEluna->PushUnit(L, player);
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
        if (!map)
            return 0;

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        Map::PlayerList const& players = map->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player* player = itr->getSource();
            if (!player)
                continue;
            if (player->GetSession() && (team >= TEAM_NEUTRAL || player->GetTeamId() == team))
            {
                ++i;
                sEluna->PushUnsigned(L, i);
                sEluna->PushUnit(L, player);
                lua_settable(L, tbl);
            }
        }

        lua_settop(L, tbl);
        return 1;
    }

    // WorldDBQuery("sql") - Executes SQL to world database and returns the query Result or nil (instant)
    static int WorldDBQuery(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if (!query)
            return 0;

        QueryResult Result = WorldDatabase.Query(query);
        if (!Result)
            return 0;

        sEluna->PushQueryResult(L, new QueryResult(Result));
        return 1;
    }

    // WorldDBExecute("sql") - Executes SQL to world database (not instant)
    static int WorldDBExecute(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if (!query)
            return 0;

        WorldDatabase.Execute(query);
        return 0;
    }

    // CharDBQuery("sql") - Executes SQL to characters database and returns the query Result or nil (instant)
    static int CharDBQuery(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if (!query)
            return 0;

        QueryResult Result = CharacterDatabase.Query(query);
        if (!Result)
            return 0;

        sEluna->PushQueryResult(L, new QueryResult(Result));
        return 1;
    }

    // CharDBExecute("sql") - Executes SQL to characters database (not instant)
    static int CharDBExecute(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if (!query)
            return 0;

        CharacterDatabase.Execute(query);
        return 0;
    }

    // AuthDBQuery("sql") - Executes SQL to auth database and returns the query Result or nil (instant)
    static int AuthDBQuery(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if (!query)
            return 0;

        QueryResult Result = LoginDatabase.Query(query);
        if (!Result)
            return 0;

        sEluna->PushQueryResult(L, new QueryResult(Result));
        return 1;
    }

    // AuthDBExecute("sql") - Executes SQL to auth database (not instant)
    static int AuthDBExecute(lua_State* L)
    {
        const char* query = luaL_checkstring(L, 1);
        if (!query)
            return 0;

        LoginDatabase.Execute(query);
        return 0;
    }

    // GetGuildByName("name") - Gets guild object
    static int GetGuildByName(lua_State* L)
    {
        const char* name = luaL_checkstring(L, 1);
        sEluna->PushGuild(L, sGuildMgr->GetGuildByName(name));
        return 1;
    }

    // GetGuildByLeaderGUID(leaderGUID) - Gets guild object
    static int GetGuildByLeaderGUID(lua_State* L)
    {
        uint32 guidLow = luaL_checkunsigned(L, 1);
        sEluna->PushGuild(L, sGuildMgr->GetGuildByLeader(MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER)));
        return 1;
    }

    // GetPlayerCount() - Gets server player count
    static int GetPlayerCount(lua_State* L)
    {
        sEluna->PushUnsigned(L, sWorld->GetPlayerCount());
        return 1;
    }

    // FindUnit(guid, entry)
    static int FindUnit(lua_State* L)
    {
        uint32 guidLow = luaL_checkunsigned(L, 1);
        uint32 entry = luaL_checkunsigned(L, 2);
        sEluna->PushUnit(L, sObjectAccessor->FindUnit(MAKE_NEW_GUID(guidLow, entry, HIGHGUID_UNIT)));
        return 1;
    }

    // CreateLuaEvent(function, delay, calls) - Creates a timed event. Calls set to 0 will call inf returns eventID.
    static int CreateLuaEvent(lua_State* L)
    {
        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);
        if (!strcmp(luaL_typename(L, 1), "function") || delay > 0)
        {
            lua_settop(L, 1);
            int functionRef = lua_ref(L, true);
            sEluna->LuaWorldAI->ScriptEventCreate(functionRef, delay, repeats);
            sEluna->PushInteger(L, functionRef);
        }
        else
            return 0;
        return 1;
    }

    // DestroyEventByID(eventID) - removes all global lua events with eventid
    static int DestroyEventByID(lua_State* L)
    {
        int functionRef = luaL_checkinteger(L, 1);
        sEluna->LuaWorldAI->ScriptEventCancel(functionRef);
        return 0;
    }

    // DestroyEvents([all_events]) - removes all global lua events, if all_events is true, removes creature and gameobject events too
    static int DestroyEvents(lua_State* L)
    {
        bool all_Events = luaL_optbool(L, 1, false);

        if (all_Events)
            Eluna::LuaEventMap::ScriptEventsResetAll();
        else
            sEluna->LuaWorldAI->ScriptEventsReset();
        return 0;
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
        if (!phase)
            return 0;

        Map* map = sMapMgr->FindMap(mapID, 0);
        if (!map)
            return 0;

        Position pos = {x,y,z,o};

        if (spawntype == 1) // spawn creature
        {
            if (save)
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
                sEluna->PushUnit(L, creature);
            }
            else
            {
                TempSummon* creature = map->SummonCreature(entry, pos, NULL, durorresptime);
                if (!creature)
                    return 0;

                if (durorresptime)
                    creature->SetTempSummonType(TEMPSUMMON_TIMED_OR_DEAD_DESPAWN);
                else
                    creature->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);

                sEluna->PushUnit(L, creature);
            }

            return 1;
        }

        if (spawntype == 2) // Spawn object
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

            if (save)
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
            sEluna->PushGO(L, object);
            return 1;
        }

        return 0;
    }

    // CreatePacket(opcode, size)
    static int CreatePacket(lua_State* L)
    {
        uint16 opcode = luaL_checkunsigned(L, 1);
        size_t size = luaL_checkunsigned(L, 2);

        if (opcode >= NUM_MSG_TYPES)
            luaL_error(L, "Eluna Nova:: Opcode %d is greater than the max Opcode type (%d)!", opcode, NUM_MSG_TYPES);
        else
        {
            WorldPacket* _packet = new WorldPacket(opcode, size);
            sEluna->PushPacket(L, _packet);
            return 1;
        }
        return 0;
    }

    // AddVendorItem(entry, itemId, maxcount, incrtime, extendedcost, persist(bool))
    static int AddVendorItem(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 item = luaL_checkunsigned(L, 2);
        int maxcount = luaL_checkinteger(L, 3);
        uint32 incrtime = luaL_checkunsigned(L, 4);
        uint32 extendedcost = luaL_checkunsigned(L, 5);
        bool persist = luaL_optbool(L, 6, true);
        if (!sObjectMgr->GetCreatureTemplate(entry))
        {
            sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a creature with (ID: %d)!", entry);
            return 0;
        }

        if (!sObjectMgr->IsVendorItemValid(entry, item, maxcount, incrtime, extendedcost))
            return 0;
        sObjectMgr->AddVendorItem(entry, item, maxcount, incrtime, extendedcost, persist);
        return 0;
    }

    // VendorRemoveItem(entry, item, persist(bool), otherNpcFlag(optional-uint))
    static int VendorRemoveItem(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 item = luaL_checkunsigned(L, 2);
        bool persist = luaL_optbool(L, 3, true);
        uint32 otherFlag = luaL_optunsigned(L, 4, UNIT_NPC_FLAG_VENDOR+1);
        if (!sObjectMgr->GetCreatureTemplate(entry))
        {
            sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a creature with (ID: %d)!", entry);
            return 0;
        }

        CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(entry);
        if (!((cInfo->npcflag | otherFlag) & UNIT_NPC_FLAG_VENDOR))
            return 0;

        if (!sObjectMgr->RemoveVendorItem(entry, item, persist))
            return 0;
        return 0;
    }

    // VendorRemoveAllItems(creature, persist(bool))
    static int VendorRemoveAllItems(lua_State* L)
    {
        Creature* creature = sEluna->CHECK_CREATURE(L, 1);
        bool persist = luaL_optbool(L, 2, true);
        if (!creature || !creature->IsInWorld())
            return 0;

        VendorItemData const* items = creature->GetVendorItems();
        if (!items || items->Empty())
            return 0;

        uint32 vendorItems[200];
        uint32 i = 0;
        for (VendorItemList::const_iterator itr = items->m_items.begin(); itr != items->m_items.end(); ++itr)
        {
            vendorItems[i] = (*itr)->item;
            i++;
        }

        for (i = 0; i < items->GetItemCount(); i++)
            sObjectMgr->RemoveVendorItem(creature->GetEntry(), vendorItems[i], persist);
        return 0;
    }

    // Kick(player)
    static int Kick(lua_State* L)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;
        player->GetSession()->KickPlayer();
        return 0;
    }

    // Ban(banMode(integer), nameOrIP(string), duration(string), reason(string), player(whoBanned))
    static int Ban(lua_State* L)
    {
        int banMode = luaL_checkint(L, 1);
        std::string nameOrIP = luaL_checkstring(L, 2);
        const char* duration = luaL_checkstring(L, 3);
        const char* reason = luaL_checkstring(L, 4);
        Player* whoBanned = sEluna->CHECK_PLAYER(L, 5);
        if (!whoBanned)
            return 0;

        switch (banMode)
        {
        case 0:
            if (!AccountMgr::normalizeString(nameOrIP))
            {
                ChatHandler(whoBanned->GetSession()).PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, nameOrIP.c_str());
                ChatHandler(whoBanned->GetSession()).SetSentErrorMessage(true);
                return 0;
            }
            else
                banMode = BAN_ACCOUNT;
            break;
        case 1:
            if (!normalizePlayerName(nameOrIP))
            {
                ChatHandler(whoBanned->GetSession()).SendSysMessage(LANG_PLAYER_NOT_FOUND);
                ChatHandler(whoBanned->GetSession()).SetSentErrorMessage(true);
                return 0;
            }
            else
                banMode = BAN_CHARACTER;
            break;
        case 2:
            if (!IsIPAddress(nameOrIP.c_str()))
                return 0;
            else
                banMode = BAN_IP;
            break;
        }

        switch (sWorld->BanAccount((BanMode)banMode, nameOrIP, duration, reason, whoBanned->GetSession() ? whoBanned->GetName() : ""))
        {
        case BAN_SUCCESS:
            if (atoi(duration) > 0)
                ChatHandler(whoBanned->GetSession()).PSendSysMessage(LANG_BAN_YOUBANNED, nameOrIP.c_str(), secsToTimeString(TimeStringToSecs(duration), true).c_str(), reason);
            else
                ChatHandler(whoBanned->GetSession()).PSendSysMessage(LANG_BAN_YOUPERMBANNED, nameOrIP.c_str(), reason);
            break;
        case BAN_SYNTAX_ERROR:
            return 0;
        case BAN_NOTFOUND:
            switch((BanMode)banMode)
            {
            default:
                ChatHandler(whoBanned->GetSession()).PSendSysMessage(LANG_BAN_NOTFOUND, "account", nameOrIP.c_str());
                break;
            case BAN_CHARACTER:
                ChatHandler(whoBanned->GetSession()).PSendSysMessage(LANG_BAN_NOTFOUND, "character", nameOrIP.c_str());
                break;
            case BAN_IP:
                ChatHandler(whoBanned->GetSession()).PSendSysMessage(LANG_BAN_NOTFOUND, "ip", nameOrIP.c_str());
                break;
            }
            ChatHandler(whoBanned->GetSession()).SetSentErrorMessage(true);
            return 0;
        }
        return 0;
    }

    // SaveAllPlayers()
    static int SaveAllPlayers(lua_State* L)
    {
        sObjectAccessor->SaveAllPlayers();
        return 0;
    }
}
#endif