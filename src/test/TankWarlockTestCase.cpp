#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/warlock/WarlockAiObjectContext.h"

using namespace ai;


class TankWarlockTestCase : public EngineTestBase
{
  CPPUNIT_TEST_SUITE( TankWarlockTestCase );
      CPPUNIT_TEST( summonPet );
      CPPUNIT_TEST( cc );
      CPPUNIT_TEST( incompatibles );
      CPPUNIT_TEST( stress );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
        EngineTestBase::setUp();
        setupEngine(new WarlockAiObjectContext(ai), "tank", NULL);
    }

protected:

    void summonPet()
    {
        itemAvailable("soul shard", 2);
        tickWithNoPet();
        tickWithNoPet();

		assertActions(">S:summon felguard>S:summon voidwalker");
    }

    void cc()
    {
        tickWithCcTarget("banish");
        tickWithCcTarget("fear");

        assertActions(">Cc:banish on cc>Cc:fear on cc");
    }

    void incompatibles()
    {
        engine->addStrategies("tank", "dps", NULL);

        CPPUNIT_ASSERT(engine->ListStrategies() == "Strategies: dps");
    }

    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( TankWarlockTestCase );
