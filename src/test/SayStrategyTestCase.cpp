#include "pch.h"

#include "aitest.h"
#include "MockAiObjectContext.h"
#include "MockedAiObjectContextTestCase.h"
#include "../../plugins/playerbot/strategy/druid/DruidAiObjectContext.h"
#include "../../plugins/playerbot/strategy/hunter/HunterAiObjectContext.h"
#include "../../plugins/playerbot/strategy/priest/PriestAiObjectContext.h"
#include "../../plugins/playerbot/strategy/mage/MageAiObjectContext.h"
#include "../../plugins/playerbot/strategy/CustomStrategy.h"

using namespace ai;


class SayStrategyTestCase : public MockedAiObjectContextTestCase
{
  CPPUNIT_TEST_SUITE( SayStrategyTestCase );
      CPPUNIT_TEST( critical_health );
      CPPUNIT_TEST( aoe );
      CPPUNIT_TEST( low_mana );
      CPPUNIT_TEST( low_health );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();

		CustomStrategy::actionLinesCache["say"] = R"(
(NULL, 'say', 'critical health>say::critical health|99'),
(NULL, 'say', 'low health>say::low health|99'),
(NULL, 'say', 'low mana>say::low mana|99'),
(NULL, 'say', 'tank aoe>say::taunt|99'),
(NULL, 'say', 'medium aoe>say::aoe|99');
        )";
    }

protected:
    void critical_health()
    {
        setupEngine(new DruidAiObjectContext(ai), "bear", "custom::say", NULL);

        addAura("dire bear form");
        set<Unit*>("tank target", MockedTargets::GetCurrentTarget());

        tickWithLowHealth(9);

        assertActions(">S:say::critical health");
    }


    void aoe()
    {
        setupEngine(new HunterAiObjectContext(ai), "dps", "dps debuff", "custom::say", NULL);

        addAura("aspect of the hawk");
        set<Unit*>("tank target", MockedTargets::GetCurrentTarget());
        tickWithAttackerCount(7);

        assertActions(">S:say::aoe");
    }


    void low_mana()
    {
        setupEngine(new PriestAiObjectContext(ai), "heal", "custom::say", NULL);

        set<Unit*>("tank target", MockedTargets::GetCurrentTarget());
        tickWithLowMana(1);

        assertActions(">S:say::low mana");
    }

    void low_health()
    {
        setupEngine(new MageAiObjectContext(ai), "frost", "custom::say", NULL);

        set<Unit*>("tank target", MockedTargets::GetCurrentTarget());
        tickWithLowHealth(39);

        assertActions(">S:say::low health");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SayStrategyTestCase );
