#ifndef _BOT_EVENTS_H
#define _BOT_EVENTS_H

//#include "Player.h"
//#include "SpellAuras.h"
//#include "bot_ai.h"
#include "Creature.h"
//#include "MapManager.h"
/*
Name: bot_Events
%Complete: 1
Comment: Custom event types for NPCBot system by Graff (onlysuffering@gmail.com)
Category: creature_cripts/custom/bots/events

Notes:
All events must be executed through botAI
*/
//DEPRECATED Visibility update: needed after near teleport
//class VisibilityUpdateEvent : public BasicEvent
//{
//    friend class bot_minion_ai;
//    protected:
//        VisibilityUpdateEvent(uint64 botGuid, bool force = true) : _botGuid(botGuid), _force(force) { }
//        ~VisibilityUpdateEvent() {}
//
//        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
//        {
//            if (Creature* bot = ObjectAccessor::GetObjectInWorld(_botGuid, (Creature*)NULL))
//            {
//                bot->GetBotMinionAI()->UpdateBotVisibility(_force);
//                return true;
//            }
//            return false;
//        }
//
//    private:
//        uint64 _botGuid;
//        bool _force;
//};
//Teleport home: near or far, only used for free bots
class TeleportHomeEvent : public BasicEvent
{
    friend class bot_minion_ai;
    friend class bot_ai;
    protected:
        TeleportHomeEvent(bot_minion_ai* ai/*, uint64 botGuid*/) :
             _ai(ai)/*, _botGuid(botGuid)*/
             { }
        ~TeleportHomeEvent() {}

        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
        {
            _ai->TeleportHome();
            return true;
        }

    private:
        bot_minion_ai* _ai;
        //uint64 _botGuid;
};
//DEPRECATEDEvade mode enable/disable: adds UNIT_STATE_EVADE
//class EvadeEvent : public BasicEvent
//{
//    friend class bot_minion_ai;
//    protected:
//        EvadeEvent(uint64 botGuid, bool apply) : _botGuid(botGuid), _apply(apply) { }
//        ~EvadeEvent() {}
//
//        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
//        {
//            if (Creature* bot = ObjectAccessor::GetObjectInWorld(_botGuid, (Creature*)NULL))
//            {
//                bot->GetBotMinionAI()->SetEvade(_apply);
//                return true;
//            }
//            return false;
//        }
//
//    private:
//        uint64 _botGuid;
//        bool _apply;
//};
//Delayed teleport finish: adds bot back to world on new location
class TeleportFinishEvent : public BasicEvent
{
    friend class bot_minion_ai;
    friend class BotMgr;
    protected:
        TeleportFinishEvent(bot_minion_ai* ai/*, uint32 mapId, uint32 instanceId, float x, float y, float z, float o*/) :
             _ai(ai)//, _mapId(mapId), _instanceId(instanceId), _x(x), _y(y), _z(z), _o(o)
             { }
        ~TeleportFinishEvent() {}

        //Execute is always called while creature is out of world so ai is never deleted
        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
        {
            _ai->FinishTeleport(/*_mapId, _instanceId, _x, _y, _z, _o*/);
            return true;
        }

    private:
        bot_minion_ai* _ai;
        //uint32 _mapId;
        //uint32 _instanceId;
        //float _x;
        //float _y;
        //float _z;
        //float _o;
};
//DEPRECATED
//class NearTeleportEvent : public BasicEvent
//{
//    friend class bot_ai;
//    protected:
//        NearTeleportEvent(uint64 botGuid, Position* pos) : _botGuid(botGuid), _pos(pos) { }
//        ~NearTeleportEvent() {}
//
//        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
//        {
//            if (Creature* bot = ObjectAccessor::GetObjectInWorld(_botGuid, (Creature*)NULL))
//            {
//                bot->Relocate(_pos);
//                return true;
//            }
//            return false;
//        }
//
//    private:
//        uint64 _botGuid;
//        Position* _pos;
//};

#endif
