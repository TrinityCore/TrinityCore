#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/mage/MageAiObjectContext.h"

using namespace ai;


class ArcaneMageTestCase : public EngineTestBase
{
  CPPUNIT_TEST_SUITE( ArcaneMageTestCase );
      CPPUNIT_TEST( combatVsMelee );
      CPPUNIT_TEST( avoid_melee );
      CPPUNIT_TEST( stress );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new MageAiObjectContext(ai), "arcane", NULL);
    }

protected:
 	void combatVsMelee()
	{
        tick();
		addAura("arcane blast");

        tick();

        addAura("missile barrage");
        tick();
        tickWithSpellAvailable("arcane missiles");
        tick();

        assertActions(">T:arcane blast>T:arcane barrage>T:arcane missiles>T:arcane missiles>T:shoot");
	}

 	void avoid_melee()
 	{
		tickInMeleeRange();
		tickInMeleeRange();

		assertActions(">T:frost nova>S:flee");
	}

    void stress()
    {
        runStressTest();
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( ArcaneMageTestCase );
