#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/druid/DruidAiObjectContext.h"

using namespace ai;


class DruidNonCombatTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( DruidNonCombatTestCase );
    CPPUNIT_TEST( buff );
    CPPUNIT_TEST( low_mana );
	CPPUNIT_TEST( resurrect );
	CPPUNIT_TEST( dispel );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new DruidAiObjectContext(ai), "nc", NULL);
    }

protected:
    void buff()
    {
		tick();
		addAura("mark of the wild");
                
		tickWithSpellAvailable("mark of the wild");
        
		assertActions(">S:mark of the wild>P:mark of the wild on party");
    }

	void resurrect()
	{
		tickWithDeadPartyMember();

		assertActions(">P:revive");
	}

	void low_mana()
	{
	    engine->addStrategy("flee");
        set<uint8>("item count", "drink", 1);
        tickWithLowMana(5);
        tickWithLowMana(5);

        set<uint8>("item count", "drink", 0);
        tickWithLowMana(5);

        assertActions(">S:innervate>S:drink>S:flee");
    }

    void dispel()
    {
        tickWithAuraToDispel(DISPEL_POISON);
        tickWithAuraToDispel(DISPEL_POISON);

        spellAvailable("abolish poison");
        spellAvailable("cure poison");
        tickWithPartyAuraToDispel(DISPEL_POISON);
        tickWithPartyAuraToDispel(DISPEL_POISON);

        assertActions(">S:abolish poison>S:cure poison>P:abolish poison on party>P:cure poison on party");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( DruidNonCombatTestCase );
