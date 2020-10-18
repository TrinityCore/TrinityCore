/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef _ELUNA_EVENT_MGR_H
#define _ELUNA_EVENT_MGR_H

#include "ElunaUtility.h"
#include "Common.h"
#ifdef TRINITY
#include "Random.h"
#else
#include "Util.h"
#endif
#include <map>

#if defined(TRINITY) || AZEROTHCORE
#include "Define.h"
#else
#include "Platform/Define.h"
#endif

class Eluna;
class EventMgr;
class ElunaEventProcessor;
class WorldObject;

enum LuaEventState
{
    LUAEVENT_STATE_RUN,    // On next call run the function normally
    LUAEVENT_STATE_ABORT,  // On next call unregisters reffed function and erases the data
    LUAEVENT_STATE_ERASE,  // On next call just erases the data
};

struct LuaEvent
{
    LuaEvent(int _funcRef, uint32 _min, uint32 _max, uint32 _repeats) :
        min(_min), max(_max), delay(0), repeats(_repeats), funcRef(_funcRef), state(LUAEVENT_STATE_RUN)
    {
    }

    void SetState(LuaEventState _state)
    {
        if (state != LUAEVENT_STATE_ERASE)
            state = _state;
    }

    void GenerateDelay()
    {
        delay = urand(min, max);
    }

    uint32 min;   // Minimum delay between event calls
    uint32 max;   // Maximum delay between event calls
    uint32 delay; // The currently used waiting time
    uint32 repeats; // Amount of repeats to make, 0 for infinite
    int funcRef;    // Lua function reference ID, also used as event ID
    LuaEventState state;    // State for next call
};

class ElunaEventProcessor
{
    friend class EventMgr;

public:
    typedef std::multimap<uint64, LuaEvent*> EventList;
    typedef std::unordered_map<int, LuaEvent*> EventMap;

    ElunaEventProcessor(Eluna** _E, WorldObject* _obj);
    ~ElunaEventProcessor();

    void Update(uint32 diff);
    // removes all timed events on next tick or at tick end
    void SetStates(LuaEventState state);
    // set the event to be removed when executing
    void SetState(int eventId, LuaEventState state);
    void AddEvent(int funcRef, uint32 min, uint32 max, uint32 repeats);
    EventMap eventMap;

private:
    void RemoveEvents_internal();
    void AddEvent(LuaEvent* luaEvent);
    void RemoveEvent(LuaEvent* luaEvent);
    EventList eventList;
    uint64 m_time;
    WorldObject* obj;
    Eluna** E;
};

class EventMgr : public ElunaUtil::Lockable
{
public:
    typedef std::unordered_set<ElunaEventProcessor*> ProcessorSet;
    ProcessorSet processors;
    ElunaEventProcessor* globalProcessor;
    Eluna** E;

    EventMgr(Eluna** _E);
    ~EventMgr();

    // Set the state of all timed events
    // Execute only in safe env
    void SetStates(LuaEventState state);

    // Sets the eventId's state in all processors
    // Execute only in safe env
    void SetState(int eventId, LuaEventState state);
};

#endif
