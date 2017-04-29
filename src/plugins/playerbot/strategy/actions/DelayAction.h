#pragma once

#include "../../PlayerbotAIConfig.h"
#include "../../RandomPlayerbotMgr.h"
#include "../Action.h"

namespace ai
{
    class DelayAction : public Action
    {
    public:
        DelayAction(PlayerbotAI* ai) : Action(ai, "delay")
        {}

        virtual bool Execute(Event event)
        {
            if (!sRandomPlayerbotMgr.IsRandomBot(bot) || bot->GetGroup() || ai->GetMaster())
                return false;

            if (bot->IsInCombat())
                return true;

            ai->SetNextCheckDelay(sPlayerbotAIConfig.maxWaitForMove + sPlayerbotAIConfig.globalCoolDown);
            return true;
        }
    };

}
