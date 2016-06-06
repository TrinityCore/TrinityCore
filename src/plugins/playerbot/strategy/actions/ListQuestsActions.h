#pragma once

#include "../Action.h"

namespace ai
{
    enum QuestListFilter {
        QUEST_LIST_FILTER_SUMMARY = 0,
        QUEST_LIST_FILTER_COMPLETED = 1,
        QUEST_LIST_FILTER_INCOMPLETED = 2,
        QUEST_LIST_FILTER_ALL = QUEST_LIST_FILTER_COMPLETED | QUEST_LIST_FILTER_INCOMPLETED
    };

    class ListQuestsAction : public Action {
    public:
        ListQuestsAction(PlayerbotAI* ai) : Action(ai, "quests") {}
        virtual bool Execute(Event event);

    private:
        int ListQuests(bool completed, bool silent);
        void ListQuests(QuestListFilter filter);

    };

}