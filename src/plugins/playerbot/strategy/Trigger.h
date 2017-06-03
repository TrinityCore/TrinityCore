#pragma once
#include "Action.h"
#include "Event.h"
#include "../PlayerbotAIAware.h"

#define NEXT_TRIGGERS(name, relevance) \
    virtual NextAction* getNextAction() { return new NextAction(name, relevance); }

#define BEGIN_TRIGGER(clazz, super) \
class clazz : public super \
    { \
    public: \
        clazz(PlayerbotAI* ai) : super(ai) {} \
    public: \
        virtual bool IsActive();

#define END_TRIGGER() \
    };

namespace ai
{
    class Trigger : public AiNamedObject
	{
	public:
        Trigger(PlayerbotAI* ai, string name = "trigger", int checkInterval = 1) : AiNamedObject(ai, name) {
			this->checkInterval = checkInterval;
			ticksElapsed = 0;
        }
        virtual ~Trigger() {}

	public:
        virtual Event Check();
        virtual void ExternalEvent(string param, Player* owner = NULL) {}
        virtual void ExternalEvent(WorldPacket &packet, Player* owner = NULL) {}
        virtual bool IsActive() { return false; }
        virtual NextAction** getHandlers() { return NULL; }
        void Update() {}
        virtual void Reset() {}
        virtual Unit* GetTarget();
        virtual Value<Unit*>* GetTargetValue();
        virtual string GetTargetName() { return "self target"; }

		bool needCheck() {
			if (++ticksElapsed >= checkInterval) {
				ticksElapsed = 0;
				return true;
			}
			return false;
		}

    protected:
		int checkInterval;
		int ticksElapsed;
	};


    class TriggerNode
    {
    public:
        TriggerNode(string name, NextAction** handlers = NULL)
        {
            this->name = name;
            this->handlers = handlers;
            this->trigger = NULL;
        }
        virtual ~TriggerNode()
        {
            NextAction::destroy(handlers);
        }

    public:
        Trigger* getTrigger() { return trigger; }
        void setTrigger(Trigger* trigger) { this->trigger = trigger; }
        string getName() { return name; }

    public:
        NextAction** getHandlers() { return NextAction::merge(NextAction::clone(handlers), trigger->getHandlers()); }

    private:
        Trigger* trigger;
        NextAction** handlers;
        std::string name;
    };
}
