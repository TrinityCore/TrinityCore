#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class LfgJoinAction : public InventoryAction
    {
    public:
        LfgJoinAction(PlayerbotAI* ai, string name = "lfg join") : InventoryAction(ai, name) {}
        virtual bool Execute(Event event);

    protected:
        bool JoinProposal();
        bool SetRoles();
        uint8 GetRoles();
    };

    class LfgAcceptAction : public LfgJoinAction
    {
    public:
        LfgAcceptAction(PlayerbotAI* ai) : LfgJoinAction(ai, "lfg accept") {}
        virtual bool Execute(Event event);
    };

    class LfgRoleCheckAction : public LfgJoinAction
    {
    public:
        LfgRoleCheckAction(PlayerbotAI* ai) : LfgJoinAction(ai, "lfg role check") {}
        virtual bool Execute(Event event);
    };

    class LfgLeaveAction : public Action
    {
    public:
        LfgLeaveAction(PlayerbotAI* ai) : Action(ai, "lfg leave") {}
        virtual bool Execute(Event event);
    };

    class LfgTeleportAction : public Action
    {
    public:
        LfgTeleportAction(PlayerbotAI* ai) : Action(ai, "lfg teleport") {}
        virtual bool Execute(Event event);
    };

}
