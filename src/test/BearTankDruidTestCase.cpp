#include "pch.h"
#include "aitest.h"
#include "../../plugins/playerbot/strategy/druid/DruidAiObjectContext.h"

using namespace ai;

class BearTankDruidTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( BearTankDruidTestCase );
        CPPUNIT_TEST( startMeleeCombat );
        CPPUNIT_TEST( meleeCombat );
        CPPUNIT_TEST( druidMustHoldAggro );
        CPPUNIT_TEST( bearFormIfDireNotAvailable );
        CPPUNIT_TEST( healHimself );
        CPPUNIT_TEST( intensiveHealing );
        CPPUNIT_TEST( healOthers );
        CPPUNIT_TEST( curePoison );
        CPPUNIT_TEST( interruptSpells );
        CPPUNIT_TEST( buff );
        CPPUNIT_TEST( aoe );
        CPPUNIT_TEST( incompatibles );
        CPPUNIT_TEST( interrupt_enemy_healer );
        CPPUNIT_TEST( stress );
    CPPUNIT_TEST_SUITE_END();


public:
    virtual void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new DruidAiObjectContext(ai), "bear", NULL);

		addAura("thorns");
        addTargetAura("faerie fire (feral)");
        set<uint8>("rage", "self target", 100);
    }

protected:
    void bearFormIfDireNotAvailable()
    {
		tickWithSpellUnavailable("dire bear form");

		assertActions(">S:bear form");
    }

    void druidMustHoldAggro()
    {
        addAura("dire bear form");

		tickWithNoAggro();

		assertActions(">T:growl");
    }

    void startMeleeCombat()
    {
        removeTargetAura("faerie fire (feral)");

        tick();
        addAura("dire bear form");

        tick();
        tickInMeleeRange();

        tickOutOfMeleeRange();
        tickInMeleeRange();

        assertActions(">S:dire bear form>T:feral charge - bear>T:faerie fire (feral)>T:reach melee>T:lacerate");
    }

    void meleeCombat()
    {
        addAura("dire bear form");

        tickInMeleeRange();
		tick();
		tick();
		tick();

		tickWithSpellAvailable("lacerate");
		tick();
		tickWithSpellAvailable("lacerate");
        tick();

        spellAvailable("lacerate");
        spellAvailable("mangle (bear)");
        spellAvailable("maul");
        spellAvailable("faerie fire (feral)");

		tickWithSpellAvailable("lacerate");
		tickWithSpellAvailable("lacerate");
		tickWithSpellAvailable("lacerate");
		tickWithSpellAvailable("lacerate");
		tickWithSpellAvailable("lacerate");
		tickWithSpellAvailable("lacerate");

        assertActions(">T:lacerate>T:mangle (bear)>T:maul>T:feral charge - bear>T:faerie fire (feral)>T:melee>T:lacerate>T:melee>T:faerie fire (feral)>T:lacerate>T:mangle (bear)>T:maul>T:melee>T:lacerate");
    }

    void healHimself()
    {
        addAura("dire bear form");

		tickWithLowHealth(59);
		tickWithLowHealth(59);

		tickWithLowHealth(39);
		tickWithLowHealth(39);

        addAura("dire bear form");
        spellAvailable("healing touch");
        spellAvailable("regrowth");
        spellAvailable("rejuvenation");
        tickWithLowHealth(1);
        tickWithLowHealth(1);
        tickWithLowHealth(1);
        tickWithLowHealth(1);
        tickWithLowHealth(1);

        assertActions(">T:reach melee>T:lacerate>S:caster form>S:regrowth>S:survival instincts>S:barskin>S:caster form>S:regrowth>S:healing touch");
    }

    void intensiveHealing()
    {
        addAura("dire bear form");
		tickWithLowHealth(1);

		assertActions(">S:survival instincts");
    }

    void healOthers()
    {
        tick();
        addAura("dire bear form");

        spellAvailable("healing touch");
        spellAvailable("regrowth");
        spellAvailable("rejuvenation");
        addAura("dire bear form");
        tickWithPartyLowHealth(39);
        tickWithPartyLowHealth(39);

        spellAvailable("healing touch");
        spellAvailable("regrowth");
        spellAvailable("rejuvenation");
        addAura("dire bear form");
        tickWithPartyLowHealth(1);
        tickWithPartyLowHealth(1);
        tickWithPartyLowHealth(1);

		assertActions(">S:dire bear form>S:caster form>P:regrowth on party>S:caster form>P:regrowth on party>P:healing touch on party");
    }
    void curePoison()
    {
        tick();
        addAura("dire bear form");

		tickWithAuraToDispel(DISPEL_POISON);
		tickWithAuraToDispel(DISPEL_POISON);

		spellAvailable("abolish poison");
		tickWithPartyAuraToDispel(DISPEL_POISON);

		tickWithAuraToDispel(DISPEL_POISON);

		spellAvailable("cure poison");
		tickWithPartyAuraToDispel(DISPEL_POISON);

		assertActions(">S:dire bear form>S:caster form>S:abolish poison>P:abolish poison on party>S:cure poison>P:cure poison on party");
    }
    void interruptSpells()
    {
        addAura("dire bear form");
        tickInMeleeRange();
		tickWithTargetIsCastingNonMeleeSpell();

        assertActions(">T:lacerate>T:bash");
    }
	void buff()
	{
        removeAura("thorns");
        tick();

        removeTargetAura("faerie fire (feral)");
        tickInMeleeRange();
		addAura("dire bear form");

        assertActions(">S:thorns>S:dire bear form");
	}

    void aoe()
    {
        addAura("dire bear form");
		tickInMeleeRange();
		tickWithAttackerCount(2);
		tickWithAttackerCount(3);
        spellAvailable("swipe (bear)");
		tickWithAttackerCount(3);

		assertActions(">T:lacerate>T:swipe (bear)>T:demoralizing roar>T:swipe (bear)");
    }

    void incompatibles()
    {
        engine->addStrategies("bear", "cat", "caster", "dps", "tank", NULL);

        CPPUNIT_ASSERT(engine->ListStrategies() == "Strategies: bear");
    }

    void interrupt_enemy_healer()
    {
        tickWithEnemyHealerIsCastingInterruptableSpell("bash");
        assertActions(">H:bash on enemy healer");
    }

    void stress()
    {
        addAura("dire bear form");
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( BearTankDruidTestCase );
