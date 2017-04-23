#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/warlock/WarlockAiObjectContext.h"

using namespace ai;


class WarlockNonCombatTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( WarlockNonCombatTestCase );
    CPPUNIT_TEST( buff );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
        EngineTestBase::setUp();
        setupEngine(new WarlockAiObjectContext(ai), "nc", NULL);
    }

protected:
    void buff()
    {
        tick();
        tick();
        tick();
        addAura("fel armor");

		itemAvailable("soul shard", 2);
		tick();
		itemAvailable("healthstone", 1);

		tick();
		itemAvailable("firestone", 1);

		tick();
		itemAvailable("spellstone", 1);

        tick();
        addAura("spellstone");

        tickWithNoPet();

        assertActions(">S:fel armor>S:demon armor>S:demon skin>S:create healthstone>S:create firestone>S:create spellstone>S:spellstone>S:summon imp");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( WarlockNonCombatTestCase );
