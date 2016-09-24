#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/paladin/PaladinAiObjectContext.h"

using namespace ai;


class DpsPaladinTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( DpsPaladinTestCase );
    CPPUNIT_TEST( buff );
	CPPUNIT_TEST( combatVsMelee );
	CPPUNIT_TEST( stress );
    CPPUNIT_TEST_SUITE_END();

public:
	virtual void setUp()
	{
		EngineTestBase::setUp();
		setupEngine(new PaladinAiObjectContext(ai), "dps", NULL);
		engine->addStrategy("bdps");

        addAura("retribution aura");
        addAura("seal of vengeance");
        addAura("blessing of might");

        set<float>("distance", "current target", 0.0f);
    }

protected:
    void buff()
    {
        removeAura("retribution aura");
        removeAura("blessing of might");
        removeAura("seal of vengeance");
        removeAura("holy shield");

        tick();
        addAura("devotion aura");

        tick();
        tick();
        tick();
        tick();
        addAura("seal of wisdom");

        tick();
        tick();
        addAura("blessing of kings");

        assertActions(">S:retribution aura>S:seal of vengeance>S:seal of command>S:seal of wisdom>S:seal of justice>S:blessing of might>S:blessing of kings");
    }

    void combatVsMelee()
    {
		tickOutOfMeleeRange();

        tick();
		tick();
		addTargetAura("judgement of wisdom");

		tick();

		tickWithAttackerCount(3);
		tickWithAttackerCount(3);

		tickWithTargetLowHealth(19);

		assertActions(">T:reach melee>T:judgement of wisdom>T:judgement of light>T:crusader strike>S:divine storm>T:consecration>T:hammer of wrath");
    }

    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( DpsPaladinTestCase );
