#pragma once

#include "Action.h"
#include "Queue.h"
#include "Trigger.h"
#include "Multiplier.h"
#include "AiObjectContext.h"
#include "Strategy.h"

namespace ai
{
    class ActionExecutionListener
    {
    public:
        virtual bool Before(Action* action, Event event) = 0;
        virtual bool AllowExecution(Action* action, Event event) = 0;
        virtual void After(Action* action, bool executed, Event event) = 0;
        virtual bool OverrideResult(Action* action, bool executed, Event event) = 0;
    };

    // -----------------------------------------------------------------------------------------------------------------------

    class ActionExecutionListeners : public ActionExecutionListener
    {
    public:
        virtual ~ActionExecutionListeners();

    // ActionExecutionListener
    public:
        virtual bool Before(Action* action, Event event);
        virtual bool AllowExecution(Action* action, Event event);
        virtual void After(Action* action, bool executed, Event event);
        virtual bool OverrideResult(Action* action, bool executed, Event event);

    public:
        void Add(ActionExecutionListener* listener)
        {
            listeners.push_back(listener);
        }
        void Remove(ActionExecutionListener* listener)
        {
            listeners.remove(listener);
        }

    private:
        std::list<ActionExecutionListener*> listeners;
    };

    // -----------------------------------------------------------------------------------------------------------------------

    enum ActionResult
    {
        ACTION_RESULT_UNKNOWN,
        ACTION_RESULT_OK,
        ACTION_RESULT_IMPOSSIBLE,
        ACTION_RESULT_USELESS,
        ACTION_RESULT_FAILED
    };

    class Engine : public PlayerbotAIAware
    {
    public:
        Engine(PlayerbotAI* ai, AiObjectContext *factory);

	    void Init();
        void addStrategy(string name);
		void addStrategies(string first, ...);
        bool removeStrategy(string name);
        bool HasStrategy(string name);
        void removeAllStrategies();
        void toggleStrategy(string name);
        std::string ListStrategies();
		bool ContainsStrategy(StrategyType type);
		void ChangeStrategy(string names);
		string GetLastAction() { return lastAction; }

    public:
	    virtual bool DoNextAction(Unit*, int depth = 0);
	    ActionResult ExecuteAction(string name);

    public:
        void AddActionExecutionListener(ActionExecutionListener* listener)
        {
            actionExecutionListeners.Add(listener);
        }
        void removeActionExecutionListener(ActionExecutionListener* listener)
        {
            actionExecutionListeners.Remove(listener);
        }

    public:
	    virtual ~Engine(void);

    private:
        bool MultiplyAndPush(NextAction** actions, float forceRelevance, bool skipPrerequisites, Event event);
        void Reset();
        void ProcessTriggers();
        void PushDefaultActions();
        void PushAgain(ActionNode* actionNode, float relevance, Event event);
        ActionNode* CreateActionNode(string name);
        Action* InitializeAction(ActionNode* actionNode);
        bool ListenAndExecute(Action* action, Event event);

    private:
        void LogAction(const char* format, ...);
        void LogValues();

    protected:
	    Queue queue;
	    std::list<TriggerNode*> triggers;
        std::list<Multiplier*> multipliers;
        AiObjectContext* aiObjectContext;
        std::map<string, Strategy*> strategies;
        float lastRelevance;
        std::string lastAction;

    public:
		bool testMode;

    private:
        ActionExecutionListeners actionExecutionListeners;
    };
}
