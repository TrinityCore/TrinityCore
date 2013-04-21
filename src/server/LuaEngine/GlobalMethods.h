#include "MapManager.h"
#include "SharedDefines.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "AccountMgr.h"

#ifndef __GLOBAL_METHODS_ELUNA
#define __GLOBAL_METHODS_ELUNA

namespace LuaGlobalFunctions
{
    // RegisterServerHook(event, function)
    static int RegisterServerHook(lua_State* L)
    {
        uint32 ev = luaL_checkunsigned(L, 1);
        lua_settop(L, 2);
        if (ev == 0 || !lua_isfunction(L, lua_gettop(L)))
            return 0;

        int functionRef = lua_ref(L, true);
        if (functionRef > 0)
            sEluna->Register(REGTYPE_SERVER, 0, ev, functionRef);
        return 0;
    }

    //RegisterCreatureGossipEvent(entry, event, function)
    static int RegisterCreatureGossipEvent(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        lua_settop(L, 3);
        if (ev == 0 || !lua_isfunction(L, lua_gettop(L)))
            return 0;

        int functionRef = lua_ref(L, true);
        if (functionRef > 0)
            sEluna->Register(REGTYPE_CREATURE_GOSSIP, entry, ev, functionRef);
        return 0;
    }

    // RegisterGameObjectGossipEvent(entry, event, function)
    static int RegisterGameObjectGossipEvent(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        lua_settop(L, 3);
        if (ev == 0 || !lua_isfunction(L, lua_gettop(L)))
            return 0;

        int functionRef = lua_ref(L, true);
        if (functionRef > 0)
            sEluna->Register(REGTYPE_GAMEOBJECT_GOSSIP, entry, ev, functionRef);
        return 0;
    }

    // RegisterItemEvent(entry, event, function)
    static int RegisterItemEvent(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        lua_settop(L, 3);
        if (ev == 0 || !lua_isfunction(L, lua_gettop(L)))
            return 0;

        int functionRef = lua_ref(L, true);
        if (functionRef > 0)
            sEluna->Register(REGTYPE_ITEM, entry, ev, functionRef);
        return 0;
    }

    // RegisterItemGossipEvent(entry, event, function)
    static int RegisterItemGossipEvent(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        lua_settop(L, 3);
        if (ev == 0 || !lua_isfunction(L, lua_gettop(L)))
            return 0;

        int functionRef = lua_ref(L, true);
        if (functionRef > 0)
            sEluna->Register(REGTYPE_ITEM_GOSSIP, entry, ev, functionRef);
        return 0;
    }

    // RegisterPlayerGossipEvent(menu_id, event, function)
    static int RegisterPlayerGossipEvent(lua_State* L)
    {
        uint32 menu_id = luaL_checkunsigned(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        lua_settop(L, 3);
        if (ev == 0 || !lua_isfunction(L, lua_gettop(L)))
            return 0;

        int functionRef = lua_ref(L, true);
        if (functionRef > 0)
            sEluna->Register(REGTYPE_PLAYER_GOSSIP, menu_id, ev, functionRef);
        return 0;
    }

    // RegisterCreatureEvent(entry, event, function)
    static int RegisterCreatureEvent(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        lua_settop(L, 3);
        if (ev == 0 || !lua_isfunction(L, lua_gettop(L)))
            return 0;

        int functionRef = lua_ref(L, true);
        if (functionRef > 0)
            sEluna->Register(REGTYPE_CREATURE, entry, ev, functionRef);
        return 0;
    }

    // RegisterGameObjectEvent(entry, event, function)
    static int RegisterGameObjectEvent(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 ev = luaL_checkunsigned(L, 2);
        lua_settop(L, 3);
        if (ev == 0 || !lua_isfunction(L, lua_gettop(L)))
            return 0;

        int functionRef = lua_ref(L, true);
        if (functionRef > 0)
            sEluna->Register(REGTYPE_GAMEOBJECT, entry, ev, functionRef);
        return 0;
    }

    // GetLuaEngine() - Gets lua engine name
    static int GetLuaEngine(lua_State* L)
    {
        sEluna->PushString(L, "ElunaEngine");
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
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        sEluna->PushUnit(L, sObjectAccessor->FindPlayer(guid));
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
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        sEluna->PushGuild(L, sGuildMgr->GetGuildByLeader(guid));
        return 1;
    }

    // GetPlayerCount() - Gets server player count
    static int GetPlayerCount(lua_State* L)
    {
        sEluna->PushUnsigned(L, sWorld->GetPlayerCount());
        return 1;
    }

    // FindUnit(guid)
    static int FindUnit(lua_State* L)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        sEluna->PushUnit(L, sObjectAccessor->FindUnit(guid));
        return 1;
    }

    // GetPlayerGUID(lowguid)
    static int GetPlayerGUID(lua_State* L)
    {
        uint32 lowguid = luaL_checkunsigned(L, 1);
        sEluna->PushULong(L, MAKE_NEW_GUID(lowguid, 0, HIGHGUID_PLAYER));
        return 1;
    }

    // GetItemGUID(lowguid)
    static int GetItemGUID(lua_State* L)
    {
        uint32 lowguid = luaL_checkunsigned(L, 1);
        sEluna->PushULong(L, MAKE_NEW_GUID(lowguid, 0, HIGHGUID_ITEM));
        return 1;
    }

    // GetObjectGUID(lowguid, entry)
    static int GetObjectGUID(lua_State* L)
    {
        uint32 lowguid = luaL_checkunsigned(L, 1);
        uint32 entry = luaL_checkunsigned(L, 2);
        sEluna->PushULong(L, MAKE_NEW_GUID(lowguid, entry, HIGHGUID_GAMEOBJECT));
        return 1;
    }

    // GetUnitGUID(lowguid, entry)
    static int GetUnitGUID(lua_State* L)
    {
        uint32 lowguid = luaL_checkunsigned(L, 1);
        uint32 entry = luaL_checkunsigned(L, 2);
        sEluna->PushULong(L, MAKE_NEW_GUID(lowguid, entry, HIGHGUID_UNIT));
        return 1;
    }

    // CreateLuaEvent(function, delay, calls) - Creates a timed event. Calls set to 0 will call inf returns eventID.
    static int CreateLuaEvent(lua_State* L)
    {
        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);
        if (!lua_isfunction(L, 1))
        {
            luaL_error(L, "#1 argument is not a function");
            return 0;
        }

        lua_settop(L, 1);
        int functionRef = lua_ref(L, true);
        sEluna->LuaWorldAI->ScriptEventCreate(functionRef, delay, repeats);
        sEluna->PushInteger(L, functionRef);
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
        {
            Eluna::LuaEventMap::ScriptEventsResetAll();
            Eluna::LuaEventData::RemoveAll();
        }
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

                uint32 db_lowguid = creature->GetDBTableGUIDLow();
                if (!creature->LoadCreatureFromDB(db_lowguid, map))
                {
                    delete creature;
                    return 0;
                }

                sObjectMgr->AddCreatureToGrid(db_lowguid, sObjectMgr->GetCreatureData(db_lowguid));
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
            uint32 lowguid = sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT);

            if (!object->Create(lowguid, objectInfo->entry, map, phase, x, y, z, o, 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
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

                // this will generate a new lowguid if the object is in an instance
                if (!object->LoadGameObjectFromDB(lowguid, map))
                {
                    delete object;
                    return false;
                }

                sObjectMgr->AddGameobjectToGrid(lowguid, sObjectMgr->GetGOData(lowguid));
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

    // AddVendorItem(entry, itemId, maxcount, incrtime, extendedcost[, persist(bool)])
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

    // VendorRemoveItem(entry, item[, persist(bool)])
    static int VendorRemoveItem(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 item = luaL_checkunsigned(L, 2);
        bool persist = luaL_optbool(L, 3, true);
        if (!sObjectMgr->GetCreatureTemplate(entry))
        {
            sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a creature with (ID: %d)!", entry);
            return 0;
        }

        sObjectMgr->RemoveVendorItem(entry, item, persist);
        return 0;
    }

    // VendorRemoveAllItems(entry, persist(bool))
    static int VendorRemoveAllItems(lua_State* L)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        bool persist = luaL_optbool(L, 2, true);

        VendorItemData const* items = sObjectMgr->GetNpcVendorItemList(entry);
        if (!items || items->Empty())
            return 0;

        for (VendorItemList::const_iterator itr = items->m_items.begin(); itr != items->m_items.end(); ++itr)
            sObjectMgr->RemoveVendorItem(entry, (*itr)->item, persist);
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
        case BAN_ACCOUNT:
            if (!AccountMgr::normalizeString(nameOrIP))
                return 0;
            break;
        case BAN_CHARACTER:
            if (!normalizePlayerName(nameOrIP))
                return 0;
            break;
        case BAN_IP:
            if (!IsIPAddress(nameOrIP.c_str()))
                return 0;
            break;
        default:
            return 0;
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

    // GetGUIDLow(guid)
    static int GetGUIDLow(lua_State* L)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);

        sEluna->PushUnsigned(L, GUID_LOPART(guid));
        return 1;
    }

    // SendMail(subject, text, receiverLowGUID[, sender, stationary, delay, itemEntry, itemAmount, itemEntry2, itemAmount2...])
    static int SendMail(lua_State* L)
    {
        int i = 0;
        std::string subject = luaL_checkstring(L, ++i);
        std::string text = luaL_checkstring(L, ++i);
        uint32 receiverGUIDLow = luaL_checkunsigned(L, ++i);
        Player* senderPlayer = sEluna->CHECK_PLAYER(L, ++i);
        uint32 stationary = luaL_optunsigned(L, ++i, MAIL_STATIONERY_DEFAULT);
        uint32 delay = luaL_optunsigned(L, ++i, 0);
        int32 argAmount = lua_gettop(L);

        MailSender sender(MAIL_NORMAL, senderPlayer ? senderPlayer->GetGUIDLow() : 0, (MailStationery)stationary);
        MailDraft draft(subject, text);

        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        uint8 addedItems = 0;
        while (addedItems <= MAX_MAIL_ITEMS && i+2 <= argAmount)
        {
            uint32 entry = luaL_checkunsigned(L, ++i);
            uint32 amount = luaL_checkunsigned(L, ++i);

            ItemTemplate const* item_proto = sObjectMgr->GetItemTemplate(entry);
            if (!item_proto)
            {
                luaL_error(L, "Item entry %u does not exist", entry);
                continue;
            }
            if (amount < 1 || (item_proto->MaxCount > 0 && amount > uint32(item_proto->MaxCount)))
            {
                luaL_error(L, "Item entry %u has invalid amount %u", entry, amount);
                continue;
            }
            if (Item* item = Item::CreateItem(entry, amount, senderPlayer ? senderPlayer : 0))
            {
                item->SaveToDB(trans);
                draft.AddItem(item);
                ++addedItems;
            }
        }

        draft.SendMailTo(trans, MailReceiver(receiverGUIDLow), sender, MAIL_CHECK_MASK_NONE, delay);
        CharacterDatabase.CommitTransaction(trans);
        return 0;
    }

    // bit_and(a, b)
    static int bit_and(lua_State* L)
    {
        uint32 a = luaL_checkunsigned(L, 1);
        uint32 b = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, a & b);
        return 1;
    }

    // bit_or(a, b)
    static int bit_or(lua_State* L)
    {
        uint32 a = luaL_checkunsigned(L, 1);
        uint32 b = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, a | b);
        return 1;
    }

    // bit_lshift(a, b)
    static int bit_lshift(lua_State* L)
    {
        uint32 a = luaL_checkunsigned(L, 1);
        uint32 b = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, a << b);
        return 1;
    }

    // bit_rshift(a, b)
    static int bit_rshift(lua_State* L)
    {
        uint32 a = luaL_checkunsigned(L, 1);
        uint32 b = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, a >> b);
        return 1;
    }

    // bit_xor(a, b)
    static int bit_xor(lua_State* L)
    {
        uint32 a = luaL_checkunsigned(L, 1);
        uint32 b = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, a ^ b);
        return 1;
    }

    // bit_not(a)
    static int bit_not(lua_State* L)
    {
        uint32 a = luaL_checkunsigned(L, 1);
        sEluna->PushUnsigned(L, ~ a);
        return 1;
    }

    static int GetGUIDType(lua_State* L)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        sEluna->PushUnsigned(L, GUID_HIPART(guid));
        return 1;
    }

    static int GetGUIDEntry(lua_State* L)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        sEluna->PushUnsigned(L, GUID_ENPART(guid));
        return 1;
    }

    // AddTaxiPath(pathTable, mountA, mountH[, price, pathId])
    static int AddTaxiPath(lua_State* L)
    {
        luaL_checktype(L, 1, LUA_TTABLE);
        uint32 mountA = luaL_checkunsigned(L, 2);
        uint32 mountH = luaL_checkunsigned(L, 3);
        uint32 price = luaL_optunsigned(L, 4, 0);
        uint32 pathId = luaL_optunsigned(L, 5, 0);
        lua_settop(L, 1);

        std::list<TaxiPathNodeEntry> nodes;

        int start = lua_gettop(L);
        int end = start;

        lua_pushnil(L);
        while (lua_next(L, -2) != 0)
        {
            luaL_checktype(L, -1, LUA_TTABLE);
            lua_pushnil(L);
            while (lua_next(L, -2) != 0)
            {
                lua_insert(L, end++);
            }
            if (start == end)
                continue;
            if (end-start < 4) // no mandatory args, dont add
            {
                while (end != start)
                    lua_remove(L, --end);
                continue;
            }

            while (end-start < 8) // fill optional args with 0
            {
                lua_pushunsigned(L, 0);
                lua_insert(L, end++);
            }
            TaxiPathNodeEntry* entry = new TaxiPathNodeEntry();
            // mandatory
            entry->mapid = luaL_checkunsigned(L, start);
            entry->x = luaL_checknumber(L, start+1);
            entry->y = luaL_checknumber(L, start+2);
            entry->z = luaL_checknumber(L, start+3);
            // optional
            entry->actionFlag = luaL_checkunsigned(L, start+4);
            entry->delay = luaL_checkunsigned(L, start+5);
            entry->arrivalEventID = luaL_checkunsigned(L, start+6);
            entry->departureEventID = luaL_checkunsigned(L, start+7);

            nodes.push_back(*entry);

            while (end != start) // remove args
                lua_remove(L, --end);

            lua_pop(L, 1);
        }

        sEluna->PushUnsigned(L, LuaTaxiMgr::AddPath(nodes, mountA, mountH, price, pathId));
        return 1;
    }
}
#endif