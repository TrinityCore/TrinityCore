#pragma once

#include "../Action.h"
#include "../../../Quests/QuestDef.h"

namespace ai
{
    class QuestAction : public Action
    {
    public:
        QuestAction(PlayerbotAI* ai, string name) : Action(ai, name) {}

    public:
        virtual bool Execute(Event event);

    protected:
        virtual void ProcessQuest(Quest const* quest, WorldObject* questGiver) = 0;

    protected:
        bool AcceptQuest(Quest const* quest, uint64 questGiver);
        bool ProcessQuests(ObjectGuid questGiver);
        bool ProcessQuests(WorldObject* questGiver);
    };

    class QuestObjectiveCompletedAction : public Action
    {
    public:
        QuestObjectiveCompletedAction(PlayerbotAI* ai) : Action(ai, "quest objective completed") {}

    public:
        virtual bool Execute(Event event);
    };
}
