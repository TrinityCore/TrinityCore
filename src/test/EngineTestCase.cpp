#include "pch.h"

#include "aitest.h"
#include "MockPlayerbotAIBase.h"

using namespace ai;

class PrerequisiteAction : public Action
{
public:
    PrerequisiteAction(PlayerbotAI* const ai) : Action(ai) {}
    virtual ~PrerequisiteAction() { destroyed = TRUE; }

    bool Execute(Event event) { executed++; return TRUE; }
    virtual string getName() {return "PrerequisiteAction"; }

    static int executed;
    static int destroyed;
};

int PrerequisiteAction::executed = 0;
int PrerequisiteAction::destroyed = 0;

class AlternativeAction : public Action
{
public:
    AlternativeAction(PlayerbotAI* const ai) : Action(ai) {}
    virtual ~AlternativeAction() {destroyed = TRUE;}

    bool Execute(Event event) { executed++; return TRUE; }
    string  getName() {return "AlternativeAction"; }

    static int executed;
    static int destroyed;
};

int AlternativeAction::executed = 0;
int AlternativeAction::destroyed = 0;

class RepeatingAction : public Action
{
public:
	RepeatingAction(PlayerbotAI* const ai) : Action(ai) {}

	virtual ~RepeatingAction()
	{
		destroyed++;
	}

    bool Execute(Event event) { executed++; return TRUE; }
    string  getName() {return "RepeatingAction"; }
    bool isPossible() { return available; }

	static int destroyed;
    static int executed;
    static int available;
};

int RepeatingAction::available = TRUE;
int RepeatingAction::destroyed = 0;
int RepeatingAction::executed = 0;

class TriggeredAction : public Action
{
public:
	TriggeredAction(PlayerbotAI* const ai) : Action(ai) { fired = false; }
	virtual ~TriggeredAction() {}

    bool Execute(Event event) { param = event.getParam(); fired = TRUE; return true; }
    string  getName() {return "TriggeredAction"; }

	static int fired;
    static string param;
};

int TriggeredAction::fired = 0;
string TriggeredAction::param;

class TestTrigger : public Trigger
{
public:
	TestTrigger(PlayerbotAI* const ai) : Trigger(ai) {count = 0;}
    virtual Event Check()
    {
        return IsActive() ? Event(getName(), "test") : Event();
    }
	virtual bool IsActive()
	{
		return ++count==3;
	}

private:
	int count;
};

class TestMultiplier : public Multiplier
{
public:
    TestMultiplier(PlayerbotAI* const ai) : Multiplier(ai, "test") { asked = 0; }
    float GetValue(Action* action) { return asked = 1.0f; }

    static int asked;
};

int TestMultiplier::asked;

class TestStrategy : public Strategy
{
public:
    TestStrategy(PlayerbotAI* const ai) : Strategy(ai) {}

    virtual string  getName() { return "TestStrategy"; }

    virtual NextAction** getDefaultActions() { return NextAction::array(0, new NextAction("RepeatingAction", 1.0f), NULL); }

    virtual void InitMultipliers(std::list<Multiplier*> &multipliers)
    {
        multipliers.push_back(new TestMultiplier(ai));
    }

    virtual void InitTriggers(std::list<TriggerNode*> &triggers)
    {
        triggers.push_back(new TriggerNode(
            "TestTrigger",
            NextAction::array(0, new NextAction("TriggeredAction", 10.0f), NULL)));
    }

    virtual ActionNode* GetAction(string  name)
    {
        if (name == "TriggeredAction")
        {
            return new ActionNode ("TriggeredAction",
                /*P*/ NULL,
                /*A*/ NULL,
                /*C*/ NULL);
        }
        else if (name == "RepeatingAction")
        {
            return new ActionNode ("RepeatingAction",
                /*P*/ NULL,
                /*A*/ NextAction::array(0, new NextAction("AlternativeAction", 1.0f), NULL),
                /*C*/ NextAction::array(0, new NextAction("RepeatingAction", 1.0f), NULL));
        }
        else if (name == "AlternativeAction")
        {
            return new ActionNode ("AlternativeAction",
                /*P*/ NextAction::array(0, new NextAction("PrerequisiteAction", 1.0f), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        else if (name == "PrerequisiteAction")
        {
            return new ActionNode ("PrerequisiteAction",
                /*P*/ NULL,
                /*A*/ NULL,
                /*C*/ NULL);
        }
        else return NULL;
    }
};

class AnotherTestStrategy : public Strategy
{
public:
    AnotherTestStrategy(PlayerbotAI* const ai) : Strategy(ai) {}

    virtual string  getName() { return "AnotherTestStrategy"; }
};

class TestStrategyContext : public NamedObjectContext<Strategy>
{
public:
    TestStrategyContext() : NamedObjectContext(false, true)
    {
        creators["TestStrategy"] = &TestStrategyContext::Test;
        creators["AnotherTestStrategy"] = &TestStrategyContext::AnotherTest;
    }

private:
    static Strategy* Test(PlayerbotAI* ai) { return new TestStrategy(ai); }
    static Strategy* AnotherTest(PlayerbotAI* ai) { return new AnotherTestStrategy(ai); }
};

class TestTriggerContext : public NamedObjectContext<Trigger>
{
public:
    TestTriggerContext()
    {
        creators["TestTrigger"] = &TestTriggerContext::Test;
    }

private:
    static Trigger* Test(PlayerbotAI* ai) { return new TestTrigger(ai); }
};


class TestActionContext : public NamedObjectContext<Action>
{
public:
    TestActionContext()
    {
        creators["TriggeredAction"] = &TestActionContext::Triggered;
        creators["RepeatingAction"] = &TestActionContext::Repeating;
        creators["AlternativeAction"] = &TestActionContext::Alternative;
        creators["PrerequisiteAction"] = &TestActionContext::Prerequisite;
    }

private:
    static Action* Triggered(PlayerbotAI* ai) { return new TriggeredAction(ai); }
    static Action* Repeating(PlayerbotAI* ai) { return new RepeatingAction(ai); }
    static Action* Alternative(PlayerbotAI* ai) { return new AlternativeAction(ai); }
    static Action* Prerequisite(PlayerbotAI* ai) { return new PrerequisiteAction(ai); }
};

class TestAiObjectContext : public AiObjectContext
{
public:
    TestAiObjectContext(PlayerbotAI* const ai) : AiObjectContext(ai)
    {
        strategyContexts.Add(new TestStrategyContext());
        triggerContexts.Add(new TestTriggerContext());
        actionContexts.Add(new TestActionContext());
    }
};

class EngineTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( EngineTestCase );
      CPPUNIT_TEST( engineMustRepeatActions );
      CPPUNIT_TEST( addRemoveStrategies );
      CPPUNIT_TEST( listStrategies );
      CPPUNIT_TEST( eventMustPassToAction );
      CPPUNIT_TEST( siblings );
  CPPUNIT_TEST_SUITE_END();

protected:

public:
	void setUp()
	{
	}

protected:
	void engineMustRepeatActions()
	{
		MockPlayerbotAIBase mock;
		Engine engine(&mock, new TestAiObjectContext(&mock));
		engine.testMode = true;
        engine.addStrategy("TestStrategy");
        engine.Init();

		for (int i=0; i<6; i++)
			engine.DoNextAction(NULL);

		CPPUNIT_ASSERT(TriggeredAction::fired);
        CPPUNIT_ASSERT(TestMultiplier::asked);
        CPPUNIT_ASSERT_EQUAL(5, RepeatingAction::executed);

        RepeatingAction::available = FALSE;
        engine.DoNextAction(NULL);
        engine.DoNextAction(NULL);
        CPPUNIT_ASSERT(AlternativeAction::executed);
        CPPUNIT_ASSERT(PrerequisiteAction::executed);
	}

    void addRemoveStrategies()
    {
		MockPlayerbotAIBase mock;
        Engine engine(&mock, new TestAiObjectContext(&mock));
        engine.testMode = true;
        engine.addStrategy("AnotherTestStrategy");
        engine.removeStrategy("AnotherTestStrategy");
        engine.Init();

        engine.addStrategy("TestStrategy");
        engine.Init();

        engine.DoNextAction(NULL);
        CPPUNIT_ASSERT(TriggeredAction::fired);
    }

    void listStrategies()
    {
		MockPlayerbotAIBase mock;
        Engine engine(&mock, new TestAiObjectContext(&mock));
        engine.testMode = true;
        engine.addStrategy("AnotherTestStrategy");
        engine.addStrategy("TestStrategy");
        engine.Init();

        std::string s = engine.ListStrategies();
        CPPUNIT_ASSERT(s == "Strategies: TestStrategy");
    }

    void eventMustPassToAction()
    {
        MockPlayerbotAIBase mock;
        Engine engine(&mock, new TestAiObjectContext(&mock));
        engine.testMode = true;
        engine.addStrategy("TestStrategy");
        engine.Init();

        for (int i=0; i<6; i++)
            engine.DoNextAction(NULL);

        CPPUNIT_ASSERT(TriggeredAction::param == "test");
    }

    void siblings()
    {
        MockPlayerbotAIBase mock;
        TestAiObjectContext * context = new TestAiObjectContext(&mock);

        set<string> siblings = context->GetSiblingStrategy("TestStrategy");

        CPPUNIT_ASSERT(siblings.size() == 1);
        CPPUNIT_ASSERT(*siblings.begin() == "AnotherTestStrategy");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( EngineTestCase );
