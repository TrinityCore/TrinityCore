#pragma once

#include "../AiObjectContext.h"

namespace ai
{
    class HunterAiObjectContext : public AiObjectContext
    {
    public:
        HunterAiObjectContext(PlayerbotAI* ai);
    };
}