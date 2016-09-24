#include "pch.h"
#include "aitest.h"
#include "MockAiObjectContext.h"

using namespace std;
using namespace ai;

class MockTrigger : public Trigger
{
public:
    MockTrigger(PlayerbotAI* const ai) : Trigger(ai)
    {
    }

public:
    virtual Event Check()
    {
        Event copy = event;
        event = Event();
        return copy;
    }

    virtual void ExternalEvent(string param, Player* owner = NULL)
    {
        this->event = Event("mock", param);
    }

private:
    Event event;
};

class MockAction : public Action
{
public:
    MockAction(PlayerbotAI* const ai, string* buffer, string  name) : Action(ai, name), buffer(buffer)
    {

    }

    virtual bool Execute(Event event)
    {
        buffer->append(">");
        buffer->append(getName());
        if (event.getParam().empty())
            return true;

        buffer->append("(");
        buffer->append(event.getParam());
        buffer->append(")");
        return true;
    }

    virtual bool ExecuteResult()
    {
        buffer->append(getName());
        return true;
    }

private:
    string* buffer;
};

MockAiObjectContext::MockAiObjectContext(PlayerbotAI* const ai, AiObjectContext *realContext, string* buffer) :
    AiObjectContext(ai), buffer(buffer), realContext(realContext)
{
}

void MockAiObjectContext::reportNotFound(string  what, string  name)
{
    std::cout << "\n===\n";
    cout << what << " " << name << " not found in context";
    std::cout << "\n===\n";
}

Strategy* MockAiObjectContext::GetStrategy(string  name)
{
    if (!realContext->GetStrategy(name))
    {
        reportNotFound("Strategy", name);
        CPPUNIT_ASSERT(false);
    }

    return realContext->GetStrategy(name);
}

Trigger* MockAiObjectContext::GetTrigger(string  name)
{
    if (!realContext->GetTrigger(name))
    {
        reportNotFound("Trigger", name);
        CPPUNIT_ASSERT(false);
    }

    Trigger* trigger = triggers[name];
    if (trigger)
        return trigger;

    return triggers[name] = new MockTrigger(ai);
}

Action* MockAiObjectContext::GetAction(string  name)
{
    if (!realContext->GetAction(name))
    {
        reportNotFound("Action", name);
        CPPUNIT_ASSERT(false);
    }

    Action* action = actions[name];
    if (action)
        return action;

    return actions[name] = new MockAction(ai, buffer, name);
}
