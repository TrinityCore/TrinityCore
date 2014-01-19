/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
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

typedef std::set<std::string> LoadedScripts;

template<class T>
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

        // If assertion fails, should check if obj really should have gc on
        // If gc / memory management is true, may need specialized function for GetTPointer to copy object using GetNewTPointerin LuaEngine.cpp
        static T const* GetNewTPointer(T const& obj) { ASSERT(manageMemory); return new T(obj); }
        static T const* GetTPointer(T const& obj) { return &obj; }

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
            if (lua_isnil(L, -1))
                luaL_error(L, "%s missing metatable", tname);
            T const** ptrHold = (T const**)lua_newuserdata(L, sizeof(T**));
            if (ptrHold)
            {
                *ptrHold = GetTPointer(*obj);
                lua_pushvalue(L, -2);
                lua_setmetatable(L, -2);
            }
            lua_replace(L, -2);
            return lua_gettop(L);
        }

        static T* check(lua_State* L, int narg)
        {
            T** ptrHold = static_cast<T**>(lua_touserdata(L, narg));
            if (!ptrHold)
                return NULL;
            return *ptrHold;
        }

        static int thunk(lua_State* L)
        {
            T* obj = check(L, 1); // get self
            lua_remove(L, 1); // remove self
            ElunaRegister<T>* l = static_cast<ElunaRegister<T>*>(lua_touserdata(L, lua_upvalueindex(1)));
            if (!obj)
                return 0;
            return l->mfunc(L, obj);
        }

        static int tostringT(lua_State* L)
        {
            char buff[32];
            T** ptrHold = (T**)lua_touserdata(L, 1);
            T* obj = *ptrHold;
            sprintf(buff, "%p", obj);
            lua_pushfstring(L, "%s (%s)", tname, buff);
            return 1;
        }
};

struct EventMgr
{
    struct LuaEvent;

    typedef std::set<LuaEvent*> EventSet;
    typedef std::map<EventProcessor*, EventSet> EventMap;
    typedef UNORDERED_MAP<uint64, EventProcessor> ProcessorMap;

    EventMap LuaEvents; // LuaEvents[processor] = {LuaEvent, LuaEvent...}
    ProcessorMap Processors; // Processors[guid] = processor
    EventProcessor GlobalEvents;

    struct LuaEvent : public BasicEvent
    {
        LuaEvent(EventProcessor* _events, int _funcRef, uint32 _delay, uint32 _calls, Object* _obj);

        ~LuaEvent();

        // Should never execute on dead events
        bool Execute(uint64 time, uint32 diff);

        bool hasObject; // Dont call event if object no longer exists
        Object* obj;    // Object to push
        int funcRef;    // Lua function reference ID, also used as event ID
        uint32 delay;   // Delay between event calls
        uint32 calls;   // Amount of calls to make, 0 for infinite
        EventProcessor* events; // Pointer to events (holds the timed event)
    };

    // Updates all processors stored in the manager
    // Should be run on world tick
    void Update(uint32 diff)
    {
        GlobalEvents.Update(diff);
        for (ProcessorMap::iterator it = Processors.begin(); it != Processors.end(); ++it)
            it->second.Update(diff);
    }

    /*
    // Updates processor stored for guid || remove from Update()
    // Should be run on gameobject tick
    static void Update(uint64 guid, uint32 diff)
    {
        if (Processors.find(guid) == Processors.end())
            return;
        Processors[guid].Update(diff);
    }
    */

    // Aborts all lua events
    void KillAllEvents(EventProcessor* events)
    {
        if (!events)
            return;
        EventMap::const_iterator it = LuaEvents.find(events); // Get event set
        if (it == LuaEvents.end())
            return;
        for (EventSet::const_iterator itr = it->second.begin(); itr != it->second.end();) // Loop events
            (*(itr++))->to_Abort = true; // Abort event
    }

    // Remove all timed events
    void RemoveEvents()
    {
        for (EventMap::const_iterator it = LuaEvents.begin(); it != LuaEvents.end();) // loop processors
            KillAllEvents((it++)->first);
        LuaEvents.clear(); // remove pointers
        // This is handled automatically on delete
        /*for (ProcessorMap::iterator it = Processors.begin(); it != Processors.end();)
            (it++)->second.KillAllEvents(true);*/
        Processors.clear(); // remove guid saved processors
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
    void RemoveEvents(uint64 guid)
    {
        if (Processors.find(guid) != Processors.end())
            LuaEvents.erase(&Processors[guid]);
        //Processors[guid].KillAllEvents(true); // remove events
        Processors.erase(guid); // remove processor
    }

    // Adds a new event to the processor and returns the eventID or 0 (Never negative)
    int AddEvent(EventProcessor* events, int funcRef, uint32 delay, uint32 calls, Object* obj = NULL)
    {
        if (!events || funcRef <= 0) // If funcRef <= 0, function reference failed
            return 0; // on fail always return 0. funcRef can be negative.
        events->AddEvent(new LuaEvent(events, funcRef, delay, calls, obj), events->CalculateTime(delay));
        return funcRef; // return the event ID
    }

    // Creates a processor for the guid if needed and adds the event to it
    int AddEvent(uint64 guid, int funcRef, uint32 delay, uint32 calls, Object* obj = NULL)
    {
        if (!guid) // 0 should be unused
            return 0;
        return AddEvent(&Processors[guid], funcRef, delay, calls, obj);
    }

    // Finds the event that has the ID from events
    LuaEvent* GetEvent(EventProcessor* events, int eventId)
    {
        if (!events || !eventId)
            return NULL;
        EventMap::const_iterator it = LuaEvents.find(events); // Get event set
        if (it == LuaEvents.end())
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
    bool RemoveEvent(uint64 guid, int eventId)
    {
        if (!guid || Processors.find(guid) == Processors.end())
            return false;
        return RemoveEvent(&Processors[guid], eventId);
    }

    // Removes the eventId from all events
    void RemoveEvent(int eventId)
    {
        if (!eventId)
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

        struct ElunaBind;
        std::map<int, std::vector<int> > PacketEventBindings;
        std::map<int, std::vector<int> > ServerEventBindings;
        std::map<int, std::vector<int> > PlayerEventBindings;
        std::map<int, std::vector<int> > VehicleEventBindings;
        std::map<int, std::vector<int> > GuildEventBindings;
        std::map<int, std::vector<int> > GroupEventBindings;
        ElunaBind* CreatureEventBindings;
        ElunaBind* CreatureGossipBindings;
        ElunaBind* GameObjectEventBindings;
        ElunaBind* GameObjectGossipBindings;
        ElunaBind* ItemEventBindings;
        ElunaBind* ItemGossipBindings;
        ElunaBind* playerGossipBindings;

        void Initialize();
        static void report(lua_State*);
        void Register(uint8 reg, uint32 id, uint32 evt, int func);
        void BeginCall(int fReference);
        bool ExecuteCall(uint8 params, uint8 res);
        void EndCall(uint8 res);
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

        void Push(lua_State* L, Pet const* pet)
        {
            Push(L, pet->ToCreature());
        }

        void Push(lua_State* L, TempSummon const* summon)
        {
            Push(L, summon->ToCreature());
        }

        void Push(lua_State* L, Unit const* unit)
        {
            if (!unit)
            {
                Push(L);
                return;
            }
            switch (unit->GetTypeId())
            {
                case TYPEID_UNIT:
                    Push(L, unit->ToCreature());
                    break;
                case TYPEID_PLAYER:
                    Push(L, unit->ToPlayer());
                    break;
                default:
                    ElunaTemplate<Unit>::push(L, unit);
            }
        }

        void Push(lua_State*, WorldObject const* obj)
        {
            if (!obj)
            {
                Push(L);
                return;
            }
            switch (obj->GetTypeId())
            {
                case TYPEID_UNIT:
                    Push(L, obj->ToCreature());
                    break;
                case TYPEID_PLAYER:
                    Push(L, obj->ToPlayer());
                    break;
                case TYPEID_GAMEOBJECT:
                    Push(L, obj->ToGameObject());
                    break;
                case TYPEID_CORPSE:
                    Push(L, obj->ToCorpse());
                    break;
                default:
                    ElunaTemplate<WorldObject>::push(L, obj);
            }
        }

        void Push(lua_State* L, Object const* obj)
        {
            if (!obj)
            {
                Push(L);
                return;
            }
            switch (obj->GetTypeId())
            {
                case TYPEID_UNIT:
                    Push(L, obj->ToCreature());
                    break;
                case TYPEID_PLAYER:
                    Push(L, obj->ToPlayer());
                    break;
                case TYPEID_GAMEOBJECT:
                    Push(L, obj->ToGameObject());
                    break;
                case TYPEID_CORPSE:
                    Push(L, obj->ToCorpse());
                    break;
                default:
                    ElunaTemplate<Object>::push(L, obj);
            }
        }

        // Checks
        WorldPacket* CHECK_PACKET(lua_State* L, int narg);
        Object* CHECK_OBJECT(lua_State* L, int narg);
        WorldObject* CHECK_WORLDOBJECT(lua_State* L, int narg);
        Unit* CHECK_UNIT(lua_State* L, int narg);
        Player* CHECK_PLAYER(lua_State* L, int narg);
        Creature* CHECK_CREATURE(lua_State* L, int narg);
        GameObject* CHECK_GAMEOBJECT(lua_State* L, int narg);
        Vehicle* CHECK_VEHICLE(lua_State* L, int narg);
        Corpse* CHECK_CORPSE(lua_State* L, int narg);
        Quest* CHECK_QUEST(lua_State* L, int narg);
        Spell* CHECK_SPELL(lua_State* L, int narg);
        uint64 CHECK_ULONG(lua_State* L, int narg);
        int64 CHECK_LONG(lua_State* L, int narg);
        Item* CHECK_ITEM(lua_State* L, int narg);

        // Creates new binding stores
        Eluna()
        {
            L = NULL;

            for (int i = 0; i < NUM_MSG_TYPES; ++i)
            {
                std::vector<int> _vector;
                PacketEventBindings.insert(std::pair<int, std::vector<int> >(i, _vector));
            }

            for (int i = 0; i < SERVER_EVENT_COUNT; ++i)
            {
                std::vector<int> _vector;
                ServerEventBindings.insert(std::pair<int, std::vector<int> >(i, _vector));
            }

            for (int i = 0; i < PLAYER_EVENT_COUNT; ++i)
            {
                std::vector<int> _vector;
                PlayerEventBindings.insert(std::pair<int, std::vector<int> >(i, _vector));
            }

            for (int i = 0; i < VEHICLE_EVENT_COUNT; ++i)
            {
                std::vector<int> _vector;
                VehicleEventBindings.insert(std::pair<int, std::vector<int> >(i, _vector));
            }

            for (int i = 0; i < GUILD_EVENT_COUNT; ++i)
            {
                std::vector<int> _vector;
                GuildEventBindings.insert(std::pair<int, std::vector<int> >(i, _vector));
            }

            for (int i = 0; i < GROUP_EVENT_COUNT; ++i)
            {
                std::vector<int> _vector;
                GroupEventBindings.insert(std::pair<int, std::vector<int> >(i, _vector));
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
                    luaL_unref(L, LUA_REGISTRYINDEX, (*it));
                itr->second.clear();
            }

            for (std::map<int, std::vector<int> >::iterator itr = PlayerEventBindings.begin(); itr != PlayerEventBindings.end(); ++itr)
            {
                for (std::vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                    luaL_unref(L, LUA_REGISTRYINDEX, (*it));
                itr->second.clear();
            }

            for (std::map<int, std::vector<int> >::iterator itr = VehicleEventBindings.begin(); itr != VehicleEventBindings.end(); ++itr)
            {
                for (std::vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                    luaL_unref(L, LUA_REGISTRYINDEX, (*it));
                itr->second.clear();
            }

            for (std::map<int, std::vector<int> >::iterator itr = GuildEventBindings.begin(); itr != GuildEventBindings.end(); ++itr)
            {
                for (std::vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                    luaL_unref(L, LUA_REGISTRYINDEX, (*it));
                itr->second.clear();
            }

            for (std::map<int, std::vector<int> >::iterator itr = GroupEventBindings.begin(); itr != GroupEventBindings.end(); ++itr)
            {
                for (std::vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                    luaL_unref(L, LUA_REGISTRYINDEX, (*it));
                itr->second.clear();
            }
            PacketEventBindings.clear();
            ServerEventBindings.clear();
            PlayerEventBindings.clear();
            VehicleEventBindings.clear();
            GuildEventBindings.clear();
            GroupEventBindings.clear();
            CreatureEventBindings->Clear();
            CreatureGossipBindings->Clear();
            GameObjectEventBindings->Clear();
            GameObjectGossipBindings->Clear();
            ItemEventBindings->Clear();
            ItemGossipBindings->Clear();
            playerGossipBindings->Clear();

            lua_close(L); // Closing
        }

        struct ElunaBind
        {
            typedef std::map<int, int> ElunaBindingMap;
            typedef UNORDERED_MAP<uint32, ElunaBindingMap> ElunaEntryMap;

            void Clear(); // unregisters all registered functions and clears all registered events from the bind std::maps (reset)
            void Insert(uint32 entryId, uint32 eventId, int funcRef); // Inserts a new registered event

            // Gets the function ref of an entry for an event
            int GetBind(uint32 entryId, uint32 eventId)
            {
                if (Bindings.empty())
                    return 0;
                ElunaEntryMap::iterator itr = Bindings.find(entryId);
                if (itr == Bindings.end())
                    return 0;

                return itr->second[eventId];
            }

            // Gets the binding std::map containing all registered events with the function refs for the entry
            ElunaBindingMap* GetBindMap(uint32 entryId)
            {
                if (Bindings.empty())
                    return NULL;
                ElunaEntryMap::iterator itr = Bindings.find(entryId);
                if (itr == Bindings.end())
                    return NULL;

                return &itr->second;
            }

            ElunaEntryMap Bindings; // Binding store Bindings[entryId][eventId] = funcRef;
        };

        struct ObjectGUIDCheck
        {
            ObjectGUIDCheck(uint64 GUID) : _GUID(GUID) { }
            bool operator()(WorldObject* object)
            {
                return object->GetGUID() == _GUID;
            }

            uint64 _GUID;
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
                if (i_obj->GetGUID() == u->GetGUID())
                    return false;
                if (!i_obj->IsWithinDistInMap(u, i_range))
                    return false;
                if (Unit* unit = u->ToUnit())
                {
                    if (!unit->IsAlive())
                        return false;
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
#define sEluna ACE_Singleton<Eluna, ACE_Null_Mutex>::instance()

class LuaTaxiMgr
{
    private:
        static uint32 nodeId;
    public:
        static void StartTaxi(Player* player, uint32 pathid);
        static uint32 AddPath(std::list<TaxiPathNodeEntry> nodes, uint32 mountA, uint32 mountH, uint32 price = 0, uint32 pathId = 0);
};
#endif
