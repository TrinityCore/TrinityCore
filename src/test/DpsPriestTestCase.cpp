#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/priest/PriestAiObjectContext.h"

using namespace ai;


class DpsPriestTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( DpsPriestTestCase );
    CPPUNIT_TEST( combat );
    CPPUNIT_TEST( low_mana );
    CPPUNIT_TEST( aoe );
    CPPUNIT_TEST( stress );
    CPPUNIT_TEST_SUITE_END();


public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new PriestAiObjectContext(ai), "dps", "dps debuff", NULL);

        addAura("power word: fortitude");
        addAura("divine spirit");
        addAura("inner fire");
        addPartyAura("power word: fortitude");
        addPartyAura("divine spirit");
    }

protected:
    void combat()
    {
        tick();
        addAura("vampiric embrace");

        tick();
        addAura("shadowform");

        tick();
        tick();
        tick();
        tick();
        tick();
        tick();

        tickWithLowHealth(39);
        tickWithLowHealth(39);
        tickWithLowHealth(39);

        spellAvailable("power word: shield");
        spellAvailable("greater heal");
        addAura("shadowform");
        tickWithLowHealth(1);
        tickWithLowHealth(1);
        tickWithLowHealth(1);

        assertActions(">S:vampiric embrace>S:shadowform>T:devouring plague>T:shadow word: pain>T:vampiric touch>T:mind blast>T:mind flay>T:shoot>S:remove shadowform>S:power word: shield>S:greater heal>S:remove shadowform>S:power word: shield>S:flash heal");
    }

    void low_mana()
    {
        tickWithLowMana(1);

        assertActions(">S:dispersion");
    }

    void aoe()
    {
        addAura("vampiric embrace");
        addAura("shadowform");
        addTargetAura("devouring plague");
        addTargetAura("shadow word: pain");
        addTargetAura("vampiric touch");

        engine->addStrategy("aoe");

        set<Unit*>("attacker without aura", "shadow word: pain", MockedTargets::GetAttackerWithoutAura());
        tick();

        set<Unit*>("attacker without aura", "shadow word: pain", NULL);
        tick();

        assertActions(">A:shadow word: pain on attacker>T:mind blast");
    }


    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( DpsPriestTestCase );
