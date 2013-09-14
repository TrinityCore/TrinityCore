#ifndef __ELUNA__H
#define __ELUNA__H

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#include "Includes.h"

enum RegisterTypes
{
    REGTYPE_SERVER,
    REGTYPE_CREATURE,
    REGTYPE_CREATURE_GOSSIP,
    REGTYPE_GAMEOBJECT,
    REGTYPE_GAMEOBJECT_GOSSIP,
    REGTYPE_ITEM,
    REGTYPE_ITEM_GOSSIP,
    REGTYPE_PLAYER_GOSSIP,
    REGTYPE_COUNT
};

// RegisterServerHook(EventId, function)
enum ServerEvents
{
    // Player
    PLAYER_EVENT_ON_CHARACTER_CREATE        =     1,            // (event, player)
    PLAYER_EVENT_ON_CHARACTER_DELETE        =     2,            // (event, guid)
    PLAYER_EVENT_ON_LOGIN                   =     3,            // (event, player)
    PLAYER_EVENT_ON_LOGOUT                  =     4,            // (event, player)
    PLAYER_EVENT_ON_SPELL_CAST              =     5,            // (event, player, spell, skipCheck)
    PLAYER_EVENT_ON_KILL_PLAYER             =     6,            // (event, killer, killed)
    PLAYER_EVENT_ON_KILL_CREATURE           =     7,            // (event, killer, killed)
    PLAYER_EVENT_ON_KILLED_BY_CREATURE      =     8,            // (event, killer, killed)
    PLAYER_EVENT_ON_DUEL_REQUEST            =     9,            // (event, target, challenger)
    PLAYER_EVENT_ON_DUEL_START              =     10,           // (event, player1, player2)
    PLAYER_EVENT_ON_DUEL_END                =     11,           // (event, winner, loser, type)
    PLAYER_EVENT_ON_GIVE_XP                 =     12,           // (event, player, amount, victim)
    PLAYER_EVENT_ON_LEVEL_CHANGE            =     13,           // (event, player, oldLevel)
    PLAYER_EVENT_ON_MONEY_CHANGE            =     14,           // (event, player, amount)
    PLAYER_EVENT_ON_REPUTATION_CHANGE       =     15,           // (event, player, factionId, standing, incremental)
    PLAYER_EVENT_ON_TALENTS_CHANGE          =     16,           // (event, player, points)
    PLAYER_EVENT_ON_TALENTS_RESET           =     17,           // (event, player, noCost)
    PLAYER_EVENT_ON_CHAT                    =     18,           // (event, player, msg, Type, lang) - Can return false
    PLAYER_EVENT_ON_WHISPER                 =     19,           // (event, player, msg, Type, lang, receiver)
    PLAYER_EVENT_ON_GROUP_CHAT              =     20,           // (event, player, msg, Type, lang, group) - Can return false
    PLAYER_EVENT_ON_GUILD_CHAT              =     21,           // (event, player, msg, Type, lang, guild) - Can return false
    PLAYER_EVENT_ON_CHANNEL_CHAT            =     22,           // (event, player, msg, Type, lang, channel) - Can return false
    PLAYER_EVENT_ON_EMOTE                   =     23,           // (event, player, emote) - Not triggered on any known emote
    PLAYER_EVENT_ON_TEXT_EMOTE              =     24,           // (event, player, textEmote, emoteNum, guid)
    PLAYER_EVENT_ON_SAVE                    =     25,           // (event, player)
    PLAYER_EVENT_ON_BIND_TO_INSTANCE        =     26,           // (event, player, difficulty, mapid, permanent)
    PLAYER_EVENT_ON_UPDATE_ZONE             =     27,           // (event, player, newZone, newArea)
    PLAYER_EVENT_ON_MAP_CHANGE              =     28,           // (event, player)

    // Guild
    GUILD_EVENT_ON_ADD_MEMBER               =     29,           // (event, guild, player, rank)
    GUILD_EVENT_ON_REMOVE_MEMBER            =     30,           // (event, guild, isDisbanding, isKicked)
    GUILD_EVENT_ON_MOTD_CHANGE              =     31,           // (event, guild, newMotd)
    GUILD_EVENT_ON_INFO_CHANGE              =     32,           // (event, guild, newInfo)
    GUILD_EVENT_ON_CREATE                   =     33,           // (event, guild, leader, name)
    GUILD_EVENT_ON_DISBAND                  =     34,           // (event, guild)
    GUILD_EVENT_ON_MONEY_WITHDRAW           =     35,           // (event, guild, player, amount, isRepair)
    GUILD_EVENT_ON_MONEY_DEPOSIT            =     36,           // (event, guild, player, amount)
    GUILD_EVENT_ON_ITEM_MOVE                =     37,           // (event, guild, player, item, isSrcBank, srcContainer, srcSlotId, isDestBank, destContainer, destSlotId)
    GUILD_EVENT_ON_EVENT                    =     38,           // (event, guild, eventType, plrGUIDLow1, plrGUIDLow2, newRank)
    GUILD_EVENT_ON_BANK_EVENT               =     39,           // (event, guild, eventType, tabId, playerGUIDLow, itemOrMoney, itemStackCount, destTabId)

    // Server
    SERVER_EVENT_ON_NETWORK_START           =     40,           // Not Implemented
    SERVER_EVENT_ON_NETWORK_STOP            =     41,           // Not Implemented
    SERVER_EVENT_ON_SOCKET_OPEN             =     42,           // Not Implemented
    SERVER_EVENT_ON_SOCKET_CLOSE            =     43,           // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE          =     44,           // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE_UNKNOWN  =     45,           // Not Implemented
    SERVER_EVENT_ON_PACKET_SEND             =     46,           // Not Implemented

    // World
    WORLD_EVENT_ON_OPEN_STATE_CHANGE        =     47,           // (event, open)
    WORLD_EVENT_ON_CONFIG_LOAD              =     48,           // (event, reload)
    WORLD_EVENT_ON_MOTD_CHANGE              =     49,           // (event, newMOTD)
    WORLD_EVENT_ON_SHUTDOWN_INIT            =     50,           // (event, code, mask)
    WORLD_EVENT_ON_SHUTDOWN_CANCEL          =     51,           // (event)
    WORLD_EVENT_ON_UPDATE                   =     52,           // (event, diff)
    WORLD_EVENT_ON_STARTUP                  =     53,           // (event)
    WORLD_EVENT_ON_SHUTDOWN                 =     54,           // (event)

    // Eluna
    ELUNA_EVENT_ON_RESTART                  =     55,           // (event)

    // Map
    MAP_EVENT_ON_CREATE                     =     56,           // Not Implemented
    MAP_EVENT_ON_DESTROY                    =     57,           // Not Implemented
    MAP_EVENT_ON_LOAD                       =     58,           // Not Implemented
    MAP_EVENT_ON_UNLOAD                     =     59,           // Not Implemented
    MAP_EVENT_ON_PLAYER_ENTER               =     60,           // Not Implemented
    MAP_EVENT_ON_PLAYER_LEAVE               =     61,           // Not Implemented
    MAP_EVENT_ON_UPDATE                     =     62,           // Not Implemented

    // Area trigger
    TRIGGER_EVENT_ON_TRIGGER                =     63,           // (event, player, triggerId)

    // Weather
    WEATHER_EVENT_ON_CHANGE                 =     64,           // (event, weather, state, grade)

    // Auction house
    AUCTION_EVENT_ON_ADD                    =     65,           // Not Implemented
    AUCTION_EVENT_ON_REMOVE                 =     66,           // Not Implemented
    AUCTION_EVENT_ON_SUCCESFUL              =     67,           // Not Implemented
    AUCTION_EVENT_ON_EXPIRE                 =     68,           // Not Implemented

    // Group
    GROUP_EVENT_ON_MEMBER_ADD               =     69,           // (event, group, guid)
    GROUP_EVENT_ON_MEMBER_INVITE            =     70,           // (event, group, guid)
    GROUP_EVENT_ON_MEMBER_REMOVE            =     71,           // (event, group, guid, method, kicker, reason)
    GROUP_EVENT_ON_LEADER_CHANGE            =     72,           // (event, group, newLeaderGuid, oldLeaderGuid)
    GROUP_EVENT_ON_DISBAND                  =     73,           // (event, group)

    // Custom
    PLAYER_EVENT_ON_EQUIP                   =     74,           // (event, player, item, bag, slot)
    PLAYER_EVENT_ON_FIRST_LOGIN             =     75,           // (event, player)
    PLAYER_EVENT_ON_CAN_USE_ITEM            =     76,           // (event, player, itemEntry)
    PLAYER_EVENT_ON_LOOT_ITEM               =     77,           // (event, player, item, count)
    PLAYER_EVENT_ON_ENTER_COMBAT            =     78,           // (event, player, enemy)
    PLAYER_EVENT_ON_LEAVE_COMBAT            =     79,           // (event, player)
    PLAYER_EVENT_ON_REPOP                   =     80,           // (event, player)
    PLAYER_EVENT_ON_RESURRECT               =     81,           // (event, player)

    SERVER_EVENT_COUNT
};

// RegisterCreatureEvent(entry, EventId, function)
enum CreatureEvents
{
    CREATURE_EVENT_ON_ENTER_COMBAT                    = 1,      // (event, creature, target)
    CREATURE_EVENT_ON_LEAVE_COMBAT                    = 2,      // (event, creature)
    CREATURE_EVENT_ON_TARGET_DIED                     = 3,      // (event, creature, victim)
    CREATURE_EVENT_ON_DIED                            = 4,      // (event, creature, killer)
    CREATURE_EVENT_ON_SPAWN                           = 5,      // (event, creature)
    CREATURE_EVENT_ON_REACH_WP                        = 6,      // (event, creature, type, id)
    CREATURE_EVENT_ON_AIUPDATE                        = 7,      // (event, creature, diff)
    CREATURE_EVENT_ON_RECEIVE_EMOTE                   = 8,      // (event, creature, player, emoteid)
    CREATURE_EVENT_ON_DAMAGE_TAKEN                    = 9,      // (event, creature, attacker, damage)
    CREATURE_EVENT_ON_PRE_COMBAT                      = 10,     // (event, creature, target)
    CREATURE_EVENT_ON_ATTACKED_AT                     = 11,     // (event, creature, attacker)
    CREATURE_EVENT_ON_OWNER_ATTACKED                  = 12,     // (event, creature, target)
    CREATURE_EVENT_ON_OWNER_ATTACKED_AT               = 13,     // (event, creature, attacker)
    CREATURE_EVENT_ON_HIT_BY_SPELL                    = 14,     // (event, creature, caster, spellid)
    CREATURE_EVENT_ON_SPELL_HIT_TARGET                = 15,     // (event, creature, target, spellid)
    CREATURE_EVENT_ON_SPELL_CLICK                     = 16,     // (event, creature, clicker)
    CREATURE_EVENT_ON_CHARMED                         = 17,     // (event, creature, apply)
    CREATURE_EVENT_ON_POSSESS                         = 18,     // (event, creature, apply)
    CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE          = 19,     // (event, creature, summon)
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN       = 20,     // (event, creature, summon)
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED          = 21,     // (event, creature, summon, killer)
    CREATURE_EVENT_ON_SUMMONED                        = 22,     // (event, creature, summoner)
    CREATURE_EVENT_ON_RESET                           = 23,     // (event, creature)
    CREATURE_EVENT_ON_REACH_HOME                      = 24,     // (event, creature)
    CREATURE_EVENT_ON_CAN_RESPAWN                     = 25,     // (event, creature)
    CREATURE_EVENT_ON_CORPSE_REMOVED                  = 26,     // (event, creature, respawndelay)
    CREATURE_EVENT_ON_MOVE_IN_LOS                     = 27,     // (event, creature, unit)
    CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS             = 28,     // (event, creature, unit)
    CREATURE_EVENT_ON_PASSANGER_BOARDED               = 29,     // (event, creature, passanger, seatid, apply)
    CREATURE_EVENT_ON_DUMMY_EFFECT                    = 30,     // (event, caster, spellid, effindex, creature)
    CREATURE_EVENT_ON_QUEST_ACCEPT                    = 31,     // (event, player, creature, quest)
    CREATURE_EVENT_ON_QUEST_SELECT                    = 32,     // (event, player, creature, quest)
    CREATURE_EVENT_ON_QUEST_COMPLETE                  = 33,     // (event, player, creature, quest)
    CREATURE_EVENT_ON_QUEST_REWARD                    = 34,     // (event, player, creature, quest, opt)
    CREATURE_EVENT_ON_DIALOG_STATUS                   = 35,     // (event, player, creature)
    CREATURE_EVENT_COUNT
};

// RegisterGameObjectEvent(entry, EventId, function)
enum GameObjectEvents
{
    GAMEOBJECT_EVENT_ON_AIUPDATE                    = 1,        // (event, go, diff)
    GAMEOBJECT_EVENT_ON_RESET                       = 2,        // (event, go)
    GAMEOBJECT_EVENT_ON_DUMMY_EFFECT                = 3,        // (event, caster, spellid, effindex, go)
    GAMEOBJECT_EVENT_ON_QUEST_ACCEPT                = 4,        // (event, player, go, quest)
    GAMEOBJECT_EVENT_ON_QUEST_REWARD                = 5,        // (event, player, go, quest, opt)
    GAMEOBJECT_EVENT_ON_DIALOG_STATUS               = 6,        // (event, player, go)
    GAMEOBJECT_EVENT_ON_DESTROYED                   = 7,        // (event, go, player)
    GAMEOBJECT_EVENT_ON_DAMAGED                     = 8,        // (event, go, player)
    GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE           = 9,        // (event, go, state, unit)
    GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED            = 10,       // (event, go, state)
    GAMEOBJECT_EVENT_COUNT
};

// RegisterItemEvent(entry, EventId, function)
enum ItemEvents
{
    ITEM_EVENT_ON_DUMMY_EFFECT                      = 1,        // (event, caster, spellid, effindex, item)
    ITEM_EVENT_ON_USE                               = 2,        // (event, player, item, target)
    ITEM_EVENT_ON_QUEST_ACCEPT                      = 3,        // (event, player, item, quest)
    ITEM_EVENT_ON_EXPIRE                            = 4,        // (event, player, itemid)
    ITEM_EVENT_COUNT
};

// RegisterCreatureGossipEvent(entry, EventId, function)
// RegisterGameObjectGossipEvent(entry, EventId, function)
// RegisterItemGossipEvent(entry, EventId, function)
// RegisterPlayerGossipEvent(menu_id, EventId, function)
enum GossipEvents
{
    GOSSIP_EVENT_ON_HELLO                           = 1,        // (event, player, object) - Object is the Creature/GameObject/Item
    GOSSIP_EVENT_ON_SELECT                          = 2,        // (event, player, object, sender, intid, code, menu_id) - Object is the Creature/GameObject/Item/Player, menu_id is only for player gossip
    GOSSIP_EVENT_COUNT
};

struct LoadedScripts
{
    std::set<std::string> luaFiles;
};

template<class T>
struct ElunaRegister
{
    const char* name;
    int(*mfunc)(lua_State*, T*);
};

template<typename T> ElunaRegister<T>* GetMethodTable();
template<typename T> const char* GetTName();

class Eluna
{
public:
    friend class ScriptMgr;
    lua_State* LuaState;

    class LuaEventMap;
    struct LuaEventData;
    class Eluna_WorldScript;
    class Eluna_CreatureScript;
    class Eluna_GameObjectScript;
    Eluna_CreatureScript* LuaCreatureAI;
    Eluna_GameObjectScript* LuaGameObjectAI;
    Eluna_WorldScript* LuaWorldAI;

    typedef std::map<int, int> ElunaBindingMap;
    typedef UNORDERED_MAP<uint32, ElunaBindingMap> ElunaEntryMap;
    struct ElunaBind;
    std::map<int, std::vector<int> > ServerEventBindings;
    ElunaBind* CreatureEventBindings;
    ElunaBind* CreatureGossipBindings;
    ElunaBind* GameObjectEventBindings;
    ElunaBind* GameObjectGossipBindings;
    ElunaBind* ItemEventBindings;
    ElunaBind* ItemGossipBindings;
    ElunaBind* playerGossipBindings;

    void StartEluna(bool restart);
    void AddScriptHooks();
    static void report(lua_State*);
    void Register(uint8 reg, uint32 id, uint32 evt, int func);
    void BeginCall(int fReference);
    bool ExecuteCall(uint8 params, uint8 res);
    void EndCall(uint8 res);
    void LoadDirectory(char* directory, LoadedScripts* scr);
    // Pushes
    void PushULong(lua_State*, uint64);
    void PushLong(lua_State*, int64);
    void PushInteger(lua_State*, int);
    void PushUnsigned(lua_State*, uint32);
    void PushBoolean(lua_State*, bool);
    void PushFloat(lua_State*, float);
    void PushDouble(lua_State*, double);
    void PushString(lua_State*, const char*);
    void PushGroup(lua_State*, Group*);
    void PushGuild(lua_State*, Guild*);
    void PushUnit(lua_State*, Unit*);
    void PushMap(lua_State*, Map*);
    void PushGO(lua_State*, GameObject*);
    void PushQueryResult(lua_State*, QueryResult*);
    void PushAura(lua_State*, Aura*);
    void PushItem(lua_State*, Item*);
    void PushSpell(lua_State*, Spell*);
    void PushQuest(lua_State*, Quest const*);
    void PushPacket(lua_State*, WorldPacket*);
    // Checks
    WorldPacket* CHECK_PACKET(lua_State* L, int narg);
    Object* CHECK_OBJECT(lua_State* L, int narg);
    WorldObject* CHECK_WORLDOBJECT(lua_State* L, int narg);
    Unit * CHECK_UNIT(lua_State* L, int narg);
    Player * CHECK_PLAYER(lua_State* L, int narg);
    Creature * CHECK_CREATURE(lua_State* L, int narg);
    GameObject* CHECK_GAMEOBJECT(lua_State* L, int narg);
    Quest* CHECK_QUEST(lua_State* L, int narg);
    Spell* CHECK_SPELL(lua_State* L, int narg);
    uint64 CHECK_ULONG(lua_State* L, int narg);
    int64 CHECK_LONG(lua_State* L, int narg);

    // Creates new binding stores
    Eluna()
    {
        LuaState = NULL;
        LuaCreatureAI = NULL;
        LuaGameObjectAI = NULL;
        LuaWorldAI = NULL;

        for (int i = 0; i < SERVER_EVENT_COUNT; ++i)
        {
            std::vector<int> _vector;
            ServerEventBindings.insert(std::pair<int, std::vector<int> >(i, _vector));
        }
        CreatureEventBindings = new ElunaBind;
        CreatureGossipBindings = new ElunaBind;
        GameObjectEventBindings = new ElunaBind;
        GameObjectGossipBindings = new ElunaBind;
        ItemEventBindings = new ElunaBind;
        ItemGossipBindings = new ElunaBind;
        playerGossipBindings = new ElunaBind;
    }

    ~Eluna()
    {
        for (std::map<int, std::vector<int> >::iterator itr = ServerEventBindings.begin(); itr != ServerEventBindings.end(); ++itr)
        {
            for (std::vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                luaL_unref(LuaState, LUA_REGISTRYINDEX, (*it));
            itr->second.clear();
        }
        ServerEventBindings.clear();
        CreatureEventBindings->Clear();
        CreatureGossipBindings->Clear();
        GameObjectEventBindings->Clear();
        GameObjectGossipBindings->Clear();
        ItemEventBindings->Clear();
        ItemGossipBindings->Clear();
        playerGossipBindings->Clear();

        lua_close(LuaState); // Closing
    }

    struct ElunaBind
    {
        void Clear(); // unregisters all registered functions and clears all registered events from the bind std::maps (reset)
        void Insert(uint32 entryId, uint32 eventId, int funcRef); // Inserts a new registered event

        // Gets the function ref of an entry for an event
        int GetBind(uint32 entryId, uint32 eventId)
        {
            ElunaEntryMap::iterator itr = Bindings.find(entryId);
            if (itr == Bindings.end())
                return 0;

            return itr->second[eventId];
        }

        // Gets the binding std::map containing all registered events with the function refs for the entry
        ElunaBindingMap* GetBindMap(uint32 entryId) 
        {
            ElunaEntryMap::iterator itr = Bindings.find(entryId);
            if (itr == Bindings.end())
                return NULL;

            return &itr->second;
        }

        ElunaEntryMap Bindings; // Binding store Bindings[entryId][eventId] = funcRef;
    };

    Item* CHECK_ITEM(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<Item>::check(LuaState, narg);
        else
            return ElunaTemplate<Item>::check(L, narg);
    }

    class NearestTypeWithEntryInRangeCheck // not self
    {
    public:
        NearestTypeWithEntryInRangeCheck(WorldObject const* obj, float range, TypeID typeId, uint32 entry = 0) : i_obj(obj), i_range(range), i_typeId(typeId), i_entry(entry)
        {
        }

        bool operator()(WorldObject* u)
        {
            if (u->GetTypeId() == i_typeId && i_obj->GetGUID() != u->GetGUID() && (!i_entry || u->GetEntry() == i_entry) && i_obj->IsWithinDistInMap(u, i_range))
            {
                if (Unit* unit = u->ToUnit())
                {
                    if (!unit->IsAlive())
                        return false;
                }

                i_range = i_obj->GetDistance(u);
                return true;
            }

            return false;
        }
    private:
        WorldObject const* i_obj;
        float i_range;
        TypeID i_typeId;
        uint32 i_entry;

        NearestTypeWithEntryInRangeCheck(NearestTypeWithEntryInRangeCheck const&);
    };

protected:
    template<typename T>
    class ElunaTemplate
    {
    public:
        typedef int (*_funcptr)(lua_State* L, T* ptr);
        typedef struct { const char* name; _funcptr mfunc; } ElunaRegister;

        static void Register(lua_State* L)
        {
            lua_newtable(L);
            int methods = lua_gettop(L);

            luaL_newmetatable(L, GetTName<T>());
            int metatable = lua_gettop(L);

            // store method table in globals so that
            // scripts can add functions in Lua
            lua_pushvalue(L, methods);
            lua_setglobal(L, GetTName<T>());

            // hide metatable
            lua_pushvalue(L, methods);
            lua_setfield(L, metatable, "__metatable");

            lua_pushvalue(L, methods);
            lua_setfield(L, metatable, "__index");

            lua_pushcfunction(L, tostringT);
            lua_setfield(L, metatable, "__tostring");

            lua_pushcfunction(L, gcT);
            lua_setfield(L, metatable, "__gc");

            lua_newtable(L);
            lua_setmetatable(L, methods);

            // fill method table.
            if (!GetMethodTable<T>())
            {
                lua_pop(L, 2);
                return;
            }

            for (ElunaRegister* l = ((ElunaRegister*)GetMethodTable<T>()); l->name; ++l)
            {
                lua_pushstring(L, l->name);
                lua_pushlightuserdata(L, (void*)l);
                lua_pushcclosure(L, thunk, 1);
                lua_settable(L, methods);
            }

            lua_pop(L, 2);
        }

        static int push(lua_State* L, T* obj, bool gc = false)
        {
            if (!obj)
            {
                lua_pushnil(L);
                return lua_gettop(L);
            }
            luaL_getmetatable(L, GetTName<T>());
            if (lua_isnil(L, -1))
                luaL_error(L, "%s missing metatable", GetTName<T>());
            int idxMt = lua_gettop(L);
            T** ptrHold = (T**)lua_newuserdata(L, sizeof(T**));
            int ud = lua_gettop(L);
            if (ptrHold)
            {
                *ptrHold = obj;
                lua_pushvalue(L, idxMt);
                lua_setmetatable(L, -2);
                char name[32];
                tostring(name, obj);
                lua_getfield(L, LUA_REGISTRYINDEX, "DO NOT TRASH");
                if (lua_isnil(L, -1))
                {
                    luaL_newmetatable(L, "DO NOT TRASH");
                    lua_pop(L, 1);
                }
                lua_getfield(L, LUA_REGISTRYINDEX, "DO NOT TRASH");
                if (gc == false)
                {
                    lua_pushboolean(L, 1);
                    lua_setfield(L, -2, name);
                }
                lua_pop(L, 1);
            }
            lua_settop(L, ud);
            lua_replace(L, idxMt);
            lua_settop(L, idxMt);
            return idxMt;
        }

        static T* check(lua_State* L, int narg)
        {
            T** ptrHold = static_cast<T**>(lua_touserdata(L, narg));
            if (!ptrHold)
                return NULL;
            return *ptrHold;
        }

    private:
        static int thunk(lua_State* L)
        {
            T* obj = check(L, 1); // get self
            lua_remove(L, 1); // remove self
            ElunaRegister* l = static_cast<ElunaRegister*>(lua_touserdata(L, lua_upvalueindex(1)));
            return l->mfunc(L, obj);
        }

        static int gcT(lua_State* L)
        {
            T* obj = check(L, 1);
            if (!obj)
                return 0;
            lua_getfield(L, LUA_REGISTRYINDEX, "DO NO TRASH");
            if (lua_istable(L, -1))
            {
                char name[32];
                tostring(name, obj);
                lua_getfield(L, -1, std::string(name).c_str());
                if (lua_isnil(L, -1))
                {
                    delete obj;
                    obj = NULL;
                }
            }
            return 1;
        }

        static int tostringT(lua_State* L)
        {
            char buff[32];
            T** ptrHold = (T**)lua_touserdata(L, 1);
            T* obj = *ptrHold;
            sprintf(buff, "%p", obj);
            lua_pushfstring(L, "%s (%s)", GetTName<T>(), buff);
            return 1;
        }

        inline static void tostring(char* buff, void* obj)
        {
            sprintf(buff, "%p", obj);
        }

        static int index(lua_State* L)
        {
            lua_getglobal(L, GetTName<T>());
            const char* key = lua_tostring(L, 2);
            if (lua_istable(L, - 1))
            {
                lua_pushvalue(L, 2);
                lua_rawget(L, -2);
                if (lua_isnil(L, -1))
                {
                    lua_getmetatable(L, -2);
                    if (lua_istable(L, -1))
                    {
                        lua_getfield(L, -1, "__index");
                        if (lua_isfunction(L, -1))
                        {
                            lua_pushvalue(L, 1);
                            lua_pushvalue(L, 2);
                            lua_pcall(L, 2, 1, 0);
                        }
                        else if (lua_istable(L, -1))
                            lua_getfield(L, -1, key);
                        else
                            lua_pushnil(L);
                    }
                    else
                        lua_pushnil(L);
                }
                else if (lua_istable(L, -1))
                {
                    lua_pushvalue(L, 2);
                    lua_rawget(L, -2);
                }
            }
            else
                lua_pushnil(L);
            lua_insert(L, 1);
            lua_settop(L, 1);
            return 1;
        }
    };
};
#define sEluna ACE_Singleton<Eluna, ACE_Null_Mutex>::instance()

class Eluna::LuaEventMap
{
public:
    LuaEventMap() { }
    ~LuaEventMap() { ScriptEventsReset(); }

    struct eventData
    {
        int funcRef; uint32 delay; uint32 calls;
        eventData(int _funcRef, uint32 _delay, uint32 _calls) :
            funcRef(_funcRef), delay(_delay), calls(_calls) {}
    };

    typedef std::multimap<uint32, eventData> EventStore; // Not to use multimap? Can same function ref ID be used multiple times?

    virtual void OnScriptEvent(int funcRef, uint32 delay, uint32 calls) { }

    static void ScriptEventsResetAll(); // Unregisters and stops all timed events
    void ScriptEventsReset();
    void ScriptEventCancel(int funcRef);
    void ScriptEventsExecute();

    // Gets the event map saved for a guid
    static LuaEventMap* GetEvents(WorldObject* obj)
    {
        if (!obj)
            return NULL;
        UNORDERED_MAP<uint64, LuaEventMap*>::const_iterator it = LuaEventMaps.find(obj->GetGUID());
        if (it != LuaEventMaps.end())
            return it->second;
        return NULL;
    }

    void ScriptEventsUpdate(uint32 time)
    {
        _time += time;
    }

    bool ScriptEventsEmpty() const
    {
        return _eventMap.empty();
    }

    void ScriptEventCreate(int funcRef, uint32 delay, uint32 calls)
    {
        _eventMap.insert(EventStore::value_type(_time + delay, eventData(funcRef, delay, calls)));
    }

    static UNORDERED_MAP<uint64, LuaEventMap*> LuaEventMaps; // Creature and gameobject timed events

private:
    EventStore _eventMap;
    uint32 _time;
};
class Eluna::Eluna_WorldScript : public WorldScript, public Eluna::LuaEventMap
{
public:
    Eluna_WorldScript() : WorldScript("SmartEluna_WorldScript"), LuaEventMap()
    {
    }
    ~Eluna_WorldScript()
    {
    }

    void OnOpenStateChange(bool open) OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_OPEN_STATE_CHANGE].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_OPEN_STATE_CHANGE].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_OPEN_STATE_CHANGE);
            sEluna->PushBoolean(sEluna->LuaState, open);
            sEluna->ExecuteCall(2, 0);
        }
    }

    void OnConfigLoad(bool reload) OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_CONFIG_LOAD].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_CONFIG_LOAD].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_CONFIG_LOAD);
            sEluna->PushBoolean(sEluna->LuaState, reload);
            sEluna->ExecuteCall(2, 0);
        }
    }

    void OnMotdChange(std::string& newMotd) OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_MOTD_CHANGE].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_MOTD_CHANGE].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_MOTD_CHANGE);
            sEluna->PushString(sEluna->LuaState, newMotd.c_str());
            sEluna->ExecuteCall(2, 0);
        }
    }

    void OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask) OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_INIT].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_INIT].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN_INIT);
            sEluna->PushInteger(sEluna->LuaState, code);
            sEluna->PushInteger(sEluna->LuaState, mask);
            sEluna->ExecuteCall(3, 0);
        }
    }

    void OnShutdownCancel() OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_CANCEL].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_CANCEL].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN_CANCEL);
            sEluna->ExecuteCall(1, 0);
        }
    }

    void OnUpdate(uint32 diff) OVERRIDE
    {
        ScriptEventsUpdate(diff);
        ScriptEventsExecute();
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_UPDATE].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_UPDATE].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_UPDATE);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(2, 0);
        }
    }
    // executed when a  timed event fires
    void OnScriptEvent(int funcRef, uint32 delay, uint32 calls) OVERRIDE
    {
        sEluna->BeginCall(funcRef);
        sEluna->PushUnsigned(sEluna->LuaState, funcRef);
        sEluna->PushUnsigned(sEluna->LuaState, delay);
        sEluna->PushUnsigned(sEluna->LuaState, calls);
        sEluna->ExecuteCall(3, 0);
    }

    void OnStartup() OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_STARTUP].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_STARTUP].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_STARTUP);
            sEluna->ExecuteCall(1, 0);
        }
    }

    void OnShutdown() OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN);
            sEluna->ExecuteCall(1, 0);
        }
    }
};
class Eluna::Eluna_CreatureScript : public CreatureScript
{
public:
    Eluna_CreatureScript() : CreatureScript("SmartEluna_CreatureScript") // Smart suppressing error @startup
    {
    }
    ~Eluna_CreatureScript()
    {
    }

    struct ScriptCreatureAI : ScriptedAI
    {
        ScriptCreatureAI(Creature* creature) : ScriptedAI(creature)
        {
        }
        ~ScriptCreatureAI()
        {
        }

        //Called at World update tick
        void UpdateAI(uint32 diff) OVERRIDE
        {
            ScriptedAI::UpdateAI(diff);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_AIUPDATE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_AIUPDATE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(3, 0);
        }

        //Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
        //Called at creature aggro either by MoveInLOS or Attack Start
        void EnterCombat(Unit* target) OVERRIDE
        {
            ScriptedAI::EnterCombat(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ENTER_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_ENTER_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // Called at any Damage from any attacker (before damage apply)
        void DamageTaken(Unit* attacker, uint32& damage) OVERRIDE
        {
            ScriptedAI::DamageTaken(attacker, damage);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DAMAGE_TAKEN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_DAMAGE_TAKEN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->PushUnsigned(sEluna->LuaState, damage);
            sEluna->ExecuteCall(4, 0);
        }

        //Called at creature death
        void JustDied(Unit* killer) OVERRIDE
        {
            ScriptedAI::JustDied(killer);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->ExecuteCall(3, 0);
        }

        //Called at creature killing another unit
        void KilledUnit(Unit* victim) OVERRIDE
        {
            ScriptedAI::KilledUnit(victim);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_TARGET_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_TARGET_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, victim);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when the creature summon successfully other creature
        void JustSummoned(Creature* summon) OVERRIDE
        {
            ScriptedAI::JustSummoned(summon);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when a summoned creature is despawned
        void SummonedCreatureDespawn(Creature* summon) OVERRIDE
        {
            ScriptedAI::SummonedCreatureDespawn(summon);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when hit by a spell
        void SpellHit(Unit* caster, SpellInfo const* spell) OVERRIDE
        {
            ScriptedAI::SpellHit(caster, spell);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_HIT_BY_SPELL);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_HIT_BY_SPELL);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, caster);
            sEluna->PushUnsigned(sEluna->LuaState, spell->Id); // Pass spell object?
            sEluna->ExecuteCall(4, 0);
        }

        // Called when spell hits a target
        void SpellHitTarget(Unit* target, SpellInfo const* spell) OVERRIDE
        {
            ScriptedAI::SpellHitTarget(target, spell);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_HIT_TARGET);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPELL_HIT_TARGET);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->PushUnsigned(sEluna->LuaState, spell->Id); // Pass spell object?
            sEluna->ExecuteCall(4, 0);
        }

        //Called at waypoint reached or PointMovement end
        void MovementInform(uint32 type, uint32 id) OVERRIDE
        {
            ScriptedAI::MovementInform(type, id);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_WP);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_REACH_WP);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, type);
            sEluna->PushUnsigned(sEluna->LuaState, id);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when AI is temporarily replaced or put back when possess is applied or removed
        void OnPossess(bool apply) OVERRIDE
        {
            ScriptedAI::OnPossess(apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_POSSESS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_POSSESS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(3, 0);
        }

        //Called at creature reset either by death or evade
        void Reset() OVERRIDE
        {
            ScriptedAI::Reset();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RESET);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_RESET);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called before EnterCombat even before the creature is in combat.
        void AttackStart(Unit* target) OVERRIDE
        {
            ScriptedAI::AttackStart(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PRE_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_PRE_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // Called in Creature::Update when deathstate = DEAD. Inherited classes may maniuplate the ability to respawn based on scripted events.
        bool CanRespawn() OVERRIDE
        {
            ScriptedAI::CanRespawn();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CAN_RESPAWN);
            if (!bind)
                return true;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CAN_RESPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
            return true;
        }

        // Called for reaction at stopping attack at no attackers or targets
        void EnterEvadeMode() OVERRIDE
        {
            ScriptedAI::EnterEvadeMode();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_LEAVE_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_LEAVE_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called when the creature is summoned successfully by other creature
        void IsSummonedBy(Unit* summoner) OVERRIDE
        {
            ScriptedAI::IsSummonedBy(summoner);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summoner);
            sEluna->ExecuteCall(3, 0);
        }

        void SummonedCreatureDies(Creature* summon, Unit* killer) OVERRIDE
        {
            ScriptedAI::SummonedCreatureDies(summon, killer);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when the creature is target of hostile action: swing, hostile spell landed, fear/etc)
        void AttackedBy(Unit* attacker) OVERRIDE
        {
            ScriptedAI::AttackedBy(attacker);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ATTACKED_AT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_ATTACKED_AT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when creature is spawned or respawned (for reseting variables)
        void JustRespawned() OVERRIDE
        {
            ScriptedAI::JustRespawned();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPAWN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        void OnCharmed(bool apply) OVERRIDE
        {
            ScriptedAI::OnCharmed(apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CHARMED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CHARMED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(3, 0);
        }

        // Called at reaching home after evade
        void JustReachedHome() OVERRIDE
        {
            ScriptedAI::JustReachedHome();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_HOME);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_REACH_HOME);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called at text emote receive from player
        void ReceiveEmote(Player* player, uint32 emoteId) OVERRIDE
        {
            ScriptedAI::ReceiveEmote(player, emoteId);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RECEIVE_EMOTE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_RECEIVE_EMOTE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, emoteId);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when owner takes damage
        void OwnerAttackedBy(Unit* attacker) OVERRIDE
        {
            ScriptedAI::OwnerAttackedBy(attacker);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when owner attacks something
        void OwnerAttacked(Unit* target) OVERRIDE
        {
            ScriptedAI::OwnerAttacked(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_OWNER_ATTACKED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // called when the corpse of this creature gets removed
        void CorpseRemoved(uint32& respawnDelay) OVERRIDE
        {
            ScriptedAI::CorpseRemoved(respawnDelay);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CORPSE_REMOVED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CORPSE_REMOVED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, respawnDelay);
            sEluna->ExecuteCall(3, 0);
        }

        void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) OVERRIDE
        {
            ScriptedAI::PassengerBoarded(passenger, seatId, apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PASSANGER_BOARDED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_PASSANGER_BOARDED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, passenger);
            sEluna->PushInteger(sEluna->LuaState, seatId);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(5, 0);
        }

        void OnSpellClick(Unit* clicker, bool& result) OVERRIDE
        {
            ScriptedAI::OnSpellClick(clicker, result);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_CLICK);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPELL_CLICK);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, clicker);
            sEluna->PushBoolean(sEluna->LuaState, result);
            sEluna->ExecuteCall(4, 0);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE
        {
            ScriptedAI::MoveInLineOfSight(who);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_MOVE_IN_LOS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_MOVE_IN_LOS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, who);
            sEluna->ExecuteCall(3, 0);
        }

        // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
        void MoveInLineOfSight_Safe(Unit* who)
        {
            ScriptedAI::MoveInLineOfSight_Safe(who);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, who);
            sEluna->ExecuteCall(3, 0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        if (!sEluna->CreatureEventBindings->GetBindMap(creature->GetEntry()))
            return NULL;

        ScriptCreatureAI* luaCreatureAI = new ScriptCreatureAI(creature);
        return luaCreatureAI;
    }
};
class Eluna::Eluna_GameObjectScript : public GameObjectScript
{
public:
    Eluna_GameObjectScript() : GameObjectScript("SmartEluna_GameObjectScript") // Smart suppressing error @startup
    {
    }
    ~Eluna_GameObjectScript()
    {
    }

    struct ScriptGameObjectAI : public GameObjectAI, public Eluna::LuaEventMap
    {
        ScriptGameObjectAI(GameObject* _go) : GameObjectAI(_go), LuaEventMap()
        {
        }
        ~ScriptGameObjectAI()
        {
            LuaEventMap::LuaEventMaps.erase(go->GetGUID());
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            ScriptEventsUpdate(diff);
            ScriptEventsExecute();
            int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_AIUPDATE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_AIUPDATE);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(3, 0);
        }

        // executed when a timed event fires
        void OnScriptEvent(int funcRef, uint32 delay, uint32 calls) OVERRIDE
        {
            sEluna->BeginCall(funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, delay);
            sEluna->PushUnsigned(sEluna->LuaState, calls);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->ExecuteCall(4, 0);
        }

        void Reset() OVERRIDE
        {
            sEluna->BeginCall(sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_RESET));
            sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_RESET);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->ExecuteCall(2, 0);
        }
    };

    GameObjectAI* GetAI(GameObject* gameObject) const OVERRIDE
    {
        if (!sEluna->GameObjectEventBindings->GetBindMap(gameObject->GetEntry()))
            return NULL;

        ScriptGameObjectAI* luaGameObjectAI = new ScriptGameObjectAI(gameObject);
        LuaEventMap::LuaEventMaps[gameObject->GetGUID()] = luaGameObjectAI;
        return luaGameObjectAI;
    }
};
struct Eluna::LuaEventData : public BasicEvent, public Eluna::LuaEventMap::eventData
{
    static UNORDERED_MAP<int, LuaEventData*> LuaEvents;
    static UNORDERED_MAP<uint64, std::set<int> > EventIDs;
    Unit* _unit;
    uint64 GUID;

    LuaEventData(int funcRef, uint32 delay, uint32 calls, Unit* unit) :
        _unit(unit), GUID(unit->GetGUID()), Eluna::LuaEventMap::eventData(funcRef, delay, calls)
    {
        LuaEvents[funcRef] = this;
        EventIDs[unit->GetGUID()].insert(funcRef);
    }

    ~LuaEventData()
    {
        luaL_unref(sEluna->LuaState, LUA_REGISTRYINDEX, funcRef);
        LuaEvents.erase(funcRef);
        EventIDs[GUID].erase(funcRef);
    }

    static void RemoveAll()
    {
        for (UNORDERED_MAP<uint64, std::set<int> >::const_iterator it = EventIDs.begin(); it != EventIDs.end(); ++it)
        {
            if(it->second.empty())
                continue;
            for(std::set<int>::const_iterator itr = it->second.begin(); itr != it->second.end(); ++itr)
            {
                if(LuaEvents.find(*itr) == LuaEvents.end())
                    continue;
                if(LuaEvents[*itr]->_unit)
                {
                    LuaEvents[*itr]->_unit->m_Events.KillAllEvents(true);
                    break;
                }
            }
        }
        LuaEvents.clear();
        EventIDs.clear();
    }

    static void RemoveAll(Unit* unit)
    {
        if(!unit)
            return;
        unit->m_Events.KillAllEvents(true); // should delete the objects
        for (std::set<int>::const_iterator it = EventIDs[unit->GetGUID()].begin(); it != EventIDs[unit->GetGUID()].end(); ++it)
            LuaEvents.erase(*it); // deletes pointers
        EventIDs.erase(unit->GetGUID());
    }

    static void Remove(uint64 guid, int eventID)
    {
        if(LuaEvents.find(eventID) != LuaEvents.end())
        {
            LuaEvents[eventID]->to_Abort = true; // delete on next cycle
            LuaEvents.erase(eventID);
        }
        EventIDs[guid].erase(eventID);
    }

    bool Execute(uint64 time, uint32 diff) // Should NEVER execute on dead events
    {
        sEluna->BeginCall(funcRef);
        sEluna->PushUnsigned(sEluna->LuaState, funcRef);
        sEluna->PushUnsigned(sEluna->LuaState, delay);
        sEluna->PushUnsigned(sEluna->LuaState, calls);
        sEluna->PushUnit(sEluna->LuaState, _unit);
        sEluna->ExecuteCall(4, 0);
        if (calls && !--calls) // dont repeat anymore
        {
            Remove(GUID, funcRef);
            return true; // destory event
        }
        _unit->m_Events.AddEvent(this, _unit->m_Events.CalculateTime(delay));
        return false; // dont destory event
    }
};
class LuaTaxiMgr
{
private:
    static uint32 nodeId;
public:
    static void StartTaxi(Player* player, uint32 pathid);
    static uint32 AddPath(std::list<TaxiPathNodeEntry> nodes, uint32 mountA, uint32 mountH, uint32 price = 0, uint32 pathId = 0);
};
#endif
