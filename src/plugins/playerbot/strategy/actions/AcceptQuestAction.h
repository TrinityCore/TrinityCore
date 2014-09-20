#pragma once

#include "../Action.h"
#include "QuestAction.h"

namespace ai
{
    class AcceptAllQuestsAction : public QuestAction {
    public:
        AcceptAllQuestsAction(PlayerbotAI* ai, string name = "accept all quests") : QuestAction(ai, name) {}

    protected:
        virtual void ProcessQuest(Quest const* quest, WorldObject* questGiver);
    };

    class AcceptQuestAction : public AcceptAllQuestsAction {
    public:
        AcceptQuestAction(PlayerbotAI* ai) : AcceptAllQuestsAction(ai, "accept quest") {}
        virtual bool Execute(Event event);
    };

    class AcceptQuestShareAction : public Action {
    public:
        AcceptQuestShareAction(PlayerbotAI* ai) : Action(ai, "accept quest share") {}
        virtual bool Execute(Event event);
    };
}
