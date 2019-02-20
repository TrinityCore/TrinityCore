#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/mage/MageAiObjectContext.h"

using namespace ai;


class FireMageTestCase : public EngineTestBase
{
  CPPUNIT_TEST_SUITE( FireMageTestCase );
  CPPUNIT_TEST( combatVsMelee );
  CPPUNIT_TEST( avoid_melee );
  CPPUNIT_TEST( avoid_melee_low_level );
  CPPUNIT_TEST( panic );
  CPPUNIT_TEST( boost );
  CPPUNIT_TEST( aoe );
  CPPUNIT_TEST( invisibility );
  CPPUNIT_TEST( stress );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new MageAiObjectContext(ai), "fire", NULL);
    }

protected:
 	void combatVsMelee()
	{
        tick();
		addTargetAura("pyroblast");

        tick();
		tick();
		tick();

        addAura("hot streak");
        spellAvailable("pyroblast");
        tick();
        tick();

        assertActions(">T:pyroblast>T:scorch>T:fireball>T:fire blast>T:pyroblast>T:shoot");
	}

 	void avoid_melee()
 	{
		tickInMeleeRange();
		tickInMeleeRange();

		spellAvailable("flamestrike");
		tickInMeleeRange();
		tickInMeleeRange();

		tickInMeleeRange();
		tickInMeleeRange();

		assertActions(">T:dragon's breath>T:flamestrike>T:blast wave>T:flamestrike>T:frost nova>S:flee");
	}

 	void avoid_melee_low_level()
 	{
 	    spellUnavailable("dragon's breath");
 	    spellUnavailable("blast wave");
		tickInMeleeRange();
		tickInMeleeRange();

		assertActions(">T:frost nova>S:flee");
	}

 	void panic()
 	{
        tickWithLowHealth(19);

        assertActions(">S:ice block");
 	}

    void boost()
    {
		tickWithBalancePercent(1);

		assertActions(">S:combustion");
    }

    void aoe()
    {
        engine->addStrategy("fire aoe");

		tickWithAttackerCount(3);
		tickWithAttackerCount(3);

		assertActions(">T:living bomb>T:flamestrike");
    }

    void invisibility()
    {
		tickWithMyAttackerCount(3);

		assertActions(">S:invisibility");
    }

    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( FireMageTestCase );
