#include "pch.h"

#include "aitest.h"
#include "MockAiObjectContext.h"
#include "MockedAiObjectContextTestCase.h"
#include "../../plugins/playerbot/strategy/generic/ChatCommandHandlerStrategy.h"

using namespace ai;


class QuestStrategyTestCase : public MockedAiObjectContextTestCase
{
  CPPUNIT_TEST_SUITE( QuestStrategyTestCase );
      CPPUNIT_TEST( turn_in_quest );
      CPPUNIT_TEST( accept_quest );
      CPPUNIT_TEST( quest_share );
      CPPUNIT_TEST( useGameObject );
      CPPUNIT_TEST( incompatibles );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(context = new MockAiObjectContext(ai, new AiObjectContext(ai), &ai->buffer), "quest", NULL);
    }

protected:
    void useGameObject()
    {
        trigger("use game object");
        tick();

        assertActions(">S:talk to quest giver");
    }

    void turn_in_quest()
    {
        trigger("complete quest");
        tick();

        trigger("gossip hello");
        tick();

        assertActions(">S:talk to quest giver>S:talk to quest giver");
    }

    void accept_quest()
    {
        trigger("accept quest");
        tick();

        assertActions(">S:accept quest");
    }

    void quest_share()
    {
        trigger("quest share");
        tick();

        assertActions(">S:accept quest share");
    }

    void incompatibles()
    {
        engine->addStrategies("quest", "accept all quests", NULL);

        CPPUNIT_ASSERT(engine->ListStrategies() == "Strategies: accept all quests");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( QuestStrategyTestCase );
