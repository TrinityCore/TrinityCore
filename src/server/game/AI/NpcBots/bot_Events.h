#ifndef _BOT_EVENTS_H
#define _BOT_EVENTS_H

#include "EventProcessor.h"

/*
Name: bot_Events
%Complete: ???
Comment: Custom event types for NPCBot system by Trickerer (onlysuffering@gmail.com)
Category: creature_cripts/custom/bots/events

Notes:
All events must be executed through botAI
*/

//Teleport home: near or far, only used for free bots
class TeleportHomeEvent : public BasicEvent
{
    friend class bot_ai;
    protected:
        TeleportHomeEvent(bot_ai* ai) : _ai(ai) {}
        ~TeleportHomeEvent() {}

        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
        {
            _ai->TeleportHome();
            return true;
        }

    private:
        bot_ai* _ai;
};
//Delayed teleport finish: adds bot back to world on new location
class TeleportFinishEvent : public BasicEvent
{
    friend class bot_ai;
    friend class BotMgr;
    protected:
        TeleportFinishEvent(bot_ai* ai) : _ai(ai) {}
        ~TeleportFinishEvent() {}

        //Execute is always called while creature is out of world so ai is never deleted
        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
        {
            _ai->FinishTeleport();
            return true;
        }

    private:
        bot_ai* _ai;
};

#endif
