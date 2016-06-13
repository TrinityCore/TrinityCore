#include "MockAiObjectContext.h"

using namespace ai;


class MockedAiObjectContextTestCase : public EngineTestBase
{
  
protected:
    MockAiObjectContext* context;


protected:
    void assertCommand(string  trigger)
    {
        assertCommand(trigger, trigger);
    }

    void assertCommand(string  trigger, string  expectedAction)
    {
        ai->buffer.clear();

        context->GetTrigger(trigger)->ExternalEvent("");
        tick();

        assertActions(string(">S:") + expectedAction);
    }

    void assertParametrizedCommand(string  trigger, string  param)
    {
        ai->buffer.clear();

        context->GetTrigger(trigger)->ExternalEvent(param);
        tick();

        assertActions(string (">S:") + trigger + "(" + param + ")");
    }

    void trigger(string  name)
    {
        context->GetTrigger(name)->ExternalEvent("");
    }

    void trigger(string  name, string  param)
    {
        context->GetTrigger(name)->ExternalEvent(param);
    }

    void tickWithTrigger(string  name)
    {
        trigger(name);
        tick();
    }
};
