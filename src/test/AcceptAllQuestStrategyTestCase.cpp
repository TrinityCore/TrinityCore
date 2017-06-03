#include "pch.h"

#include "aitest.h"
#include "MockAiObjectContext.h"
#include "MockedAiObjectContextTestCase.h"
#include "../../plugins/playerbot/strategy/generic/ChatCommandHandlerStrategy.h"

using namespace ai;


class AcceptAllQuestStrategyTestCase : public MockedAiObjectContextTestCase
{
  CPPUNIT_TEST_SUITE( AcceptAllQuestStrategyTestCase );
      CPPUNIT_TEST( turn_in_quest );
      CPPUNIT_TEST( accept_quest );
      CPPUNIT_TEST( quest_share );
      CPPUNIT_TEST( useGameObject );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(context = new MockAiObjectContext(ai, new AiObjectContext(ai), &ai->buffer), "accept all quests", NULL);
    }

protected:
    void useGameObject()
    {
        trigger("use game object");
        tick();
        tick();

        assertActions(">S:talk to quest giver>S:accept all quests");
    }

    void turn_in_quest()
    {
        trigger("complete quest");
        tick();
        tick();

        trigger("gossip hello");
        tick();
        tick();

        assertActions(">S:talk to quest giver>S:accept all quests>S:talk to quest giver>S:accept all quests");
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

};

CPPUNIT_TEST_SUITE_REGISTRATION( AcceptAllQuestStrategyTestCase );
