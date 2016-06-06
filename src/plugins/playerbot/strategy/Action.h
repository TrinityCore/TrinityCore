#pragma once
#include "Event.h"
#include "Value.h"
#include "AiObject.h"

namespace ai
{
    class NextAction
    {
    public:
        NextAction(string name, float relevance = 0.0f)
        {
            this->name = name;
            this->relevance = relevance;
        }
        NextAction(const NextAction& o)
        {
            this->name = o.name;
            this->relevance = o.relevance;
        }

    public:
        string getName() { return name; }
        float getRelevance() {return relevance;}

    public:
        static int size(NextAction** actions);
        static NextAction** clone(NextAction** actions);
        static NextAction** merge(NextAction** what, NextAction** with);
        static NextAction** array(uint8 nil,...);
        static void destroy(NextAction** actions);

    private:
        float relevance;
        std::string name;
    };

    //---------------------------------------------------------------------------------------------------------------------

    class ActionBasket;

    enum ActionThreatType
    {
        ACTION_THREAT_NONE = 0,
        ACTION_THREAT_SINGLE= 1,
        ACTION_THREAT_AOE = 2
    };

    class Action : public AiNamedObject
	{
	public:
        Action(PlayerbotAI* ai, string name = "action") : verbose(false), AiNamedObject(ai, name) { }
        virtual ~Action(void) {}

    public:
        virtual bool Execute(Event event) { return true; }
        virtual bool isPossible() { return true; }
        virtual bool isUseful() { return true; }
        virtual NextAction** getPrerequisites() { return NULL; }
        virtual NextAction** getAlternatives() { return NULL; }
        virtual NextAction** getContinuers() { return NULL; }
        virtual ActionThreatType getThreatType() { return ACTION_THREAT_NONE; }
        void Update() {}
        void Reset() {}
        virtual Unit* GetTarget();
        virtual Value<Unit*>* GetTargetValue();
        virtual string GetTargetName() { return "self target"; }
        void MakeVerbose() { verbose = true; }

    protected:
        bool verbose;
	};

    class ActionNode
    {
    public:
        ActionNode(string name, NextAction** prerequisites = NULL, NextAction** alternatives = NULL, NextAction** continuers = NULL)
        {
            this->action = NULL;
            this->name = name;
            this->prerequisites = prerequisites;
            this->alternatives = alternatives;
            this->continuers = continuers;
        }
        virtual ~ActionNode()
        {
            NextAction::destroy(prerequisites);
            NextAction::destroy(alternatives);
            NextAction::destroy(continuers);
        }

    public:
        Action* getAction() { return action; }
        void setAction(Action* action) { this->action = action; }
        string getName() { return name; }

    public:
        NextAction** getContinuers() { return NextAction::merge(NextAction::clone(continuers), action->getContinuers()); }
        NextAction** getAlternatives() { return NextAction::merge(NextAction::clone(alternatives), action->getAlternatives()); }
        NextAction** getPrerequisites() { return NextAction::merge(NextAction::clone(prerequisites), action->getPrerequisites()); }

    private:
        string name;
        Action* action;
        NextAction** continuers;
        NextAction** alternatives;
        NextAction** prerequisites;
    };

    //---------------------------------------------------------------------------------------------------------------------

	class ActionBasket
	{
	public:
        ActionBasket(ActionNode* action, float relevance, bool skipPrerequisites, Event event) :
          action(action), relevance(relevance), skipPrerequisites(skipPrerequisites), event(event) {}
        virtual ~ActionBasket(void) {}
	public:
		float getRelevance() {return relevance;}
		ActionNode* getAction() {return action;}
        Event getEvent() { return event; }
        bool isSkipPrerequisites() { return skipPrerequisites; }
        void AmendRelevance(float k) {relevance *= k; }
        void setRelevance(float relevance) { this->relevance = relevance; }
	private:
		ActionNode* action;
		float relevance;
        bool skipPrerequisites;
        Event event;
	};

    //---------------------------------------------------------------------------------------------------------------------


}

#define AI_VALUE(type, name) context->GetValue<type>(name)->Get()
#define AI_VALUE2(type, name, param) context->GetValue<type>(name, param)->Get()
