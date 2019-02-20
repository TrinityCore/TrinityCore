#pragma once

#include "../Action.h"

namespace ai
{
    class EmoteAction : public Action, public Qualified
    {
    public:
        EmoteAction(PlayerbotAI* ai) : Action(ai, "emote"), Qualified() {}
        virtual bool Execute(Event event);
        bool isUseful();

    private:
        void InitEmotes();
        static map<string, uint32> emotes;
        static map<string, uint32> textEmotes;

    };
}
