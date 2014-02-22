/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef __ELUNA__H
#define __ELUNA__H

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#include "Includes.h"
#include "HookMgr.h"

// Required
#include "AccountMgr.h"
#include "ArenaTeam.h"
#include "AuctionHouseMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "Chat.h"
#include "Channel.h"
#include "DBCStores.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Language.h"
#include "Mail.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "Pet.h"
#include "ReputationMgr.h"
#include "revision.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#ifdef MANGOS
#include "ReactorAI.h"
#include "revision_nr.h"
#else
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "WeatherMgr.h"
#endif
#ifndef TBC
#include "Vehicle.h"
#endif

typedef std::set<std::string> LoadedScripts;

#define ELUNA_GUARD() \
    ACE_Guard< ACE_Thread_Mutex > ELUNA_GUARD_OBJECT (sEluna->lock);

#ifdef MANGOS
#undef  sWorld
#undef  sMapMgr
#undef  sGuildMgr
#undef  sObjectMgr
#undef  sAccountMgr
#undef  sObjectAccessor
#define sWorld                  (&MaNGOS::Singleton<World>::Instance())
#define sMapMgr                 (&MapManager::Instance())
#define sGuildMgr               (&MaNGOS::Singleton<GuildMgr>::Instance())
#define sObjectMgr              (&MaNGOS::Singleton<ObjectMgr>::Instance())
#define sAccountMgr             (&MaNGOS::Singleton<AccountMgr>::Instance())
#define sObjectAccessor         (&ObjectAccessor::Instance())
#define MAKE_NEW_GUID(l, e, h)  ObjectGuid(h, e, l)
#define GUID_TYPE               ObjectGuid
#define GET_GUID                GetObjectGuid
#define GetGameObjectTemplate   GetGameObjectInfo
#define GetItemTemplate         GetItemPrototype
#define TC_LOG_INFO(L, ...)     sLog.outString(__VA_ARGS__);
#define TC_LOG_ERROR(L, ...)    sLog.outErrorEluna(__VA_ARGS__);
#define TC_LOG_DEBUG(L, ...)    sLog.outDebug(__VA_ARGS__);
#define CORE_VERSION            REVISION_NR
#define CORE_NAME               "MaNGOS"
#define SERVER_MSG_STRING       SERVER_MSG_CUSTOM
#define MAX_LOCALES             MAX_LOCALE
#define OVERRIDE                override
#define DIALOG_STATUS_SCRIPTED_NO_STATUS    DIALOG_STATUS_UNDEFINED
#define TempSummon              TemporarySummon
#define PLAYER_FIELD_LIFETIME_HONORABLE_KILLS   PLAYER_FIELD_LIFETIME_HONORBALE_KILLS
#define MAX_TALENT_SPECS        MAX_TALENT_SPEC_COUNT
#define Vehicle                 VehicleInfo
#define GUID_ENPART(guid)       ObjectGuid(guid).GetEntry()
#define GUID_LOPART(guid)       ObjectGuid(guid).GetCounter()
#define GUID_HIPART(guid)       ObjectGuid(guid).GetHigh()
enum SelectAggroTarget
{
    SELECT_TARGET_RANDOM = 0,                               // Just selects a random target
    SELECT_TARGET_TOPAGGRO,                                 // Selects targes from top aggro to bottom
    SELECT_TARGET_BOTTOMAGGRO,                              // Selects targets from bottom aggro to top
    SELECT_TARGET_NEAREST,
    SELECT_TARGET_FARTHEST
};
#ifdef TBC
#define SPELL_AURA_MOD_KILL_XP_PCT  SPELL_AURA_MOD_XP_PCT
#endif
#else
#define GUID_TYPE               uint64
#define GET_GUID                GetGUID
#define CORE_VERSION            _DATE
#define CORE_NAME               "TrinityCore"
#define REGEN_TIME_FULL
#define ThreatList              ThreatContainer::StorageType
#endif

template<typename T>
struct ElunaRegister
{
    const char* name;
    int(*mfunc)(lua_State*, T*);
};

template<typename T>
class ElunaTemplate
{
public:
    static const char* tname;
    static bool manageMemory;

    static int type(lua_State* L)
    {
        lua_pushstring(L, tname);
        return 1;
    }

    static int gcT(lua_State* L)
    {
        if (!manageMemory)
            return 0;
        T* obj = check(L, 1);
        delete obj; // Deleting NULL should be safe
        return 1;
    }

    // name will be used as type name
    // If gc is true, lua will handle the memory management for object pushed
    // gc should be used if pushing for example WorldPacket,
    // that will only be needed on lua side and will not be managed by TC/mangos/<core>
    static void Register(lua_State* L, const char* name, bool gc = false)
    {
        tname = name;
        manageMemory = gc;

        lua_settop(L, 0); // clean stack

        lua_newtable(L);
        int methods = lua_gettop(L);

        luaL_newmetatable(L, tname);
        int metatable = lua_gettop(L);

        // store method table in globals so that
        // scripts can add functions in Lua
        lua_pushvalue(L, methods);
        lua_setglobal(L, tname);

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
    }

    template<typename C>
    static void SetMethods(lua_State* L, ElunaRegister<C>* methodTable)
    {
        if (!methodTable)
            return;
        if (!lua_istable(L, 1))
            return;
        lua_pushstring(L, "GetObjectType");
        lua_pushcclosure(L, type, 0);
        lua_settable(L, 1);
        for (; methodTable->name; ++methodTable)
        {
            lua_pushstring(L, methodTable->name);
            lua_pushlightuserdata(L, (void*)methodTable);
            lua_pushcclosure(L, thunk, 1);
            lua_settable(L, 1);
        }
    }

    static int push(lua_State* L, T const* obj)
    {
        if (!obj)
        {
            lua_pushnil(L);
            return lua_gettop(L);
        }
        luaL_getmetatable(L, tname);
        if (lua_isnoneornil(L, -1))
            return luaL_error(L, "%s missing metatable", tname);
        T const** ptrHold = (T const**)lua_newuserdata(L, sizeof(T**));
        if (ptrHold)
        {
            *ptrHold = obj;
            lua_pushvalue(L, -2);
            lua_setmetatable(L, -2);
        }
        lua_replace(L, -2);
        return lua_gettop(L);
    }

    static T* check(lua_State* L, int narg, bool error = true)
    {
        T** ptrHold = static_cast<T**>(lua_touserdata(L, narg));
        if (!ptrHold)
        {
            if (error)
            {
                std::string errmsg(ElunaTemplate<Unit>::tname);
                errmsg += " expected";
                luaL_argerror(L, narg, errmsg.c_str());
            }
            return NULL;
        }
        return *ptrHold;
    }

    static int thunk(lua_State* L)
    {
        T* obj = check(L, 1); // get self
        ElunaRegister<T>* l = static_cast<ElunaRegister<T>*>(lua_touserdata(L, lua_upvalueindex(1)));
        if (!obj)
            return 0;
        return l->mfunc(L, obj);
    }

    static int tostringT(lua_State* L)
    {
        char buff[32];
        T** ptrHold = (T**)lua_touserdata(L, 1);
        sprintf(buff, "%p", *ptrHold);
        lua_pushfstring(L, "%s (%s)", tname, buff);
        return 1;
    }
};

struct EventMgr
{
    struct LuaEvent;

    typedef std::set<LuaEvent*> EventSet;
    typedef std::map<EventProcessor*, EventSet> EventMap;
    // typedef UNORDERED_MAP<uint64, EventProcessor> ProcessorMap;

    EventMap LuaEvents; // LuaEvents[processor] = {LuaEvent, LuaEvent...}
    // ProcessorMap Processors; // Processors[guid] = processor
    EventProcessor GlobalEvents;

    struct LuaEvent : public BasicEvent
    {
        LuaEvent(EventProcessor* _events, int _funcRef, uint32 _delay, uint32 _calls, Object* _obj);

        ~LuaEvent();

        // Should never execute on dead events
        bool Execute(uint64 time, uint32 diff);

        EventProcessor* events; // Pointer to events (holds the timed event)
        int funcRef;    // Lua function reference ID, also used as event ID
        uint32 delay;   // Delay between event calls
        uint32 calls;   // Amount of calls to make, 0 for infinite
        Object* obj;    // Object to push
    };

    // Should be run on world tick
    void Update(uint32 diff)
    {
        GlobalEvents.Update(diff);
    }

    // Updates processor stored for guid || remove from Update()
    // Should be run on gameobject tick
    /*void Update(uint64 guid, uint32 diff)
    {
    if (Processors.find(guid) == Processors.end())
    return;
    Processors[guid].Update(diff);
    }*/

    // Aborts all lua events
    void KillAllEvents(EventProcessor* events)
    {
        if (!events)
            return;
        if (LuaEvents.empty())
            return;
        EventMap::const_iterator it = LuaEvents.find(events); // Get event set
        if (it == LuaEvents.end())
            return;
        if (it->second.empty())
            return;
        for (EventSet::const_iterator itr = it->second.begin(); itr != it->second.end();) // Loop events
            (*(itr++))->to_Abort = true; // Abort event
    }

    // Remove all timed events
    void RemoveEvents()
    {
        if (!LuaEvents.empty())
            for (EventMap::const_iterator it = LuaEvents.begin(); it != LuaEvents.end();) // loop processors
                KillAllEvents((it++)->first);
        LuaEvents.clear(); // remove pointers
        // This is handled automatically on delete
        // for (ProcessorMap::iterator it = Processors.begin(); it != Processors.end();)
        //    (it++)->second.KillAllEvents(true);
        // Processors.clear(); // remove guid saved processors
        GlobalEvents.KillAllEvents(true);
    }

    // Remove timed events from processor
    void RemoveEvents(EventProcessor* events)
    {
        if (!events)
            return;
        KillAllEvents(events);
        LuaEvents.erase(events); // remove pointer set
    }

    // Remove timed events from guid
    // void RemoveEvents(uint64 guid)
    //{
    //    if (Processors.empty())
    //        return;
    //    if (Processors.find(guid) != Processors.end())
    //        LuaEvents.erase(&Processors[guid]);
    //    // Processors[guid].KillAllEvents(true); // remove events
    //    Processors.erase(guid); // remove processor
    //}

    // Adds a new event to the processor and returns the eventID or 0 (Never negative)
    int AddEvent(EventProcessor* events, int funcRef, uint32 delay, uint32 calls, Object* obj = NULL)
    {
        if (!events || funcRef <= 0) // If funcRef <= 0, function reference failed
            return 0; // on fail always return 0. funcRef can be negative.
        events->AddEvent(new LuaEvent(events, funcRef, delay, calls, obj), events->CalculateTime(delay));
        return funcRef; // return the event ID
    }

    // Creates a processor for the guid if needed and adds the event to it
    // int AddEvent(uint64 guid, int funcRef, uint32 delay, uint32 calls, Object* obj = NULL)
    //{
    //    if (!guid) // 0 should be unused
    //        return 0;
    //    return AddEvent(&Processors[guid], funcRef, delay, calls, obj);
    //}

    // Finds the event that has the ID from events
    LuaEvent* GetEvent(EventProcessor* events, int eventId)
    {
        if (!events || !eventId)
            return NULL;
        if (LuaEvents.empty())
            return NULL;
        EventMap::const_iterator it = LuaEvents.find(events); // Get event set
        if (it == LuaEvents.end())
            return NULL;
        if (it->second.empty())
            return NULL;
        for (EventSet::const_iterator itr = it->second.begin(); itr != it->second.end(); ++itr) // Loop events
            if ((*itr) && (*itr)->funcRef == eventId) // Check if the event has our ID
                return *itr; // Return the event if found
        return NULL;
    }

    // Remove the event with the eventId from processor
    // Returns true if event is removed
    bool RemoveEvent(EventProcessor* events, int eventId) // eventId = funcRef
    {
        if (!events || !eventId)
            return false;
        LuaEvent* luaEvent = GetEvent(events, eventId);
        if (!luaEvent)
            return false;
        luaEvent->to_Abort = true; // Set to remove on next call
        LuaEvents[events].erase(luaEvent); // Remove pointer
        return true;
    }

    // Remove event by ID from processor stored for guid
    /*bool RemoveEvent(uint64 guid, int eventId)
    {
    if (Processors.empty())
    return false;
    if (!guid || Processors.find(guid) == Processors.end())
    return false;
    return RemoveEvent(&Processors[guid], eventId);
    }*/

    // Removes the eventId from all events
    void RemoveEvent(int eventId)
    {
        if (!eventId)
            return;
        if (LuaEvents.empty())
            return;
        for (EventMap::const_iterator it = LuaEvents.begin(); it != LuaEvents.end();) // loop processors
            if (RemoveEvent((it++)->first, eventId))
                break; // succesfully remove the event, stop loop.
    }

    ~EventMgr()
    {
        RemoveEvents();
    }
};

class Eluna
{
public:
    friend class ScriptMgr;
    lua_State* L;
    EventMgr m_EventMgr;
    ACE_Thread_Mutex lock;

    Eluna()
    {
        L = NULL;
    }

    ~Eluna()
    {
    }

    struct EventBind
    {
        typedef std::vector<int> ElunaBindingMap;
        typedef std::map<int, ElunaBindingMap> ElunaEntryMap;

        ~EventBind()
        {
            Clear();
        }

        void Clear(); // unregisters all registered functions and clears all registered events from the bind std::maps (reset)
        void Insert(int eventId, int funcRef); // Inserts a new registered event

        // Gets the binding std::map containing all registered events with the function refs for the entry
        ElunaBindingMap* GetBindMap(int eventId)
        {
            if (Bindings.empty())
                return NULL;
            ElunaEntryMap::iterator itr = Bindings.find(eventId);
            if (itr == Bindings.end())
                return NULL;

            return &itr->second;
        }

        // Checks if there are events for ID, if so, cleans stack and pushes eventId
        bool BeginCall(int eventId) const;
        // Loops through all registered events for the eventId at stack index 1
        // Copies the whole stack as arguments for the called function. Before Executing, push all params to stack!
        // Leaves return values from all functions in order to the stack.
        void ExecuteCall();
        void EndCall() const;

        ElunaEntryMap Bindings; // Binding store Bindings[eventId] = {funcRef};
    };

    struct EntryBind
    {
        typedef std::map<int, int> ElunaBindingMap;
        typedef std::map<uint32, ElunaBindingMap> ElunaEntryMap;

        ~EntryBind()
        {
            Clear();
        }

        void Clear(); // unregisters all registered functions and clears all registered events from the bind std::maps (reset)
        void Insert(uint32 entryId, int eventId, int funcRef); // Inserts a new registered event

        // Gets the function ref of an entry for an event
        int GetBind(uint32 entryId, int eventId) const
        {
            if (Bindings.empty())
                return 0;
            ElunaEntryMap::const_iterator itr = Bindings.find(entryId);
            if (itr == Bindings.end() || itr->second.empty())
                return 0;
            ElunaBindingMap::const_iterator itr2 = itr->second.find(eventId);
            if (itr2 == itr->second.end())
                return 0;
            return itr2->second;
        }

        // Gets the binding std::map containing all registered events with the function refs for the entry
        const ElunaBindingMap* GetBindMap(uint32 entryId) const
        {
            if (Bindings.empty())
                return NULL;
            ElunaEntryMap::const_iterator itr = Bindings.find(entryId);
            if (itr == Bindings.end())
                return NULL;

            return &itr->second;
        }

        // Returns true if the entry has registered binds
        bool HasBinds(uint32 entryId) const
        {
            if (Bindings.empty())
                return false;
            return Bindings.find(entryId) != Bindings.end();
        }

        ElunaEntryMap Bindings; // Binding store Bindings[entryId][eventId] = funcRef;
    };

    // Use templates for EventBind
    EventBind PacketEventBindings;
    EventBind ServerEventBindings;
    EventBind PlayerEventBindings;
    EventBind GuildEventBindings;
    EventBind GroupEventBindings;
    EventBind VehicleEventBindings;

    EntryBind CreatureEventBindings;
    EntryBind CreatureGossipBindings;
    EntryBind GameObjectEventBindings;
    EntryBind GameObjectGossipBindings;
    EntryBind ItemEventBindings;
    EntryBind ItemGossipBindings;
    EntryBind playerGossipBindings;

    static void report(lua_State*);
    void Register(uint8 reg, uint32 id, uint32 evt, int func);
    void BeginCall(int fReference);
    bool ExecuteCall(int params, int res);
    void EndCall(int res);
    void LoadDirectory(char* directory, LoadedScripts* scr);

    // Pushes
    void Push(lua_State*); // nil
    void Push(lua_State*, const uint64);
    void Push(lua_State*, const int64);
    void Push(lua_State*, const uint32);
    void Push(lua_State*, const int32);
    void Push(lua_State*, const bool);
    void Push(lua_State*, const float);
    void Push(lua_State*, const double);
    void Push(lua_State*, const char*);
    void Push(lua_State*, const std::string);
    template<typename T> void Push(lua_State* L, T const* ptr)
    {
        ElunaTemplate<T>::push(L, ptr);
    }
    void Push(lua_State* L, Object const* obj);
    void Push(lua_State* L, WorldObject const* obj);
    void Push(lua_State* L, Unit const* unit);
    void Push(lua_State* L, Pet const* pet);
    void Push(lua_State* L, TempSummon const* summon);

    // Checks
    template<typename T> T CHECKVAL(lua_State* L, int narg);
    template<typename T> T CHECKVAL(lua_State* L, int narg, T def);
    template<typename T> T* CHECKOBJ(lua_State* L, int narg, bool error = true)
    {
        return ElunaTemplate<T>::check(L, narg, error);
    }

    struct ObjectGUIDCheck
    {
        ObjectGUIDCheck(GUID_TYPE guid) : _guid(guid) { }
        bool operator()(WorldObject* object)
        {
            return object->GET_GUID() == _guid;
        }

        GUID_TYPE _guid;
    };

    // Binary predicate to sort WorldObjects based on the distance to a reference WorldObject
    struct ObjectDistanceOrderPred
    {
        ObjectDistanceOrderPred(WorldObject const* pRefObj, bool ascending = true) : m_refObj(pRefObj), m_ascending(ascending) { }
        bool operator()(WorldObject const* pLeft, WorldObject const* pRight) const
        {
            return m_ascending ? m_refObj->GetDistanceOrder(pLeft, pRight) : !m_refObj->GetDistanceOrder(pLeft, pRight);
        }

        WorldObject const* m_refObj;
        const bool m_ascending;
    };

    // Doesn't get self
    struct WorldObjectInRangeCheck
    {
        WorldObjectInRangeCheck(bool nearest, WorldObject const* obj, float range,
            uint16 typeMask = 0, uint32 entry = 0, uint32 hostile = 0) : i_nearest(nearest),
            i_obj(obj), i_range(range), i_typeMask(typeMask), i_entry(entry), i_hostile(hostile) {}
        WorldObject const& GetFocusObject() const { return *i_obj; }
        bool operator()(WorldObject* u)
        {
            if (i_typeMask && !u->isType(TypeMask(i_typeMask)))
                return false;
            if (i_entry && u->GetEntry() != i_entry)
                return false;
            if (i_obj->GET_GUID() == u->GET_GUID())
                return false;
            if (!i_obj->IsWithinDistInMap(u, i_range))
                return false;
            if (Unit* unit = u->ToUnit())
            {
#ifdef MANGOS
                if (!unit->isAlive())
                    return false;
#else
                if (!unit->IsAlive())
                    return false;
#endif
                if (i_hostile)
                {
                    if (const Unit* obj = i_obj->ToUnit())
                    {
                        if ((i_hostile == 1) != obj->IsHostileTo(unit))
                            return false;
                    }
                }
            }
            if (i_nearest)
                i_range = i_obj->GetDistance(u);
            return true;
        }

        WorldObject const* i_obj;
        float i_range;
        uint16 i_typeMask;
        uint32 i_entry;
        bool i_nearest;
        uint32 i_hostile;

        WorldObjectInRangeCheck(WorldObjectInRangeCheck const&);
    };
};
template<> Unit* Eluna::CHECKOBJ<Unit>(lua_State* L, int narg, bool error);
template<> Player* Eluna::CHECKOBJ<Player>(lua_State* L, int narg, bool error);
template<> Creature* Eluna::CHECKOBJ<Creature>(lua_State* L, int narg, bool error);
template<> GameObject* Eluna::CHECKOBJ<GameObject>(lua_State* L, int narg, bool error);
template<> Corpse* Eluna::CHECKOBJ<Corpse>(lua_State* L, int narg, bool error);

#ifdef MANGOS
#define sEluna (&MaNGOS::Singleton<Eluna>::Instance())
#else
#define sEluna ACE_Singleton<Eluna, ACE_Null_Mutex>::instance()
#endif

class LuaTaxiMgr
{
private:
    static uint32 nodeId;
public:
    static void StartTaxi(Player* player, uint32 pathid);
    static uint32 AddPath(std::list<TaxiPathNodeEntry> nodes, uint32 mountA, uint32 mountH, uint32 price = 0, uint32 pathId = 0);
};
#endif
