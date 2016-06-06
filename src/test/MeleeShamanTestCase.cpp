#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/shaman/ShamanAiObjectContext.h"

using namespace ai;


class MeleeShamanTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( MeleeShamanTestCase );
    CPPUNIT_TEST( combat );
	CPPUNIT_TEST( buff );
	CPPUNIT_TEST( incompatibles );
    CPPUNIT_TEST( aoe );
    CPPUNIT_TEST( boost );
    CPPUNIT_TEST( interruptSpell );
    CPPUNIT_TEST( interrupt_enemy_healer );
    CPPUNIT_TEST( stress );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new ShamanAiObjectContext(ai), "melee", NULL);

        addAura("lightning shield");
    }

protected:
    void combat()
    {
		tickInMeleeRange();

        tick();
        tick();
        addTargetAura("earth shock");

        tick();
		tick();
		tick();

        assertActions(">S:searing totem>T:earth shock>T:flame shock>T:stormstrike>T:lava lash>T:melee");
    }

    void buff()
    {
        engine->addStrategy("bdps");
        removeAura("lightning shield");
        tickInMeleeRange();

        tick();
        addAura("lightning shield");

        tickWithItemForSpell("windfury weapon");
        tickWithItemForSpell("windfury weapon");

        assertActions(">S:lightning shield>S:searing totem>S:windfury weapon>S:rockbiter weapon");
    }

    void incompatibles()
    {
        engine->addStrategies("melee", "dps", "heal", NULL);

        CPPUNIT_ASSERT(engine->ListStrategies() == "Strategies: heal");
    }

    void aoe()
    {
        engine->addStrategy("melee aoe");

        tickInMeleeRange();
        tickWithAttackerCount(3);
        tickWithAttackerCount(3);
        tickWithAttackerCount(3);

        assertActions(">S:searing totem>S:strength of earth totem>S:magma totem>T:fire nova");
    }

    void boost()
    {
        tickWithBalancePercent(1);
        tickWithBalancePercent(1);

        assertActions(">S:heroism>S:bloodlust");
    }

    void interruptSpell()
    {
        tickWithTargetIsCastingNonMeleeSpell();

        assertActions(">T:wind shear");
    }

    void interrupt_enemy_healer()
    {
        tickWithEnemyHealerIsCastingInterruptableSpell("wind shear");

        assertActions(">H:wind shear on enemy healer");
    }

    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( MeleeShamanTestCase );
