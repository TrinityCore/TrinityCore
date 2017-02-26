#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class FollowChatShortcutAction : public Action
    {
    public:
        FollowChatShortcutAction(PlayerbotAI* ai) : Action(ai, "follow chat shortcut") {}
        virtual bool Execute(Event event);
    };

    class StayChatShortcutAction : public Action
    {
    public:
        StayChatShortcutAction(PlayerbotAI* ai) : Action(ai, "stay chat shortcut") {}
        virtual bool Execute(Event event);
    };

    class FleeChatShortcutAction : public Action
    {
    public:
        FleeChatShortcutAction(PlayerbotAI* ai) : Action(ai, "flee chat shortcut") {}
        virtual bool Execute(Event event);
    };

    class GoawayChatShortcutAction : public Action
    {
    public:
        GoawayChatShortcutAction(PlayerbotAI* ai) : Action(ai, "runaway chat shortcut") {}
        virtual bool Execute(Event event);
    };

    class GrindChatShortcutAction : public Action
    {
    public:
        GrindChatShortcutAction(PlayerbotAI* ai) : Action(ai, "grind chat shortcut") {}
        virtual bool Execute(Event event);
    };

    class TankAttackChatShortcutAction : public Action
    {
    public:
        TankAttackChatShortcutAction(PlayerbotAI* ai) : Action(ai, "tank attack chat shortcut") {}
        virtual bool Execute(Event event);
    };

    class MaxDpsChatShortcutAction : public Action
    {
    public:
        MaxDpsChatShortcutAction(PlayerbotAI* ai) : Action(ai, "max dps chat shortcut") {}
        virtual bool Execute(Event event);
    };

}
