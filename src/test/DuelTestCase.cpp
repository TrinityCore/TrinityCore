#include "pch.h"

#include "aitest.h"
#include "MockAiObjectContext.h"
#include "MockedAiObjectContextTestCase.h"
#include "../../plugins/playerbot/strategy/generic/ChatCommandHandlerStrategy.h"

using namespace ai;


class DuelTestCase : public MockedAiObjectContextTestCase
{
  CPPUNIT_TEST_SUITE( DuelTestCase );
      CPPUNIT_TEST( accept );
      CPPUNIT_TEST( attack );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(context = new MockAiObjectContext(ai, new AiObjectContext(ai), &ai->buffer), "default", "duel", NULL);
    }

protected:
    void accept()
    {
        trigger("duel requested");
        tick();

        assertActions(">S:accept duel");
    }
    void attack()
    {
        trigger("no attackers");
        context->GetValue<Unit*>("duel target")->Set(MockedTargets::GetDuelTarget());
        tick();
        context->GetValue<Unit*>("duel target")->Set(NULL);

        assertActions(">S:attack duel opponent");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( DuelTestCase );
