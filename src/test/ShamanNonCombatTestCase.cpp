#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/shaman/ShamanAiObjectContext.h"

using namespace ai;


class ShamanNonCombatTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( ShamanNonCombatTestCase );
        CPPUNIT_TEST( ressurect );
        CPPUNIT_TEST( swimming );
        CPPUNIT_TEST( healing );
        CPPUNIT_TEST( aoe );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new ShamanAiObjectContext(ai), "nc", NULL);
    }

protected:
	void ressurect()
	{
		tickWithDeadPartyMember();

		assertActions(">P:ancestral spirit");
	}

	void healing()
	{
	    tickWithLowHealth(10);
	    spellAvailable("healing wave");
	    tickWithPartyLowHealth(10);

		assertActions(">S:healing wave>P:healing wave on party");
	}

	void aoe()
	{
	    tickWithAoeHeal("medium");

		assertActions(">P:chain heal");
	}

	void swimming()
	{
	    tickWhileSwimming();
	    addAura("water breathing");

	    tickWhileSwimming();
        addAura("water walking");

        spellAvailable("water breathing");
        tickWhileSwimming();
        addPartyAura("water breathing");

        spellAvailable("water walking");
        tickWhileSwimming();
        addPartyAura("water walking");

		assertActions(">S:water breathing>S:water walking>P:water breathing on party>P:water walking on party");
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( ShamanNonCombatTestCase );
