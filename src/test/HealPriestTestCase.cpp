#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/priest/PriestAiObjectContext.h"

using namespace ai;


class HealPriestTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( HealPriestTestCase );
    CPPUNIT_TEST( healHimself );
    CPPUNIT_TEST( healOthers );
    CPPUNIT_TEST( aoe_heal );
    CPPUNIT_TEST( dispel );
    CPPUNIT_TEST( flee );
    CPPUNIT_TEST( cc );
    CPPUNIT_TEST( enemyTooClose );
	CPPUNIT_TEST( racials );
	CPPUNIT_TEST( incompatibles );
	CPPUNIT_TEST( range );
	CPPUNIT_TEST( stress );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new PriestAiObjectContext(ai), "heal", NULL);

        addAura("power word: fortitude");
        addAura("divine spirit");
        addAura("inner fire");
        addPartyAura("power word: fortitude");
        addPartyAura("divine spirit");
    }

protected:
    void healHimself()
    {
        addPartyAura("power word: fortitude");

		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithLowHealth(39);

		tick();

		tickWithLowHealth(59);

        spellAvailable("renew");
        tickWithLowHealth(79);

		tickWithSpellAvailable("shoot");

		assertActions(">S:power word: shield>S:greater heal>S:renew>S:heal>S:lesser heal>T:shoot>S:flash heal>S:renew>T:shoot");
    }

	void racials()
	{
		engine->addStrategy("racials");
		addPartyAura("power word: fortitude");

		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithLowHealth(39);

		tick();

		tickWithLowHealth(59);

		tickWithSpellAvailable("shoot");

		assertActions(">S:lifeblood>S:gift of the naaru>S:power word: shield>S:greater heal>S:renew>S:heal>S:lesser heal>T:shoot>S:flash heal>T:shoot");
	}

    void healOthers()
    {
        tick(); // shoot

		tickWithPartyLowHealth(39);
		tickWithPartyLowHealth(39);
		tickWithPartyLowHealth(39);
		tickWithPartyLowHealth(39);
		tickWithPartyLowHealth(39);

        spellAvailable("greater heal");
        spellAvailable("renew");
        spellAvailable("flash heal");
        spellAvailable("lesser heal");
        spellAvailable("power word: shield");
        tickWithPartyLowHealth(1);
        tickWithPartyLowHealth(1);
        tickWithPartyLowHealth(1);
        tickWithPartyLowHealth(1);

		tickWithSpellAvailable("shoot");

        spellAvailable("flash heal");
		tickWithPartyLowHealth(59);

        spellAvailable("renew");
        tickWithPartyLowHealth(79);

        tickWithSpellAvailable("shoot"); // shoot


		assertActions(">T:shoot>P:power word: shield on party>P:greater heal on party>P:renew on party>P:heal on party>P:lesser heal on party>P:power word: shield on party>P:flash heal on party>P:renew on party>P:greater heal on party>T:shoot>P:flash heal on party>P:renew on party>T:shoot");
    }

    void aoe_heal()
    {
        tickWithAoeHeal("medium");
        tickWithAoeHeal("medium");

        assertActions(">P:circle of healing>P:flash heal on party");
    }

    void flee()
    {
        tickInMeleeRange();
        tickInMeleeRange();

		assertActions(">S:fade>S:flee");
    }

    void cc()
    {
		tickWithMyAttackerCount(3);
		tickWithMyAttackerCount(3);
        set<float>("distance", "current target", 5);
		tickWithMyAttackerCount(3);

		assertActions(">T:psychic scream>S:fade>S:flee");
    }

    void enemyTooClose()
    {
        tick();

		tickInMeleeRange();
		tickInMeleeRange();

		spellAvailable("shoot");
		tickInSpellRange();

		assertActions(">T:shoot>S:fade>S:flee>T:shoot");
    }

    void dispel()
    {
        tick(); // shoot

		tickWithAuraToDispel(DISPEL_MAGIC);

		spellAvailable("dispel magic");
		tickWithPartyAuraToDispel(DISPEL_MAGIC);

		tickWithAuraToDispel(DISPEL_DISEASE);

		spellAvailable("abolish disease");
		tickWithPartyAuraToDispel(DISPEL_DISEASE);

		tickWithAuraToDispel(DISPEL_DISEASE);

		spellAvailable("cure disease");
		tickWithPartyAuraToDispel(DISPEL_DISEASE);

        tickWithSpellAvailable("shoot");

		assertActions(">T:shoot>S:dispel magic>P:dispel magic on party>S:abolish disease>P:abolish disease on party>S:cure disease>P:cure disease on party>T:shoot");
    }


    void incompatibles()
    {
        engine->addStrategies("heal", "shadow", NULL);

        CPPUNIT_ASSERT(engine->ListStrategies() == "Strategies: shadow");
    }

    void range()
    {
        tickOutOfSpellRange();

        assertActions(">T:reach spell");
    }

    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( HealPriestTestCase );
