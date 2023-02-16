#pragma once

#include "InventoryAction.h"

namespace ai
{
    class SuggestWhatToDoAction : public InventoryAction
    {
    public:
        SuggestWhatToDoAction(PlayerbotAI* ai, string name = "suggest what to do");
        virtual bool Execute(Event event);
        virtual bool isUseful();

    protected:
        typedef void (SuggestWhatToDoAction::*Suggestion) ();
        vector<Suggestion> suggestions;
        void instance();
        void specificQuest();
        void grindMaterials();
        void grindReputation();
        void something();
        void trade();
        void spam(string msg, uint32 channelId = 1);

        vector<uint32> GetIncompletedQuests();

    private:
        static map<string, int> instances;
        static map<string, int> factions;
    };

    class SuggestTradeAction : public SuggestWhatToDoAction
    {
    public:
        SuggestTradeAction(PlayerbotAI* ai);
        virtual bool Execute(Event event);
        virtual bool isUseful() { return true; }
    };
}
