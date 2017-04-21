#pragma once

#include "string "

using namespace std;

#include "MockedTargets.h"

namespace ai
{
    class MockAiObjectContext : public AiObjectContext
    {
    public:
        MockAiObjectContext(PlayerbotAI* const ai, AiObjectContext *realContext, string* buffer);
    
    public:
        virtual Strategy* GetStrategy(string  name);
        virtual Trigger* GetTrigger(string  name);
        virtual Action* GetAction(string  name);

    private:
        void reportNotFound(string  what, string  name);

	private:
		string* buffer;
        AiObjectContext *realContext;
        map<string , Trigger*> triggers;
        map<string , Action*> actions;
    };

}