#pragma once

#include "../Action.h"

namespace ai
{
    class EmoteActionBase : public Action
    {
    public:
        EmoteActionBase(PlayerbotAI* ai, string name);

    protected:
        bool Emote(Unit* target, uint32 type);
        Unit* GetTarget();
        void InitEmotes();
        static map<string, uint32> emotes;
        static map<string, uint32> textEmotes;

    };

    class EmoteAction : public EmoteActionBase, public Qualified
    {
    public:
        EmoteAction(PlayerbotAI* ai);
        virtual bool Execute(Event event);
        bool isUseful();
    };

    class TalkAction : public EmoteActionBase
    {
    public:
        TalkAction(PlayerbotAI* ai) : EmoteActionBase(ai, "talk") {}
        virtual bool Execute(Event event);

        static uint32 GetRandomEmote(Unit* unit);
    };
}
