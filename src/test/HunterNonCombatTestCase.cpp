#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/hunter/HunterAiObjectContext.h"

using namespace ai;


class HunterNonCombatTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( HunterNonCombatTestCase );
    CPPUNIT_TEST( buff );
    CPPUNIT_TEST( lowMana );
    CPPUNIT_TEST( summonPet );
	CPPUNIT_TEST( buffIfPackUnavailable );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new HunterAiObjectContext(ai), "nc", NULL);

        set<uint8>("attacker count", 0);
    }

protected:
    void buff()
    {
		engine->addStrategy("bspeed");

		tick();
        addAura("aspect of the pack");
        tick();

        engine->addStrategy("bdps");
		tickWithAttackerCount(1);

        assertActions(">S:aspect of the pack>S:trueshot aura>S:aspect of the hawk");
    }

    void lowMana()
    {
        addAura("trueshot aura");

        engine->addStrategy("bmana");

		tick();
        addAura("aspect of the viper");

        assertActions(">S:aspect of the viper");
    }

    void summonPet()
    {
        tickWithNoPet();

		tickWithPetDead();
		tickWithPetLowHealth(30);

		assertActions(">S:call pet>S:revive pet>Pet:mend pet");
	}

    void buffIfPackUnavailable()
    {
		engine->addStrategy("bspeed");

        tickWithSpellUnavailable("aspect of the pack");

		assertActions(">S:aspect of the cheetah");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( HunterNonCombatTestCase );
