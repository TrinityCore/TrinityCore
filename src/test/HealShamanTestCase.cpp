#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/shaman/ShamanAiObjectContext.h"

using namespace ai;


class HealShamanTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( HealShamanTestCase );
    CPPUNIT_TEST( healHimself );
    CPPUNIT_TEST( healOthers );
    CPPUNIT_TEST( aoe_heal );
    CPPUNIT_TEST( buff );
    CPPUNIT_TEST( interruptSpell );
	CPPUNIT_TEST( dispel );
	CPPUNIT_TEST( cure );
	CPPUNIT_TEST( lowMana );
	CPPUNIT_TEST( range );
	CPPUNIT_TEST( aoe );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new ShamanAiObjectContext(ai), "heal", NULL);

        addAura("water shield");
    }

protected:
    void healHimself()
    {
        tickWithLowHealth(45);
		tickWithLowHealth(35);
        tickWithLowHealth(35);

        assertActions(">S:lesser healing wave>S:riptide>S:healing wave");
    }

    void healOthers()
    {
        tickWithPartyLowHealth(45);
        tickWithPartyLowHealth(35);
		tickWithPartyLowHealth(35);

        assertActions(">P:lesser healing wave on party>P:riptide on party>P:healing wave on party");
    }

    void aoe_heal()
    {
        tickWithAoeHeal("medium");
        tickWithAoeHeal("medium");

        assertActions(">P:chain heal>P:lesser healing wave on party");
    }

    void buff()
    {
        engine->addStrategy("bmana");
        removeAura("water shield");

        tick();
        addAura("water shield");

        tickWithItemForSpell("earthliving weapon");
        tickWithItemForSpell("earthliving weapon");
        tickWithItemForSpell("earthliving weapon");
        tickWithItemForSpell("earthliving weapon");

        engine->addStrategy("totems");
        tick();
        tick();
        tick();
        tick();

        assertActions(">S:water shield>S:earthliving weapon>S:flametongue weapon>S:frostbrand weapon>S:rockbiter weapon>S:mana spring totem>S:strength of earth totem>S:flametongue totem>S:windfury totem");
    }

    void interruptSpell()
    {
        tickWithTargetIsCastingNonMeleeSpell();

		assertActions(">T:wind shear");
    }

	void dispel()
	{
		tickWithTargetAuraToDispel(DISPEL_MAGIC);

		assertActions(">T:purge");
	}

	void cure()
	{
		tickWithAuraToDispel(DISPEL_CURSE);
		spellAvailable("cleanse spirit");
		tickWithAuraToDispel(DISPEL_DISEASE);
        spellAvailable("cleanse spirit");
		tickWithAuraToDispel(DISPEL_POISON);
        spellAvailable("cleanse spirit");

        tickWithPartyAuraToDispel(DISPEL_CURSE);
		spellAvailable("cleanse spirit");
		tickWithPartyAuraToDispel(DISPEL_DISEASE);
        spellAvailable("cleanse spirit");
		tickWithPartyAuraToDispel(DISPEL_POISON);
        spellAvailable("cleanse spirit");

		assertActions(">S:cleanse spirit>S:cleanse spirit>S:cleanse spirit>P:cleanse spirit curse on party>P:cleanse spirit disease on party>P:cleanse spirit poison on party");
	}

	void lowMana()
	{
	    tickWithLowMana(1);
		assertActions(">S:mana tide totem");
	}

    void range()
    {
        tickOutOfSpellRange();

        assertActions(">T:reach spell");
    }

    void aoe()
    {
        tickWithAttackerCount(3);

        assertActions(">S:healing stream totem");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( HealShamanTestCase );
