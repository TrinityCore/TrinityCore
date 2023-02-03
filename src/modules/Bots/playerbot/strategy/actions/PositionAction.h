#pragma once

#include "../Action.h"
#include "MovementActions.h"

namespace ai
{
    class PositionAction : public Action
    {
    public:
        PositionAction(PlayerbotAI* ai) : Action(ai, "position")
        {}

        virtual bool Execute(Event event);
    };

    class MoveToPositionAction : public MovementAction
    {
    public:
        MoveToPositionAction(PlayerbotAI* ai, string name, string qualifier, bool idle = false) :
            MovementAction(ai, name), qualifier(qualifier), idle(idle)
        {}

        virtual bool Execute(Event event);
        virtual bool isUseful();

    protected:
        string qualifier;
        bool idle;
    };

    class GuardAction : public MoveToPositionAction
    {
    public:
        GuardAction(PlayerbotAI* ai) : MoveToPositionAction(ai, "move to position", "guard") {}
    };

    class SetReturnPositionAction : public Action
    {
    public:
        SetReturnPositionAction(PlayerbotAI* ai) : Action(ai, "set return position")
        {}

        virtual bool Execute(Event event);
        virtual bool isUseful();
    };

    class ReturnAction : public MoveToPositionAction
    {
    public:
        ReturnAction(PlayerbotAI* ai) : MoveToPositionAction(ai, "return", "random", true) {}

        virtual bool isUseful();
    };

}
