#pragma once

#include "../../PlayerbotAIConfig.h"
#include "../../RandomPlayerbotMgr.h"
#include "../../ServerFacade.h"
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

            if (sServerFacade.IsInCombat(bot))
                return true;

            ai->SetNextCheckDelay(sPlayerbotAIConfig.passiveDelay + sPlayerbotAIConfig.globalCoolDown);
            return true;
        }
    };

}
