#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/paladin/PaladinAiObjectContext.h"

using namespace ai;


class HealPaladinTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( HealPaladinTestCase );
		CPPUNIT_TEST( healing );
    CPPUNIT_TEST_SUITE_END();

public:
	virtual void setUp()
	{
		EngineTestBase::setUp();
		setupEngine(new PaladinAiObjectContext(ai), "heal", NULL);

        addAura("devotion aura");
        addAura("seal of justice");
        addAura("blessing of sanctuary");
        addAura("righteous fury");

		addAura("holy shield");

        set<float>("distance", "current target", ATTACK_DISTANCE - 1);
    }

protected:

    void healing()
    {
		tickWithLowHealth(50);

		tickWithLowHealth(30);
        tickWithLowHealth(30);

		tickWithLowHealth(19);

		spellAvailable("lay on hands");
		tickWithPartyLowHealth(20);
        tickWithLowHealth(19);
        spellAvailable("flash of light");
        tickWithLowHealth(19);

        assertActions(">S:flash of light>S:divine protection>S:holy light>S:lay on hands>P:lay on hands on party>S:divine shield>S:flash of light");
    }

    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( HealPaladinTestCase );
