#pragma once

#include "../AiObjectContext.h"

namespace ai
{
    class PaladinAiObjectContext : public AiObjectContext
    {
    public:
        PaladinAiObjectContext(PlayerbotAI* ai);
    };
}