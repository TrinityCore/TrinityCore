#pragma once

#include "../../ServerFacade.h"
#include "../Action.h"

namespace ai
{
    class AcceptResurrectAction : public Action {
    public:
        AcceptResurrectAction(PlayerbotAI* ai) : Action(ai, "accept resurrect") {}

        virtual bool Execute(Event event)
        {
            if (sServerFacade.IsAlive(bot))
                return false;

            WorldPacket p(event.getPacket());
            p.rpos(0);
            ObjectGuid guid;
            p >> guid;

            WorldPacket packet(CMSG_RESURRECT_RESPONSE, 8+1);
            packet << guid;
            packet << uint8(1);                        // accept
            bot->GetSession()->HandleResurrectResponseOpcode(packet);   // queue the packet to get around race condition

            ai->ChangeEngine(BOT_STATE_NON_COMBAT);
            return true;
        }
    };

}
