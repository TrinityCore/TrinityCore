#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/warrior/WarriorAiObjectContext.h"

using namespace ai;


class TankWarriorTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( TankWarriorTestCase );
    CPPUNIT_TEST( buff );
    CPPUNIT_TEST( startMeleeCombat );
    CPPUNIT_TEST( melee );
    CPPUNIT_TEST( warriorMustHoldAggro );
    CPPUNIT_TEST( aoe );
    CPPUNIT_TEST( healing );
	CPPUNIT_TEST( snare );
    CPPUNIT_TEST( interruptSpells );
    CPPUNIT_TEST( incompatibles );
    CPPUNIT_TEST( interrupt_enemy_healer );
    CPPUNIT_TEST( stress );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
        EngineTestBase::setUp();
        setupEngine(new WarriorAiObjectContext(ai), "tank", NULL);

        // this buff is combat-only, so skip for most test cases
        addAura("battle shout");
        set<uint8>("rage", "self target", 20);
        set<float>("distance", "current target", ATTACK_DISTANCE - 1);
    }

protected:
    void interruptSpells()
    {
		tickWithTargetIsCastingNonMeleeSpell();

        tick(); // rend

        assertActions(">T:shield bash>S:defensive stance");
    }

    void healing()
    {
        tickWithLowHealth(50); // defensive stance
        tickWithLowHealth(50); // shield wall
        tickWithLowHealth(50); // shield block

		tickWithLowHealth(4);
		tickWithLowHealth(4);

		assertActions(">S:defensive stance>T:shield wall>S:shield block>S:last stand>T:intimidating shout");
    }

    void buff()
    {
        set<uint8>("rage", "self target", 0);
        removeAura("battle shout");

        tickInSpellRange();
        addAura("battle shout");

        tickInSpellRange();

		assertActions(">S:battle shout>S:bloodrage");

    }

    void aoe()
    {
        addAura("defensive stance");

		tickWithAttackerCount(3);
		tickWithAttackerCount(3);

		spellAvailable("cleave");
		tickWithAttackerCount(2);
		tickWithAttackerCount(2);
		tickWithAttackerCount(2);

        assertActions(">T:shockwave>T:thunder clap>T:demoralizing shout>T:cleave>T:devastate");
    }

    void warriorMustHoldAggro()
    {
        addAura("defensive stance");

		tickWithNoAggro();
		tickWithNoAggro();

		assertActions(">T:taunt>T:mocking blow");
    }

    void startMeleeCombat()
    {
        tickOutOfMeleeRange();
        tickWithRage(0);
        tickInMeleeRange();
        tick();
        tick();
        tick();

        assertActions(">T:reach melee>S:bloodrage>S:defensive stance>T:devastate>T:revenge>T:rend");
    }

    void melee()
    {
        addAura("defensive stance");
        tickInMeleeRange();
        tick();
        tick();
        tick();
        tick();
        spellAvailable("rend");
        addTargetAura("rend");

        tickWithRage(31);

        set<uint8>("rage", "self target", 41);
        tick();

        tickWithSpellAvailable("heroic strike");

        addAura("sword and board");
		tickWithSpellAvailable("devastate");
        tickWithSpellAvailable("shield slam");

		assertActions(">T:devastate>T:revenge>T:rend>T:disarm>T:sunder armor>T:melee>T:shield slam>T:heroic strike>T:melee>T:shield slam");
    }

    void revengeIfDodge()
    {
        tick(); // melee
        spellAvailable("revenge");
        tick(); // defensive stance
        tick(); // revenge

		assertActions(">T:melee>S:defensive stance>T:revenge");
    }

	void snare()
	{
		tick();
		tickWithTargetIsMoving();

		assertActions(">S:defensive stance>T:concussion blow");
	}


    void incompatibles()
    {
        engine->addStrategies("tank", "dps", NULL);

        CPPUNIT_ASSERT(engine->ListStrategies() == "Strategies: dps");
    }

    void interrupt_enemy_healer()
    {
        tickWithEnemyHealerIsCastingInterruptableSpell("shield bash");

        assertActions(">H:shield bash on enemy healer");
    }

    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( TankWarriorTestCase );
