#pragma once

#include "InventoryAction.h"

namespace ai
{
    class SuggestWhatToDoAction : public InventoryAction
    {
    public:
        SuggestWhatToDoAction(PlayerbotAI* ai);
        virtual bool Execute(Event event);

    private:
        typedef void (SuggestWhatToDoAction::*Suggestion) ();
        vector<Suggestion> suggestions;

    private:
        void instance();
        void specificQuest();
        void newQuest();
        void grindMaterials();
        void grindReputation();
        void nothing();
        void relax();
        void achievement();
        void trade();
        void spam(string msg);

        vector<uint32> GetIncompletedQuests();

    private:
        bool suggested;
    };
}
