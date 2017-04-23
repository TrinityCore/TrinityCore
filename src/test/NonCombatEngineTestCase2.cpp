#include "pch.h"
#include "aitest.h"

#include "EngineTestBase.h"
#include "MockedAiObjectContextTestCase.h"

using namespace ai;


class NonCombatEngineTestCase2 : public MockedAiObjectContextTestCase
{
  CPPUNIT_TEST_SUITE( NonCombatEngineTestCase2 );
      CPPUNIT_TEST( emote );
      CPPUNIT_TEST( ready_check );
  CPPUNIT_TEST_SUITE_END();

public:
	void setUp()
	{
		EngineTestBase::setUp();
        setupEngine(context = new MockAiObjectContext(ai, new AiObjectContext(ai), &ai->buffer), "emote", NULL);
	}

protected:
    void emote()
    {
        tickWithTrigger("random");
        tickWithTrigger("seldom");

        assertActions(">S:emote>S:suggest what to do");
    }

    void ready_check()
    {
        engine->addStrategy("ready check");
        tickWithTrigger("timer");

        assertActions(">S:ready check");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( NonCombatEngineTestCase2 );
