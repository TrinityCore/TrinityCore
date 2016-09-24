#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/priest/PriestAiObjectContext.h"

using namespace ai;


class PriestNonCombatTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( PriestNonCombatTestCase );
    CPPUNIT_TEST( buff );
    CPPUNIT_TEST( healing );
    CPPUNIT_TEST( aoe_heal );
    CPPUNIT_TEST( nonCombat );
    CPPUNIT_TEST( dispel );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new PriestAiObjectContext(ai), "nc", NULL);

        addAura("power word: fortitude");
        addPartyAura("power word: fortitude");
        addAura("divine spirit");
        addAura("inner fire");
        addPartyAura("power word: fortitude");
        addPartyAura("divine spirit");
    }

protected:
    void nonCombat()
    {
		tickWithDeadPartyMember();

		assertActions(">P:resurrection");
    }

    void aoe_heal()
    {
        tickWithAoeHeal("medium");

		assertActions(">P:circle of healing");
    }

    void healing()
    {
		tickWithLowHealth(30);

		spellAvailable("flash heal");
		tickWithPartyLowHealth(30);

		tickWithLowHealth(10);
		addAura("power word: shield");
		tickWithLowHealth(10);

		spellAvailable("power word: shield");
		spellAvailable("greater heal");
		tickWithPartyLowHealth(10);
        addPartyAura("power word: shield");
		tickWithPartyLowHealth(10);

		assertActions(">S:flash heal>P:flash heal on party>S:power word: shield>S:greater heal>P:power word: shield on party>P:greater heal on party");
    }

    void buff()
    {
		removeAura("power word: fortitude");
        removeAura("divine spirit");
        removeAura("inner fire");
        removePartyAura("power word: fortitude");
        removePartyAura("divine spirit");

        tick();
        addAura("divine spirit");

        tickWithSpellAvailable("divine spirit");
        addPartyAura("divine spirit");

        tick();
        addAura("power word: fortitude");

        tickWithSpellAvailable("power word: fortitude");
        addPartyAura("power word: fortitude");

        tick();

		assertActions(">S:divine spirit>P:divine spirit on party>S:power word: fortitude>P:power word: fortitude on party>S:inner fire");
    }

    void dispel()
    {
        tickWithAuraToDispel(DISPEL_DISEASE);
        tickWithAuraToDispel(DISPEL_DISEASE);

        spellAvailable("abolish disease");
        spellAvailable("cure disease");
        tickWithPartyAuraToDispel(DISPEL_DISEASE);
        tickWithPartyAuraToDispel(DISPEL_DISEASE);

        tickWithAuraToDispel(DISPEL_MAGIC);

        spellAvailable("dispel magic");
        tickWithPartyAuraToDispel(DISPEL_MAGIC);

		assertActions(">S:abolish disease>S:cure disease>P:abolish disease on party>P:cure disease on party>S:dispel magic>P:dispel magic on party");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( PriestNonCombatTestCase );
