#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/paladin/PaladinAiObjectContext.h"

using namespace ai;


class PaladinNonCombatTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( PaladinNonCombatTestCase );
        CPPUNIT_TEST( buff );
		CPPUNIT_TEST( resurrect );
		CPPUNIT_TEST( healing );
        CPPUNIT_TEST( curePoison );
        CPPUNIT_TEST( cureMagic );
        CPPUNIT_TEST( cureDisease );
    CPPUNIT_TEST_SUITE_END();


public:
    virtual void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new PaladinAiObjectContext(ai), "nc", NULL);

        set<uint8>("attacker count", 0);
    }

protected:
    void buff()
    {
        tick();

        engine->addStrategy("bspeed");
        set<bool>("mounted", "self target", true);
		tick();
        set<bool>("mounted", "self target", false);

		assertActions(">S:check mount state>S:crusader aura");
    }

	void resurrect()
	{
		tickWithDeadPartyMember();
		assertActions(">P:redemption");
	}

    void healing()
    {
        tickWithLowHealth(50);
        tickWithLowHealth(30);

        spellAvailable("flash of light");
        spellAvailable("holy light");
        tickWithPartyLowHealth(50);
        tickWithPartyLowHealth(30);

        assertActions(">S:flash of light>S:holy light>P:flash of light on party>P:holy light on party");
    }


    void cureDisease()
    {
        cureKind(DISPEL_DISEASE);
        assertActions(">S:cleanse>P:cleanse disease on party>S:purify>P:purify disease on party");
    }

    void curePoison()
    {
        cureKind(DISPEL_POISON);
        assertActions(">S:cleanse>P:cleanse poison on party>S:purify>P:purify poison on party");
    }

    void cureMagic()
    {
        cureKind(DISPEL_MAGIC);
        assertActions(">S:cleanse>P:cleanse magic on party>S:check mount state>S:check mount state");
    }

    void cureKind(DispelType type)
    {
        spellAvailable("cleanse");
        tickWithAuraToDispel(type);

        spellAvailable("cleanse");
        tickWithPartyAuraToDispel(type);

        spellAvailable("purify");
        tickWithAuraToDispel(type);

        spellAvailable("purify");
        tickWithPartyAuraToDispel(type);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( PaladinNonCombatTestCase );
