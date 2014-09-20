#pragma once

#include "../Action.h"

namespace ai
{
    class EmoteAction : public Action
    {
    public:
        EmoteAction(PlayerbotAI* ai) : Action(ai, "emote") {}
        virtual bool Execute(Event event);

    private:
        void InitEmotes();
        static map<string, uint32> emotes;

    };
}
