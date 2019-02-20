#pragma once

#include "../Action.h"
#include "QuestAction.h"

namespace ai
{
    class TalkToQuestGiverAction : public QuestAction {
    public:
        TalkToQuestGiverAction(PlayerbotAI* ai) : QuestAction(ai, "talk to quest giver") {}

    protected:
        virtual void ProcessQuest(Quest const* quest, WorldObject* questGiver);

    private:
        void TurnInQuest(Quest const* quest, WorldObject* questGiver, ostringstream& out);
        void RewardNoItem(Quest const* quest, WorldObject* questGiver, ostringstream& out);
        void RewardSingleItem(Quest const* quest, WorldObject* questGiver, ostringstream& out);
        void AskToSelectReward(Quest const* quest, ostringstream& out);
    };

}