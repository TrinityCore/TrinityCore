#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/mage/MageAiObjectContext.h"

using namespace ai;


class MageNonCombatTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( MageNonCombatTestCase );
    CPPUNIT_TEST( buff );
    CPPUNIT_TEST( bdps );
    CPPUNIT_TEST( bmana );
    CPPUNIT_TEST( dispel );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new MageAiObjectContext(ai), "nc", NULL);
		set<uint8>("item count", "food", 1);
		set<uint8>("item count", "drink", 1);
    }

protected:
    void buff()
    {
		tick();
        addAura("arcane intellect");

		tickWithSpellAvailable("arcane intellect");
        addPartyAura("arcane intellect");

		tickWithNoDrink();
		tickWithNoFood();

        assertActions(">S:arcane intellect>P:arcane intellect on party>S:conjure water>S:conjure food");
    }

    void bmana()
    {
        engine->addStrategy("bmana");

        addAura("arcane intellect");
        addPartyAura("arcane intellect");

        tick();
        tick();
        tick();

        assertActions(">S:mage armor>S:ice armor>S:frost armor");
    }

    void bdps()
    {
        engine->addStrategy("bdps");

        addAura("arcane intellect");
        addPartyAura("arcane intellect");

        tick();
        tick();
        tick();
        tick();

        assertActions(">S:molten armor>S:mage armor>S:ice armor>S:frost armor");
    }

    void dispel()
    {
        addAura("arcane intellect");
        addPartyAura("arcane intellect");
        addAura("mage armor");

        tickWithAuraToDispel(DISPEL_CURSE);

        spellAvailable("remove curse");
        tickWithPartyAuraToDispel(DISPEL_CURSE);

        assertActions(">S:remove curse>P:remove curse on party");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( MageNonCombatTestCase );
