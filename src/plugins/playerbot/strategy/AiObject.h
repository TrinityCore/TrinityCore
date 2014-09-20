#pragma once

class PlayerbotAI;

namespace ai
{
    class AiObjectContext;
    class ChatHelper;

    class AiObject : public PlayerbotAIAware
	{
	public:
        AiObject(PlayerbotAI* ai);

    protected:
        Player* bot;
        Player* GetMaster();
        AiObjectContext* context;
        ChatHelper* chat;
	};

    class AiNamedObject : public AiObject
    {
    public:
        AiNamedObject(PlayerbotAI* ai, string name) : AiObject(ai), name(name) {}

    public:
        virtual string getName() { return name; }

    protected:
        string name;
    };
}
