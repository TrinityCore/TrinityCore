#pragma once

namespace ai
{
    class PlayerbotAIAware 
    {
    public:
        PlayerbotAIAware(PlayerbotAI* const ai) : ai(ai) { }

    protected:
        PlayerbotAI* ai;
    };
}