#pragma once

#include "../Action.h"

namespace ai
{
    class PassLeadershipToMasterAction : public Action {
    public:
        PassLeadershipToMasterAction(PlayerbotAI* ai) : Action(ai, "leader") {}

        virtual bool Execute(Event event)
        {
            Player* master = GetMaster();
            if (master && bot->GetGroup() && bot->GetGroup()->IsMember(master->GetGUID()))
            {
                WorldPacket p(SMSG_GROUP_SET_LEADER, 8);
                p << master->GetGUID();
                bot->GetSession()->HandleGroupSetLeaderOpcode(p);
                return true;
            }

            return false;
        }
    };

}
