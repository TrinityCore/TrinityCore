#pragma once

#include "InventoryAction.h"

namespace ai
{
    class SuggestWhatToDoAction : public InventoryAction
    {
    public:
		SuggestWhatToDoAction(PlayerbotAI* ai, string name = "suggest what to do");
        virtual bool Execute(Event event);

	protected:
        typedef void (SuggestWhatToDoAction::*Suggestion) ();
        vector<Suggestion> suggestions;
        void instance();
        void specificQuest();
        void newQuest();
        void grindMaterials();
        void grindReputation();
        void nothing();
        void relax();
        void achievement();
        void trade();
		void spam(string msg, uint32 channelId = 1);

        vector<uint32> GetIncompletedQuests();
	};

	class SuggestTradeAction : public SuggestWhatToDoAction
	{
	public:
		SuggestTradeAction(PlayerbotAI* ai);
		virtual bool Execute(Event event);
    };
}
